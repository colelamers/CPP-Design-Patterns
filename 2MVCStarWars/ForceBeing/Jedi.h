#include <iostream>
#include <string>
#include "ForceBeing.h"

class Jedi : public ForceBeing {

public:
	Jedi(string jediName, int level) :ForceBeing(level) {
    
		setName(jediName);
		setGood();
	}
	int getPowerLevel() {
		return ForceBeing::getPowerLevel() + 1;
	}
};
