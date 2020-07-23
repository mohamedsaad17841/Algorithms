// GROUP:   3
// ID:      20170212
// Assign:  04
// Assign:  CountInv
// UVA:     10810
// Name:    Mohamed Ahmed Saad Abouzaid


#include <iostream>

using namespace std;

void towerOfHanoi(int n, char from, char to, char rest)
{
    if(n == 1)
    {
        cout << "Disk 1 moved from " << from << " to " << to << endl;
        return;
    }
    towerOfHanoi(n-1, from, rest, to);
    cout << "Disk " << n << " moved from " << from << " to " << to << endl;
    towerOfHanoi(n-1, rest, to, from);
}

void towerGame(int n)
{
    towerOfHanoi(n, 'A', 'C', 'B');
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    towerGame(2);
}
