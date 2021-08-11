#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

void comb(map<string, int> &m, string str, int maxlen, string key, int index)
{
    if(key.size() == maxlen)
    {
        if(m.find(key) == m.end())
        {
            m.insert({key, 1});
        }
        else
        {
            m[key]++;
        }        
        return;
    }

    for(int i = index; i<str.size(); i++)
    {
        comb(m, str, maxlen, key + str[i], i + 1);
    }

    return;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    map<string, int> mn;
    for(int c=0; c<course.size(); c++)
    {
        int Len = course[c];
        mn.clear();

        for(int od=0; od<orders.size(); od++)
        {
            if(orders[od].size() < Len) continue;
            sort(orders[od].begin(), orders[od].end());
            comb(mn, orders[od], Len, "", 0);
        }
        
        if(mn.empty()) continue;

        vector<pair<string, int>> vec(mn.begin(), mn.end());
        sort(vec.begin(), vec.end(), cmp);

        int maxLen = vec[0].second;

        if(maxLen < 2) continue;

        for(int i=0; i<vec.size(); i++)
        {
            if(maxLen != vec[i].second) break;
            answer.push_back(vec[i].first);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}