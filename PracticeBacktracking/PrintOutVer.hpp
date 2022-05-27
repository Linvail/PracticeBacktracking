#ifndef PRINT_OUT_VER
#define PRINT_OUT_VER

#include <iostream>

using namespace std;

//! Check if a queen can be put at (x, y). Note that we know
//! column y is empty and column after y are all empty.
template <size_t TableSize>
bool isValid( bool( &aTable )[TableSize][TableSize], int x, int y )
{
    // Check row
    for( int j = y - 1; j >= 0; --j )
    {
        if( aTable[x][j] )
        {
            return false;
        }
    }

    // Check '\' direction
    for( int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j )
    {
        if( aTable[i][j] )
        {
            return false;
        }
    }

    // Check '/' direction
    for( int i = x + 1, j = y - 1; i < TableSize && j >= 0; ++i, --j )
    {
        if( aTable[i][j] )
        {
            return false;
        }
    }

    return true;
}

template <size_t TableSize>
void printResult( bool( &aTable )[TableSize][TableSize] )
{
    for( int i = 0; i < TableSize; ++i )
    {
        for( int j = 0; j < TableSize; ++j )
        {
            if( aTable[i][j] )
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

template <size_t TableSize>
void solveEightQueens( bool( &aTable )[TableSize][TableSize], int columnIdx )
{
    for( int x = 0; x < TableSize; ++x )
    {
        if( isValid( aTable, x, columnIdx ) )
        {
            aTable[x][columnIdx] = true;
            if( columnIdx == TableSize - 1 )
            {
                static int count = 1;
                cout << "Result " << count << endl;
                printResult( aTable );
                count++;
            }
            else
            {
                solveEightQueens( aTable, columnIdx + 1 );
            }

            aTable[x][columnIdx] = false;
        }
    }

}

#endif