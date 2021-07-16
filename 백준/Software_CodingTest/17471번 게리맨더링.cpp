// https://www.acmicpc.net/problem/17471

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, result = 987654321;
int weight[10];
vector<int> cross[10];

int BFS(int bit)
{
  int stBit, retBit = 0;
  int sum;
  queue<int> que;
  for(int i=0; i<N; i++)
  {
    if((1<<i) & bit)
    {
      stBit = i;
      break;
    }
  }

  que.push(stBit);
  retBit |= (1<<stBit);
  sum = weight[stBit];

  while(!que.empty())
  {
    int b = que.front();
    que.pop();
    
    for(int n=0; n<cross[b].size(); n++)
    {
      if((1<<cross[b][n]) & retBit) continue;

      if((1<<cross[b][n]) & bit)
      {
        que.push(cross[b][n]);
        retBit |= (1<<cross[b][n]);
        sum += weight[cross[b][n]];
      }
    }
  }

  if(retBit == bit) return sum;
  
  return 0;
}

void comb(int bit)
{
  int Asum, Bsum;
  if((Asum = BFS(bit)) == 0) return;
  bit = (bit ^ ((1<<N)-1));
  if((Bsum = BFS(bit)) == 0) return;

  result = result > abs(Asum - Bsum) ? abs(Asum - Bsum) : result;
}

int main()
{
  cin >> N;

  for(int i=0; i<N; i++)
  {
    cin >> weight[i];
  }

  for(int i=0; i<N; i++)
  {
    int j;
    cin >> j;
    while(j--)
    {
      int tmp;
      cin >> tmp;
      cross[i].push_back(tmp-1);
    }
  }

  for(int i=1; i<((1<<N)/2); i++)
  {
    comb(i);
  }

  if(result == 987654321)
    result = -1;
  
  cout << result << endl;
}