// https://programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<int> day;
    int size = progresses.size();
    for(int i=0; i<size; i++)
    {
        int rd = (100 - progresses[i]) / speeds[i];

        if((100 - progresses[i]) % speeds[i])
        {
            rd += 1;
        }
        
        day.push_back(rd);
    }

    int first = day[0];
    int count = 1;
    for(int i=1; i<size; i++)
    {
        if(first < day[i])
        {
            answer.push_back(count);
            count = 0;
            first = day[i];
        }
        count++;
    }
    if(count != 0)
    {
        answer.push_back(count);
    }

    return answer;
}