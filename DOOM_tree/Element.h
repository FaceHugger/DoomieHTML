/*
 * Element.h
 *
 *  Created on: 30/3/2015
 *      Author: Marien
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#ifndef STRING
	#include <string>
	using std::string;
#endif

#ifndef LIST
	#include <list>
	using std::list;
#endif

#ifndef ATTRIBUTE_H_
	#include "Attribute.h"
#endif

#ifndef IOSTREAM
	#include <iostream>
	using std::cout;
	//using std::ostream;
#endif

class Element
{

	private:
		string tagname;
		list<attribute> attributes;
		string innerhtml;

	public:
		//Builders
		Element() : tagname(" "), attributes(), innerhtml(" ") {};
		Element(string tN, list<attribute> a, string iH) : tagname(tN), attributes(a), innerhtml(iH) {};

		//Consult
		string tagName() { return tagname; }
		list<attribute> attributeList() { return attributes; }
		string innerHTML() { return innerhtml; }

		//Modifier
		void setTagName(string tagN) { tagname = tagN; }
		void setAttributeList( list<attribute> listofattributes) { attributes = listofattributes; }
		void setinnerHTML(string inner) { innerhtml = inner; }
		
		//Overload of operators
		//=
		Element &operator=(const Element &);
		//<<
		friend ostream &operator<<(ostream &, list<attribute> &);
		friend ostream &operator<<(ostream &, Element &);
};

Element &Element::operator=(const Element &orig)
{
	this->tagname = orig.tagname;
	this->attributes = orig.attributes;
	this->innerhtml = orig.innerhtml;
		
	return *this;
}

ostream &operator<<(ostream &output, list<attribute> &l)
{
	cout << "Attributes:";
	for (list<attribute>::iterator it = l.begin(); it != l.end(); ++it)
		output << " " << *it;
	
	return output;
}

ostream &operator<<(ostream &output, Element &e)
{
	output << "TagName: " << e.tagname << " " << e.attributes << " InnerHTML: " << e.innerhtml;
	return output;
}

#endif /* ELEMENT_H_ */
