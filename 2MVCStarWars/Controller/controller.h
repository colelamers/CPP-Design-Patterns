#include "../Model/model.h"
#include "../View/view.h"

#define Print(x) view.printRecord(x); //#define function

class Controller {
private:
	Model model;
	View view;

public:
	string sithModel() {
		return model.sithModel();
	}
	string jediModel() {
		return model.jediModel();
	}

	inline void updateView(string jedi, string sith) {
		Print(jedi) //#define function
		Print(sith) //#define function
		view.printRecord(jedi);
		view.printRecord(sith);
	}
};