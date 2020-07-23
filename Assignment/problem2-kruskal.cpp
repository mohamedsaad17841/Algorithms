///a = 97  z = 122
///A = 65  Z = 90

#include <bits/stdtr1c++.h>

using namespace std;

#define endl                "\n"
#define pb                  push_back
#define ii                  pair<int, int>
#define mp                  make_pair
#define x                   first
#define y                   second
#define all(v)			    ((v).begin()), ((v).end())
#define sz(v)			    ((int)((v).size()))
#define ll                  long long
#define rep(i,n)            for(int i=0 ; i<sz(n) ; i++)
#define lp(i, n)            for(int i = 0 ; (int)i<n ; i++)
#define loop(i, x, n)       for(int i=x ; (int)i<=n ; i++)
#define ms(arr, v)      memset(arr, v, sizeof arr)
typedef vector<vector<char>> vcc;
typedef vector<int> vi;
typedef deque<int> de;

class unionFind {
private:
    vi p, rank;
public:
    unionFind(int n)
    {
        rank.assign(n+1, 0);
        p.assign(n+1, 0);
        lp(i, n+1) p[i] = i;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j)
    {
        if(!isSameSet(i,j))
        {
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y])
            {
                p[y] = x;
            }
            else
            {
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int m, n;
int x, y, z;
vector< pair<int, ii> > edgeList;
int mst_cost;   //minimum spannig tree cost
int totalCost;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    while(cin >> m >> n)
    {
        if(!m && !n) return 0;
        totalCost = 0;
        edgeList.clear();
        lp(i, n)
        {
            cin >> x >> y >> z;
            totalCost += z;
            edgeList.pb(mp(z, ii(x, y)));
        }
        sort(edgeList.begin(), edgeList.end());
        mst_cost = 0;   //minimum spannig tree cost
        unionFind UF(m+1);
        lp(i, n)    //loop on all edges
        {
            pair<int, ii> front = edgeList[i];
            if(!UF.isSameSet(front.second.first, front.second.second))
            {
                mst_cost += front.first;
                UF.unionSet(front.second.first, front.second.second);
            }
        }
        cout << totalCost - mst_cost << endl;
    }
    return 0;
}
