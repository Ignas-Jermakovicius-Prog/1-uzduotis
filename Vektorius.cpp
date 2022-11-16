#include "build_lib.h"

using namespace std;

struct stud {
    string vard, pav;
    vector<int> paz;
    int egz;
    float gal;
    float med;
};

float vid(vector<int> paz)
{
    float pazymiu_suma = accumulate(paz.begin(), paz.end(), 0);
	  float pazymiu_vidurkis = pazymiu_suma / paz.size();
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
void autopaz(vector<stud>& S, int i, int pazkiek)
{
   
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
        cin >> S.at(i).vard;
    } while (S.at(i).vard.length() < 0 || S.at(i).vard.length() > 25 || has_digit(S.at(i).vard));
    do {
        cout << "iveskite studento nr. " << i + 1 << " pav:\n";
        cin >> S.at(i).pav;
    } while (S.at(i).pav.length() < 0 && S.at(i).pav.length() > 25 || has_digit(S.at(i).pav));
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

void name_input(vector<stud>& s, int i)
{
    
}
void print_student(vector<stud> s, int studentu_sk) //atspausdina rezultatus
{
    cout << "\n\n";
    cout << setw(20) << left << "vardas"
        << setw(20) << left << "pavarde"
        << setw(18) << left << "galutinis(vid.)/"
        << left << "galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentu_sk; i++)
    {
        cout << setw(20) << left << s.at(i).vard
            << setw(20) << left << s.at(i).pav
            << setw(18) << left << s.at(i).gal
            << left << s.at(i).med << endl;
    }
    cout << "\n\n";
}

int main()
{
    int studentu_sk;
    string temp;
    do
    {
        cout << "iveskite studentu kieki:\n";
        cin >> studentu_sk;
    } while (int(studentu_sk) < 0 || int(studentu_sk) > 256);
    vector<stud> s;
    s.resize(s.size() + studentu_sk);
    
    for (int i = 0; i < studentu_sk; i++)
    {
        input(s, i);
    }
    print_student(s, studentu_sk);
    system("pause");
    return 0;
}
