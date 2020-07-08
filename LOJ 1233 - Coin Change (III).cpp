//LOJ 1233 - Coin Change (III)
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

ll dp[100005], coins[105], times[105];
ll n, m;

ll coin_change()
{
    ll coinsTaken[100005];

    for(int i=0; i<100005; i++)
    {
        dp[i] = 0;
        coinsTaken[i] = 1000000;
    }

    dp[0] = 1;
    coinsTaken[0] = 0;
    ll cnt = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=coins[i]; j<=m; j++)
        {
            if(dp[j-coins[i]] == 1 && dp[j]==0 && coinsTaken[j - coins[i]] + 1 <= times[i])
            {
                dp[j] = 1;
                cnt++;
                coinsTaken[j] = coinsTaken[j - coins[i]] + 1;
            }
        }

        for(int j=0; j<=m; j++)
            coinsTaken[j] = 0;
    }
    return cnt;
}
int main()
{
    //fastIO;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;

    scanf("%d", &t);

    for(int T=1; T<=t; T++)
    {
        cin>>n>>m;

        for(ll i=0; i<n; i++) cin>>coins[i];
        for(ll i=0; i<n; i++) cin>>times[i];


        printf("Case %d: %d\n", T, coin_change());
    }
    return 0;
}
