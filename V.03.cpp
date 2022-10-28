#include "vidmed.h"
#include "generavimas.h"
#include "build_lib.h"

using namespace std;


int main()
{

	int kiek = 1000;
	for (int i = 0; i < 5; i++)
	{
		auto startviso = chrono::high_resolution_clock::now();
		failogeneravimas(kiek);
		vector<stud> studentai;
		int pazskc;
		skaitymas(studentai, "studentai_" + to_string(kiek) + ".txt", &pazskc);

		auto start = high_resolution_clock::now();

		vector<stud> talentai;
		vector<stud> nuskriaustieji;

		for (int i = 0; i < studentai.size(); i++)
		{
			stud laikstud = studentai[i];
			vid(laikstud);
			med(laikstud);
			
			if (laikstud.gal >= 5)
				talentai.push_back(laikstud);
			else
				nuskriaustieji.push_back(laikstud);
		}
		auto end = high_resolution_clock::now();
		duration<double> diff = end - start;
		cout << "Studentu rusiavimas i 2 grupes uztruko : " << diff.count() << "s\n";
		
		isvedimas("talentai" + to_string(kiek) + ".txt", talentai);
		isvedimas("nuskriaustieji" + to_string(kiek) + ".txt", nuskriaustieji);

		auto endviso = high_resolution_clock::now();
		duration<double> diffviso = endviso - startviso;
		cout << "Testas su " << kiek << " studentu uztruko: " << diffviso.count() << "s" << endl << endl;
		kiek *= 10;
	}
	cout << endl;
}
