#include "stud.h"
#include "build_lib.h"
#include "generavimas.h"

using namespace std;

void kadarytabiem(int strategija)
{
	vector<stud> studentai;
	list<stud> studentail;
	int pazskc;

	string failas;

	cout << "Iveskite failo pavadinima (be .txt)\n";
	cin >> failas;

	skaitymas(studentai, failas + ".txt", &pazskc);
	if (studentai.size() == 0)
		return;
	sort(studentai.begin(), studentai.end(), compare);

	skaitymaslist(studentail, failas + ".txt", &pazskc);
	if (studentail.size() == 0)
		return;
	studentail.sort(compare);

	int a = studentai.size();

	if (strategija == 1)
	{
		vector<stud> talentai;
		vector<stud> nuskriaustieji;

		list<stud> talentail;
		list<stud> nuskriaustiejil;

		studgrupvek1(studentai, nuskriaustieji, talentai);
		studgruplist1(studentail, nuskriaustiejil, talentail);

		//isvedimaslist("talentai" + to_string(a) + ".txt", talentail);
		//isvedimaslist("nuskriaustieji" + to_string(a) + ".txt", nuskriaustiejil);

	}

	else if (strategija == 2)
	{
		vector<stud> nuskriaustieji;
		list<stud> nuskriaustiejil;

		studgrupvek2(studentai, nuskriaustieji);
		studgruplist2(studentail, nuskriaustiejil);

		//isvedimas("talentai" + to_string(a) + ".txt", studentai);
		//isvedimas("nuskriaustieji" + to_string(a) + ".txt", nuskriaustieji);
	}

	else
	{
		vector<stud> nuskriaustieji;
		list<stud> nuskriaustiejil;

		studgrupvekopt(studentai, nuskriaustieji);
		studgruplistopt(studentail, nuskriaustiejil);

		//isvedimaslist("talentai" + to_string(a) + ".txt", studentail);
		//isvedimaslist("nuskriaustieji" + to_string(a) + ".txt", nuskriaustiejil);
	}
}
