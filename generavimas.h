#pragma once
#include "build_lib.h";
#include "stud.h";

using namespace std;

int countWords(string const& str);
void failogeneravimas(int kiek);
void skaitymas(vector<stud>& S, string failo_pavadinimas, int* kiek);
void isvedimas(string failo_pavadinimas, vector<stud> vek);
