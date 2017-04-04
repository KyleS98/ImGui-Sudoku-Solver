// Suduko.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"





class Solver
{
public:
	bool solve(int p[9][9], int (&final)[9][9]);
	bool validateSolution(int p[9][9]);
	void draw(int final[9][9]);
protected:
	bool findEmptySquare(int p[9][9], int &row, int &col);
	bool canBePlaced(const int numToCheck, const int row, const int col, int p[9][9]);
	bool checkCross(const int numToCheck, const int row, const int col, int p[9][9]);
	bool checkCube(const int numToCheck, const int row, const int col, int p[9][9]);
	int getCubeRegionNumber(const int row, const int col);
	std::vector<int> getCubeValues(const int cubeRegionNumber, int p[9][9]);
};



int main()
{
	Solver* s = new Solver;
	int testPuzzle[9][9] =
	{
		{0,7,0, 0,8,0, 3,0,0},
		{2,0,0, 0,0,0, 0,0,8},
		{3,0,0, 9,0,0, 0,7,0},

		{0,0,0, 0,9,0, 0,0,0},
		{0,0,5, 0,2,0, 0,4,7},
		{0,8,0, 0,0,0, 0,6,2},

		{0,0,2, 0,0,6, 0,8,0},
		{0,4,7, 0,3,9, 0,0,6},
		{0,5,0, 2,0,0, 4,0,0}
	};

	int output[9][9];





	std::vector<int> final;
	std::cout << "Computing solution...";
	if (s->solve(testPuzzle, output))
	{
		system("cls");
		if (s->validateSolution(output))
		{
			s->draw(output);
			std::cout << "\nSolution validated...";
		}
	}


	std::cin.get();
}


bool Solver::solve(int p[9][9], int (&final)[9][9])
{

	int row, col;
	if (!findEmptySquare(p, row, col))
		return true;
	if (validateSolution(p))
		return true;


	for (int a = 1; a <= 9; a++)
	{
		if(canBePlaced(a, row, col, p))
		{
			p[row][col] = a;
			if (solve(p, final))
			{
				for(int x = 0; x < 9; x++)
				{
					for(int y = 0; y < 9; y++)
					{
						final[x][y] = p[x][y];
					}
				}
				return true;
			}
			p[row][col] = 0;
		}
	}
	return false;
}

void Solver::draw(int final[9][9])
{
	std::cout << "SOLUTION:" << std::endl << " -------------------------------------" << std::endl;

	for (int a = 0; a < 9; a++)
	{
		std::cout << " | ";
		for (int b = 0; b < 9; b++)
		{
			int countB = b + 1;

			std::cout << final[a][b] << " | ";

			if (countB % 9 == 0) std::cout << std::endl << " -------------------------------------" << std::endl;
		}
	}

}

bool Solver::findEmptySquare(int p[9][9], int &row, int &col)
{
	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 9; b++)
		{
			if(p[a][b] == 0)
			{
				row = a;
				col = b;
				return true;
			}
		}
	}
	return false;
}

bool Solver::canBePlaced(const int numToCheck, const int row, const int col, int p[9][9])
{
	//use this to see if a number can be placed not if a puzzle is valid

	if (!p[row][col] == 0)
		return false;
	else if (checkCross(numToCheck, row, col, p) && checkCube(numToCheck, row, col, p))
		return true;
	else return false;
}

bool Solver::validateSolution(int p[9][9])
{
	//use this to see if a completed (filled-in) puzzle is valid
	//there is another function to see if a single number is possibly valid with given information


	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 9; b++)
		{
			if (p[a][b] == 0)
				return false;
			else
			{
				if (!checkCube(p[a][b], a, b, p) || !checkCross(p[a][b], a, b, p))
					return false;
				
			}
		}
	}
	return true;
}

