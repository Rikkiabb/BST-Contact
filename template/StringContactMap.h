#ifndef STRINGCONTACTMAP_H
#define STRINGCONTACTMAP_H

#include <iostream>
#include <string>
#include <vector>
#include "ContactNode.h"

class KeyException { };

class StringContactMap {
    
public:
    // Creates an empty map.
    StringContactMap ();
    
    ~StringContactMap();
    
    // Returns the number ef entries in this map.
    int size() const;
    
    int size(NodePtr Node) const;
    
    // Returns true if and only if the map contains no entries.
    bool empty() const;
    
    // Returns a vector containing the contacts in this map, ordered by
    // their keys in increasing order.
    vector<Contact> all_contacts() const;
    
    vector<Contact> all_contacts(NodePtr node, vector<Contact>& inorderTraversal) const;
    
    // Adds the specified key to the map associated with the specified
    // contact.
    // If there exists an entry in the map with the specified key, it
    // should be replaced with the specified value.
    void add(string key, Contact value);
    
    // Returns true if and only if there exists an entry in the map with
    // the specified key.
    bool contains(string key) const;
    
    // Returns the contact associated wih the specified key.
    // Throws KeyException if no such contact exists.
    Contact get(string key) const;
    
    // Removes the entry with the specified key from the map.
    // If no entry in the map has the specified key, this operation has no
    // effect.
    void remove(string key);
    
    // Returns a vector containing the contacts in this map, whose key is
    // prefixed by 'prefix'. The contacts are ordered by their
    // keys in increasing order,
    // NOTE: This is for part C of the assignment.
    vector<Contact> prefix_search(string prefix) const;
    
    friend ostream& operator <<(ostream& out, const StringContactMap& map);
    
private:
    NodePtr root;
    
    // Deallocates all memory allocated for the specified tree.
    void free_memory(NodePtr node);
    
    // Adds the specified key, to the specified tree, associated with the
    // specified contact.
    // If there exists an entry in the tree with the specified key, it
    // should be replaced.
    // Note: This is an optional helper function
    void add(NodePtr& node, string key, Contact value);
    
    // Returns true if and only if there exists an entry in the map with
    // the specified key in the specified tree.
    // Note: This is an optional helper function
    bool contains(NodePtr node, string key) const;
    
    // Returns the contact associated wih the specified key in the
    // specified tree.
    // Throws KeyException if no such contact exists.
    // Note: This is an optional helper function
    Contact get(NodePtr node, string key) const;
    
    // Removes the node with the specified key from the specified tree
    void remove(NodePtr& node, string key);
    
    // Removes the root node of the specified tree.
    void remove_root(NodePtr& node);
    
    // Removes the node with the smallest key from the specified tree and
    // returns a pointer to that node.
    NodePtr remove_min(NodePtr& node);
    
    // Adds the the Contacts in the specified tree, whose key is prefixed
    // by 'prefix', to the vector v. The contacts are ordered by their keys
    // in increasing order.
    // Uncomment for part C.
    // NOTE: This is for part C of the assignment.
    void prefix_search(NodePtr node, string prefix, vector<Contact>& v) const;
};

#endif
