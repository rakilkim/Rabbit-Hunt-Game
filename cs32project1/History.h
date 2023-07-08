#ifndef HISTORY_H
#define HISTORY_H
class Arena;
#include "globals.h"

class History
{
public:
	History(int nRows, int nCols);
	bool record(int r, int c);
	void display() const;
private:
	int m_nRows;
	int m_nCols;
	int historyGrid[MAXROWS][MAXCOLS];
};

#endif