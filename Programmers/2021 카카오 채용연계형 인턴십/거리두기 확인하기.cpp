// https://programmers.co.kr/learn/courses/30/lessons/81302

#include <string>
#include <vector>

using namespace std;

int disCheck(vector<string>& room)
{
    vector<pair<int, int>> pvec;

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(room[i][j] == 'P')
            {
                pvec.push_back({i, j});
            }
        }
    }

    if(pvec.size() == 0) return 1;

    for(int i=0; i<pvec.size()-1; i++)
    {
        for(int j=i+1; j<pvec.size(); j++)
        {
            int md = abs(pvec[i].first - pvec[j].first) + abs(pvec[i].second - pvec[j].second);

            if(md == 1)
            {
                return 0;
            }
            else if(md == 2)
            {
                if(pvec[i].first < pvec[j].first && pvec[i].second < pvec[j].second)
                {
                    if(room[pvec[i].first + 1][pvec[i].second] == 'X' && room[pvec[i].first][pvec[i].second + 1] == 'X')
                    {
                        continue;
                    }
                    return 0;
                }
                else if(pvec[i].first < pvec[j].first && pvec[i].second > pvec[j].second)
                {
                    if(room[pvec[i].first + 1][pvec[i].second] == 'X' && room[pvec[i].first][pvec[i].second - 1] == 'X')
                    {
                        continue;
                    }
                    return 0;
                }
                else if(pvec[i].first == pvec[j].first)
                {
                    if(room[pvec[i].first][pvec[i].second + 1] == 'X')
                    {
                        continue;
                    }
                    return 0;
                }
                else if(pvec[i].second == pvec[j].second)
                {
                    if(room[pvec[i].first + 1][pvec[i].second] == 'X')
                    {
                        continue;
                    }
                    return 0;
                }
                
            }
        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(int i=0; i<5; i++)
    {
        int ret = disCheck(places[i]);
        answer.push_back(ret);
    }

    return answer;
}