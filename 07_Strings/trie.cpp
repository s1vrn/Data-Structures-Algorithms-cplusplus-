/**
 * Trie (Prefix Tree)
 * 
 * Optimized for string searches/insertions.
 * Operations: Insert O(L), Search O(L), Prefix Search O(L), where L is word length.
 * Commonly used for Autocomplete, Spell Checkers.
 */

#include <iostream>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string key) {
        TrieNode* pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }

    bool search(string key) {
        TrieNode* pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != nullptr && pCrawl->isEndOfWord);
    }
    
    bool startsWith(string prefix) {
         TrieNode* pCrawl = root;
        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return true;
    }
};

int main() {
    Trie t;
    vector<string> keys = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    for(const string& key : keys) t.insert(key);

    cout << "Search 'the': " << (t.search("the") ? "Found" : "Not Found") << "\n";
    cout << "Search 'these': " << (t.search("these") ? "Found" : "Not Found") << "\n";
    cout << "Starts with 'th': " << (t.startsWith("th") ? "Yes" : "No") << "\n";

    return 0;
}
