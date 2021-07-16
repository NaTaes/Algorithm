// https://www.acmicpc.net/problem/17779

#include <iostream>
#include <queue>

using namespace std;

int NN[20][20];
int ch[20][20];
int D[4];
int N;
int Sum[5];
int result = 987654321;

pair<int, int> Point[4];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void Cal(void)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {   
            if(ch[i][j] == 0) Sum[4] += NN[i][j];
            else Sum[ch[i][j] - 1] += NN[i][j];
            
            ch[i][j] = 0;
        }
    }
    
    int Sum_max = 0;
    int Sum_min = 987654321;
    
    for(int i=0; i<5; i++)
    {
        Sum_max = Sum_max < Sum[i] ? Sum[i] : Sum_max;
        Sum_min = Sum_min > Sum[i] ? Sum[i] : Sum_min;
        Sum[i] = 0;
    }

    result = result > Sum_max - Sum_min ? Sum_max - Sum_min : result;
}

void BFS(void)
{
    queue<pair<int, int> > que;
    for(int i=0; i<4; i++)
    {
        que.push(Point[i]);
        int x = Point[i].first;
        int y = Point[i].second;
        ch[x][y] = i + 1;
        int index[2] = {(i + 1) % 4, (i + 2) % 4};
        
        while(!que.empty())
        {
            x = que.front().first;
            y = que.front().second;
            que.pop();

            for(int n=0; n<2; n++)
            {
                int mx = x + dx[index[n]];
                int my = y + dy[index[n]];
                if(ch[mx][my] != 0) continue;
                ch[mx][my] = i + 1;
                que.push(make_pair(mx, my));
            }
        }
    }
}

void DIV(int x, int y)
{
    for(int i=0; i<4; i++)
    {
        int mx = x;
        int my = y;
        while(true)
        {
            mx += dx[i];
            my += dy[i];
            if(mx < 0 || my < 0 || mx > N-1 || my > N-1) break;
            ch[mx][my] = i + 1;
        }

        int index1 = (i + 1) % 4;
        int index2 = (i + 2) % 4;
        for(int d=0; d<D[i]; d++)
        {
            x += (dx[index1] + dx[index2]);
            y += (dy[index1] + dy[index2]);
            ch[x][y] = 5;
        }
    }
    BFS();
    Cal();
}

int main(void)
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> NN[i][j];
        }
    }

    Point[0] = make_pair(0, 0);
    Point[1] = make_pair(0, N-1);
    Point[2] = make_pair(N-1, N-1);
    Point[3] = make_pair(N-1, 0);

    for(int i=0; i<N-2; i++)
    {
        for(int j=1; j<N-1; j++)
        {
            for(int d1=1; d1<N-1; d1++)
            {
                for(int d2=1; d2<N-1; d2++)
                {
                    if(i+d1+d2 > N-1 || j-d1 < 0 || j+d2 > N-1) continue;
                    D[0] = D[2] = d2;
                    D[1] = D[3] = d1;
                    ch[i][j] = 5;
                    DIV(i, j);
                }
            }
        }
    }

    cout << result << endl;
}