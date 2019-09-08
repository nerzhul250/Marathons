#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

vll wasteCells;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,t;
    cin >> n >> m >> k >> t;
    wasteCells.push_back(-1);
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        wasteCells.push_back(a*m+b);
    }
    wasteCells.push_back(m*n);
    sort(wasteCells.begin(),wasteCells.end());
    for(int i=0;i<t;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        ll targetCell=a*m+b;
        int j=1;
        int index=0;
        while((j<wasteCells.size()) && (targetCell>wasteCells[j])){
            ll toAdd=max(wasteCells[j]-wasteCells[j-1]-1,(ll)0);
            index=(index+toAdd)%3;
            j++;
        }
        if(targetCell==wasteCells[j]){
            cout << "Waste\n";
        }else{
            index=(index+max(targetCell-wasteCells[j-1]-1,(ll)0))%3;
            if(index==0){
                cout << "Carrots\n";
            }else if(index==1){
                cout << "Kiwis\n";
            }else{
                cout << "Grapes\n";
            }
        }
    }
    return 0;
}
