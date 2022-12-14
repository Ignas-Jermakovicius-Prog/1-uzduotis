#include "vidmed.h"
#include "generavimas.h"
#include "build_lib.h"

using namespace std;

void kadarytvek(string raide)
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
			int pazskc;
			auto startviso = chrono::high_resolution_clock::now();
			skaitymas(studentai, "studentai" + to_string(kiek) + ".txt", &pazskc);
			sort(studentai.begin(), studentai.end(), compare);

			vector<stud> talentai;
			vector<stud> nuskriaustieji;

			auto start = high_resolution_clock::now();

			for (int i = 0; i < studentai.size(); i++)
			{
				if (studentai[i].gal >= 5)
					talentai.push_back(studentai[i]);
				else
					nuskriaustieji.push_back(studentai[i]);
			}
			auto end = high_resolution_clock::now();
			duration<double> diff = end - start;
			cout << "Studentu rusiavimas i 2 grupes uztruko : " << diff.count() << "s\n";

			isvedimas("talentai" + to_string(kiek) + ".txt", talentai);
			isvedimas("nuskriaustieji" + to_string(kiek) + ".txt", nuskriaustieji);

			auto endviso = high_resolution_clock::now();
			duration<double> diffviso = endviso - startviso;
			cout << "Testas su " << kiek << " studentu/-ais uztruko: " << diffviso.count() << "s\n\n\n";
			kiek *= 10;
		}
	}
	else if (raide == "f" || raide == "F")
	{
		vector<stud> studentai;
		int pazskc;
		string failas;
		cout << "Iveskite failo pavadinima (be .txt)\n";
		cin >> failas;
		auto startviso = chrono::high_resolution_clock::now();
		skaitymas(studentai, failas + ".txt", &pazskc);
		if (studentai.size() == 0)
			return;
		sort(studentai.begin(), studentai.end(), compare);

		vector<stud> talentai;
		vector<stud> nuskriaustieji;

		auto start = high_resolution_clock::now();

		for (int i = 0; i < studentai.size(); i++)
		{
			if (studentai[i].gal >= 5)
				talentai.push_back(studentai[i]);
			else
				nuskriaustieji.push_back(studentai[i]);
		}
		auto end = high_resolution_clock::now();
		duration<double> diff = end - start;
		cout << "Studentu rusiavimas i 2 grupes uztruko : " << diff.count() << "s\n";

		isvedimas("talentai" + to_string(studentai.size()) + ".txt", talentai);
		isvedimas("nuskriaustieji" + to_string(studentai.size()) + ".txt", nuskriaustieji);

		auto endviso = high_resolution_clock::now();
		duration<double> diffviso = endviso - startviso;
		cout << "Testas su " << studentai.size() << " studentu/-ais uztruko: " << diffviso.count() << "s" << endl;
	}
	else
	{
		string tempc;
		vector<stud> studentai;
		int studentu_sk;
		do
		{
			cout << "iveskite studentu kieki:\n";
			cin >> studentu_sk;
		} while (int(studentu_sk) < 0 || int(studentu_sk) > 256);
		studentai.resize(studentai.size() + studentu_sk);
		for (int i = 0; i < studentu_sk; i++)
		{
			input(studentai, i);
		}
		sort(studentai.begin(), studentai.end(), compare);

		auto startviso = chrono::high_resolution_clock::now();

		vector<stud> talentai;
		vector<stud> nuskriaustieji;

		auto start = high_resolution_clock::now();

		for (int i = 0; i < studentai.size(); i++)
		{
			if (studentai[i].gal >= 5)
				talentai.push_back(studentai[i]);
			else
				nuskriaustieji.push_back(studentai[i]);
		}
		auto end = high_resolution_clock::now();
		duration<double> diff = end - start;
		cout << "Studentu rusiavimas i 2 grupes uztruko : " << diff.count() << "s\n";

		isvedimas("talentai" + to_string(studentai.size()) + ".txt", talentai);
		isvedimas("nuskriaustieji" + to_string(studentai.size()) + ".txt", nuskriaustieji);

		auto endviso = high_resolution_clock::now();
		duration<double> diffviso = endviso - startviso;
		cout << "Testas su " << studentai.size() << " studentu/-ais uztruko: " << diffviso.count() << "s" << endl << endl;
	}
}