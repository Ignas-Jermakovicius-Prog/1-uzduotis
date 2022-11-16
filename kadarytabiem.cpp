#include "stud.h"
#include "build_lib.h"
#include "generavimas.h"

using namespace std;

void kadarytabiem(string raide)
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
			vector<stud> studentai;
			list<stud> studentail;

			int pazskc;
			skaitymas(studentai, "studentai" + to_string(kiek) + ".txt", &pazskc);
			sort(studentai.begin(), studentai.end(), compare);
			skaitymaslist(studentail, "studentai" + to_string(kiek) + ".txt", &pazskc);
			studentail.sort(compare);

			vector<stud> talentai;
			vector<stud> nuskriaustieji;

			auto startvek = high_resolution_clock::now();

			for (int i = 0; i < studentai.size(); i++)
			{
				if (studentai[i].gal >= 5)
					talentai.push_back(studentai[i]);
				else
					nuskriaustieji.push_back(studentai[i]);
			}
			auto endvek = high_resolution_clock::now();
			duration<double> diffvek = endvek - startvek;
			cout << "Studentu rusiavimas i 2 grupes uztruko(vector): " << diffvek.count() << "s\n";

			list<stud> talentail;
			list<stud> nuskriaustiejil;
			list<stud>::iterator it;

			auto startlist = high_resolution_clock::now();

			for (it = studentail.begin(); it != studentail.end(); it++)
			{
				if ((*it).gal >= 5)
					talentail.push_back(*it);
				else
					nuskriaustiejil.push_back(*it);
			}
			auto endlist = high_resolution_clock::now();
			duration<double> difflist = endlist - startlist;
			cout << "Studentu rusiavimas i 2 grupes uztruko(list): " << difflist.count() << "s\n";

			isvedimas("talentai" + to_string(kiek) + ".txt", talentai);
			isvedimas("nuskriaustieji" + to_string(kiek) + ".txt", nuskriaustieji);
			cout << endl;

			kiek *= 10;
		}
	}
	else if (raide == "f" || raide == "F")
	{
		vector<stud> studentai;
		list<stud> studentail;
		int pazskc;
		string failas;
		cout << "Iveskite failo pavadinima (be .txt)\n";
		cin >> failas;

		skaitymas(studentai, failas + ".txt", &pazskc);
		skaitymaslist(studentail, failas + ".txt", &pazskc);
		if (studentail.size() == 0)
			return;

		sort(studentai.begin(), studentai.end(), compare);
		studentail.sort(compare);

		vector<stud> talentai;
		vector<stud> nuskriaustieji;

		auto startvek = high_resolution_clock::now();

		for (int i = 0; i < studentai.size(); i++)
		{
			if (studentai[i].gal >= 5)
				talentai.push_back(studentai[i]);
			else
				nuskriaustieji.push_back(studentai[i]);
		}
		auto endvek = high_resolution_clock::now();
		duration<double> diffvek = endvek - startvek;
		cout << "Studentu rusiavimas i 2 grupes uztruko(vector): " << diffvek.count() << "s\n";

		list<stud> talentail;
		list<stud> nuskriaustiejil;
		list<stud>::iterator it;

		auto startlist = high_resolution_clock::now();

		for (it = studentail.begin(); it != studentail.end(); it++)
		{
			if ((*it).gal >= 5)
				talentail.push_back(*it);
			else
				nuskriaustiejil.push_back(*it);
		}
		auto endlist = high_resolution_clock::now();
		duration<double> difflist = endlist - startlist;
		cout << "Studentu rusiavimas i 2 grupes uztruko(list): " << difflist.count() << "s\n";

		isvedimaslist("talentai" + to_string(studentail.size()) + ".txt", talentail);
		isvedimaslist("nuskriaustieji" + to_string(studentail.size()) + ".txt", nuskriaustiejil);
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
		auto startviso = chrono::high_resolution_clock::now();

		auto startsort = high_resolution_clock::now();
		studentai.sort(compare);
		auto endsort = high_resolution_clock::now();
		duration<double> diffsort = endsort - startsort;
		cout << studentai.size() << " studentu rusiavimas didejimo tvarka laikas : " << diffsort.count() << "s\n";

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