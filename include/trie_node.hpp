#ifndef TRIE_NODE_HPP
#define TRIE_NODE_HPP

#include <unordered_map>

class TrieNode
{
public:
    TrieNode() : _is_leaf(false), _children(){};
    TrieNode *next(char c);
    bool hasChildren();
    bool insert(const std::string &word, int &pos);
    bool remove(const std::string &word, int &pos, bool &to_remove);
    bool search(const std::string &word, int &pos);
    int size();

private:
    bool _is_leaf;
    std::unordered_map<char, TrieNode *> _children;
};

#endif // !TRIE_NODE_HPP