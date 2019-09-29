#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

pair<ll,ll> getNum(string str){
    ll nam=0;
    ll den=1;
    bool decimal=false;
    for(int i=0;i<str.size();i++){
        if(str[i]=='.'){
            decimal=true;
            continue;
        }
        nam*=10;
        nam+=(str[i]-'0');
        if(decimal){
            den*=10;
        }
    }
    return {nam,den};
}

ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<ll> integersSol;
    for(int i=0;i<N;i++){
        string R;
        cin >> R;
        pair<ll,ll> frac=getNum(R);
        integersSol.clear();
        for(int j=0;j<8;j++){
            double num=frac.first;
            double den=frac.second;
            ll integerPart=(ll)(num/den);
            ll integerPart=(frac.first-(frac.first%frac.second))/frac.second;
            integersSol.push_back(integerPart);
            ll firstNum=frac.second;
            ll secondNum=frac.first-frac.second*integerPart;
            frac={firstNum,secondNum};
        }
        pair<ll,ll> currentDen={1,integersSol[integersSol.size()-1]};
        for(int j=integersSol.size()-2;j>=0;j--){
            ll dencurr=integersSol[j]*currentDen.second+currentDen.first;
            currentDen.first=currentDen.second;
            currentDen.second=dencurr;
        }
        for(int j=0;j<integersSol.size();j++){
            if(j==integersSol.size()-1){
                cout << integersSol[j]<<"\n";
            }else{
                cout << integersSol[j] << " ";
            }
        }
        cout << currentDen.second << "/" << currentDen.first << "\n";
    }
    return 0;
}
