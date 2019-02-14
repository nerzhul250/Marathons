#include <iostream>

using namespace std;

char board[8][8];
bool check(int i, int j){
    return i>=0 && i<8 && j>=0 && j<8 && (board[i][j]=='1' || board[i][j]=='0');
}
int main()
{
    string fen;
    int i=0,j=0;
    int counter;
    while(cin >> fen){
        i=0;
        j=0;
        for (int m=0;m<8 ;m++ ){
            for (int n=0;n<8;n++ ){
                    board[m][n]='0';
            }
        }
        for (int p=0;p<fen.length();p++){
            if('1'<=fen[p]&& fen[p]<='8'){
                j+=(fen[p]-'0');
            }else if(fen[p]=='/'){
                i++;
                j=0;
            }else{
                board[i][j]=fen[p];
                j++;
            }
        }
        for (i=0;i<8 ;i++ ){
            for (j=0;j<8;j++ ){
                if(board[i][j]=='p'){
                    if(check(i+1,j-1))board[i+1][j-1]='1';
                    if(check(i+1,j+1))board[i+1][j+1]='1';
                }else if(board[i][j]=='P'){
                    if(check(i-1,j-1))board[i-1][j-1]='1';
                    if(check(i-1,j+1))board[i-1][j+1]='1';
                }else if(board[i][j]=='r' || board[i][j]=='R'){
                    for (int k=j+1;k<8 && check(i,k);k++)board[i][k]='1';
                    for (int k=j-1;k>=0 && check(i,k);k--)board[i][k]='1';
                    for (int k=i+1;k<8 && check(k,j);k++)board[k][j]='1';
                    for (int k=i-1;k>=0 && check(k,j);k--)board[k][j]='1';
                }else if(board[i][j]=='n' || board[i][j]=='N'){
                    if(check(i-2,j+1))board[i-2][j+1]='1';
                    if(check(i-2,j-1))board[i-2][j-1]='1';
                    if(check(i-1,j+2))board[i-1][j+2]='1';
                    if(check(i-1,j-2))board[i-1][j-2]='1';
                    if(check(i+2,j+1))board[i+2][j+1]='1';
                    if(check(i+2,j-1))board[i+2][j-1]='1';
                    if(check(i+1,j+2))board[i+1][j+2]='1';
                    if(check(i+1,j-2))board[i+1][j-2]='1';
                }else if(board[i][j]=='b' || board[i][j]=='B'){
                    for (int k=1;k+i<8 && k+j<8 && check(k+i,k+j);k++)board[k+i][k+j]='1';
                    for (int k=-1;k+i>=0 && k+j>=0 && check(k+i,k+j);k--)board[k+i][k+j]='1';
                    for (int k=1;i-k>=0 && k+j<8 && check(i-k,k+j);k++)board[i-k][k+j]='1';
                    for (int k=1;k+i<8 && j-k>=0 && check(k+i,j-k);k++)board[k+i][j-k]='1';
                }else if(board[i][j]=='q' || board[i][j]=='Q'){
                    for (int k=j+1;k<8 && check(i,k);k++)board[i][k]='1';
                    for (int k=j-1;k>=0 && check(i,k);k--)board[i][k]='1';
                    for (int k=i+1;k<8 && check(k,j);k++)board[k][j]='1';
                    for (int k=i-1;k>=0 && check(k,j);k--)board[k][j]='1';
                    for (int k=1;k+i<8 && k+j<8 && check(k+i,k+j);k++)board[k+i][k+j]='1';
                    for (int k=-1;k+i>=0 && k+j>=0 && check(k+i,k+j);k--)board[k+i][k+j]='1';
                    for (int k=1;i-k>=0 && k+j<8 && check(i-k,k+j);k++)board[i-k][k+j]='1';
                    for (int k=1;k+i<8 && j-k>=0 && check(k+i,j-k);k++)board[k+i][j-k]='1';
                }else if(board[i][j]=='k' || board[i][j]=='K'){
                    if(check(i+1,j+1))board[i+1][j+1]='1';
                    if(check(i,j+1))board[i][j+1]='1';
                    if(check(i-1,j+1))board[i-1][j+1]='1';
                    if(check(i-1,j))board[i-1][j]='1';
                    if(check(i-1,j-1))board[i-1][j-1]='1';
                    if(check(i,j-1))board[i][j-1]='1';
                    if(check(i+1,j-1))board[i+1][j-1]='1';
                    if(check(i+1,j))board[i+1][j]='1';
                }
            }
        }

        counter=0;
        for (int m=0;m<8 ;m++ ){
            for (int n=0;n<8;n++ ){
                    if(board[m][n]=='0'){
                        counter++;
                    }
            }
        }
        cout << counter<<endl;
    }
    return 0;
}
