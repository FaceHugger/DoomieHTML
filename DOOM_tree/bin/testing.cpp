/*
 * main.cpp

 *
 *  Created on: 30/3/2015
 *      Author(s): Marien
 *		   Sergio
    
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
	string example = "<title>PRIMEROS PASOS CON BRACKETS</title>"; // Need to find a way read double quoting input without escape characters ASAP.
	Element elem;
	Attribute a1("hello", "world"), a2("hello2", "world2");
	list<Attribute> l1(1, a1), l2(1, a2);
	Element e1("html", l1, "Hi!"), e2("html2", l2, "Hi!2");


	//n1 = new Node(elem);
	
	
	/* Testing overloads
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
		 */

	/* Testing Elemet input */
	
	elem.readstring(example); // Change for overload of >> in class Element
	elem.print(); // Change for overload of << in class Element
	
	return 0;
}


