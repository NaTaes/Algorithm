#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i=1; i<=n; i++)
    {
        queue<vector<int>> win, lose;
        vector<vector<bool>> ch(2, vector<bool>(n));
        int people = 0;

        for(int r =0; r<results.size(); r++)
        {
            if(results[r][0] == i)
            {
                win.push(results[r]);
                ch[0][results[r][1]-1] = true;
                people++;
                continue;
            }
            if(results[r][1] == i)
            {
                lose.push(results[r]);
                ch[1][results[r][0]-1] = true;
                people++;
            }
        }

        while(true)
        {
            if(win.empty() && lose.empty()) break;
            int tw, tl;
            if(!win.empty()){
                tw = win.front()[1];
                win.pop();
            }
            else tw = -1;
            if(!lose.empty()){
                tl = lose.front()[0];
                lose.pop();
            }
            else tl = -1;

            for(int r=0; r<results.size(); r++)
            {
                if(results[r][0] == tw)
                {
                    if(ch[0][results[r][1]-1] == false)
                    {
                        win.push(results[r]);
                        ch[0][results[r][1]-1] = true;
                        people++;
                    }
                }
                if(results[r][1] == tl)
                {
                    if(ch[1][results[r][0]-1] == false)
                    {
                         lose.push(results[r]);
                        ch[1][results[r][0]-1] = true;
                        people++;
                    }
                }
            }
        }
        if(people == n-1) answer++;
    }
    return answer;
}