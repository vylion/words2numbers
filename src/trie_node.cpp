#include "trie_node.hpp"

typedef std::unordered_map<char, TrieNode *>::iterator ChildIt;

TrieNode *TrieNode::next(char c)
{
    if (_children.find(c) != _children.end())
    {
        return _children[c];
    }

    TrieNode *new_child = new TrieNode;
    _children[c] = new_child;

    return new_child;
}

bool TrieNode::hasChildren()
{
    return _children.size() > 0;
}

bool TrieNode::insert(const std::string &word, int &pos)
{
    if (pos == word.length())
    {
        if (!_is_leaf)
        {
            _is_leaf = true;
            return true;
        }
        return false;
    }
    else
    {
        char c = word[pos];
        TrieNode *next_node = next(c);
        pos++;

        return next_node->insert(word, pos);
    }
}

bool TrieNode::remove(const std::string &word, int &pos, bool &to_remove)
{
    // base case: end of string
    if (pos == word.length() && _is_leaf)
    {
        _is_leaf = false;
        to_remove = !hasChildren(); //to be deleted if no _children
        return true;
    }

    // otherwise keep going
    char c = word[pos];
    pos++;
    ChildIt it = _children.find(c);

    // found nothing
    if (it == _children.end())
    {
        to_remove = false;
        return false;
    }

    bool success = it->second->remove(word, pos, to_remove);

    // if child gets marked for removal
    if (to_remove)
    {
        delete it->second;                       // delete the pointer
        _children.erase(it);                     // remove the entry
        to_remove = !_is_leaf && !hasChildren(); // remove if not a leaf either and no more _children remaining
    }

    return success;
}

bool TrieNode::search(const std::string &word, int &pos)
{
    if (pos == word.length())
    {
        return _is_leaf;
    }

    char c = word[pos];
    pos++;
    ChildIt it = _children.find(c);

    if (it == _children.end())
    {
        return 0;
    }

    return it->second->search(word, pos);
}

int TrieNode::size()
{
    return _children.size();
}
