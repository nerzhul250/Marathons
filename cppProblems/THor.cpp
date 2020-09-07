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
typedef pair<int,int> ii;
set<ii> notif;
set<int> colas[300005];
int main(){FIN;	
	int n,q;
	cin >> n >> q;
	int size=0;
	int unread=0;
	fore(i,0,q){
		int t,x;
		cin >> t >> x;
		if(t==1){
			unread++;
			x--;
			notif.insert(ii(size,x));
			colas[x].insert(size);
			size++;
		}else if(t==2){
			x--;
			while(colas[x].size()!=0){
				notif.erase(ii(*colas[x].begin(),x));
				colas[x].erase(colas[x].begin());
				unread--;
			}
		}else{
			while(notif.size()!=0 && notif.begin()->ff<x){
				colas[notif.begin()->ss].erase(notif.begin()->ff);
				notif.erase(notif.begin());
				unread--;
			}
		}
		cout << unread << "\n";
	}
    return 0;
}
