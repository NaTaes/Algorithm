/* https://programmers.co.kr/learn/courses/30/lessons/43165 */

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    queue<int> que;

    que.push(0);

    for(int n : numbers)
    {
        int size = que.size();

        for(int i=0; i<size; i++)
        {
            int sum = que.front();
            que.pop();
            que.push(sum + n);
            que.push(sum - n);
        }
    }

    while (!que.empty())
    {
        if(target == que.front())
        {
            answer++;
        }
        que.pop();
    }

    return answer;
}