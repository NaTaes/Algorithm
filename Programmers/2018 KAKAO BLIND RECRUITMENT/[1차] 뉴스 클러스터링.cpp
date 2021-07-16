/* https://programmers.co.kr/learn/courses/30/lessons/17677 */

#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 65536;

    vector<string> vstr[2];
    string mstr[2] = {str1, str2};

    int unionCount = 0;
    int interCount = 0;

    for(int n=0; n<2; n++)
    {
        for(int i=0; i<mstr[n].size()-1; i++)
        {
            if((mstr[n][i] >= 'A' && mstr[n][i] <= 'Z') || (mstr[n][i] >= 'a' && mstr[n][i] <= 'z'))
            {
                if((mstr[n][i+1] >= 'A' && mstr[n][i+1] <= 'Z') || (mstr[n][i+1] >= 'a' && mstr[n][i+1] <= 'z'))
                {
                    string tmp;
                    if(mstr[n][i] >= 'a' && mstr[n][i] <= 'z')
                    {
                        mstr[n][i] += ('A' - 'a');
                    }
                    if(mstr[n][i+1] >= 'a' && mstr[n][i+1] <= 'z')
                    {
                        mstr[n][i+1] += ('A' - 'a');
                    }
                    tmp = mstr[n][i];
                    tmp += mstr[n][i+1];
                    vstr[n].push_back(tmp);
                }
            }
        }
    }

    for(int i=0; i<vstr[0].size(); i++)
    {
        for(int j=0; j<vstr[1].size(); j++)
        {
            if(vstr[0][i] == vstr[1][j])
            {
                vstr[1][j] = "";
                unionCount++;
                break;
            }
        }
    }

    interCount = vstr[0].size() + vstr[1].size() - unionCount;
    if(interCount != 0)
    {
        answer = answer * unionCount / interCount;
    }

    return answer;
}