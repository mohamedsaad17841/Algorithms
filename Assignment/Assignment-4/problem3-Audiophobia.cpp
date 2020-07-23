
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

int const C = 1e2 + 10;
int decibels[C][C];
int c, s, q;
int c1, c2, d;
int Case;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    while(cin >> c >> s >> q)
    {
        if(!c && !s && !q) return 0;
        if(Case) cout << endl;      //if this wasn't the first time
        loop(i, 1, c) loop(j, 1, c) { decibels[i][j] = INT_MAX; }
        lp(i, s)
        {
            cin >> c1 >> c2 >> d;
            decibels[c1][c2] = decibels[c2][c1] = d;
        }
        //I don't need to sum the decibels of the whole path, I only need to know the maximum decibels of that path.
        loop(k, 1, c) loop(i, 1, c) loop(j, 1, c)   {decibels[i][j] = decibels[j][i] = min(decibels[i][j], max(decibels[i][k], decibels[k][j]));}
        cout << "Case #" << ++Case << endl;
        lp(i, q)
        {
            cin >> c1 >> c2;
            (decibels[c1][c2] == INT_MAX) ? cout << "no path\n" : cout << decibels[c1][c2] << endl;
        }
    }
    return 0;
}
