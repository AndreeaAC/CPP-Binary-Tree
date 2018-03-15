#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct data
{
	int zi;
	int luna;
	int an;
};

struct Farmacie
{
	char nume[20];
	float pret;
	float cantitate;
	struct data P;
	struct data E;

	Farmacie *st;
	Farmacie *dr;

};

//functie pt citirea campurilor unui nod
Farmacie* citeste_medicament()
{

	Farmacie *p;

	p = new Farmacie;

	cout << "Nume medicament: ";
	cin >> p->nume;

	cout << "Pret medicament: ";
	cin >> p->pret;

	cout << "Cantitate medicament: ";
	cin >> p->cantitate;

	cout << "Data primire: zi/luna/an ";
	cin >> p->P.zi >> p->P.luna >> p->P.an;

	cout << "Data expirare: zi/luna/an ";
	cin >> p->E.zi >> p->E.luna>>p->E.an;


	p->st = NULL;
	p->dr = NULL;


	return p;

}

//parcurgerea in inordine a medicamentelor

void lista_medicamente(Farmacie *radacina)
{

	if (radacina != 0)
	{
		lista_medicamente(radacina->st);
		cout << radacina->nume << " " << radacina->pret << " " << radacina->cantitate << " " << radacina->P.zi << " " << radacina->P.luna << " " << radacina->P.an << " " << radacina->E.zi << " " << radacina->E.luna << " " << radacina->E.an << endl;
		lista_medicamente(radacina->dr);

	}
}

//crearea arborelui	

void creare_stoc(Farmacie *radacina, Farmacie *nod)
{
		if (radacina!=NULL)
			if(strcmp(nod->nume, radacina->nume) < 0)
			{
				if (radacina->st != NULL)
					creare_stoc(radacina->st, nod);
				else
					radacina->st = nod;
			}
			else
			{
				if (radacina->dr != NULL)
					creare_stoc(radacina->dr, nod);
				else
					radacina->dr = nod;
			}
}


//functia ce cauta un medicament dupa campul nume, returneaza locatia la care acesta se gaseste,va fi apelata in functia de stergere

Farmacie* cautare2(Farmacie *radacina, Farmacie *locatie, int *ok,char m[])
{
	if (*ok == 1 )
		return locatie;
	if (radacina->st != NULL)
		if (strcmp(radacina->st->nume,m ) != 0)
			cautare2(radacina->st, locatie, ok,m);
		else
		{
			*ok = 1;
			locatie = radacina->st;
			radacina->st = NULL;
			return locatie;
		}
	if (*ok != 1)
		if (radacina->dr != NULL)
		{
			if (strcmp(radacina->dr->nume, m) != 0)
				cautare2(radacina->dr, locatie, ok,m);
			else
			{
				*ok = 1;
				locatie = radacina->dr;
				radacina->dr = NULL;
				return locatie;
			}
		}
}

//functia de cautare a unui medicament dupa campul nume, se va folosii pt actualizarea datelor
void cautare3(Farmacie *radacina, int *ok, char m[])
{
	if (*ok == 1)
		return ;
	if (radacina->st != NULL)
		if (strcmp(radacina->st->nume, m) != 0)
			cautare3(radacina->st, ok, m);
		else
		{
			*ok = 1;
			cin >> radacina->st->pret >> radacina->st->cantitate >> radacina->st->P.zi >> radacina->st->P.luna >> radacina->st->P.an >> radacina->st->E.zi >> radacina->st->E.luna >> radacina->st->E.an;
			return;
		}
	if (*ok != 1)
		if (radacina->dr != NULL)
		{
			if (strcmp(radacina->dr->nume, m) != 0)
				cautare3(radacina->dr, ok, m);
			else
			{
				*ok = 1;
				cin >> radacina->dr->pret >> radacina->dr->cantitate >> radacina->dr->P.zi >> radacina->dr->P.luna >> radacina->dr->P.an >> radacina->dr->E.zi >> radacina->dr->E.luna >> radacina->dr->E.an;
				return;
			}
		}
}

//functie cauta daca radacina este cea care trebuie sa fie actualizata,daca da face acest lucru,in caz contrar apeleaza functia cautare3

void cautare(Farmacie *radacina, char m[])
{
	Farmacie *p;
	int ok = 0;
	if(strcmp(radacina->nume,m)==0)
		cin >> radacina->pret >> radacina->cantitate >> radacina->P.zi >> radacina->P.luna >> radacina->P.an >> radacina->E.zi >> radacina->E.luna >> radacina->E.an;
			
	else
	{
		cautare3(radacina, &ok, m);
		if (ok == 0)
			cout << "Medicamentul nu exista.\n";
	}

}

//functie ce sterge un nod dupa campul nume introdus de la tastatura,apeleaza functia cautare 2

