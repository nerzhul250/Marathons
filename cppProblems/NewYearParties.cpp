#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

struct segment{
	bool merged=false;
	int left,sum,right;
	segment(int l,int s, int r):left(l),sum(s),right(r){}
	segment(){}
};


int houses[200005];
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n){
		int num;
		cin >> num;
		houses[num]++;
	}
	int flag=0;
	int sum=0;
	vector<segment> segments;
	fore(i,0,n+2){
		if(flag==0){//searching zero
			if(houses[i]!=0){
				segments.pb(segment(i-1,houses[i],i+1));
				flag=1;
			}
		}else{//summing
			if(houses[i]==0){
				segments.back().right=i;
				flag=0;
			}else{
				segments.back().sum+=houses[i];
			}
		}
	}
	int max=0;
	bool lastOccupied=false;
	fore(i,0,segments.size()){
		segment seg=segments[i];
		int segLen=seg.right-seg.left-1;
		int segSum=seg.sum;
		
		if(i==0 || segments[i-1].right!=segments[i].left)lastOccupied=false;
		
		if(segSum==segLen){
			max+=segLen;
			lastOccupied=false;
		}else if(segSum==segLen+1){
			max+=segSum;
		}else if(segSum>=segLen+2){
			if(lastOccupied){
				max+=segLen+1;
			}else{
				max+=segLen+2;
				lastOccupied=true;
			}
		}
	}
	int min=0;
	fore(i,0,n+1){
		if(houses[i]!=0){
			min++;
			i+=2;
		}
	}
	cout << min<<" "<<max<<"\n";
    return 0;
}
