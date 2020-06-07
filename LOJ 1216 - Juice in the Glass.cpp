//LOJ 1216 - Juice in the Glass
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

int main()
{
    int t; cin>>t;

    for(int k=1; k<=t; k++)
    {
        double r1, r2, h, p;
        scanf("%lf %lf %lf %lf", &r1, &r2, &h, &p);

        double x = (r2 * h) / (r1 - r2);
        double r = r2 + (p * (r1-r2) / h);

        double v =  ( (PI*r*r*(p+x))  - (PI*r2*r2*x)  ) / 3;

        printf("Case %d: %0.9lf\n", k, v);
    }
    return 0;
}
