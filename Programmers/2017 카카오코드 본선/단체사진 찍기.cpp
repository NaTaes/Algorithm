// https://programmers.co.kr/learn/courses/30/lessons/1835

#include <string>
#include <vector>

using namespace std;

void Comb(string& Nm, string& S, bool* ch, int num, int& asw, vector<string>& dt)
{
    if(num == Nm.size())
    {
        asw++;
        return;
    }

    for(int i=0; i<Nm.size(); i++)
    {
        if(ch[i] == true) continue;
        bool state = false;

        S.push_back(Nm[i]);

        for(int n=0; n<dt.size(); n++)
        {
            if(S.find(dt[n][0]) == string::npos || S.find(dt[n][2]) == string::npos) continue;

            int fi = S.find(dt[n][0]);
            int si = S.find(dt[n][2]);
            char sign = dt[n][3];
            int pd = (int)(dt[n][4] - '0') + 1;

            if(sign == '=')
            {
                if(abs(fi - si) != pd)
                {
                    state = true;
                }
            }
            else if(sign == '>')
            {
                if(abs(fi - si) <= pd)
                {
                    state = true;
                }
            }
            else
            {
                if(abs(fi - si) >= pd)
                {
                    state = true;
                }
            }

            if(state) break;;
        }

        if(state)
        {
            S.pop_back();
            continue;
        }

        ch[i] = true;

        Comb(Nm, S, ch, num+1, asw, dt);
        S.pop_back();
        ch[i] = false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;

    string name = "ACFJMNRT";
    string pos;
    bool ch[8] = {false, };

    for(int i=0; i<name.size(); i++)
    {
        pos.clear();
        pos.push_back(name[i]);
        ch[i] = true;
        Comb(name, pos, ch, 1, answer, data);
        ch[i] = false;
    }

    return answer;
}