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

		void empty();
		static Node *copyNodes(Node *);
		void copy(const DOM_Tree &);
	public:
		DOM_Tree() : root(NULL) {};
		DOM_Tree(Element info, list<DOM_Tree> childs);
		DOM_Tree(const DOM_Tree &n_root); // builder copy
		//~DOM_Tree(); // destructor

		DOM_Tree childNode(int p);
		DOM_Tree getElementByID(string id); // returns a list of subtrees whose roots match with the id requested
		
		void appendChild(DOM_Tree newChild);
		void appendChild(int p, DOM_Tree newChild);
		void removeChild(int p);
		void replaceChild(int p, DOM_Tree newSubtree);
		void print(); // prints the DOM_Tree in console ( going to be changed as an "<<" overload)
		//Overload of operators
		//=
		DOM_Tree &operator=(const DOM_Tree &);
};

///Private methods:

Node *DOM_Tree::copyNodes(Node *n)
{
	Node *newNode;

    if(n == NULL)
        return(NULL);
    else
        newNode = new Node(n->element(), copyNodes(n->firstChild()), copyNodes(n->nextSibling()));

    return newNode;
}

void DOM_Tree::copy(const DOM_Tree &D)
{
    if( &D.root != NULL )
        root = new Node(D.root->element(), copyNodes(D.root->firstChild()), NULL);
    else
        root = NULL;
}

void DOM_Tree::empty()
{
    DOM_Tree *aux;

    if( root != NULL )
    {
        if( root->nextSibling() != NULL )
        {
            aux->root = root->nextSibling();
            aux->empty();
            delete aux;
        }
		
        if( root->firstChild() != NULL )
        {
            aux->root = root->firstChild();
            aux->empty();
            delete aux;
        }
		
        delete root;
        root = NULL;
    }
}

///Public methods:

//Overloads

//= DOM_Tree
DOM_Tree &DOM_Tree::operator=(const DOM_Tree &orig)
{
   if (this != &orig)
   {  
		this->empty();
		this->copy( orig );
   }
   return *this;
}

/*
DOM_Tree :: DOM_Tree(Element info, list<attribute> childs)
{
	//root = new Node(info);

}
*/


#endif /* DOM_TREE_H_ */
