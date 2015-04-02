#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#ifndef STRING
	#include <string>
	using std::string;
#endif

#ifndef IOSTREAM
	#include <iostream>
	using std::cout;
	//using std::ostream;
#endif

class attribute
{
	private:
		string name, value;
	
	public:
		//Builders
		attribute() : name(" "), value(" ") {};
		attribute(string n, string v) : name(n), value(v) {};
		
		string getName() { return name; }
		string getValue() { return value; }
		
		void setName(string n) { name = n; }
		void setValue(string v) { value = v; }
		
		//Overload of operators
		//=
		attribute &operator=(const attribute &);
		//<<
		friend ostream &operator<<(ostream &, const attribute &);
};

//Overloads

//= attribute
attribute &attribute::operator=(const attribute &orig)
{
	name = orig.name;
	value = orig.value;
	
	return *this;
}

//<< attribute
ostream &operator<<(ostream &output, const attribute &a)
{
	output << "Name: " << a.name << " Value: " << a.value;
	return output;
}

#endif // ATTRIBUTE_H_