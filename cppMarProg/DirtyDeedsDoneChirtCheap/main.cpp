#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back


using namespace std;
typedef pair<int,int> ii;

bool cmp1(pair<ii,int> p1,pair<ii,int> p2){
    return p1.ff.ff>p2.ff.ff;
}

bool cmp2(pair<ii,int> p1,pair<ii,int> p2){
    return p1.ff.ff<p2.ff.ff;
}


int main()
{
    int n;
    cin >> n;
    vector<pair<ii,int>> grp1,grp2;//<,>
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a<b){
            grp1.pb({{a,b},i+1});
        }else{
            grp2.pb({{a,b},i+1});
        }
    }
    if(grp1.size()>grp2.size()){
        sort(grp1.begin(),grp1.end(),cmp1);
        cout << grp1.size()<<"\n";
        for(int i=0;i<grp1.size();i++){
            if(i==grp1.size()-1){
                cout << grp1[i].ss<<"\n";
            }else{
                cout << grp1[i].ss<<" ";
            }
        }
    }else{
        sort(grp2.begin(),grp2.end(),cmp2);
        cout << grp2.size() << "\n";
        for(int i=0;i<grp2.size();i++){
            if(i==grp2.size()-1){
                cout << grp2[i].ss<<"\n";
            }else{
                cout << grp2[i].ss<<" ";
            }
        }
    }
    return 0;
}
