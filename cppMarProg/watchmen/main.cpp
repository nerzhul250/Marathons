#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

int n;
vector<ii> coordinatesx;
vector<ii> coordinatesy;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        coordinatesx.push_back(ii(x,y));
        coordinatesy.push_back(ii(y,x));
    }
    sort(coordinatesx.begin(),coordinatesx.end());
    sort(coordinatesy.begin(),coordinatesy.end());
    ll sum=0;
    ll counter=1;
    for(int i=1;i<n;i++){
        if(coordinatesx[i].first==coordinatesx[i-1].first){
            counter++;
        }else{
            counter*=(counter-1);
            counter/=2;
            sum+=counter;
            counter=1;
        }
    }
    counter*=(counter-1);
    counter/=2;
    sum+=counter;

    counter=1;
    ll repeated=0;
    ll toSubstract=0;
    for(int i=1;i<n;i++){
        if(coordinatesy[i].first==coordinatesy[i-1].first){
            counter++;
        }else{
            counter*=(counter-1);
            counter/=2;
            sum+=counter;
            counter=1;
        }
        if(coordinatesy[i].second==coordinatesy[i-1].second &&
           coordinatesy[i].first==coordinatesy[i-1].first){
            repeated++;
        }else{
            repeated*=(repeated+1);
            repeated/=2;
            toSubstract+=(repeated);
            repeated=0;
        }
    }
    counter*=(counter-1);
    counter/=2;
    sum+=counter;

    repeated*=(repeated+1);
    repeated/=2;
    toSubstract+=(repeated);

    sum-=toSubstract;

    cout << sum << "\n";

}
