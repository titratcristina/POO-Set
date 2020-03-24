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

void Set::insertAt(int element, int index) {
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
