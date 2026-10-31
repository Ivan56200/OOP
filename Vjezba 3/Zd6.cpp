/*Napišite funkciju std::vector<std::string> split_words (const std::string& text) koja rečenicu dijeli na riječi (find, substr). 
Riječi mogu biti odvojene s više razmaka. Za rečenicu koju korisnik unese ispišite:
  o broj riječi i najdulju riječ,
  o riječi obrnutim redoslijedom, spojene znakom - u jedan string (+=),
  o riječ koja je prva po abecedi (operator <).

banana Zebra auto Mrkva kiwi
broj rijeci: 5
najdulja: banana
kiwi-Mrkva-auto-Zebra-banana 
prva po abecedi: Mrkva*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> split_words(const std::string& text){
    std::vector<std::string> rijeci;
    int pocetak = 0;

    while (pocetak < text.length()){
        int kraj = text.find(' ', pocetak);

        if (kraj == -1){
            rijeci.push_back(text.substr(pocetak));
            break;
        }

        if (kraj > pocetak){
            rijeci.push_back(text.substr(pocetak, kraj - pocetak));
        }
        pocetak = kraj + 1;
    }

    return rijeci;
}

int main(){
    std::string recenica = "banana Zebra auto Mrkva kiwi";

    std::vector<std::string> rijeci = split_words(recenica);

    std::cout << "Broj rijeci: " << rijeci.size() << std::endl;

    std::string najduza = rijeci[0];
    for (int i = 1; i < rijeci.size(); i++){
        if (rijeci[i].length() > najduza.length())
            najduza = rijeci[i];
    }
    std::cout << "Najdulja rijec: " << najduza << std::endl;

    std::string obrnuto = "";
    for (int i = rijeci.size() - 1; i >= 0; i--){
        obrnuto += rijeci[i];

        if (i != 0)
            obrnuto += "-";
    }
    std::cout << "Obrnuti redoslijed: " << obrnuto << std::endl;

    std::string prva = rijeci[0];
    for (int i = 1; i < rijeci.size(); i++){
        if (rijeci[i] < prva)
            prva = rijeci[i];
    }
    std::cout << "Prva po abecedi: " << prva << std::endl;

    return 0;
}



//DRUGI NACIN
/*
std::vector<std::string> split_words(const std::string& text){
	std::vector<std::string> rijeci;

	auto pocetak = std::find_if(text.begin(), text.end(),
		[](unsigned char c) { return std::isalpha(c); });

	while (pocetak != text.end()){
		auto kraj = std::find(pocetak, text.end(), ' ');
		rijeci.emplace_back(pocetak, kraj);

		if (kraj == text.end())
			break;

		pocetak = std::find_if(kraj + 1, text.end(),
			[](unsigned char c) { return std::isalpha(c); });
	}

	return rijeci;
}*/
