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

bool has_digit(string s)
{
	return (s.find_first_of("0123456789") != string::npos);
}

void input(vector<stud>& S, int i)
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
	string tempc;
	do
	{
		cout << "jeigu norite, kad studento pazymiai butu suvesti automatiskai - spauskite \"r\"\n jeigu norite suvesti duomenis patys - rasykite \"p\"\n";
		cin >> tempc;
		if (tempc != "r" && tempc != "R" && tempc != "p" && tempc != "P") {
			cout << "pakartokite, netinkamas simbolis\n";
		}
	} while (tempc != "r" && tempc != "R" && tempc != "p" && tempc != "P");
	if (tempc == "p" || tempc == "P")
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
		cout << endl;
	}
	else
	{
		S.at(i).egz = randompaz();
		for (int j = 0; j < 5; j++)
		{
			S.at(i).paz.push_back(randompaz());
		}
		S.at(i).gal = vid(S.at(i).paz) * 0.4 + S.at(i).egz * 0.6;
		S.at(i).med = med(S.at(i).paz) * 0.4 + S.at(i).egz * 0.6;
		cout << endl;
	}
}

void inputlist(list<stud>& S, int i)
{
	stud studentas;
	string tempc;
	cout << "iveskite studento nr. " << i + 1 << " duomenis:\n";
	do {
		cout << "iveskite studento nr. " << i + 1 << " varda:\n";
		cin >> studentas.Vard;
	} while (studentas.Vard.length() < 0 && studentas.Vard.length() > 25 || has_digit(studentas.Vard));
	do {
		cout << "iveskite studento nr. " << i + 1 << " pav:\n";
		cin >> studentas.Pav;
	} while (studentas.Pav.length() < 0 && studentas.Pav.length() > 25 || has_digit(studentas.Pav));
	do
	{
		cout << "jeigu norite, kad studento pazymiai butu suvesti automatiskai - spauskite \"r\"\n jeigu norite suvesti duomenis patys - rasykite \"p\"\n";
		cin >> tempc;
		if (tempc != "r" && tempc != "R" && tempc != "p" && tempc != "P") {
			cout << "pakartokite, netinkamas simbolis\n";
		}
	} while (tempc != "r" && tempc != "R" && tempc != "p" && tempc != "P");
	if (tempc == "p" || tempc == "P")
	{
		int temp, egz;
		cout << "iveskite studento pazymius (kai baigsite, iveskite -1 (minus vienas)):";
		cin >> temp;
		while (temp != -1) {
			studentas.paz.push_back(temp);
			cin >> temp;
		}
		do {
			cout << "iveskite studento egz:\n";
			cin >> egz;
			studentas.egz = egz;
		} while (egz < 0 || egz > 10);
		studentas.gal = vid(studentas.paz) * 0.4 + studentas.egz * 0.6;
		studentas.med = med(studentas.paz) * 0.4 + studentas.egz * 0.6;
		S.push_back(studentas);
		cout << endl;
	}
	else
	{
		studentas.egz = randompaz();
		for (int j = 0; j < 5; j++)
		{
			studentas.paz.push_back(randompaz());
		}
		studentas.gal = vid(studentas.paz) * 0.4 + studentas.egz * 0.6;
		studentas.med = med(studentas.paz) * 0.4 + studentas.egz * 0.6;
		S.push_back(studentas);
		cout << endl;
	}
}

bool compare(const stud& a, const stud& b)
{
	if (a.gal != b.gal)
		return a.gal > b.gal;
	if (a.med != b.med)
		return a.med > b.med;
	else if (a.Vard != b.Vard)
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
			S.at(studentas).gal = 0.4 * vid(S.at(studentas).paz) + 0.6 * S.at(studentas).egz;
			S.at(studentas).med = 0.4 * med(S.at(studentas).paz) + 0.6 * S.at(studentas).egz;
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
	cout << "Failo nuskaitymas su " + to_string(studentas) + " studentu/-ais uztruko(vek): " << diff.count() << "s\n";
	if (S.size() == 0)
		cout << "Negalima atidaryti failo arba jis tuscias." << endl;
}

void skaitymaslist(list<stud>& S, string failopavadinimas, int* kiek)
{
	auto start = chrono::high_resolution_clock::now();

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
			stud studentas;
			r >> studentas.Vard;
			if (r.eof())
			{
				break;
			}
			r >> studentas.Pav;
			for (int i = 0; i < *kiek; i++)
			{
				r >> temp;
				studentas.paz.push_back(temp);
			}
			r >> studentas.egz;
			studentas.gal = vid(studentas.paz) * 0.4 + studentas.egz * 0.6;
			studentas.med = med(studentas.paz) * 0.4 + studentas.egz * 0.6;
			S.push_back(studentas);
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
	cout << "Failo nuskaitymas su " + to_string(S.size()) + " studentu/-ais uztruko(list): " << diff.count() << "s\n";
	if (S.size() == 0)
		cout << "Negalima atidaryti failo arba jis tuscias." << endl;
}

