#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int N;
    cin >> N;
    while(N--){
        int k,m;
        cin >> m >> k;
        ll arr[m+5];
        ll sum=0;
        for(int i=0;i<m;i++){
            cin >> arr[i];
            sum+=arr[i];
        }
        ll minimo=1e15;
        ll i=1,j=sum;
        while(i<=j){
            ll mid=(i+j)/2;
            int possible=0;

            int cnt=0;
            ll suma=0;
            for(int index=0;index<m;index++){
                if(arr[index]>mid){
                    cnt=k+1;
                    break;
                }
                if(arr[index]+suma>mid){
                    cnt++;
                    suma=arr[index];
                }else{
                    suma+=arr[index];
                }
            }

            if(cnt<k)possible=1;

            if(possible){
                j=mid-1;
                minimo=mid;
            }else{
                i=mid+1;
            }
        }
        sum=0;
        k--;
        vector<int> ans;
        for(i=m-1;i>=0;i--){
            if(arr[i]+sum>minimo){
                k--;
                sum=arr[i];
                ans.insert(ans.begin(),-1);
                ans.insert(ans.begin(),arr[i]);
            }else if(k+1==i+1){
                for(j=i;j>=0;j--){
                    ans.insert(ans.begin(),arr[j]);
                    if(j!=0)ans.insert(ans.begin(),-1);
                }
                break;
            }else{
                sum+=arr[i];
                ans.insert(ans.begin(),arr[i]);
            }
        }

        for(i=0;i<ans.size();i++){
            if(i==ans.size()-1){
                cout <<ans[i] <<"\n";
            }else{
                if(ans[i]==-1){
                    cout <<"/ ";
                }else{
                    cout<<ans[i]<<" ";
                }
            }
        }

    }
    return 0;
}
