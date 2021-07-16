/* https://programmers.co.kr/learn/courses/30/lessons/42895 */

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int N, int number) {
    int answer = -1;

    vector<vector<int>> result(9);

    result[0].push_back(0);

    for(int i=1; i<=8; i++)
    {
        result[i].push_back(result[i-1][0] + (N * pow(10, i-1)));
        if(result[i][0] == number) return i;

        for(int j=1; j<i; j++)
        {
            for(int n=0; n<result[j].size(); n++)
            {
                for(int k=0; k<result[i-j].size(); k++)
                {
                    if(result[j][n] + result[i-j][k] == number) return i;
                    result[i].push_back(result[j][n] + result[i-j][k]);
                    if(result[j][n] - result[i-j][k] == number) return i;
                    if(result[j][n] - result[i-j][k] > 0)
                        result[i].push_back(result[j][n] - result[i-j][k]);
                    if(result[j][n] * result[i-j][k] == number) return i;
                    result[i].push_back(result[j][n] * result[i-j][k]);

                    if(result[i-j][k] != 0)
                    {
                        if(result[j][n] / result[i-j][k] == number) return i;
                        if(result[j][n] / result[i-j][k] > 0)
                            result[i].push_back(result[j][n] / result[i-j][k]);
                    }
                }
            }
        }
    }

    return answer;
}