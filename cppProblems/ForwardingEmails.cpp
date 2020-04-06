#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef pair<int,int> ii;

struct node{
	int id;
	vector<int> sons;
	int father;
};
int N;
int cycleNodes[50005];
vector<node> graph;
int computeCycleNodes(){
	int visited[50005];
	memset(visited,0,sizeof visited);
	vector<ii> answers;
	vector<int> repCycleNodes;
	
	fore(i,0,N){
		if(visited[i]==0){
			node currentNode=graph[i];
			while(visited[currentNode.id]==0){
				visited[currentNode.id]++;
				currentNode=graph[currentNode.father];
			}
			int count=0;
			if(visited[currentNode.id]==3){
				currentNode=graph[i];
				while(visited[currentNode.id]==1){
					visited[currentNode.id]--;
					currentNode=graph[currentNode.father];
				}
				continue;
			}
			while(visited[currentNode.id]==1){
				count++;
				visited[currentNode.id]++;
				currentNode=graph[currentNode.father];
			}
			while(visited[currentNode.id]==2){
				visited[currentNode.id]++;
				cycleNodes[currentNode.id]=count;
				currentNode=graph[currentNode.father];
			}
			repCycleNodes.pb(currentNode.id);
		}
	}
	
	memset(visited,0,sizeof visited);
	
	fore(i,0,repCycleNodes.size()){
		queue<ii> q;
		q.push({repCycleNodes[i],cycleNodes[repCycleNodes[i]]});
		visited[repCycleNodes[i]]++;
		while(!q.empty()){
			ii u=q.front();
			q.pop();
			if(cycleNodes[u.ff]>0){
				answers.pb({-u.ss,u.ff});
			}
			node theNode=graph[u.ff];
			if(theNode.sons.size()==0){
				answers.pb({-u.ss,u.ff});
			}else{
				fore(j,0,theNode.sons.size()){
					if(!visited[theNode.sons[j]]){
						visited[theNode.sons[j]]++;
						if(cycleNodes[theNode.sons[j]]>0){
							q.push({theNode.sons[j],cycleNodes[theNode.sons[j]]});
						}else{
							q.push({theNode.sons[j],u.ss+1});
						}
					}
				}
			}
		}
	}
	sort(answers.begin(),answers.end());
	return answers[0].ss;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    fore(t,1,T+1){
		cin >> N;
		graph.clear();
		graph.assign(N,node());
		fore(i,0,N)graph[i].id=i;
		fore(i,0,N){
			int u,v;
			cin >> u >> v;
			u--;
			v--;
			graph[u].father=v;
			graph[v].sons.pb(u);
		}
		memset(cycleNodes,0,sizeof cycleNodes);
		cout << "Case "<<t<<": "<<computeCycleNodes()+1<< "\n";
	}
    return 0;
}

