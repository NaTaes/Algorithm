// https://programmers.co.kr/learn/courses/30/lessons/42861

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ch[100];

int findParent(int x)
{
    if(ch[x] != x)
        ch[x] = findParent(ch[x]);

    return ch[x];
}

struct cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        if(a[2] == b[2])
        {
            return a[0] < b[0];
        }
        return a[2] < b[2];
    }
}mycmp;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=0; i<n; i++)
        ch[i] = i;
    
    sort(costs.begin(), costs.end(), mycmp);

    for(int i=0; i<costs.size(); i++)
    {
        int p = findParent(costs[i][0]);
        int c = findParent(costs[i][1]);

        if(p != c)
        {
            ch[c] = p;
            answer += costs[i][2];
        }
    }
    
    return answer;
}