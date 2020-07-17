/** @file */
#ifndef listTags_H
#define listTags_H

#include "struktury.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Funkcja dodaje kolejne znaczniki jezyka html do listy jednokierunkowej.
@param head wskaŸnik na pocz¹tek listy
@param bufor znacznik otwieraj¹cy
@param bufor2 znacznik zamykaj¹cy
*/
void pushBackToTags(TagsElement_type** head, char* bufor, char* bufor2);

/** Funkcja wczytuje znaczniki jêzyka html z pliku.
@param bufor tablica do przechowywania pobranych znaczników
@param head wskaŸnik na pocz¹tek listy
*/
void readFileWithTags(char* bufor, TagsElement_type** head);

/** Funkcja wypisuje liste wybranych znaczników html.
@param head wskaŸnik na pocz¹tek listy
*/
void showTags(TagsElement_type* head);

/** Funkcja sprawdza ile elementów ma lista znaczników.
@param head wskaŸnik na pocz¹tek listy
*/
int listTagsSize(TagsElement_type* head);

/** Funkcja przeszukuje liste znaczników w celu wypisania zadanych znaczników.
@param head wskaŸnik na pocz¹tek listy
@param n pocz¹tek pobranego znacznika
@param tab tworzy tablice znaczników rozpoczynaj¹cych siê tak samo
*/
void findTag(TagsElement_type* head, char n, int** tab);

/** Funkcja dealokuje pamiêæ.
@param head wskaŸnik na pocz¹tek listy
*/
void deleteTagList(TagsElement_type** head);

/** Funkcja przeszukuje liste tagów wyswietlaj¹c tylko te, które zaczynaj¹ siê na zadany pocz¹tek oraz zwraca element listy w której znajduje siê wybrany przez u¿ytkownika znacznik.
@param tag pocz¹tek znacznika 
@param tHead wskaŸnik na pocz¹tek listy z Tagami
@param tab wskaŸnik na wybrany element listy z tagami
@param wsk adres wybranej lini z listy
@param tagLine numer wybranego Tagu 
*/
void startOfTag(char* tag, TagsElement_type* tHead, int* tab, ListElement_type* wsk, int tagLine);

#endif