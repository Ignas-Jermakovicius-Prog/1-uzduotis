#include "countWords.h"
#include "stud.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include "countWords.h"
using namespace std;

int countWords(string const& str) // funkcija randanti žodžių (simbolių) atskirtų tarpais skaičius eiluteje
{
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}