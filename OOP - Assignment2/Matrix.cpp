#include <iostream>
#include "Matrix.h"
#include <cstdlib>
#include <time.h>

using namespace std;

Matrix::Matrix(const int Rows, const int Cols)
{
	if (!Rows || !Cols)
		return;

	arr = new int*[Rows];
	this->Rows = Rows;
	this->Cols = Cols;
	for (int i = 0; i < Rows; i++)
	{
		arr[i] = new int[Cols];
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix &m)
{
	this->arr = new int*[m.Rows];


	for (int i = 0; i < m.Rows; i++)
	{
		this->arr[i] = new int[m.Cols];
		for (int j = 0; j < m.Cols; j++)
		{
			this->arr[i][j] = m[i][j];
		}
	}
	this->Rows = m.Rows;
	this->Cols = m.Cols;

}

Matrix::~Matrix()
{
	for (int i = 0; i < this->Rows; i++)
	{
		delete[] this->arr[i];
	}
	delete[] arr;
}

int Matrix::getByXY(const int i, const int j) const
{
	return this->arr[i][j];
}

void Matrix::setByXY(const int i,const int j,const int value)
{
	this->arr[i][j] = value;
}

int* Matrix::operator [] (int Row) const 
{
	return this->arr[Row];
}

std::ostream& operator << (std::ostream& out,const Matrix& m)
{
	for (int i = 0; i < m.Rows; i++)
	{
		for (int j = 0; j < m.Cols; j++)
		{
			out << m[i][j] << " ";
		}
		out << endl;
	}
	return out;
}


void Matrix::operator = (const Matrix &m) 
{
	if (m.Rows != this->Rows || m.Cols != this->Cols)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < this->Cols; j++)
			{
				this->arr[i][j] = 0;
			}
			
		}
		return;
	}
	else if (this == &m)
	{
		return;
	}

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < this->Cols; j++)
		{
			this->arr[i][j] = m[i][j];
		}
	}
}

Matrix Matrix::operator - () const
{
	Matrix M(*this);
	
	for (int i = 0; i < M.Rows; i++)
	{
		for (int j = 0; j < M.Cols; j++)
		{
			M[i][j] = (*this).arr[i][j] * (-1);
		}
	}

	return M;
}

Matrix Matrix::operator * (const int& scalar) const
{
	return scalar * (*this);
}

Matrix operator * (const int& scalar, const Matrix& m)
{
	Matrix result = m;
	for (int i = 0; i <m.Rows; i++)
	{
		for (int j = 0; j < m.Cols; j++)
		{
			result[i][j] *= scalar;
		}
	}

	return result;

}

Matrix Matrix::operator + (const Matrix &m) const
{
	Matrix result = (*this);

	for (int i = 0; i < m.Rows; i++)
	{
		for (int j = 0; j < m.Cols; j++)
		{
			result[i][j] += m[j][i];
		}
	}

	return result;
}

Matrix Matrix::operator - (const Matrix &m) const
{
	Matrix result = (*this);

	for (int i = 0; i < m.Rows; i++)
	{
		for (int j = 0; j < m.Cols; j++)
		{
			result[i][j] -= m[j][i];
		}
	}

	return result;
}

Matrix Matrix::operator * (const Matrix &m) const
{
	Matrix result(m.Rows, m.Rows);

	for (int i = 0; i < this->Rows; i++)
	{
		for (int j = 0; j < this->Cols; j++)
		{
			for (int k = 0; k < m.Cols; k++)
			{
				result[i][j] += (*this)[i][k] * m[k][j];
			}
		}
	}

	return result;
}