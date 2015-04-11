/*
 * Attribute.h
 *
 *  Created on: 30/3/2015
 *  Author(s): Marien
 *		   	   Sergio
 */
 
#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#ifndef STRING
	#include <string>
	using std::string;
#endif

#ifndef IOSTREAM
	#include <iostream>
	using std::cout;
	using std::ostream;
#endif

class Attribute
{
	private:
		string name, value;
	
	public:
		//Builders
		Attribute() : name(), value() {};
		Attribute(string n, string v) : name(n), value(v) {};
		Attribute(const Attribute &);
		
		string getName() { return name; }
		string getValue() { return value; }
		
		void setName(string n) { name = n; }
		void setValue(string v) { value = v; }
		
		//Overload of operators
		//=
		Attribute &operator=(const Attribute &);
		//==
		bool operator==(Attribute );
		//<<
		friend ostream &operator<<(ostream &, const Attribute &);
};

//Copy Builder
Attribute :: Attribute(const Attribute &orig)
{
	*this = orig;
}

//Overloads

//= Attribute
Attribute &Attribute::operator=(const Attribute &orig)
{
	name = orig.name;
	value = orig.value;
	
	return *this;
}

//==
bool Attribute::operator==(Attribute orig)
{
	return(name == orig.name && value == orig.value);
}

//<< Attribute
ostream &operator<<(ostream &output, const Attribute &a)
{
	output << "" << a.name << "=" << "\"" << a.value << "\"";
	return output;
}

#endif // ATTRIBUTE_H_