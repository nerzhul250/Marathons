#include <iostream>
#include <vector>
#include <string>

using namespace std;
string permutation;
vector<int> ans;
int existence[60];
int n,found;
void num(){
    if(permutation.length()<10){
        n=permutation.length();
    }else{
        n=9+(permutation.length()-9)/2;
    }
}
int f(int i){
    if(i>=permutation.length()){
        found=1;
        return 1;
    }
    int res=0;
    int nam=permutation[i]-'0';
    if(!found && nam<=n && nam!=0 && !existence[nam]){
        existence[nam]=1;
        res=f(i+1);
        existence[nam]=0;
        if(res){ans.push_back(nam);return res;}
    }
    if(!found && permutation[i]!='0' && i+1<permutation.length()){
        int a=permutation[i]-'0';
        int b=permutation[i+1]-'0';
        int nam=a*10+b;
        if(nam<=n && !existence[nam]){
            existence[nam]=1;
            res=f(i+2);
            existence[nam]=0;
            if(res){ans.push_back(nam);return res;}
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> permutation){
        found=0;
        for(int i=0;i<60;i++){existence[i]=0;}
        ans.clear();
        num();
        f(0);
        for(int i=ans.size()-1;i>=0;i--){
            if(i==0){
                cout << ans[i] << endl;
            }else{
                cout << ans[i] << " ";
            }
        }
    }
    return 0;
}
