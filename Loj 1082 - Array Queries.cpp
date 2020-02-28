//	1082 - Array Queries
//segment tree
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pfi(n) printf("%d\n", n)
#define sci(n) scanf("%d", &n)
#define rep(i, n) for(int i=0; i<n; i++)
#define repi(i, n) for(int i=1; i<=n; i++)
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Max 100005
#define pii pair<string, ll>
#define mp make_pair
template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest)
{
    print(first);
    print(rest ...) ;
}

int ara[Max], tree[Max*3];

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = ara[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid+1, e);

    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)  //out of range
        return INT_MAX;

    if(b >= i && e <= j)
        return tree[node];

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    return min(p1 ,  p2);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    fastIO;

    int t, n, q;
    cin>>t;

    for(int ks=1; ks<=t; ks++)
    {
        cout<<"Case "<<ks<<":\n";
        cin>>n>>q;

        for(int i=1; i<=n; i++)
             cin>>ara[i];
        init(1, 1, n);

        while(q--)
        {
             int l, r; cin>>l>>r;
             cout<<query(1, 1, n, l, r)<<endl;
        }
    }
    return 0;
}
