
#ifndef TRIE_HPP
#define TRIE_HPP

#include<string>
#include<unordered_map>

class Trie {
    public:

    private:
    struct TrieNode
    {
        bool is_leaf;
        std::unordered_map<char, TrieNode*> children;

        TrieNode() : is_leaf(false) {};

        TrieNode* next(char c) {
            if (children.find(c) != children.end()) {
                return children[c];
            }

            TrieNode* new_child = new TrieNode;
            children[c] = new_child;

            return new_child;
        }

        bool insert(const std::string &word, int &pos) {
            if (pos == word.length()) {
                if (!is_leaf) {
                    is_leaf = true;
                    return true;
                }
                return false;
            }
            else {
                char c = word[pos];
                TrieNode* next_node = next(c);
                pos++;

                return next_node->insert(word, pos);
            }
        }

        bool hasChildren() {
            // get iterator to first element. If value is non-empty
            // => there is at least 1 value => has children.
            // faster than looking at map size
            for(auto it : children) {
                if(it.second != nullptr) {
                    return true;
                }
            }

            return false;
        }

        bool remove(const std::string &word, int &pos) {
            // base case: end of string
            if (pos == word.length() && is_leaf) {
                is_leaf = false;
                return !hasChildren(); //to be deleted if no children
            }

            // otherwise keep going
            char c = word[pos];
            pos++;
            TrieNode* child = children[c];

            // found nothing
            if (child == nullptr) {
                return false;
            }

            // if child has the following node, gets marked for removal,
            // and child itself is not a leaf
            if (child->children.find(c) != child->children.end() &&
                child->remove(word, pos) &&
                !child->is_leaf) {
                    delete child;
                    return true;
            }
        }

        bool search(const std::string &word, int &pos) {
            if(pos == word.length()) {
                return is_leaf;
            }

            char c = word[pos];
            pos++;
            TrieNode* child = children[c];

            if (child == nullptr) {
                return false;
            }

            return child->search(word, pos);
        }
    };

    TrieNode* root;
    
    bool insert(std::string word);
};

#endif // !TRIE_HPP