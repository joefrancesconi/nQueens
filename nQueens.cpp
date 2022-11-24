/*
 * Name: Joe Francesconi
 * Date Submitted: 4/18/2022
 * Lab Section: 005
 * Assignment Name: Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board

//prototypes
bool place(int **, int, int, int);
int find(int**, int, int);

int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
    int ** queens = new int*[n];
    for (int i = 0; i < n; i++)
    {
        queens[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            queens[i][j] = 0;
        }
    }
    //returns count of solutions
    return find(queens, n, 0);
}
//checks if queen can be placed in position
bool place(int ** queens, int n, int c, int r)
{
    //checks row
    for (int i = 0; i < n; i++)
    {
        if (queens[r][i] == 1)
            return false;
        
    }
    //checks diags
    int j;
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (queens[i][j] == 1)
            return false;
    }
    for (int i = r, j = c; i < n && j >= 0; i++, j--)
    {
        if (queens[i][j] == 1)
            return false;
    }
    return true;
}
//finds number of solution
int find(int ** queens, int n, int c)
{
    int r;
    int count = 0;

    if (c == n)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        r = i;
        if (place(queens, n, c, r))
        {
            queens[r][c] = 1;
            count += find(queens, n, c + 1);
            queens[r][c] = 0;
        }
    }
    return count;
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