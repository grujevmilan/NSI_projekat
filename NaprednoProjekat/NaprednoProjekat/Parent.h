#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include <algorithm>

using namespace std;

class Parent final : public Person //final
{
	std::vector<std::shared_ptr<Person>> children; //smart pointers
public:
	Parent();
	Parent(int, string); //inheritance constructor
	~Parent();
	void ChildrenSort(); //lambda, sort algorithm, auto
	void ShowChildren(); //range-based for loop
	void AddChild(std::shared_ptr<Person>); //std::vector
	void SayHello() override; //override
};

