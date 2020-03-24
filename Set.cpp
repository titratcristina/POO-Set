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
void Set::insert(int index) {
	insertAt(index, size + 1);
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

// metodă care șterge elementul de pe poziția dată
void Set::remove(int index) {
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
