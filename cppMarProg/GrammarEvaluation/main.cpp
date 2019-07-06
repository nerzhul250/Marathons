#include <iostream>
#include <string>
#include <float.h>
#include <math.h>

using namespace std;
typedef float ll;
string e;
int i;

ll comp();
ll fact();
ll exp();

ll fact(){
    if(e[i]=='('){
        i++;
        ll val1=exp();
        if(e[i]==')'){
            i++;
            return val1;
        }else{
            throw "BAD EXPRESSION";
        }
    }else{
        ll val1=0;
        if(e[i]>='1' && e[i]<='9'){
            val1*=10;
            val1+=(e[i]-'0');
            i++;
            while(e[i]>='0' && e[i]<='9'){
                if (val1 > FLT_MAX / 10) throw "BAD EXPRESSION";
                val1*=10;
                val1+=(e[i]-'0');
                i++;
            }
            return val1;
        }else{
            throw "BAD EXPRESSION";
        }
    }
}

ll comp(){
    ll f=fact();
    if(e[i]=='*'){
        i++;
        ll f2=comp();
        if (f > FLT_MAX / f2) throw "BAD EXPRESSION";
        return f*f2;
    }else{
        return f;
    }
}
ll exp(){
    ll val1=comp();
    if(e[i]=='+'){
        i++;
        ll val2=exp();
        if (val1 > FLT_MAX - val2) throw "BAD EXPRESSION";
        return val1+val2;
    }else{
        return val1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    getline(cin,e);
    T=stoi(e);
    while(T--){
        getline(cin,e);
        string aux="";
        for(int j=0;j<e.length();j++){
            if(e[j]!=' '){
                aux+=e[j];
            }
        }
        e=aux;
        i=0;
        try {
            ll val=exp();
            if(i!=e.length())throw "BAD EXPRESSION";
            cout << floor(val)<<"\n";
        } catch(...) {
            cout << "ERROR\n";
        }
    }
    return 0;
}
