// matrix.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include "RealMatrix.h"


int _tmain(int argc, _TCHAR* argv[])
{
	RealMatrix matrix = RealMatrix("matrix.txt");
	matrix.printMatrix();
	return 0;
}