/*
 * Element.h
 *
 *  Created on: 30/3/2015
 *      Author: Marien
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef struct{
	string name;
	string value;

}attribute;  /// "name='value'"

class Element
{
	string tagname;
	list<attribute> attributes;
	string innerhtml;

	//Builder
	Element(): tagname(), attributes(), innerhtml() {};

	//Consult
	string tagName() { return tagname; }
	list<attribute> attributeList() {return attributes;}
	string innerHTML() {return innerhtml;}

	//Modifier
	void setTagName(string tagN) {tagname = tagN;}
	void setAttributeList( list<attribute> listofattributes) {attributes = listofattributes;}
	void setinnerHTML(string inner) {innerhtml = inner;}



};



#endif /* ELEMENT_H_ */
