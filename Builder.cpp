#include <iostream>
using namespace std;

// Your end product 
class AppleProduct {
	string _product;
	string _input;
	string _processor;
	string _size;
	string _performance;

public:

	AppleProduct(string set_product) { _product = set_product; }

	void setProcessor(string set_processor) { _processor = set_processor; }
	void setInput(string set_input) { _input = set_input; }
	void setSize(string set_size) { _size = set_size; }
	void setPerformance(string set_performance) { _performance = set_performance; }

	string getProcessor() { return _processor; }
	string getInput() { return _input; }
	string getSize() { return _size; }
	string getPerformance() { return _performance; }

	void show() {
		cout << "Apple Base Product Info: " << _product << endl;
		cout << "Input Type: " << _input << endl;
		cout << "Processor Type: " << _processor << endl;
		cout << "Model Size: " << _size << endl;
		cout << "Device performance: " << _performance << endl << endl;
	}
};

// AppleProductBuilder Abstract Class all builders should have at least these methods
class AppleProductBuilder {
protected:
	AppleProduct* _apple_product;
public:
	virtual void getOtherParts() = 0;
	virtual void buildInput() = 0;
	virtual void buildProcessor() = 0;
	virtual void buildSize() = 0;
	virtual void buildPerformance() = 0;

	AppleProduct* getAppleProduct() { return _apple_product; }
};

// AppleProductBuilder concrete class knows only how to build iPhone AppleProduct!
class iPhoneBuilder : public AppleProductBuilder {

public:

	void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPhone"); }

	void buildProcessor() { _apple_product->setProcessor("Apple ARM Processor"); }

	void buildInput() { _apple_product->setInput("Touchscreen Input"); }

	void buildSize() { _apple_product->setSize("7.5\" model"); }

	void buildPerformance() { _apple_product->setPerformance("Single Core Performance is at 12350"); }

};

// AppleProductBuilder concrete class knows only how to build Mac AppleProduct
class MacBuilder : public AppleProductBuilder {

public:

	void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Mac"); }

	void buildProcessor() { _apple_product->setProcessor("Intel Core i5 Processor"); }

	void buildInput() { _apple_product->setInput("Mouse and Keyboard Input"); }

	void buildSize() { _apple_product->setSize("21.5\" model"); }

	void buildPerformance() { _apple_product->setPerformance("Single Core Performance is at 55020"); }
};

class iPadBuilder : public AppleProductBuilder {

public:

	void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Mac"); }

	void buildProcessor() { _apple_product->setProcessor("A13 ARM Chip"); }

	void buildInput() { _apple_product->setInput("Retina Touch Display"); }

	void buildSize() { _apple_product->setSize("11\" model"); }

	void buildPerformance() { _apple_product->setPerformance("Single Core Performance is at 22421"); }
};

class appleWatchBuilder : public AppleProductBuilder {

public:

	void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Mac"); }

	void buildProcessor() { _apple_product->setProcessor("Power Saving A6 Chip"); }

	void buildInput() { _apple_product->setInput("Gorrilla Glass Touch Input"); }

	void buildSize() { _apple_product->setSize("2\" model"); }

	void buildPerformance() { _apple_product->setPerformance("Single Core Performance is at 938"); }
};

// Defines steps and tells to the builder that build in given order.
class Director {

	AppleProductBuilder* builder;

public:

	AppleProduct* createAppleProduct(AppleProductBuilder* builder) {
		builder->getOtherParts();
		builder->buildInput();
		builder->buildProcessor();
		builder->buildSize();
		builder->buildPerformance();

		return builder->getAppleProduct();
	}
};

int main() {

	Director dir;
	MacBuilder mb;
	iPhoneBuilder ib;
	iPadBuilder padb;
	appleWatchBuilder ab;

	AppleProduct* mac = dir.createAppleProduct(&mb);
	AppleProduct* iphone = dir.createAppleProduct(&ib);
	AppleProduct* ipad = dir.createAppleProduct(&padb);
	AppleProduct* watch = dir.createAppleProduct(&ab);


	mac->show();
	delete mac;

	iphone->show();
	delete iphone;

	ipad->show();
	delete ipad;

	watch->show();
	delete watch;

	return 0;
}