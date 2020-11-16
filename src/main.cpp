#pragma once
#include <iostream>
#include <cmath>
#include <vector>

// This C++ script is intended to outline an understanding of a bitwise categoristaion
// method using 2**(category) as the representation of the catagory.

// For example, if there is an array of integer values which are flags for categories that an object has
// such as: arr = [1, 3, 5, 6, 8, 2] this array could be represented by a single integer (categories) built with the following loop:
//      int categories = 0;
//      for (int i : arr) {
//          categories += std::pow(2, i);
//      }



// A class template for an example object which holds permission levels in an encoded integer method which is compatible with the 
// bitwise-categorisation method
class Item {
public:
    Item(std::vector<int> permissionsIn) {
        for (int  i : permissionsIn) {
            permissions += std::pow(2, i);
        }
    }
    void SetPermissions(std::vector<int> permissionsIn) {
        int encodedVal = 0;
        // loop through inputted arrray of permissions
        for (int  i : permissionsIn) {
            // encode int array value
            encodedVal = std::pow(2, i);
            // check exclusivity of array value with obj's permissions variable 
            if ((encodedVal & permissions) != 0 ) {
                // if not already in permissions then add to the permissions value
                permissions += encodedVal;
            }
        }
    }
    int GetPermissions() {
        return permissions;
    }
private:
    int permissions = 0;
};

//this could be a security wrapper function for allowing/not-allowing an object access to something in a program
// the item's permissions must include 3, 4 and 8
bool canItPass(Item* it) {
    //set the required permissions
    int requiredPermissions = std::pow(2, 8) + std::pow(2, 4) + std::pow(2, 3);
    
    //check if the item's permssions includes the needed permissions
    if ((it->GetPermissions() & requiredPermissions) == requiredPermissions ) {
        // allow access
        return true;
    }
    // deny access
    return false;
}

// workings and tests
int main() {
    //define some encoded values
    int one = std::pow(2, 1); // 2
    int seven = std::pow(2, 7);
    int oneAndSeven = std::pow(2, 1) + std::pow(2, 7); // 130
    int nine  = std::pow(2, 9);
    int eight = std::pow(2, 8);
    // do some simple bitwise operations to ensure that the concept works
    std::cout << "oneAndSeven:\t\t" << oneAndSeven << std::endl;
    std::cout << "one & oneAndSeven:\t" << (one & oneAndSeven) << std::endl;
    std::cout << "seven & oneAndSeven:\t" << (seven & oneAndSeven) << std::endl;
    std::cout << "nine & oneAndSeven:\t" << (nine & oneAndSeven) << std::endl;
    int allVals = 1022;
    //has categories 1, 2, 3, 4, 5, 6, 7, 9
    char charArr[] = {'1', '2', '3', '4', '5', '6', '7', '9'};
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int arrVals = 0;
    int encodedVal = 0;
    for (int i  : arr) {
        encodedVal = std::pow(2, i);
        arrVals += encodedVal;
    }

    std::cout << "0)" << arrVals << std::endl;

    std::cout << "1)" << (one & arrVals) << std::endl;
    
    std::cout << "2)" << (nine & arrVals) << std::endl;

    int charArrVals = 0;
    for (int i  : charArr) {
        encodedVal = std::pow(2, i - 48);
        charArrVals += encodedVal;
    }


    std::cout << "3)" << charArrVals << std::endl;

    std::cout << "4)" << (one & charArrVals) << std::endl;

    std::cout << "5)" << (nine & charArrVals) << std::endl;

    std::cout << "6)" << (eight & charArrVals) << std::endl;



    // initialise a couple of objects of class Item
    // one which has permissions to pass func canItPass() 
    // one which doesn't
    std::vector<int> goodPermissions = {1, 2, 3, 4, 7, 8};
    Item item1(goodPermissions);
    std::vector<int> badPermissions = {1, 2, 4, 7, 8};
    Item item2(badPermissions);

    std::cout << "badPermissions: " << canItPass(&item2) << std::endl;
    std::cout << "goodPermissions: " << canItPass(&item1) << std::endl;
}