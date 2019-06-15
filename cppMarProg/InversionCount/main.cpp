#include <iostream>

using namespace std;
typedef long long ll;

int arr[200009],n;
ll counter;

void mergeComb(int i, int p, int j){
    int index=0,auxAd[j-i+1],indexl=i,indexr=p+1;
    while(indexl<p+1 && indexr<j+1){
        if(arr[indexl]>arr[indexr]){
            counter+=p-indexl+1;
            auxAd[index]=arr[indexr];
            indexr++;
        }else if(arr[indexl]==arr[indexr]){
            counter+=p-indexl;
            auxAd[index]=arr[indexr];
            indexr++;
        }else{
            auxAd[index]=arr[indexl];
            indexl++;
        }
        index++;
    }
    if(indexl==p+1){
        while(indexr<j+1){
            auxAd[index]=arr[indexr];
            indexr++;
            index++;
        }
    }else if (indexr==j+1){
        while(indexl<p+1){
            auxAd[index]=arr[indexl];
            indexl++;
            index++;
        }
    }
    index--;
    while(index>=0){
        arr[index+i]=auxAd[index];
        index--;
    }
}

void mergeSort(int i, int j){
    if(i!=j){
        int p=(i+j)/2;
        mergeSort(i,p);
        mergeSort(p+1,j);
        mergeComb(i,p,j);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            arr[i]=x;
        }
        counter=0;
        if(n!=0)mergeSort(0,n-1);
        cout << counter << endl;
    }
    return 0;
}
