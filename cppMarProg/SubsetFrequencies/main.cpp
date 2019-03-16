#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>


using namespace std;

typedef int64_t ll;

int k,n;
ll S[105],A[1000005],cuenta[105];
bool Aset[200000005];


bool myfunction (pair<ll,ll> i,pair<ll,ll> j) {
    if(i.second<j.second){
        return false;
    }
    if(i.second>j.second){
        return true;
    }
    if(i.second==j.second){
        return i.first<j.first;
    }
}

int main()
{
    scanf("%d %d",&n,&k);

    for (int i=0;i<n;i++){
        scanf("%lld",&A[i]);
        Aset[A[i]]=true;
    }

    for (int i=0;i<k;i++){
        scanf("%lld",&S[i]);
    }

    sort(A,A+n);
    sort(S,S+k);

    for (int j=0;j<k ;j++){
        for (int i=0;i<n;i++){
            if(S[j]-A[i]<=0)break;
            if(S[j]-A[i]<=A[i])break;
            if(Aset[S[j]-A[i]]){
                cuenta[j]++;
            }
        }
    }

    vector<pair<ll,ll>> answer;
    for (int i=0;i<k;i++){
        answer.push_back(pair<ll,ll>(S[i],cuenta[i]));
    }
    sort (answer.begin(), answer.end(), myfunction);
    for (int i=0;i<k;i++){
        printf("%lld %lld\n",answer[i].first,answer[i].second);
    }
    return 0;
}
