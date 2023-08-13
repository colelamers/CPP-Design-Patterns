#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define carModelSearch(i) find(choice) != carModel[i]->outputModel().end()

// Created by Cole Lamers

using namespace std;

class Car {
public:

    // Factory Method, note it's static
    static Car* make_car(string choice, int price);

    // method that we will use polymorphically per product
    virtual void outputInfo() = 0;
    virtual void outputPrice() = 0;
    virtual string outputModel() = 0;

    // Note: need to specify an explicicit default destructor
    virtual ~Car() = default;
};

class Chevy : public Car {
private:
    int price = 0;
    string model = "";
public:
    Chevy(string choice, int carPrice) {
        price = carPrice;
        model = choice;
    }
    void outputInfo() {
        cout << "This brand could technically be considered an extension of the GMC class. Oh wait, thats just a subsidiary.\n\n";
    }
    void outputPrice() {
        cout << "$" << price;
    }
    string outputModel() {
        return model;
    }
};

class Ford : public Car {
private:
    int price = 0;
    string model = "";
public:
    Ford(string choice, int carPrice) {
        price = carPrice;
        model = choice;
    }
    void outputInfo() {
        cout << "These once were as contentious of a brand as the US political climate today!\n\n";
    }
    void outputPrice() {
        cout << "$" << price;
    }
    string outputModel() {
        return model;
    }
};

class Dodge : public Car {
private:
    int price = 0;
    string model = "";
public:
    Dodge(string choice, int carPrice) {
        price = carPrice;
        model = choice;
    }
    void outputInfo() {
        cout << "The Dodge is a funny vehicle that is ultimately the \"Schrodingers Car\" in terms of if it's good or not.\n\n";
    }
    void outputPrice() {
        cout << "$" << price;
    }
    string outputModel() {
        return model;
    }
};

class Used : public Car {
private:
    int price = 0;
    string model = "";
public:
    Used(string choice, int carPrice) {
        price = carPrice;
        model = choice;
    }
    void outputInfo() {
        cout << "A generic vehicle that we aren't too concerned on the details of.\n\n";
    }
    void outputPrice() {
        cout << "$" << price;
    }
    string outputModel() {
        return model;
    }
};


// this is the FACTORY Method
// it does need to know about the derived methods
// but this allows us to abstract this from our 
// "client" calling code in main()
Car* Car::make_car(string choice, int price) {
    if (choice == "Chevy")
        return new Chevy(choice, price);
    else if (choice == "Ford")
        return new Ford(choice, price);
    else if (choice == "Dodge")
        return new Dodge(choice, price);
    else
        return new Used(choice, price);
}


// main() is considered the "client"
// while in this example we could hard code the
// derived classes since we are making a menu anyway
// imagine having 

int main() {
    vector<Car*> carModel;
    vector<string> carlist;

    string choice;
    int price = 0;
    while (true) {
        cout << "Enter a car sold today:\n"
            << "(Press 0 to end entries)" << endl;
        cin >> choice;
        if (choice == "0") break;
        cout << "Price? (ignore change): ";
        cin >> price;
        carModel.push_back(Car::make_car(choice, price));
    }//Constructs the objects entered

    while (true) {
        string action;
        cout << "\nWhat would you like to do?\n" 
            << "1: Generate todays vehicles sold report\n"
            << "2: Generate todays sales report\n"
            << "0: Quit program\n";
        cin >> action;
        if (action == "1") {
            for (int i = 0; i < carModel.size(); i++) {
                cout << carModel[i]->outputModel() << endl;
                carModel[i]->outputInfo();
            }//this adds all the vehicles from the carModel vector as string values to this vector
            cout << "What vehicle would you like to learn about?";
        }
        else if (action == "2") {
            for (int i = 0; i < carModel.size(); i++) {
                carModel[i]->outputPrice();
                cout << ", " << carModel[i]->outputModel() << endl;
            }
        }
        else if (action == "0") break;
        else {
            cout << "Not a proper entry. Please try again.";
        }
    }//Performs the action the user inputs
    for (int i = 0; i < carModel.size(); i++) {
        delete carModel[i];
    }
}