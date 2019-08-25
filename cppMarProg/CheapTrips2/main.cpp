#include <iostream>
#include <unordered_map>
#include <iomanip>

using namespace std;
int n,tripsD[10005],tripsC[10005];
unordered_map<int,double> dp[10005][125];
double cheapTrips(int pos,int tLeft,int trips){
    if(pos==n)return 0;
    if(dp[pos][trips].find(tLeft)!=dp[pos][trips].end())return dp[pos][trips][tLeft];
    if(tLeft==0|| trips>=6){
        return dp[pos][trips][tLeft]=tripsC[pos]+cheapTrips(pos+1,max(0,120-tripsD[pos]),1);
    }else{
        double discount=1;
        if(trips==1){
            discount=0.5;
        }else if(trips<6){
            discount=0.25;
        }
        return dp[pos][trips][tLeft]=min(discount*tripsC[pos]+cheapTrips(pos+1,max(0,tLeft-tripsD[pos]),trips+1),
                   tripsC[pos]+cheapTrips(pos+1,max(0,120-tripsD[pos]),1));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> tripsD[i] >> tripsC[i];
    }

    double f=cheapTrips(0,0,0);
    cout << fixed;
    cout << setprecision(2)<< f << "\n";
}
