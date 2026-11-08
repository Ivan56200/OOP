/*Napišite klasu Volume koja predstavlja glasnoću zvuka. Glasnoća je cijeli broj od 0 do 100 i to je invarijanta klase.
◦ Konstruktor Volume(int l) vrijednost izvan raspona svodi na najbližu granicu (-20 postaje 0, 130 postaje 100).
◦ Default konstruktor postavlja glasnoću na 50 delegiranjem na prvi konstruktor.
◦ Napišite pomoćnu static funkciju koja ograničava vrijednost na 0–100.
◦ Metode up(int step = 10) i down(int step = 10) mijenjaju glasnoću, ali nikad izvan raspona.
◦ mute() postavlja glasnoću na 0, a unmute() vraća glasnoću na vrijednost prije mute().
◦ Napišite privatnu metodu bool valid() const i provjerite invarijantu s assert na kraju svake metode koja mijenja glasnoću.
Program za testiranje je u datoteci volume_main.cpp (očekivani ispis je na dnu datoteke).*/

// Vjezba 5, zadatak 1: napisite klasu Volume iznad main.

#include <cassert>
#include <iostream>

// ovdje napisite klasu Volume
class Volume {
private:
    int v;
    int prijeMute;

    static int limit(long value)    {
        if (value < 0) { return 0; }
        if (value > 100) { return 100; }

        return static_cast<int>(value);
    }

    bool valid() const { return v >= 0 && v <= 100; }

public:
    Volume(int l) : v(limit(l)), prijeMute(v) {
        assert(valid());
    }

    Volume() : Volume(50) {}

    int get() const { return v; }

    void up(int step = 10){
        v = limit(static_cast<int>(v)+step);
        assert(valid());
    }

    void down(int step = 10){
        v = limit(static_cast<int>(v)-step);
        assert(valid());
    }

    void mute() {
        if (v != 0) {
            prijeMute = v;
            v = 0;
        }

        assert(valid());
    }

    void unmute(){
        v = prijeMute;
        assert(valid());
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

/*
Ocekivani ispis:

    50
    100
    0
    100
    0
*/

