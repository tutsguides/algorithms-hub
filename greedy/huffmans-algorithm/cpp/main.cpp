#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <unordered_map>

using namespace std;

// Node represents a node in the Huffman tree
struct Node {
    char symbol; // The character (symbol) stored in this node; '\0' for internal nodes
    long long freq; // Frequency (weight) of this node/subtree
    shared_ptr<Node> left; // Pointer to left child (represents '0' bit)
    shared_ptr<Node> right; // Pointer to right child (represents '1' bit)

    // Constructor for leaf nodes
    Node(const char s, const long long f)
        : symbol(s), freq(f), left(nullptr), right(nullptr) {
    }

    // Constructor for internal nodes: merge two subtrees
    Node(const shared_ptr<Node> &l, const shared_ptr<Node> &r)
        : symbol('\0'), freq(l->freq + r->freq), left(l), right(r) {
    }
};

// Compare functor to order priority queue by smallest frequency
struct Compare {
    bool operator()(const shared_ptr<Node> &a, const shared_ptr<Node> &b) const {
        // Return true if a has higher freq than b, so b is processed first
        return a->freq > b->freq;
    }
};

// Builds the Huffman tree from input data string
shared_ptr<Node> buildHuffmanTree(const string &data) {
    // Count frequency of each character in the data
    unordered_map<char, long long> freq;
    for (const auto &c: data) {
        freq[c]++;
    }

    // Min-priority queue to select two nodes with lowest frequency
    priority_queue<shared_ptr<Node>, vector<shared_ptr<Node> >, Compare> pq;

    // Create a leaf node for each unique character and add to queue
    for (const auto &p: freq) {
        pq.push(make_shared<Node>(p.first, p.second));
    }

    // Merge nodes until only the root remains
    while (pq.size() > 1) {
        // Extract two nodes with smallest frequencies
        auto left = pq.top();
        pq.pop();
        auto right = pq.top();
        pq.pop();

        // Create a new parent node with combined frequency
        pq.push(make_shared<Node>(left, right));
    }

    // The remaining node is the root of the Huffman tree
    return pq.top();
}

// Recursively generate Huffman codes from the tree
void generateCodes(const shared_ptr<Node> &node,
                   const string &prefix,
                   unordered_map<char, string> &codebook) {
    if (!node) return;

    // If this is a leaf node, assign the code (use "0" if only one symbol)
    if (node->symbol != '\0') {
        codebook[node->symbol] = prefix.empty() ? "0" : prefix;
    } else {
        // Internal: go left (add '0') and right (add '1')
        generateCodes(node->left, prefix + "0", codebook);
        generateCodes(node->right, prefix + "1", codebook);
    }
}

int main() {
    // Example input string to encode
    string text = "AAABBBBBAAABBDDCCCCCDDDDBBAAAAAAAAAAACCCCAAAEEEEAAADDDAADAAAABBAADDACCACAAAAEEEBBEEAAAADDDDAA";

    // Build Huffman tree based on character frequencies
    auto root = buildHuffmanTree(text);

    // Generate the codebook (mapping from char to codeword)
    unordered_map<char, string> codes;
    generateCodes(root, "", codes);

    // Output the resulting Huffman codes
    cout << "Codewords:\n";
    for (auto &p: codes) {
        cout << "'" << p.first << "': " << p.second << "\n";
    }

    return 0;
}
