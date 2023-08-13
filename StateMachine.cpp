#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Attack;
class TypeOfAttack;
class Punch;
class Kick;
class Headbutt;

class Attack {
public:
	virtual void alert(TypeOfAttack* ctx) = 0;

	virtual ~Attack() {}
};

class Punch : public Attack {
public:
	void alert(TypeOfAttack* ctx) {
		cout << "You performed a punch...\n";
	}
};

class Kick : public Attack {
public:
	void alert(TypeOfAttack* ctx) {
		cout << "You performed a kick...\n";
	}
};

class Headbutt : public Attack {
public:
	void alert(TypeOfAttack* ctx) {
		cout << "You performed a headbutt...\n";
	}
};

class TypeOfAttack {
private:
	Attack* currentAttack;

public:
	TypeOfAttack(Attack* state) {
		currentAttack = state;
	}

	void setAttack(Attack* state) {
		currentAttack = state;
	}

	Attack* getAttack() {
		return currentAttack;
	}

	void alert() {
		currentAttack->alert(this);
	}
};

string contextAction(TypeOfAttack* toa, int& monsterHealth) { //pass by reference because we want it to actually modify the global variable set
	int dmg = rand() % 50 + 1;
	bool boolHitMiss = (rand() % 1) == 0 ? true : false;

	monsterHealth = monsterHealth - dmg;
	toa->alert();
	if (boolHitMiss) {
		return "It did " + to_string(dmg) + " amount of damage!\n\nMonster Health: " + to_string(monsterHealth) + "\n";
	}
	else {
		return "It missed!\n";
	}
}//will output info and explain the sucess of the result



int main() {
	Attack* punch = new Punch;//Sets the default state
	TypeOfAttack* stateContext = new TypeOfAttack(punch);
	int monsterHealth = 100;

	cout << "You encountered a monster. What would you like to do?\n1.Punch\n2.Kick\n3.Headbutt" << endl;
	cout << "Monster Health: " << to_string(monsterHealth) << endl;
	while (monsterHealth > 0) {
		int globalInputVar;
		while (true) {
			string userInput;
			cin >> userInput;
			if (userInput == "1" || userInput == "2" || userInput == "3") {
				globalInputVar = stoi(userInput);
				break;
			}
			else {
				cout << "Please enter a legitimate input." << endl;
			}
		}//gets 1, 2, or 3 only

		//int inputAsInt = stoi(userInput);
		switch (globalInputVar) {
		case 1:
		{
			cout << contextAction(stateContext, monsterHealth);
			break;
		}
		case 2:
		{
			Attack* kick = new Kick;
			stateContext->setAttack(kick);

			cout << contextAction(stateContext, monsterHealth);
			break;
		}
		case 3:
		{
			Attack* headbutt = new Headbutt;
			stateContext->setAttack(headbutt);

			cout << contextAction(stateContext, monsterHealth);
			break;
		}

		}//determines the context action applied
	}
	cout << "Hooray! You killed the monster!" << endl;
}
