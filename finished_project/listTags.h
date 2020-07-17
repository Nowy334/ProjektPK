/** @file */
#ifndef listTags_H
#define listTags_H

#include "struktury.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Funkcja dodaje kolejne znaczniki jezyka html do listy jednokierunkowej.
@param head wska�nik na pocz�tek listy
@param bufor znacznik otwieraj�cy
@param bufor2 znacznik zamykaj�cy
*/
void pushBackToTags(TagsElement_type** head, char* bufor, char* bufor2);

/** Funkcja wczytuje znaczniki j�zyka html z pliku.
@param bufor tablica do przechowywania pobranych znacznik�w
@param head wska�nik na pocz�tek listy
*/
void readFileWithTags(char* bufor, TagsElement_type** head);

/** Funkcja wypisuje liste wybranych znacznik�w html.
@param head wska�nik na pocz�tek listy
*/
void showTags(TagsElement_type* head);

/** Funkcja sprawdza ile element�w ma lista znacznik�w.
@param head wska�nik na pocz�tek listy
*/
int listTagsSize(TagsElement_type* head);

/** Funkcja przeszukuje liste znacznik�w w celu wypisania zadanych znacznik�w.
@param head wska�nik na pocz�tek listy
@param n pocz�tek pobranego znacznika
@param tab tworzy tablice znacznik�w rozpoczynaj�cych si� tak samo
*/
void findTag(TagsElement_type* head, char n, int** tab);

/** Funkcja dealokuje pami��.
@param head wska�nik na pocz�tek listy
*/
void deleteTagList(TagsElement_type** head);

/** Funkcja przeszukuje liste tag�w wyswietlaj�c tylko te, kt�re zaczynaj� si� na zadany pocz�tek oraz zwraca element listy w kt�rej znajduje si� wybrany przez u�ytkownika znacznik.
@param tag pocz�tek znacznika 
@param tHead wska�nik na pocz�tek listy z Tagami
@param tab wska�nik na wybrany element listy z tagami
@param wsk adres wybranej lini z listy
@param tagLine numer wybranego Tagu 
*/
void startOfTag(char* tag, TagsElement_type* tHead, int* tab, ListElement_type* wsk, int tagLine);

#endif