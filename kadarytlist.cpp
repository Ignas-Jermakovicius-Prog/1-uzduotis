#include "stud.h"
#include "build_lib.h"
#include "generavimas.h"

using namespace std;

void kadarytlist(string raide)
{
	if (raide == "r" || raide == "R")
	{
		int kiek = 1000;
		char failsk;
		cout << "Kiek norite sukurti failu?\n";
		do
		{
			cin >> failsk;
			if (!isdigit(failsk) || int(failsk) - 48 == 0)
			{
				cout << "pakartokite, netinkamas simbolis\n";
			}
			else if (int(failsk) - 48 > 5)
				cout << "Pakartokite, negalima kurti daugiau negu 5 failu\n";
		} while (!isdigit(failsk) || int(failsk) - 48 > 5 || int(failsk) - 48 == 0);
		for (int i = 0; i < int(failsk) - 48; i++)
		{
			failogeneravimas(kiek);
			list<stud> studentai;
			int pazskc;
			auto startviso = chrono::high_resolution_clock::now();
			skaitymaslist(studentai, "studentai" + to_string(kiek) + ".txt", &pazskc);
			studentai.sort(compare);

			list<stud> talentai;
			list<stud> nuskriaustieji;
			list<stud>::iterator it;

			auto start = high_resolution_clock::now();

			for (it = studentai.begin(); it != studentai.end(); it++)
			{
				if ((*it).gal >= 5)
					talentai.push_back(*it);
				else
					nuskriaustieji.push_back(*it);
			}
			auto end = high_resolution_clock::now();
			duration<double> diff = end - start;
			cout << "Studentu rusiavimas i 2 grupes uztruko : " << diff.count() << "s\n";

			isvedimaslist("talentai" + to_string(kiek) + ".txt", talentai);
			isvedimaslist("nuskriaustieji" + to_string(kiek) + ".txt", nuskriaustieji);

			auto endviso = high_resolution_clock::now();
			duration<double> diffviso = endviso - startviso;
			cout << "Testas su " << kiek << " studentu/-ais uztruko: " << diffviso.count() << "s\n\n\n";
			kiek *= 10;
		}
	}
	else if (raide == "f" || raide == "F")
	{
		list<stud> studentai;
		int pazskc;
		string failas;
		cout << "Iveskite failo pavadinima (be .txt)\n";
		cin >> failas;

		auto startviso = chrono::high_resolution_clock::now();
		skaitymaslist(studentai, failas + ".txt", &pazskc);
		if (studentai.size() == 0)
			return;
		studentai.sort(compare);

		list<stud> talentai;
		list<stud> nuskriaustieji;
		list<stud>::iterator it;

		auto start = high_resolution_clock::now();

		for (it = studentai.begin(); it != studentai.end(); it++)
		{
			if ((*it).gal >= 5)
				talentai.push_back(*it);
			else
				nuskriaustieji.push_back(*it);
		}
		auto end = high_resolution_clock::now();
		duration<double> diff = end - start;
		cout << "Studentu rusiavimas i 2 grupes uztruko : " << diff.count() << "s\n";

		isvedimaslist("talentai" + to_string(studentai.size()) + ".txt", talentai);
		isvedimaslist("nuskriaustieji" + to_string(studentai.size()) + ".txt", nuskriaustieji);

		auto endviso = high_resolution_clock::now();
		duration<double> diffviso = endviso - startviso;
		cout << "Testas su " << studentai.size() << " studentu/-ais uztruko: " << diffviso.count() << "s" << endl << endl;
	}
	else
	{
		string tempc;
		list<stud> studentai;
		int studentu_sk;
		do
		{
			cout << "iveskite studentu kieki:\n";
			cin >> studentu_sk;
		} while (int(studentu_sk) < 0 || int(studentu_sk) > 256);
		for (int i = 0; i < studentu_sk; i++)
		{
			inputlist(studentai, i);
		}
		studentai.sort(compare);

		auto startviso = chrono::high_resolution_clock::now();

		list<stud> talentai;
		list<stud> nuskriaustieji;
		list<stud>::iterator it;

		auto start = high_resolution_clock::now();

		for (it = studentai.begin(); it != studentai.end(); it++)
		{
			if ((*it).gal >= 5)
				talentai.push_back(*it);
			else
				nuskriaustieji.push_back(*it);
		}
		auto end = high_resolution_clock::now();
		duration<double> diff = end - start;
		cout << "Studentu rusiavimas i 2 grupes uztruko : " << diff.count() << "s\n";

		isvedimaslist("talentai" + to_string(studentai.size()) + ".txt", talentai);
		isvedimaslist("nuskriaustieji" + to_string(studentai.size()) + ".txt", nuskriaustieji);

		auto endviso = high_resolution_clock::now();
		duration<double> diffviso = endviso - startviso;
		cout << "Testas su " << studentai.size() << " studentu/-ais uztruko: " << diffviso.count() << "s" << endl << endl;
	}
}