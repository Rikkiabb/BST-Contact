#include <iostream>
#include <vector>
#include "InteractivePhoneBook.h"
#include <cstdlib>

using namespace std;

int main()
{
    InteractivePhoneBook phonebook;
    phonebook.start();
    StringContactMap test;
    cout << "Empty: "<< test.empty()  << endl;
    Contact bleble;
    bleble.name = "Jón";
    bleble.phone = "1";
    bleble.email = "HA?";
    bleble.address = "HR";
    test.add("bla", bleble);
    Contact blabla;
    blabla.name = "Helga";
    blabla.phone = "2";
    blabla.email = "HMMMM?";
    blabla.address = "Laugavegur";
    test.add("ble", blabla);
    return 0;
}
