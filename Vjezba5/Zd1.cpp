/*Napišite klasu Volume koja predstavlja glasnoću zvuka. Glasnoća je cijeli broj od 0 do 100 i to je invarijanta klase.
 1. Konstruktor Volume(int l) vrijednost izvan raspona svodi na najbližu granicu (-20 postaje 0, 130 postaje 100).
 2. Default konstruktor postavlja glasnoću na 50 delegiranjem na prvi konstruktor.
 3. Napišite pomoćnu static funkciju koja ograničava vrijednost na 0–100.
 4. Metode up(int step = 10) i down(int step = 10) mijenjaju glasnoću, ali nikad izvan raspona.
 5. mute() postavlja glasnoću na 0, a unmute() vraća glasnoću na vrijednost prije mute ().
 6. Napišite privatnu metodu bool valid() const i provjerite invarijantu s assert na kraju svake metode koja mijenja glasnoću.
Program za testiranje je u datoteci volume_main.cpp (očekivani ispis je na dnu datoteke)*/

// Vjezba 5, zadatak 1: napisite klasu Volume iznad main.

#include <cassert>
#include <iostream>

// ovdje napisite klasu Volume
class Volume {
private:
    int glasnoca;
    int prijeMute;

    static int limit(int g) {   //3
        if (g < 0) return 0;
        if (g > 100) return 100;
        return g;
    }

    bool valid() const {        //6
        return glasnoca >= 0 && glasnoca <= 100;
    }

public:
    Volume(int g){
        glasnoca = limit(g);
        prijeMute = glasnoca;
        assert(valid());
    }

    Volume() : Volume(50) {} //2

    void up(int step = 10) {    //4
        glasnoca = limit(glasnoca + step);
        assert(valid());
    }

    void down(int step = 10) {
        glasnoca = limit(glasnoca - step);
        assert(valid());
    }

    void mute() {   //5
        prijeMute = glasnoca;
        glasnoca = 0;
        assert(valid());

    }

    void unmute() {
        glasnoca = prijeMute;
        assert(valid());
    }

    int get() const {
        return glasnoca;
    }
};

int main()
{
    Volume v;
    std::cout << v.get() << '\n';
    v.up();
    v.up(60);
    std::cout << v.get() << '\n';
    v.mute();
    std::cout << v.get() << '\n';
    v.unmute();
    std::cout << v.get() << '\n';
    Volume w(-20);
    w.down();
    std::cout << w.get() << '\n';
    return 0;
}


/*Ocekivani ispis:

    50
    100
    0
    100
    0
*/
