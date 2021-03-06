#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef long long int ll;

ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 should be enough for most cases
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(1000);
    int n;
    cin>>n;
    vi ans;
    for(int i=0;i<primes.size() && primes[i]<=n;i++){
        int power=primes[i];
        while(power<=n){
            ans.push_back(power);
            power=power*primes[i];
        }
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++){
        if(i==ans.size()-1){
            cout << ans[i] << "\n";
        }else{
            cout << ans[i] << " ";
        }
    }
    return 0;
}
