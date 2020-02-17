#ifndef TRIE_HPP
#define TRIE_HPP

#include <string>
#include <unordered_map>
#include "trie_node.hpp"

class Trie
{
public:
    Trie() : _root(new TrieNode){};
    bool insert(std::string word);
    bool remove(std::string word);
    bool search(std::string word);
    bool empty();
    int size();
    void print();

private:
    TrieNode *_root;
};

#endif // !TRIE_HPP