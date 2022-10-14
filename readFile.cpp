#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iterator>
#include "readFile.h"
#include "countWords.h"
#include <chrono>
using namespace std;

void readFile(vector<stud>& S, int kiek)
{
	int studentas = 0;
	ifstream fileRead;
	string pavadinimas = "Studentai_" + to_string(kiek) + ".txt";
	string buff;
	fileRead.open(pavadinimas);
	if (fileRead.is_open()) {

		auto start = chrono::high_resolution_clock::now();
		auto st = start;
		getline(fileRead >> ws, buff);
		while (studentas < kiek)
		{

			S.resize(S.size() + 1);
			fileRead >> S.at(studentas).Vard;
			fileRead >> S.at(studentas).Pav;
			fileRead >> S.at(studentas).gal;
			studentas++;
		}
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		cout << "Failo su " + std::to_string(kiek) + " irasu(studentu) nuskaitymas uztruko: " << diff.count() << " s\n";

	}


}