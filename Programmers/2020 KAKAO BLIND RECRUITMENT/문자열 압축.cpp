/* https://programmers.co.kr/learn/courses/30/lessons/60057 */

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    answer = s.size();

    for(int l=1; l<=s.size()/2; l++)
    {
        map<string, int> m;
        m.clear();
        string str = "";
        int Len = 0;
        int tmp_answer = 0;

        for(int i=0; i<s.size(); i++)
        {
            str = str + s[i];
            Len++;

            if(Len == l)
            {
                if(m.empty())
                {
                    m[str] = 1;
                }
                else
                {
                    if(m.find(str) == m.end())
                    {
                        if(m.begin()->second == 1)
                            tmp_answer += l;
                        else
                            tmp_answer += (l + to_string(m.begin()->second).size());

                        m.clear();
                        m[str] = 1;
                    }
                    else
                    {
                        m[str]++;
                    }
                }

                str.clear();
                Len = 0;                
            }
        }

        if(m.begin()->second == 1)
            tmp_answer += (l + Len);
        else
            tmp_answer += (l + to_string(m.begin()->second).size() + Len);

        answer = answer > tmp_answer ? tmp_answer : answer;
    }

    return answer;
}