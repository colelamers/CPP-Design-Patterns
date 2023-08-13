#include <iostream>



/* Cole Lamers 10/7/2020
* Modified the list length index to start at 0
* Added previous_item ListItem*
* Added the insertAtIndex() method
* Added the deleteAtIndex() method
*/

class ListItem {

private:

	const char* item;
	ListItem* next = nullptr;

public:

	ListItem(const char* newItem) {
		item = newItem;
		next = nullptr;
	}//sets initial to the string passed through, sets next to null

	ListItem* nextItem() {
		return next;
	}//next item check getter

	void setNextItem(ListItem* new_next) {
		next = new_next;
	}//next item setter

	const char* view() {
		return item;
	}//item getter

};

class LinkedList {

private:

	ListItem* first_item;
	ListItem* previous_item;
	int list_length;

	void deleteItem(ListItem* parent, ListItem* item) {
		parent->setNextItem(item->nextItem());
		delete item;
	}

public:

	LinkedList(const char* newItem) {
		first_item = new ListItem(newItem);
		list_length = 0;
	}//constructs the list item as the string value and the list length

	void addListItem(const char* newItem) {
		ListItem* new_item = new ListItem(newItem);//creates the new item with "bob" as a pointer to item = bob, next = null
		ListItem* current_item = first_item; //this is the first item
		ListItem* next_item = first_item->nextItem();
		while (next_item != nullptr) { //the first one is null, so it will jump to the set function
			current_item = next_item;
			next_item = current_item->nextItem();
		}//loops through the list of items
		current_item->setNextItem(new_item);//sets the next item of the previous one that was just a null that broke the loop
		list_length += 1;
	}

	void insertAtIndex(const char* newItem, int index) {
		ListItem* new_item = new ListItem(newItem);//creates the new item with "bob" as a pointer to item = bob, next = null
		ListItem* current_item = first_item; //this is the first item
		ListItem* next_item = first_item->nextItem();
		ListItem* swap_item;
		int itemIndex = 0;
		if (index <= list_length && index > -1) {
			while (current_item != nullptr) {
				if (itemIndex == 0 && index == 0) {
					swap_item = first_item;//holds first_item original value
					first_item = new_item;
					current_item = first_item;//might not have to do
					current_item->setNextItem(swap_item);
				}//separate if to catch the first_index because it is the basis for the whole list
				else if (itemIndex == index) {
					swap_item = current_item;//holds first_item original value
					current_item = new_item;
					current_item->setNextItem(swap_item);
					previous_item->setNextItem(current_item);
				}//finds the index and swaps the new item in there
				previous_item = current_item;
				next_item = current_item->nextItem();
				current_item = next_item;
				itemIndex += 1;
			}//loops through the list of items
			list_length += 1;
		}//allows for the method to run if the index chosen isn't out of bounds
		else {
			std::cout << "Index chosen is out of bounds." << std::endl;
		}//skips the loop if it is out of bounds
	}//finds the index position and inserts it in the list there

	void deleteAtIndex(int index) {
		ListItem* current_item = first_item; //this is the first item
		ListItem* next_item = first_item->nextItem();
		ListItem* swap_item;
		int itemIndex = 0;
		if (index <= list_length && index > -1) {

		while (current_item != nullptr) {
			if (itemIndex == 0 && index == 0) {
				swap_item = first_item;//holds first_item original value
				first_item = first_item->nextItem(); //might not have to do
				break;
			}//separate if to catch the first_index because it is the basis for the whole list
			else if (itemIndex == index) {
				previous_item->setNextItem(current_item->nextItem());
				break;
			}//removes the item at the index and reorganizes the list
			previous_item = current_item;
			current_item = next_item;
			next_item = current_item->nextItem();
			itemIndex += 1;
		}//loops through the list of items
		list_length -= 1;
		}//allows for the method to run if the index chosen isn't out of bounds
		else {
			std::cout << "Index chosen is out of bounds." << std::endl;
		}//skips the loop if it is out of bounds
	}//finds the index position and removes it from there

	int length() {
		return list_length;
	}//returns the list length

	void outputLength() {
		std::cout << length() << std::endl;
	}//prints out the list length

	void outputList() {
		std::cout << first_item->view() << std::endl;
		ListItem* next_item = first_item->nextItem();
		while (next_item != nullptr) {
			std::cout << next_item->view() << std::endl;
			next_item = next_item->nextItem();
		}
	}//prints out the list of contents (basically for loop)

};

int main() {
	LinkedList l("sam");
	l.outputList();
	l.outputLength();
	l.addListItem("bob");
	l.outputList();
	l.outputLength();
	l.addListItem("jan");
	l.outputList();
	l.outputLength();
	l.addListItem("cal");
	l.outputList();
	l.outputLength();
	l.addListItem("nat");
	l.outputList();
	l.outputLength();
	l.insertAtIndex("tim", 3);
	l.outputList();
	l.outputLength();
	l.deleteAtIndex(3);
	l.outputList();
	l.outputLength();
	return 0;
}