#include <iostream>
#include <stack>
#include <string>

using namespace std;

typedef long long int ll;

string ex;
int iks;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }


string parseFrac() {
    string ans="";
    while(iks>=0 &&iks<ex.size()&& ((ex[iks]>='0' && ex[iks]<='9') || ex[iks]=='/')) {
        ans+=ex[iks];
        iks++;
    }
    return ans;
}

ll parseNumerator(string f){
    ll num=0;
    unsigned int index=0;
    ll flag=1;
    if(f[index]=='-'){
        index++;
        flag=-1;
    }
    while(index<f.size() && f[index]>='0' && f[index]<='9'){
        num*=10;
        num+=(f[index]-'0');
        index++;
    }
    num*=flag;
    return num;
}

ll parseDenominator(string f){
    ll num=0;
    unsigned int index=0;
    while(index<f.size()&&((f[index]>='0' && f[index]<='9')||f[index]=='-'))index++;

    index++;

    while(index<f.size() && f[index]>='0' && f[index]<='9'){
        num*=10;
        num+=(f[index]-'0');
        index++;
    }
    return num;
}

string sumFractions(string f1,string f2) {
    string ans="";
    ll a1=parseNumerator(f1);
    ll a2=parseDenominator(f1);
    ll b1=parseNumerator(f2);
    ll b2=parseDenominator(f2);

    ll a=a1*b2+a2*b1;
    ll b=a2*b2;
    ll d=gcd(abs(a),abs(b));
    if(d==0)d++;

    ans+=to_string(a/d);
    ans+="/";
    ans+=to_string(b/d);
    return ans;
}

string subFractions(string f1,string f2) {
        ll a1=parseNumerator(f1);
        ll a2=parseDenominator(f1);
        ll b1=parseNumerator(f2);
        ll b2=parseDenominator(f2);

		ll a=a1*b2-a2*b1;
		ll b=a2*b2;
		ll d=gcd(abs(a),abs(b));
		if(d==0)d++;

		string ans="";
		ans+=to_string(a/d);
		ans+="/";
		ans+=to_string(b/d);
        return ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(getline(cin,ex)){
        if(ex.empty())break;
        iks=0;
        stack<int> st;
        st.push(1);
        string res="0/1";
        while(iks>=0 &&iks<ex.size()){
            if(iks>=0 &&iks<ex.size()&&ex[iks]=='('){
                st.push(st.top());
                iks++;
            }else if(iks>=0 &&iks<ex.size() &&ex[iks]=='+' && ex[iks+1]=='('){
                st.push(st.top());
                iks+=2;
            }else if(iks>=0 &&iks<ex.size()&&ex[iks]=='-' && ex[iks+1]=='('){
                st.push(st.top()*-1);
                iks+=2;
            }else if(iks>=0 &&iks<ex.size()&&ex[iks]=='-' && ex[iks+1]>='0'&&ex[iks+1]<='9' ){
                iks++;
                string b=parseFrac();
                int type=-1*st.top();
                if(type==-1){
                    res=subFractions(res,b);
                }else{
                    res=sumFractions(res,b);
                }
            }else if(iks>=0 &&iks<ex.size()&&ex[iks]=='+' && ex[iks+1]>='0'&&ex[iks+1]<='9'){
                iks++;
                string b=parseFrac();
                int type=st.top();
                if(type==-1){
                    res=subFractions(res,b);
                }else{
                    res=sumFractions(res,b);
                }
            }else if(iks>=0 &&iks<ex.size()&&ex[iks]==')'){
                st.pop();
                iks++;
            }else if(iks>=0 &&iks<ex.size()&&ex[iks]>='0'&&ex[iks]<='9'){
                string b=parseFrac();
                int type=st.top();
                if(type==-1){
                    res=subFractions(res,b);
                }else{
                    res=sumFractions(res,b);
                }
             }
         }
        cout << res << "\n";
    }
    return 0;
}
