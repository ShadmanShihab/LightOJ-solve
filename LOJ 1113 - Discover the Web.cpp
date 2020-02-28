#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 1000000
#define piii  pair<int, pair<int, int> >
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair
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

bool cmp(pii a, pii  b)
{
    if(a.first < b.first)
        return a.first < b.first;
    return a.second < b.second;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;
    int t; cin>>t;

    for(int k=1; k<=t; k++)
    {
        cout<<"Case "<<k<<":\n";
        string str, current="http://www.lightoj.com/", temp;
        stack<string> b;
        stack<string> f;

        while(1)
        {
            cin>>str;
            if(str == "QUIT") break;
            if(str == "VISIT")
            {
                cin>>temp;
                if(current != "")
                    b.push(current);
                current = temp;
                cout<<current<<endl;

                while(f.size() != 0)
                    f.pop();
            }
            else if(str == "BACK")
            {
                if(b.size() == 0)
                {
                    cout<<"Ignored\n";
                }
                else
                {
                    f.push(current);
                    current = b.top();
                    b.pop();
                    cout<<current<<endl;
                }
            }
            else if(str == "FORWARD")
            {
                if(f.size() == 0)
                {
                    cout<<"Ignored\n";
                }
                else
                {
                    b.push(current);
                    current = f.top();
                    f.pop();
                    cout<<current<<endl;
                }
            }
        }
    }
    return 0;
}
