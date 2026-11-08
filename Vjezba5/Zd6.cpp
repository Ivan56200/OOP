/*Napišite klasu Coin (novčić u igri) s vrijednošću i statičkim brojačem novčića koji trenutno postoje. Novčić postoji dok ga igrač ne pokupi.
◦ Konstruktor povećava brojač, a destruktor ga smanjuje.
◦ Statička metoda remaining() vraća broj novčića koji trenutno postoje.
Za razliku od Ticket, koji broji koliko je ulaznica izdano, ovdje se broje novčići koji još postoje. Program za testiranje je u datoteci coin_main.cpp
(očekivani ispis je na dnu datoteke).*/

// Vjezba 5, zadatak 6: napisite klasu Coin iznad funkcije bonus.

#include <iostream>

// ovdje napisite klasu Coin
class Coin {
    int vrijednost;
    static int kolicina;

public:
    Coin(int v) : vrijednost(v) {
        kolicina++;
    }

    ~Coin() {
        kolicina--;
    }

    static int remaining(){
        return kolicina;
    }
};

int Coin::kolicina = 0;

void bonus()               // bonus runda: tri novcica
{
    Coin c1(5);
    Coin c2(5);
    Coin c3(10);
    std::cout << Coin::remaining() << '\n';
}

int main()
{
    std::cout << Coin::remaining() << '\n';
    Coin gold(50);
    {
        Coin a(1);
        Coin b(1);
        std::cout << Coin::remaining() << '\n';
    }
    std::cout << Coin::remaining() << '\n';
    bonus();
    std::cout << Coin::remaining() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    0
    3
    1
    4
    1
*/
