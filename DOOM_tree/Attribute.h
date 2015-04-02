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
		Attribute() : name(" "), value(" ") {};
		Attribute(string n, string v) : name(n), value(v) {};
		
		string getName() { return name; }
		string getValue() { return value; }
		
		void setName(string n) { name = n; }
		void setValue(string v) { value = v; }
		
		//Overload of operators
		//=
		Attribute &operator=(const Attribute &);
		//<<
		friend ostream &operator<<(ostream &, const Attribute &);
};

//Overloads

//= Attribute
Attribute &Attribute::operator=(const Attribute &orig)
{
	name = orig.name;
	value = orig.value;
	
	return *this;
}

//<< Attribute
ostream &operator<<(ostream &output, const Attribute &a)
{
	output << "Name: " << a.name << " Value: " << a.value;
	return output;
}

#endif // ATTRIBUTE_H_