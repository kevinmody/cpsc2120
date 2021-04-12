/*
 * Name: Kevin Mody
 * Date Submitted: 04/05/21
 * Lab Section: Using Recursion to Solve the N-Queens Problem
 * Assignment Name: Kevin Mody
 */

#include <iostream>
#include <vector>

using namespace std;
/*
//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
    int num = 0;
    vector<vector<bool>> chess(n, vector<bool>(n,false));
    recursiveBoard(0, n, chess, num);
    return num;
}
*/

void recursiveBoard(int rows, int n, vector<vector<bool>>&board, int& num){

    int totalCol = n;
    if(rows == n)
    {
        if(n % 2 == 1 && board[0][n/2])
        {
            num++;
        }
        else
        {
            num += 2;
        }
        return;
    }

    if(rows == 0)
    {
        totalCol = (n + 1)/2;
    }else
    {
        totalCol = n;
    }


    for(int i = 0; i < totalCol; i++)
    {
        bool safe = true;

        for(int j = rows-1; j >= 0; j--)
        {
            if(board[j][i] == true)
            {
                safe = false;
            }
            int left = i-(rows-j);
            int right = i+(rows-j);

            if(left >= 0)
            {
                if(board[j][left] == true)
                {
                    safe = false;
                }
            }
            if(right < n)
            {
                if(board[j][right] == true)
                {
                    safe = false;
                }
            }
        }

        if(safe == true)
        {
            board[rows][i] = true;
            recursiveBoard(rows+1, n, board, num);
            board[rows][i] = false;
        }
    }
}
//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
    int num = 0;
    vector<vector<bool>> chess(n, vector<bool>(n,false));
    recursiveBoard(0, n, chess, num);
    return num;
}

int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}