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
	RealMatrix(int width = 0,int height = 0 );//создает пустую матрицу размером width*height
	RealMatrix(string );//Считывает матрицу из файла. Принимает строку-адрес файла
	void printMatrix();//печатает матрицу
	RealMatrix operator *(RealMatrix );//умножает матрицу на матрицу
	void operator *= (RealMatrix );//умножает матрицу на матрицу
	RealMatrix operator *(int );//умножает матрицу на число
	void operator *=(int );//умножает матрицу на число
	RealMatrix operator -(RealMatrix);//отнимает от матрицы матрицу
	void operator -=(RealMatrix);//отнимает от матрицы матрицу
	RealMatrix operator -(int);//отнимает от матрицы число
	void operator -=(int);//отнимает от матрицы число
	RealMatrix createE(int );//создает единичную матрицу
	RealMatrix operator +(RealMatrix);//сумма матриц
	void operator +=(RealMatrix);//сумма матриц
	RealMatrix operator +(int);//складывает число и матрицу
	void operator +=(int);//складывает число и матрицу
	~RealMatrix();
private:
	bool checkForComp(vector<vector<double>> &, vector<vector<double>> &);
	void adjusmentMatrix();//некорректную матрицу добивает нулями
	bool checkShape(vector<vector<double>> &, vector<vector<double>> &);
	bool squareMatrix();
};

RealMatrix operator *(int a, RealMatrix matrix);//умножает число на матрицу
RealMatrix operator -(int a, RealMatrix matrix);//отнимает от числа матрицу
RealMatrix operator +(int a, RealMatrix matrix); // складывает число и матрицу