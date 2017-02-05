#ifndef MYLIBRARY
#define MYLIBRARY
#include <stdio.h>
#include <termios.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include <cmath>
#include <stdlib.h>
#include "Colors.hpp"
using namespace std;

//const int PRINT_FAST=;
const int PRINT_MEDIUM=50000;
//const int PRINT_SLOW=;
static struct termios old, nuovo;
char getch();
void slow_print(const char *text);
bool uguali(char a[], char b[]);
void clear_input(char*,const int);
void beep();
void clear_screen();
void loading();
#endif
