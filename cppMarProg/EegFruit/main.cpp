#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef long long int ll;

int mini[100005];
string cake;
int s;
int minimumIndex(int i){
    if(mini[i]!=-1)return mini[i];
    if(cake[i]=='E'){
        return mini[i]=i;
    }else{
        return mini[i]=minimumIndex((i+1)%cake.size());
    }
}

int hasE(){
    fore(i,0,cake.size()){
        if(cake[i]=='E'){
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    cin >> cake;
    cin >> s;

    if(!hasE()){
        cout << "0\n";
        return 0;
    }

    memset(mini,-1,sizeof mini);

    ll ans=0;

    fore(i,0,cake.size()){
        int theIndex=minimumIndex(i);
        if(theIndex<i){
            if(i+s>=cake.size()){
                int val=(((i+s)%cake.size())-theIndex);
                ans+=max(0,val);
            }
        }else{
            ans+=max(0,i+s-theIndex);
        }
    }

    cout << ans<<endl;

    return 0;
}
