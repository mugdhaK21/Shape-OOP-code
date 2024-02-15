#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>
using namespace std;

class Item {
protected:
    string name;
    double rentPrice;
    double depositAmount;

public:
    Item(const string& name, double rentPrice, double depositAmount); 

    virtual ~Item() {}

    void virtual displayDetails()  = 0;
    double virtual calculateRent(int duration)  = 0;
    string& getName();
    double getDepositAmount();
};

class Book : public Item {
    int subscriptionDuration; // in months

public:
    Book(const std::string& name, double rentPrice, double depositAmount, int subscriptionDuration);
   
    void displayDetails();
    double calculateRent(int duration);
};

class FlowerPot : public Item {
private:
    int subscriptionDuration; // in weeks

public:
    FlowerPot(const std::string& name, double rentPrice, double depositAmount, int subscriptionDuration);
    void displayDetails() ;
    double calculateRent(int duration) ;
};

class Camera : public Item {
public:
    Camera(const std::string& name, double rentPrice, double depositAmount);
    void displayDetails() ;
    double calculateRent(int duration) ;
};

class PCLaptop : public Item {
public:
    PCLaptop(const std::string& name, double rentPrice, double depositAmount);
    void displayDetails() ;
    double calculateRent(int duration) ;
};


class Customer {
private:
    string name;
    vector<Item*> rentedItems;

public:
    Customer(const std::string& name);

    void rentItem(Item* item);
    void displayRentedItems() ;
    // Other methods related to subscription and transactions can be added here
};

class Library {
private:
    vector<Item*> availableItems;
    vector<Item*> rentedItems;

public:
    void addItem(Item* item);
    void rentItem(Item* item, Customer& customer);
    void displayAvailableItems() ;
    void displayRentedItems() ;
    // Other methods like returnItem(), searchItem(), suggestItem() can be added here
};


#endif