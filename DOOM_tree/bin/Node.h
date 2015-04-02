/*
 * Node.h
 *
 *  Created on: 30/3/2015
 *      Author: Marien
 */

#ifndef NODE_H_
#define NODE_H_

#ifndef CSTDEF
	#include <cstddef>
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

		Element element() {return(info);}
		Node *firstChild() {return(fChild);}
		Node *nextSibling() {return(nSibling);}

		void setelement(Element content) { info = content; }
		void setfirstChild(Node *leftChild) { fChild = leftChild; }
		void setnextSibling(Node *rightSibling) { nSibling = rightSibling; }
};

#endif /* NODE_H_ */