bool Solver::checkCross(const int numToCheck, const int row, const int col, int p[9][9])
{


	//check col
	for (int a = 0; a < 9; a++)
	{

		if (a != row)
		{
			if (numToCheck == p[a][col])
			{
				return false;
			}
		}
	}

	//check row
	for (int b = 0; b < 9; b++)
	{
		if (b != col)
		{
			if (numToCheck == p[row][b])
			{
				return false;
			}
		}
	}

	return true;
}

bool Solver::checkCube(const int numToCheck, const int row, const int col, int p[9][9])
{
	int region = getCubeRegionNumber(row, col);
	std::vector<int> vals = getCubeValues(region, p);

	for(int a = 0; a < vals.size(); a++)
	{
		if (numToCheck == vals.at(a) && p[row][col] != numToCheck)
			return false;
	}

	return true;
}

int Solver::getCubeRegionNumber(const int row, const int col)
{
	if ((col <= -1) || (col >= 9) || (row <= -1) || (row >= 9))
		throw std::runtime_error("Invalid cube region parameters passed");

	if (row <= 2)
	{
		if (col <= 2)
		{
			return 1;
		}

		else if (col <= 5)
		{
			return 2;
		}

		else if (col >= 6)
		{
			return 3;
		}
	}

	else if (row <= 5)
	{
		if (col <= 2)
		{
			return 4;
		}

		else if (col <= 5)
		{
			return 5;
		}

		else if (col >= 6)
		{
			return 6;
		}
	}

	else if (row <= 8)
	{
		if (col <= 2)
		{
			return 7;
		}

		else if (col <= 5)
		{
			return 8;
		}

		else if (col >= 6)
		{
			return 9;
		}
	}
	
}

std::vector<int> Solver::getCubeValues(const int cubeRegionNumber, int p[9][9])
{
	std::vector<int> values;
	
	//top third

	if (cubeRegionNumber == 1)
	{
		for (int a = 0; a < 3; a++)
		{
			for (int b = 0; b < 3; b++)
			{
				values.push_back(p[a][b]);
			}
		}
		return values;
	}
	if (cubeRegionNumber == 2)
	{
		for (int a = 0; a < 3; a++)
		{
			for (int b = 3; b < 6; b++)
			{
				values.push_back(p[a][b]);
			}
		}
		return values;
	}
	if (cubeRegionNumber == 3)
	{
		for (int a = 0; a < 3; a++)
		{
			for (int b = 6; b < 9; b++)
			{
				values.push_back(p[a][b]);
			}
		}
		return values;
	}


	//middle third

	if (cubeRegionNumber == 4)
	{
		for (int a = 3; a < 6; a++)
		{
			for (int b = 0; b < 3; b++)
			{
				values.push_back(p[a][b]);
			}
		}
		return values;
	}
	if (cubeRegionNumber == 5)
	{
		for (int a = 3; a < 6; a++)
		{
			for (int b = 3; b < 6; b++)
			{
				values.push_back(p[a][b]);
			}
		}
		return values;
	}
	if (cubeRegionNumber == 6)
	{
		for (int a = 3; a < 6; a++)
		{
			for (int b = 6; b < 9; b++)
			{
				values.push_back(p[a][b]);
			}
		}
		return values;
	}
	

	//bottom third

	if (cubeRegionNumber == 7)
	{
		for (int a = 6; a < 9; a++)
		{
			for (int b = 0; b < 3; b++)
			{
				values.push_back(p[a][b]);
			}
		}
		return values;
	}
	if (cubeRegionNumber == 8)
	{
		for (int a = 6; a < 9; a++)
		{
			for (int b = 3; b < 6; b++)
			{
				values.push_back(p[a][b]);
			}
		}
		return values;
	}
	if (cubeRegionNumber == 9)
	{
		for (int a = 6; a < 9; a++)
		{
			for (int b = 6; b < 9; b++)
			{
				values.push_back(p[a][b]);
			}
		}
		return values;
	}
	

	throw std::runtime_error("You done fucked up nigga");
}
