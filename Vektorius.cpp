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
void autopaz(vector<stud>& s, int i, int pazkiek)
{
    s.at(i).egz = randompaz();
    for (int j = 0; j < pazkiek; j++)
    {
        s.at(i).paz.push_back(randompaz());
    }
    s.at(i).gal = vid(s.at(i).paz) * 0.6 + s.at(i).egz * 0.4;
    s.at(i).med = med(s.at(i).paz) * 0.6 + s.at(i).egz * 0.4;
}
void input(vector<stud>& s, int i)
{
    int temp, egz;
    cout << "iveskite studento pazymius (kai baigsite, iveskite -1 (minus vienas)):";
    cin >> temp;
    while (temp != -1) {
        s.at(i).paz.push_back(temp);
        cin >> temp;
    }
    do {
        cout << "iveskite studento egz:\n";
        cin >> egz;
        s.at(i).egz = egz;
    } while (egz < 0 || egz > 10);
    s.at(i).gal = vid(s.at(i).paz) * 0.6 + s.at(i).egz * 0.4;
    s.at(i).med = med(s.at(i).paz) * 0.6 + s.at(i).egz * 0.4;
}
bool has_digit(string s)
{
    return (s.find_first_of("0123456789") != string::npos);
}
void name_input(vector<stud>& s, int i)
{
    cout << "iveskite studento nr. " << i + 1 << " duomenis:\n";
    do {
        cout << "iveskite studento nr. " << i + 1 << " varda:\n";
        cin >> s.at(i).vard;
    } while (s.at(i).vard.length() < 0 || s.at(i).vard.length() > 25 || has_digit(s.at(i).vard));
    do {
        cout << "iveskite studento nr. " << i + 1 << " pav:\n";
        cin >> s.at(i).pav;
    } while (s.at(i).pav.length() < 0 && s.at(i).pav.length() > 25 || has_digit(s.at(i).pav));
    cout << endl;
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
    do
    {
        cout << "jeigu norite, kad studentu pazymiai butu suvesti automatiskai - spauskite \"r\"\n jeigu norite suvesti duomenis patys - rasykite \"p\"\n";
        cin >> temp;
        if (temp != "r" && temp != "R" && temp != "p" && temp != "P") {
            cout << "pakartokite, netinkamas simbolis\n";
        }
    } while (temp != "r" && temp != "R" && temp != "p" && temp != "P");
    for (int i = 0; i < studentu_sk; i++)
    {
        name_input(s, i);
        if (temp == "p" || temp == "P") {
            input(s, i);
        }
        else {
            autopaz(s, i, 5);
        }  
    }
    print_student(s, studentu_sk);
    system("pause");
    return 0;
}
