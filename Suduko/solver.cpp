#include "solver.hpp"

bool Solver::solve(int p[9][9], int final[9][9])
{



	int row, col;
	if (!findEmptySquare(p, row, col) && validateSolution(p))
		return true;



	for (int a = 1; a <= 9; a++)
	{
		if (canBePlaced(a, row, col, p))
		{
			p[row][col] = a;
			if (solve(p, final))
			{
				for (int x = 0; x < 9; x++)
				{
					for (int y = 0; y < 9; y++)
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

void Solver::draw(int final[9][9], int original[9][9])
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD oldColor;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(h, &csbi);
	oldColor = csbi.wAttributes;


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	std::cout << std::endl << " ------------------------------- " << std::endl;

	for (int a = 0; a < 9; a++)
	{
		int countA = a + 1;
		std::cout << " | ";
		for (int b = 0; b < 9; b++)
		{
			int countB = b + 1;
			std::cout << final[a][b];

			if ((countB % 3 == 0) && (countB == 9))
			{
				std::cout << " | ";
				std::cout << std::endl;
			}
			else if (countB % 3 == 0)
				std::cout << " | ";
			else
			{
				std::cout << "  ";
			}
		}
		if (countA % 3 == 0) std::cout << " ------------------------------- " << std::endl;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), oldColor);
}

bool Solver::findEmptySquare(int p[9][9], int &row, int &col)
{
	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 9; b++)
		{
			if (p[a][b] == 0)
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
	//use this to see if a completed, filled-in, puzzle is valid


	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 9; b++)
		{
			if (p[a][b] == 0)
				return false;
			else
			{
				if (!checkCube(p[a][b], a, b, p) || !checkCross(p[a][b], a, b, p) || !checkSum(a, b, p))
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

	for (int a = 0; a < vals.size(); a++)
	{
		if (numToCheck == vals.at(a) && p[row][col] != numToCheck)
			return false;
	}

	return true;
}


bool Solver::checkSum(const int row, const int col, int final[9][9])
{
	//check row sums
	int temp = 0;
	for(int a = 0; a < 9; a++)
	{
		temp += final[a][0];
	}
	if (temp != 45) return false;
	
	//check cols
	temp = 0;
	for (int a = 0; a < 9; a++)
	{
		temp += final[0][a];
	}
	if (temp != 45) return false;

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


void openConsole()
{
	if (FreeConsole())
	{
		if (!AllocConsole())
			return;
	}
	else if (!AllocConsole())
	{
		return;
	}

	SetConsoleTitleA("Suduko Solver");

	FILE* console = nullptr;
	freopen_s(&console, "CONOUT$", "w", stdout);
}