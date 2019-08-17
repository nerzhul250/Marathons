#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d1,d2,e;
    cin >> d1 >> d2 >> e;
    int first=min(2*d1+2*e,2*d2+2*e);
    int second=min(2*d1+2*d2,d1+d2+e);
    cout << min(first,second) << "\n";
    return 0;
}
