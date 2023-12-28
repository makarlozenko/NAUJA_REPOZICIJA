# first_project
Sistemos informacija:
| CPU                                       | RAM | SSD   | 
|-------------------------------------------|-----|-------|
| Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz | 8GB | 512GB |

# V1.1 versija 
# Class ir Struct palyginimas:

Struct versija:
| Testavimas               |     1000000  |  10000000 |    1000000  |  10000000 |     1000000  |  10000000 |
|--------------------------|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|
| Flagas                   |     O1   |        O1 |     O2   |        O2 |     O3   |        O3 |
| Failo   nuskaitymas      | 3.00431 s |  30.6276 s  |3.03645 s |  30.8246 s |2.99319 s|   30.7396 s |
| Funkcija sort            |3.14813 s | 39.1952 s |3.16918 s | 38.693 s|2.96981 s | 37.6804 s |
| Išvedimas į   kietakius  | 1.9013 s  | 19.0356 s|1.92242 s  | 19.4687 s|1.8852 s  | 19.1405 s|
| Išvedimas į   vargšiukus | 1.33451 s  | 13.3261 s | 1.34884 s  | 13.6236 s | 1.31388 s  |13.4542 s |
| Bendras laikas           | 9.38825 s | 102.185 s| 9.47689 s | 102.61 s| 9.16208 s | 101.015 s|
| exe failo dydis          | 2607 KB | 2607 KB| 3404 KB | 3404 KB| 3358 KB | 3358 KB|


Class versija:
| Testavimas               |     1000000  |  10000000 |    1000000  |  10000000 |     1000000  |  10000000 |
|--------------------------|:---------:|:---------:|:---------:|:---------:|:---------:|:---------:|
| Flagas                   |     O1   |        O1 |     O2   |        O2 |     O3   |        O3 |
| Failo   nuskaitymas      | 3.22829 s |  37.0912 s  |3.176 s |  33.1306 s |3.17075 s |  32.96 s  |
| Funkcija sort            | 1.18674 s | 15.7502 s |1.19442 s| 14.4812 s |1.18469 s | 14.3167 s |
| Išvedimas į   kietakius  | 1.89738 s  | 18.8566 s|1.88974 s | 18.9461 s|1.87434 s  | 18.803 s|
| Išvedimas į   vargšiukus | 1.32766 s | 13.1207 s | 1.32952 s  | 13.3899 s |1.3213 s  | 13.2821 s |
| Bendras laikas           | 7.64007 s | 84.8187 s| 7.58968 s | 79.9478 s|  7.55108 s | 79.3617 s|
| exe failo dydis          | 220 KB | 220 KB| 214 KB | 214 KB| 212 KB | 212 KB|


# V1.2 versija 
Buvo realizuota trijų metodų taisyklė:

![image](https://github.com/makarlozenko/NAUJA_REPOZICIJA/assets/145557353/09f1e7e4-9652-49a3-9bdb-09070030866c)

Be to, perdengti įvesties ir išvesties metodai darbui su Studentų klasę:

![image](https://github.com/makarlozenko/NAUJA_REPOZICIJA/assets/145557353/68b4859b-8196-47b4-9437-3b573405f955)

Įvesties metodo panaudojimas: 

![image](https://github.com/makarlozenko/NAUJA_REPOZICIJA/assets/145557353/6d7100c7-9dfe-42e7-919b-a4c4ef7921b8)

Išvesties metodo panaudojimas: 

![image](https://github.com/makarlozenko/NAUJA_REPOZICIJA/assets/145557353/14171280-c24f-45de-a66d-3d8f890aa250)



# V1.5 versija 
Buvo realizuota bazinė (abstrakti) klasė, skirta bendrai aprašyti žmogų ir iš jos išvestinę (derived) klasę - Studentas.

![image](https://github.com/makarlozenko/NAUJA_REPOZICIJA/assets/145557353/c91a7633-924a-4ac6-9621-d52cfb5869cd)

Abstrakčios klasės Žmogus objektų kūrimas negalimas:

![image](https://github.com/makarlozenko/NAUJA_REPOZICIJA/assets/145557353/5007049f-eccf-4a87-889e-a0de68c91ab4)

Užkomentavus abstrakčios klasės Žmogus objekto kūrimą, programa veikia:

![image](https://github.com/makarlozenko/NAUJA_REPOZICIJA/assets/145557353/34fe99e4-70ce-4e30-b308-7a1193309b27)









 









