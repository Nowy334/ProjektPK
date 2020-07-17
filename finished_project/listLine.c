#include "struktury.h"
#include "ListLine.h"
#include "ListTags.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pushBack(ListElement_type** head, char* bufor) {
	if (*head == NULL)
	{
		*head = (ListElement_type*)malloc(sizeof(ListElement_type));
		strcpy_s((*head)->line, _countof((*head)->line), bufor);
		(*head)->next = NULL;
	}
	else
	{
		ListElement_type* current = *head;

		while (current->next != NULL) {
			current = current->next;
		}

		current->next = (ListElement_type*)malloc(sizeof(ListElement_type));
		strcpy_s(current->next->line, _countof(current->next->line), bufor);
		current->next->next = NULL;
	}
}

void readFile(char* bufor, ListElement_type** head, char* read) {
	FILE* file;
	if (fopen_s(&file, read, "r") == 0) {
		while (fgets(bufor, 255, file) != NULL) {
			pushBack(head, bufor);
		}
	}
	fclose(file);
}

void show(ListElement_type* head) {
	int i = 1;
	printf("\n");
	if (head == NULL) printf("List is empty");
	else
	{
		ListElement_type* current = head;
		do {
			printf("%d", i++);
			printf(". ");
			printf("%s", current->line);
			current = current->next;
		} while (current != NULL);
		printf("\n");
	}
}

void saveToFile(ListElement_type* head, char* save) {
	FILE* file;
	fopen_s(&file, save, "w");
	ListElement_type* current = head;
	do {
		fprintf(file, "%s", (current->line));
		current = current->next;
	} while (current != NULL);
	fclose(file);
}

int listSize(ListElement_type* head)
{
	int counter = 0;
	if (head == NULL) return counter;
	else
	{
		ListElement_type* current = head;
		do {
			counter++;
			current = current->next;
		} while (current != NULL);
	}
	return counter;
}

void editLine(char* head, int** tab, const int n) {
	ListElement_type* current = head;
	TagsElement_type* p = tab[n - 1];
	char tekst[255];
	char tekst2[255] = "";
	printf("Podaj tekst: ");
	fgets(tekst, 254, stdin);
	tekst[strcspn(tekst, "\n")] = 0;
	strcat_s(tekst2, 255, p->Tag1);
	strcat_s(tekst2, 255, tekst);
	strcat_s(tekst2, 255, p->Tag2);
	strcpy_s(current->line, _countof(current->line), tekst2);
}

ListElement_type* findLine(ListElement_type* head, int n) {
	int i = 1;
	if (head == NULL) {
		printf("Lista jest pusta");
		return NULL;
	}
	else
	{
		ListElement_type* current = head;
		while (i < n) {
			current = current->next;
			i++;
		}
		return current->line;
	}
}

void deleteList(ListElement_type** head) {
	ListElement_type* current = *head;
	ListElement_type* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

ListElement_type* whichLine(int line, int counter, ListElement_type* head) {

	printf("\nKtora linie chcesz edytowac? ");

	scanf_s("%d", &line);
	while ((getchar()) != '\n');
	if (line > counter || line <= 0) {
		printf("Nieprawidlowy numer lini");
		return NULL;
	}
	else {
		return findLine(head, line);
	}
}

void menu(char* read, char* save) {
	//HTML
	ListElement_type* head;
	head = (ListElement_type*)malloc(sizeof(ListElement_type));
	head = NULL;
	int line;
	char bufor[255];

	//TAGS
	TagsElement_type* tHead;
	tHead = (TagsElement_type*)malloc(sizeof(TagsElement_type));
	tHead = NULL;
	char Tag1[255];
	char tag[10];
	int tagLine = 0;

	ListElement_type* wsk = NULL;
	int* tab[50];
	char koniec = ' ';
	readFile(bufor, &head, read);
	show(head);
	int counter = listSize(head);
	int counterTag = listTagsSize(tHead);
	readFileWithTags(Tag1, &tHead);

	while (koniec != 'k') {
		wsk = whichLine(&line, counter, head);

		startOfTag(tag, tHead, tab, wsk, tagLine); //, tag[1]
		saveToFile(head, save);
		puts("Jezeli chcesz zakonczyc wpisz k: ");
		koniec = getchar();
	}
	deleteList(&head);
	deleteTagList(&tHead);
}