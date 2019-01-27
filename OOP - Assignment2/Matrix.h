#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
private:
	int Rows;
	int Cols;
	int **arr;
public:
	Matrix(const int, const int);
	Matrix(const Matrix &m);
	~Matrix();
	int getByXY(const int,const int) const;
	void setByXY(const int,const int,const int);
	int* operator [] (const int a) const;
	void operator = (const Matrix&);
	Matrix operator * (const int& scalar) const;
	friend Matrix operator * (const int& scalar, const Matrix&);
	Matrix operator + (const Matrix &m) const;
	Matrix operator - () const;
	Matrix operator - (const Matrix &m) const;
	Matrix operator * (const Matrix &m) const;
	friend std::ostream& operator << (std::ostream& out, const Matrix& m);
};



#endif