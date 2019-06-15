#include <iostream>

using namespace std;
vector<vector<long>.assign(105)>.assign(105);

vector<vector<long>> multMatrixes (long mat1[][105], long mat2 [][105], int cize){
    long toReturn [cize][cize];
    for (int i = 0; i < cize; i++){
        for (int j = 0; j < cize; j++){
                toReturn[i][j] = 0;
            for (int k = 0; j < cize; j++){
                toReturn [i][j] += ((mat1[i][k]) % 1000000009 *(mat2[k][j])%1000000009) % 1000000009;
            }
        }
    }
    return toReturn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    int n;
    cin >> k;
    cin >> n;
    while(k != 0 && n != 0){
        for (int i = 0; i < k; i++){
            for (int j = 0; j < k; j++){
                if (j < k - i){
                    matrix[i][j] = 1;
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
        long acum [k][k];
        long result [k][k];
        for (int i = 0; i < k; i++){
            for (int j = 0; j < k; j++){
                if (i == j){
                    result[i][j] = 1;
                    acum[i][j] = 1;
                } else {
                    result [i][j] = 0;
                    acum[i][j] = 0;
                }
            }
        }
        for (int i = 0; (1<<i) <= n ; i++){
            acum = multMatrixes(acum, matrix, k);
            if (n & (1 << i) != 0){
                result = multMatrixes(result, acum, k);
            }
        }
        cout << (result[0][0])%1000000009 << endl
        cin >> k;
        cin >> n;
    }

    cout << "Hello world!" << endl;
    return 0;
}
