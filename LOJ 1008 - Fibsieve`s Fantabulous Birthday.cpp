//LOJ 1008 - Fibsieve`s Fantabulous Birthday

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    int kase=0, t;
    cin>>t;

    while(t--)
    {
        ll n, sq;
        cin>>n;

        sq = ceil(sqrt(n));

        ll row=0, col=0;
        ll temp = sq*sq - n;

        if(temp >= sq)
        {
            col = sq;
            row = n - (sq-1)*(sq-1);
        }
        else
        {
            col = temp + 1;
            row = sq;
        }

        if(sq % 2 == 0)
            swap(col, row);
        cout<<"Case "<<++kase<<": ";
        cout<<col<<" "<<row<<endl;
    }
    return 0;
}
