#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
int parent[MAX],n,m;
vector< bitset<MAX> > personal;

void make_set (int n) {
    for (int i=0;i<n;++i) {
        parent[i] = i;
    }
}
int find (int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge ( int x, int y ) {
    x = find(x);
    y = find(y);
    if ( x != y ) {
        parent[x] = y;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int flag=1;
    for(int i=0;i<n;i++){
        int k=0;
        cin >> k;
        if(k>0)flag=0;
        bitset<105> p;
        for(int j=0;j<k;j++){
            int index=0;
            cin >> index;
            index--;
            p.set(index);
        }
        personal.push_back(p);
    }
    make_set(n);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((personal[i]&personal[j]).any()){
                merge(i,j);
            }
        }
    }
    unordered_set<int> setx;
    for(int i=0;i<n;i++){
        if(setx.find(find(i))==setx.end())setx.insert(find(i));
    }
    if(flag){
        cout << setx.size() << "\n";
    }else{
        cout << setx.size()-1 << "\n";
    }
}
