/** @file */
#ifndef listLine_H
#define listLine_H

#include "struktury.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Funkcja dodaje do listy jednokierunkowej kolejno pobrane linie przyk�adowego pliku
@param head wska�nik na pocz�tek listy
@param bufor tablica do przechowywania pobranych linijek z pliku
*/
void pushBack(ListElement_type** head, char* bufor);

/** Funkcja wczytuje kolejne linijki kodu z przyk�adowego pliku
@param bufor tablica do przechowywania pobranych linijek z pliku
@param head wska�nik na pocz�tek listy
*/
void readFile(char* bufor, ListElement_type** head, char* read);

/** Funkcja wyswietla pobrany plik na ekran konsoli
@param head wska�nik na pocz�tek listy
*/
void show(ListElement_type* head);

/** Funkcja zapisuje zmiany do pliku.
@param head wska�nik na pocz�tek listy
*/
void saveToFile(ListElement_type* head, char* save);

/** Funkcja zlicza ilo�� element�w listy jednokierunkowej
@param head wska�nik na pocz�tek listy
@return counter ilo�� element�w listy
*/
int listSize(ListElement_type* head);

/** Funkcja edytuj�ca wybran� lini� programu.
@param head wska�nik na pocz�tek listy
@param tab tablica znacznik�w rozpoczynaj�cych si� tak samo
@param n wybrany tag
*/
void editLine(char* head, int** tab, const int n);

/** Funkcja edytuj�ca wybran� lini� programu.
@param head wska�nik na pocz�tek listy
@param n numer wybranej lini
@param wsk wska�nik na wybrany element listy jednokierunkowej
*/
ListElement_type* findLine(ListElement_type* head, int n);

/** Funkcja dealokuje pami��.
@param head wska�nik na pocz�tek listy
*/
void deleteList(ListElement_type** head);

/** Funkcja pobiera numer lini kt�r� u�ytkownik chce edytowa� 
@param line pobrany przez u�ytkownika numer lini
@param counter ilo�� wszystkich lini w pliku
@param head wska�nik na pierwsyz element listy 
*/
ListElement_type* whichLine(int line, int counter, ListElement_type* head);

/** Funkcja obs�uguje dzia��nie ca�ego programu wywo�uj�c pozosta�e funkcje
@param read nazwa pliku do wczytania podana przez u�ytkownika 
@param save nazwa pliku do zapisu podana przez u�ytkownika 
*/
void menu(char* read, char* save);

#endif