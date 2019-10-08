//https://programmers.co.kr/learn/courses/30/lessons/42886

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    int answer = 0;
    
    sort(weight.begin(), weight.end());

    if(weight[0] > 1) return 1;

    for(int i=1; i<weight.size(); i++)
    {
        if(weight[i-1]+1 < weight[i])
        {
            answer = weight[i-1] + 1;
            return answer;
        }
        weight[i] += weight[i-1];
    }
    
    answer = weight[weight.size()-1] + 1;
    
    return answer;
}