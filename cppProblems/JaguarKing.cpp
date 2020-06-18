#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

int cycleNum;
int minSwaps(int arr[], int n)
{
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    sort(arrPos, arrPos + n);
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || arrPos[i].second == i)
            continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
            j = arrPos[j].second;
            cycle_size++;
        }
        if (cycle_size > 0){
			ans += (cycle_size-1);
			cycleNum++;
		}
    }
    return ans;
}



int main(){FIN;
	int N;
	int i=0;
	while(cin >> N){
		if(N==0)break;
		i++;
		int arr[N+1];
		int org[N+1];
		fore(i,0,N){
			cin >> arr[i];
			arr[i]--;
			org[i]=arr[i];
		}
		cout <<"Set "<<i<<":\n";
		cycleNum=0;
		int mins=minSwaps(arr,N);
		if(cycleNum==0){
			cout << "0\n";
		}else{
			if(org[0]==0){
				cout << mins+2*cycleNum<<"\n";
			}else{
				cout << mins+2*(cycleNum-1)<<"\n";	
			}
		} 
	}
    return 0;
}
