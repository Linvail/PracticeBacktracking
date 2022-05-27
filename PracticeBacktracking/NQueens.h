#ifndef N_QUEENS_H
#define N_QUEENS_H

#include <iostream>
#include <vector>

namespace Backtracking
{
    using namespace std;

    class NQueenVerbose
    {
    public:

        int m_tableSize;

        NQueenVerbose(int aTableSize) : m_tableSize(aTableSize) {}

        //! Check if a queen can be put at (x, y). Note that we know
        //! column y is empty and column after y are all empty.
        bool isValid(vector<vector <bool>>& aTable, int x, int y);

        void printResult(vector<vector <bool>>& aTable);

        void solveEightQueens(vector<vector <bool>>& aTable, int columnIdx);
    };

    class NQueensLeetCode
    {
    public:

        void buildResults(vector<vector<string>>& aResults, char* aTable, size_t aTableSize);

        bool isValid(char* aTable, size_t aTableSize, int x, int y);

        void putQueenInColumn(vector<vector<string>>& aResults, char* aTable, size_t aTableSize, size_t columnIndex);

        vector<vector<string>> solveNQueens(int n);
    };

    void TestNQueens();
}

#endif