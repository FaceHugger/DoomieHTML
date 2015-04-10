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
		Node *getRoot() {return root;}
		void setRoot(Node *r) { root = r; }
		
	public:
		DOM_Tree() : root(NULL) {};
		DOM_Tree(Element e) {root = new Node(e);}
		DOM_Tree(Element info, list<DOM_Tree> childs);
		DOM_Tree(const DOM_Tree &aRoot); // copy constructor
		~DOM_Tree(); // destructor
	
		Element infoRoot() {return root->element();}
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

DOM_Tree :: DOM_Tree(const DOM_Tree &aRoot)
{
  root = copyNodes(aRoot.root);
}

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

DOM_Tree DOM_Tree :: childNode(int p)
{
	int i=3;
	DOM_Tree aux;
	Node *left, *right, *ptrActL, *ptrActR;
	
	if(p == 1)
		aux.copy(*this);
	else
	{
		if(p == 2)
			aux.root = copyNodes(root->firstChild());
		else
		{
			ptrActL = root->firstChild()->firstChild();
			left = ptrActL;
			right = ptrActL->nextSibling();
			
			while(left != NULL || right != NULL)
			{
				while(ptrActL != NULL)
				{
					if(i == p)
						aux.root = copyNodes(ptrActL);
					else
					{
						i++;
						ptrActL = ptrActL->nextSibling();
					}
				}
				
				while(ptrActR != NULL)
				{
					if(i == p)
						aux.root = copyNodes(ptrActR);
					else
					{
						i++;
						ptrActR = ptrActR->nextSibling();
					}
				}
				
				if(ptrActL != NULL)
				{
					ptrActL = left->firstChild();
					left = ptrActL;
				}
				
				if(ptrActR != NULL)
				{
					ptrActR = right->firstChild();
					right = ptrActR;
				}
				
				i++;
			}
		}
	}
	return aux;
}

DOM_Tree DOM_Tree :: getElementByID(string id)
{
	Node *ptrActL, *ptrActR, *left, *right;
	DOM_Tree subTree;
	list<Attribute> aux;
	Attribute aux1("id", id);
	Attribute aux2("ID", id);
	bool found = false;
	
	ptrActL = root->firstChild()->firstChild();
	left = ptrActL;
	right = ptrActL->nextSibling();
			
	while(left != NULL || right != NULL)
	{
		while(ptrActL != NULL)
		{
			aux = ptrActL->element().AttributeList();
				
			for(list<Attribute>::iterator it = aux.begin(); it != aux.end() && !found; ++it)
			{
				if(*it == aux1 || *it == aux2)
				{
					found = true;
				}
			}
			ptrActL = ptrActL->nextSibling();
		}
		
		while(ptrActR != NULL)
		{
			aux = ptrActR->element().AttributeList();
				
			for(list<Attribute>::iterator it = aux.begin(); it != aux.end() && !found; ++it)
			{
				if(*it == aux1 || *it == aux2)
				{
					found = true;
				}
			}
			ptrActR = ptrActR->nextSibling();
		}
		
		if(ptrActL != NULL)
		{
			ptrActL = left->firstChild();
			left = ptrActL;
		}
		
		if(ptrActR != NULL)
		{
			ptrActR = right->firstChild();
			right = ptrActR;
		}
	}
}

void DOM_Tree :: appendChild(DOM_Tree newChild)
{

  Node *aux;
  if(root != NULL)
  {
     aux = copyNodes(newChild.root);
     aux->setnextSibling(root->firstChild());
     root->setfirstChild(aux);
    
  }else
  {
    copy(newChild); 
  }
  
 
}

void DOM_Tree :: appendChild(int pos, DOM_Tree a )
{
  Node *aux, *aux2;
  int i;

  if(pos==1)
     appendChild(a);
  else
  {
      aux=root->firstChild();
      for(i=2; i<= pos-1; i++)
      {
        aux=root->firstChild();
      }
          aux2=copyNodes(a.root);
          aux2->setnextSibling(aux->nextSibling());
          aux->setnextSibling(aux2);
  }
}

void DOM_Tree :: removeChild(int pos)
{
   Node *aux, *aux2;
   int i;

   aux=root->firstChild();
   
   for(i=2; i<=pos-1; i++)
   {
      aux = aux->nextSibling();
   }

   aux2=aux->nextSibling();
   aux->setnextSibling(aux2->nextSibling());
   //empty(aux);
}

void DOM_Tree :: replaceChild(int p, DOM_Tree newSubtree)
{
	int i=3;
	Node *left, *right, *ptrActL, *ptrActR, *ptrAux;
	
	ptrAux = newSubtree.getRoot();
	
	if(p == 1)
		this->setRoot(copyNodes(ptrAux));
	else
	{
		if(p == 2)
			this->setRoot(ptrAux->firstChild());
		else
		{
			ptrActL = root->firstChild()->firstChild();
			left = ptrActL;
			right = ptrActL->nextSibling();
			
			while(left != NULL || right != NULL)
			{
				while(ptrActL != NULL)
				{
					if(i == p)
						this->setRoot(copyNodes(ptrActL));
					else
					{
						i++;
						ptrActL = ptrActL->nextSibling();
					}
				}
				
				while(ptrActR != NULL)
				{
					if(i == p)
						this->setRoot(copyNodes(ptrActR));
					else
					{
						i++;
						ptrActR = ptrActR->nextSibling();
					}
				}
				
				if(ptrActL != NULL)
				{
					ptrActL = left->firstChild();
					left = ptrActL;
				}
				
				if(ptrActR != NULL)
				{
					ptrActR = right->firstChild();
					right = ptrActR;
				}
				
				i++;
			}
		}
	}
}

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


//Destructor

DOM_Tree :: ~DOM_Tree()
{
	this->empty();
}


#endif /* DOM_TREE_H_ */
