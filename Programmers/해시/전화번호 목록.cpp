// https://programmers.co.kr/learn/courses/30/lessons/42577

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int size = phone_book.size();

    for(int i=0; i < size - 1; i++)
    {
        if(answer == false) break;
        int st_len1 = phone_book[i].length();
        for(int j=i+1; j < size; j++)
        {
            int st_len2 = phone_book[j].length();
            if(st_len1 > st_len2)
            {
                if(phone_book[j] == phone_book[i].substr(0, st_len2))
                    answer = false;
            }
            else
            {
                if(phone_book[i] == phone_book[j].substr(0, st_len1))
                    answer = false;
            }
            if(answer == false) break;
        }
    }
    return answer;
}