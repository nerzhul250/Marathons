#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long int ll;

unordered_map<ll,ll> cnt;
vector<ll>numeros;

int findPos(int pos,ll toFind){
    int i=pos+1,j=numeros.size()-1;
    int ans=-1;
    while(i<=j){
        int mid=(i+j)/2;
        if(numeros[mid]<toFind){
            i=mid+1;
        }else if(numeros[mid]>toFind){
            j=mid-1;
            ans=mid;
        }else{
            ans=mid;
            break;
        }
    }
    return ans;
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

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        ll a;
        cin >>a;
        if(cnt.find(a)==cnt.end()){
            cnt[a]=1;
        }else{
            cnt[a]=cnt[a]+1;
        }
    }

    unordered_map<ll,ll> :: iterator it =cnt.begin();
    unordered_map<ll,ll> :: iterator itEnd =cnt.end();

    set<ll> st;

    while(it!=itEnd){
        st.insert((*it).second);
        it++;
    }

    set<ll> :: iterator its=st.begin();
    set<ll> :: iterator itEnds=st.end();


    while(its!=itEnds){
        numeros.pb((*its));
        its++;
    }

    ll maximo=0;
    for(ll i=1;i<=numeros[numeros.size()-1];i++){
        ll elNumero=i;
        ll laCuenta=0;
        int pos=findPos(-1,elNumero);
        if(pos!=-1){
            laCuenta+=elNumero;
            pos=findPos(pos,elNumero*2);
        }
        while(pos!=-1){
            elNumero*=2;
            laCuenta+=elNumero;
            pos=findPos(pos,elNumero*2);
        }
        if(laCuenta>maximo)maximo=laCuenta;
    }
    cout << maximo << endl;
}
