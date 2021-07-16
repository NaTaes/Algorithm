// https://programmers.co.kr/learn/courses/30/lessons/12899

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    vector<int> remain;

    while(n > 0)
    {
        remain.push_back(n % 3);
        n /= 3;
    }

    for(int i=remain.size()-1 ; i>0; i--)
    {
        if(remain[i-1] == 0)
        {
            if(remain[i] != 0)
            {
                remain[i] /= 2;
                remain[i-1] = 4;

                if(remain[i] == 0 && i < remain.size() - 1)
                {
                    answer.pop_back();
                    i += 2;
                    continue;
                }
            }
        }
        if(remain[i] != 0)
            answer.push_back(char(remain[i]) + '0');
    }
    answer.push_back(char(remain[0]) + '0');

    return answer;
}
