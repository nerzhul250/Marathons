#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

int matrix[305][305];
int lines[305][305],columns[305][305];

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
        if (cycle_size > 0)ans += (cycle_size - 1);
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int L,C;
    cin >> L>>C;
    fore(i,0,L){
        fore(j,0,C){
            int num;
            cin >> num;
            matrix[i][j]=num;
            lines[i][j]=num;
            columns[j][i]=num;
        }
    }
    bool possible=true;
    fore(i,0,L){
        sort(lines[i],lines[i]+C);
        fore(j,0,C-1){
            possible=possible && (lines[i][j]+1==lines[i][j+1]);
        }
    }
    fore(i,0,C){
        sort(columns[i],columns[i]+L);
        fore(j,0,L-1){
            possible=possible && (columns[i][j]+C==columns[i][j+1]);
        }
    }
    if(possible){
        int arr[305];
        int sol=0;
        fore(i,0,C)arr[i]=matrix[0][i];
        sol+=minSwaps(arr,C);
        fore(i,0,L)arr[i]=matrix[i][0];
        sol+=minSwaps(arr,L);
        cout << sol<<"\n";
    }else{
        cout << "*\n";
    }
}
