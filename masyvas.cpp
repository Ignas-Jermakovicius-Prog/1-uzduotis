#include "build_lib.h"

using namespace std;

struct stud {
    string Vard, Pav;
    int paz[10] = {0};
    int egz;
    float gal;
    float med;
};

void vid(stud& s, int size)
{
    float pazymiu_suma = accumulate(s.paz, s.paz+size, 0);
    float pazymiu_vidurkis = pazymiu_suma / size;
    s.gal = 0.4 * pazymiu_vidurkis + 0.6 * s.egz;
}

void med(stud& s, int size)
{
    sort(s.paz, s.paz+size);
    float mediana;
    if (size % 2 == 0)
    {
        mediana = (s.paz[(size - 1) / 2] + s.paz[size / 2]) / 2.0;
    }
    else
    {
        mediana = s.paz[size / 2];
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
        S[i].paz[j] == randompaz();
    }
    vid(S[i],pazkiek);
    med(S[i],pazkiek);
}
void input(stud S[], int i)
{
    int temp;
    cout << "Iveskite studento pazymius (kai baigsite, iveskite -1 (minus vienas)):";
    cin >> temp;
    int size = 0;
    while (temp != -1) {
        S[i].paz[size] = temp;
        size++;
        cin >> temp;
    }
    do {
        cout << "Iveskite studento EGZ:\n";
        cin >> S[i].egz;
    } while (S[i].egz < 0 || S[i].egz > 10);
    vid(S[i],size);
    med(S[i],size);
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