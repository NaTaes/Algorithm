// https://www.acmicpc.net/problem/17472

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int NM[10][10];
int N, M;
vector<pair<int, int> > Is[6];
pair<int, int> combBox[5];
int Dis[10][10];
bool ch[6][6];
bool chIs[6];
int Number, result = 987654321;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void search(int n)
{
  for(int i=0; i<Is[n].size(); i++)
  {
    int x = Is[n][i].first;
    int y = Is[n][i].second;
    
    for(int d=0; d<4; d++)
    {
      int mx = x;
      int my = y;
      int dis = 0;
      
      while(1)
      {
        mx += dx[d];
        my += dy[d];

        if(mx < 0 || my < 0 || mx > N-1 || my > M-1 || NM[mx][my] == NM[x][y])
        {
          dis = 0;
          break;
        }
        
        dis++;

        if(NM[mx][my] == 0) continue;
        
        if(NM[mx][my] < NM[x][y])
        {
          dis = 0;
          break;
        }

        dis--;
        break;
      }
      
      if(dis > 1)
      {
        if(Dis[NM[x][y]-1][NM[mx][my]-1] == 0) 
        {
          Dis[NM[x][y]-1][NM[mx][my]-1] = dis;
        }
        if(Dis[NM[x][y]-1][NM[mx][my]-1] > dis)
        {
          Dis[NM[x][y]-1][NM[mx][my]-1] = dis;
        }
      }
    }
  }
}

void comb(int count)
{
  if(count == Number-2)
  {
    int re = 0;

    for(int i=0; i<Number; i++)
    {
      chIs[i] = false;
    }

    chIs[combBox[0].first] = true;
    chIs[combBox[0].second] = true;

    for(int i=1; i<Number-1; i++)
    {
      if(chIs[combBox[i].first] || chIs[combBox[i].second])
      {
        chIs[combBox[i].first] = true;
        chIs[combBox[i].second] = true;
      }
    }

    for(int i=0; i<Number; i++)
    {
      if(chIs[i] == false) return;
    }

    for(int i=0; i< Number-1; i++)
    {
      re += Dis[combBox[i].first][combBox[i].second];
    }

    result = result > re ? re : result;
    
    return;
  }
  
  for(int i=0; i<Number-1; i++)
  {
    for(int j=i+1; j<Number; j++)
    {
      if(ch[i][j]) continue;
      if(Dis[i][j] == 0) continue;
      ch[i][j] = true;
      combBox[count+1] = make_pair(i, j);
      comb(count+1);
      ch[i][j] = false;
    }
  }
}

int main(void)
{
  cin >> N >> M;
  
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<M; j++)
    {
      cin >> NM[i][j];
      if(NM[i][j] == 1) NM[i][j] = -1;
    }
  }
  
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<M; j++)
    {
      if(NM[i][j] == -1)
      {
        queue<pair<int, int> > que;
        Number++;
        NM[i][j] = Number;
        que.push(make_pair(i, j));
        Is[Number-1].push_back(make_pair(i, j));
        
        while(!que.empty())
        {
          int x = que.front().first;
          int y = que.front().second;
          que.pop();
          
          for(int n=0; n<4; n++)
          {
            int mx = x + dx[n];
            int my = y + dy[n];
            
            if(mx < 0 || my < 0 || mx > N-1 || my > M-1 || NM[mx][my] != -1) continue;
            
            que.push(make_pair(mx, my));
            NM[mx][my] = Number;
            Is[Number-1].push_back(make_pair(mx, my));
          }
        }
      }
    }
  }
  
  for(int i=0; i<Number; i++)
  {
    search(i);
  }

  for(int i=0; i<Number-1; i++)
  {
    for(int j=i+1; j<Number; j++)
    {
      if(Dis[i][j] == 0) continue;
      ch[i][j] = true;
      combBox[0] = make_pair(i, j);
      comb(0);
      ch[i][j] = false;
    }
  }
  
  if(result == 987654321) result = -1;
  cout << result << endl;
}