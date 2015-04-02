#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#ifndef STRING
	#include <string>
	using std::string;
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
		
		//'=' Overload
		Attribute &operator=(const Attribute &);
		
};

Attribute &Attribute::operator=(const Attribute &orig)
{
	name = orig.name;
	value = orig.value;
	
	return *this;
}

#endif // ATTRIBUTE_H_