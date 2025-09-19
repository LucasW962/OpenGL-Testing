#include <iostream>
#include <memory>

class TestCases {
public:
	TestCases() {
		std::cout << "our constructor was called" << std::endl;
	}

	~TestCases() {
		std::cout << "our destructor was called" << std::endl;
	}
};


int main() {

	std::unique_ptr<TestCases> TestPtr = std::make_unique<TestCases>();


	return 0;
}