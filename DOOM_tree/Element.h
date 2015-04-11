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
		bool bslash;

	public:
		//Builders
		Element() : tagname(), attrList(), innerhtml(), bslash(false) {};
		Element(string tN): tagname(tN), attrList(), innerhtml(), bslash(false) {};
		Element(string tN, list<Attribute> a, string iH) : tagname(tN), attrList(a), innerhtml(iH), bslash(false){};

		//Consult
		string tagName() { return tagname; }
		list<Attribute> AttributeList() { return attrList; }
		string innerHTML() { return innerhtml; }
		bool itsTheEnd() {return bslash;}
		void print();

		//Modifier
		void setTagName(string tagN) { tagname = tagN; }
		void setAttributeList( list<Attribute> listofattributes) { attrList = listofattributes; }
		void setinnerHTML(string inner) { innerhtml = inner; }
		list<Element> convertToElem(list<string> input);
		
		//Overload of operators
		//=
		Element &operator=(const Element &);
		//<<
		friend ostream &operator<<(ostream &, const list<Attribute> &);
		friend ostream &operator<<(ostream &, const Element &);	
};


list<Element> Element :: convertToElem(list<string> input)
{
  string elem;
  Element newElem;
  list<Attribute> attrList;
  Attribute info;
  elem = input.front();
  string name, value;
  string todaList;
  list<string> aux, aux2; 
  list<Element> listofElem;
  bool flagTag, theEnd, flagAName, flagAValue;
  bool aSlash;
  int cont;

  
  while(!input.empty())
  {
    elem = input.front();
    std::string::iterator it = elem.begin();
    newElem.tagname.clear();
    newElem.attrList.clear();
    newElem.innerhtml.clear();
    newElem.bslash = false;
    todaList.clear();
       
    aSlash = flagTag = theEnd = flagAName = flagAValue = false;
    cont = 0;
    
      if( *it == '<' )
      {
          it++;
	
            while(!theEnd)
            {
                if(*it == '/')
                {
                  newElem.bslash = true;

                }
                  if(*it == '!')//if header or comment
                  {
                      newElem.tagname += *it;
                      it++;

                      if(*it == 'd' || *it == 'D')
                      {
                          while(!flagTag)
                          {
                              if(*it != '>')
                              {
                                  newElem.tagname += *it;
                                  *it++;
                              }else
                                flagTag=true;
                          }

                          theEnd=true;
                          cont =2;

                      }

                  }else
                  {
                      if(*it != ' ' && !flagTag) // saving tag
                      {
                        newElem.tagname += *it;

                      }else{

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
                                  newElem.attrList.push_back(info);

                                  //reset flags and local strings
                                  flagAName = false;
                                  flagAValue = false;
                                  name.clear();
                                  value.clear();
                                  cont = 0;

                                  if(*it == '>')
                                  {
                                      theEnd=true;
                                  }
                              }
                          }
                      }
                  }
                
                it++;

                if(*it == '>')
                {
                    it++;
                    theEnd=true;	
                }
            }

            if(theEnd)
            {

                if( it != elem.end())
                {   

                    while(*it != '<') // saving innerHTML
                    {     
                        newElem.innerhtml += *it;
                        it++;
                    }

                    if(*it == '<') //there is more info
                    {  
                        it++;
                        if(*it == '/')
                        {
                            newElem.bslash = true; // it means thats a tag closed

                            while(*it != '>')
                            {
                                it++:
                            }


                            it++;
                            if(*it == '<')
                            {
                                while( it != elem.end())
                                {
                                    todaList += *it;
                                    *it++;
                                }
                            }

                        }else
                        {

                            todaList += '<';
                        }

                        if(!newElem.bslash)
                        {

                            while( it != elem.end())
                            {
                                todaList += *it;
                                *it++;
                            }
                        }

                        if(!todaList.empty())
                        {
                            input.push_back(todaList);
                        }
                    }
                }
            }
          }
      
          listofElem.push_back(newElem);
          input.pop_front();
  }
  
    return(listofElem);
  
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
