#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 10000000
#define pii pair<int, int>
#define piii  pair<int, pair<int, int> >
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair


/*direction array*/

/***4 moves***/

int dx[] = { 0,  0, -1, +1 } ;
int dy[] = {-1, +1,  0,  0 };

/***8 moves***/
/*
int dx[] = { 0,  0, -1, -1, -1, +1, +1, +1 } ;
int dy[] = {-1, +1, -1,  0, +1, -1,  0, +1 } ;
*/


long long limit = 4294967296;
int MOD = 1000000007;
template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest)
{
    print(first);
    print(rest ...) ;
}

char adj[25][25];
bool visited[25][25];
int sx, sy, w, h;

int bfs()
{
    memset(visited, false, sizeof(visited));

    queue<pii> q;
    q.push(mp(sx, sy));
    visited[sx][sy] = true;
    int c = 0;

    while(!q.empty())
    {
        pii u = q.front();
        q.pop();
        c++;

        int x = u.first, y = u.second;

        //dbg(q.size(), x, y)

        for(int i=0; i<4; i++)
        {
            int vx = x + dx[i];
            int vy = y + dy[i];

            if(vx < 1 || vx > h || vy < 1 || vy > w)
                continue;
            if(visited[vx][vy] == true || adj[vx][vy] == '#')
                continue;

            q.push(mp(vx, vy));
            visited[vx][vy] = true;
        }
    }
    return c;
}

int main()
{

    int t; cin>>t;

    for(int k=1; k<=t; k++)
    {
        cin>>w>>h;
        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                cin>>adj[i][j];
                if(adj[i][j] == '@')
                    sx = i, sy = j;
            }
        }


        int c = bfs();
        printf("Case %d: %d\n",k, c);
    }

    return 0;
}
