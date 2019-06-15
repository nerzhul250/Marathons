#include <iostream>
#include <map>
using namespace std;
typedef pair<int,int> ii;

int N,K,n,freq[1009];
map<int,ii>freqToNumber;
map<int,ii>::iterator it;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> N;
    for(int i=0;i<N;i++){
        cin >> n;
        freq[n]++;
    }
    for(int i=1;i<=K;i++){
        if(freqToNumber.count(freq[i])==0){
            freqToNumber[freq[i]]=ii(i,1);
        }else{
            freqToNumber[freq[i]]=ii(i,++freqToNumber[freq[i]].second);
        }
    }
    if(freqToNumber.size()==2){
        it=freqToNumber.begin();
        ii a=it->second;int a1=it->first;
        it++;
        ii b=it->second;int b1=it->first;
        if(a1+1==b1){
            if(b.second>a.second){
                cout <<"+"<<a.first << endl;
            }else{
                cout <<"-"<<b.first << endl;
             }
        }else{
            cout << "*" << endl;
        }
    }else if(freqToNumber.size()==3){
        it=freqToNumber.begin();
        ii a=it->second;int a1=it->first;
        it++;
        ii b=it->second;int b1=it->first;
        it++;
        ii c=it->second;int c1=it->first;
        if(a1+1==b1 && c1-1==b1){
            cout <<"-"<<c.first<<" "<<"+"<<a.first<< endl;
        }else{
            cout << "*" << endl;
        }
    }else{
        cout << "*" << endl;
    }
    return 0;
}
