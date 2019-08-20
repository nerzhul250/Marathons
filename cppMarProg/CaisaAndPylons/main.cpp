#include <iostream>

using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cin >> n;
    int maximum=-1;
    for(int i=0;i<n;i++){
        int nam=0;
        cin >> nam;
        if(nam>maximum)maximum=nam;
    }
    cout << maximum;
}