Farmacie* sterge(Farmacie *radacina , char m[])
{
	int ok = 0;
	Farmacie *a;
	if (strcmp(radacina->nume, m) == 0)
	{
		a = radacina;
		if (a->dr != NULL)
		{
			radacina = a->dr;
			if(a->st)
				creare_stoc(radacina, a->st);
		}
		else
				radacina = radacina->st;
		delete(a);
	}
	else
	{
		a = cautare2(radacina, NULL, &ok,m);
		if (ok == 0)
			cout << "nu s-a gasit medicamentul";
		else
		{
			if (a->st != NULL)
				creare_stoc(radacina, a->st);
			if (a->dr != NULL)
				creare_stoc(radacina, a->dr);
		}
	}
	return radacina;
}

//functia copiaza informatiile din nodul a in nodul b
Farmacie* transfer(Farmacie *a)
{
	Farmacie *b;
	b = new Farmacie;
	strcpy(b->nume, a->nume);
	b->pret = a->pret;
	b->cantitate = a->cantitate;
	b->E.an = a->E.an;
	b->E.luna = a->E.luna;
	b->E.zi = a->E.zi;
	b->P.an = a->P.an;
	b->P.luna = a->P.luna;
	b->P.zi = a->P.zi;
	b->st = NULL;
	b->dr = NULL;
	return b;
}

//functia verifica daca o data este mai mica decat o data introdusa de la tastatura(de expirare)
int verificare(struct data b, struct data a)
{
	if (b.an < a.an || (b.an == a.an && b.luna < a.luna) || (b.an == a.an && b.luna == a.luna && b.zi < a.zi))
		return 1;
	else
		return 0;
}

//functia ce creeaza cel de al doilea arbore de cautare cu medicamentele expirate

Farmacie *cautare_si_introducere_in_arbore2(Farmacie *radacina, Farmacie * radacina2, struct data a)
{
	if (radacina != NULL)
	{
		if (radacina->st != NULL && verificare(radacina->st->E, a) == 1)
		{
			if (radacina2 == NULL)
			{
				radacina2 = transfer(radacina->st);
				return radacina2;
			}
			else
			{
				Farmacie *b;
				b = transfer(radacina->st);
				creare_stoc(radacina2, b);
			}
		}
		if (radacina->dr != NULL && verificare(radacina->dr->E, a) == 1)
		{
			if (radacina2 == NULL)
			{
				radacina2 = transfer(radacina->dr);
				return radacina2;
			}
			else
			{
				Farmacie *b;
				b = transfer(radacina->dr);
				creare_stoc(radacina2, b);
			}
		}
		cautare_si_introducere_in_arbore2(radacina->st, radacina2, a);
		cautare_si_introducere_in_arbore2(radacina->dr, radacina2, a);
	}
	return radacina2;
}

//functia ce creeaza cel de al doilea arbore de cautare cu medicamentele expirate,apeland functia anterioara

Farmacie *creare_arbore2(struct data a,Farmacie *radacina,Farmacie *radacina2)
{
	if (radacina != NULL && verificare(radacina->E, a) == 1)
			radacina2 = transfer(radacina);
	radacina2= cautare_si_introducere_in_arbore2(radacina, radacina2, a);
	return radacina2;
}

int main()
{

	int k, aux = 0, i;
	char m[30];
	Farmacie *radacina = NULL,*radacina2=NULL;
	char cerinta;
	do
	{
		cout << "Ce doriti sa faceti? " << endl << "creare-> c " << endl << "afisare->  a" << endl << "actualizare-> A " << endl << "stergere-> S" << endl<< "expirate->E" << endl;
		cin >> cerinta;

		switch (cerinta)
		{
		case 'c':
			int n;
			cout << "Cate medicamente va avea farmacia? ";
			cin >> n;
			for (i = 0;i < n;i++)
			{
				Farmacie *nod;
				nod = citeste_medicament();
				if (radacina == NULL)
					radacina = nod;
				else
					creare_stoc(radacina, nod);
			}

			cout << "--------------------------------------";
			cout << endl;
			break;

		case 'a':
			lista_medicamente(radacina);
			cout << "--------------------------------------";
			cout << endl;
			break;

		case 'A':
			cout << "Ce medicament doriti sa actualizati?";
			cin >> m;
			cautare(radacina, m);
			cout << "--------------------------------------";
			cout << endl;
			break;

		case 'S':
			cout << "Ce medicament doriti sa eliminati? ";
			cin >> m;
			radacina = sterge(radacina,m);
			cout << "--------------------------------------";
			cout << endl;
			break;
		case 'E':
			cout << "Introduceti o data de expirare: ";
			struct data exp;
			cin >> exp.zi >> exp.luna >> exp.an;
			radacina2 = creare_arbore2(exp,radacina,NULL);
			cout << "--------------------------------------";
			cout << endl;
			lista_medicamente(radacina2);
		}

		cout << "Continuati programul? <cititi un intreg; pentru a iesi, cititi valoarea 0>: ";
		cin >> k;

	} while (k != 0);



	getch();
	return 0;


}
