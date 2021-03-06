//
// Created by Cristina Titrat on 19/03/2020.
//

#ifndef POO_SET_SET_H
#define POO_SET_SET_H

#include "Node.h"
#include <exception>
#include <iostream>
#include <ostream>

using namespace std;

class Set {
	Node *array;
	unsigned size{};

	bool has(int);        		// funcție pentru a verifica dacă un element se află în set
	int get(int);       		// ia elementul de pe poziția dată

public:

	//  Implementatea constructorilor cu parametri, fără parametri, de copiere.
	Set();                    	// constructor fără parametri
	explicit Set(int);          // constructor cu un parametru
	Set(int, int);            	// constructor cu doi parametri (inserează un element pe o poziție dată)
	Set(Set &);                	// constructor de copiere

	//  Implementarea destructorului.
	~Set();

	//  Inserarea, ștergerea și căutarea unui element.
	void insertAt(int, int);	// inserează un element pe pozitia specificată
	void insert(int);           // inserează un element pe ultima poziție
	void remove(int);           // sterge elementul dat ca parametru
	int find(int);              // returnează poziția elementului

	//  Obținerea elementelor pare, respectiv impare din mulțime (sub formă de Set).
	Set getEven();        		// returnează un set nou cu elementele pare din mulțimea inițială
	Set getOdd();        		// returnează un set nou cu elementele impare din mulțimea inițială

	//  Obținerea sumei elementelor din mulțime.
	int sum();

	//  Obținerea numărului de elemente din mulțime.
	unsigned length();

	//  Supraı̂ncărcarea operatorului =.
	Set &operator=(Set &);

	//  Supraîncărcarea operatorului [] pentru accesarea elementului de pe poziția i.
	int operator[](unsigned);

	//  Supraîncărcarea operatorului + care să efectueze reuniunea a două mulțimi (fără duplicate).
	Set operator+(const Set &);

	//  Supraîncărcarea operatorilor < și > care să compare cardinalul a două mulțimi.
	bool operator<(const Set &);
	bool operator>(const Set &);

	//  Supraîncărcarea operatorului * pentru înmulțirea cu un scalar.
	void operator*(int);

	//  Supraı̂ncărcarea operatorilor de citire și afișare (<< și >>).
	friend istream &operator>>(istream &, Set &);
	friend ostream &operator<<(ostream &, const Set &);

};


#endif //POO_SET_SET_H
