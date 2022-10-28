#include "build_lib.h"
#include "stud.h"


using namespace std;


int countWords(string const& str)
{
	stringstream stream(str);
	return std::distance(istream_iterator<string>(stream), istream_iterator<string>());
}
void failogeneravimas(int kiek)
{
	
	string pavadinimas = "Studentai_" + to_string(kiek) + ".txt";
	ofstream out_data(pavadinimas);

	mt19937 mt(static_cast<long unsigned int>(high_resolution_clock::now().time_since_epoch().count()));
	uniform_int_distribution<int> dist(1, 10);

	auto start = chrono::high_resolution_clock::now();
	
	out_data << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde";
	for (int j = 1; j < 4; j++)
		out_data << right << setw(6) << "ND" + to_string(j);
	out_data << setw(6) << "Egz.";
	out_data << endl;



	for (int s = 1; s <= kiek; s++)
	{
		out_data << left << setw(25) << "Vardas" + to_string(s) << setw(25) << "Pavarde" + to_string(s);
		for (int i = 0; i < 4; i++)
			out_data << right << setw(6) << dist(mt);
		out_data << endl;
	}
	out_data.close();

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;
	cout << "Failo su " << kiek << " irasu(studentu) kurimas uztruko: " << diff.count() << "s\n";
}


void skaitymas(vector<stud>& S, string failo_pavadinimas, int* kiek)
{
	auto start = chrono::high_resolution_clock::now();

	string eilute;
	ifstream fileRead(failo_pavadinimas);

	int studentas = 0;
	int temp;

	string buff;
	ifstream r;
	try {
		r.open(failo_pavadinimas);
		if (!r)
			throw std::runtime_error("Failo tokiu pavadinimu nera.");

		getline(r >> ws, buff);
		*kiek = countWords(buff) - 3;
		while (true)
		{
			S.resize(S.size() + 1);
			r >> S.at(studentas).Vard;
			if (r.eof())
			{
				S.pop_back();
				break;
			}
			r >> S.at(studentas).Pav;
			for (int i = 0; i < *kiek; i++)
			{
				r >> temp;
				S.at(studentas).paz.push_back(temp);
			}
			r >> S.at(studentas).egz;
			studentas++;
		}
		r.close();
	}
	catch (int e) {}
	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "Failo nuskaitymas uztruko: " << diff.count() << "s\n";
	if (S.size() == 0)
		cout << "Negalima atidaryti failo arba jis tuscias." << endl;
}

void isvedimas(string failo_pavadinimas, vector<stud> S)
{
	ofstream stud_failas(failo_pavadinimas);

	auto matavimo_pradzia = high_resolution_clock::now();

	stud_failas << left << setw(25) << "Vardas" << setw(25) << "Pavarde" << setw(15) << "Gal.(vid)" << setw(15) << "Gal.(med)" << endl;

	for (int i = 0; i < S.size(); i++)
	{
		stud laikstud = S[i];
		stud_failas << left << setw(25) << laikstud.Vard << setw(25) << laikstud.Pav 
					<< setw(15) << laikstud.gal << setw(15) << laikstud.med << endl;
	}

	stud_failas.close();

	auto matavimo_pabaiga = high_resolution_clock::now();
	duration<double> skirtumas = matavimo_pabaiga - matavimo_pradzia;
	cout << "Failo " + failo_pavadinimas + " kurimas uztruko: " << skirtumas.count() << "s" << endl;
}
