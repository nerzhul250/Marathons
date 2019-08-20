#include <iostream>

using namespace std;
int n,days[400];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int num=0;
        cin >> num;
        days[num]=1;
    }
    int dirtiness=0;
    int toSum=0;
    int timesCleaned=0;
    for(int i=1;i<=365;i++){
        dirtiness+=toSum;
        if(dirtiness>=20){
            timesCleaned++;
            toSum=0;
            dirtiness=0;
        }
        if(days[i]){
            toSum++;
        }
    }
    if(dirtiness>0 || toSum>0)timesCleaned++;
    cout << timesCleaned << "\n";
}
