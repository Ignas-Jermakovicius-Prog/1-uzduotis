#include "build_lib.h"
#include "stud.h"
#include "vidmed.h"


using namespace std;


int countWords(string const& str)
{
	stringstream stream(str);
	return std::distance(istream_iterator<string>(stream), istream_iterator<string>());
}

int randompaz()
{
	mt19937 mt(static_cast<long unsigned int>(high_resolution_clock::now().time_since_epoch().count()));
	uniform_int_distribution<int> dist(1, 10);
	return dist(mt);
}

void autopaz(vector<stud>& S, int i, int pazkiek)
{
	S.at(i).egz = randompaz();
	for (int j = 0; j < pazkiek; j++)
	{
		S.at(i).paz.push_back(randompaz());
	}
	S.at(i).gal = vid(S.at(i).paz) * 0.4 + S.at(i).egz * 0.6;
	S.at(i).med = med(S.at(i).paz) * 0.4 + S.at(i).egz * 0.6;
}
void input(vector<stud>& S, int i)
{
	int temp, egz;
	cout << "iveskite studento pazymius (kai baigsite, iveskite -1 (minus vienas)):";
	cin >> temp;
	while (temp != -1) {
		S.at(i).paz.push_back(temp);
		cin >> temp;
	}
	do {
		cout << "iveskite studento egz:\n";
		cin >> egz;
		S.at(i).egz = egz;
	} while (egz < 0 || egz > 10);
	S.at(i).gal = vid(S.at(i).paz) * 0.4 + S.at(i).egz * 0.6;
	S.at(i).med = med(S.at(i).paz) * 0.4 + S.at(i).egz * 0.6;
}
bool has_digit(string s)
{
	return (s.find_first_of("0123456789") != string::npos);
}
void name_input(vector<stud>& S, int i)
{
	cout << "iveskite studento nr. " << i + 1 << " duomenis:\n";
	do {
		cout << "iveskite studento nr. " << i + 1 << " varda:\n";
		cin >> S.at(i).Vard;
	} while (S.at(i).Vard.length() < 0 || S.at(i).Vard.length() > 25 || has_digit(S.at(i).Vard));
	do {
		cout << "iveskite studento nr. " << i + 1 << " pav:\n";
		cin >> S.at(i).Pav;
	} while (S.at(i).Pav.length() < 0 && S.at(i).Pav.length() > 25 || has_digit(S.at(i).Pav));
	cout << endl;
}

bool compare(const stud& a, const stud& b)
{
	if (a.Vard != b.Vard)
		return a.Vard < b.Vard;
	else
		return a.Pav < b.Pav;
}


void failogeneravimas(int kiek)
{
	
	string pavadinimas = "studentai" + to_string(kiek) + ".txt";
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
			out_data << right << setw(6) << randompaz();
		out_data << endl;
	}
	out_data.close();

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;
	cout << "Failo su " << kiek << " studentu/-ais kurimas uztruko: " << diff.count() << "s\n\n";
}


void skaitymas(vector<stud>& S, string failopavadinimas, int* kiek)
{
	auto start = chrono::high_resolution_clock::now();

	int studentas = 0;
	int temp;

	string buff;
	ifstream r;
	try {
		r.open(failopavadinimas);
		if (!r)
			throw 0;
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
	catch (int e) 
	{
		cout << "Failo tokiu pavadinimu nera.";
		return;
	}
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
					<< setw(15) << setprecision(3) << laikstud.gal << setw(15) << setprecision(3) << laikstud.med << endl;
	}

	stud_failas.close();

	auto matavimo_pabaiga = high_resolution_clock::now();
	duration<double> skirtumas = matavimo_pabaiga - matavimo_pradzia;
	cout << "Failo " + failo_pavadinimas + " kurimas uztruko: " << skirtumas.count() << "s\n";
}