#include <iostream>
#include <math.h>
#include <bitset> // compact STL for Sieve, better than vector<bool>!
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<1000010> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>

void sieve(ll upperbound) { // create list of primes in [0..upperbound]
_sieve_size = upperbound + 1; // add 1 to include upperbound
bs.set(); // set all bits to 1
bs[0] = bs[1] = 0; // except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
primes.push_back((int)i); // add this prime to the list of primes
} } // call this method in main method
bool isPrime(ll N) { // a good enough deterministic prime tester
if (N <= _sieve_size) return bs[N]; // O(1) for small primes
for (int i = 0; i < (int)primes.size(); i++)
if (N % primes[i] == 0) return false;
return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2


ll countNonPrimes(ll low, ll high){
    ll sum=0;
    for(int i=0;i<primes.size() && primes[i]*primes[i]<=high;i++){
        int l=ceil(log2(low)/log2(primes[i]));
        int r=floor(log2(high)/log2(primes[i]));
        if(l<=r){
            if(l==0){
                sum+=r-1;
            }else if(l==1){
                sum+=r-l;
            }else{
                sum+=r-l+1;
            }
        }
    }
    return sum;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(1000000); // can go up to 10^7 (need few seconds)
    int N;
    cin >> N;
    while(N--){
        ll low, high;
        cin >> low >> high;
        if(low > high) swap(low,high);
        cout << countNonPrimes(low,high) << "\n";
    }
    return 0;
}
