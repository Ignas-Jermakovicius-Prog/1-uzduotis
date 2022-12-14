
# 1-oji užduotis
**V0.1**\
V0.1 versijoje pirmiausia yra nuskaitomi įvesti studento duomenys(vardas, pavardė), tada yra galimybė generuoti atsitiktinius studento pažymius, ar įvesti studento pažymius patiems. Galiausiai atspausdinami rezultatai su studento galutiniais balais (apskaičiuota pagal vidurkį ir medianą). Programa realizuota dviem būdais, kai namų darbų rezultatai ir visi studentai saugomi į: 1) tradicinį dinaminį C masyvą. 2) std::vector tipo konteinerį.


**V0.2**\
V0.2 versijoje funkcijos yra išskirtos į atskirus .cpp ir .h failus. Taip pat kai yra nuskaitoma iš failo, įdėtas exception, kad kiekvieną kartą tikrintų ar gerai įvestas failo pavadinimas. Jei ne, išmetama "Neteisingas failo pavadinimas", taip žinome kur palikome klaidą. Pati programa nuskaito duomenis iš duom.txt (bendras failas i kuri kopijavau testus) failo ir sukuria nauja txt faila "rez.txt'.


**V0.3**\
Iš pirmo programa reikalauja pasirinkti testo būdą, t.y. 1) ar norime sugeneruoti studentų failus su šabloniškais vardais ir atsitiktiniais pažymiais 2) ar norime nuskaityti studentų duomenis iš failo 3) ar norime studentų duomenis įvesti ranka . 1) testu (po generavimo) ir 2) testu failas yra nuskaitomas, o poto visais testais studentai yra surūšiuoti į dvi grupes - talentus ir nuskriaustuosius. Šios dvi studentų grupės tada yra įrašomos į du atskirus .txt failus. Pamatuota failo sukurimo trukmė. Atlikta greičio analizė (rasta vykdymo trukmė atskirų programos dalių): .txt failo su studentais nuskaitymo, studentų rūšiavimo į dvi grupes, studentų įrašimo į nuskriaustųjų bei talentų failus, viso testo atlikimo laikas. Kiekvieno žingsnio atlikimo trukmė yra aprašoma programos vykdymo metu.


**V0.4**\
Testavimo sistemos parametrai: CPU: AMD Ryzen 7 5800H with Radeon Graphics @ 3.20 GHz, RAM: 16.0 GB, SSD: 476GB

Duomenų nuskaitymas iš failų:


|       |       1000 |     10000 |   100000 |  1000000 | 10000000 |
|   --- |        --- |      ---  |     ---  |    ---   |    ---   |
| Vector| 0.004314s  | 0.0156839s| 0.141334s| 1.42481s | 14.4696s |
| List  | 0.0016492s | 0.0139762s| 0.140468s| 1.45837s | 14.3941s |

Studentų rūšiavimas į dvi grupes:

|       |       1000 |     10000 |   100000 |  1000000 | 10000000 |
|   --- |        --- |      ---  |     ---  |    ---   |    ---   |
|Vector | 0.0001215s | 0.0016568s|0.0200248s|0.255469s | 2.90975s |
| List  | 0.0001221s | 0.0011378s|0.0210761s|0.25152s  | 2.45141s |

**V1.0**\
Testavimo sistemos parametrai: CPU: AMD Ryzen 7 5800H with Radeon Graphics @ 3.20 GHz, RAM: 16.0 GB, SSD: 476GB

Pirma strategija (dviejų naujų vektorių/listų sukūrimas):
![image](https://user-images.githubusercontent.com/114738526/205181324-4c520cce-1462-42d2-9314-0c7b2b23891f.png)

Antroji strategija(vieno naujo vektoriaus/list'o sukūrimas, paliekant pradiniame talentingus studentus):
![image](https://user-images.githubusercontent.com/114738526/205441262-cece5d83-eed3-46b1-babb-4e0a85797917.png)


Trečioji strategija(optimizuota naudojant copy ir find_if algoritmus):
![image](https://user-images.githubusercontent.com/114738526/205181371-f39f0115-c3f5-484c-9232-94d68b7fa0ed.png)

