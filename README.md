# V0.4
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
