#ifndef MAIN_GORDON_MAZE_H
#define MAIN_GORDON_MAZE_H

#include <fstream>
#include <string>

class maze
{
	public:
		// maze(int x, int y);
		maze();

		void init();

		bool solve(int index);

		void read(char *filename);

		// bool moveleft(int index);
		// bool moveright(int index);
		// bool movedown(int index);
		// bool moveup(int index);
		// bool backtrack(int index);


		friend std::ostream& operator <<(std::ostream& outs, const maze& source);


		// private:
		char* mazeArray;
		int startingIndex;
		int xDim;
		int yDim;
		int arraylength;
};



#endif


