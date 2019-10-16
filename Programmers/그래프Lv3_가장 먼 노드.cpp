#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<bool> ch(n, false);
    queue<int> que;
    ch[1] = true;

    for(int i=0; i<edge.size(); i++)
    {
        if(edge[i][0] != 1 && edge[i][1] != 1) continue;
        int next = edge[i][0] == 1 ? edge[i][1] : edge[i][0];
        que.push(next);
        ch[next] = true;
    }

    while(!que.empty())
    {
        int size = que.size();
        int nodeCount = 0;

        for(int i=0; i<size; i++)
        {
            int node = que.front();
            que.pop();

            for(int n=0; n<edge.size(); n++)
            {
                if(edge[n][0] != node && edge[n][1] != node) continue;
                int next = edge[n][0] == node ? edge[n][1] : edge[n][0];
                if(ch[next]) continue;
                que.push(next);
                ch[next] = true;
                nodeCount++;
            }
        }
        if(nodeCount != 0) answer = nodeCount;
    }
    return answer;
}