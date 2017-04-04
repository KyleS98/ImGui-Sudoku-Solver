#pragma once
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <sstream>
#include <vector>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <Rtutils.h>

class Solver
{
public:
	bool solve(int in[9][9], int(&final)[9][9]);
	bool validateSolution(int p[9][9]);
	void draw(int final[9][9], int original[9][9]);
protected:
	bool findEmptySquare(int p[9][9], int &row, int &col);
	bool canBePlaced(const int numToCheck, const int row, const int col, int p[9][9]);
	bool checkCross(const int numToCheck, const int row, const int col, int p[9][9]);
	bool checkCube(const int numToCheck, const int row, const int col, int p[9][9]);
	int getCubeRegionNumber(const int row, const int col);
	std::vector<int> getCubeValues(const int cubeRegionNumber, int p[9][9]);
};