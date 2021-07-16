// https://programmers.co.kr/learn/courses/30/lessons/42888

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;

    for(string rd : record)
    {
        if(rd[0] == 'L')
            continue;
        int findex = rd.find(" ", 0) + 1;
        int sindex = rd.find(" ", findex + 1);

        m[rd.substr(findex, sindex - findex)] = rd.substr(sindex + 1);
    }

    for(string rd : record)
    {
        string str = "";

        if(rd[0] == 'E')
        {
            str = "님이 들어왔습니다.";
        }
        else if(rd[0] == 'L')
        {
            str = "님이 나갔습니다.";
        }
        else
        {
            continue;
        }

        int findex = rd.find(" ", 0) + 1;
        int sindex = rd.find(" ", findex + 1);

        str = m[rd.substr(findex, sindex - findex)] + str;

        answer.push_back(str);
    }

    return answer;
}