#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int Min, int Max, int M, vector<int> Vtmp, int value)
{
    if(Max < Min) return value;
    int Mid = (Max + Min) / 2;

    int sum = 0;
    for(int i=0; i<Vtmp.size(); i++)
    {
        if(Vtmp[i] < Mid) sum+=Vtmp[i];
        else sum+=Mid;
    }

    if(sum <= M)
    {
        value = value < Mid ? Mid : value; 
        return binarySearch(Mid+1, Max, M, Vtmp, value);
    }
    else return binarySearch(Min, Mid-1, M, Vtmp, value);
}

int solution(vector<int> budgets, int M) {
    int answer = 0;
    
    int Max = *max_element(budgets.begin(), budgets.end());
    int Min = *min_element(budgets.begin(), budgets.end());
    
    Min = M/budgets.size() < Min ? M/budgets.size() : Min;

    answer = binarySearch(Min, Max, M, budgets, 0);
    
    return answer;
}