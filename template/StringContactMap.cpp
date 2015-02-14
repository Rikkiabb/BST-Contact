#include "StringContactMap.h"

using namespace std;

// Root byrjar i NULL
StringContactMap::StringContactMap ()
{
	root = NULL;
}

// Notfaerdum okkur free_memory, tar sem tar er haegt ad nota recursion
StringContactMap::~StringContactMap()
{
	free_memory(root);
}

// Returns the number ef entries in this map.
// Ef ekkert stak er til ta er treid tomt og vid skilum 0.
// Annars notfaerum vid okkur hjalparfallid.
int StringContactMap::size() const
{
    if (empty())
    {
        return 0;
    }
    else
    {
        return size(root);
    }
}

// Ef root er NULL, ta er treid tomt.
bool StringContactMap::empty() const
{
	return root == NULL;
}

// Returns a vector containing the contacts in this map, ordered by
// their keys in increasing order.
// Hjalparfallid tekur vid vector og nodu, tvi buum vid til vector her og hendum honum og nodu inn i hjalparfallid.
vector<Contact> StringContactMap::all_contacts() const
{
    vector<Contact> inorderTraversal;
    return all_contacts(root, inorderTraversal);
}

// Hjalparfall
// Ef noda er null ta skilum vid vectorinum.
// annars notum vid okkur stakinn og rodum i vectorinn infix. Ta er byrjad a laegsta gildinu og farid upp.
vector<Contact> StringContactMap::all_contacts(NodePtr node, vector<Contact>& inorderTraversal) const
{
    if (node == NULL)
    {
        return inorderTraversal;
    }
    else
    {
        all_contacts(node->left, inorderTraversal);
        inorderTraversal.push_back(node->value);
        all_contacts(node->right, inorderTraversal);
        return inorderTraversal;
    }
}

// Adds the specified key to the map associated with the specified
// contact.
// If there exists an entry in the map with the specified key, it
// should be replaced with the specified value.
// Ef root er tomt, ta buum vid til fyrstu noduna sem er root.
// Annars notfaerum vid okkur hjalparfall.
void StringContactMap::add(string key, Contact value)
{
    if (empty())
    {
        root = new ContactNode(key, value, NULL, NULL);
        return;
    }
    else
    {
        add(root, key, value);
    }
}

// Removes the entry with the specified key from the map.
// If no entry in the map has the specified key, this operation has no
// effect.
// Ef key er ekki til ta turfum vid ekki ad gera neitt og haettum.
// Annars notfaerum vid okkur hjalparfallid
void StringContactMap::remove(string key)
{
    if (!contains(key))
    {
        return;
    }
    else
    {
        remove(root, key);
    }
}

// Returns true if and only if there exists an entry in the map with
// the specified key.
// Notfaerum okkur hjalparfall sem tekur inn nodu.
bool StringContactMap::contains(string key) const
{
	return contains(root, key);
}

// Returns the contact associated wih the specified key.
// Throws KeyException if no such contact exists.
// Ef lykill er ekki til ta kostum vid villu
// Annars notfaerum vid okkur hjalparfall.
Contact StringContactMap::get(string key) const
{
    if (!contains(key))
    {
        throw KeyException();
    }
    else
    {
        return get(root, key);
    }
}

// Returns a vector containing the contacts in this map, whose key is
// prefixed by 'prefix'. The contacts are ordered by their
// keys in increasing order,
// Turfum ad bua til vector og notfaerum okkur svo hjalparfallid.
vector<Contact> StringContactMap::prefix_search(string prefix) const
{
    vector<Contact> prefixVec;
    prefix_search(root, prefix, prefixVec);
	return prefixVec;
}

// Adds the the Contacts in the specified tree, whose key is prefixed
// by 'prefix', to the vector v. The contacts are ordered by their keys
// in increasing order.
// Ef nodan er null ta haettum vid.
// Annars latum vid stackinn muna gildid a undirstrengnum.
// Rodum svo i vectorinn med recursion og notfaerum okkur infix.
void StringContactMap::prefix_search(NodePtr node, string prefix, vector<Contact>& v) const
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        string nodePref = node->key.substr(0, (prefix.length()));
        prefix_search(node->left, prefix, v);
        if (prefix == nodePref)
        {
            v.push_back(node->value);
        }
        prefix_search(node->right, prefix, v);
    }
}

