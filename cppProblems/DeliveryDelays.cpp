#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll,int> ii;

const ll INF=1e18;

int n,m,k;
vector<pair<int,ll>> AdjList[5005];
ll distances[5005][5005];
int orderRoad[5005];
ll orderStartTime[5005],orderDeliveryTime[5005];
ll latestStartTime[5005];

ll latestStartTimeF(int i,ll D){
	ll &r=latestStartTime[i];
	if(r!=-1)return r;
	r=-2;
	ll maxDelay=0;
	int prevNode=0;
	ll sum=0;
	int j=i;
	while(j<k){
		ll delayNewOrder=sum+distances[prevNode][orderRoad[j]]+(orderDeliveryTime[j]-orderStartTime[j]);
		ll maxDelayIncreased=maxDelay+orderDeliveryTime[j]-orderDeliveryTime[(j==i?j:j-1)];
		if(max(maxDelayIncreased,delayNewOrder)<=D){
			maxDelay=max(maxDelayIncreased,delayNewOrder);
			sum+=distances[prevNode][orderRoad[j]];
			if(j==k-1){
				r=max(r,orderDeliveryTime[k-1]+D-maxDelay);
			}else{
				ll theTime=latestStartTimeF(j+1,D)-(sum+distances[orderRoad[j]][0]);
				if(theTime>=orderDeliveryTime[j])r=max(r,theTime);	
			}
		}else{
			j=k-1;
		}
		prevNode=orderRoad[j];
		j++;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<m;i++){
        int u,v;
        ll d;
        cin >> u >> v >> d;
        u--;
        v--;
        AdjList[u].push_back({v,d});
        AdjList[v].push_back({u,d});
    }
    
    for(int i=0;i<n;i++){
        vector<ll> dist(n, INF); dist[i] = 0; // INF = 1B to avoid overflow
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq; pq.push(ii(0,i));
        while (!pq.empty()) { // main loop
        ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
        ll d = front.first;
        int u = front.second;
        if (d > dist[u]) continue; // this is a ve ry important check
        for (int k = 0; k < (int)AdjList[u].size(); k++) {
        ii v = AdjList[u][k]; // all outgoing edges from u
        if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second; // relax operation
        pq.push(ii(dist[v.first], v.first));
        }}} // this variant can cause duplicate items in the priority queue
        for(int j=0;j<n;j++){
            distances[i][j]=dist[j];
        }
    }
    
    cin >> k;
    ll maxDelay=-1;
    for(int i=0;i<k;i++){
		ll s,t;
		int u;
		cin >> s >> u >> t;
		u--;
		orderStartTime[i]=s;
		orderRoad[i]=u;
		orderDeliveryTime[i]=t;
		maxDelay=max(t-s,maxDelay);
	}
	
	ll leftDelay=0;
	ll rightDelay=1e17; 
	while(leftDelay<=rightDelay){
		ll midDelay=(leftDelay+rightDelay)/2;
		memset(latestStartTime,-1,sizeof latestStartTime);
		ll ans=latestStartTimeF(0,midDelay);
		if(ans>=orderDeliveryTime[0]){
			maxDelay=midDelay;
			rightDelay=midDelay-1;
		}else{
			leftDelay=midDelay+1;
		}
	}
	cout << maxDelay<<endl;
}
