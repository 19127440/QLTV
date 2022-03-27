#ifndef _READER_H_
#define _READER_H_
#include <iostream>
#include <string.h>
using namespace std;

void outputReader(int i, int id[], char name[][51], int cmnd[], char bday[][11], bool sex[], char email[][51], char add[][51], char since[][11], char end[][11]);
//bool checkCMND(char cmnd[]);
//int convertData(char cmnd[]);
//int inputCMND(char check[]);
//int inputSex(char c);
void inputReader(int n, int id[], char name[][51], int cmnd[], char bday[][11], bool sex[], char email[][51], char add[][51], char since[][11], char end[][11]);
void editInfo(int inf, int pos, int id[], char name[][51], int cmnd[], char bday[][11], bool sex[], char email[][51], char add[][51], char since[][11], char end[][11]);
void editReader(int pos, int id[], char name[][51], int cmnd[], char bday[][11], bool sex[], char email[][51], char add[][51], char since[][11], char end[][11]);
void deleteItemChar(char a[][51], int pos);
void deleteReader(int pos, int n, int id[], char name[][51], int cmnd[], char bday[][11], bool sex[], char email[][51], char add[][51], char since[][11], char end[][11]);
int findReaderWithCMND(int n, int cmnd[], int x);
void lowercaseName(char name[]);
int findReaderWithFirstName(int i, char name[][51], char x[]);
void firstName(char fullname[], char firstname[]);
char convertChar(char s[]);
#endif