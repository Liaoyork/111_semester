#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

map<string, int> countWords(const string& str) {
    map<string, int> wordCount;
    stringstream ss(str);
    string word;

    while (ss >> word) {
        wordCount[word]++;
    }

    return wordCount;
}

bool checkWordCount(map<string, int>& wordCount, const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Failed to open the file: " << filename << endl;
        return false;
    }

    map<string, int> fileWordCount;

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string word;
        int count;
        ss >> word >> count;
        fileWordCount[word] = count;
    }

    inputFile.close();

    for (const auto& pair : fileWordCount) {
        const string& word = pair.first;
        int fileCount = pair.second;

        if (wordCount[word] != fileCount) {
            cout << word << ": " << fileCount << " (" << wordCount[word] << "->" << fileCount - wordCount[word] << ")" << endl;
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <filename> <input string>" << endl;
        return 1;
    }

    string filename = argv[1];
    string inputString = argv[2];

    map<string, int> wordCount = countWords(inputString);

    bool result = checkWordCount(wordCount, filename);

    if (result) {
        cout << "True" << endl;
        for (const auto& pair : wordCount) {
            const string& word = pair.first;
            int count = pair.second;
            cout << word << ": " << count << "(" << count << "->" << count - count << ")" << endl;
        }
    } else {
        cout << "False" << endl;
    }

    return 0;
}
