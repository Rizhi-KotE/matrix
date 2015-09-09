#include "stdafx.h"
#include "RealMatrix.h"


RealMatrix::RealMatrix(int whidth, int height )
{
	for (int i = 0; i < height; i++)
	{
		vector<double> temp(whidth);
		this->matrix.push_back(temp);
	}
}
RealMatrix::RealMatrix()
{
	int whidth = 0;
	int height = 0;
	for (int i = 0; i < height; i++)
	{
		vector<double> temp(whidth);
		this->matrix.push_back(temp);
	}
}
//принимает параметр - имя текстового файла с матрицей
RealMatrix::RealMatrix(string name)
{
	ifstream In;
	In.open(name, ios::in);
	bool incorrect = false;
	while (!In.eof()){
		string s;
		getline(In, s);
		string sNumber;
		stringstream ss(s);
		
		
		
		vector<double> temp;
		while (!ss.eof())
		{
			double a;
			ss >> a;
			temp.push_back(a);
		}
		ss.clear();
		this->matrix.push_back(temp);		
		if (!(this->matrix[0].size() == temp.size()))
		{
			cout << "Некоректная матрица" << endl;
			incorrect = true;
		}
	}
	if (incorrect == true)
	{
		this->adjusmentMatrix();
	}
	
}
//выводит на монитор матрицу
void RealMatrix::printMatrix()
{
	for (size_t i = 0; i < this->matrix.size(); i++)
	{
		for (size_t j = 0; j < this->matrix[i].size(); j++)
			cout << setw(5) << this->matrix[i][j];
		cout << endl;
	}
}
RealMatrix::~RealMatrix()
{
	for (int i = 0; i < this->matrix.size(); i++)
		this->matrix[i].clear();
}
//перегрузка оператора. перемножает 2 матрицы
RealMatrix RealMatrix::operator *(RealMatrix matrix)
{
	
	if (checkForComp(this->matrix, matrix.matrix))
	{
		RealMatrix m = RealMatrix(this->matrix.size(), matrix.matrix[0].size());
		//выбираем строку 1-ой
		for (int i = 0; i < this->matrix.size(); i++)
		{
			//выбираем столбец 2-ой матрицы
			for (int j = 0; j < matrix.matrix[0].size(); j++)
			{
				//перемножаем строку 1-ой матрицы и столбец 2-ой матрицы
				for (int z = 0; z < this->matrix[0].size(); z++)
					m.matrix[i][j] += this->matrix[i][z] * matrix.matrix[z][j];
				//выбираем следущий столбец
			}
			//выбираем следующую стороку
		}
		this->matrix[1] = matrix.matrix[1];
		return m;
	}
	return *this;
}
void RealMatrix::operator *=(RealMatrix matrix)
{

	if (checkForComp(this->matrix, matrix.matrix))
	{
		RealMatrix m = RealMatrix(this->matrix.size(), matrix.matrix[0].size());
		//выбираем строку 1-ой
		for (int i = 0; i < this->matrix.size(); i++)
		{
			//выбираем столбец 2-ой матрицы
			for (int j = 0; j < matrix.matrix[0].size(); j++)
			{
				//перемножаем строку 1-ой матрицы и столбец 2-ой матрицы
				for (int z = 0; z < this->matrix[0].size(); z++)
					m.matrix[i][j] += this->matrix[i][z] * matrix.matrix[z][j];
				//выбираем следущий столбец
			}
			//выбираем следующую стороку
		}
		//this->matrix[1] = matrix.matrix[1];
		this->matrix = m.matrix;
	}
	
}
//ровняет длину строк матрицы по максимальной
void RealMatrix::adjusmentMatrix()
{
	size_t max = this->matrix[0].size();
	for (int i = 1; i < this->matrix.size(); i++)
		if (max < this->matrix[i].size())
			max = this->matrix[i].size();
		for (int i = 0; i < this->matrix.size(); i++)
			this->matrix[i].resize(max);		
}
//проверяет возможность перемножения матриц
bool RealMatrix::checkForComp(vector<vector<double>> matrix1, vector<vector<double>> matrix2)
{
	//проверка на равность кол-ва столбцов 1-ой мат-цы и кол-ва строк во 2-ой
	if (matrix1[0].size() == matrix2.size())
		return true;
	cout << " умножение невозможно" << endl;
	return false;
}
RealMatrix operator *(int a, RealMatrix matrix)
{
	return matrix*a;
}
RealMatrix RealMatrix::createE(int a)
{
	RealMatrix matrix = RealMatrix(a, a);
	for (int i = 0; i < a; i++)
		matrix.matrix[i][i] = 1;
	return matrix;
}
RealMatrix RealMatrix::operator *(int a)
{
	for (int i = 0; i < this->matrix.size();i++)
	for (int j = 0; j < this->matrix[i].size(); j++)
		this->matrix[i][j] *= a;
	return *this;
}
void RealMatrix::operator *=(int a)
{
	for (int i = 0; i < this->matrix.size(); i++)
	for (int j = 0; j < this->matrix[i].size(); j++)
		this->matrix[i][j] *= a;
}
