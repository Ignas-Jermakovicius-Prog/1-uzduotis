#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include "printStudent.h"
#include "countMedian.h"
using namespace std;

void printStudent(vector<stud> S, int pazkiek) //funkcija atspausdinanti rezultatus
{
    ofstream out;
    out.open("rez.txt");
    out << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(20) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < S.size(); i++)
    {
        out << setw(20) << left << S[i].Vard
            << setw(20) << left << S[i].Pav
            << setw(20) << left << S[i].gal
            << countMedian(S[i].paz) << endl;
    }
}