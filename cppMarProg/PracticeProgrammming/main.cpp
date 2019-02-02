#include <iostream> //printf,scanf,cout,cin
#include <cmath> // atan()
#include <vector> //vector
#include <algorithm> //sort,binarysearch
#include <utility>      // std::pair, std::make_pair

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;
constexpr double pi() { return atan(1)*4; }

void one(){
    double x;
    scanf("%lf",&x);
    printf("%7.3f",x);
}
void two(){
    int n;
    scanf("%d",&n);
    string s1="%.",s2=to_string(n),s3="f",s;
    s=s1+s2+s3;
    const char *k=s.c_str();
    printf(k,pi());
}
void three(){
    int n;
    vector<int> myvector;
    vector<int>::iterator it = myvector.begin();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        if(find(myvector.begin(),myvector.end(),val) ==myvector.end())it = myvector.insert ( it ,val);
    }
    sort(myvector.begin(),myvector.end());
    while(it!=myvector.end()){printf("%d\n",*it);++it;}
}
void threetwo(){
    int a[] = {1, 2, 2, 2, 3, 3, 2, 2, 1};
    vector<int> v(a, a + 9);
    sort(ALL(v)); UNIQUE(v);
    for (int i = 0; i < (int)v.size(); i++) printf("%d\n", v[i]);
}
void five(){
    iii A=make_pair(ii(5,24),-1982);
    iii B=make_pair(ii(5,24),-1980);
    iii C=make_pair(ii(11,13),-1983);
    vector<iii> myvector;
    myvector.push_back(A);
    myvector.push_back(B);
    myvector.push_back(C);
    sort(ALL(myvector));
    for(vector<iii>::iterator it=myvector.begin();it!=myvector.end();++it)printf("%d %d %d\n",(it->first).first,(it->first).second,-(it->second));
}
void six(){
    int n = 5, L[] = {10, 7, 5, 20, 8}, v = 7;
    sort(L, L + n);
    printf("%d\n", binary_search(L, L + n, v));
}
void seven(){
    int N=3,p[N];
    for(int i=0;i<N;i++)p[i]=i;
    for(int i=1;i<(1<<N);i++){
        for (int j=0;j<N;j++){
                if(i & (1<<j)){
                    printf("%d ",p[j]);
                }
        }
        printf("\n");
    }
}
int main()
{
    seven();
    return 0;
}
