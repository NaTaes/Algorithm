/* https://programmers.co.kr/learn/courses/30/lessons/62048 */

using namespace std;

long long solution(int w,int h) {
    long long answer = (long long)w * h;

    int first = 0;
    int second;

    int x;
    int y;

    if(w > h)
    {
        x = h;
        y = w;
    }
    else
    {
        x = w;
        y = h;
    }

    for(int n=1; n<=x; n++)
    {
        long long sub = (long long)y * n;

        if(sub % x != 0)
        {
            second = (int)(sub/x) + 1;
        }
        else
        {
            second = (int)(sub/x);
        }

        answer -= (second - first);
        first = (int)(sub/x);
    }

    return answer;
}