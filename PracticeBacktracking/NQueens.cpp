// EightQueens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "NQueens.h"
#include "LeetCodeUtil.h"

namespace Backtracking
{
    using namespace std;
    using namespace LeetCodeUtil;

    void NQueenVerbose::solveEightQueens(vector<vector <bool>>& aTable, int columnIdx)
    {
        for (int x = 0; x < m_tableSize; ++x)
        {
            if (isValid(aTable, x, columnIdx))
            {
                aTable[x][columnIdx] = true;
                if (columnIdx == m_tableSize - 1)
                {
                    static int count = 1;
                    cout << "Result " << count << endl;
                    printResult(aTable);
                    count++;
                }
                else
                {
                    solveEightQueens(aTable, columnIdx + 1);
                }

                aTable[x][columnIdx] = false;
            }
        }

    }

    void NQueenVerbose::printResult(vector<vector <bool>>& aTable)
    {
        for (int i = 0; i < m_tableSize; ++i)
        {
            for (int j = 0; j < m_tableSize; ++j)
            {
                if (aTable[i][j])
                {
                    cout << "Q";
                }
                else
                {
                    cout << "E";
                }
            }
            cout << "\n";
        }
        cout << "\n\n";
    }

    //! Check if a queen can be put at (x, y). Note that we know
    //! column y is empty and column after y are all empty.
    bool NQueenVerbose::isValid(vector<vector <bool>>& aTable, int x, int y)
    {
        // Check row
        for (int j = y - 1; j >= 0; --j)
        {
            if (aTable[x][j])
            {
                return false;
            }
        }

        // Check '\' direction
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (aTable[i][j])
            {
                return false;
            }
        }

        // Check '/' direction
        for (int i = x + 1, j = y - 1; i < m_tableSize && j >= 0; ++i, --j)
        {
            if (aTable[i][j])
            {
                return false;
            }
        }

        return true;
    }

    /////////////////////////////////////////////////////////////////////////////////////

    //! Check if a queen can be put in (x, y).
    bool NQueensLeetCode::isValid(char* aTable, size_t aTableSize, int x, int y)
    {
        // Check row
        for (int j = y - 1; j >= 0; --j)
        {
            if (aTable[x * aTableSize + j] == 'Q')
            {
                return false;
            }
        }

        // Check '\' direction
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (aTable[i * aTableSize + j] == 'Q')
            {
                return false;
            }
        }

        // Check '/' direction
        for (int i = x + 1, j = y - 1; i < aTableSize && j >= 0; ++i, --j)
        {
            if (aTable[i * aTableSize + j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    //! Build results.
    void NQueensLeetCode::buildResults(vector<vector<string>>& aResults, char* aTable, size_t aTableSize)
    {
        vector<string> table;
        for (size_t i = 0; i < aTableSize; ++i)
        {
            std::string row(aTable + ( i * aTableSize ), aTableSize);
            table.push_back(std::move(row));
        }
        aResults.push_back(std::move(table));
    }

    void NQueensLeetCode::putQueenInColumn(vector<vector<string>>& aResults, char* aTable, size_t aTableSize, size_t columnIndex)
    {
        for (size_t x = 0; x < aTableSize; ++x)
        {
            if (isValid(aTable, aTableSize, x, columnIndex))
            {
                aTable[x * aTableSize + columnIndex] = 'Q';
                if (columnIndex == aTableSize - 1)
                {
                    buildResults(aResults, aTable, aTableSize);
                }
                else
                {
                    putQueenInColumn(aResults, aTable, aTableSize, columnIndex + 1);
                }

                aTable[x * aTableSize + columnIndex] = '.';
            }
        }
    }

    vector<vector<string>> NQueensLeetCode::solveNQueens(int n)
    {
        char* table = new char[n * n];

        // Init
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                table[i * n + j] = '.';
            }
        }

        vector<vector<string>> results;

        putQueenInColumn(results, table, n, 0);

        delete[] table;

        return results;
    }

    void TestNQueens()
    {
        std::cout << "Test NQueenVerbose!\n";

        const int tableSize = 4;
        vector<vector<bool>> table(tableSize, vector<bool>(tableSize, false));

        NQueenVerbose nQueenVerbose(tableSize);
        nQueenVerbose.solveEightQueens(table, 0);

        std::cout << "Test NQueensLeetCode!\n";
        NQueensLeetCode nQueenLeetCode;
        vector<vector<string>> results = nQueenLeetCode.solveNQueens(tableSize);
        LeetCodeUtil::PrintMatrix(results);
    }
}

