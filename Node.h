//
// Created by Cristina Titrat on 24/03/2020.
//

#ifndef POO_SET_NODE_H
#define POO_SET_NODE_H


class Node {
	int info;
	Node *next;
public:
	// Constructor fără parametri
	Node();

	// Constructor cu parametri
	Node(int, Node *);

};


#endif //POO_SET_NODE_H
