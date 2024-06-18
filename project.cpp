//i200795, i200928
//Data Structures Project

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Node {
public:
    char character;
    int freq;
    Node* left, * right;

    //New Node Creation
    Node(char c, int f) {
        character = c;
        freq = f;
        left = right = NULL;
    }
};
class PriorityQueue {
public:
    Node** heap;
    int size;
    int capacity;
    PriorityQueue(int cap) {
        capacity = cap;
        heap = new Node * [cap];
        size = 0;
    }

    //Insertion and Arrangements
    void insert(Node* n) {
        heap[size] = n;
        size++;
        int i = size - 1;
        while (i > 0 && heap[i]->freq < heap[(i - 1) / 2]->freq) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    //Heapifying
    Node* extractMin() {
        if (size == 0)
            return NULL;
        Node* min = heap[0];
        heap[0] = heap[size - 1];
        size--;
        int i = 0;
        while (2 * i + 1 < size) {
            int child = 2 * i + 1;
            if (child + 1 < size && heap[child + 1]->freq < heap[child]->freq)
                child++;
            if (heap[i]->freq > heap[child]->freq) {
                swap(heap[i], heap[child]);
                i = child;
            }
            else
                break;
        }
        return min;
    }
};


//Recursive code for adding 0 and 1 edges
void Generate_Huffman_Codes(Node* root, string s, string* huffman_codes) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        huffman_codes[root->character] = s;
        return;
    }
    Generate_Huffman_Codes(root->left, s + "0", huffman_codes);
    Generate_Huffman_Codes(root->right, s + "1", huffman_codes);
}


int main()
{

    // File Reading
    ifstream fin;
    cout << "Enter the filename to be compressed: ";
    string filename;
    cin >> filename;
    fin.open(filename.c_str());
    int file_length = 0;
    int frequency[256] = { 0 };
    char ch;

    //Frequency and file length
    while (fin.get(ch)) {
        file_length++;
        frequency[ch]++;
    }
    fin.close();
    int capacity = file_length;
    PriorityQueue pq(capacity);

    //Insertion from file
    for (int i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            Node* n = new Node(i, frequency[i]);
            pq.insert(n);
        }
    }
    int i = 0;

    //Constructing Tree
    while (pq.size > 1) {
        Node* n1 = pq.extractMin();
        Node* n2 = pq.extractMin();
        Node* n3 = new Node(255, n1->freq + n2->freq);
        n3->left = n1;
        n3->right = n2;
        pq.insert(n3);
    }

    //Specifying root
    Node* root = pq.extractMin();
    string huffman_codes[256];

    //Huffman function call
    Generate_Huffman_Codes(root, "", huffman_codes);

    // printing all characters and their huffman codes and frequency
    cout << "Character\tFrequency\tHuffman Code\n";
    for (int i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            cout << (char)i << "\t\t" << frequency[i] << "\t\t" << huffman_codes[i] << "\n";
        }
    }
    cout << "\n";

    //Compression Ratio Calculation
    double compression_ratio = 0;
    for (int i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            compression_ratio += (double)frequency[i] * huffman_codes[i].length();
        }
    }
    compression_ratio = compression_ratio / file_length;

    //Printing compression

    cout << "Average Bit rate : " << compression_ratio << "\n";

    compression_ratio = 8 / compression_ratio;

    cout << "Compression Ratio : " << compression_ratio << "\n";


}