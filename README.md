# V0.4
Testavimo sistemos parametrai: CPU: AMD Ryzen 7 5800H with Radeon Graphics @ 3.20 GHz, RAM: 16.0 GB, SSD: 476GB

Duomenų nuskaitymas iš failų:


|       |       1000 |     10000 |   100000 |  1000000 | 10000000 |
|   --- |        --- |      ---  |     ---  |    ---   |    ---   |
| List  | 0.0014434s | 0.0133053s| 0.144224s| 1.45863s | 15.2533s |
| Vector| 0.0019104s | 0.0160166s| 0.145654s| 1.474s   | 14.7041s |

Studentų rūšiavimas į dvi grupes:

|       |       1000 |     10000 |   100000 |  1000000 | 10000000 |
|   --- |        --- |      ---  |     ---  |    ---   |    ---   |
| List  | 0.0001049s | 0.0023134s|0.0415745s|0.686667s | 10.6689s |
| Vector| 0.000151s  | 0.0041602s|0.0574573s|0.712997s | 8.7719s  |
