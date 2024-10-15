#include <iostream>
#include <string>

using namespace std;

class Trie {
public:
    char data;
    Trie* childNode[26];
    bool isTerminal;

    // Root node pointer
    Trie* rootNode;

    // Constructor for creating nodes
    Trie(char ch) : data(ch), isTerminal(false) {
        for (size_t i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
        // Initialize rootNode as nullptr by default
        rootNode = nullptr;
    }

    // Constructor for creating the root node
    Trie() {
        // Root node doesn't hold a character
        data = '\0'; 
        isTerminal = false;
        for (size_t i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
        rootNode = this;  // Root node points to itself
    }

    void insertion(string word) {
        Trie* temp = rootNode;  // Always start from the root node
        int i = 0;
        while (i < word.length()) {
            int index = word[i] - 'a';
            if (temp->childNode[index] != nullptr) {
                temp = temp->childNode[index];
            } else {
                Trie* newNode = new Trie(word[i]);
                temp->childNode[index] = newNode;
                temp = newNode;
            }
            i++;
        }
        temp->isTerminal = true;  // Mark the end of the word
    }

    bool search(string word) {
        Trie* temp = rootNode;  // Always start from the root node
        int i = 0;
        while (i < word.length()) {
            int index = word[i] - 'a';
            if (temp->childNode[index] != nullptr) {
                temp = temp->childNode[index];
                i++;
            } else {
                return false;
            }
        }
        return temp->isTerminal;  // Ensure it is a complete word
    }
};

int main() {
    Trie t;  // Root node initialized
    t.insertion("apple");
    t.insertion("apex");

    cout << "Is 'hello' in trie? " << t.search("hello") << endl;
    cout << "Is 'apple' in trie? " << t.search("apple") << endl;

    return 0;
}
