#include "function.h"

const int Vector::operator[](int index) const
{
    if (index >= v_size);
    else  return v[index];
}

int Vector::operator*(const Vector& a)
{
    int ans = 0;
    if (v_size != a.v_size);
    else {
        for (int i = 0; i < v_size; ++i) {
            ans += *(this->v+i) * *(a.v+i);
        }
        return ans;
    }
}
