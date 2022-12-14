
# 1-oji užduotis
#V0.1
V0.1 versijoje pirmiausia yra nuskaitomi įvesti studento duomenys(vardas, pavardė), tada yra galimybė generuoti atsitiktinius studento pažymius, ar įvesti studento pažymius patiems. Galiausiai atspausdinami rezultatai su studento galutiniais balais (apskaičiuota pagal vidurkį ir medianą). Programa realizuota dviem būdais, kai namų darbų rezultatai ir visi studentai saugomi į: 1) tradicinį dinaminį C masyvą. 2) std::vector tipo konteinerį.

#V1.0
Testavimo sistemos parametrai: CPU: AMD Ryzen 7 5800H with Radeon Graphics @ 3.20 GHz, RAM: 16.0 GB, SSD: 476GB

Pirma strategija (dviejų naujų vektorių/listų sukūrimas):
![image](https://user-images.githubusercontent.com/114738526/205181324-4c520cce-1462-42d2-9314-0c7b2b23891f.png)

Antroji strategija(vieno naujo vektoriaus/list'o sukūrimas, paliekant pradiniame talentingus studentus):
![image](https://user-images.githubusercontent.com/114738526/205441262-cece5d83-eed3-46b1-babb-4e0a85797917.png)


Trečioji strategija(optimizuota naudojant copy ir find_if algoritmus):
![image](https://user-images.githubusercontent.com/114738526/205181371-f39f0115-c3f5-484c-9232-94d68b7fa0ed.png)

