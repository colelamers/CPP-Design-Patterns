#ifndef FORCEBEING_H
#define FORCEBEING_H

#include <iostream>
#include <string>

using namespace std;

class ForceBeing {
private:
	int power_level;
	std::string name;
	bool evil;

protected:
	ForceBeing(int level) {
		power_level = level;
	}
	void setName(string characterName) {
		name = characterName;
	}
	void setPowerLevel(int level) {
		power_level = level;
	}

public:
	virtual int getPowerLevel() {
		return power_level;
	}
	void setEvil() {
		evil = true;
	}
	virtual string getName() {
		return name;
	}
	void setGood() {
		evil = false;
	}
};

#endif