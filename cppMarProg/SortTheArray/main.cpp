#include <iostream>

using namespace std;
int arr[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int stage=0;
    int l=1,r=1;
    for(int i=0;i<n-1;i++){
        if(stage==0 && arr[i+1]<arr[i]){
            stage=1;
            l=i;
        }else if(stage==1 && arr[i+1]>arr[i]){
            stage=2;
            r=i;
        }else if(stage==2 && arr[i+1]<arr[i]){
            stage=3;
            break;
        }
    }
    if(stage==0){
        cout << "yes\n";
        cout << "1 1\n";
    }else if(stage==1){
        if(arr[l-1]<=arr[n-1]){
            cout << "yes\n";
            cout << l+1<<" "<<n<<"\n";
        }else{
            cout << "no\n";
        }
    }else if(stage==2){
        if(arr[l-1]<=arr[r] && arr[l]<=arr[r+1]){
            cout << "yes\n";
            cout << l+1<<" "<<r+1<<"\n";
        }else{
            cout << "no\n";
        }
    }else if(stage==3){
        cout << "no\n";
    }
    return 0;
}
