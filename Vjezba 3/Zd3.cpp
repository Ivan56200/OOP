/*Broj dana u tjednu zadajte kao constexpr int DAYS = 7;. Sati učenja po danima čuvaju se u std::array<double, DAYS>.
• Napišite funkciju double total (const std:: array<double, DAYS>& hours) koja vraća ukupan broj sati u tjednu.
• Napišite funkciju int best_day (const std::array<double, DAYS>& hours) koja vraća redni broj dana (od 1) s najviše sati učenja.
• Za prvi tjedan korisnik unosi sate za svaki dan. Pomoću funkcija ispišite ukupan broj sati i dan s najviše sati učenja.
• Drugi tjedan popunite s fill (1.5). Usporedite tjedne operatorima == i <, zamjenite ih sa swap i ponovno ispišite ukupne sate.*/

#include <iostream>
#include <array>

constexpr int DAYS = 7;

double total(const std::array<double, DAYS>& hours) {
    double zbroj = 0;
    
    for (double i : hours) {
        zbroj += i;
    }

    return zbroj;
}

int best_day(const std::array<double, DAYS>& hours) {
    int index = 0;

    for (int i = 1; i < DAYS; i++) {
        if (hours[i] > hours[index]) {
            index = i;
        }
    }

    return index + 1;
}

int main() {
    std::array<double, DAYS> tj1;
    std::array<double, DAYS> tj2;

    std::cout << "Sati u prvom tjednu: ";

    for (int i = 0; i < DAYS; i++) {
         std::cin >> tj1[i];
    }

    std::cout << "\nPrvi tjedan, ukupno sati: " << total(tj1) << std::endl;
    std::cout << "Prvi tjedan, dan s najvise sati: " << best_day(tj1) << std::endl;


    tj2.fill(1.5);
    if (tj1 == tj2)
        std::cout << "Jednaki tjedni" << std::endl;
    else
        std::cout << "Nejednaki tjedni" << std::endl;
    if (tj1 < tj2)
        std::cout << "Prvi tjedan manji" << std::endl;
    else
        std::cout << "Drugi tjedan manji" << std::endl;


    tj1.swap(tj2);
    std::cout << "Ukupno sati u prvom: " << total(tj1) << std::endl;
    std::cout << "Ukupno sati u drugom: " << total(tj2) << std::endl;

    return 0;
}