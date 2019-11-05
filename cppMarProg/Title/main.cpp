#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int encontrar(bool ar[30],int SIZE){
    int res=0;
    for(int i = SIZE-1; i >= 0; i--){
        if(!ar[i]){
            res= i;
            break;
        }
    }
    return res;
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

    int k; cin>>k;
    string s; cin>>s;
    bool usadas[30];
    memset(usadas,0,sizeof usadas);
    int i,j;
    if(s.size()%2==0){
        i=(s.size()-1)/2;
        j=(s.size()-1)/2+1;
    }else{
        i=(s.size()-1)/2;
        j=(s.size()-1)/2;
    }

    string res;
    int cantUsadas=0;
    bool imposible=false;
     for(int i =0; i< s.size();i++){
            if(s[i]!= '?'){
                usadas[s[i]-'a']=1;

            }
        }
    if(s.size()==1 &&k==1 && s[0]!= '?'){
        cout<< s<<endl;
    }else{

    while(i>=0){
        //cout<<i<<" "<<j<<endl;
        if(i!= j){
            if(s[i]!= '?' && s[j]!= '?'){
                if(s[i]!=s[j]){
                    res="IMPOSSIBLE";
                    imposible = true;
                    break;
                }else{
                    usadas[s[i]-'a']= 1;
                    cantUsadas++;
                }
            }else{
                if((s[i]!= '?'&&s[j]=='?') || (s[i]== '?'&&s[j]!='?')){
                    if(s[i]!= '?'&&s[j]=='?'){
                        s[j]=s[i];
                        usadas[s[i]-'a']=1;
                        cantUsadas++;
                    }else if(s[i]== '?'&&s[j]!='?'){
                        s[i]=s[j];
                        usadas[s[j]-'a']=1;
                        cantUsadas++;
                    }
                }else if(s[i]== '?'&&s[j]=='?'){
                    int l= encontrar(usadas,k);
                    s[i]='a'+l;
                    s[j]= 'a'+l;
                    usadas[l]=1;
                    cantUsadas++;
                }
            }
        }else{
            if(s[i]=='?'){
                int l = encontrar(usadas,k);
                s[i]= 'a'+l;
                usadas[l]=1;
            }
        }
        //cout<< s<<endl;
        i--;
        j++;
    }
    if(imposible){
        cout<<res<<"\n";
    }else{
        int cant = 0;
        for(int i =0; i< s.size();i++){
            usadas[s[i]-'a']=1;
        }
        for(int i =0; i< k;i++){
            if(usadas[i]){
                cant++;
            }
        }
        if(cant == k){
            cout<<s<<"\n";
        }else{
            cout<<"IMPOSSIBLE\n";
        }
    }
    }

}
