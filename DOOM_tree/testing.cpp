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
#include <sstream>
#include <string>

using std::cin;

int main()
{
	
	Node *n1;
	Element elem;
	string str;
	Attribute a1("hello", "world"), a2("hello2", "world2");
	list<Element> l;
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
	

	list<string> input;
	while(getline(cin, str))
	{
	  input.push_back(str);
	}
	
	l = elem.convertToElem(input); // list of elements
	
	
	
	/*Testing DOM_Tree building */
	
	DOM_Tree aTree(elem);
	DOM_Tree bTree;
	
	bTree.tree(l);
	bTree.print();
	
	/*Testing DOM_Tree methods
	
	
	bTree.appendChild(aTree);
	bTree.appendChild(1, aTree); // Need more testing
	
	DOM_Tree cTree(bTree);
	
	//bTree.removeChild(1); // memory leak
	
	cout << bTree.infoRoot() << endl;
	cout << cTree.infoRoot() << endl;*/
	
	
	/* Testing building a DOM-Tree from an input*/
	

	
	return 0;
}


