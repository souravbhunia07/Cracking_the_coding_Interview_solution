#include <bits/stdc++.h>
using namespace std;

// TC = O(M * N)
// SC = O(M * N)

class Solution
{
public:
    
    bool canPlace(vector<string> &board, int &n, int x, int y)
    {
        // Column
        for(int k = 0; k < x; k++)
        {
            if(board[k][y] == 'Q')
            {
                return false;
            }
        }

        // Left Diagonal
        int i = x;
        int j = y;
        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
            i--; j--;
        }

        // Right Diagonal
        i = x;
        j = y;
        while(i >= 0 && j < n)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
            i--; j++;
        }
        return true;
    }

    void Nqueen(vector<string> &board, vector<vector<string>> &res, int n, int i)
    {
        // Base case
        if(i == n)
        {
            res.push_back(board);
            return;
        }

        // Recursive case
        // Try to place the queen in every row
        for(int j = 0; j < n; j++)
        {
            // weather the current i, j is safe or not
            if(canPlace(board, n, i, j))
            {
                board[i][j] = 'Q';
                Nqueen(board, res, n, i + 1);
                board[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        Nqueen(board, res, n, 0);
        return res;
    }
};

int main()
{
    Solution solution;
    int n = 4;
    vector<vector<string>> ans = solution.solveNQueens(n);

    for(auto str : ans)
    {
        cout << "[";
        for(auto ch : str)
        {
            cout << ch << " ";
        }
        cout << "]";
        cout << endl;
    }
    cout << endl;

    return 0;
}
