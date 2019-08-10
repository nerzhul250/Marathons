#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> numbers;
int indexes[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int nam=0;
        cin >> nam;
        numbers.push_back(nam);
        indexes[nam]=i;
    }
    sort(numbers.begin(),numbers.end());
    int index=indexes[numbers[0]];
    int counter=1;
    int maxC=1;
    for(int i=1;i<n;i++){
        if(indexes[numbers[i]]>index){
            counter++;
        }else{
            counter=1;
        }
            index=indexes[numbers[i]];
        if(counter>maxC)maxC=counter;
    }
    cout << n-maxC<<"\n";
    return 0;
}
