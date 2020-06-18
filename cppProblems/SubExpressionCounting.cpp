#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
string buildS(string exp){
	string s;
	fore(i,0,exp.size()){
		if(exp[i]=='+' ||exp[i]=='/' ||exp[i]=='*' ||exp[i]=='-'){
			s+='*';
		}else if(exp[i]=='(' || exp[i]==')'){
			s+=exp[i];
		}else if(exp[i]>='a' && exp[i]<='z'){
			s+='0';
		}else if(exp[i]>='0' && exp[i]<='9'){
			if(s.back()!='0'){
				s+='0';
			}
		}
	}
	return s;
}
int main(){FIN;
	string alpha,beta;
	while(cin >> alpha){
		cin >> beta;
		string s1,s2;
		s1=buildS(alpha);
		s2=buildS(beta);
		string s=s1+s2;
		vector<int> z=z_function(s);
		int cnt=0;
		fore(i,s1.size(),s.size()){
			if(z[i]>=s1.size()){
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
    return 0;
}
