#include <bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3

int g[100][100];
int n, e, Time = 1;
int color[100],startingTime[100],finishingTime[100];
stack<int> ans;
void dfsVisit(int x)
{
    startingTime[x] = Time++;
    color[x] = GRAY;
    for (int i = 0; i < n; i++)
    {
        if (g[x][i] == 1)
        {
            if (color[i] == WHITE)
            {
                dfsVisit(i);
            }
        }
    }
    finishingTime[x] = Time++;
    color[x] = BLACK;
    ans.push(x);
}

void dfs()
{
    for (int i = 0; i < n; i++)
    {
        color[i] = WHITE;
    }
    for (int i = 0; i < n; i++)
    {
        if (color[i] == WHITE)
        {
            dfsVisit(i);
        }
    }
    while(!ans.empty()){
        int temp = ans.top();
        ans.pop();
        cout << temp << " ";
    }
}

int main()
{

    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    dfs();
}