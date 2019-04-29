#include <iostream>
#include <stdio.h>
#include <string>
#include"function.h"

using namespace std;

Polynomial::Polynomial(){
    for (int i = 0; i < 101; ++i) coefficients[i] = 0;
    greatestPower = 0;
}
Polynomial::Polynomial (const int pow, const int coef[51]){
    greatestPower = pow;
    for (int i = 0; i <= pow; ++i)
        coefficients[i] = coef[i];
    for (int i = greatestPower + 1 ; i < 101; ++i)
        coefficients[i] = 0;
}
Polynomial Polynomial::add (const Polynomial b)const{
    int a_pow = this->greatestPower;
    int b_pow = b.greatestPower;
    int power = max(a_pow,b_pow);
    //cout << "add " <<endl;
    Polynomial added(power,this->coefficients);
    while (a_pow >= 0 && b_pow >= 0){
        if (a_pow == b_pow){
            added.coefficients[power--] += b.coefficients[b_pow--];
            --a_pow;
        }
        else if (a_pow < b_pow){
            added.coefficients[power--] += b.coefficients[b_pow--];
        }
        else if (a_pow > b_pow){
            --a_pow;
        }
    }

    return added;
}
Polynomial Polynomial::subtract (const Polynomial b) const{
    int a_pow = this->greatestPower;
    int b_pow = b.greatestPower;
    int power = max(a_pow,b_pow);
    //cout << "sub " <<endl;
    Polynomial subed(power,this->coefficients);
    while (a_pow >= 0 && b_pow >= 0){
        if (a_pow == b_pow){
            subed.coefficients[power--] -= b.coefficients[b_pow--];
            --a_pow;
        }
        else if (a_pow < b_pow){
            subed.coefficients[power--] -= b.coefficients[b_pow--];
        }
        else if (a_pow > b_pow){
            --a_pow;
        }
    }
    return subed;
}
Polynomial Polynomial::multiplication (const Polynomial b) const{
    int a_pow = this->greatestPower;
    int b_pow = b.greatestPower;
    int index = a_pow + b_pow;
    //cout << "mul " <<endl;
    Polynomial muled;
    muled.greatestPower = index;

    for (int i = a_pow; i >= 0; --i)
        for (int j = b_pow; j >= 0; --j)
            muled.coefficients[i + j] += this->coefficients[i] * b.coefficients[j];

    return muled;
}
void Polynomial::output()const{
    for (int i = greatestPower; i >= 0; --i)
        cout << coefficients[i] << (i>0?" ":"");
}
