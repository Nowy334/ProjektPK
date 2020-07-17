/** @file */
#ifndef listLine_H
#define listLine_H

#include "struktury.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Funkcja dodaje do listy jednokierunkowej kolejno pobrane linie przyk³adowego pliku
@param head wskaŸnik na pocz¹tek listy
@param bufor tablica do przechowywania pobranych linijek z pliku
*/
void pushBack(ListElement_type** head, char* bufor);

/** Funkcja wczytuje kolejne linijki kodu z przyk³adowego pliku
@param bufor tablica do przechowywania pobranych linijek z pliku
@param head wskaŸnik na pocz¹tek listy
*/
void readFile(char* bufor, ListElement_type** head, char* read);

/** Funkcja wyswietla pobrany plik na ekran konsoli
@param head wskaŸnik na pocz¹tek listy
*/
void show(ListElement_type* head);

/** Funkcja zapisuje zmiany do pliku.
@param head wskaŸnik na pocz¹tek listy
*/
void saveToFile(ListElement_type* head, char* save);

/** Funkcja zlicza iloœæ elementów listy jednokierunkowej
@param head wskaŸnik na pocz¹tek listy
@return counter iloœæ elementów listy
*/
int listSize(ListElement_type* head);

/** Funkcja edytuj¹ca wybran¹ liniê programu.
@param head wskaŸnik na pocz¹tek listy
@param tab tablica znaczników rozpoczynaj¹cych siê tak samo
@param n wybrany tag
*/
void editLine(char* head, int** tab, const int n);

/** Funkcja edytuj¹ca wybran¹ liniê programu.
@param head wskaŸnik na pocz¹tek listy
@param n numer wybranej lini
@param wsk wskaŸnik na wybrany element listy jednokierunkowej
*/
ListElement_type* findLine(ListElement_type* head, int n);

/** Funkcja dealokuje pamiêæ.
@param head wskaŸnik na pocz¹tek listy
*/
void deleteList(ListElement_type** head);

/** Funkcja pobiera numer lini któr¹ u¿ytkownik chce edytowaæ 
@param line pobrany przez u¿ytkownika numer lini
@param counter iloœæ wszystkich lini w pliku
@param head wskaŸnik na pierwsyz element listy 
*/
ListElement_type* whichLine(int line, int counter, ListElement_type* head);

/** Funkcja obs³uguje dzia³¹nie ca³ego programu wywo³uj¹c pozosta³e funkcje
@param read nazwa pliku do wczytania podana przez u¿ytkownika 
@param save nazwa pliku do zapisu podana przez u¿ytkownika 
*/
void menu(char* read, char* save);

#endif