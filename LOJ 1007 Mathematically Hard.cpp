//LOJ 1007 Mathematically Hard
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 5000005
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

vector<ull> phi(Max);

void phi_1_to_n(int n)
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (ll i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for(int j = i; j <= n; j += i)
                phi[j] = phi[j]/i * (i-1);
        }
    }

    for(int i=1; i<=n; i++)
    {
        phi[i] = phi[i] * phi[i];
        phi[i] += phi[i-1];
    }
}

int main()
{
    fastIO;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    phi_1_to_n(5000005);

    int t; cin>>t;
    for(int k=1; k<=t; k++)
    {
        ull a, b; cin>>a>>b;
        ull res = phi[b] - phi[a-1];
        cout<<"Case "<<k<<": "<<res<<endl;
    }
    return 0;
}
