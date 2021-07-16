// https://programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(const int a, const int b)
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
}mycmp;

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), mycmp);

    int size = numbers.size();

    for(int i=0; i<size; i++)
        answer += to_string(numbers[i]);

    if(answer[0] == '0')
        answer = "0";

    return answer;
}