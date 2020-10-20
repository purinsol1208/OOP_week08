#include <iostream>
using namespace std;

class StrategyPattern {
public:
	virtual int doOperation(int num1, int num2) = 0;
};

class OperationAdd : public StrategyPattern {
public:
	virtual int doOperation(int num1, int num2) {
		return num1 + num2;
	}
};

class OperationSubstract : public StrategyPattern {
public:
	virtual int doOperation(int num1, int num2) {
		return num1 - num2;
	}
};

class OperationMultiply : public StrategyPattern {
public :
	virtual int doOperation(int num1, int num2) {
		return num1 * num2;
	}
};

class Context {
private:
	StrategyPattern* strategy;
public:
	void setStrategy(StrategyPattern* strategy) {
		this->strategy = strategy;
	}
	int executeStrategy(int num1, int num2) {
		return strategy->doOperation(num1, num2);
	}
};

int main() {
	Context* context_ = new Context();
	StrategyPattern* A = new OperationAdd();
	context_->setStrategy(A);
	cout << "10 + 5 = " << context_->executeStrategy(10, 5) << endl;

	StrategyPattern* B = new OperationSubstract();
	context_->setStrategy(B);
	cout << "10 - 5 = " << context_->executeStrategy(10, 5) << endl;

	StrategyPattern* C = new OperationMultiply();
	context_->setStrategy(C);
	cout << "10 * 5 = " << context_->executeStrategy(10, 5) << endl;
	
	return 0;
}