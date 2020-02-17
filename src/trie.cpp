#include "trie.hpp"

bool Trie::insert(std::string word)
{
    int pos = 0;
    return _root->insert(word, pos);
}

bool Trie::remove(std::string word)
{
    int pos = 0;
    bool to_remove = false;
    return _root->remove(word, pos, to_remove);
}

bool Trie::search(std::string word)
{
    int pos = 0;
    return _root->search(word, pos);
}

bool Trie::empty()
{
    return !_root->hasChildren();
}

int Trie::size()
{
    return _root->size();
}
