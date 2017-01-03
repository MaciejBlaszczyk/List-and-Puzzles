#include "Puzzle.h"
#include<windows.h> //for system("cls")
#include<conio.h> //for getch()

main()
{
	string word("banana");
	string answer("banaan");
	Puzzle puzle(answer.c_str(), word.c_str());

	char element;

	while(1)
	{
		char numb;
		system("cls");
		cout<<"Welcome to Puzzles !\n\n"
				<<"If you want to insert element after cursor , press +\n"
				<<"If you want to delete element on cursor position, press -\n"
				<<"If you want to replace element on cursor position, press =\n"
				<<"If you want to show element on cursor position, press @\n"
				<<"If you want to show whole puzzles, press S\n"
				<<"If you want to show answer, press A\n"
				<<"If you want to go to next element, press N\n"
				<<"If you want to go to prior element, press P\n"
				<<"If you want to go to the beginning of the list, press <\n"
				<<"If you want to go to the end of the list, press >\n"
				<<"If you want to check if list is empty, press E\n"
				<<"If you want to clear whole list, press C\n"
				<<"If you want to check if puzzles are solved, press ?\n"
				<<"If you want to exit, press Q\n";

		cin>>numb;
		try
		{
			switch(toupper(numb))
			{
				case '+' : cout<<"Enter element: "; cin>>element; puzle.puzzle.insert(element); getch();
				break;
				case '-' : puzle.puzzle.remove(); getch();
				break;
				case '=' : cout<<"Enter element: "; cin>>element; puzle.puzzle.replace(element); getch();
				break;
				case '@' : puzle.puzzle.showElement(); getch();
				break;
				case 'S' : puzle.puzzle.showEverything(); getch();
				break;
				case 'A' : puzle.solution.showEverything(); getch();
				break;
				case 'N' : puzle.puzzle.gotoNext();
				break;
				case 'P' : puzle.puzzle.gotoPrior();
				break;
				case '<' : puzle.puzzle.gotoBeginning();
				break;
				case '>' : puzle.puzzle.gotoEnd();
				break;
				case 'E' : if(puzle.puzzle.isEmpty() == true) cout<<"List is empty"<<endl; else cout<<"List is not empty"<<endl; getch();
				break;
				case 'C' : puzle.puzzle.clear(); getch();
				break;
				case '?' : if(puzle.isSolved() == true) { cout<<"Puzzles solved !!! Congratulations !!!"<<endl; getch(); }  else { cout<<"Try again"<<endl; getch(); }
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
