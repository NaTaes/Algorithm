// https://www.acmicpc.net/problem/17822

#include <iostream>
#include <queue>

using namespace std;

int NM[50][50];
int index[50];
int N, M, T, result, count;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool aroundFind(void)
{
    queue<pair<int, int> > que;
    bool ch = true;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            int value = NM[i][(j + index[i]) % M];
            if(value == 0) continue;
            que.push(make_pair(i, j));

            while(!que.empty())
            {
                int mi = que.front().first;
                int mj = que.front().second;
                que.pop();

                for(int n=0; n<4; n++)
                {
                    int mx = mi + dx[n];
                    int my = (mj + dy[n]) < 0 ? M-1 : (mj + dy[n]);
                    int ard = (my + index[mx]) % M;

                    if(mx < 0 || mx > N-1 || NM[mx][ard] == 0) continue;
                    if(NM[mx][ard] != value) continue;
                    result -= value;
                    NM[mx][ard] = 0;
                    que.push(make_pair(mx, my));
                    count--;
                    ch = false;
                }
            }
        }
    }
    return ch;
}

void avgFunc(void)
{
    if(count == 0) return;
    int avg = result / count;
    int remain = result % count;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(NM[i][j] == 0) continue;
            if(NM[i][j] > avg)
            {
                NM[i][j] -= 1;
                result -= 1;
            }
            else if(NM[i][j] < avg)
            {
                NM[i][j] += 1;
                result +=1;
            }
            else
            {
                if(remain != 0)
                {
                    NM[i][j] += 1;
                    result +=1;
                }
            }
            
        }
    }
}

void Rotate(int xi, int di, int ki)
{
    for(int i=xi-1; i<N; i+=xi)
    {
        if(di == 0) di = M-1;
        index[i] = (index[i] + (di * ki)) % M;
    }

    if(aroundFind()) avgFunc();
}

int main(void)
{
    cin >> N >> M >> T;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> NM[i][j];
            result += NM[i][j];
            count++;
        }
    }

    for(int i=0; i<T; i++)
    {
        int xi, di, ki;
        cin >> xi >> di >> ki;
        Rotate(xi, di, ki);
    }

    cout << result << endl;
}