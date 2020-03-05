#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pr pair<int,int>
#define loop(i,n) for(ll i=0 ; i<n ; i++)
#define rep(i,x,n) for(ll i=x ; i<=n ; i++)
#define PI 3.141592654

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=1e3 + 5,M=1e5+5, MOD=1e9 + 7 , OO=2e9;
vector<int> graph[N];
int n,m;
bool vis[N];
vector<int> teams;
int dist[N];
int main() {

   // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    loop(i,n-1){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin>>m;
    loop(i,m){
        int x;
        cin>>x;
        teams.push_back(x);
    }

    // bfs
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){		
        int u=q.front();
        q.pop();
        for(int v:graph[u]){
            if(vis[v])continue;
            vis[v]=1;
            dist[v]=dist[u]+1;		//dist will have the depth of the nodes
            q.push(v);
        }
    }
    sort(teams.begin(),teams.end());	//sort them because if we have 2 nodes with the same depth, will choose the less id (less number)
    int mn=1e9;
    int ans=-1;
    for(int x:teams){
        if(dist[x]<mn){
            mn=dist[x];
            ans=x;
        }
    }
    cout<<ans<<endl;
}
