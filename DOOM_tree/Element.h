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
	using std::ostream;
#endif


class Element
{

	private:

		string tagname;
		list<Attribute> attrList;
		string innerhtml;

	public:
		//Builders
		Element() : tagname(), attrList(), innerhtml() {};
		Element(string tN): tagname(tN), attrList(), innerhtml() {};
		Element(string tN, list<Attribute> a, string iH) : tagname(tN), attrList(a), innerhtml(iH) {};

		//Consult
		string tagName() { return tagname; }
		list<Attribute> AttributeList() { return attrList; }
		string innerHTML() { return innerhtml; }
		void print();

		//Modifier
		void setTagName(string tagN) { tagname = tagN; }
		void setAttributeList( list<Attribute> listofattributes) { attrList = listofattributes; }
		void setinnerHTML(string inner) { innerhtml = inner; }
		void readstring(string input);
		
		//Overload of operators
		//=
		Element &operator=(const Element &);
		//<<
		friend ostream &operator<<(ostream &, const list<Attribute> &);
		friend ostream &operator<<(ostream &, const Element &);	
};

void Element :: readstring(string input)
{
  
  int cont;
  bool flagTag, flagAName, flagAValue;
  bool theEnd;
  string name;
  string value;
  Attribute info;

  cont = 0;
  theEnd = false;
  flagTag = flagAName = flagAValue = false;
  std::string::iterator it = input.begin();

  
  while(*it != '>' && !theEnd)
  {
   
      if(*it == '<' || *it == '/')
      {
          it++;
      }
      
      if(*it == '!')//if header
      {
	tagname += *it;
	it++;
	if(*it == 'd' || *it == 'D')
	{
	   while(!flagTag)
	  {
	    if(*it != '>')
	    {
	      tagname += *it;
	      *it++;
	    }
	    else
	      flagTag=true;
	  }
	  
	  theEnd=true;
	  cont =2;
	}
	
      }else
      {
      
	if(*it != ' ' && !flagTag) // saving tag
	{
	    tagname += *it;
	}else
	{
	    flagTag=true;
	    
	    if( *it == ' ')
		it++;
	    
	    if(*it != '=' && !flagAName)// saving attribute name
	    {
		name += *it;
	    }else
	    {
		flagAName = true;
		cont++;
		
		if(*it == '=')
		    it++;
		
		while(*it != '"' && !flagAValue) // saving attribute value
		{
		    value += *it;
		    
		    if(*it == '"')
		    {
			cont++;
			it++;
			flagAValue=true;
		    }
		    
		    it++;
		}
		
		if(cont == 2)//if cont has count 2 double quotes 
		{
		    //save attribute in a list
		    info.setName(name); 
		    info.setValue(value);
		    attrList.push_back(info);
		    
		    //reset flags and local strings
		    flagAName = false;
		    flagAValue = false;
		    name.clear();
		    value.clear();
		    cont = 0;
		
		    if(*it == '>')
			theEnd=true;
		}
	    }
	}
      }
      
      it++;
  }
    
    if(*it == '>')
    {
        it++;
	innerhtml.clear();
    }
    
    if( it != input.end())
    {
        while(*it != '<') // saving innerHTML
        {     
            innerhtml += *it;
            it++;
        }
    }
}


  
//Overloads

//= Element
Element & Element::operator=(const Element &orig)
{
	this->tagname = orig.tagname;
	this->attrList = orig.attrList;
	this->innerhtml = orig.innerhtml;
	return *this;
}

//<< list<Attribute>
ostream &operator<<(ostream &output, const list<Attribute> &l)
{
	for (list<Attribute>::const_iterator it = l.begin(); it != l.end(); ++it)
		output << " " << *it;
	
	return output;
}

//<< Element
ostream &operator<<(ostream &output, const Element &e)
{
	output << "<" << e.tagname;
	if(!e.attrList.empty())
	{
	  output << e.attrList;
	}
	if(!e.innerhtml.empty())
	  output<< ">" << e.innerhtml << "</" << e.tagname << ">";
	else
	  cout << ">";
	return output;
}

#endif /* ELEMENT_H_ */
