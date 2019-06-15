#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
vector<int> positions;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    positions.assign(100005,0);
    while(t--){
        int n,c;
        cin >> n >> c;
        int minPos=1000000000;
        for(int k=0;k<n;k++){
            int x;
            cin >> x;
            positions[k]=x;
        }
        sort(positions.begin(),positions.begin()+n);
        int i=0;
        int j=positions[n-1]-positions[0];
        int maxMinDistance=0;
        int prev=0;
        while(i<=j){
            maxMinDistance=(i+j)/2;
            int counter=1;
            int currentPos=0;
            for(int k=1;k<n;k++){
                if(abs(positions[k]-positions[currentPos])>=maxMinDistance){
                    counter++;
                    currentPos=k;
                }
            }
            if(counter>=c){
                prev=maxMinDistance;
                i=maxMinDistance+1;
            }else{
                j=maxMinDistance-1;
            }
        }
        cout << prev << endl;
    }
    return 0;
}
