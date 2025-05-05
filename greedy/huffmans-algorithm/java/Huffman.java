import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class Huffman {
    // Node represents a node in the Huffman tree
    static class Node implements Comparable<Huffman.Node> {
        char symbol; // The character (symbol) stored in this node; '\0' for internal nodes
        int freq; // Frequency (weight) of this node/subtree
        Huffman.Node left; // Pointer to left child (represents '0' bit)
        Huffman.Node right; // Pointer to right child (represents '1' bit)

        // Constructor for leaf nodes
        Node(char symbol, int freq) {
            this.symbol = symbol;
            this.freq = freq;
            this.left = this.right = null;
        }

        // Constructor for internal nodes: merge two subtrees
        Node(Huffman.Node left, Huffman.Node right) {
            this.symbol = '\0';
            this.freq = left.freq + right.freq;
            this.left = left;
            this.right = right;
        }

        @Override
        public int compareTo(Huffman.Node other) {
            return Integer.compare(this.freq, other.freq);
        }
    }

    // Builds the Huffman tree from input data string
    public static Huffman.Node buildHuffmanTree(String data) {
        // Count frequency of each character in the data
        Map<Character, Integer> freq = new HashMap<>();
        for (char ch : data.toCharArray()) {
            freq.put(ch, freq.getOrDefault(ch, 0) + 1);
        }

        // Min-priority queue to select two nodes with lowest frequency
        PriorityQueue<Huffman.Node> pq = new PriorityQueue<>();

        // Create a leaf node for each unique character and add to queue
        for (Map.Entry<Character, Integer> entry : freq.entrySet()) {
            pq.add(new Huffman.Node(entry.getKey(), entry.getValue()));
        }

        // Merge nodes until only the root remains
        while (pq.size() > 1) {
            // Extract two nodes with smallest frequencies
            Huffman.Node left = pq.poll();
            Huffman.Node right = pq.poll();

            // Create a new parent node with combined frequency
            pq.add(new Huffman.Node(left, right));
        }

        // The remaining node is the root of the Huffman tree
        return pq.poll();
    }

    // Recursively generate Huffman codes from the tree
    public static void generateCodes(Huffman.Node node, String prefix, Map<Character, String> codebook) {
        if (node == null) return;

        if (node.symbol != '\0') {
            // If this is a leaf node, assign the code (use "0" if only one symbol)
            codebook.put(node.symbol, prefix.isEmpty() ? "0" : prefix);
        } else {
            // Internal: go left (add '0') and right (add '1')
            generateCodes(node.left, prefix + '0', codebook);
            generateCodes(node.right, prefix + '1', codebook);
        }
    }

    public static void main(String[] args) {
        System.setOut(new PrintStream(System.out, true, StandardCharsets.UTF_8));

        // Example input string to encode
        String text = "AAABBBBBAAABBDDCCCCCDDDDBBAAAAAAAAAAACCCCAAAEEEEAAADDDAADAAAABBAADDACCACAAAAEEEBBEEAAAADDDDAA";

        // Build Huffman tree based on character frequencies
        Huffman.Node root = buildHuffmanTree(text);

        // Generate the codebook (mapping from char to codeword)
        Map<Character, String> codes = new HashMap<>();
        generateCodes(root, "", codes);

        // Output the resulting Huffman codes
        System.out.println("Codewords:");
        for (Map.Entry<Character, String> entry : codes.entrySet()) {
            System.out.println("'" + entry.getKey() + "': " + entry.getValue());
        }
    }
}
