#pragma once
#include <string>
#include <iostream>

struct Person
{
	friend std::istream &read(std::istream&, Person&);
	friend std::ostream &print(std::ostream&, const Person&);
private:
	std::string name;
	std::string address;

public:
	std::string Name() const { return this->name; }
	std::string Address() const { return this->address; }
	Person() = default;
	explicit Person(std::string n) : name(n) {}
	Person(std::string n, std::string a) : name(n), address(a) {}
	explicit Person(std::istream &is) { read(is, *this); }

};



std::istream &read(std::istream &is, Person &person)
{
	is >> person.name >> person.address;
	return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
	os << person.Name() << " " << person.Address();
	return os;
}

