//#include "build_lib.h"
//
//using namespace std;
//
//struct stud {
//    string vard, pav;
//    int *paz;
//    int egz;
//    float gal;
//    float med;
//};
//
//float vid(int * pazymiai, int pazkiek)
//{
//    float pazymiu_suma = accumulate(pazymiai, pazymiai + pazkiek, 0);
//    float pazymiu_vidurkis = pazymiu_suma / pazkiek;
//    return pazymiu_vidurkis;
//}
//float med(int *pazymiai, int pazkiek) //funkcija skaiciuojanti mediana
//{
//    sort(pazymiai, pazymiai+pazkiek);
//
//    float mediana;
//
//    if (pazkiek == 0)
//    {
//        mediana = 0;
//    }
//    else if (pazkiek % 2 == 0)
//    {
//        mediana = (pazymiai[pazkiek / 2] + pazymiai[pazkiek / 2 - 1]) / 2.0;
//    }
//    else
//    {
//        mediana = pazymiai[(pazkiek - 1) / 2];
//    }
//    return mediana;
//}
//
//int randompaz()
//{
//    mt19937 mt(static_cast<long unsigned int>(high_resolution_clock::now().time_since_epoch().count()));
//    uniform_int_distribution<int> dist(1, 10);
//    return dist(mt);
//}
//
//bool has_digit(string s)
//{
//    return (s.find_first_of("0123456789") != string::npos);
//}
//
//void input(stud *& s, int i)
//{
//
//    cout << "iveskite studento nr. " << i + 1 << " duomenis:\n";
//    do {
//        cout << "iveskite studento nr. " << i + 1 << " varda:\n";
//        cin >> s[i].vard;
//    } while (s[i].vard.length() < 0 || s[i].vard.length() > 25 || has_digit(s[i].vard));
//    do {
//        cout << "iveskite studento nr. " << i + 1 << " pav:\n";
//        cin >> s[i].pav;
//    } while (s[i].pav.length() < 0 && s[i].pav.length() > 25 || has_digit(s[i].pav));
//    cout << endl;
//    string temp;
//    do
//    {
//        cout << "jeigu norite, kad studento pazymiai butu suvesti automatiskai - spauskite \"r\"\n jeigu norite suvesti duomenis patys - rasykite \"p\"\n";
//        cin >> temp;
//        if (temp != "r" && temp != "R" && temp != "p" && temp != "P") {
//            cout << "pakartokite, netinkamas simbolis\n";
//        }
//    } while (temp != "r" && temp != "R" && temp != "p" && temp != "P");
//    if (temp == "p" || temp == "P")
//    {
//        int size = 1, pazymys;
//        s[i].paz = new int[size];
//        cout << "iveskite studento pazymius (kai baigsite, iveskite -1 (minus vienas)):";
//        cin >> pazymys;
//        while (pazymys != -1) {
//            s[i].paz[size - 1] = pazymys;
//            size_t newSize = size + 1;
//            int* newPaz = new int[newSize];
//            memcpy(newPaz, s[i].paz, size * sizeof(int));
//            size = newSize;
//            delete[] s[i].paz;
//            s[i].paz = newPaz;
//            cin >> pazymys;
//        }
//        do {
//            cout << "iveskite studento egz:\n";
//            cin >> pazymys;
//        } while (pazymys < 0 || pazymys > 10);
//        s[i].egz = pazymys;
//        s[i].gal = 0.4 * vid(s[i].paz, size - 1) + s[i].egz * 0.6;
//        s[i].med = 0.4 * med(s[i].paz, size - 1) + s[i].egz * 0.6;
//    }
//    else 
//    {
//        s[i].egz = randompaz();
//        s[i].paz = new int[5];
//        for (int j = 0; j < 5; j++)
//        {
//            s[i].paz[j] = randompaz();
//        }
//        s[i].gal = 0.4 * vid(s[i].paz, 5) + s[i].egz * 0.6;
//        s[i].med = 0.4 * med(s[i].paz, 5) + s[i].egz * 0.6;
//    }   
//}
//
//void print_student(stud * s, int studentu_sk) //atspausdina rezultatus
//{
//    cout << "\n\n";
//    cout << setw(20) << left << "vardas"
//        << setw(20) << left << "pavarde"
//        << setw(18) << left << "galutinis(vid.)/"
//        << left << "galutinis(med.)\n"
//        << "--------------------------------------------------------------------------\n";
//    for (int i = 0; i < studentu_sk; i++)
//    {
//        cout << setw(20) << left << s[i].vard
//            << setw(20) << left << s[i].pav
//            << setw(18) << left << s[i].gal
//            << left << s[i].med << endl;
//    }
//    cout << "\n\n";
//}
//
//int main()
//{
//    int studentu_sk;
//    do
//    {
//        cout << "iveskite studentu kieki:\n";
//        cin >> studentu_sk;
//    } while (int(studentu_sk) < 0 || int(studentu_sk) > 256);
//    stud* s = new stud[studentu_sk];
//    
//    for (int i = 0; i < studentu_sk; i++)
//    {
//        input(s, i);
//    }
//    print_student(s, studentu_sk);
//    system("pause");
//    return 0;
//}