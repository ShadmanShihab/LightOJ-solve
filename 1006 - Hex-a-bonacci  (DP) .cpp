//Light OJ 1006 Hexabonacci
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define  max 10010

int main()
{
    ll ara[max], n;
    int T;
    scanf("%d", &T);

    for(int i=1; i<=T; i++)
    {
        for(int j=0; j<6; j++)
            scanf("%lld", &ara[j]);

        scanf("%lld", &n);

        for(int k=6; k<=n; k++)
            ara[k] = (ara[k-1]+ara[k-2]+ara[k-3]+ara[k-4]+ara[k-5]+ara[k-6]) % 10000007;

        printf("Case %d: %lld\n", i, ara[n] % 10000007);
    }
    return 0;
}
