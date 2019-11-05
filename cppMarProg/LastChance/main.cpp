#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    string s1;
    cin >> s1;
    string s2;
    forn(i,s1.size())s2+=(tolower(s1[i]));

    if(s2.size()==1){
        if(s2[0]=='a' ||s2[0]=='e' ||s2[0]=='i' ||s2[0]=='o' ||s2[0]=='u'){
            cout << "No solution\n";
        }else{
            cout << "1 1\n";
        }
        return 0;
    }

    s2="$"+s2;

    int arr[s2.size()+5];
    forn(i,s2.size()){
        if(s2[i]=='a' ||s2[i]=='e' ||s2[i]=='i' ||s2[i]=='o' ||s2[i]=='u'){
            arr[i]=-1;
        }else if(s2[i]=='$'){
            arr[i]=0;
        }else{
            arr[i]=2;
        }
    }
    int prefixes[s2.size()+5];
    prefixes[0]=arr[0];
    for(int i=1;i<s2.size();i++){
        prefixes[i]=prefixes[i-1]+arr[i];
    }
    int sk[s2.size()+5];
    sk[s2.size()-1]=prefixes[s2.size()-1];
    for(int i=s2.size()-2;i>=0;i--){
        sk[i]=max(prefixes[i],sk[i+1]);
    }
    int maxLength=0;
    forn(i,s2.size()){
        auto j=upper_bound(sk+i,sk+s2.size(),prefixes[i],greater<int>());
        maxLength=max(maxLength,((j-1)-(sk+i)));
    }
    int cnt=0;
    for(int i=1;i+maxLength-1<s2.size() && maxLength!=0;i++){
        if(prefixes[i+maxLength-1]-(i==0?0:prefixes[i-1])>=0){
            cnt++;
        }
    }
    if(maxLength==0){
        cout << "No solution\n";
    }else{
        cout << maxLength<<" "<<cnt << endl;
    }
    return 0;
}
