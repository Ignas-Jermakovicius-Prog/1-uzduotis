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
#include "stud.h"
#include "countgal.h"

using namespace std;

float countgal(vector<int> skaiciai) {
	stud S;
	S.gal = 0.4 * accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * genrandom();
	return S.gal;
}