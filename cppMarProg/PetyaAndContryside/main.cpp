#include <iostream>

using namespace std;
int garden[1005];
int dp[1005][5],n;
int wateredSections(int index, int param){
    if(dp[index][param]!=0)return dp[index][param];
    int l=0,r=0;
    if(param==0){
        if(index-1>=0 && garden[index-1]<=garden[index]){
            l=wateredSections(index-1,1);
        }
        if(index+1<n && garden[index+1]<=garden[index]){
            r=wateredSections(index+1,2);
        }
    }else if(param==1){
        if(index-1>=0 && garden[index-1]<=garden[index]){
            l=wateredSections(index-1,1);
        }
    }else{
        if(index+1<n && garden[index+1]<=garden[index]){
            r=wateredSections(index+1,2);
        }
    }
    return dp[index][param]=1+r+l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> garden[i];
    }
    int maximum=-1;

    for(int i=0;i<n;i++){
        maximum=max(maximum,wateredSections(i,0));
    }

    cout << maximum<<"\n";

    return 0;
}
