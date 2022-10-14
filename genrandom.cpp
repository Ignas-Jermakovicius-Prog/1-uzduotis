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
using namespace std;

int genrandom()
{
	return rand() % 10 + 1;
}
