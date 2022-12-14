#pragma once
#include "build_lib.h";
#include "stud.h";

using namespace std;

int countWords(string const& str);
int randompaz();
bool has_digit(string s);
void input(vector<stud>& S, int i);
void inputlist(list<stud>& S, int i);
bool compare(const stud& a, const stud& b);
void failogeneravimas(int kiek);
void skaitymas(vector<stud>& S, string failopavadinimas, int* kiek);
void skaitymaslist(list<stud>& S, string failo_pavadinimas, int* kiek);
bool kuriame(stud c);
void studgrupvek1(vector<stud> studentai, vector<stud>& nuskriaustieji, vector<stud>& talentai);
void studgruplist1(list<stud>& studentai, list<stud>& nuskriaustieji, list<stud>& talentai);
void studgrupvek2(vector<stud>& studentai, vector<stud>& nuskriaustieji);
void studgruplist2(list<stud>& studentai, list<stud>& nuskriaustieji);
void studgrupvekopt(vector<stud>& studentai, vector<stud>& nuskriaustieji);
void studgruplistopt(list<stud>& studentai, list<stud>& nuskriaustieji);
void isvedimas(string failo_pavadinimas, vector<stud> S);
void isvedimaslist(string failo_pavadinimas, list<stud> s); 
