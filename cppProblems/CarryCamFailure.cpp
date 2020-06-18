#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
string multiply(string a,string b){
	reverse(ALL(a));
	reverse(ALL(b));
	int arr[a.size()+1][2*a.size()-1];
	fore(i,0,a.size()+1){
		fore(j,0,2*a.size()-1){
			arr[i][j]=0;
		}
	}
	fore(i,0,b.size()){
		fore(j,0,a.size()){
			arr[i][i+j]=((b[i]-'0')*(a[j]-'0'))%10;
		}
	}
	fore(j,0,2*a.size()-1){
		int sum=0;
		fore(i,0,a.size()){
			sum+=arr[i][j];
		}
		arr[a.size()][j]=sum%10;
	}
	string ans="";
	reverse(arr[a.size()],arr[a.size()]+2*a.size()-1);
	fore(i,0,2*a.size()-1){
		ans+=to_string(arr[a.size()][i]);
	}
	return ans;
}
string get_low(string a,string b){
	if(a=="-1" && b=="-1"){
		return "-1";
	}else if(a=="-1"){
		return b;
	}else if(b=="-1"){
		return a;
	}else{
		if(a<b){
			return a;
		}else{
			return b;
		}
	}
}
string N;
string Nr;
string compute(int currIndex,string prev){
	if(prev.size()==(N.size()+1)/2){
		reverse(ALL(prev));
		if(multiply(prev,prev)==N){
			return prev;
		}else{
			return "-1";
		}
	}
	string lowest="-1";
	if(currIndex==0){
		fore(i,0,10){
			if(to_string((i*i)%10)==to_string(Nr[0]-'0')){
				lowest=get_low(lowest,compute(1,to_string(i)));
			}
		}
	}else{
		int b=0;
		int a=0;
		fore(i,0,currIndex+1){
			int upInd=currIndex-i;
			int botInd=i;
			if(upInd==currIndex || botInd==currIndex){
				if(upInd==currIndex){
					a+=(prev[botInd]-'0');
				}else{
					a+=(prev[upInd]-'0');
				}
				a%=10;
			}else{
				b+=(prev[upInd]-'0')*(prev[botInd]-'0');
				b%=10;
			}
		}
		if(a==0){
			if(to_string(b)==to_string(Nr[currIndex]-'0')){
				fore(i,0,10){
					lowest=get_low(lowest,compute(currIndex+1,prev+to_string(i)));
				}
			}
		}else{
			fore(i,0,10){
				if(to_string((i*a+b)%10)==to_string(Nr[currIndex]-'0')){
					lowest=get_low(lowest,compute(currIndex+1,prev+to_string(i)));
				}
			}
		}
	}
	return lowest;
}
int main(){FIN;
	cin >> N;
	Nr=N;
	reverse(ALL(Nr));
	cout << compute(0,"")<<"\n";
    return 0;
}
