#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;
    cin >> t;
    int actCase = 0;
    while (actCase < t){
        int n = 0;
        cin >> n;

        int sticksToNumber [7] = {0,1,0,4,2,6,8};
        int sticksToSticks [7] = {2,2,5,5,5,6,7};
        int numDigits = n/7 + 1;
        if (n < 7){
            int toPrint = sticksToNumber[sticksToSticks[n]-1];
            if (toPrint == 6){
                toPrint = 0;
            }
            cout << toPrint;
        } else if (true){
            int restSticks = n%7;
            int realPalos = sticksToSticks[restSticks];
            int firstDigit = sticksToNumber[realPalos-1];
            n -= realPalos;
            int tot8 = 0;
            if (6*(numDigits - 1) > n){
                tot8 = 0;
            }
            numDigits -= (tot8+1);
            cout << firstDigit;
            for (int i = 0; i < numDigits; i++){
                cout << "0";
            }
            for (int i = 0; i < tot8; i++){
                cout << "8";
            }
        } else {
            cout <<"1";
            if (n == 7){
                cout << "0";
            } else {
                for (int i = 0; i < numDigits - 1; i++){
                    cout << "8";
                }
            }

        }
        cout << "\n";
        actCase++;
    }
}
