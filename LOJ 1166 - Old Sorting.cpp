//LOJ 1166 - Old Sorting
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 10000
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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
    //fastIO;

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T; cin>>T;

    for(int k=1; k<=T; k++)
    {
        int n; cin>>n;
        int ara[n+5];
        for(int i=1; i<=n; i++)
        {
            cin>>ara[i];
        }

        int c = 0;
        for(int i=1; i<=n; i++)
        {
            if(i != ara[i])
            {
                for(int j=i+1; j<=n; j++)
                {
                    if(ara[j] == i)
                    {
                        c++;
                        swap(ara[i], ara[j]);
                        break;
                    }
                }
            }
        }


        printf("Case %d: %d\n", k, c);
    }
    return 0;
}



