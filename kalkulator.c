/**
* Program "wielomian":
*
* - czyta wielomian (do 10 stopnia włącznie)
*
* - wykonuje operacje sumy i iloczynu na wielomianie przechowywanym w akumulatorze (początkowo zerowym) oraz wielomianie podanym na wejściu - argumencie
*
* - pisze wynik operacji na wyjściu
*
* - program kończy swoje działanie gdy na wejściu wykryje "."
* 
* autor: Bartosz Kościołek <b.kosciolek@student.mimuw.edu.pl>
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

/**
* Liczba współczynników wielomianu (dla stopni od 0 do 10 włącznie)
*/
#define WIELKOSC_WIELOMIANU 11

/**
* Definicja typu "wielomian" jako tablicy współczynników
* Indeks tablicy odpowiada potędze przy "x"
*/
typedef int wielomian[WIELKOSC_WIELOMIANU];

/**
* Zeruje wielomian (wypełnia tablicę zerami)
*/
void wielomian_zero(wielomian p) {
    for (int i = 0; i < WIELKOSC_WIELOMIANU; i++) {
        p[i] = 0;
    }
}

/**
* Sprawdza czy wszystkie współczynniki wielomianu to 0
*/
bool czy_wielomian_zerowy(wielomian p) {
    for (int i = 0; i < WIELKOSC_WIELOMIANU; i++) {
        if (p[i] != 0) {
            return false;
        }
    }
    return true;
}

/**
* Oblicza sumę wielomianów "a" i "b", zapisując wynik w "wynik"
*/
void wielomian_dodawanie(wielomian a, wielomian b, wielomian wynik) {
    for (int i = 0; i < WIELKOSC_WIELOMIANU; i++) {
        wynik[i] = a[i] + b[i];
    }
}

/**
* Oblicza iloczyn wielomianów "a" i "b", zapisując wynik w "wynik"
* Wynik jest obcinany do maksymalnego stopnia = WIELKOSC_WIELOMIANU - 1
* Wykorzystuje procedurę "wielomian_zero"
*/
void wielomian_mnozenie(wielomian a, wielomian b, wielomian wynik) {
    wielomian_zero(wynik);
    for (int i = 0; i < WIELKOSC_WIELOMIANU; i++) {
        for (int j = 0; j < WIELKOSC_WIELOMIANU; j++) {
            if (i + j < WIELKOSC_WIELOMIANU) {
                wynik[i + j] += a[i] * b[j];
            }
        }
    }
}

/**
* Wczytuje najbliższy następny znak, pomijając spacje
*/
int wczytaj_nastepny_znak() {
    int c;
    do {
        c = getchar();
    } while (c == ' ');
    return c;
}

/**
* Wczytuje liczbę całkowitą (współczynnik lub stopień)
* Pomija spacje
*/
int liczba_wczytaj() {
    int c;
    int liczba = 0;
    do {
        c = getchar();
    } while (c == ' ');
    while (isdigit(c)) {
        liczba = liczba * 10 + (c - '0');
        c = getchar();
    }
    ungetc(c, stdin);
    return liczba;

}

/**
* Wczytuje jeden jednomian np. 5x^4 i dodaje go do wielomianu p z podanym znakiem
* Zwraca znak separatora, który wystąpił po jednomianie
* Wykorzystuje funkcje "liczba_wczytaj" ; "wczytaj_nastepny_znak"
*/
int przetworz_jednomian(wielomian p, int znak, int c_start) {
    int wspolczynnik = 0;
    int stopien = 0;
    int c = c_start;
    if (isdigit(c)) {
        ungetc(c, stdin);
        wspolczynnik = liczba_wczytaj();
        c = wczytaj_nastepny_znak();
    }
    else if (c == 'x') {
        wspolczynnik = 1;
    }
    if (c == 'x') {
        c = wczytaj_nastepny_znak();
        if (c == '^') {
            stopien = liczba_wczytaj();
            c = wczytaj_nastepny_znak();
        }
        else {
            stopien = 1;
        }
    }
    else {
        stopien = 0;
    }
    p[stopien] += (znak * wspolczynnik);
    return c;
}

/**
* Wczytuje cały wiersz reprezentujący wielomian
* Zarządza pętlą wczytywania znakami "+" i "-"
* Wykorzystuje funkcję "przetworz_jednomian" i "wczytaj_nastepny_znak"
*/

