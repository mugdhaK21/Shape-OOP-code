#include<iostream>
#include "item.h"
using namespace std;

int main() {
    Library library;

    // Adding items to library
    library.addItem(new Book("Harry Potter", 10.0, 20.0, 1));
    library.addItem(new FlowerPot("Clay Pot", 5.0, 10.0, 1));
    library.addItem(new Camera("Canon EOS", 20.0, 50.0));
    library.addItem(new PCLaptop("MacBook Pro", 50.0, 100.0));

    // Display available items
    library.displayAvailableItems();

    // Renting an item
    Customer customer("John Doe");
    Item* itemToRent = new Camera("Canon EOS", 20.0, 50.0);
    library.rentItem(itemToRent, customer);

    // Display rented items
    customer.displayRentedItems();

    return 0;
}