bool kuriame(stud c)
{
	return c.gal < 5;
}

void studgrupvek1(vector<stud> studentai, vector<stud>& nuskriaustieji, vector<stud>& talentai)
{
	auto start = high_resolution_clock::now();
	for (int i = 0; i < studentai.size(); i++)
	{
		if (kuriame(studentai[i]))
			nuskriaustieji.push_back(studentai[i]);
		else
			talentai.push_back(studentai[i]);			
	}
	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "Studentu rusiavimas i 2 grupes uztruko(1 strategija, vector): " << diff.count() << "s\n";
}

void studgruplist1(list<stud>& studentai, list<stud>& nuskriaustieji, list<stud>& talentai)
{
	auto start = high_resolution_clock::now();
	list<stud>::iterator it = studentai.begin();
	while (it != studentai.end())
	{
		if (kuriame(*it))
			nuskriaustieji.push_back(*it);
		else
			talentai.push_back(*it);

		++it;
	}
	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "Studentu rusiavimas i 2 grupes uztruko(1 strategija, list): " << diff.count() << "s\n";
}

void studgrupvek2(vector<stud>& studentai, vector<stud>& nuskriaustieji)
{
	auto start = high_resolution_clock::now();
	vector<stud>::iterator it = studentai.end();
	--it;
	while(it >= studentai.begin())
	{
		if (kuriame(*it))
		{
			nuskriaustieji.push_back(*it);
			it = studentai.erase(it);
			--it;
		}
		else
			--it;
	}
	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "Studentu rusiavimas i 2 grupes uztruko(2 strategija, vector): " << diff.count() << "s\n";
}

void studgruplist2(list<stud>& studentai, list<stud>& nuskriaustieji)
{
	auto start = high_resolution_clock::now();
	list<stud>::iterator it = studentai.begin();
	while (it != studentai.end())
	{
		if (kuriame(*it))
		{
			nuskriaustieji.push_back(*it);
			studentai.erase(it++);
		}
		else
			++it;
	}
	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "Studentu rusiavimas i 2 grupes uztruko(2 strategija, list): " << diff.count() << "s\n";
}

void studgrupvekopt(vector<stud>& studentai, vector<stud>& nuskriaustieji)
{
	auto start = high_resolution_clock::now();
	vector<stud>::iterator it = find_if(studentai.begin(), studentai.end(), kuriame);
	if (it != studentai.end()) {
		copy(it, studentai.end(), back_inserter(nuskriaustieji));
	}
	studentai.resize(studentai.size() - nuskriaustieji.size());
	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "Studentu rusiavimas i 2 grupes uztruko(3 strategija, vector): " << diff.count() << "s\n";
}

void studgruplistopt(list<stud>& studentai, list<stud>& nuskriaustieji)
{
	auto start = high_resolution_clock::now();
	list<stud>::iterator it = find_if(studentai.begin(), studentai.end(), kuriame);
	if (it != studentai.end()) {
		copy(it, studentai.end(), back_inserter(nuskriaustieji));
	}
	studentai.resize(studentai.size() - nuskriaustieji.size());
	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "Studentu rusiavimas i 2 grupes uztruko(3 strategija, list): " << diff.count() << "s\n";
}


void isvedimas(string failo_pavadinimas, vector<stud> S)
{
	auto matavimo_pradzia = high_resolution_clock::now();

	ofstream stud_failas(failo_pavadinimas);

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

void isvedimaslist(string failo_pavadinimas, list<stud> S)
{
	auto matavimo_pradzia = high_resolution_clock::now();

	ofstream stud_failas(failo_pavadinimas);
	list<stud>::iterator it;

	stud_failas << left << setw(25) << "Vardas" << setw(25) << "Pavarde" << setw(15) << "Gal.(vid)" << setw(15) << "Gal.(med)" << endl;

	it = S.begin();
	while (it != S.end()) {
		stud_failas << left << setw(25) << it->Vard << left << setw(25) << it->Pav
			<< setw(15) << setprecision(3) << it->gal << setw(15) << setprecision(3) << it->med << endl;
		it++;
	}

	stud_failas.close();

	auto matavimo_pabaiga = high_resolution_clock::now();
	duration<double> skirtumas = matavimo_pabaiga - matavimo_pradzia;
	cout << "Failo " + failo_pavadinimas + " kurimas uztruko: " << skirtumas.count() << "s\n";
}
