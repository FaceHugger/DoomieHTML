/*
 * Node.h
 *
 *  Created on: 30/3/2015
 *  Author(s): Marien
 *		   	   Sergio
 */

#ifndef NODE_H_
#define NODE_H_

#ifndef CSTDEF
	#include <cstddef>
#endif

#ifndef IOSTREAM
	#include <iostream>
	using std::cout;
	using std::ostream;
#endif

#include "Element.h"

class Node {

	private:
		Element info;
		Node *fChild;
		Node *nSibling;

	public:
		Node() :
			info(), fChild(NULL), nSibling(NULL) {};

		Node(Element content) :
			info(content), fChild(NULL), nSibling(NULL) {};

		Node(Element content, Node *leftChild, Node *rigthSibling) :
			info(content), fChild(leftChild), nSibling(rigthSibling) {};
			
		Node(const Node &);

		Element element() { return(info); }
		Node *firstChild() { return(fChild); }
		Node *nextSibling() { return(nSibling); }

		void setelement(Element content) { info = content; }
		void setfirstChild(Node *leftChild) { fChild = leftChild; }
		void setnextSibling(Node *rightSibling) { nSibling = rightSibling; }
		
		//Overload of operators
		//= 
		Node &operator=(const Node &);
		//<<
		friend ostream &operator<<(ostream &, const Node &);
};

//Copy Builder
Node :: Node(const Node &orig)
{
	*this = orig;
}

//Overloads

//= Node
Node &Node::operator=(const Node &orig)
{
	this->info = orig.info;
	this->fChild = orig.fChild;
	this->nSibling = orig.nSibling;
	
	return *this;
}

//<< Node
ostream &operator<<(ostream &output, const Node &n)
{
	output << "info: " << n.info << " fChild: " << n.fChild << " nSibling: " << n.nSibling;
	return output;
}
#endif /* NODE_H_ */
