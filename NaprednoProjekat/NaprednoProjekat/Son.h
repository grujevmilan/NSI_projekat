#pragma once
#include <iostream>
#include "Parent.h"

using namespace std;

class Son final : public Person //final
{
	std::pair<std::shared_ptr<Parent>, std::shared_ptr<Parent>> parents; //smart pointers
public:
	Son(int, string); //inheritance constructor
	~Son();
	void SayHello() override; //override
	void AddParent(shared_ptr<Parent>); //std::pair
};

