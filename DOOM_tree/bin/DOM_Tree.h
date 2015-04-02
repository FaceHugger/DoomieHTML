/*
 * DOM_Tree.h
 *
 *  Created on: 30/3/2015
 *      Author: Marien
 */

#ifndef DOM_TREE_H_
#define DOM_TREE_H_

#ifndef IOSTREAM
	#include <iostream>
	using std::cout;
	using std::endl;
#endif

#ifndef ELEMENT_H_
	#include "Element.h"
#endif

#ifndef NODE_H_
	#include "Node.h"
#endif

class DOM_Tree{
	
	private:
		Node *root;

	private:
		void empty();
		void copy(Node *originRoot, Node * &destinyRoot);

	public:
		DOM_Tree() : root(NULL) {};
		DOM_Tree(Element info, list<Attribute> childs);
		DOM_Tree(const DOM_Tree &n_root); // builder copy
		//~DOM_Tree(); // destructor

		DOM_Tree childNode(int p);
		list<DOM_Tree> getElementByID(string id); // returns a list of subtrees whose roots match with the id requested

		void appendChild(int p, DOM_Tree newChild);
		void removeChild(int p);
		void replaceChild(int p, DOM_Tree newSubtree);
		void print(); // prints the DOM_Tree in console ( going to be changed as an ">>" overload)
};

/*
DOM_Tree :: DOM_Tree(Element info, list<Attribute> childs)
{
	//root = new Node(info);

}
*/


#endif /* DOM_TREE_H_ */
