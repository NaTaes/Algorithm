//https://programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>

using namespace std;

int d[2] = {-1, 1};

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> student;
    
    for(int i=0; i<n; i++)
        student.push_back(1);
    
    for(int i=0; i<lost.size(); i++)
        student[lost[i]-1]--;
    
    for(int i=0; i<reserve.size(); i++)
        student[reserve[i]-1]++;
    
    for(int i=0; i<n; i++)
    {
        if(student[i] > 0)
            answer++;
        if(student[i] == 2)
        {
            for(int m=0; m<2; m++)
            {
                int ti = i;
                ti += d[m];
            
                if(ti < 0 || ti > n-1) continue;
            
                if(student[ti] == 0)
                {
                    student[i]--;
                    student[ti]++;
                    if(m==0)
                        answer++;
                    break;
                }
            }
        }
    }
    
    return answer;
}