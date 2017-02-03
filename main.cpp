#include "Puzzle.h"

main()
{
	string word("banana");
	string solution("banaan");
	Puzzle puzle(solution.c_str(), word.c_str());

	while(1)
	{
		char numb;
		system("cls");
		cout<<"Welcome to Puzzles !\n\n"
			<<"If you want to insert element after cursor , press +\n"
			<<"If you want to delete element on cursor position, press -\n"
			<<"If you want to replace element on cursor position, press =\n"
			<<"If you want to go to next element, press N\n"
			<<"If you want to go to prior element, press P\n"
			<<"If you want to go to the beginning of the list, press <\n"
			<<"If you want to go to the end of the list, press >\n"
			<<"If you want to check if list is empty, press E\n"
			<<"If you want to clear whole list, press C\n"
			<<"If you want to check if puzzles are solved, press ?\n"
			<<"If you want to exit, press Q\n";

		cout<<endl<<"Puzzle:"<<endl;
		puzle.showWord();
		cout<<endl;
		puzle.cursor();
		cout<<"Solution:"<<endl;
		puzle.showSolution();
		cout<<endl;
		cin>>numb;
		try
		{
			switch(toupper(numb))
			{
				case '+' : puzle.insert();
				break;
				case '-' : puzle.remove();
				break;
				case '=' : puzle.replace();
				break;
				case 'N' : puzle.gotoNext();
				break;
				case 'P' : puzle.gotoPrior();
				break;
				case '<' : puzle.gotoBeginning();
				break;
				case '>' : puzle.gotoEnd();
				break;
				case 'E' : puzle.isEmpty();
				break;
				case 'C' : puzle.clear();
				break;
				case '?' : puzle.isSolved();
				break;
				case 'Q' : return 1;
				break;

				default : cout<<"Enter other sign"<<endl;
				break;
			}
		}

		catch(const logic_error &le)
		{
			cerr<<"Logic Error: "<<le.what()<<endl;
			getch();
		}

		catch(const bad_alloc &ba)
		{
			cerr<<"Bad Alloc Error: "<<ba.what()<<endl;
			getch();
		}
	}
	return 0;
}

