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
     
    int di[2005],state[2005][5],wi[2005];
    vector<int> ans[2005];
    int main(){FIN;
    	int m,n,w,h;
    	cin >> m >> n >> w >> h;
    	priority_queue<ii> q;
    	fore(i,0,m){
    		cin >> wi[i];
    		q.push(ii(wi[i],i));
    	}
    	fore(i,0,n)cin >> di[i];
    	fore(i,0,m){
    		state[i][0]=0;
    		state[i][1]=h;
    	}
    	fore(i,0,n){
    		fore(j,0,m){
    			if(state[j][0]==1){//working
    				wi[j]--;
    				di[i]--;
    				//cout << di[i] << " "<<j << " "<<i <<endl;
    				state[j][1]++;
    				if(state[j][1]==w){
    					state[j][0]=0;
    					state[j][1]=-1;
    					if(wi[j]!=0)q.push(ii(wi[j],j));					
    				}
    			}			
    		}
    		while(!q.empty()){
    			ii worker=q.top();
    			q.pop();
    			int j=worker.ss;
    			//cout << i<<" "<<wi[j] <<" "<< j <<" "<<state[j][1]<<endl;
    			if(state[j][1]>=h && di[i]>0){
    				state[j][0]=1;
    				state[j][1]=1;
    				wi[j]--;
    				di[i]--;
    				//cout << di[i] << " "<<j << " "<<i <<endl;
    				ans[j].pb(i+1);
    				if(state[j][1]==w){
    					state[j][0]=0;
    					state[j][1]=0;					
    				}
    			}else{
    				state[j][1]++;
    			}
    		}
    		while(!q.empty())q.pop();
    		fore(j,0,m){
    			if(wi[j]!=0 && state[j][0]==0)q.push(ii(wi[j],j));
    		}
    	}
    	bool possible=true;
    	
    	fore(i,0,n){
    		if(di[i]!=0){
    			possible=false;
    		}
    	}
    	fore(i,0,m){
    		if(wi[i]!=0){
    			possible=false;
    		}
    	}
    	/*fore(i,0,m){
    		fore(j,0,ans[i].size()){
    			if(j==ans[i].size()-1){
    				cout <<ans[i][j]<<"\n";
    			}else{
    				cout << ans[i][j]<<" ";
    			}
    		}
    	}cout<<endl;*/
    	if(possible){
    		cout << "1\n";
    		fore(i,0,m){
    			fore(j,0,ans[i].size()){
    				if(j==ans[i].size()-1){
    					cout <<ans[i][j]<<"\n";
    				}else{
    					cout << ans[i][j]<<" ";
    				}
    			}
    		}
    	}else{
    		cout << "-1\n";
    	}
        return 0;
    }
