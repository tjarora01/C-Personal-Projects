#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include algorithm

using namespace std;

vector<string> split(string s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        std::string result;
        std::remove_copy(item.begin(), item.end(), std::back_inserter(result), '.');
        if (!result.empty()) {
            tokens.push_back(result);

        }
    }
    return tokens;
}

int substringcount(vector<string> v, string s) {

    int matches = 0;
    for (auto i : v) {
        // std::cout << i << '\t';
        if (i.find(s) != string::npos) {
            matches = matches +1;
        }
    }

    return matches;
}

int wordCount(vector<string> v) {

    int counter = 0;
    string yes;


    for(int i = 0; i < v.size(); i++) {
        if (v[i].find('0') == 18446744073709551615 && v[i].find('1') == 18446744073709551615 && v[i].find('2') == 18446744073709551615 && v[i].find('3') == 18446744073709551615 && v[i].find('4') == 18446744073709551615 && v[i].find('5') == 18446744073709551615 && v[i].find('6') == 18446744073709551615 && v[i].find('7') == 18446744073709551615 && v[i].find('8') == 18446744073709551615 && v[i].find('9') == 18446744073709551615)
        {
            counter++;
        }
    }
    return counter;
}


int unique(vector<string> v) {

    int counter = 0;
    string yes;

    std::unordered_set<std::string> myset;

    for(int i = 0; i < v.size(); i++) {
        if (v[i].find('0') == 18446744073709551615 && v[i].find('1') == 18446744073709551615 && v[i].find('2') == 18446744073709551615 && v[i].find('3') == 18446744073709551615 && v[i].find('4') == 18446744073709551615 && v[i].find('5') == 18446744073709551615 && v[i].find('6') == 18446744073709551615 && v[i].find('7') == 18446744073709551615 && v[i].find('8') == 18446744073709551615 && v[i].find('9') == 18446744073709551615)
        {
            myset.insert(v[i]);
        }
    }

    return myset.size();
}


float avg(int total, int count) {
    return (float) total/ (float) count;
}

int main() {
    std::cout << "Hello, World!" << std::endl;


    string str = "I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo. I got the ramblin fever. Said goodbye to ma and pa. Crossed that ol red river and this is what I saw. I saw miles and miles of Texas 1000 stars up in the sky. I saw miles and miles of Texas gonna live here till I die.";
    std::vector<std::string> x = split(str,' ');

    string somestring = "is";
    int y = substringcount(x,somestring);

    std::cout << "number of words with substring " << somestring << ": " << y << '\t' << endl;

    int wcount = wordCount(x);

    std::cout << "total number of words (exlcuding numbers): "  << wcount << '\t' << endl;

    std::vector<std::string> sentencevector = split(str,'.');

    std::cout << "total number of sentences: "  << sentencevector.size() << '\t' << endl;

    std::cout << "avg number of words per sentence: "  << avg(wcount, sentencevector.size()) << '\t' << endl;

    std::cout << "unique number of words: "  << unique(x) << '\t' << endl;

    std::cout << "Lexical Density: "  << ((float) unique(x)/(float) wcount)*100  << endl;

    string hi = "hello";
    cout << hi.find('0');#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

    using namespace std;

    vector<string> split(string s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> tokens;
        while (getline(ss, item, delim)) {
            std::string result;
            std::remove_copy(item.begin(), item.end(), std::back_inserter(result), '.');
            if (!result.empty()) {
                tokens.push_back(result);

            }
        }
        return tokens;
    }

    int substringcount(vector<string> v, string s) {

        int matches = 0;
        for (auto i : v) {
            // std::cout << i << '\t';
            if (i.find(s) != string::npos) {
                matches = matches +1;
            }
        }

        return matches;
    }

    int wordCount(vector<string> v) {

        int counter = 0;
        string yes;


        for(int i = 0; i < v.size(); i++) {
            if (v[i].find('0') == 18446744073709551615 && v[i].find('1') == 18446744073709551615 && v[i].find('2') == 18446744073709551615 && v[i].find('3') == 18446744073709551615 && v[i].find('4') == 18446744073709551615 && v[i].find('5') == 18446744073709551615 && v[i].find('6') == 18446744073709551615 && v[i].find('7') == 18446744073709551615 && v[i].find('8') == 18446744073709551615 && v[i].find('9') == 18446744073709551615)
            {
                counter++;
            }
        }
        return counter;
    }


    int unique(vector<string> v) {

        int counter = 0;
        string yes;

        std::unordered_set<std::string> myset;

        for(int i = 0; i < v.size(); i++) {
            if (v[i].find('0') == 18446744073709551615 && v[i].find('1') == 18446744073709551615 && v[i].find('2') == 18446744073709551615 && v[i].find('3') == 18446744073709551615 && v[i].find('4') == 18446744073709551615 && v[i].find('5') == 18446744073709551615 && v[i].find('6') == 18446744073709551615 && v[i].find('7') == 18446744073709551615 && v[i].find('8') == 18446744073709551615 && v[i].find('9') == 18446744073709551615)
            {
                myset.insert(v[i]);
            }
        }

        return myset.size();
    }


    float avg(int total, int count) {
        return (float) total/ (float) count;
    }

    int main() {
        std::cout << "Hello, World!" << std::endl;


        string str = "I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo. I got the ramblin fever. Said goodbye to ma and pa. Crossed that ol red river and this is what I saw. I saw miles and miles of Texas 1000 stars up in the sky. I saw miles and miles of Texas gonna live here till I die.";
        std::vector<std::string> x = split(str,' ');

        string somestring = "is";
        int y = substringcount(x,somestring);

        std::cout << "number of words with substring " << somestring << ": " << y << '\t' << endl;

        int wcount = wordCount(x);

        std::cout << "total number of words (exlcuding numbers): "  << wcount << '\t' << endl;

        std::vector<std::string> sentencevector = split(str,'.');

        std::cout << "total number of sentences: "  << sentencevector.size() << '\t' << endl;

        std::cout << "avg number of words per sentence: "  << avg(wcount, sentencevector.size()) << '\t' << endl;

        std::cout << "unique number of words: "  << unique(x) << '\t' << endl;

        std::cout << "Lexical Density: "  << ((float) unique(x)/(float) wcount)*100  << endl;

        string hi = "hello";
        cout << hi.find('0');

        return 0;
    }


    return 0;
}