void wielomian_wczytaj(wielomian p) {
    wielomian_zero(p);
    int c = wczytaj_nastepny_znak();
    int znak = 1;
    if (c == '0') {
        wczytaj_nastepny_znak();
        return;
    }
    if (c == '-') {
        znak = -1;
        c = wczytaj_nastepny_znak();
    }
    else if (c == '+') {
        c = wczytaj_nastepny_znak();
    }
    c = przetworz_jednomian(p, znak, c);
    while (c != '\n') {
        if (c == '+') {
            znak = 1;
        }
        else if (c == '-') {
            znak = -1;
        }
        c = wczytaj_nastepny_znak();
        c = przetworz_jednomian(p, znak, c);
    }
}

/**
* Wypisuje wnętrze jednomianu (współczynnik)(x)(^)(stopień)
* Zakłada, że znak +/- został obsłużony
*/

void wypisz_wnetrze_jednomianu(int wspolczynnik, int stopien) {
    int bezwgledny_wspolczynnik;
    if (wspolczynnik > 0) {
        bezwgledny_wspolczynnik = wspolczynnik;
    }
    else {
        bezwgledny_wspolczynnik = -wspolczynnik;
    }
    if (bezwgledny_wspolczynnik != 1 || stopien == 0) {
        printf("%d", bezwgledny_wspolczynnik);
    }
    if (stopien > 0) {
        printf("x");
    }
    if (stopien > 1) {
        printf("^%d", stopien);
    }
}

/**
* Wypisuje pierwszy niezerowy składnik wielomianu
* Obsługuje logikę znaku dla pierwszego elementu (wstawia minus albo nie)
* Wykorzystuje procedurę "wypisz_wnetrze_jednomianu"
*/
void wypisz_pierwszy_skladnik(int wspolczynnik, int stopien) {
    if (wspolczynnik < 0) {
        printf("-");
    }
    wypisz_wnetrze_jednomianu(wspolczynnik, stopien);
}

/**
* Wypisuje kolejny (nie pierwszy) składnik wielomianu
* Oddziela operatory spacjami
* Wykorzystuje procedurę "wypisz_wnetrze_jednomianu"
*/
void wypisz_kolejny_skladnik(int wspolczynnik, int stopien) {
    if (wspolczynnik < 0) {
        printf(" - ");
    }
    else {
        printf(" + ");
    }
    wypisz_wnetrze_jednomianu(wspolczynnik, stopien);
}

/**
* Wypisuje wielomian w formacie zgodnym ze specyfikacją zadania
* Wykorzystuje funkcję "czy_wielomian_zerowy"
* Wykorzystuje procedurę "wypisz_pierwszy_skladnik" ; "wypisz_kolejny_skladnik"
*/
void wielomian_wypisz(wielomian p) {
    if (czy_wielomian_zerowy(p)) {
        putchar('0');
        return;
    }
    int i = WIELKOSC_WIELOMIANU - 1;
    while (i >= 0 && p[i] == 0) {
        i--;
    }
    wypisz_pierwszy_skladnik(p[i], i);
    i--;
    while (i >= 0) {
        if (p[i] != 0) {
            wypisz_kolejny_skladnik(p[i], i);
        }
        i--;
    }
}

/**
 * Kopiuje wielomian "zrodlo" do wielomianu "cel"
 */
void wielomian_kopiuj(wielomian cel, wielomian zrodlo) {
    for (int i = 0; i < WIELKOSC_WIELOMIANU; i++) {
        cel[i] = zrodlo[i];
    }
}

/**
* Główna funkcja programu
* Zarządza akumulatorem, pętlą wczytywania poleceń (aż do ".")
* Wykonuje odpowiednie operacje - suma, mnożenie
* Zmienna "akumulator" przechowuje wielomian, który jest wynikiem poprzedniej operacji (wielomian zerowy na start)
* Zmienna "argument" przechowuje wielomian wczytywany
* Zmienna "tymczasowy_wynik" przechowuje tymczasowy wynik do poprawnego wykonania operacji mnożenia
*/
int main(void) {
    wielomian akumulator;
    wielomian argument;
    wielomian tymczasowy_wynik;
    wielomian_zero(akumulator);
    int c;
    while ((c = getchar()) != '.') {
        wielomian_wczytaj(argument);
        if (c == '+') {
            wielomian_dodawanie(akumulator, argument, akumulator);
        }
        else if (c == '*') {
            wielomian_mnozenie(akumulator, argument, tymczasowy_wynik);
            wielomian_kopiuj(akumulator, tymczasowy_wynik);
        }
        wielomian_wypisz(akumulator);
        putchar('\n');
    }
    return 0;
}