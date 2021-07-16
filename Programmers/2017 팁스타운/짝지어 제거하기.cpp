// https://programmers.co.kr/learn/courses/30/lessons/12973

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;

    for(int i=0; i<s.size(); i++)
    {
        if(!st.empty() && st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    answer = !st.size();
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}