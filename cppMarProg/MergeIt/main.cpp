#include <iostream>

using namespace std;
int buff[4];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        buff[0]=0;
        buff[1]=0;
        buff[2]=0;
        while(n--){
            int x;
            cin >> x;
            buff[x%3]++;
        }
        int minAd=min(buff[1],buff[2]);
        buff[1]-=minAd;
        buff[2]-=minAd;
        cout << buff[0]+(buff[1]/3)+(buff[2]/3)+minAd<< endl;
    }
    return 0;
}
