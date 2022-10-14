#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iterator>
#include <stdlib.h>
#include <numeric>
#include <chrono>
#include "genrandom.h"
#include "genpaz.h"
using namespace std;

vector<int> genpaz(int pazkiek)
{
	vector<int> skaiciai;
	for (int i = 0; i < pazkiek; i++)
	{
		skaiciai.push_back(genrandom());
	}
	return skaiciai;

}