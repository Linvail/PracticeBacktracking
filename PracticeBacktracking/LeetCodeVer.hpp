#ifndef LEET_CODE_VER
#define LEET_CODE_VER

#include <iostream>
#include <vector>

using namespace std;

//! Check if a queen can be put in (x, y).
bool isValid( char* aTable, size_t aTableSize, int x, int y )
{
    // Check row
    for( int j = y - 1; j >= 0; --j )
    {
        if( aTable[x * aTableSize + j] == 'Q' )
        {
            return false;
        }
    }

    // Check '\' direction
    for( int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j )
    {
        if( aTable[i * aTableSize + j] == 'Q' )
        {
            return false;
        }
    }

    // Check '/' direction
    for( int i = x + 1, j = y - 1; i < aTableSize && j >= 0; ++i, --j )
    {
        if( aTable[i * aTableSize + j] == 'Q' )
        {
            return false;
        }
    }

    return true;
}

//! Build results.
void buildResults( vector<vector<string>>& aResults, char* aTable, size_t aTableSize )
{
    vector<string> table;
    for( size_t i = 0; i < aTableSize; ++i )
    {
        std::string row( aTable + ( i * aTableSize ), aTableSize );
        table.push_back( std::move( row ) );
    }
    aResults.push_back( std::move( table ) );
}

void putQueenInColumn( vector<vector<string>>& aResults, char* aTable, size_t aTableSize, size_t columnIndex )
{
    for( size_t x = 0; x < aTableSize; ++x )
    {
        if( isValid( aTable, aTableSize, x, columnIndex ) )
        {
            aTable[x * aTableSize + columnIndex] = 'Q';
            if( columnIndex == aTableSize - 1 )
            {
                buildResults( aResults, aTable, aTableSize );
            }
            else
            {
                putQueenInColumn( aResults, aTable, aTableSize, columnIndex + 1 );
            }

            aTable[x * aTableSize + columnIndex] = '.';
        }
    }
}

vector<vector<string>> solveNQueens( int n )
{
    char* table = new char[n * n];

    // Init
    for( int i = 0; i < n; ++i )
    {
        for( int j = 0; j < n; ++j )
        {
            table[i * n + j] = '.';
        }
    }

    vector<vector<string>> results;

    putQueenInColumn( results, table, n, 0 );

    delete[] table;

    return results;
}

#endif