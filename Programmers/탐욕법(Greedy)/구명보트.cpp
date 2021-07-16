// https://programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    int index = 0, boat = 0;
    int endex = people.size() - 1;

    sort(people.begin(), people.end(), less<int>());

    while(index < endex)
    {
        if(people[index]+people[endex] > limit)
        {
            endex--;
            continue;
        }

        boat++;
        index++;
        endex--;
    }

    answer = boat + (people.size() - (boat*2));

    return answer;
}