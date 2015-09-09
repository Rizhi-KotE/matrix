// matrix.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "RealMatrix.h"


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	RealMatrix matrix1 = RealMatrix("matrix1.txt");
	RealMatrix matrix2 = RealMatrix("matrix2.txt");
	matrix1 *= matrix2;
	matrix2 *= 3;
	matrix2.printMatrix();
	return 0;
}