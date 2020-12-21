#pragma once
#include <iostream>
#include "Parent.h"

using namespace std;

class Son final : public Person
{
	std::pair<std::shared_ptr<Parent>, std::shared_ptr<Parent>> parents;
public:
	Son(int, string);
	~Son();
	void SayHello() override;
	void AddParent(shared_ptr<Parent>);
};

