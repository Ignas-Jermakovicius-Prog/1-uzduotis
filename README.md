# V0.4
Testavimo sistemos parametrai: CPU: AMD Ryzen 7 5800H with Radeon Graphics @ 3.20 GHz, RAM: 16.0 GB, SSD: 476GB

Duomenų nuskaitymas iš failų:

| First Header  | Second Header |
| ------------- | ------------- |
| Content Cell  | Content Cell  |
| Content Cell  | Content Cell  |

|       |       1000 |     10000 |   100000 |  1000000 | 10000000 |
|   --- |        --- |      ---  |     ---  |    ---   |    ---   |
| List  | 0.0171262s | 0.171614s | 1.73248s |        0 |    0     |
| Vector| 0.0252226s | 0.200523s | 2.13556s | 19.9591s |    0     |
