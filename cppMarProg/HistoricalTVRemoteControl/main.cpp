#include <iostream>
#include <string.h>

using namespace std;
int n,target,invalid[15];
bool valid(string schannel){
    for(int i=0;i<schannel.size();i++){
        if(invalid[((schannel[i])-'0')])return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int nam=0;
        cin >> nam;
        invalid[nam]=1;
    }
    cin >> target;
    int minimum=1000000;
    for(int channel=0;channel<=999;channel++){
        string schannel=to_string(channel);
        int distance=abs(channel-target);
        if(valid(schannel) && distance<minimum)minimum=distance;
    }
    cout << minimum << "\n";
}
