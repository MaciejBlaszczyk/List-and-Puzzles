#ifndef PUZZLE
#define PUZZLE

#include<cstring>
#include<windows.h> //for system("cls")
#include<conio.h> //for getch()
#include "List.h"

class Puzzle
{
public:
	Puzzle(const char _solution[], const char _word[]);

	void insert();
	void replace();
	void remove();
	void clear();
	void gotoPrior();
	void gotoNext();
	void gotoBeginning();
	void gotoEnd();
	void isSolved();
	void isEmpty() const;
	void showSolution() const;
	void showWord() const;
	void cursor() const;

private:
	List<char> solution, word;
	int wordLength;
	int cursorPosition;
};

Puzzle:: Puzzle(const char _solution[], const char _word[]) : wordLength(0), cursorPosition(0)
{
	for(unsigned int i = 0; i < strlen(_word); i++)
	{
		word.insert(_word[i]);
		solution.insert(_solution[i]);
		wordLength++;
		cursorPosition++;
	}

}

void Puzzle:: insert()
{
	char element;
	cout<<"Enter element: ";
	cin>>element;
	word.insert(element);
	cursorPosition++;
	wordLength++;
}

void Puzzle:: replace()
{
	char element;
	cout<<"Enter element: ";
	cin>>element;
	word.replace(element);
}

void Puzzle:: remove()
{
	word.remove();
	wordLength--;
}

void Puzzle:: clear()
{
	word.clear();
}

void Puzzle:: gotoPrior()
{
	word.gotoPrior();
	cursorPosition--;
	if(cursorPosition == 0)
		cursorPosition = wordLength;
}

void Puzzle:: gotoNext()
{
	word.gotoNext();
	cursorPosition++;
	if(cursorPosition == 1 + wordLength)
		cursorPosition = 1;
}

void Puzzle:: gotoBeginning()
{
	word.gotoBeginning();
	cursorPosition = 0;
}

void Puzzle:: gotoEnd()
{
	word.gotoEnd();
	cursorPosition = wordLength;
}

void Puzzle:: isSolved()
{
	if(solution == word)
	{
		cout<<"Puzzles solved !!!"<<endl;
		getch();
	}
	else
	{
		cout<<"Try again"<<endl;
		getch();
	}
}

void Puzzle:: isEmpty() const
{
	if(word.isEmpty())
		cout<<"List is empty"<<endl;
	else
		cout<<"List is not empty"<<endl;
	getch();
}

void Puzzle:: showWord() const
{
	word.showEverything();
}

void Puzzle:: showSolution() const
{
	solution.showEverything();
}

void Puzzle:: cursor() const
{
	for(int i = 0; i < cursorPosition-1; i++)
		cout<<" ";
	cout<<"^"<<endl;
}

#endif // PUZZLE
