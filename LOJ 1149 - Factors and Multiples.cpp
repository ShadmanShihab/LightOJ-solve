#include <bits/stdc++.h>
using namespace std;

#define Max 200


int a[Max], b[Max];
vector<int> adj[Max];
int visited[Max], match[Max];

int dfs(int u)
{
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(visited[v]==1) continue;
        visited[v]=1;
        if(match[v]==-1||dfs(match[v]))
        {
            match[v]=u;
            return 1;
        }
    }
    return 0;
}


int main()
{
    int T, n1, n2;
    cin>>T;

    for(int t=1; t<=T; t++)
    {
        memset(match, -1, sizeof(match));
        memset(adj, 0, sizeof(adj));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));

        cin>>n1;
        for(int i=0; i<n1; i++) cin>>a[i];


        cin>>n2;
        for(int i=0; i<n2; i++) cin>>b[i];

        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                if(b[j] % a[i] == 0)
                    adj[i].push_back(j);
            }
        }

        int res = 0;
        for(int i=0; i<n1; i++)
        {
            memset(visited, 0, sizeof(visited));
            res += dfs(i);
        }
        printf("Case %d: ", t);
        cout<<res<<endl;
    }
    return 0;
}
