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

<<<<<<< HEAD
=======
#ifndef IOSTREAM
	#include <iostream>
	using std::cout;
	using std::ostream;
#endif

>>>>>>> 3876a76827d45b68fbdafbd37c8ad6a0e86141ee
class Element
{

	private:

		string tagname;
		list<Attribute> Attributes;
		string innerhtml;

	public:
		//Builders
		Element() : tagname(" "), Attributes(), innerhtml(" ") {};
		Element(string tN, list<Attribute> a, string iH) : tagname(tN), Attributes(a), innerhtml(iH) {};

		//Consult
		string tagName() { return tagname; }
		list<Attribute> AttributeList() { return Attributes; }
		string innerHTML() { return innerhtml; }
		void print();

		//Modifier
		void setTagName(string tagN) { tagname = tagN; }
		void setAttributeList( list<Attribute> listofAttributes) { Attributes = listofAttributes; }
		void setinnerHTML(string inner) { innerhtml = inner; }
		void readstring(string input);
		
		//Overload of operators
		//=
		Element &operator=(const Element &);
		//<<
		friend ostream &operator<<(ostream &, list<Attribute> &);
		friend ostream &operator<<(ostream &, Element &);	
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
  
  std::string::iterator it = input.begin();

  while(*it != '>' && !theEnd)
  {
   
      if(*it == '<' || *it == '/')
      {
          it++;
      }
         
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
              
              while(*it != '"' && !flagAValue) // sving attribute value
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
                  Attributes.push_back(info);
                  
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
      
      it++;
  }
    
    if(*it == '>')
        it++;
    
    if( it != input.end())
    {
        while(*it != '<') // saving innerHTML
        {     
            innerhtml += *it;
            it++;
        }
    }
}

  
void Element :: print()
{
  list<Attribute> aux;
  
  aux = Attributes;
  
  cout << tagname << " "; 
  while(!aux.empty())
  {
    cout << aux.front().getName() << " ";
    cout << aux.front().getValue() << " ";
    aux.pop_front();
  }
  cout << innerhtml << endl;
}
  
//Overloads

//= Element
Element &Element::operator=(const Element &orig)
{
	this->tagname = orig.tagname;
	this->Attributes = orig.Attributes;
	this->innerhtml = orig.innerhtml;
		
	return *this;
}

//<< list<Attribute>
ostream &operator<<(ostream &output, list<Attribute> &l)
{
	cout << "Attributes:";
	for (list<Attribute>::iterator it = l.begin(); it != l.end(); ++it)
		output << " " << *it;
	
	return output;
}

//<< Element
ostream &operator<<(ostream &output, Element &e)
{
	output << "TagName: " << e.tagname << " " << e.Attributes << " InnerHTML: " << e.innerhtml;
	return output;
}

#endif /* ELEMENT_H_ */
