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
	bool bad = false;
public:
	RealMatrix();
	RealMatrix(int ,int );
	RealMatrix(string );//Считывает матрицу из файла. Принимает строку-адрес файла
	void printMatrix();
	RealMatrix operator *(RealMatrix );
	void operator *= (RealMatrix );
	RealMatrix createE(int);
	RealMatrix operator *(int );
	void operator *=(int );
	~RealMatrix();
private:
	bool checkForComp(vector<vector<double>>, vector<vector<double>> );
	void adjusmentMatrix();//некорректную матрицу добивает нулями
};

RealMatrix operator *(int a, RealMatrix matrix);
