#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iterator>
#include <stdlib.h>
#include <numeric>
#include <chrono>
#include "genrandom.h"
#include "readFile.h"
#include "genpaz.h"
#include "countgal.h"
#include "generavimas.h"

using namespace std;


int main()
{
	vector<int> skaiciai;
	int kiek = generavimas(skaiciai);
	
	vector<stud> studentai;
	readFile(studentai, kiek);

	vector<stud> talentai;
	vector<stud> nuskriaustieji;
	int tal = 0;
	int nusk = 0;

	auto start = chrono::high_resolution_clock::now();
	auto st = start;
	for (int i = 0; i < kiek; i++) {
		float paz = 5.00;
		if (studentai.at(i).gal >= paz) {
			talentai.push_back(studentai.at(i));
			tal++;
		}
	}
	for (int i = 0; i < kiek; i++) {
		float paz = 5.00;
		if (studentai.at(i).gal < paz) {
			nuskriaustieji.push_back(studentai.at(i));
			nusk++;
		}
	}
	
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;
	cout << to_string(kiek) + " studentu rusiavimas i 2 grupes uztruko : " << diff.count() << " s\n";

	string pav;

	pav = "nuskriaustieji_" + to_string(kiek) + ".txt";
	ofstream nuskduom(pav);
	auto start1 = chrono::high_resolution_clock::now();
	auto st1 = start1;
	for (int i = 0; i < kiek; i++) {

		float paz = 5.00;
		if (studentai.at(i).gal < paz) {
			nuskduom << studentai.at(i).Vard << setw(20) << studentai.at(i).Pav << setw(18) << studentai.at(i).gal << endl;
		}
	}
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double> diff1 = end1 - start1;
	cout << to_string(kiek) + " nuskriaustuju studentu irasymas i faila uztruko : " << diff1.count() << " s\n";

	pav = "talentai_" + to_string(kiek) + ".txt";
	ofstream talduom(pav);
	auto start2 = chrono::high_resolution_clock::now();
	auto st2 = start2;
	for (int j = 0; j < kiek; j++) {
		float paz = 5.00;
		if (studentai.at(j).gal >= paz) {
			talduom << studentai.at(j).Vard << setw(20) << studentai.at(j).Pav << setw(18) << studentai.at(j).gal << endl;
		}
	}
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<double> diff2 = end2 - start2;
	cout << to_string(kiek) + " talentu studentu irasymas i faila : " << diff2.count() << " s\n";
	
}