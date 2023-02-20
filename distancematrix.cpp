#include "clases.hpp"

DistanceMatrix::DistanceMatrix(std::vector<City *> *cities)
{
    rows_ = cities->size();
    col_ = cities->size();
    try
    {
        matrix_ = new double *[rows_];
    }
    catch (std::bad_alloc &b)
    {
        delete[] matrix_;
        matrix_ = NULL;
    }

    for (size_t i = 0; i < rows_; i++)
    {
        try
        {
            matrix_[i] = new double[col_];
        }
        catch (std::bad_alloc &b)
        {
            for (size_t j = 0; j < i; j++)
            {
                delete[] matrix_[j];
            }
            delete[] matrix_;
            matrix_ = NULL;
        }
    }

    if (matrix_ != NULL)
    {
        for (size_t i = 0; i < cities->size(); i++)
        {
            for (size_t j = 0; j < cities->size(); j++)
            {
                if (i == j)
                {
                    matrix_[i][j] = 0;
                }
                else
                {
                    matrix_[i][j] = sqrt(pow(abs((cities->at(i)->GetX()) - (cities->at(j)->GetX())), 2) + pow(abs((cities->at(i)->GetY()) - (cities->at(j)->GetY())), 2));
                }
            }
        }
    }
}

DistanceMatrix::~DistanceMatrix()
{
    for (size_t i = 0; i < rows_; i++)
    {
        delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = NULL;
}

double **DistanceMatrix::GetDistanceMatrix() const
{
    return matrix_;
}
size_t DistanceMatrix::GetRows() const
{
    return rows_;
}
size_t DistanceMatrix::GetCol() const
{
    return col_;
}
void DistanceMatrix::SetRows(size_t r)
{
    rows_ = r;
}
void DistanceMatrix::SetCol(size_t c)
{
    col_ = c;
}