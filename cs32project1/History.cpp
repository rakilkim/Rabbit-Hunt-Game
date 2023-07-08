#include "History.h"
#include "Arena.h"
#include "globals.h"

#include <iostream>
using namespace std;

History::History(int nRows, int nCols)
{
	m_nRows = nRows;
	m_nCols = nCols;
    int row, col;
    for (row = 1; row <= m_nRows; row++)
        for (col = 1; col <= m_nCols; col++)
            historyGrid[row - 1][col - 1] = 0;
}


bool History::record(int r, int c)
{
	if (r > m_nRows || c > m_nCols || r < 1 || c < 1)
	{
		return false;
	}

    historyGrid[r - 1][c - 1]++;
    return true;
	
}
void History::display() const
{


    char displayGrid[MAXROWS][MAXCOLS];
    int r, c;

    for (r = 1; r <= m_nRows; r++)
        for (c = 1; c <= m_nCols; c++)
        {
            if (historyGrid[r - 1][c - 1] == 0)
                displayGrid[r - 1][c - 1] = '.';
            else if (historyGrid[r - 1][c - 1] < 26)
                displayGrid[r - 1][c - 1] = 'A' - 1 + historyGrid[r - 1][c - 1];
            else 
                displayGrid[r - 1][c - 1] = 'Z';
        }
            

    // Draw the grid
    clearScreen();
    for (r = 1; r <= m_nRows; r++)
    {
        for (c = 1; c <= m_nCols; c++)
            cout << displayGrid[r - 1][c - 1];
        cout << endl;
    }
    cout << endl;


}

