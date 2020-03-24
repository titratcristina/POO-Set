//
// Created by Cristina Titrat on 24/03/2020.
//
#pragma once

#ifndef POO_SET_NODE_H
#define POO_SET_NODE_H

#include <iostream>

class Node {
	int info;
	Node *next;
public:
	// Constructor fără parametri
	Node();

	// Constructor cu parametri
	Node(int, Node *);

	// Setter pentru info
	void setInfo(int);

	// Setter pentru next
	void setNext(Node *);

	// Getter pentru info
	int getInfo();

	// Getter pentru next
	Node *getNext();

	// Desctructor
	// ~Node();

};


#endif //POO_SET_NODE_H
