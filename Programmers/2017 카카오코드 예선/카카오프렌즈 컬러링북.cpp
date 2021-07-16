/* https://programmers.co.kr/learn/courses/30/lessons/1829 */

#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void DFS(vector<vector<int>>& bk, int x, int y, int target, int& area, int& mx_area)
{
    mx_area = area > mx_area ? area : mx_area;
    bk[x][y] = 0;

    for(int n=0; n<4; n++)
    {
        int mx = x + dx[n];
        int my = y + dy[n];
        if(mx < 0 || my < 0 || mx > bk.size() -1 || my > bk[0].size() - 1 || bk[mx][my] != target) continue;

        DFS(bk, mx, my, target, ++area, mx_area);
    }

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<vector<int>> Book(m, vector<int>(n, 0));
    vector<pair<int, int>> pnt;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            Book[i][j] = picture[i][j];
            if(picture[i][j] != 0)
            {
                pnt.push_back({i, j});
            }
        }
    }



    for(int i=0; i<pnt.size(); i++)
    {
        if(Book[pnt[i].first][pnt[i].second] != 0)
        {
            number_of_area++;

            int size_area = 1;
            DFS(Book, pnt[i].first, pnt[i].second, Book[pnt[i].first][pnt[i].second], size_area, max_size_of_one_area);
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}