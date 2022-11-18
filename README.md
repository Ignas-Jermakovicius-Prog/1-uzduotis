# V0.4
Testavimo sistemos parametrai: CPU: AMD Ryzen 7 5800H with Radeon Graphics @ 3.20 GHz, RAM: 16.0 GB, SSD: 476GB

Duomenų nuskaitymas iš failų:


|       |       1000 |     10000 |   100000 |  1000000 | 10000000 |
|   --- |        --- |      ---  |     ---  |    ---   |    ---   |
| List  | 0.0015337s | 0.0145265s| 0.150834s| 1.59346s |   16.428s|
| Vector| 0.0074809s | 0.0175813s| 0.150886s| 1.58293s | 16.107s  |

Studentų rūšiavimas į dvi grupes:

|       |       1000 |     10000 |   100000 |  1000000 | 10000000 |
|   --- |        --- |      ---  |     ---  |    ---   |    ---   |
| List  | 0.0001049s | 0.0014709s|0.0199687s|0.191866s | 2.1736s  |
| Vector| 0.000151s  | 0.0017298s|0.0161772s|0.201541s |  2.2868s |
