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

// Se implementează setterul Info pentru a seta un element
void Node::setInfo(int i) {
	info = i;
}

// Se implementează setterul Next pentru a seta următorul element
void Node::setNext(Node *n) {
	next = n;
}
