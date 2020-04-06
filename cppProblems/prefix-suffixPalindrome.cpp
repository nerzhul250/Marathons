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

const int MAXN=1000005;

int d1[MAXN];//d1[i] = max odd palindrome centered on i
int d2[MAXN];//d2[i] = max even palindrome centered on i
//s  aabbaacaabbaa
//d1 1111117111111
//d2 0103010010301
void manacher(string& s){
	int l=0,r=-1,n=s.size();
	fore(i,0,n){
		int k=i>r?1:min(d1[l+r-i],r-i);
		while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
		d1[i]=k--;
		if(i+k>r)l=i-k,r=i+k;
	}
	l=0;r=-1;
	fore(i,0,n){
		int k=i>r?0:min(d2[l+r-i+1],r-i+1);k++;
		while(i+k<=n&&i-k>=0&&s[i+k-1]==s[i-k])k++;
		d2[i]=--k;
		if(i+k-1>r)l=i-k,r=i+k-1;
	}
}


int rtl[1000005],ltr[1000005],rtl2[1000005],ltr2[1000005];
const int p = 31;
const int p2 = 53;
const int m = 1e9 + 9;

bool check(string s){
	fore(i,0,SZ(s)/2){
		if(s[i]!=s[SZ(s)-1-i])return false;
	}
	return true;
}

bool theSame(int i,int j){
	return rtl[i]==ltr[j] && rtl2[i]==ltr2[j]; 
}

int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		manacher(s);
		ll hash=0;
		ll hash2=0;
		fore(i,0,s.size()){
			hash=(hash*p+s[i]-'a'+1)%m;
			rtl[i]=hash;
			hash2=(hash2*p2+s[i]-'a'+1)%m;
			rtl2[i]=hash2;
		}
		hash=0;
		hash2=0;
		for(int i=s.size()-1;i>=0;i--){
			hash=(hash*p+s[i]-'a'+1)%m;
			ltr[i]=hash;
			hash2=(hash2*p2+s[i]-'a'+1)%m;
			ltr2[i]=hash2;
		}
		int longestLength=0;
		int preffix=-1,suffix=-1;
		fore(i,0,s.size()){
			int l=i-d1[i]+1,r=i+d1[i]-1,len=(d1[i]-1)*2+1,smallLen=0;
			if(i<SZ(s)/2){
				smallLen=l;
				if(len+(smallLen)*2>longestLength &&
					(l==0 || theSame(l-1,(l-smallLen*2+SZ(s))%SZ(s)))){
					longestLength=len+(smallLen)*2;
					preffix=r;
					suffix=(l-smallLen*2+SZ(s))%SZ(s);
				}
			}else{
				smallLen=SZ(s)-(r+1);
				if(len+(smallLen)*2>longestLength &&
					(r+1==SZ(s) || theSame((r+smallLen*2)%SZ(s),r+1))){
					longestLength=len+(smallLen)*2;
					preffix=(r+smallLen*2)%SZ(s);
					suffix=l;
				}
			}
		}
		fore(i,0,s.size()){
			int l=i-d2[i],r=i+d2[i]-1,len=d2[i]*2,smallLen=0;
			if(i<=SZ(s)/2){
				smallLen=l;
				if(len+(smallLen)*2>longestLength &&
					(l==0 || theSame(l-1,(l-smallLen*2+SZ(s))%SZ(s)))){
					longestLength=len+(smallLen)*2;
					preffix=r;
					suffix=(l-smallLen*2+SZ(s))%SZ(s);
				}
			}else{
				smallLen=SZ(s)-(r+1);
				if(len+(smallLen)*2>longestLength &&
					(r+1==SZ(s) || theSame((r+smallLen*2)%SZ(s),r+1))){
					longestLength=len+(smallLen)*2;
					preffix=(r+smallLen*2)%SZ(s);
					suffix=l;
				}
			}
		}
		//cout << preffix << " "<<suffix <<endl;
		string palindromo;
		if(preffix<suffix){
			fore(i,0,preffix+1){
				palindromo+=s[i];
			}
			fore(i,suffix,s.size()){
				palindromo+=s[i];
			}	
		}else{
			if(preffix!=s.size()-1){
				fore(i,0,preffix+1){
					palindromo+=s[i];
				}
			}else{
				fore(i,suffix,s.size()){
					palindromo+=s[i];
				}	
			}
		}
		if(!check(palindromo)){
			cout << preffix << " "<<suffix<<"\n";
		}
		cout << palindromo<<"\n";
	}
    return 0;
}
