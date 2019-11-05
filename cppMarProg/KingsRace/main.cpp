#include <iostream>
#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long int ll;

int main()
{
    ll n, i, j;
    cin>>n;
    cin >>i;
    cin>>j;
    if(i == 1 && j == 1){
        cout<<"White"<<endl;
    }else if(i == n && j== n){
        cout<<"Black"<<endl;
    }else if(i+j<n+1){
        cout<<"White"<<endl;
    }else if(i+j>n+1){
        cout<<"Black"<<endl;
    }else if( i+ j== n+1){
        cout<<"White"<<endl;
    }
}
