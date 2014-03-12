#include <cassert>//provides assert
#include <iostream> //we are adding ostream and istream
#include <cstdlib>
#include <fstream>
#include <string>
#include "maze.h"

using namespace std;


		
				maze::maze()
				{
					ifstream myIns;
					myIns.open("Maze.txt");
					assert (myIns.is_open());

					myIns>>yDim>>xDim;

					mazeArray= new char[yDim*xDim];
					for (int i=0; i<yDim; i++)
						{
						for (int p=0; p<xDim; p++)
						{
						myIns>>mazeArray[i*xDim+p];
						}
						}
				}



		void maze::init()
		{
			for ( int i = 0; i < xDim*yDim; i++)
			{
				
				if (mazeArray[i] == '*')
				{
					startingIndex = i;
					cout << "The starting index is:" << i << endl; 

				}
			}
			solve(startingIndex);



		}





		bool maze::solve(int index)
		{
			int row = index / xDim;
			char wall = 'x';
			char passage = '-';
			char goal = '$';
			char beenthere = '*';
			char badpath = '#';
			mazeArray[index]=beenthere;

			//WIN
			if (mazeArray[index-xDim]==goal){mazeArray[index-xDim] = '*';cout << "YOU WIN" << endl;return true;}
			if (mazeArray[index+xDim]==goal){mazeArray[index+xDim] = '*';cout << "YOU WIN" << endl;return true;}
			if ((mazeArray[index-1]==goal) && ((index-1) != (((xDim-1)*row)+(row-1)))) {mazeArray[index-1] = '*';cout << "YOU WIN" << endl;return true;}
			if ((mazeArray[index+1]==goal) && ((index+1) % xDim != 0)){mazeArray[index+1] = '*';cout << "YOU WIN" << endl;return true;}

			//UP
			if ((mazeArray[index - xDim]==passage) && (mazeArray[index - xDim]>0))
					{if (solve(index-xDim)){mazeArray[index]= '*'; return true;}}
			
			//RIGHT
			if ((mazeArray[index+1]==passage) && ((index+1) % xDim != 0))
				{if (solve(index+1)){mazeArray[index]='*';return true;}}

			//LEFT
			if ((mazeArray[index-1]==passage) && ((index-1) != (((xDim-1)*row)+(row-1))))
				{if (solve(index-1)){mazeArray[index]='*';return true;}}

			//DOWN
			if ((mazeArray[index+xDim]==passage) && (index+xDim < xDim*yDim)) //arraylength
				{if (solve(index+xDim)){mazeArray[index] = '*'; return true;}}

			mazeArray[index]=passage;
			return false;

		}


		ostream&operator <<(std::ostream& outs, const maze& source)
		{
			for (int i = 0; i <= source.yDim; i++)
			{
				for (int a = 0; a <= source.xDim; a++)
				{
					outs << source.mazeArray[(i * source.xDim) + a];
				}
				cout << "\n";
			}
		cout << "\n";
		return outs;

		}


