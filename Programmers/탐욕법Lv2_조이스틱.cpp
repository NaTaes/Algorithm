//https://programmers.co.kr/learn/courses/30/lessons/42860

#include <string>
#include <vector>

using namespace std;

int searchWord(char goWord)
{
    int t = 0;
    char stw1 = 'A', stw2 = 'Z' + 1;
    for(; stw1 != goWord && stw2 != goWord; t++)
    {
        stw1++;
        stw2--;
    }
    return t;
}

int searchSpot(int now, string tmpName, vector<char> tmp)
{
    int lenMax = tmpName.length() - 1;
    int t = 0, mindex = now, pindex = now;
    
    while(true)
    {
        t++;
        if(t > lenMax) return 0;
        pindex++;
        mindex--;
        
        if(pindex > lenMax) pindex = 0;
        if(mindex < 0) mindex = lenMax;
        
        if(tmpName[pindex] != tmp[pindex]) return ((pindex<<5)|t);
        if(tmpName[mindex] != tmp[mindex]) return ((mindex<<5)|t);
    }
}

int solution(string name) {
    int answer = 0;
    int size = name.length();
    int spot = 0;
    
    vector<char> vecName;
    for(int i=0; i<size; i++)
        vecName.push_back('A');
    
    answer += searchWord(name[0]);
    vecName[0] = name[0];

    while(true)
    {
        spot = searchSpot(spot, name, vecName);
        if(spot == 0) break;
        answer += (spot & 31);
        spot = (spot >> 5);
        answer += searchWord(name[spot]);
        vecName[spot] = name[spot];
    }
    
    return answer;
}