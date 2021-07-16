// https://www.acmicpc.net/problem/17837

#include <iostream>

using namespace std;

int N, K, count=1;
int NN[12][12];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

typedef struct
{
    int x;
    int y;
    int dir;
    int prev;
    int next;
}CHESS;

CHESS piece[10];

void Go(int x, int y, int idx)
{
    piece[idx].x = x;
    piece[idx].y = y ;

    for(int i=0; i<K; i++)
    {
        if(idx == i) continue;
        if(piece[i].x == x && piece[i].y == y)
        {
            int mi = i;
            while(piece[mi].next != mi)
            {
                mi = piece[mi].next;
            }
            piece[mi].next = idx;
            piece[idx].prev = mi;
            break;
        }
    }

    while(piece[idx].next != idx)
    {
        piece[piece[idx].next].x = x;
        piece[piece[idx].next].y = y;

        idx = piece[idx].next;
    }
}

int Height(int index)
{
    int result = 0;
    int idx = index;
    
    while(piece[idx].next != idx)
    {
        idx = piece[idx].next;
        result++;
    }

    idx = index;
    while(piece[idx].prev != idx)
    {
        idx = piece[idx].prev;
        result++;
    }

    return result + 1;
}

int Move(int index)
{
    int x = piece[index].x;
    int y = piece[index].y;
    int dir = piece[index].dir;

    int mx = x + dx[dir];
    int my = y + dy[dir];

    if(mx < 0 || my < 0 || mx > N-1 || my > N-1 || NN[mx][my] == 2)
    {
        if(dir % 2 == 0) dir++;
        else dir--;

        piece[index].dir = dir;

        mx = x + dx[dir];
        my = y + dy[dir];

        if(mx < 0 || my < 0 || mx > N-1 || my > N-1 || NN[mx][my] == 2)
        {
            return Height(index);
        }
    }
    
    if(piece[index].prev != index)
    {
        piece[piece[index].prev].next = piece[index].prev;
    }

    piece[index].prev = index;

    if(NN[mx][my] == 1)
    {
        int midx = index;
        int tmp;
        
        while(piece[midx].next != midx)
        {
            tmp = piece[midx].prev;
            piece[midx].prev = piece[midx].next;
            piece[midx].next = tmp;

            midx = piece[midx].prev;
        }

        tmp = piece[midx].prev;
        piece[midx].prev = piece[midx].next;
        piece[midx].next = tmp;

        Go(mx, my, midx);
    }
    else
        Go(mx, my, index);

    return Height(index);
}

int main(void)
{
    cin >> N >> K;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> NN[i][j];

    for(int i=0; i<K; i++)
    {
        cin >> piece[i].x >> piece[i].y >> piece[i].dir;
        piece[i].x--;
        piece[i].y--;
        piece[i].dir--;
        piece[i].prev = i;
        piece[i].next = i;
    }
    
    int index = 0;

    while(count <= 1000)
    {
        if(index > K-1)
        {
            index = 0;
            count++;
        }

        if(Move(index) > 3)
        {
            cout << count << endl;
            return 0;
        }

        index++;
    }

    cout << -1 << endl;
    return 0;
}