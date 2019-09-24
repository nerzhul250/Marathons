#include <iostream>

using namespace std;
int n,rows[2000005];
int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >>n){
        int left=0,right=0;
        for(int i=0;i<2*n;i++){
            cin>>rows[i];
            right=max(right,rows[i]);
        }
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            bool possible=true;
            int lookingFor=-1;
            for(int i=0;i<n;i++){
                if(rows[i]>mid){
                    if(lookingFor==-1){
                        lookingFor=rows[i];
                    }else if(lookingFor==rows[i]){
                        lookingFor=-1;
                    }else if(lookingFor!=rows[i]){
                        possible=false;
                        break;
                    }
                }
            }
            if(lookingFor!=-1)possible=false;
            if(possible){
                for(int i=n;i<n*2;i++){
                    if(rows[i]>mid){
                        if(lookingFor==-1){
                            lookingFor=rows[i];
                        }else if(lookingFor==rows[i]){
                            lookingFor=-1;
                        }else if(lookingFor!=rows[i]){
                            possible=false;
                            break;
                        }
                    }
                }
            }
            if(possible){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
