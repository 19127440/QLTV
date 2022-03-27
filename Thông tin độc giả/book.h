#ifndef _BOOK_H_
#define _BOOK_H_
#include "reader.h"

void outputBook(int i, char isbn[][18], char name[][101], char tg[][51], char nxb[][51], int year[], char type[][51], int price[]);
void inputBook(int n, char isbn[][18], char name[][101], char tg[][51], char nxb[][51], int year[], char type[][51], int price[]);
void editInfo(int inf, int pos, char isbn[][18], char name[][101], char tg[][51], char nxb[][51], int year[], char type[][51], int price[]);
void editBook(int pos, char isbn[][18], char name[][101], char tg[][51], char nxb[][51], int year[], char type[][51], int price[]);
void deleteItemChar1(char a[][101], int pos);
void deleteBook(int pos, int n, char isbn[][18], char name[][101], char tg[][51], char nxb[][51], int year[], char type[][51], int price[]);
int findBookWithISBN(int n, char isbn[][18], char x[]);
int checkBookName(int i, char name[][101], char x[]);
void listOfBorrowedBook(int nb, int n[], int i, int isbn[][10], char ISBN[][18]);
void borrowCard(int nb, int n[], int i, int id[], char borrow[][11], char expect[][11], int isbn[][10], char ISBN[][18]);
void outputBorrowCard(int n[], int i, int id[], char borrow[][11], char expect[][11], int isbn[][10], char ISBN[][18]);
void returnCard(int pm, int n[], int id[], char borrow[][11], char expect[][11], char reality[][11], int isbn[][10], char ISBN[][18]);
#endif