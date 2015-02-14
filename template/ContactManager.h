#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "StringContactMap.h"

using namespace std;

class ContactMissingException { };

class ContactManager
{
    public:
        // Adds the specified contact to the contact manager.
        void add(Contact contact);

        // Remove the contact with the specified name.
		// If no contact exists with the specified name this operation has no
		// effect.
        void remove(string name);

        // Updates the phone number of the contact with the specified name.
		// Throws ContactMissingException if no such contact exsits,
        void update_phone(string name, string new_number);

        // Updates the email address of the contact with the specified name.
		// Throws ContactMissingException if no such contact exsits,
        void update_email(string name, string new_email);

		// Returns true if and only if the contact manager has a contact with
		// the specified name.
		bool name_exists(string name);

		// Returns true if and only if the contact manager has a contact with
		// the specified phone.
		bool phone_exists(string phone);

		// Returns the contact with the specified name.
		// Throws ContactMissingException if no such contact exsits,
        Contact get_contact_by_name(string name);

		// Returns the contact with the specified phone number.
		// Throws ContactMissingException if no such contact exsits,
        Contact get_contact_by_phone(string phone);

		// Uncomment for part C
		// Returns a vector containing the contacts in this contact manager,
		// whose name is prefixed by 'name_prefix'. The contacts are ordered by
		// their names in increasing order,
		// NOTE: This is for part C of the assignment.
        vector<Contact> get_contacts_by_name_prefix(string name_prefix);

		// Returns a vector containing the contacts in this contact manager,
		// whose phone is prefixed by 'phone_prefix'. The contacts are ordered
		// by their phone numbers in increasing (lexicographical) order,
		// NOTE: This is for part C of the assignment.
        vector<Contact> get_contacts_by_phone_prefix(string phone_prefix);

		// Outputs all the contacts of this contact manager twice. First
		// ordered by name and then by phone number.
        friend ostream& operator<< (ostream& out, ContactManager& manager);

    private:
        StringContactMap name_map;
        StringContactMap phone_map;

};

#endif
