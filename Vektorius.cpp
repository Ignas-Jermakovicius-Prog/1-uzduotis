#include "build_lib.h"

using namespace std;

struct stud {
    string Vard, Pav;
    vector<int> paz;
    int egz;
    float gal;
    float med;
};

float vid(vector<int> paz)
{
    int pazymiu_suma = accumulate(paz.begin(), paz.end(), 0);
    int pazymiu_vidurkis = pazymiu_suma / paz.size();
    return pazymiu_vidurkis;
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

int randompaz()
{
    mt19937 mt(static_cast<long unsigned int>(high_resolution_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> dist(1, 10);
    return dist(mt);
}
void autopaz(vector<stud> S, int i, int pazkiek)
{
    S.at(i).egz = randompaz();
    for (int j = 0; j < pazkiek; j++)
    {
        S.at(i).paz.push_back(randompaz());
    }
    S.at(i).gal = vid(S.at(i).paz) * 0.6 + S.at(i).egz * 0.4;
    S.at(i).med = med(S.at(i).paz) * 0.6 + S.at(i).egz * 0.4;
}
void input(vector<stud>& S, int i)
{
    int temp, egz;
    cout << "Iveskite studento pazymius (kai baigsite, iveskite -1 (minus vienas)):";
    cin >> temp;
    while (temp != -1) {
        S.at(i).paz.push_back(temp);
        cin >> temp;
    }
    do {
        cout << "Iveskite studento EGZ:\n";
        cin >> egz;
        S.at(i).egz = egz;
    } while (egz < 0 || egz > 10);
    S.at(i).gal = vid(S.at(i).paz) * 0.6 + S.at(i).egz * 0.4;
    S.at(i).med = med(S.at(i).paz) * 0.6 + S.at(i).egz * 0.4;
}
bool has_digit(string s)
{
    return (s.find_first_of("0123456789") != string::npos);
}
void name_input(vector<stud>& S, int i)
{
    cout << "Iveskite studento nr. " << i + 1 << " duomenis:\n";
    do {
        cout << "Iveskite studento nr. " << i + 1 << " VARDA:\n";
        cin >> S.at(i).Vard;
    } while (S.at(i).Vard.length() < 0 || S.at(i).Vard.length() > 25 || has_digit(S.at(i).Vard));
    do {
        cout << "Iveskite studento nr. " << i + 1 << " PAV:\n";
        cin >> S.at(i).Pav;
    } while (S.at(i).Pav.length() < 0 && S.at(i).Pav.length() > 25 || has_digit(S.at(i).Pav));
    cout << endl;
}
void print_student(vector<stud> S, int studentu_sk) //atspausdina rezultatus
{
    cout << "\n\n";
    cout << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentu_sk; i++)
    {
        cout << setw(20) << left << S.at(i).Vard
            << setw(20) << left << S.at(i).Pav
            << setw(18) << left << S.at(i).gal
            << left << S.at(i).med << endl;
    }
    cout << "\n\n";
}

int main()
{
    int studentu_sk;
    string temp;
    do
    {
        cout << "Iveskite studentu kieki:\n";
        cin >> studentu_sk;
    } while (int(studentu_sk) < 0 || int(studentu_sk) > 256);
    vector<stud> S;
    S.resize(S.size() + studentu_sk);
    do
    {
        cout << "Jeigu norite, kad studentu pazymiai butu suvesti automatiskai - SPAUSKITE \"R\"\n Jeigu norite suvesti duomenis patys - RASYKITE \"P\"\n";
        cin >> temp;
        if (temp != "r" && temp != "R" && temp != "p" && temp != "P") {
            cout << "pakartokite, netinkamas simbolis\n";
        }
    } while (temp != "r" && temp != "R" && temp != "p" && temp != "P");
    for (int i = 0; i < studentu_sk; i++)
    {
        name_input(S, i);
        if (temp == "p" || temp == "P") {
            input(S, i);
        }
        else {
            autopaz(S, i, 5);
        }  
    }
    print_student(S, studentu_sk);
    system("pause");
    return 0;
}
