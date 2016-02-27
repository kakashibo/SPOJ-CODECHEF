#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define sz size()
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
#define N 111111
int v[N], RM[N], depth[N], maxi = 0;
vector <int> adj[N];
map <int, int> M;
int main()
{
    int n, m;

    scanf("%d%d", &n, &m);
    rep(i, n)
    {
        scanf("%d", &v[i]);
        M[v[i]];
    }
    maxi = 0;
    for( map <int, int > :: iterator it = M.begin(); it != M.end(); it++ )
    {
        cout<<it->first<<" "<<maxi<<" "<<it->second<<endl;
        M[it->first] = maxi;
        RM[maxi] = it->first;
        maxi++;
        cout<<it->first<<" "<<maxi<<" "<<it->second<<endl;
    }
    rep(i, n-1)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    return 0;
}
