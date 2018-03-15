
Am folosit 3 biblioteci :iostream,conio(getch),string(strcpy,strcmp)

Am declarat 2 structuri una de tip data cu campurile zi, luna , an , si farmacie care reprezinta un arbore binar cu campurile nume, pret, cantitate si 2 date de tip structura data (data de expirare si data de primire) si 2 pointeri stanga si dreapta.

1)
Functia citeste_medicament citeste si aloca memorie pentru un nod de tip farmacie, citeste campurile acestuia si returneaza adresa nodului.


2)
Functia lista_medicament are doar un parametru(radacina) si aceasta este de tip void.

Parcurge arborele recursiv si afiseaza nodurile in inordine (stanga – radacina – dreapta SRD).


3)
Functia creare_stoc este una de tip cautare si introducere element in arbore, aceasta verifica recursiv unde trebuie introdus nod-ul si apoi face acest lucru.

Este de tip void deoarece nu se modifica adresa radacinii, iar elementele vor ramane legate de aceasta indiferent de ce modificari vor fi facute.

Functia are 2 parametrii : radacina si nodul care trebuie introdus, la reapelare parametrul radacina se va modifica in functie de cum trebuie introdus nodul in arbore.


4)
Functia cautare2 cauta primul nod dupa un nume de medicament introdus de la tastatura si returneaza adresa acestuia.

Functia cautare3 (de tip void) face acelasi lucru,fara a returna locatia nodului gasit,actualizand datele.

5)
A cincea si a sasea functie cauta un nod dupa campul nume si daca se gaseste actualizeaza informatiile acestui nod.

6)
Functia sterge verifica daca radacina are campul nume identic cu un nume introdus de la tastatura ,si daca o are transforma subarborele drept in arbore principal si adauga subarborele stang la acesta.

In caz contrar apeleaza functia de cautare si utilizeaza adresa nodului pentru a-l sterge,adaugand(daca exista) subarborele stang si drept la arbore.

7)
Functia transfer copiaza campurile din nodul a in nodul b , si returneaza adresa nodului b.

8)
Functia verificare compara 2 date diferite si returneaza 1 sau 0 in funtie de care data e mai mare.

9)
Functia cautare_si_introducere_in_arbore2 creaza radacina celui de-al doilea arbore si adaug restul elementelor.

La final returnez radacina.

10)

Functia creare_arbore2 verifica daca radacina primului arbore satisface conditiile datei de expirare, daca da radacina este copiata in radacina celui de-al doilea arbore.

In caz contrat radacina este creata pe parcursul cautarii in arborele 1, primul nod care satisface conditia datei de expirare este copiat in radacina celui de-al doilea.

apoi se verifica restul elementelor arborelui 1 ,iar daca satisfac conditia datei de expirare se introduc in arborele 2.


Main-ul este de tip meniu folosind un switch,fiind apelate toate functiile de mai sus.

Pentru introducerea datei de expirare si de primire trebuie dat cate un enter pentru a trece de la zi ,la luna ,la an.