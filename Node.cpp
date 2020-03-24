//
// Created by Cristina Titrat on 24/03/2020.
//

#include "Node.h"

// Constructorul inițializează nodul cu 0 și null
Node::Node() {
	info = 0;
	next = nullptr;
}

// Constructorul inițializează nodul cu parametrii primiți
Node::Node(int i, Node *n) {
	info = i;
	next = n;
}
