//LOJ 1231 - Coin Change (I)
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

int coins[55], times[55];
int dp[55][1005];
int n, make;

int coin_change(int pos, int amount)
{
    if(amount == make) return 1;
    if(pos == n) return 0;
    if(dp[pos][amount] != -1) return dp[pos][amount];

    int mod = 100000007;

    int ret = 0;
    for(int i=0; i<=times[pos] && (i*coins[pos])+amount <= make; i++)
    {
        ret += coin_change(pos+1, amount + coins[pos] * i);
    }

    return dp[pos][amount] = ret % mod;
}

int main()
{
    //fastIO;
    int t;
    scanf("%d", &t);

    for(int T=1; T<=t; T++)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &n, &make);

        for(int i=0; i<n; i++) cin>>coins[i];
        for(int i=0; i<n; i++) cin>>times[i];

        printf("Case %d: %d\n", T, coin_change(0, 0));
    }
    return 0;
}
