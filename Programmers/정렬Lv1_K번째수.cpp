//https://programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int size = commands.size();
    
    for(int n =0; n < size; n++)
    {
        vector<int> temp;
        int i = commands[n][0];
        int j = commands[n][1];
        int k = commands[n][2];
        
        for(; i-1 < j; i++)
            temp.push_back(array[i-1]);
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k-1]);
    } 
    return answer;
}