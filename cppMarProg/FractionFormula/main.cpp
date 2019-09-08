#include <iostream>
#include <string.h>

using namespace std;

typedef long long int ll;

string ex;
int i;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }


string parseFrac() {
		string ans="";
		while(i<ex.size() && ((ex[i]>='0' && ex[i]<='9') || ex[i]=='/')) {
			ans+=ex[i];
			i++;
		}
		return ans;
}

ll parseNumerator(string f){
    int index=0;
    ll num=0;
    ll flag=1;
    if(f[index]=='-'){
        index++;
        flag=-1;
    }
    while(f[index]>='0' && f[index]<='9'){
        num*=10;
        num+=(f[index]-'0');
        index++;
    }
    num*=flag;
    return num;
}

ll parseDenominator(string f){
    int index=0;
    while((f[index]>='0' && f[index]<='9')||f[index]=='-')index++;

    index++;

    ll num=0;
    while(index<f.size() && f[index]>='0' && f[index]<='9'){
        num*=10;
        num+=(f[index]-'0');
        index++;
    }
    return num;
}

string sumFractions(string f1,string f2) {
        ll a1=parseNumerator(f1);
        ll a2=parseDenominator(f1);
        ll b1=parseNumerator(f2);
        ll b2=parseDenominator(f2);

		ll a=a1*b2+a2*b1;
		ll b=a2*b2;
		ll d=abs(gcd(a,b));

        return to_string(a/d) +"/"+ to_string(b/d);
}

string subFractions(string f1,string f2) {
        ll a1=parseNumerator(f1);
        ll a2=parseDenominator(f1);
        ll b1=parseNumerator(f2);
        ll b2=parseDenominator(f2);

		ll a=a1*b2-a2*b1;
		ll b=a2*b2;
		ll d=abs(gcd(a,b));

        return to_string(a/d) +"/"+ to_string(b/d);

}

string parse();

string parseExpression(string a){
    if(i<ex.size() && ex[i]=='-') {
        i++;
        string b=parse();
        return subFractions(a,b);
    }else if(i<ex.size() && ex[i]=='+') {
        i++;
        string b=parse();
        return sumFractions(a,b);
    }else {
        return a;
    }
}
string parse() {
    if(i<ex.size() && ex[i]=='(') {
        i++;
        string a=parse();
        i++;
        return parseExpression(a);
    }else {
        string a=parseFrac();
        return parseExpression(a);
    }
}

int counter;
void test(){
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    cout << counter << endl;
    counter++;
    test();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    counter=0;
    while(cin >> ex){
        i=0;
        cout << parse() << "\n";
    }
    return 0;
}
