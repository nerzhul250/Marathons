#include <iostream>

using namespace std;
int arr[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,ori;
    cin >> t;
    ori=t;
    while(t--){
        int n,maximum=-1;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            if(i>0 && arr[i]-arr[i-1]>maximum)maximum=arr[i]-arr[i-1];
        }
        if(arr[0]>maximum)maximum=arr[0];
        int cS=maximum,possible=1;
        if(cS==arr[0])cS--;
        for(int i=1;i<n&&possible;i++){
            if(cS==arr[i]-arr[i-1]){
                cS--;
            }else if(cS<arr[i]-arr[i-1]){
                possible=0;
            }
        }
        if(possible){
            cout << "Case "<<ori-t<<": "<<maximum<<endl;
        }else{
            cout << "Case "<<ori-t<<": "<<maximum+1<<endl;
        }
    }
    return 0;
}
