#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include "stud.h"
#include "wordsmedian.h"
using namespace std;

int randompaz();
void autopaz(vector<stud>& S, int i, int pazkiek);
void input(vector<stud>& S, int i);
bool has_digit(string s);
void name_input(vector<stud>& S, int i);
void readFile(vector<stud>& S, int* pazkiek);
bool compare(const stud& a, const stud& b);
void printStudent(vector<stud> S, int pazkiek);