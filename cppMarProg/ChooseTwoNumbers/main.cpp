#include <iostream>
#include <algorithm>
using namespace std;
int n,m,arrayA[105],arrayB[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++)cin >> arrayA[i];
    cin >> m;
    for(int i=0;i<m;i++)cin >> arrayB[i];
    sort(arrayA,arrayA+n);
    sort(arrayB,arrayB+m);
    cout << arrayA[n-1] << " "<<arrayB[m-1] << "\n";
}
