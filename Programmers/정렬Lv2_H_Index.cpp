//https://programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(const int a, const int b)
    {
        return a > b;
    }
}mycmp;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    
    sort(citations.begin(), citations.end(), mycmp);
    
    for(;answer<size; answer++)
    {
        if(answer < citations[answer]) continue;
        break;
    }
    
    return answer;
}