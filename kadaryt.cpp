#include "vidmed.h"
#include "generavimas.h"
#include "build_lib.h"

using namespace std;

void kadaryt(string raide)
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
			auto startviso = chrono::high_resolution_clock::now();
			vector<stud> studentai;
			int pazskc;
			skaitymas(studentai, "studentai" + to_string(kiek) + ".txt", &pazskc);

			auto startsort = high_resolution_clock::now();
			sort(studentai.begin(), studentai.end(), compare);
			auto endsort = high_resolution_clock::now();
			duration<double> diffsort = endsort - startsort;
			cout << studentai.size() << " studentu rusiavimas didejimo tvarka laikas : " << diffsort.count() << "s\n";

			auto start = high_resolution_clock::now();

			vector<stud> talentai;
			vector<stud> nuskriaustieji;

			for (int i = 0; i < studentai.size(); i++)
			{
				studentai[i].gal = 0.4 * vid(studentai[i].paz) + 0.6 * studentai[i].egz;
				studentai[i].med = 0.4 * med(studentai[i].paz) + 0.6 * studentai[i].egz;

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

		auto startsort = high_resolution_clock::now();
		sort(studentai.begin(), studentai.end(), compare);
		auto endsort = high_resolution_clock::now();
		duration<double> diffsort = endsort - startsort;
		cout << studentai.size() << " studentu rusiavimas didejimo tvarka laikas : " << diffsort.count() << "s\n";

		auto start = high_resolution_clock::now();

		vector<stud> talentai;
		vector<stud> nuskriaustieji;

		for (int i = 0; i < studentai.size(); i++)
		{
			studentai[i].gal = 0.4 * vid(studentai[i].paz) + 0.6 * studentai[i].egz;
			studentai[i].med = 0.4 * med(studentai[i].paz) + 0.6 * studentai[i].egz;

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
		int paz;
		int studentu_sk;
		do
		{
			cout << "iveskite studentu kieki:\n";
			cin >> studentu_sk;
		} while (int(studentu_sk) < 0 || int(studentu_sk) > 256);
		studentai.resize(studentai.size() + studentu_sk);
		do
		{
			cout << "jeigu norite, kad studentu pazymiai butu suvesti automatiskai - spauskite \"r\"\n jeigu norite suvesti duomenis patys - rasykite \"p\"\n";
			cin >> tempc;
			if (tempc != "r" && tempc != "R" && tempc != "p" && tempc != "P") {
				cout << "pakartokite, netinkamas simbolis\n";
			}
		} while (tempc != "r" && tempc != "R" && tempc != "p" && tempc != "P");
		for (int i = 0; i < studentu_sk; i++)
		{
			name_input(studentai, i);
			if (tempc == "p" || tempc == "P") {
				input(studentai, i);
			}
			else {
				autopaz(studentai, i, 5);
			}
			paz = studentai.at(i).paz.size();
		}
		auto startviso = chrono::high_resolution_clock::now();

		auto startsort = high_resolution_clock::now();
		sort(studentai.begin(), studentai.end(), compare);
		auto endsort = high_resolution_clock::now();
		duration<double> diffsort = endsort - startsort;
		cout << studentai.size() << " studentu rusiavimas didejimo tvarka laikas : " << diffsort.count() << "s\n";

		auto start = high_resolution_clock::now();

		vector<stud> talentai;
		vector<stud> nuskriaustieji;

		for (int i = 0; i < studentai.size(); i++)
		{
			studentai[i].gal = 0.4 * vid(studentai[i].paz) + 0.6 * studentai[i].egz;
			studentai[i].med = 0.4 * med(studentai[i].paz) + 0.6 * studentai[i].egz;

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