#include <iostream>
#define N 8
using namespace std;

//int N;

void queen(int board[N][N])

{

    for (int i = 0; i < N; i++)

    {
        for (int j = 0; j < N; j++)
            cout<<board[i][j]<<"  ";
        cout<<endl;
    }

}

bool colFound(int board[N][N], int r, int c){

    int i, j;
    for (i = 0; i < c; i++)
    {
        if (board[r][i])
            //queen(board);
            return false;
    }
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--){

        if (board[i][j]){
            queen(board);
            cout<<""<<endl;
            return false;
        }
    }
    for (i = r, j = c; j >= 0 && i < N; i++, j--){

        if (board[i][j])
            return false;
    }

    return true;
}

bool check(int board[N][N], int c){

    if (c >= N)
        return true;
    for (int i = 0; i < N; i++){

        if ( colFound(board, i, c) )
        {
            board[i][c] = 1;
            if (check(board, c + 1) == true){

                return true;
            }

            board[i][c] = 0;
        }
    }
    return false;
}

bool solve(){

    int board[N][N] = {0};
    if (check(board, 0) == false)
    {
        //queen(board);
        cout<<"Not found";
        return false;
    }
    queen(board);
    return true;
}
int main()

{
    /*
    cout<<"Size:";
    int zN;
    cin>>zN;
*/
    solve();

    return 0;

}
