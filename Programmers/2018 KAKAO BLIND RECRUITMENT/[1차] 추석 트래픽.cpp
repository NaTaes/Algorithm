// https://programmers.co.kr/learn/courses/30/lessons/17676

// 시 분을 초 단위로 변경시켜서 진행하면 더욱 간변해 질 수 있다.

#include <string>
#include <vector>

using namespace std;

void cal_time(int& vmin, int& vmax, string line, bool ch)
{
    int th = stoi(line.substr(11, 2));
    int tm = stoi(line.substr(14, 2));
    int ts = stoi(line.substr(17, 2));
    int te = stoi(line.substr(20, 3));

    if(ch)
    {
        vmin = th * 10000000 + tm * 100000 + ts * 1000 + te;
        te += 999;

        if(te / 1000 != 0)
        {
            ts += 1;
            te %= 1000;
            if(ts / 60 != 0)
            {
                tm += 1;
                ts %= 60;
                if(tm / 60 != 0)
                {
                    th += 1;
                    tm %= 60;
                }
            }
        }
        vmax = th * 10000000 + tm * 100000 + ts * 1000 + te;
    }
    else
    {
        vmax = th * 10000000 + tm * 100000 + ts * 1000 + te;

        string ST = line.substr(24);
        int ps = 1000;
        int sv_dif = 0;
        for(int n=0; n<ST.size()-1; n++)
        {
            if(ST[n] == '.') continue;
            sv_dif += (ST[n] - '0') * ps;
            ps /= 10;
        }
        sv_dif -= 1;
        te -= (sv_dif % 1000);

        if(te < 0)
        {
            te = 1000 + te;
            ts -= 1;
        }
        ts -= (sv_dif / 1000);
        if(ts < 0)
        {
            ts = 60 + ts;
            tm -= 1;
            if(tm < 0)
            {
                tm = 60 + tm;
                th -= 1;
            }
        }

        vmin = th * 10000000 + tm * 100000 + ts * 1000 + te;
    }
}

int solution(vector<string> lines) {
    int answer = 0;
    int tmp_answer = 1;

    for(int i=0; i<lines.size()-1; i++)
    {
        tmp_answer = 1;

        int fv_min;
        int fv_max;

        cal_time(fv_min, fv_max, lines[i], true);

        for(int j=i+1; j<lines.size(); j++)
        {
            int sv_min;
            int sv_max;

            cal_time(sv_min, sv_max, lines[j], false);

            if(fv_min <= sv_max && fv_max >= sv_min)
            {
                tmp_answer++;
            }
        }
        answer = answer < tmp_answer ? tmp_answer : answer;
    }

    answer = answer < tmp_answer ? tmp_answer : answer;

    return answer;
}