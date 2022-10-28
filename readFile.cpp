#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iterator>
#include "readFile.h"
#include "countWords.h"
using namespace std;

void readFile(vector<stud>& S, int* paz) // failo nuskaitymo funkcija
{
    int studentas = 0;
    int temp;
    string eile;
    ifstream fileRead;
    try {
        fileRead.open("duom.txt");
        if (!fileRead.is_open())
            throw 0;
        if (fileRead.is_open())
        {
            getline(fileRead >> ws, eile);
            *paz = countWords(eile) - 3; // randa kiek stringe yra pažymių
            while (true)
            {

                S.resize(S.size() + 1);
                fileRead >> S.at(studentas).Vard;
                if (fileRead.eof()) { S.pop_back(); break; }
                fileRead >> S.at(studentas).Pav;
              for (int i = 0; i < *paz; i++)
                {
                    fileRead >> temp;
                    S.at(studentas).paz.push_back(temp);
                    sum = sum + temp;
                }
                fileRead >> S.at(studentas).egz;
                S.at(studentas).gal = 0.4 * accumulate(S.at(studentas).paz.begin(),S.at(studentas).paz.end(),0)/(S.at(studentas).paz.size()) 
                                      + 0.6 * S.at(studentas).egz;
                studentas++;
            }
        }
    }
    catch (int e)
    {
        cout << "Neteisingai ivestas failo pavadinimas " << endl;

    }
}
