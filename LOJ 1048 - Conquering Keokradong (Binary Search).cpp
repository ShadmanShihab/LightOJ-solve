//LOJ 1048 - Conquering Keokradong (Binary Search)
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

bool check(int ara[], int n, int k, int x)
{
    int c = 0;
    int rest = 0;
    for(int i=0; i<n+1; i++)
    {
        if(c + ara[i] > x)
        {
            if(ara[i] > x)
                return false;

            c = ara[i];
            rest++;
        }
        else
        {
            c += ara[i];
        }
    }

    if(rest <= k)
        return true;
    else
        return false;
}

void print_ans(int ara[], int n, int k, int ans)
{
    int c=0, rest = 0;
    n++;
    for(int i=0;i<n;i++){
        if(c+ara[i]>ans|| (k-rest+1)>n-i){
            printf("%d\n", c);
            c=ara[i];
            rest++;
        }
        else
            c+=ara[i];
    }
    printf("%d\n", c);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int t=1; t<=T; t++)
    {
        int n, k;
        scanf("%d %d", &n, &k);

        int ara[n+5];
        ll l = 1, r = 0, mid;

        for(int i=0; i<n+1; i++)
        {
            scanf("%d", &ara[i]);
            r += ara[i];
        }

        int ans = -1;
        while(l <= r)
        {
            mid = (l + r) / 2;

            if(check(ara, n, k, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        printf("Case %d: %d\n",t,ans);

        print_ans(ara, n, k, ans);
    }
    return 0;
}
