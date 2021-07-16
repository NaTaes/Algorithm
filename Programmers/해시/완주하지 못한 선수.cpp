//https://programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> mala;
    int size = participant.size();
    
    for(int i=0; i < size-1; i++)
    {
        mala[participant[i]]++;
        mala[completion[i]]++;
    }
    mala[participant[size-1]]++;
    
    for(int i=0; i < size; i++)
    {
        if(mala[participant[i]] % 2 != 0)
        {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}