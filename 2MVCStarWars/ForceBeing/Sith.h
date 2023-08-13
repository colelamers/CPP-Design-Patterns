#include <iostream>
#include <string>
#include "ForceBeing.h"

class Sith : public ForceBeing {

public:
	Sith(string sithName, int level) :ForceBeing(level) {

		setName(sithName);
		setEvil();
	}
	int getPowerLevel() {
		return ForceBeing::getPowerLevel() - 1;
	}
};
