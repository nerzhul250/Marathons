#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

struct Concert{
    int i,f,o,stage;
};

int N,theMask;
int dp[(1<<10)+5][86405];
map<int,vector<Concert>> conciertos;

int maxO(int mask,int time){
    if(time==86400){
        if(mask==theMask){
            return 0;
        }else{
            return -1e9;
        }
    }
    if(dp[mask][time]!=0)return dp[mask][time];
    int maximum=-1e9;
    if(conciertos.find(time)!=conciertos.end()){
        vector<Concert>concerts=conciertos[time];
        fore(i,0,concerts.size()){
            Concert con=concerts[i];
            maximum=max(maximum,con.o+maxO(mask|(1<<con.stage),con.f));
        }
    }
    auto it=conciertos.upper_bound(time);
    if(it==conciertos.end()){
        return dp[mask][time]=max(maximum,maxO(mask,86400));
    }else{
        return dp[mask][time]=max(maximum,maxO(mask,it->first));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    fore(i,0,N){
        int M;
        cin >> M;
        fore(j,0,M){
            int inicio,f,o;
            cin >> inicio >> f >> o;
            Concert con;
            con.i=inicio,con.f=f,con.o=o,con.stage=i;
            conciertos[inicio].pb(con);
        }
    }
    fore(i,0,N){
        theMask+=(1<<i);
    }
    int ans=maxO(0,1);
    cout <<(ans<0?-1:ans) <<"\n";
}
