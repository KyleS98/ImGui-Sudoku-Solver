#include "solver.hpp"


int main()
{
	Solver* s = new Solver;
	int puzzle[9][9] =
	{
		{ 5,7,0, 0,8,0, 3,0,0 },
		{ 2,0,0, 0,0,0, 0,0,8 },
		{ 3,0,0, 9,0,0, 0,7,0 },

		{ 0,0,0, 0,9,0, 0,0,0 },
		{ 0,0,5, 0,2,0, 0,4,7 },
		{ 0,8,0, 0,0,0, 0,6,2 },

		{ 1,3,2, 5,0,6, 0,8,0 },
		{ 0,4,7, 0,3,9, 0,0,6 },
		{ 0,5,0, 2,0,0, 4,0,0 }
	};

	int originalCpy[9][9];
	int output[9][9];
	memcpy(originalCpy, puzzle, sizeof(puzzle));


	std::vector<int> final;
	std::cout << "Computing solution...";
	if (s->solve(puzzle, output))
	{
		if (s->validateSolution(output))
		{
			system("cls");
			s->draw(output, originalCpy);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN  | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "\nSolution validated!";
		}
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\n\nUnable to generate solution. The puzzle is likely unsolvable.";
	}


	std::cin.get();
}


