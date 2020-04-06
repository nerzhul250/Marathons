#include <bits/stdc++.h>
#include <stdio.h>

#define fore(i,low,n) for(int i=low;i<n;i++)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long int ll;

struct point{
	ll x,y;
	bool operator<(point p){
		return x<p.x || (x==p.x && y<p.y);
	}
};


point producers[500005],consumers[500005],lower_hull[500005],upper_hull[500005];
int lower_hull_size,upper_hull_size;

ll f(int a,int b){
	if(upper_hull[b].x<=lower_hull[a].x &&upper_hull[b].y<=lower_hull[a].y)return 0;
	return (upper_hull[b].x-lower_hull[a].x)*(upper_hull[b].y-lower_hull[a].y);
}

ll divide_conquer(int l, int r,int bl,int br){
	if(l>r)return 0;
	int mid=(l+r)/2;
	int bestIndex=bl;
	ll maximum=f(mid,bl);
	fore(i,bl+1,br+1){
		ll tmp=f(mid,i);
		if(tmp>maximum){
			maximum=tmp;
			bestIndex=i;
		}
	}
	maximum=max(maximum,divide_conquer(l,mid-1,bl,bestIndex));
	maximum=max(maximum,divide_conquer(mid+1,r,bestIndex,br));
	return maximum;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    //producers and consumers
    cin >> m >> n;
    fore(i,0,m){
		cin >> producers[i].x >> producers[i].y;
	}
	fore(i,0,n){
		cin >> consumers[i].x >> consumers[i].y;
	}
	
	sort(begin(producers),producers+m);
	sort(begin(consumers),consumers+n);	
	
	
	int k=1;
	lower_hull[0]=producers[0];
	fore(i,1,m){
		if(producers[i].y<lower_hull[k-1].y){
			lower_hull[k++]=producers[i];
		}
	}
	lower_hull_size=k;
	
	k=1;
	upper_hull[0]=consumers[n-1];
	for(int i=n-2;i>=0;i--){
		if(consumers[i].y>upper_hull[k-1].y){
			upper_hull[k++]=consumers[i];
		}
	}
	upper_hull_size=k;
	
	sort(begin(upper_hull),upper_hull+upper_hull_size);
	
	ll ans=divide_conquer(0,lower_hull_size-1,0,upper_hull_size-1);
	cout << (ans<0?0:ans)<<"\n";
}
