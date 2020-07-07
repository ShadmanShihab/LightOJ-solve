//LOJ 1232 - Coin Change (II)
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

ll dp[100009], coins[1000];
ll n, make;

ll coin_change()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    ll mod = 100000007;

    for(ll i=0; i<n; i++)
    {
        for(ll j=coins[i], k=0; j<=make; j++, k++)
        {
            //dp[j] += (dp[k] % mod);
            dp[j] = (dp[j] % mod) + (dp[j - coins[i]] % mod);
        }
    }
    return dp[make] % mod;
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
        cin>>n>>make;

        for(ll i=0; i<n; i++) cin>>coins[i];

        printf("Case %d: %d\n", T, coin_change());
    }
    return 0;
}
