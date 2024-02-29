#pragma once
#include <iostream>

#include "../DenseMatrix/dence_matrix.h"
#include "../Vector/vector_matrix.h"

struct QRDecomposition {
    Matrix Q;
    Matrix R;
};

vector<double> MakeBasisVector(const int &number_basis_column, const int &number_elements);
vector<double> FindNormal(const vector<double> &matrix_column, const int &number_column,
                          const int &number_elements);
vector<double> ConvertsMatrixColumn(const vector<double> &matrix_column,
                                    const vector<double> &normal, const double &denominator);
Matrix MultiplyColumnRow(const vector<double> &column, const vector<double> &row);
Matrix MakeTransformationMatrix(const vector<float> &normal);
vector<double> ConvertsMatrixColumnOrRow(const vector<double> &matrix_column,
                                         const vector<double> &normal, const double &denominator);
void TransformUpperDiagonalMatrix(Matrix &matrix, const int &number_transformation,
                                  const vector<double> &normal, const double &denominator);
void TransformOrthogonalMatrix(Matrix &matrix, const int &number_transformation,
                               const vector<double> &normal, const double &denominator);
QRDecomposition HouseholderAlgorithm(const Matrix &original_matrix);