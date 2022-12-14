#include "build_lib.h"
#include "stud.h"
#include "generavimas.h"
#include "kadarytlist.h"
#include "kadarytvek.h"
#include "kadarytabiem.h"

using namespace std;

int main()
{
	string raide;
	int strategija;
	cout << "Jeigu norite atlikti testa naudojant 1 strategija, rasykite 1\nJeigu norite atlikti testa naudojant 2 strategija, rasykite 2\nJeigu norite atlikti testa naudojant 3 (optimizuota) strategija, rasykite 3\n";
	do
	{
		cin >> strategija;
		if (strategija != 1 && strategija != 2 && strategija != 3)
		{
			cout << "pakartokite, netinkamas simbolis\n";
		}
	} while (strategija != 1 && strategija != 2 && strategija != 3);
	cout << "Jeigu norite, kad studentai bei ju pazymiai butu sugeneruoti atsitiktinai - rasykite \"r\"\nJeigu norite duomenis nuskaityti is failo- rasykite \"f\"\nJeigu norite duomenis irasyti ranka - rasykite \"p\"\n";
	do
	{
		cin >> raide;
		if (raide != "r" && raide != "R" && raide != "F" && raide != "f" && raide != "p" && raide != "P")
		{
			cout << "pakartokite, netinkamas simbolis\n";
		}
	} while (raide != "r" && raide != "R" && raide != "F" && raide != "f" && raide != "p" && raide != "P");
	if (raide == "F" || raide == "f")
	{
		string kont;
		cout << "Jeigu testui norite naudoti list konteineri,rasykite \"l\"\nJeigu testui norite naudoti vector konteineri- rasykite \"v\"\nJeigu norite palyginti list ir vector veikimo sparta - rasykite \"b\"\n";
		do
		{
			cin >> kont;
			if (kont != "l" && kont != "L" && kont != "v" && kont != "V" && kont != "b" && kont != "B")
			{
				cout << "pakartokite, netinkamas simbolis\n";
			}
		} while (kont != "l" && kont != "L" && kont != "v" && kont != "V" && kont != "b" && kont != "B");
		if (kont == "l" || kont == "L")
			kadarytlist(raide, strategija);
		else if (kont == "v" || kont == "V")
			kadarytvek(raide,strategija);
		else
			kadarytabiem(strategija);
	}
	else if (raide == "r" || raide == "R")
	{
		string kont;
		cout << "Jeigu generavimui norite naudoti list konteineri,rasykite \"l\"\nJeigu generavimui norite naudoti vector konteineri- rasykite \"v\"\n";
		do
		{
			cin >> kont;
			if (kont != "l" && kont != "L" && kont != "v" && kont != "V")
			{
				cout << "pakartokite, netinkamas simbolis\n";
			}
		} while (kont != "l" && kont != "L" && kont != "v" && kont != "V");
		if (kont == "l" || kont == "L")
			kadarytlist(raide, strategija);
		else
			kadarytvek(raide,strategija);
	}
	else
	{
		string kont;
		cout << "Jeigu testui norite naudoti list konteineri,rasykite \"l\"\nJeigu testui norite naudoti vector konteineri- rasykite \"v\"\n";
		do
		{
			cin >> kont;
			if (kont != "l" && kont != "L" && kont != "v" && kont != "V")
			{
				cout << "pakartokite, netinkamas simbolis\n";
			}
		} while (kont != "l" && kont != "L" && kont != "v" && kont != "V");
		if (kont == "l")
			kadarytlist(raide, strategija);
		else
			kadarytvek(raide, strategija);
	}
	return 0;
}
