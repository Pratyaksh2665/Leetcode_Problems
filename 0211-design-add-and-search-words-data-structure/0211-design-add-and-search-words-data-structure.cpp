class WordDictionary {

    class Node {
    public:

        Node* children[26];
        bool eow;

        Node() {

            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }

            eow = false;
        }
    };

    Node* root;

    bool searchHelper(Node* node, string word, int i) {

        // Reached end of word
        if (i == word.length()) {
            return node->eow;
        }

        char ch = word[i];

        // Normal character
        if (ch != '.') {

            int idx = ch - 'a';

            if (node->children[idx] == NULL) {
                return false;
            }

            return searchHelper(
                node->children[idx],
                word,
                i + 1
            );
        }

        // '.' -> try every possible character
        for (int j = 0; j < 26; j++) {

            if (node->children[j] != NULL) {

                if (searchHelper(
                        node->children[j],
                        word,
                        i + 1
                    )) {
                    return true;
                }
            }
        }

        return false;
    }

public:

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {

        Node* node = root;

        for (int i = 0; i < word.length(); i++) {

            int idx = word[i] - 'a';

            if (node->children[idx] == NULL) {
                node->children[idx] = new Node();
            }

            node = node->children[idx];
        }

        // Mark the LAST node
        node->eow = true;
    }

    bool search(string word) {

        return searchHelper(root, word, 0);
    }
};