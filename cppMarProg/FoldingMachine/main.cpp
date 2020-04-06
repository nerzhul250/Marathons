#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
set<string> estados;
int N,M;
void go(string s){
    if(estados.count(s)>0)return;
    estados.insert(s);
    vector<int> nums;
    int n=0;
    fore(i,0,s.size()){
        if(s[i]==','){
            nums.pb(n);
            n=0;
        }else{
            n*=10;
            n+=(s[i]-'0');
        }
    }
    if(nums.size()==1)return;
    fore(i,0,nums.size()){
        int left=i-1;
        int right=i;
        while(left>0 || right<nums.size()-1){
            left--;
            right++;
        }
        string str;
        while(left<right){
            int theNum=(left>=0?nums[left]:0)+(right<nums.size()?nums[right]:0);
            str+=to_string(theNum);
            str+=',';
            left++;
            right--;
        }
        go(str);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    string s;
    fore(i,0,N){
        int a;
        cin >> a;
        s+=to_string(a);
        s+=',';
    }
    string s2;
    cin >> M;
    fore(i,0,M){
        int a;
        cin >> a;
        s2+=to_string(a);
        s2+=',';
    }
    go(s);
    if(estados.count(s2)>0){
        cout << "S\n";
    }else{
        cout << "N\n";
    }
}
