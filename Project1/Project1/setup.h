#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string>
//#include <unistd.h>
#include <vector>
#include <windows.h>
#include <fstream>
#include <iomanip>
#define xx 20
#define yy 5
#define mauKhung 15
#define mauChu 14
#define mauTieuDe 11

using namespace std;

struct date;

void TextColor(int color);
void gotoXY(int column, int line);
void Khung(int cot, int hang, int m, int n);
int Menu(int k);
