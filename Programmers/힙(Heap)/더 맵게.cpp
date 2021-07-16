/* https://programmers.co.kr/learn/courses/30/lessons/42626 */

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pque(scoville.begin(), scoville.end());

    while(pque.top() < K)
    {
        if(pque.size() == 1) return -1;
        int sco = pque.top();
        pque.pop();
        sco += pque.top() * 2;
        pque.pop();
        pque.push(sco);
        answer++;
    }

    return answer;
}