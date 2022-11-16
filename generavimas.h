#pragma once
#include "build_lib.h";
#include "stud.h";

using namespace std;

int countWords(string const& str);
int randompaz();
bool has_digit(string s);
void input(vector<stud>& S, int i);
bool compare(const stud& a, const stud& b);
void failogeneravimas(int kiek);
void skaitymas(vector<stud>& S, string failo_pavadinimas, int* kiek);
void isvedimas(string failo_pavadinimas, vector<stud> S);