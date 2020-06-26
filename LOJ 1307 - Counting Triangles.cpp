//LOJ 1307 - Counting Triangles
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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //fastIO;
    int T;
    scanf("%d", &T);

    for(int t=1; t<=T; t++)
    {

        int n; scanf("%d", &n);

        vector<int> v;
        for(int i=0; i<n; i++)
        {
            int val; scanf("%d", &val);
            v.push_back(val);
        }
        sort(all(v));

        ll res = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                int cnt = upper_bound(all(v), v[i]+v[j]-1) - v.begin() - 1;
                //dbg(v[i], v[j], cnt)
                res += (cnt - j);
            }
        }
        printf("Case %d: %d\n", t, res);
    }
    return 0;
}
