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
