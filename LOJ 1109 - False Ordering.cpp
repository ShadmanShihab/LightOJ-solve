//LOJ 1109 - False Ordering
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 1005
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

bool cmp(const pair<int,int> &a,const pair<int,int> &b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}

vector<int> primes;
int mark[Max+2];

void sieve(ll n)
{
    mark[1]=1;
    for(int i=4; i<=n; i+=2)
    {
        mark[i]=1;
    }
    int limit=sqrt(n);
    for(int i=3; i<=limit; i+=2)
    {
        if(!mark[i])
        {
            for(int j=i*i; j<=n; j+=(2*i))
                mark[j]=1;
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(mark[i]==0)
            primes.push_back(i);
    }

}

int divisorCount(ll n)
{
    int res = 1;
    int limit = sqrt(n);
    for(int i=0; primes[i]*primes[i] <=n && primes[i]<=limit; i++)
    {
        int val = primes[i];
        if(n % val == 0)
        {
            int p = 0;
            while(n % val == 0)
            {
                n /= val;
                p++;
            }
            p++;
            res *= p;
        }
    }
    if(n != 1)
        res *= 2;

    return res;
}


int main()
{
    fastIO;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    sieve(1005);

    vector<pii> v;
    v.push_back({0, 0});
    for(int i=1000; i>=1; i--)
    {
        int nod = divisorCount(i);
        v.push_back({nod, i});
    }
    sort(v.begin(), v.end(), cmp);


    int t;
    cin>>t;

    for(int k=1; k<=t; k++)
    {
        int n; cin>>n;
        cout<<"Case "<<k<<": "<<v[n].second<<endl;
    }
    return 0;
}
