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
bool RealMatrix::checkForComp(vector<vector<double>> &matrix1, vector<vector<double>> &matrix2)
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
RealMatrix RealMatrix::operator -(RealMatrix matrix)
{
	if (checkShape(this->matrix, matrix.matrix))
	{
		RealMatrix temp = RealMatrix(this->matrix.size(), this->matrix[0].size());
		for (int i = 0; i < this->matrix.size();i++)
		for (int j = 0; j < this->matrix[0].size(); i++)
			temp.matrix[i][j] = this->matrix[i][j] - matrix.matrix[i][j];
		return temp;
	}
	return *this;
}
void RealMatrix::operator -=(RealMatrix matrix)
{
	if (checkShape(this->matrix, matrix.matrix))
	{
		for (int i = 0; i < this->matrix.size(); i++)
		for (int j = 0; j < this->matrix[0].size(); i++)
			this->matrix[i][j] = this->matrix[i][j] - matrix.matrix[i][j];
	}
}
RealMatrix RealMatrix::operator-(int a)
{
	//1. опредилить возможность отнимать от матрицы число
	if (this->squareMatrix())
	{
		//2. создать единичную марицу умноженную на число
		RealMatrix eMatrix = createE(this->matrix.size()) * a;
		//3. отнять
		return (*this) - eMatrix;
	}
	return *this;
}
void RealMatrix::operator -=(int a)
{
	//1. опредилить возможность отнимать от матрицы число
	if (this->squareMatrix())
	{
		//2. создать единичную марицу умноженную на число
		RealMatrix eMatrix = createE(this->matrix.size()) * a;
		//3. отнять
		*this= *this - eMatrix;
	}
}
bool RealMatrix::checkShape(vector<vector<double>> &matrix1, vector<vector<double>> &matrix2)
{
	if ((matrix1.size() == matrix2.size()) && matrix1[0].size() == matrix2[0].size())
		return true;
	return false;
}
bool RealMatrix::squareMatrix()
{
	if (this->matrix.size() == this->matrix[0].size())
		return true;
	return false;
}
RealMatrix RealMatrix::operator +(RealMatrix matrix)
{
	if (checkShape(this->matrix, matrix.matrix))
	{
		RealMatrix temp = RealMatrix(this->matrix.size(), this->matrix[0].size());
		for (int i = 0; i < this->matrix.size(); i++)
		for (int j = 0; j < this->matrix[0].size(); i++)
			temp.matrix[i][j] = this->matrix[i][j] + matrix.matrix[i][j];
		return temp;
	}
	return *this;
}
void RealMatrix::operator +=(RealMatrix matrix)
{
	if (checkShape(this->matrix, matrix.matrix))
	{
		for (int i = 0; i < this->matrix.size(); i++)
		for (int j = 0; j < this->matrix[0].size(); i++)
			this->matrix[i][j] = this->matrix[i][j] + matrix.matrix[i][j];
	}
}
RealMatrix RealMatrix::operator+(int a)
{
	//1. опредилить возможность сложить матрицу и число
	if (this->squareMatrix())
	{
		//2. создать единичную марицу умноженную на число
		RealMatrix eMatrix = createE(this->matrix.size()) * a;
		//3. сложить
		return (*this) + eMatrix;
	}
	return *this;
}
void RealMatrix::operator +=(int a)
{
	//1.  опредилить возможность сложить матрицу и число
	if (this->squareMatrix())
	{
		//2. создать единичную марицу умноженную на число
		RealMatrix eMatrix = createE(this->matrix.size()) * a;
		//3. сложить
		*this = *this + eMatrix;
	}
}

//перегрузка оператора присваивания
RealMatrix& RealMatrix::operator =(RealMatrix& mat)
{
	for (int i = 0; i < matrix.size(); i++)
		matrix[i].clear();
	matrix.clear();
	matrix.resize(mat.matrix.size());
	for (int i = 0; i < matrix.size(); i++)
	{
		matrix[i].resize(mat.matrix[i].size());
		for (int j = 0; j < matrix[i].size(); j++)
			matrix[i][j] = mat.matrix[i][j];
	}
	return *this;
}

//перегрузка оператора /
RealMatrix RealMatrix::operator /(double x)
{
	for (int i = 0; i < matrix.size(); i++)
	for (int j = 0; j < matrix[i].size(); j++)
		matrix[i][j] /= x;
	return *this;
}

