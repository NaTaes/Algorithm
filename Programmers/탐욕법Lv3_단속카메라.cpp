//https://programmers.co.kr/learn/courses/30/lessons/42884

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }
}mycmp;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end(), mycmp);

    int dmin = routes[0][1];
    for(int i=1; i<routes.size(); i++)
    {
        if(routes[i][0] > dmin)
        {
            answer++;
            dmin = routes[i][1];
            continue;
        } 

        if(routes[i][1] < dmin) dmin = routes[i][1];  
    }
    
    return answer + 1;
}