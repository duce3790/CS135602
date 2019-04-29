#include "function.h"

Matrix Matrix::operator*(const Matrix &a) const
{
    Matrix ans(this->size_row, a.size_col);
    for (int row = 0; row < this->size_row; ++row){
        for (int col = 0; col < a.size_col; ++col){
            ans.arr[row][col] = 0;
            for (int k = 0; k < this->size_col; ++k){
                ans.arr[row][col] += this->arr[row][k] * a.arr[k][col];
            }
        }
    }
    return ans;
}
Matrix Matrix::operator=(const Matrix &a)
{
    size_row =  a.size_row;
    size_col =  a.size_col;
    arr = a.arr;
    return *this;
}
Matrix MatrixChain::calc(int l, int r) const
{
    Matrix ans = *arr[l];
    for(int i=l+1; i<r; i++){
        ans = ans * (*arr[i]);
    }
    return ans;
}
