// https://www.acmicpc.net/problem/17281

#include <iostream>

#define MAX 9

using namespace std;

int N;
int N9[50][MAX];
int HG[4];
int Hit[MAX];
bool ch[MAX];
int result;

void HitRun(int type)
{
  for(int i=3; i>0; i--)
  {
    if(HG[i] == 1)
    {
      HG[i] = 0;
      if(i + type > 3)
        HG[0]++;
      else
        HG[i + type] = 1;
    }
  }
  if(type == 4)
  {
    HG[0]++;
  } 
  else
  {
    HG[type] = 1;
  }
}

void comb(int index, int number)
{
  if(index == MAX)
  {
    int idx = 0;
    
    for(int n=0; n<N; n++)
    {
      int out = 0;
      for(int i=3; i>0; i--)
        HG[i] = 0;
      while(out < 3)
      {
        if(N9[n][Hit[idx]] == 0)
        {
          out++;
        } 
        else
        {
          HitRun(N9[n][Hit[idx]]);
        }
        idx = (idx + 1) % 9;
      }
    }

    result = result < HG[0] ? HG[0] : result;
    
    HG[0] = 0;

    return;
  }
  
  for(int i=1; i<MAX; i++)
  {
    if(ch[i]) continue;
    
    Hit[index] = i;
    ch[i] = true;
    if(index+1 == 3)
      comb(index+2, i);
    else
      comb(index+1, i);
    Hit[index] = 0;
    ch[i] = false;
  }
}

int main(void)
{
  cin >> N;
  
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<MAX; j++)
    {
      cin >> N9[i][j];
    }
  }
  
  
  for(int i=1; i<MAX; i++)
  {
    Hit[0] = i;
    ch[i] = true;
    comb(1, i);
    Hit[0] = 0;
    ch[i] = false;
  }

  cout << result << endl;
}