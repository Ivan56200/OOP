/*1. Učitajte dva cijela broja a i b i ispišite njihov zbroj, aritmetičku sredinu i re-
zultat usporedbe a < b spremljen u varijablu tipa bool. Varijable inicijalizirajte
pomoću {}.*/

#include <iostream>

int main()
{
    int a{};
    int b{};
    std::cin >> a >> b;

    bool usporedba(a < b);

    std::cout << "Zbroj: " << a + b << std::endl;
    std::cout << "Aritmeticka sredina: " << (a + b) / 2.0 << std::endl;
    std::cout << "A manji od B: " << std::boolalpha << usporedba << std::endl;

    return 0;
}