#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

int cnt[105];
int main(){FIN;
	int T;
	cin >> T;
	int org=T;
	while(T--){
		string s;
		cin >> s;
		fore(i,0,s.size())cnt[i]=s[i]-'0';
		bool sePuede=true;
		while(sePuede){
			sePuede=false;
			int cntIndex=-1;
			int flag=0;
			for(int i=0;i<s.size();i++){
				if(s[i]!='(' && s[i]!=')'){
					cntIndex++;
					if(cnt[cntIndex]==0){
						if(flag==1){
							s=s.substr(0,i)+')'+s.substr(i);
							i++;
							flag=0;
						}
					}else{
						cnt[cntIndex]--;
						sePuede=true;
						if(flag==0){
							s=s.substr(0,i)+'('+s.substr(i);
							i++;
							flag=1;
						}
					}
				}
			}
			if(flag==1){
				s+=")";
			}
		}
		cout << "Case #"<<org-T<<": "<<s<<"\n";
	}
    return 0;
}

