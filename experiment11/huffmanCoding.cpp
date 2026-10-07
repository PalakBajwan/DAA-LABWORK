//Palak Bajwan
//25/DA/049

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node of Huffman Tree
struct Node {
    char data;
    int frequency;
    Node *left, *right;

    Node(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = NULL;
    }
};

// Compare nodes based on frequency
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

// Generate Huffman Codes
void generateCodes(Node* root, string code,
                   unordered_map<char, string>& huffmanCode) {

    if (root == NULL)
        return;

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        huffmanCode[root->data] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Huffman Coding function
void huffmanCoding(string text) {

    // Count frequency of each character
    unordered_map<char, int> frequency;

    for (char ch : text) {
        frequency[ch]++;
    }

    // Priority queue (min heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a node for every character
    for (auto pair : frequency) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {

        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('\0',
                                 left->frequency + right->frequency);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    // Generate Huffman codes
    unordered_map<char, string> huffmanCode;

    generateCodes(root, "", huffmanCode);

    // Display Huffman Codes
    cout << "\nHuffman Codes:\n";

    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }

    // Encode the text
    string encodedText = "";

    for (char ch : text) {
        encodedText += huffmanCode[ch];
    }

    cout << "\nOriginal Text: " << text << endl;
    cout << "Encoded Text: " << encodedText << endl;
}

int main() {

    string text;

    cout << "Enter the text: ";
    getline(cin, text);

    if (text.empty()) {
        cout << "Text cannot be empty." << endl;
        return 0;
    }

    huffmanCoding(text);

    return 0;
}