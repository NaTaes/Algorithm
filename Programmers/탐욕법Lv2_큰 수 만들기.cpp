//https://programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int index = 0, endex;
    int del = k;

    while(answer.length() != number.length() - k)
    {
        if(index + del + 1> number.length())
            endex = number.length();
        else
            endex = index + del + 1;

        int numax = 0, dif = 0;
        for(int i = index; i < endex; i++)
        {
            if(number[i] > numax)
            {
                dif = i - index;
                numax = number[i];
            }
        }

        answer += number[index + dif];
        index += (dif + 1);
        del -= dif;
    }
    
    return answer;
}