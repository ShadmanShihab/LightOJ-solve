//LOJ 1047 - Neighbor House
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

int n;
int dp[105][105];
int red[105], green[105], blue[105];


//0 for red
//1 for green
//2 for blue
int solve(int c, int prev)
{
    if(dp[c][prev] != -1)
        return dp[c][prev];

    if(c == n)
        return 0;

    if(c == 0)
    {
        int r = red[c] + solve(c+1, 0);
        int g = green[c] + solve(c+1, 1);
        int b = blue[c] + solve(c+1, 2);

        return dp[c][prev] = min(r, min(g, b));
    }
    else
    {
        if(prev == 0)
        {
            int g = green[c] + solve(c+1, 1);
            int b = blue[c] + solve(c+1, 2);

            return dp[c][prev] = min(g, b);
        }
        else if(prev == 1)
        {
            int r = red[c] + solve(c+1, 0);
            int b = blue[c] + solve(c+1, 2);

            return dp[c][prev] = min(r, b);
        }
        else
        {
            int r = red[c] + solve(c+1, 0);
            int g = green[c] + solve(c+1, 1);

            return dp[c][prev] = min(r, g);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    for(int t=1; t<=T; t++)
    {
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n; i++)
            scanf("%d %d %d", &red[i], &green[i], &blue[i]);

        printf("Case %d: %d\n", t, solve(0, 0));
    }
    return 0;
}
