#include "build_lib.h";
#include "stud.h";
#include "vidmed.h"

using namespace std;

void vid(stud& studentai)
{
    int pazymiu_suma = accumulate(studentai.paz.begin(), studentai.paz.end(), 0);
    int pazymiu_vidurkis = pazymiu_suma / studentai.paz.size();
    studentai.gal = 0.4 * pazymiu_vidurkis + 0.6 * studentai.egz;
}
void med(stud& s)
{
    vector<int> pazymiai;
    for (int i = 0; i < s.paz.size(); i++)
    {
        pazymiai.push_back(s.paz[i]);
    }
    pazymiai.push_back(s.egz);
    sort(pazymiai.begin(), pazymiai.end());

    float mediana;

    if (pazymiai.size() == 0)
    {
        mediana = 0;
    }
    else if (pazymiai.size() % 2 == 0)
    {
        mediana = (pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1]) / 2.0;
    }
    else
    {
        mediana = pazymiai[(pazymiai.size() - 1) / 2];
    }
    s.med = 0.4 * mediana + 0.6 * s.egz;
}
