#include "build_lib.h"

using namespace std;

struct stud {
    string Vard, Pav;
    vector<int> paz;
    int egz;
    float gal;
    float med;
};

void vid(stud& s)
{
    int pazymiu_suma = accumulate(s.paz.begin(), s.paz.end(), 0);
    int pazymiu_vidurkis = pazymiu_suma / s.paz.size();
    s.gal = 0.4 * pazymiu_vidurkis + 0.6 * s.egz;
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

int randompaz()
{
    mt19937 mt(static_cast<long unsigned int>(high_resolution_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> dist(1, 10);
    return dist(mt);
}
void autopaz(stud S[], int i, int pazkiek)
{
    S[i].egz = randompaz();
    for (int j = 0; j < pazkiek; j++)
    {
        S[i].paz.push_back(randompaz());
    }
    vid(S[i]);
    med(S[i]);
}
void input(stud S[], int i)
{
    int temp;
    cout << "Iveskite studento pazymius (kai baigsite, iveskite -1 (minus vienas)):";
    cin >> temp;
    while (temp != -1) {
        S[i].paz.push_back(temp);
        cin >> temp;
    }
    do {
        cout << "Iveskite studento EGZ:\n";
        cin >> S[i].egz;
    } while (S[i].egz < 0 || S[i].egz > 10);
    vid(S[i]);
    med(S[i]);
}
bool has_digit(string s)
{
    return (s.find_first_of("0123456789") != string::npos);
}
void name_input(stud S[], int i)
{
    cout << "Iveskite studento nr. " << i + 1 << " duomenis:\n";
    do {
        cout << "Iveskite studento nr. " << i + 1 << " VARDA:\n";
        cin >> S[i].Vard;
    } while (S[i].Vard.length() < 0 || S[i].Vard.length() > 25 || has_digit(S[i].Vard));
    do {
        cout << "Iveskite studento nr. " << i + 1 << " PAV:\n";
        cin >> S[i].Pav;
    } while (S[i].Pav.length() < 0 && S[i].Pav.length() > 25 || has_digit(S[i].Pav));
    cout << endl;
}
void print_student(stud S[], int studentu_sk) //atspausdina rezultatus
{
    cout << "\n\n";
    cout << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentu_sk; i++)
    {
        cout << setw(20) << left << S[i].Vard
            << setw(20) << left << S[i].Pav
            << setw(18) << left << S[i].gal
            << left << S[i].med << endl;
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
    stud S[25];
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
