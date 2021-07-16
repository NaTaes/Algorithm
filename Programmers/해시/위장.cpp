// https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;    
    int size = clothes.size();
    map<string, int> clothes_num;

    for(int i=0; i < size; i++)
        clothes_num[clothes[i][1]]++;

    map<string, int>::iterator iter;    
    for(iter = clothes_num.begin(); iter!=clothes_num.end(); iter++)
    {
        answer = answer * ((*iter).second + 1);
    }

    return answer-1;
}