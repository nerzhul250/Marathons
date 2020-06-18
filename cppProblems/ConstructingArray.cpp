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
typedef pair<ii,int> iii;
int arr[200005];
void constructArr(int lon,int ind,int pos){
	if(lon==0)return;
	if(lon%2==0){
		arr[pos+(lon/2)-1]=ind;
		constructArr((lon/2)-1,ind*2+1,pos);
		constructArr(lon/2,ind*2,pos+(lon/2));
	}else{
		arr[pos+(lon/2)]=ind;
		constructArr(lon/2,ind*2,pos);
		constructArr(lon/2,ind*2+1,pos+(lon/2)+1);
	}
}
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		priority_queue<ii> q;
		q.push(ii(n,0));
		int ind=1;
		while(!q.empty()){
			ii e=q.top();q.pop();
			int lon=e.ff;
			int pos=-e.ss;
			if(lon==0)continue;
			if(lon%2==0){
				arr[pos+(lon/2)-1]=ind;
				q.push(ii((lon/2)-1,-pos));
				q.push(ii(lon/2,-(pos+(lon/2))));
			}else{
				arr[pos+(lon/2)]=ind;
				q.push(ii(lon/2,-pos));
				q.push(ii(lon/2,-(pos+(lon/2)+1)));
			}
			ind++;
		}
		fore(i,0,n){
			if(i==n-1)cout <<arr[i]<<"\n";
			else cout << arr[i] << " ";
		}
	}
    return 0;
}

