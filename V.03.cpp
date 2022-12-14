#include "vidmed.h"
#include "generavimas.h"
#include "build_lib.h"
#include "kadaryt.h";

using namespace std;

int main()
{
	string raide;
	cout << "Jeigu norite, kad studentai bei ju pazymiai butu sugeneruoti atsitiktinai - spauskite \"r\"\nJeigu norite duomenis nuskaityti is failo- rasykite \"f\"\nJeigu norite duomenis irasyti ranka - rasykite \"p\"\n";
	do
	{	
		cin >> raide;
		if (raide != "r" && raide != "R" && raide != "F" && raide != "f" && raide != "p" && raide != "P") 
		{
			cout << "pakartokite, netinkamas simbolis\n";
		}
	} while (raide != "r" && raide != "R" && raide != "F" && raide != "f" && raide != "p" && raide != "P");
	kadaryt(raide);
	return 0;
}