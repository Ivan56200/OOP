/*Definirajte strukturu Fraction (razlomak) s članovima numerator i denominator te
metodama:
◦ void reduce() — skraćuje razlomak (koristite najveći zajednički djelitelj),
◦ double value() — vraća decimalnu vrijednost,
◦ void print() — ispisuje razlomak u obliku 3/4.
Napišite i globalnu funkciju Fraction sum(const Fraction& a, const Fraction& b) koja
vraća skraćeni zbroj.*/

#include <iostream>

struct Fraction {
    int numerator;
    int denominator;

    void reduce() {      
        int najDjelitelj{};
        int manjiBr = (numerator < denominator) ? numerator : denominator;

        for (int i = 1; i < manjiBr; i++) {
            if (numerator % i == 0 && denominator % i == 0) { najDjelitelj = i; }
        }

        numerator = numerator / najDjelitelj;
        denominator = denominator / najDjelitelj;
    }

    double value() {
        return (double)numerator / denominator;
    }

    void print() {
        std::cout << numerator << "/" << denominator;
    }
};

Fraction sum(const Fraction& a, const Fraction& b) {
    Fraction r;
    r.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    r.denominator = a.denominator * b.denominator;
    r.reduce();
    return r;
}

int main() {
    Fraction a;
    a.numerator = 2;
    a.denominator = 3;

    Fraction b;
    b.numerator = 6;
    b.denominator = 7;

    a.print();
    std::cout << " + ";
    b.print();
    std::cout << " = ";

    Fraction rez = sum(a, b);
    rez.print();
    std::cout << std::endl;

    std::cout << "Decimalno: " << rez.value() << std::endl;

    return 0;
}