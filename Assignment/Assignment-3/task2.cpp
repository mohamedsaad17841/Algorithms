#include <iostream>
#include <deque>
#include <math.h>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;

int N;
pair<double,double> pairs[100001];

double closest_pair(int l,int r)
{
    if(l >= r)
        return INT_MAX;

    int mid = l + (r - l) / 2;
    double dist = min(closest_pair(l, mid) ,closest_pair(mid + 1, r)), dist2;
    deque<pair<double,double>> left_intermediate, right_intermediate;

    for(int i = mid ;i >= l && pairs[mid].first - pairs[i].first <= dist;i--)
        left_intermediate.push_back(pairs[i]);

    for(int i = mid + 1 ;i <= r && pairs[i].first - pairs[mid].first <= dist;i++)
        right_intermediate.push_back(pairs[i]);

    for(unsigned int i = 0;i < left_intermediate.size();i++)
        for(unsigned int j = 0;j < right_intermediate.size();j++)
        {
            double frst = right_intermediate[j].second - left_intermediate[i].second;
            double scnd = right_intermediate[j].first - left_intermediate[i].first;
            dist2 = sqrt(frst*frst +
                         scnd*scnd);
            dist = min(dist2,dist);
        }
    return dist;
}

double closest_pair()
{
    sort(pairs, pairs + N);
    return closest_pair(0, N - 1);
}
int main()
{
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
    while(cin >> N)
    {
        if(!N) break;

        for(int i = 0;i < N;i++)
            cin >> pairs[i].first >> pairs[i].second;
        double res = closest_pair();
        if(res < 10000) cout <<fixed<<setprecision(4)<< res << endl;
        else            cout << "INFINITY" << endl;
    }
    return 0;
}