#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> primes;
int memo[5005][105];
int bp[1000];
/*if(j==-1)return 0;
    if(primes[j]>q){
        return f(q,j-1);
    }else{
        int res=q%primes[j];
        return ((q-res)/primes[j])+f(res,j-1);
    }*/
/*if(q==0)return 0;
    if(memo[q]!=0)return memo[q];
    int minimum=6000;
    for(int i=0;i<=j && primes[i]<=q;i++){
        minimum=min(minimum,1+f(q-primes[i],j));
    }
    return memo[q]=minimum;*/
    int f(int q,int j){
        if(q==0)return 0;
        if(q<0 || j<0)return 6001;
        if(memo[q][j]!=0)return memo[q][j];
        return memo[q][j]=min(f(q-primes[j],j)+1,f(q,j-1));
    }
int main()
{
    primes.push_back(1);
    for(int i=2;i<1000;i++){
        if(!bp[i]){
            primes.push_back(i);
            for(int j=2;j*i<1000;j++){
                bp[j*i]=1;
            }
        }
    }
    int t,n,q;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n >> q;
        int j=0;
        while(j+1<n&&primes[j+1]<=q)j++;
        cout << f(q,j) << endl;
    }
    return 0;
}
