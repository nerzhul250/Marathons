#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

int main(){FIN;
	int n;
	cin >>n;
	fore(i,0,n){
		string s;
		cin >> s;
		int len=s.size();
		if(s.substr(len-1)=="a"){
			cout << s.substr(0,len-1)+"as";
		}else if(s.substr(len-1)=="i" ||s.substr(len-1)=="y"){
			cout << s.substr(0,len-1)+"ios";
		}else if(s.substr(len-1)=="l"){
			cout << s.substr(0,len-1)+"les";
		}else if(s.substr(len-1)=="n"||s.substr(len-2)=="ne"){
			if(s.substr(len-1)=="n"){
				cout << s.substr(0,len-1)+"anes";
			}else{
				cout << s.substr(0,len-2)+"anes";
			}
		}else if(s.substr(len-1)=="o"){
			cout << s.substr(0,len-1)+"os";
		}else if(s.substr(len-1)=="r"){
			cout << s.substr(0,len-1)+"res";
		}else if(s.substr(len-1)=="t"){
			cout << s.substr(0,len-1)+"tas";
		}else if(s.substr(len-1)=="u"){
			cout << s.substr(0,len-1)+"us";
		}else if(s.substr(len-1)=="v"){
			cout << s.substr(0,len-1)+"ves";
		}else if(s.substr(len-1)=="w"){
			cout << s.substr(0,len-1)+"was";
		}else{
			cout << s+"us";
		}
		cout << "\n";
	}
    return 0;
}

