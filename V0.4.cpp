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
	cout << "Jeigu norite, kad studentai bei ju pazymiai butu sugeneruoti atsitiktinai - rasykite \"r\"\nJeigu norite duomenis nuskaityti is failo- rasykite \"f\"\nJeigu norite duomenis irasyti ranka - rasykite \"p\"\n";
	do
	{
		cin >> raide;
		if (raide != "r" && raide != "R" && raide != "F" && raide != "f" && raide != "p" && raide != "P")
		{
			cout << "pakartokite, netinkamas simbolis\n";
		}
	} while (raide != "r" && raide != "R" && raide != "F" && raide != "f" && raide != "p" && raide != "P");
	if (raide == "r" || raide == "R" || raide == "F" || raide == "f")
	{
		string kont;
		cout << "Jeigu testui norite naudoti list konteineri,rasykite \"l\"\nJeigu testui norite naudoti vector konteineri- rasykite \"v\"\nJeigu norite palyginti list ir vector veikimo sparta - rasykite \"b\"\n";
		do
		{
			cin >> kont;
			if (kont != "l" && kont != "L" && kont != "v" && kont != "V" && kont != "b" && raide != "B")
			{
				cout << "pakartokite, netinkamas simbolis\n";
			}
		} while (kont != "l" && kont != "L" && kont != "v" && kont != "V" && kont != "b" && raide != "B");
		if (kont == "l" || kont == "L")
			kadarytlist(raide);
		else if (kont == "v" || kont == "V")
			kadarytvek(raide);
		else
			kadarytabiem(raide);
	}
	else
		kadarytabiem(raide);
	return 0;
}