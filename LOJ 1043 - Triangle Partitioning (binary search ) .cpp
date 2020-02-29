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

double find_ratio(double ab, double ac, double bc, double ad)
{
    double ae = (ad * ac) / ab, de = (ad * bc) / ab;
    double s1 = (ad + de + ae)/2.0 , s2 = (ab + bc + ac) / 2.0;

    double triangle = sqrt( s1 * (s1 - ad) * (s1 - de) * (s1 - ae) );
    double total_area = sqrt( s2 * (s2 - ab) * (s2 - ac) * (s2 - bc) );
    double trapezium = total_area - triangle;

    double r = triangle / trapezium;
    return r;
}

int main()
{
    freopen("in.txt", "r", stdin);
    fastIO;

    int T; cin>>T;

    for(int t=1; t<=T; t++)
    {
        printf("Case %d: ", t);
        double ab, ac, bc, r, ad; cin>>ab>>ac>>bc>>r;

        //bs
        double low, high, mid;
        low = 0.0;
        high = ab;

        for(int i=0; i<100; i++)
        {
            mid = (low + high) / 2.0;
            ad = mid;

            double temp = find_ratio(ab, ac, bc, mid);

            if(temp > r)
                high = mid;
            else
                low = mid;
        }

        printf("%0.10f\n", ad);
    }
    return 0;
}
