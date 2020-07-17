#include "struktury.h"
#include "listTags.h"
#include "listLine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pushBackToTags(TagsElement_type** head, char* bufor, char* bufor2) {
	if (*head == NULL)
	{
		*head = (TagsElement_type*)malloc(sizeof(TagsElement_type));
		strcpy_s((*head)->Tag1, _countof((*head)->Tag1), bufor);
		strcpy_s((*head)->Tag2, _countof((*head)->Tag2), bufor2);
		(*head)->next = NULL;
	}
	else
	{
		TagsElement_type* current = *head;

		while (current->next != NULL) {
			current = current->next;
		}

		current->next = (TagsElement_type*)malloc(sizeof(TagsElement_type));
		strcpy_s(current->next->Tag1, _countof(current->next->Tag1), bufor);
		strcpy_s(current->next->Tag2, _countof(current->next->Tag2), bufor2);
		current->next->next = NULL;
	}
}

void readFileWithTags(char* bufor, TagsElement_type** head) {
	FILE* file;
	char* schowek;
	char* schowek2;
	char korektor[] = " ";
	if (fopen_s(&file, "tags.txt", "r") == 0) {
		while (fgets(bufor, 255, file) != NULL) {
			schowek = strtok_s(NULL, korektor, &bufor);
			schowek2 = strtok_s(NULL, korektor, &bufor);
			pushBackToTags(head, schowek, schowek2);
		}
	}
	fclose(file);

}

void showTags(TagsElement_type* head) {
	int i = 1;
	if (head == NULL) printf("List is empty");
	else
	{
		TagsElement_type* current = head;
		do {
			printf("%d", i++);
			printf(". ");
			printf("%s", current->Tag1);
			printf("%s", current->Tag2);
			current = current->next;
		} while (current != NULL);
		printf("\n");
	}
}

int listTagsSize(TagsElement_type* head) {
	int counter = 0;
	if (head == NULL) return counter;
	else
	{
		TagsElement_type* current = head;
		do {
			counter++;
			current = current->next;
		} while (current != NULL);
	}
	return counter;
}

void findTag(TagsElement_type* head, char n, int** tab) {

	int i = 1;
	int j = 0;
	printf("\n");
	if (head == NULL) {
		printf("Lista jest pusta");
	}
	else
	{
		TagsElement_type* current = head;
		while (current) {
			if (n == current->Tag1[1]) {
				printf("%d", i++);
				printf(". ");
				printf(current->Tag1);
				printf(current->Tag2);
				tab[j] = current;
				j++;
			}
			current = current->next;
		}
	}
	printf("\n");
}

void deleteTagList(TagsElement_type** head) {
	TagsElement_type* current = *head;
	TagsElement_type* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

void startOfTag(char* tag, TagsElement_type* tHead, int* tab, ListElement_type* wsk, int tagLine) { 
	printf("Podaj poczatek znacznika, ktorego chcesz uzyc: ");

	gets_s(tag, 9);
	findTag(tHead, tag[1], tab);
	printf("\nKtorego tagu chcesz uzyc? ");
	scanf_s("%d", &tagLine);
	while ((getchar()) != '\n');
	editLine(wsk, tab, tagLine);
}