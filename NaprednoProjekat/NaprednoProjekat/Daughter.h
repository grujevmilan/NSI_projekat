#include <iostream>
#include "Parent.h"

using namespace std;

class Daughter final : public Person
{
	std::pair<weak_ptr<Parent>, weak_ptr<Parent>> parents;
public:
	Daughter(int, string);
	~Daughter();
	void SayHello() override;
	void AddParent(weak_ptr<Parent> parent);
};