// Turfum fyrst ad skoda hvort ad nodan til er null og ef svo er ta haettum vid keyrslu a fallinu.
// Annars vinnum vid okkur niður allar nodur og eydum upp.
void StringContactMap::free_memory(NodePtr node)
{
    NodePtr destruct = node;
    if (destruct == NULL)
    {
        return;
    }
    if (destruct->left != NULL)
    {
        free_memory(destruct->left);
    }
    if (destruct->right != NULL)
    {
        free_memory(destruct->right);
    }

    delete destruct;
}

// Hjalparfall
// Her faum vid nodu inn og notum recursion til ad telja hversu margar nodur eru i trenu.
int StringContactMap::size(NodePtr node) const
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return size(node->left) + size(node->right) + 1;
    }
}

// Adds the specified key, to the specified tree, associated with the
// specified contact.
// If there exists an entry in the tree with the specified key, it
// should be replaced.
// Note: This is an optional helper function
// Turfum fyrst ad skoda hvort vid turfum ad uppfaera nodu.
// Ef svo er ekki ta vinnum vid okkur ad rettum stad med tvi ad skoda staerd lykla. Ef lykill er minni en lykill nuverandi nodu ta forum vid til vinstri annars til haegri.
// Vid endurtokum tetta tangad til vid faum sama value og er til fyrir eda lendum a NULL
// Ef vid lendum a NULL ta buum vid til nyja nodu tar og tengjum treid vid hana
void StringContactMap::add(NodePtr& node, string key, Contact value)
{
    if (node->key == key)
    {
        node->value = value;
        return;
    }
    if (key < node->key)
    {
        if (node->left == NULL)
        {
            node->left = new ContactNode(key, value, NULL, NULL);
            return;
        }
        else
        {
            add(node->left, key, value);
        }
    }
    else
    {
        if(node->right == NULL)
        {
            node->right = new ContactNode(key, value, NULL, NULL);
            return;
        }
        else
        {
            add(node->right, key, value);
        }
    }
}

// Returns the contact associated wih the specified key in the
// specified tree.
// Throws KeyException if no such contact exists.
// Ef noda er ekki til ta kostum vid villu.
// Ef vid finnum retta nodu ta skilum vid henni.
// Ef vid erum ekki kominn ad henni ta leitum vid ad henni med tvi ad skoda hvort hun se i vinstra eda haegri treinu og gerum tetta tangad til vid finnum rettu noduna
Contact StringContactMap::get(NodePtr node, string key) const
{
    if (!contains(node, key))
    {
        throw KeyException();
    }
    
    else if (node->key == key)
    {
        return node->value;
    }
    
    else if (contains(node->left, key))
    {
        return get(node->left, key);
    }
    
    else
    {
        return get(node->right, key);
    }
    
}

// Returns true if and only if there exists an entry in the map with
// the specified key in the specified tree.
// Note: This is an optional helper function
// Skodum fyrst hvort ad noda se NULL, ef svo er ta er nodan ekki til stadar og vid skilum false.
// Ef vid finnum noduna ta skilum vid true
// Ef hvorugt af tessu a vid ta skodum vid staerd nuverandi nodu midad vid lykill og forum i att ad henni tangad til vid lendum a somu nodu og vid erum ad leita ad eda tangad til noda verdur ad NULL.
bool StringContactMap::contains(NodePtr node, string key) const
{
    if (node == NULL)
    {
        return false;
    }
    
    else if (node->key == key)
    {
        return true;
    }
    
    if (key < node->key)
    {
        return contains(node->left, key);
    }
    else
    {
        return contains(node->right, key);
    }
}

void StringContactMap::remove(NodePtr& node, string key)
{
	if(node == NULL) {
		return;
	} else if(node->key == key) {
		remove_root(node);
	} else if(key < node->key) {
		remove(node->left, key);
	} else {
		remove(node->right, key);
	}
}

void StringContactMap::remove_root(NodePtr& root)
{
	NodePtr succ;
	if(root->is_leaf()) {
		delete root;
		root = NULL;
	} else if(root->left == NULL) {
		succ = root->right;
		delete root;
		root = succ;
	} else if(root->right == NULL) {
		succ = root->left;
		delete root;
		root = succ;
	} else {
		NodePtr new_root = remove_min(root->right);
		new_root->left = root->left;
		new_root->right = root->right;
		delete root;
		root = new_root;
	}
}

NodePtr StringContactMap::remove_min(NodePtr& node)
{
	if(node->left == NULL) {
		NodePtr old_node = node;
		node = node->right;
		return old_node;
	} else {
		return remove_min(node->left);
	}
}

ostream& operator <<(ostream& out, const StringContactMap& map)
{
	vector<Contact> contacts = map.all_contacts();
    
	for(size_t i = 0; i < contacts.size(); i++) {
		out << contacts[i] << endl;
	}
	return out;
}

