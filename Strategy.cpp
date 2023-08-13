#include <iostream>

/*
* Created by Cole Lamers
*/

using namespace std;

class Strategy {
public:
	virtual int doOperation(int num1, int num2) = 0;
};

class OperationAdd :public Strategy {
public:
	int doOperation(int num1, int num2) {
		return num1 + num2;
	}
};

class OperationSubstract :public Strategy {

public:
	int doOperation(int num1, int num2) {
		return num1 - num2;
	}
};

class OperationMultiply :public Strategy {

public:
	int doOperation(int num1, int num2) {
		return num1 * num2;
	}
};

class OperationDivide :public Strategy {

public:
	int doOperation(int num1, int num2) {
		return num1 / num2;
	}
};

class Context {
private:
	Strategy* strategy;

public:
	Context(Strategy* new_strategy) {
		strategy = new_strategy;
	}

	void changeStrategy(Strategy* new_strategy) {
		strategy = new_strategy;
	}

	int executeStrategy(int num1, int num2) {
		return strategy->doOperation(num1, num2);
	}
}; //the flow of the strategy execution

int main() {
	char choice;
	int num1 = 0;
	int num2 = 0;
	OperationAdd add_strategy; //defaults to an add strategy
	Context context(&add_strategy);
	cout << "Calculator App" << endl;

	while (true)
	{
		cout << "Choose from the following options:" << endl
			<< "1: Add\n2: Subtract\n3: Multiply\n4: Divide\n0: Quit" << endl;

		cin >> choice;

		switch (choice) {
		case '1':
		{
			cout << "Enter the first number" << endl;
			cin >> num1;
			cout << "Enter the second number" << endl;
			cin >> num2;
			cout << endl
				<< "The answer is: " << context.executeStrategy(num1, num2) << endl << endl;
			break;
		}
		case '2':
		{
			OperationSubstract subtract_strategy;
			context.changeStrategy(&subtract_strategy);
			cout << "Enter the first number" << endl;
			cin >> num1;
			cout << "Enter the second number" << endl;
			cin >> num2;
			cout << endl
				<< "The answer is: " << context.executeStrategy(num1, num2) << endl << endl;
			break;
		}
		case '3':
		{
			OperationMultiply multiply_strategy;
			context.changeStrategy(&multiply_strategy);
			cout << "Enter the first number" << endl;
			cin >> num1;
			cout << "Enter the second number" << endl;
			cin >> num2;
			cout << endl
				<< "The answer is: " << context.executeStrategy(num1, num2) << endl << endl;
			break;
		}
		case '4':
		{
			OperationDivide divide_strategy;
			context.changeStrategy(&divide_strategy);
			cout << "Enter the first number" << endl;
			cin >> num1;
			cout << "Enter the second number" << endl;
			cin >> num2;
			cout << endl
				<< "The answer is: " << context.executeStrategy(num1, num2) << endl << endl;
			break;
		}
		case '0':
		{
			break;
		}
		}
	}
}