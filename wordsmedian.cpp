#include <numeric>
#include <algorithm>
#include <iterator>
#include <istream>
#include <string>
#include <vector>
#include <sstream>
#include "build.lib.h"
#include "wordsmedian.h"
using namespace std;

int countWords(string const& str) // funkcija randanti žodžių (simbolių) atskirtų tarpais skaičius eiluteje
{
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

float med(vector<int> paz) //funkcija skaiciuojanti mediana
{
    sort(paz.begin(), paz.end());

    float mediana;

    if (paz.size() == 0)
    {
        mediana = 0;
    }
    else if (paz.size() % 2 == 0)
    {
        mediana = (paz[paz.size() / 2] + paz[paz.size() / 2 - 1]) / 2.0;
    }
    else
    {
        mediana = paz[(paz.size() - 1) / 2];
    }
    return mediana;
}

float vid(vector<int> paz)
{
    float pazymiu_suma = accumulate(paz.begin(), paz.end(), 0);
    float pazymiu_vidurkis = pazymiu_suma / paz.size();
    return pazymiu_vidurkis;
}