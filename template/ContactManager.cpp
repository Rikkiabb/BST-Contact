#include "ContactManager.h"

// Adds the specified contact to the contact manager.
// Vid erum med tvo mop og tvi latum vid inn i baedi.
// Munurinn er ad i name_map ta er name key en i phone_map er phone key
void ContactManager::add(Contact contact)
{
    name_map.add(contact.name, contact);
    phone_map.add(contact.phone, contact);
}

// Remove the contact with the specified name.
// If no contact exists with the specified name this operation has no
// effect.
// Fyrst skodum vid hvort nafnid er til, ef tad er ekki til ta gerum vid ekkert annars. Finnum vid tad eftir nafni og sima og eydum tvi ur badum kortum.
// vid turfum ad finna tad eftir nafni og sima utaf tvi ad key i phone_map er siminn.
void ContactManager::remove(string name)
{
    if (!name_exists(name))
    {
        return;
    }
    else
    {
        string phone = get_contact_by_name(name).phone;
        name_map.remove(name);
        phone_map.remove(phone);
    }
}

// Updates the phone number of the contact with the specified name.
// Throws ContactMissingException if no such contact exsits,
// Vid getum ekki uppfaert simanumer sem er ekki til svo ef er verid ad reyna gera tad, ta hendum vid villu.
// Annars geymum vid núverandi contact og breytum simanumeri hans svo eydum vid honum ut med gamla numerinu, svo tad eru ekki tveir sem eru sa sami med tvo mismunandi numer og svo baetum vid uppfaerda adilanum vid mapid.
void ContactManager::update_phone(string name, string new_number)
{
    if (!name_exists(name))
    {
        throw ContactMissingException();
    }
    else
    {
        Contact Update = name_map.get(name);
        Update.phone = new_number;
        remove(name);
        add(Update);
    }
}

// Updates the email address of the contact with the specified name.
// Throws ContactMissingException if no such contact exsits,
// Gerum tad sama og med update_phone nema med email
void ContactManager::update_email(string name, string new_email)
{
    if (!name_exists(name))
    {
        throw ContactMissingException();
    }
    else
    {
        Contact Update =  name_map.get(name);
        Update.email = new_email;
        remove(name);
        add(Update);
    }
}

// Returns true if and only if the contact manager has a contact with
// the specified name.
// Notfaerum okkur fallid sem vid utfaerdum i StringContactMap
bool ContactManager::name_exists(string name)
{
	return name_map.contains(name);
}

// Returns true if and only if the contact manager has a contact with
// the specified phone.
// -||-
bool ContactManager::phone_exists(string phone)
{
	return phone_map.contains(phone);
}

// Returns the contact with the specified name.
// Throws ContactMissingException if no such contact exsits,
// Ef nafnid er ekki til ta kostum vid villu
// Annars notfaerdum vid okkur get fallid
Contact ContactManager::get_contact_by_name(string name)
{
    if (!name_exists(name))
    {
        throw ContactMissingException();
    }
    else
    {
        return name_map.get(name);
    }
}

// Returns the contact with the specified phone number.
// Throws ContactMissingException if no such contact exsits,
// -||-
Contact ContactManager::get_contact_by_phone(string phone)
{
    if (!phone_exists(phone))
    {
        throw ContactMissingException();
    }
    else
    {
        return phone_map.get(phone);
    }
}

// Uncomment for part C
// Returns a vector containing the contacts in this contact manager,
// whose name is prefixed by 'name_prefix'. The contacts are ordered by
// their names in increasing order,
// NOTE: This is for part C of the assignment.
// Notfaerdum okkur fallid i StringContactMap og skilum sem kemur ur tvi
vector<Contact> ContactManager::get_contacts_by_name_prefix(string name_prefix)
{
    vector<Contact> name = name_map.prefix_search(name_prefix);
	return name;
}

// Returns a vector containing the contacts in this contact manager,
// whose phone is prefixed by 'phone_prefix'. The contacts are ordered
// by their phone numbers in increasing (lexicographical) order,
// NOTE: This is for part C of the assignment.
// -||-
vector<Contact> ContactManager::get_contacts_by_phone_prefix(string phone_prefix)
{
    vector<Contact> phone = phone_map.prefix_search(phone_prefix);
	return phone;
}

// Outputs all the contacts of this contact manager twice. First
// ordered by name and then by phone number.
ostream& operator<< (ostream& out, ContactManager& manager)
{
	out << manager.name_map << endl << endl;
	out << manager.phone_map;
	return out;
}
