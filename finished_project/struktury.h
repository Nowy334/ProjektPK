/** @file  */

#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Lista jednokierunkowa  lini wczytywanych z pliku */
typedef struct ListElement {
	char line[100]; ///<dana linia
	struct ListElement* next; ///< adres nastepnego elementu
} ListElement_type;

/** Lista jednokierunkowa znacznik�w j�zyka html wczytywanych z pliku */
typedef struct TagsElement {
	char Tag1[20];///< znacznik pocz�tku
	char Tag2[20];///< znacznik ko�ca 
	struct TagsElement* next;
} TagsElement_type;

#endif