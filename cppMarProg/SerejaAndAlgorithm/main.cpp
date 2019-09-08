#include <iostream>
#include <algorithm>
using namespace std;
string str;
int xcount[1000005],ycount[1000005],zcount[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    int acumx=0,acumy=0,acumz=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='x'){
            acumx++;
        }else if(str[i]=='y'){
            acumy++;
        }else {
            acumz++;
        }
        xcount[i]=acumx;
        ycount[i]=acumy;
        zcount[i]=acumz;
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        if(r-l+1<=2){
            cout << "YES\n";
        }else{
            int numx,numy,numz;
            numx=xcount[r]-(l==0?0:xcount[l-1]);
            numy=ycount[r]-(l==0?0:ycount[l-1]);
            numz=zcount[r]-(l==0?0:zcount[l-1]);
            if(numy<numx)swap(numx,numy);
            if(numz<numx)swap(numx,numz);
            if(numz<numy)swap(numz,numy);
            if((numx==numy && numy==numz) ||
               (numx==numy && numy+1==numz) ||
               (numx+1==numy && numy==numz)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
