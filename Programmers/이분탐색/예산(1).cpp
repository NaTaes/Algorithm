// https://programmers.co.kr/learn/courses/30/lessons/43237

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
}mycmp;

int solution(vector<int> budgets, int M) {
    int answer = 0;

    sort(budgets.begin(), budgets.end(), mycmp);

    int myMax;

    for(int i=0; i<budgets.size(); i++)
    {
        myMax = M / (budgets.size() - i);
        if(myMax < budgets[i])
        {
            answer = myMax;
            break;
        }
        M -= budgets[i];
    }

    if(answer == 0)
    {
        answer = budgets[budgets.size() - 1];
    }

    return answer;
}
