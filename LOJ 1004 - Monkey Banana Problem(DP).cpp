//LOJ 1004 - Monkey Banana Problem(DP)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 100005
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI acos(-1)
#define all(a) a.begin(), a.end()
long long limit = 4294967296;
int MOD = 1000000007;
template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... anst)
{
    print(first);
    print(anst ...) ;
}

/*direction array*/

/***4 moves***/
/*
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
*/
/***8 moves***/
/*
int dx[] = { 0,  0, -1, -1, -1, +1, +1, +1 } ;
int dy[] = {-1, +1, -1,  0, +1, -1,  0, +1 } ;
*/

/*direction array ends*/

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b)
{
    return (a * (b / gcd(a, b)));
}

ll n, k;
ll dp[201][201];
ll grid[201][201];

int solve(int r, int c)
{
    if(grid[r][c] == 0)
        return 0;

    if(r == k-1)
        return grid[r][c];

    if(dp[r][c] != -1)
        return dp[r][c];

    int down = grid[r][c] + solve(r+1, c);
    int down_right = grid[r][c] + solve(r+1, c+1);

    return dp[r][c] = max(down, down_right);
}

int main()
{
    int T;
    scanf("%d", &T);

    for(int t=1; t<=T; t++)
    {
        scanf("%d", &n);

        memset(dp, -1, sizeof(dp));
        memset(grid, 0, sizeof(grid));

        k = 2 * n - 1;

        //upper part
        for(int i=0; i<n; i++)
            for(int j=0; j<=i; j++)
                scanf("%d", &grid[i][j]);

        //lower part
        int len = 1;
        for(int i=n; i<k; i++)
        {
            for(int j=len; j<n; j++)
                scanf("%d", &grid[i][j]);
            len++;
        }

        /*
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
        */


        printf("Case %d: %d\n", t, solve(0, 0));
    }
    return 0;
}
