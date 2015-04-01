#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#ifndef STRING
	#include <string>
	using std::string;
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
		
		//Overload of operator '='
		attribute &operator=(const attribute &);
		
};

attribute &attribute::operator=(const attribute &orig)
{
	name = orig.name;
	value = orig.value;
	
	return *this;
}

#endif // ATTRIBUTE_H_