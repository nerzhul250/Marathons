#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;

int arr[100005];

int LSOne(int b){
    return (b & (-b));
}

class FenwickTree{
    private: vi ft;
    public: FenwickTree(int n){ft.assign(n+1,0);};
    int rsq(int b){
        int sum=0;for(;b;b-=LSOne(b))sum+=ft[b];
        return sum;
    }
    int rsq(int a,int b){
        return rsq(b)-(a==1?0:rsq(a-1));
    }
    void adjust(int k,int v){
        for(;k<(int)ft.size();k+=LSOne(k))ft[k]+=v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int N,K;
    while(cin >> N>>K){
        FenwickTree ft1(N);
        FenwickTree ft2(N);
        for(int i=1;i<=N;i++){
            cin >> arr[i];
            if(arr[i]<0){
                ft1.adjust(i,1);
            }else if(arr[i]==0){
                ft2.adjust(i,1);
            }
        }

        for(int i=0;i<K;i++){
            char type;
            int a,b;
            cin >> type >>a>>b;
            if(type=='C'){
                if(arr[a]<0){
                    ft1.adjust(a,-1);
                }else if(arr[a]==0){
                    ft2.adjust(a,-1);
                }
                arr[a]=b;
                if(arr[a]<0){
                    ft1.adjust(a,1);
                }else if(arr[a]==0){
                    ft2.adjust(a,1);
                }
            }else if(type=='P'){
                if(ft2.rsq(a,b)>0){
                    cout << "0";
                }else if(ft1.rsq(a,b)%2!=0){
                    cout <<"-";
                }else{
                    cout <<"+";
                }
            }
        }
        cout <<"\n";
    }
}
