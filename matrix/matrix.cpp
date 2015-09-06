// matrix.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "RealMatrix.h"


int _tmain(int argc, _TCHAR* argv[])
{
	RealMatrix matrix = RealMatrix("matrix.txt");
	matrix.printMatrix();
	return 0;
}