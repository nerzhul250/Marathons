#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
string names[105];
int girls[105],taxis[105],pizzas[105];
int maxG,maxT,maxP;
bool isTaxi(string s){
	return s[0]==s[1] &&s[1]==s[3] &&s[3]==s[4] &&s[4]==s[6] &&s[6]==s[7];
}
bool isPizza(string s){
	return s[0]>s[1] &&s[1]>s[3] &&s[3]>s[4] &&s[4]>s[6] &&s[6]>s[7];
}
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n){
		int s;
		string name;
		cin >> s >> name;
		names[i]=name;
		fore(j,0,s){
			string phone;
			cin >> phone;
			if(isTaxi(phone)){
				taxis[i]++;
			}else if(isPizza(phone)){
				pizzas[i]++;
			}else{
				girls[i]++;
			}
		}
		maxG=max(maxG,girls[i]);
		maxT=max(maxT,taxis[i]);
		maxP=max(maxP,pizzas[i]);
	}
	cout << "If you want to call a taxi, you should call: ";
	vector<int> guys;
	fore(i,0,n){
		if(taxis[i]==maxT){
			guys.pb(i);
		}
	}
	fore(i,0,guys.size()){
		if(i==guys.size()-1)cout <<names[guys[i]]<<".\n";
		else cout << names[guys[i]]<<", ";
	}
	
	cout << "If you want to order a pizza, you should call: ";
	guys.clear();
	fore(i,0,n){
		if(pizzas[i]==maxP){
			guys.pb(i);
		}
	}
	fore(i,0,guys.size()){
		if(i==guys.size()-1)cout <<names[guys[i]]<<".\n";
		else cout << names[guys[i]]<<", ";
	}
	
	cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
	guys.clear();
	fore(i,0,n){
		if(girls[i]==maxG){
			guys.pb(i);
		}
	}
	fore(i,0,guys.size()){
		if(i==guys.size()-1)cout <<names[guys[i]]<<".\n";
		else cout << names[guys[i]]<<", ";
	}
    return 0;
}
