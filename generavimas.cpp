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

int generavimas(vector<int> pazymiai)
{
	int kiek;
	cout << "Irasykite norima studentu skaiciu: " << endl;
	cin >> kiek;
	string pavadinimas = "Studentai_" + to_string(kiek) + ".txt";
	auto start = chrono::high_resolution_clock::now();
	auto st = start;
	ofstream out_data(pavadinimas);
	vector<int> skaiciai;
	out_data << setw(20) << left << "Vardas"
		<< setw(20) << left << "Pavarde"
		<< setw(20) << left << "Galutinis(vid.)";



	for (int s = 1; s <= kiek; s = s + 1)
	{
		skaiciai = genpaz(5);
		out_data << setw(20) << "Vardas" + to_string(s) <<
			setw(20) << "Pavarde" + to_string(s) <<
			setw(18) << countgal(skaiciai) << endl;;
		skaiciai.clear();

	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;
	cout << "Failo su " + to_string(kiek) + " irasu(studentu) kurimas uztruko: " << diff.count() << " s\n";

	return kiek;
}