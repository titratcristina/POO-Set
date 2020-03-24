#include <iostream>
#include "Node.h"
#include "Set.h"
#include <exception>
#include <cassert>

using namespace std;

void setTests () {
	Set s1, s2(40), s3;

	s1.insert(1);
	s1.insert(3);
	s1.insert(4);

	assert( s1.length() == 3);
	assert( s1.sum() == 8);
	assert( s1.find(4) == 2);

	s1.remove(3);
	assert( s1[1] == 4);

	try {
		s1[5];
		assert(false);
	} catch(...) {
		assert(true);
	}

	assert( s2[0] == 40);

	assert( s1 > s2);
	assert( s2 < s1);
	

	// se citesc 3 numere de la tastatura: 4, 8, 10
	//cin >> s3;
	//cout << s3;
	//assert( s3[0] == 4);


}

int main() {
Set s;
	setTests();

	cout << "Testele au trecut" << endl;

    return 0;
}
