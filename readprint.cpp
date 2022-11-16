#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <numeric>
#include "readprint.h"
#include "wordsmedian.h"
#include "build.lib.h"
using namespace std;

int randompaz()
{
    mt19937 mt(static_cast<long unsigned int>(high_resolution_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> dist(1, 10);
    return dist(mt);
}

bool has_digit(string s)
{
    return (s.find_first_of("0123456789") != string::npos);
}

void input(vector<stud>& S, int i)
{
    cout << "iveskite studento nr. " << i + 1 << " duomenis:\n";
    do {
        cout << "iveskite studento nr. " << i + 1 << " varda:\n";
        cin >> S.at(i).Vard;
    } while (S.at(i).Vard.length() < 0 || S.at(i).Vard.length() > 25 || has_digit(S.at(i).Vard));
    do {
        cout << "iveskite studento nr. " << i + 1 << " pav:\n";
        cin >> S.at(i).Pav;
    } while (S.at(i).Pav.length() < 0 && S.at(i).Pav.length() > 25 || has_digit(S.at(i).Pav));
    cout << endl;
    string temp;
    do
    {
        cout << "jeigu norite, kad studento pazymiai butu suvesti automatiskai - spauskite \"r\"\n jeigu norite suvesti duomenis patys - rasykite \"p\"\n";
        cin >> temp;
        if (temp != "r" && temp != "R" && temp != "p" && temp != "P") {
            cout << "pakartokite, netinkamas simbolis\n";
        }
    } while (temp != "r" && temp != "R" && temp != "p" && temp != "P");
    if (temp == "p" || temp == "P")
    {
        int temps, egz;
        cout << "iveskite studento pazymius (kai baigsite, iveskite -1 (minus vienas)):";
        cin >> temps;
        while (temps != -1) {
            S.at(i).paz.push_back(temps);
            cin >> temps;
        }
        do {
            cout << "iveskite studento egz:\n";
            cin >> egz;
            S.at(i).egz = egz;
        } while (egz < 0 || egz > 10);
        S.at(i).gal = vid(S.at(i).paz) * 0.4 + S.at(i).egz * 0.6;
        S.at(i).med = med(S.at(i).paz) * 0.4 + S.at(i).egz * 0.6;
    }
    else
    {
        S.at(i).egz = randompaz();
        for (int j = 0; j < 5; j++)
        {
            S.at(i).paz.push_back(randompaz());
        }
        S.at(i).gal = vid(S.at(i).paz) * 0.4 + S.at(i).egz * 0.6;
        S.at(i).med = med(S.at(i).paz) * 0.4 + S.at(i).egz * 0.6;
    }
}

void readFile(vector<stud>& S, int* paz) // failo nuskaitymo funkcija
{
    int studentas = 0;
    int temp;
    string tempc;
    string eile, failas;
    ifstream fileRead;
    try {
        do {
            cout << "jeigu norite, kad studentai butu skaitomi is failo - spauskite \"f\"\n jeigu norite suvesti duomenis patys - rasykite \"p\"\n";
            cin >> tempc;
            if (tempc != "f" && tempc != "F" && tempc != "p" && tempc != "P") {
                cout << "pakartokite, netinkamas simbolis\n";
            }
        } while (tempc != "f" && tempc != "F" && tempc != "p" && tempc != "P");
        if (tempc != "p" && tempc != "P")
        {
            cout << "Iveskite failo pavadinima\n";
            cin >> failas;
            fileRead.open(failas);
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
                    if (fileRead.eof()) {
                        S.pop_back();
                        break;
                    }
                    fileRead >> S.at(studentas).Pav;
                    int sum = 0;
                    for (int i = 0; i < *paz; i++)
                    {
                        fileRead >> temp;
                        S.at(studentas).paz.push_back(temp);
                        sum = sum + temp;
                    }
                    fileRead >> S.at(studentas).egz;
                    S.at(studentas).gal = 0.4 * vid(S.at(studentas).paz) + 0.6 * S.at(studentas).egz;
                    S.at(studentas).med = 0.4 * med(S.at(studentas).paz) + 0.6 * S.at(studentas).egz;
                    studentas++;
                }
            }
        }
        else
        {
            int studentu_sk;
            do
            {
                cout << "iveskite studentu kieki:\n";
                cin >> studentu_sk;
            } while (int(studentu_sk) < 0 || int(studentu_sk) > 256);
            S.resize(S.size() + studentu_sk);
            for (int i = 0; i < studentu_sk; i++)
            {
                input(S, i);
                *paz = S.at(i).paz.size();
            }
        }
    }
        
    catch (int e)
    {
        cout << "Neteisingai ivestas failo pavadinimas " << endl;

    }
        
}
bool compare(const stud& a, const stud& b)
{
    if (a.Vard != b.Vard)
        return a.Vard < b.Vard;
    else
        return a.Pav < b.Pav;
}

void printStudent(vector<stud> S, int pazkiek) //funkcija atspausdinanti rezultatus
{

    ofstream out;
    out.open("rez.txt");
    out << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(20) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    sort(S.begin(), S.end(), compare);
    for (int i = 0; i < S.size(); i++)
    {
        out << setw(20) << left << S[i].Vard
            << setw(20) << left << S[i].Pav
            << setw(20) << left << setprecision(3) << S[i].gal
            << setw(20) << left << setprecision(3) << S[i].med << endl;
    }
}
