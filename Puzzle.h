#ifndef PUZZLE
#define PUZZLE

#include<cstring>
#include "List.h"

class Puzzle
{
public:
	Puzzle(const char answ[], const char init[]);

	bool isSolved() { return solution == puzzle ? true : false; }

	List<char> solution, puzzle;
};

Puzzle:: Puzzle(const char answ[], const char init[])
{
	for(unsigned int i = 0; i < strlen(init); i++)
	{
		puzzle.insert(init[i]);
		solution.insert(answ[i]);
	}
}

#endif // PUZZLE
