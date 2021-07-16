// https://www.acmicpc.net/problem/17406

#include <iostream>
#include <vector>

using namespace std;

typedef struct 
{
  int x;
  int y;
  int length;
}POINT;

int N, M, K;
vector<POINT> point;
bool ch[6];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int result = 987654321;

void Rotation(int map[50][50], int index, int dir)
{
  int x = point[index].x;
  int y = point[index].y;
  int length = point[index].length;
  int mx = x, my = y;
  int dn;
  int tmp = map[x][y];

  if(dir == 1)
  {
    dn = 0;
  }
  else
  {
    dn = 1;
  }
  
  for(int i=0; i<(length/2); i++)
  {
    for(int n=0; n<4; n++)
    {
      for(int j=0; j<((length-1)-(i*2)); j++)
      {
        int rx = mx;
        int ry = my;
        mx += dx[dn];
        my += dy[dn];
        
        map[rx][ry] = map[mx][my];
      }
      dn = (dn + dir) % 4;
    }
    map[mx+dx[(((dn*3) + 1) % 4)]][my+dy[(((dn*3) + 1) % 4)]] = tmp;
    mx = mx + dx[0];
    my = my + dy[1];
    tmp = map[mx][my];
  }
}

void DFS(int map[50][50], int index, int count)
{
  if(count == K)
  {
    int sum;
    for(int i=0; i<N; i++)
    {
      sum = 0;
      for(int j=0; j<M; j++)
      {
        sum += map[i][j];
      }
      result = result > sum ? sum : result;
    }
    return;
  }

  for(int n=0; n<K; n++)
  {
    index = ((index + 1) % K);
    if(ch[index]) continue;
    ch[index] = true;
    Rotation(map, index, 1);
    DFS(map, index, count+1);
    Rotation(map, index, 3);
    ch[index] = false;
  }
}
int main()
{
  int MAP[50][50];
  cin >> N >> M >> K;

  for(int i=0; i<N; i++)
  {
    for(int j=0; j<M; j++)
    {
      cin >> MAP[i][j];
    }
  }
  
  for(int i=0; i<K; i++)
  {
    int tmp1, tmp2, tmp3;
    POINT tmp;
    cin >> tmp1 >> tmp2 >> tmp3;
    tmp.x = (tmp1 - tmp3) - 1;
    tmp.y = (tmp2 - tmp3) - 1;
    tmp.length = (tmp3 * 2) + 1;
    point.push_back(tmp);
  }
  
  DFS(MAP, -1, 0);

  cout << result << endl;
}