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
	vector <vector <double>> mult(vector <vector <double>>, vector <vector <double>>);
public:
	RealMatrix(int width = 0,int height = 0 );//������� ������ ������� �������� width*height
	RealMatrix(string );//��������� ������� �� �����. ��������� ������-����� �����
	void printMatrix();//�������� �������
	RealMatrix operator *(RealMatrix );//�������� ������� �� �������
	void operator *= (RealMatrix );//�������� ������� �� �������
	RealMatrix operator *(int );//�������� ������� �� �����
	void operator *=(int );//�������� ������� �� �����
	RealMatrix operator -(RealMatrix);//�������� �� ������� �������
	void operator -=(RealMatrix);//�������� �� ������� �������
	RealMatrix operator -(int);//�������� �� ������� �����
	void operator -=(int);//�������� �� ������� �����
	RealMatrix createE(int );//������� ��������� �������
	RealMatrix operator +(RealMatrix);//����� ������
	void operator +=(RealMatrix);//����� ������
	RealMatrix operator +(int);//���������� ����� � �������
	void operator +=(int);//���������� ����� � �������
	RealMatrix& operator = (RealMatrix&);//���������� ��������� ������������
	RealMatrix operator /(double);//������� ������� �� �����	
	void operator /=(double);//������� ������� �� �����
	void operator ^=(int);//���������� ������� � �������
	RealMatrix operator ^(int);//���������� ������� � �������
	int det();
	~RealMatrix();
private:
	bool checkForComp(vector<vector<double>> &, vector<vector<double>> &);
	void adjusmentMatrix();//������������ ������� �������� ������
	bool checkShape(vector<vector<double>> &, vector<vector<double>> &);
	bool squareMatrix();
};

RealMatrix operator *(int a, RealMatrix matrix);//�������� ����� �� �������
RealMatrix operator -(int a, RealMatrix matrix);//�������� �� ����� �������
RealMatrix operator +(int a, RealMatrix matrix); // ���������� ����� � �������