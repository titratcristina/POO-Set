//
// Created by Cristina Titrat on 19/03/2020.
//

#include "Set.h"

// constructor fără parametrii care inițializează Setul
Set::Set() {
	array = nullptr;
	size = 0;
}

// constructor cu un parametru care creează un set cu un singur element
Set::Set(int element) {
	array = new Node(element, nullptr);
	size = 1;
}

// constructor cu doi parametri care inserează elementul pe poziția dată
Set::Set(int element, int index) {
	array = nullptr;
	for (int i = 0; i < element; i++) {
		insert(index);
	}
}

// constructor de copiere
Set::Set(Set &s) {
	array = nullptr;
	size = 0;
	Node *p = s.array;
	while (p != nullptr) {
		insert(p->getInfo());
		p = p->getNext();
	}
}

// destructor
Set::~Set() {
	Node *p = array, *o;
	while (p != nullptr) {
		o = p;
		p = p->getNext();
		delete o;
	}
	array = nullptr;
	size = 0;
}

// metodă de inserare a unui element pe ultima poziție
void Set::insert(int element) {
	insertAt(element, size + 1);
}

// funcție booleană care returnează true dacă un element este de mai multe ori în mulțime
bool Set::has(int element) {
	Node *p = array;
	while (p != nullptr) {
		if (p->getInfo() == element) {
			return true;
		}
		p = p->getNext();
	}
	return false;
}

// metodă de inserare a unui element pe o poziție dată
void Set::insertAt(int element, int index) {
	// verific să nu existe același element de mai multe ori într-un set
	if (has(element)) {
		return;
	}
	if (array == nullptr) {
		array = new Node(element, nullptr);
		size = 1;
		return;
	}
	Node *p = new Node(element, nullptr);
	if (index == 0) {
		p->setNext(array);
		array = p;
		size++;
		return;
	}
	if (index < 0 || index >= size) {
		Node *q = array;
		for (int j = 2; j <= size; j++)
			q = q->getNext();

		q->setNext(p);
		size++;
		return;
	}

	Node *o = array;
	for (int j = index; j > 1; j--) {
		o = o->getNext();
	}
	p->setNext(o->getNext());
	o->setNext(p);
	size++;
}

// metodă care șterge elementul dat ca parametru
void Set::remove(int element) {
	int index = find(element);
	if (index < 0 || index >= size) {
		return;
	}
	Node *p = array;
	if (index == 0) {
		if (size == 1 || size == 0) {
			array = nullptr;
		} else {
			array = array->getNext();
			delete p;
		}
	} else {
		for (int j = index; j > 1; j--) {
			p = p->getNext();
		}
		Node *o = p->getNext();
		p->setNext(o->getNext());
		delete o;
	}
	size--;
}

// returnez pozitia elementului, altfel -1 dacă nu există
int Set::find(int element) {
	Node *p = array;
	int i = 0;
	while (p != nullptr) {
		if (p->getInfo() == element) {
			return i;
		} else {
			i++;
		}
		p = p->getNext();
	}
	return -1;
}

// metodă care iterează array-ul cu elementele din muțime și verifică care sunt pare
Set Set::getEven() {
	Node *p = array;
	Set s;
	while (p != nullptr) {
		if (p->getInfo() % 2 == 0)
			s.insert(p->getInfo());
		p = p->getNext();
	}
	return s;
}

// metodă care iterează array-ul cu elementele din muțime și verifică care sunt impare
Set Set::getOdd() {
	Node *p = array;
	Set s;
	while (p != nullptr) {
		if (p->getInfo() % 2 != 0)
			s.insert(p->getInfo());
		p = p->getNext();
	}
	return s;
}

// metodă care returnează suma elementelor din set
int Set::sum() {
	int s = 0;
	Node *p = array;
	while (p != nullptr) {
		s = s + p->getInfo();
		p = p->getNext();
	}
	return s;
}

// metodă care returnează lungimea setului
unsigned Set::length() {
	return size;
}

// supraı̂ncărcarea operatorului =
Set &Set::operator=(Set &s) {
	if (this->size != 0) {
		this->~Set();
		for (int i = 0; i < s.size; i++)
			this->insert(s[i]);
	} else {
		for (int i = 0; i < s.size; i++)
			this->insert(s[i]);
	}
}


int Set::get(int i) {
	if (i < 0 || i >= size) {
		return -1;
	}
	Node *p = array;
	for (int j = i; j > 0; j--) {
		p = p->getNext();
	}
	return p->getInfo();
}

// supraı̂ncărcarea operatorului []
int Set::operator[](unsigned index) {
	if (index > size) {
		throw out_of_range("Index mai mare ca dimensiunea vectorului");
	}
	return get(index);
}

// supraı̂ncărcarea operatorului +
Set Set::operator+(const Set &o) {
	Set s(*this);
	Node *p = o.array;
	while (p != nullptr) {
		s.insert(p->getInfo());
		p = p->getNext();
	}
	return s;
}

// supraı̂ncărcarea operatorului <, folosind o funcție bool
bool Set::operator<(const Set &s) {
	if (this->size < s.size) {
		return true;
	}
	return false;
}

// supraı̂ncărcarea operatorului >, folosind o funcție bool
bool Set::operator>(const Set &s) {
	if (this->size > s.size) {
		return true;
	}
	return false;
}

// supraı̂ncărcarea operatorului *
void Set::operator*(int i) {
	Node *p = array;
	while (p != nullptr) {
		p->setInfo(p->getInfo() * i);
		p = p->getNext();
	}
}

// supraı̂ncărcarea operatorului de afisare
ostream &operator<<(ostream &output, const Set &s) {
	Node *p = s.array;
	while (p != nullptr) {
		output << p->getInfo() << " ";
		p = p->getNext();
	}
	return output;
}


// supraı̂ncărcarea operatorului de citire
istream &operator>>(istream &in, Set &s) {
	int len, i, element;
	in >> len;
	for (i = 0; i < len; i++) {
		in >> element;
		s.insert(element);
	}
	return in;
}


