#include <iostream>
#include <bits/stdc++.h>
#include <list>

#define Max 100

using namespace std;

int N;
int r[Max];
int c[Max];
int mem[Max][Max];

void set_mem()
{
    for(int i = 0;i < Max;i++)
        for(int j = 0;j < Max;j++)
            mem[i][j] = -1;
}

int dp(int s,int e)
{
    if(s == e)
        return 0;
    if(mem[s][e] != -1)
        return mem[s][e];
    int mn = 1e9;
    for(int i = s; i < e ; i++)
        mn = min(mn,dp(s,i) + r[s]*c[i]*c[e] + dp(i+1,e));
    mem[s][e] = mn;
    return mem[s][e];
}
void build(int s,int e,string& res)
{
    if(s != e)
        res += '(' ;///cout << '(';
    else
    {
        stringstream ss;
        ss << s + 1;
        res += 'A' + ss.str() ;///cout << 'A' << s + 1;
    }

    int mn = 1e9;

    for(int i = s; i < e ; i++)
    {
        mn = dp(s,i) + r[s]*c[i]*c[e] + dp(i+1,e);
        if(mn == dp(s,e))
        {
            build(s,i,res);
            res += " x " ;///cout << " x ";
            build(i+1,e,res);
            break;
        }
    }
    if(s != e)
        res += ')' ;///cout << ')';
}

int main()
{
    list<string> res;
    cin >> N;
    while(N != 0)
    {
        set_mem();
        string s;
        for(int i = 0; i < N; i++)
            cin >> r[i] >> c[i];
        //cout << dp(0,N-1) << endl;
        build(0,N-1,s);
        res.push_back(s);
        cin >> N;
    }
    int i = 1;
    for(list<string>::iterator itr = res.begin(),temp; itr != res.end();itr++,i++)
    {
        cout << "Case " << i << ": " << *itr ;
        temp = itr;
        temp++;
        //if(temp != res.end())
            cout << '\n';
    }
    return 0;
}