//перегрузка оператора /=
void RealMatrix::operator /=(double x)
{
	for (int i = 0; i < matrix.size(); i++)
	for (int j = 0; j < matrix[i].size(); j++)
		matrix[i][j] /= x;
}

//перегрузка оператора ^=
void RealMatrix::operator ^=(int n)
{
	//проверка на квадратность матрицы
	if (this->matrix.size() != this->matrix[0].size())
	{
		cout << "Matrix is not square";
		return;
	}
	vector <vector <double>> temp; //временная матрица temp
	temp.resize(matrix.size());
	int x = matrix[0].size();
	for (int i = 0; i < temp.size(); i++)
	{
		temp[i].resize(x);
		for (int j = 0; j < x; j++)
			temp[i][j] = matrix[i][j];
	}
	//возведение в степень n
	for (int i = 1; i < n; i++)
	{
		matrix = mult(matrix, temp);
	}
	for (int i = 0; i < temp.size(); i++)
		temp[i].clear();
	temp.clear();
}

//перегрузка оператора ^
RealMatrix RealMatrix::operator ^(int n)
{
	//проверка на квадратность матрицы
	if (this->matrix.size() != this->matrix[0].size())
	{
		cout << "Matrix is not square";
		return *this;
	}
	vector <vector <double>> temp; //временная матрица temp
	temp.resize(matrix.size());
	int x = matrix[0].size();
	for (int i = 0; i < temp.size(); i++)
	{
		temp[i].resize(x);
		for (int j = 0; j < x; j++)
			temp[i][j] = matrix[i][j];
	}
	//возведение в степень n
	for (int i = 1; i < n; i++)
	{
		matrix = mult(matrix, temp);
	}
	for (int i = 0; i < temp.size(); i++)
		temp[i].clear();
	temp.clear();
	return *this;
}

vector <vector <double>> RealMatrix::mult(vector<vector<double>> mat1, vector<vector<double>> mat2)
{
	vector <vector <double>> temp;
	if (checkForComp(mat1, mat2))
	{
		temp.resize(mat1.size());
		int x = mat2[0].size();
		for (int i = 0; i < mat1.size(); i++)
			temp[i].resize(x);
		//выбираем строку 1-ой матрицы
		for (int i = 0; i < mat1.size(); i++)
		{
			//выбираем столбец 2-ой матрицы
			for (int j = 0; j < x; j++)
			{
				temp[i][j] = 0;
				//перемножаем строку 1-ой матрицы и столбец 2-ой матрицы
				for (int z = 0; z < mat2.size(); z++)
					temp[i][j] = temp[i][j] + mat1[i][z] * mat2[z][j];
				//выбираем следущий столбец
			}
			//выбираем следующую стороку
		}
	}
	return temp;
}

/*bool RealMatrix::checkForComp(vector<vector<double>> &matrix1, vector<vector<double>> &matrix2)
{
	//проверка на равность кол-ва столбцов 1-ой мат-цы и кол-ва строк во 2-ой
	if (matrix1[0].size() == matrix2.size())
		return true;
	cout << " умножение невозможно" << endl;
	return false;
}*/

//вычисление детерминанта
int RealMatrix::det()
{
	//проверка на квадратность матрицы
	if (this->matrix.size() != this->matrix[0].size())
	{
		cout << "Matrix is not square";
		return NULL;
	}
	vector <vector <double>> temp;
	int x = matrix.size();
	temp.resize(x);
	for (int i = 0; i < x; i++)
	{
		temp[i].resize(matrix[i].size());
	}
	for (int i = 0; i < x; i++)
	for (int j = 0; j < temp[i].size(); j++)
		temp[i][j] = matrix[i][j];
	double a = 0;
	for (int i = 1; i < x; i++) //приведение матрицы к ступенчатому виду
	{
		for (int j = i; j < x; j++)
		{
			a = temp[j][i - 1] / temp[i - 1][i - 1];
			for (int k = i - 1; k < x; k++)
				temp[j][k] = temp[j][k] - temp[i - 1][k] * a;
		}
	}                           ////////////////////////////////////////
	int deter = 1;
	for (int i = 0; i < x; i++) //перемножение диоганальных эл-ов
	{
		deter *= temp[i][i];
	}
	for (int i = 0; i < x; i++)
	for (int j = 0; j < temp[i].size(); j++)
		temp[i].clear();
	temp.clear();
	return deter;
}