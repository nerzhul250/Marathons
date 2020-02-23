#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

int arcos[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int sum=0;
    fore(i,0,N){
        cin >> arcos[i];
        sum+=arcos[i];
    }
    if(sum%3!=0){
        cout << "0\n";
    }else{
        int PART=sum/3;
        int cnt=0;
        int i0=0,i1=0,i2=1;
        int sum1=arcos[0],sum2=arcos[1];
        while(i0<N){
            while(sum1<PART){
                i1=(i1+1)%N;
                sum1+=arcos[i1];
                sum2-=arcos[i1];
                if(i1==i2){
                    i2=(i2+1)%N;
                    sum2+=arcos[i2];
                }
            }
            if(sum1==PART){
                while(sum2<PART){
                    i2=(i2+1)%N;
                    sum2+=arcos[i2];
                }
                if(sum2==PART)cnt++;
                sum1-=arcos[i0];
                i0++;
            }else{
                while(i0<N && PART<sum1){
                    sum1-=arcos[i0];
                    i0++;
                }
            }
        }
        cout << cnt/3<<"\n";
    }
    return 0;
}
