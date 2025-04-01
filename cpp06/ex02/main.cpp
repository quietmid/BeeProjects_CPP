#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"

Base* generate(void)
{
	//seeding the random number generator with the current time to ensure randomness
	// srand(time(0));
	int random = rand() % 3;
    switch (random)
    {
        case 0:
            return new BaseA();
        case 1:
            return new BaseB();
        case 2:
            return new BaseC();
        default:
            return nullptr; // just in case, though it should never hit this
    }
}

void identify(Base* pointer)
{
	if (pointer == nullptr)
	{
		std::cout << "this base doesn't exist" << std::endl;
		return;
	}
	if (dynamic_cast<BaseA*>(pointer))
		std::cout << "Base A" << std::endl;
	else if (dynamic_cast<BaseB*>(pointer))
		std::cout << "Base B" << std::endl;
	else if (dynamic_cast<BaseC*>(pointer))
		std::cout << "Base C" << std::endl;
	else
		std::cout << "Unknown Base Type" << std::endl;
};
void identify(Base& reference)
{
	try {
		BaseA &a = dynamic_cast<BaseA&>(reference);
		std::cout << "This is Base A" << std::endl;
		(void)a;
	} catch (std::bad_cast &e) {
		try {
			BaseB &b = dynamic_cast<BaseB&>(reference);
			std::cout << "This is Base B" << std::endl;
			(void)b;
		} catch (std::bad_cast &e) {
			try {
				BaseC &c = dynamic_cast<BaseC&>(reference);
				std::cout << "This is Base C" << std::endl;
				(void)c;
			} catch (std::bad_cast &e) {
				std::cout << "Unknown Base Type" << std::endl;
			}
		}
	}
};



int main()
{
	//seeding the random number generator with the current time to ensure randomness
	srand(time(0));

	std::cout << "<---Test 1--->" << std::endl;
	Base* base = generate();
	identify(base);

	std::cout << "<---Test 2--->" << std::endl;
	Base* base1 = generate();
	identify(base1);

	std::cout << "<---Test 3--->" << std::endl;
	Base* base2 = generate();
	identify(base2);


	std::cout << "<---testing & and * --->" << std::endl;
	Base *base3 = nullptr;
	// BaseZ z;
	identify(*base);
	identify(*base1);
	identify(*base2);
	identify(base3);
	// identify(z);

	std::cout << "-----deleting test subjects ..." << std::endl;
	delete base;
	delete base1;
	delete base2;
	
	return 0;
};