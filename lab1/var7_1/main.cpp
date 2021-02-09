#include <iostream>
#include <cmath>
#include <string>
//
// Варіант 7. Створити клас для виконання операцій з комплексними числами.+
// Передбачити операції: складання та віднімання;+
// множення та ділення;+
// обчислення модулю;+
// консольне введення та виведення;+
// ініціалізацію. (данные по умолчанию)+
//
using namespace std;

class Complex
{
    private:
        string name;
        double real, imag;
    public:
        Complex(double real = 0.0, double imag = 0.0, string name = "noname")
        {
            this->real = real;
            this->imag = imag;
            this->name = name;
        }
        ~Complex()
        {
            cout << name << "---DESTRUCTOR---real="<< real << "---imag=" << imag << "----" << endl;
        }
        Complex add(Complex& b);
        Complex sub(Complex& b);
        Complex mult(Complex& b);
        Complex div(Complex& b);
        double Module();
        void ReadFromConsole();
        void PrintToConsole();

};
//(a + bi) ± (c + di) = (a ± c) + (b ± d)i
Complex Complex::add(Complex& b)
{
    Complex temp;
    temp.name = "add";
    temp.real = this->real + b.real;
    temp.imag = this->imag + b.imag;
    return temp;
}
//(a + bi) ± (c + di) = (a ± c) + (b ± d)i
Complex Complex::sub(Complex& b)
{
    Complex temp;
    temp.name = "sub";
    temp.real = this->real - b.real;
    temp.imag = this->imag - b.imag;
    return temp;
}
//(a + bi) · (c + di) = (ac – bd) + (ad + bc)i
Complex Complex::mult(Complex& b)
{
    Complex temp;
    temp.name = "mult";
    //                  a  * c               b  *  d
    temp.real = (this->real*b.real) - (this->imag*b.imag);
    //                   a * d             b * c
    temp.imag = (this->real*b.imag) + (this->imag*b.real);
    return temp;
}

Complex Complex::div(Complex& b)
{
    Complex temp;
    temp.name = "div";
    //                   a*c                  b*d
    temp.real = (this->real*b.real + this->imag*b.imag)
                / // c*c             d*d
                (b.real*b.real+b.imag*b.imag);
    //                   b*c                 a*d
    temp.imag = (this->imag*b.real - this->real*b.imag)
                / // c*c             d*d
                (b.real*b.real+b.imag*b.imag);
    return temp;
}

double Complex::Module()
{
    return sqrt(this->real*this->real + this->imag*this->imag);
}

void Complex::ReadFromConsole()
{
    cout << "Enter real:";
    cin >> this->real;
    cout << "Enter imagine:";
    cin >> this->imag;
    cout << "Enter name: ";
    cin >> this->name;
}

void Complex::PrintToConsole()
{
    cout << this->name << "  Real=" << this->real << " Imagine= " << this->imag << endl;
}

int main()
{
    Complex num1;
    Complex num2(5,6,"num2");
    num1.PrintToConsole();
    num2.PrintToConsole();

    num1.ReadFromConsole();
    num1.PrintToConsole();

    num2.ReadFromConsole();
    num2.PrintToConsole();

    Complex add = num1.add(num2);
    add.PrintToConsole();

    Complex sub = num1.sub(num2);
    sub.PrintToConsole();

    Complex mult = num1.mult(num2);
    mult.PrintToConsole();

    Complex div = num1.div(num2);
    div.PrintToConsole();

    double module = num1.Module();
    cout << "Module(num1) = " << module << endl;
    return  0;
}
