#ifndef ITEM_CPP
#define ITEM_CPP
#include "item.h"
#include <iostream>
#include <vector>
using namespace std;

Item::Item(const string& name, double rentPrice, double depositAmount) : name(name), rentPrice(rentPrice), depositAmount(depositAmount) {}

string& Item::  getName() {
    return name;
}
double Item::getDepositAmount() {
    return depositAmount;
}

Book::Book(const std::string& name, double rentPrice, double depositAmount, int subscriptionDuration)
    : Item(name, rentPrice, depositAmount), subscriptionDuration(subscriptionDuration) {}

void Book:: displayDetails() {
    std::cout << "Name: " << name << ", Rent Price: " << rentPrice << ", Subscription Duration: " << subscriptionDuration << " months\n";
}

double Book:: calculateRent(int duration) {
    return rentPrice * duration;
}

FlowerPot::FlowerPot(const std::string& name, double rentPrice, double depositAmount, int subscriptionDuration)
    : Item(name, rentPrice, depositAmount), subscriptionDuration(subscriptionDuration) {}

void FlowerPot::displayDetails()  {
    std::cout << "Name: " << name << ", Rent Price: " << rentPrice << ", Subscription Duration: " << subscriptionDuration << " weeks\n";
}

double FlowerPot::calculateRent(int duration) {
    return rentPrice * duration;
}

Camera::Camera(const std::string& name, double rentPrice, double depositAmount)
    : Item(name, rentPrice, depositAmount) {}

void Camera::displayDetails()  {
    std::cout << "Name: " << name << ", Rent Price: " << rentPrice << " per day\n";
}

double Camera::calculateRent(int duration)  {
    return rentPrice * duration;
}

PCLaptop::PCLaptop(const std::string& name, double rentPrice, double depositAmount)
    : Item(name, rentPrice, depositAmount) {}

void PCLaptop::displayDetails() {
    std::cout << "Name: " << name << ", Rent Price: " << rentPrice << " per week\n";
}

double PCLaptop::calculateRent(int duration){
    return rentPrice * duration;
}


Customer::Customer(const std::string& name) : name(name) {}

void Customer::rentItem(Item* item) {
    rentedItems.push_back(item);
}

void Customer::displayRentedItems()  {
    std::cout << "Rented Items:\n";
    for (const auto& item : rentedItems) {
        item->displayDetails();
    }
}

void Library::addItem(Item* item) {
    availableItems.push_back(item);
}

void Library::rentItem(Item* item, Customer& customer) {
    // Check if item is available
    auto it = std::find(availableItems.begin(), availableItems.end(), item);
    if (it != availableItems.end()) {
        availableItems.erase(it);
        rentedItems.push_back(item);
        customer.rentItem(item);
        std::cout << "Item rented successfully.\n";
    }
    else {
        std::cout << "Item not available for rent.\n";
    }
}

void Library::displayAvailableItems() {
    std::cout << "Available Items:\n";
    for (const auto& item : availableItems) {
        item->displayDetails();
    }
}

void Library::displayRentedItems() {
    std::cout << "Rented Items:\n";
    for (const auto& item : rentedItems) {
        item->displayDetails();
    }
}

#endif