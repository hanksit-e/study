#include <unordered_map>
#include <iostream>
#include <fstream>

using namespace std;

unordered_map<char, int> word_to_map(string word) {
    unordered_map<char, int> word_map;

    for (char ch: word) {
        if (word_map.find(ch) == word_map.end()) {
            word_map[ch] = 1;
        } else {
            word_map[ch]++;
        };
    };

    return word_map;
};

void lower(string* s) {
    int len = s->length();
    for (int i = 0; i < len; i++) {
        s[i] = (char)tolower(s[i]);
        // doesn't work
    };
};

bool is_anagram(unordered_map<char, int> mp, string word) {
    unordered_map<char, int> target_map = word_to_map(word);
    if (mp == target_map) {
        return true;
    } else {
        return false;
    };
};


int main() {
    unordered_map<char, int> word_map;
    string word = "niska";
    string fname = "names.txt";

    word_map = word_to_map(word);

    for (auto pair: word_map) {
        cout << pair.first << " ==> " << pair.second << endl;
    };

    ifstream file(fname);
    string line;

    while (getline(file, line)) {
        lower(&line);
        if (is_anagram(word_map, line)) {
            cout << line << endl;
        };
    };

    file.close();
    return 0;
}