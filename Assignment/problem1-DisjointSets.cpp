///a = 97  z = 122
///A = 65  Z = 90

#include <bits/stdtr1c++.h>

using namespace std;

#define endl                "\n"
#define pb                  push_back
#define pii                 pair<int, int>
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

vi numOfNodes;
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
                numOfNodes[x] += numOfNodes[y];     //if we union 2 sets, union their num of nodes also
            }
            else
            {
                p[x] = y;
                numOfNodes[y] += numOfNodes[x];
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }

};

int q, n, m, a, b, res;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    cin >> q;
    while(q--)
    {
        cin >> n >> m;
        unionFind UF(n);
        numOfNodes.assign(n+1, 1);
        res = -1;
        lp(i, m)
        {
            cin >> a >> b;
            if(!UF.isSameSet(a, b))
                UF.unionSet(a,b);
        }
        rep(i, numOfNodes) res = max(res, numOfNodes[i]);
        cout << res << endl;
    }
    return 0;
}
