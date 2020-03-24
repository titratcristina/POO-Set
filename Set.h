//
// Created by Cristina Titrat on 19/03/2020.
//

#ifndef POO_SET_SET_H
#define POO_SET_SET_H

#include "Set.h"
#include "Node.h"
#include <iostream>
#include <ostream>

using namespace std;

class Set {
	Node *array;
	unsigned size;

public:

	//  TODO

	//  Implementatea constructorilor cu parametri, fără parametri, de copiere.
	Set();					// constructor fără parametri
	Set(int);				// constructor cu un parametru

	//  Implementarea destructorului.

	//  Inserarea, ștergerea și căutarea unui element.
	void insertAt(int, int);		// inserează un element pe pozitia specificată

	//  Obținerea elementelor pare, respectiv impare din mulțime (sub formă de Set).

	//  Obținerea sumei elementelor din mulțime.

	//  Obținerea numărului de elemente din mulțime.

	//  Supraı̂ncărcarea operatorului =.

	//  Supraîncărcarea operatorului [] pentru accesarea elementului de pe poziția i.

	//  Supraîncărcarea operatorului + care să efectueze reuniunea a două mulțimi (fără duplicate).

	//  Supraîncărcarea operatorilor < și > care să compare cardinalul a două mulțimi.

	//  Supraîncărcarea operatorului * pentru înmulțirea cu un scalar.

	//  Supraı̂ncărcarea operatorilor de citire și afișare (<< și >>).


};


#endif //POO_SET_SET_H
