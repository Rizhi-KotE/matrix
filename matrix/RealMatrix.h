#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

class RealMatrix
{
private:
	vector < vector <double> > matrix;

public:
	RealMatrix();
	RealMatrix(int ,int );
	RealMatrix(string );//Считывает матрицу из файла. Принимает строку-адрес файла
	void printMatrix();
	~RealMatrix();
};

