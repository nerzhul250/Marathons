#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef long long int ll;
ll dp[25][21][3][5][7][9];
ll countOdds(ll n){
	n++;
	string s=to_string(n);
	ll sum=0;
	int rems[4]={0,0,0,0};
	int odds[4]={3,5,7,9};
	int mask=0;
	ll power=1;
	fore(i,0,s.size()-1)power*=10;
	fore(i,0,s.size()){
		int limit=s[i]-'0';
		int p=s.size()-i-1;
		for(int x=3;x<limit;x+=2){
			sum+=dp[p][mask|(1<<((x-3)/2))][(rems[0]+x*power)%3][(rems[1]+x*power)%5][(rems[2]+x*power)%7][(rems[3]+x*power)%9];
		}
		if(s[i]!='3' &&
		   s[i]!='5' &&
		   s[i]!='7' &&
		   s[i]!='9'){
			   break;
		}else{
			fore(j,0,4){
				ll m=(limit*power);
				m%=odds[j];
				int toAdd=m;
				rems[j]+=toAdd;
				rems[j]%=odds[j];
			}
			mask|=(1<<((limit-3)/2));
			power/=10;
		}
	}
	fore(i,0,s.size()-1){
		int p=s.size()-i-1;
		sum+=dp[p][0][0][0][0][0];
	}
	return sum;
}
int main(){FIN;
	fore(mask,0,(1<<4)){
		fore(i,0,3){
			fore(j,0,5){
				fore(k,0,7){
					fore(l,0,9){
						if((i!=0 || (mask&(1<<0))==0) &&
						   (j!=0 || (mask&(1<<1))==0) &&
						   (k!=0 || (mask&(1<<2))==0) &&
						   (l!=0 || (mask&(1<<3))==0)){
							dp[0][mask][i][j][k][l]=1;
						}
					}
				}
			}
		}	
	}
	int odds[4]={3,5,7,9};
	int rems[4]={1,1,1,1};
	fore(p,1,25){
		fore(mask,0,(1<<4)){
			fore(i,0,3){
				fore(j,0,5){
					fore(k,0,7){
						fore(l,0,9){
							for(int x=3;x<=9;x+=2){
								dp[p][mask][i][j][k][l]+=dp[p-1][mask|(1<<((x-3)/2))][(i+x*rems[0])%3][(j+x*rems[1])%5][(k+x*rems[2])%7][(l+x*rems[3])%9];
							}
						}
					}
				}
			}	
		}
		fore(i,0,4){
			rems[i]*=10;
			rems[i]%=odds[i];
		}
	}
	int Q;
	cin >> Q;
	fore(q,0,Q){
		ll A,B,K;
		cin >> A >> B >> K;
		ll base=countOdds(A-1);
		ll total=countOdds(B);
		//cout <<"Total "<< total<<endl;
		if(total-base<K){
			cout << "-1\n";
		}else{
			ll i=A,j=B;
			ll ans=0;
			while(i<=j){
				ll mid=(i+j)/2;
				ll k=countOdds(mid)-base;
				//cout << k << " "<<mid<<endl;
				if(k<K){
					i=mid+1;
				}else if(k>K){
					j=mid-1;
				}else if(k==K){
					ans=mid;
					j=mid-1;
				}
			}
			cout << ans << "\n";
		}
	}
    return 0;
}
