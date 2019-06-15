#include <iostream>

using namespace std;

bool check(int a,int b,int c, int d, int e, int f){
    if(a-c>=0 && b-d>=0 && e-a>=0 && f-b>=0)return true;
    if(a-e>=0 && b-f>=0 && c-a>=0 && d-b>=0)return true;
    if(a-c>=0 && d-b>=0 && e-a>=0 && b-f>=0)return true;
    if(a-e>=0 && f-b>=0 && c-a>=0 && b-d>=0)return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int k;
    cin >> k;
    while(k--){
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        if(abs(c-e)==abs(d-f) && abs(a-c)==abs(b-d) && check(a,b,c,d,e,f)){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
    return 0;
}
