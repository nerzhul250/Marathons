#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

typedef pair<int,int> ii;


struct lex_compare {
    bool operator() (const string& s1, const string& s2) const {
        if(s1.size()>s2.size()){
			return true;
		}else if(s1.size()<s2.size()){
			return false;
		}else{
			return s1.compare(s2)<0;
		}
    }
};

string toUpperCase(string s){
	string ans="";
	fore(i,0,s.size()){
		ans+=toupper(s[i]);
	}
	return ans;
}

int main(){FIN;
	int n;
	cin >> n;
	int org=n;
	while(n--){
		map<int,string> mpItos;
		map<string,int> mpStoi;
		set<ii> pps;
		int t,p,s;
		cin >> t >> p >> s;
		multiset<string,lex_compare> naturalOrder;
		fore(i,0,t){
			string s;
			cin >> s;
			naturalOrder.insert(toUpperCase(s));
		}
		int index=0;
		for(auto s:naturalOrder){
			mpItos[index]=s;
			mpStoi[s]=index;
			index++;	
		}
		fore(i,0,p){
			string s1,s2;
			cin >> s1 >> s2;	
			s1=toUpperCase(s1);
			s2=toUpperCase(s2);
			pps.insert(ii(mpStoi[s2],mpStoi[s1]));
			pps.insert(ii(mpStoi[s1],mpStoi[s2]));
		}
		cout << "Set "<<org-n<<":\n";
		string ans="";
		if(s==1){
			fore(i,0,t){
				ans=mpItos[i];
				cout << ans<<"\n";
			}
		}else if(s==2){
			fore(i,0,t-1){
				fore(i1,i+1,t){
					if(pps.count(ii(i,i1))==0){
						ans=mpItos[i]+" "+mpItos[i1];
						cout << ans<<"\n";
					}
				}
			}
		}else if(s==3){
			fore(i,0,t-2){
				fore(i1,i+1,t-1){
					fore(i2,i1+1,t){
						if(pps.count(ii(i,i1))==0 &&
							pps.count(ii(i,i2))==0 &&
							pps.count(ii(i1,i2))==0){
								ans=mpItos[i]+" "+mpItos[i1]+" "+mpItos[i2];
								cout << ans<<"\n";
						}
					}
				}
			}
		}else if(s==4){
			fore(i,0,t-3){
				fore(i1,i+1,t-2){
					fore(i2,i1+1,t-1){
						fore(i3,i2+1,t){
							if(pps.count(ii(i,i1))==0 &&
							pps.count(ii(i,i2))==0 &&
							pps.count(ii(i,i3))==0 &&
							pps.count(ii(i1,i2))==0 &&
							pps.count(ii(i1,i3))==0 &&
							pps.count(ii(i2,i3))==0){
								ans=mpItos[i]+" "+mpItos[i1]+" "+mpItos[i2]+" "+mpItos[i3];
								cout << ans<<"\n";
							}	
						}
					}
				}
			}
		}else if(s==5){
			fore(i,0,t-4){
				fore(i1,i+1,t-3){
					fore(i2,i1+1,t-2){
						fore(i3,i2+1,t-1){
							fore(i4,i3+1,t){
								if(pps.count(ii(i,i1))==0 &&
								pps.count(ii(i,i2))==0 &&
								pps.count(ii(i,i3))==0 &&
								pps.count(ii(i,i4))==0 &&
								pps.count(ii(i1,i2))==0 &&
								pps.count(ii(i1,i3))==0 &&
								pps.count(ii(i1,i4))==0 &&
								pps.count(ii(i2,i3))==0 &&
								pps.count(ii(i2,i4))==0 &&
								pps.count(ii(i3,i4))==0){
									ans=mpItos[i]+" "+mpItos[i1]+" "+mpItos[i2]+" "+mpItos[i3]+" "+mpItos[i4];
									cout << ans<<"\n";
								}	
							}
						}
					}
				}
			}
		}
		cout << "\n";
	}
    return 0;
}

