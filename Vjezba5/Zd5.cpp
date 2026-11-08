/*Napišite klasu Ticket (ulaznica za koncert) s nazivom koncerta i jedinstvenim brojem.
◦ Broj se dodjeljuje automatski u konstruktoru: prva ulaznica ima broj 1, sljedeća 2, itd. Koristite statički član (definicija izvan klase).
◦ Statička metoda issued() vraća broj dosad izdanih ulaznica.
Program za testiranje je u datoteci ticket_main.cpp (očekivani ispis je na dnu datoteke).*/

// Vjezba 5, zadatak 5: napisite klasu Ticket iznad main.

#include <iostream>
#include <string>

// ovdje napisite klasu Ticket
class Ticket {
    std::string koncert;
    int id;
    static int counter;

public:
    Ticket(std::string k): koncert(k), id(++counter){}

    int get_id() const { 
        return id;
    }
    
    static int issued() { 
        return counter; 
    }
};

int Ticket::counter = 0;

int main()
{
    std::cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");
    std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
    std::cout << Ticket::issued() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    0
    1 2 3
    3
*/
