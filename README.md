# V0.4
Testavimo sistemos parametrai: CPU: AMD Ryzen 7 5800H with Radeon Graphics @ 3.20 GHz, RAM: 16.0 GB, SSD: 476GB

Duomenų nuskaitymas iš failų:


|       |       1000 |     10000 |   100000 |  1000000 | 10000000 |
|   --- |        --- |      ---  |     ---  |    ---   |    ---   |
| List  | 0.0175739s | 0.170326s | 1.73186s | 17.2091s |  165.428s|
| Vector| 0.0245706s | 0.199081s | 2.12594s | 19.7415s |188.107s  |

Studentų rūšiavimas į dvi grupes:

|       |       1000 |     10000 |   100000 |  1000000 | 10000000 |
|   --- |        --- |      ---  |     ---  |    ---   |    ---   |
| List  | 0.0026424s | 0.0280753s| 0.22283s | 2.11777s |42.6736s  |
| Vector| 0.0044978s | 0.0660278s| 0.65598s | 6.28727s |70.7868s  |
