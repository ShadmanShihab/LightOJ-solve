//LOJ 1099 - Not the Best
#include <bits/stdc++.h>
using namespace std;

#define Max 5010
#define pii pair<int, int>
#define ll long long

vector<pii> adj[Max];
int n;
vector<ll> dis[Max];

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push({0, s});


    while(!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if(dis[u].size() == 0 || dis[u].back() != w)
            dis[u].push_back(w);

        if(dis[u].size() > 2) continue;

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int c = adj[u][i].second;

            if(dis[v].size() >= 2)
                continue;

            int dis = c + w;
            pq.push({dis, v});
        }
    }

    cout<<dis[n][1]<<endl;
}

int main()
{
    int m, t;
    cin>>t;

    for(int ks=1; ks<=t; ks++)
    {
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            int a, b, w; cin>>a>>b>>w;

            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        cout<<"Case "<<ks<<": ";
        dijkstra(1);

        vector <pii> t1[Max];
        vector <ll> t2[Max];
        swap (t1, adj);
        swap (t2, dis);
    }
    return 0;
}
