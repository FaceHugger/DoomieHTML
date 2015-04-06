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
	
	Node *n1;
	Element elem;
	string str;
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
	
	//getline(cin, str);
	//elem.readstring(str); // Change for overload of '>>' in class Element
	
	

	/*Testing DOM_Tree building 
	
	DOM_Tree aTree(elem);
	DOM_Tree bTree;*/
	
	/*Testing DOM_Tree methods
	
	
	bTree.appendChild(aTree);
	bTree.appendChild(1, aTree); // Need more testing
	
	DOM_Tree cTree(bTree);
	
	//bTree.removeChild(1); // memory leak
	
	cout << bTree.infoRoot() << endl;
	cout << cTree.infoRoot() << endl;*/
	
	
	/* Testing building a DOM-Tree from an input*/
	
	list<DOM_Tree> listofTrees;
	list<Attribute> l;
	DOM_Tree dTree;
	
	while(getline(cin,str)) // Building a list of DOM_Trees
	{
	  elem.readstring(str);
	  dTree.appendChild(elem);
	  listofTrees.push_back(dTree);
	  elem.setTagName("");
	  elem.setAttributeList(l);
	  elem.setinnerHTML("");
	  dTree.empty();
	}
	
	while(!listofTrees.empty())
	{
	  cout << listofTrees.front().infoRoot() << endl;
	  listofTrees.pop_front();
	}
	
	return 0;
}


