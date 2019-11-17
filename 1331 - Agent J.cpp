#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 100005
#define pii pair<int, int>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

long long limit = 4294967296;
int MOD = 1000000007;
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

int visited[1000005] = {0};

int main()
{
    //freopen("in.txt", "r", stdin);

    fastIO;

    int T; cin>>T;
    for(int k=1; k<=T; k++)
    {
        double r1, r2, r3; cin>>r1>>r2>>r3;
        double A, B, C, a, b, c, s, area1, area2, area3, triangle;

        a = r1 + r2;
        b = r2 + r3;
        c = r3 + r1;
        s = (a+b+c) / 2;
        triangle = sqrt(s * (s-a) * (s-b) * (s-c));

        A = acos((a*a+c*c-b*b) / (2*a*c));
        area1 = 0.5 * r1*r1* A;


        B = acos((a*a + b*b - c*c) / (2*b*a));
        area2 = 0.5 * r2*r2 * B;

        C = acos((b*b + c*c - a*a) / (2*b*c));
        area3 = 0.5 *r3*r3* C;

        printf("Case %d: %f\n", k, triangle-(area1+area2+area3));
    }
    return 0;
}
