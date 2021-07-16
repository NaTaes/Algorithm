// https://programmers.co.kr/learn/courses/30/lessons/43238

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long Possible(long long num, int n, vector<int> tmp)
{
    long long Mx = 0;
    for(int i=0; i<tmp.size(); i++)
    {
        if(n * tmp[i] < num)
        {
            Mx = Mx > n * tmp[i] ? Mx : n * tmp[i];
            return Mx;
        }
        if(num/tmp[i]==0) return -1;
        n-=(num/tmp[i]);
        long long comp = tmp[i] * (num/tmp[i]);
        Mx = Mx > comp ? Mx : comp;
    }
    return -1;
}

long long binarySearch(long long Mn, long long Mx, int n, long long value, vector<int> tmp)
{
    if(Mx - Mn == 1) return value;
    long long Md = (Mx + Mn) / 2;
    long long Ps = Possible(Md, n, tmp);
    if(Ps == -1) return binarySearch(Md, Mx, n, value, tmp);
    else return binarySearch(Mn, Ps, n, Ps, tmp);
}

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    long long Mx = times[times.size()-1] * n;

    answer = binarySearch(0, Mx, n, 0, times);

    return answer;
}