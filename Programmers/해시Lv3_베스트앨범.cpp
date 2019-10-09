//https://programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class song{
public:
    string genr;
    int play;
    int index;
    song(string genr, int play, int index)
    {
        this->genr = genr;
        this->play = play;
        this->index = index;
    }
};

bool cmp(const song &a, const song &b)
{
    return a.play > b.play;
}

bool cmp2(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<song> vec;
    map<string, int> m;
    vector<pair<string, int>> name_ch;
    int size = genres.size();
    
    for(int i=0; i < size; i++)
    {
        vec.push_back(song(genres[i], plays[i], i));
        m[genres[i]]+=plays[i];
    }
    
    for(auto it = m.begin(); it != m.end(); it++)
        name_ch.push_back(make_pair(it->first, it->second));
    
    sort(vec.begin(), vec.end(), cmp);
    sort(name_ch.begin(), name_ch.end(), cmp2);
    
    int genres_size = m.size();
    for(int n=0; n<genres_size; n++)
    {
        int i = 0;
        string ch;
        for(; i<size; i++)
        {
            if(name_ch[n].first == vec[i].genr && vec[i].play > 0)
            {
                answer.push_back(vec[i].index);
                ch = vec[i].genr;
                i++;
                break;
            }
        }
        
        for(; i<size; i++)
        {
            if(vec[i].genr != ch) continue;
            answer.push_back(vec[i].index);
            break;
        }
    }
    return answer;
}