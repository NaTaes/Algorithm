// https://www.acmicpc.net/problem/17825

#include <iostream>
#define ENDPOINT        21

using namespace std;

typedef struct 
{
    char s_next;
    char next;
    char point;
} MapInfo;

int Dice[10];
int result;

int Horse[4];

MapInfo Map[33] = {{1, 1, 0}, {2, 2, 2}, {3, 3, 4}, {4, 4, 6}, {5, 5, 8}, {22, 6, 10},
                    {7, 7, 12}, {8, 8, 14}, {9, 9, 16}, {10, 10, 18}, {25, 11, 20},
                    {12, 12, 22}, {13, 13, 24}, {14, 14, 26}, {15, 15, 28}, {27, 16, 30},
                    {17, 17, 32}, {18, 18, 34}, {19, 19, 36}, {20, 20, 38}, {21, 21, 40},
                    {0, 0, 0}, {23, 23, 13}, {24, 24, 16}, {30, 30, 19}, {26, 26, 22}, {30, 30, 24},
                    {28, 28, 28}, {29, 29, 27}, {30, 30, 26}, {31, 31, 25}, {32, 32, 30}, {20, 20, 35}};

bool Horse_GO(int index, int cnt)
{
    int now = Map[Horse[index]].s_next;

    for(int i=1; i<cnt; i++)
    {
        if(now == ENDPOINT)
        {
            Horse[index] = now;
            return true;
        }
        now = Map[now].next;
    }

    for(int i=0; i<4; i++)
        if(Horse[i] == now) return false;

    Horse[index] = now;
    return true;
}

void GO(int count, int sum)
{
    if(count == 10)
    {
        result = result < sum ? sum : result;
        return;
    }
    
    int Horse_Backup[4];

    for(int i=0; i<4; i++)
    {
        if(Horse[i] == ENDPOINT) continue;
        Horse_Backup[i] = Horse[i];
        if(Horse_GO(i, Dice[count]))
            GO(count+1, sum+Map[Horse[i]].point);
        Horse[i] = Horse_Backup[i];
    }
}

int main(void)
{
    for(int i=0; i<10; i++)
        cin >> Dice[i];

    for(int i=0; i<4; i++)
    {
        Horse[i] = 0;
        Horse_GO(i, Dice[0]);
        GO(1, Map[Horse[i]].point);
    }

    cout << result << endl;
    return 0;
}