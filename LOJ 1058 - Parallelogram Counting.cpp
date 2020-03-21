//LOJ 1058 - Parallelogram Counting
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t, n, kase=0;
    cin>>t;

    while(t--)
    {
        vector<pair<ll, ll>> v;

        cin>>n;

        ll x[n+5], y[n+5];
        for(int i=0; i<n; i++)
        {
            cin>>x[i]>>y[i];
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                ll tx = x[i] + x[j];
                ll ty = y[i] + y[j];

                v.push_back(make_pair(tx, ty));
            }
        }



        sort(v.begin(), v.end());

        ll c = 0, cnt=1;
        for(ll i=0; i<v.size()-1; i++)
        {
            if(v[i].first == v[i+1].first && v[i].second==v[i+1].second)
                cnt++;
            else
            {
                c += (cnt * (cnt-1)) / 2;
                cnt = 1;
            }
        }
        cout<<"Case "<<++kase<<": "<<c<<endl;
    }
    return 0;
}
