#include <iostream>
#include "Parent.h"

using namespace std;

class Daughter final : public Person //final
{
	std::pair<weak_ptr<Parent>, weak_ptr<Parent>> parents; //smart pointers
public:
	Daughter(int, string); //inheritance constructor
	~Daughter();
	void SayHello() override; //override
	void AddParent(weak_ptr<Parent> parent); //std::pair
};

