/*
 * main.cpp

 *
 *  Created on: 30/3/2015
 *      Author: Marien
 */

#include "DOM_Tree.h"
#include "Node.h"
#include "Element.h"
#include <string>

using std::cin;

int main()
{
	DOM_Tree aTree;
	Node n1;
	string example;
	Element elem;
	attribute a1("hello", "world"), a2("hello2", "world2");
	list<attribute> l1(1, a1), l2(1, a2);
	Element e1("html", l1, "Hi!"), e2("html2", l2, "Hi!2");

//	elem =

	//n1 = new Node(elem);
	
	//Testing overloads
	cout << a1.getName() << "  " << a1.getValue() << endl;
	a1 = a2;
	cout << a1.getName() << "  " << a1.getValue() << endl;
	
	cout << e1.tagName() << "  " 
		 << e1.attributeList().front().getName() << "  " 
		 << e1.attributeList().front().getValue() << " "
		 << e1.innerHTML() << endl;
		 
	e1 = e2;
	
	cout << e1.tagName() << "  " 
		 << e1.attributeList().front().getName() << "  " 
		 << e1.attributeList().front().getValue() << " "
		 << e1.innerHTML() << endl;

	//cin >> example;
	
	return 0;
}


