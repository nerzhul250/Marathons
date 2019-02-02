#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAX = 1e6 + 5;

vector <ll> lista[MAX];

int n, d[MAX];
double dp[MAX], c[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> d[i] >> c[i], dp[i] = 1e15;

    for(int i = 1; i <= n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + c[i]);
        int dur = d[i];
        if(dur < 120)
            dp[i + 1] = min(dp[i + 1], dp[i - 1] + c[i] + 0.5 * c[i + 1]);
        double s = 0;
        for(int j = 1; j <= 4; j++) {
            dur += d[j + i];
            s += c[i + j + 1];
            if(dur < 120)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - 1] + c[i] + 0.5 * c[i + 1] + 0.25 * s);
        }
    }

    cout << setprecision(2) << fixed;
    cout << dp[n] << '\n';
}
