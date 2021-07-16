/* https://programmers.co.kr/learn/courses/30/lessons/1844 */

#include<vector>
#include<queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int count = 1;

    queue<pair<int, int>> que;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    que.push({0, 0});

    while(!que.empty())
    {
        int size = que.size();

        for(int s=0; s<size; s++)
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            maps[0][0] = 0;

            for(int n=0; n<4; n++)
            {
                int mx = x + dx[n];
                int my = y + dy[n];

                if(mx < 0 || my < 0 || mx > maps.size()-1 || my > maps[0].size()-1) continue;
                if(maps[mx][my] == 0) continue;
                if(mx == maps.size()-1 && my == maps[0].size()-1) return count+1;

                que.push({mx, my});
                maps[mx][my] = 0;
            }
        }
        count++;
    }

    return answer;
}