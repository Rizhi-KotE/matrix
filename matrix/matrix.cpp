// matrix.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "RealMatrix.h"


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	RealMatrix matrix1 = RealMatrix("matrix1.txt");
	RealMatrix matrix2 = RealMatrix("matrix2.txt");
	RealMatrix matrix3 = RealMatrix("matrix3.txt");
	RealMatrix matrix4 = RealMatrix("matrix4.txt");
	cout << matrix4.det();
	//matrix3.printMatrix();
	system("pause");
	return 0;
}