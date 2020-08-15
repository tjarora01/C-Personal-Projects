#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct countriesStruct {
    string countryName;
    double lifeExpectancy;
};


countriesStruct arr[231];

countriesStruct advancedArr[231];

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


void sort(countriesStruct A[], int length) {

    string holder = "";
    double key = 0;
    int i = 0;

    for (int j = 1; j < length; j++) {
        key = A[j].lifeExpectancy;
        holder = A[j].countryName;
        i = j - 1;
        while ((i > -1) && (A[i].lifeExpectancy < key)) {
            A[i + 1] = A[i];
            i = i - 1;
        }

        A[i + 1].lifeExpectancy = key;
        A[i+1].countryName = holder;
    }

}

int main() {
    string name = "/Users/tanmayarora/Documents/UN.csv";
    ifstream bucky;
    bucky.open(name);


    if(!(bucky.is_open())){
        cout << "failure!";
    }


    string line;
    int counter = 0;

    int arr_size = 0;

    int advanced_arr_size = 0;

    for (int i = 0; i < 231; i++) {
        arr[i].lifeExpectancy = 0;
        advancedArr[i].lifeExpectancy = 0;
    }


    while (getline (bucky,line)) {
        counter++;

        if ((counter > 31 && counter < 259) ) {

            vector<string> tokens = split(line, ',');
            // cout << tokens[2] << endl;

            double life;
            life = stoi(tokens[14]);

            string countryName = tokens[2];
            std::replace( countryName.begin(), countryName.end(), '"', '_');

            if ((countryName  != "_Northern Africa_") && (countryName  != "_Central African Republic_")
                && (countryName  != "_Southern Africa_") && (countryName  != "_ASIA_")
                && (countryName  != "_Eastern Asia_") && (countryName  != "_South-Central Asia_")
                && (countryName  != "_Central Asia_") && (countryName  != "_Southern Asia_")
                && (countryName  != "_South-Eastern Asia_") && (countryName  != "_Western Asia_")
                && (countryName  != "_EUROPE_") && (countryName  != "_Eastern Europe_")
                && (countryName  != "_Northern Europe_") && (countryName  != "_Southern Europe_")
                && (countryName  != "_Western Europe_") && (countryName  != "_LATIN AMERICA AND THE CARIBBEAN_")
                && (countryName  != "_Caribbean_") && (countryName  != "_Central America_")
                && (countryName  != "_South America_") && (countryName  != "_NORTHERN AMERICA_")
                && (countryName  != "_OCEANIA_") && (countryName  != "_Australia/New Zealand_")
                    ) {
                arr[arr_size].countryName = countryName;
                arr[arr_size].lifeExpectancy = life/100.0;
                arr_size++;
            }

            if ((countryName  != "_Northern Africa_") && (countryName  != "_Central African Republic_")
                && (countryName  != "_Southern Africa_") && (countryName  != "_ASIA_")
                && (countryName  != "_Eastern Asia_") && (countryName  != "_South-Central Asia_")
                && (countryName  != "_Central Asia_") && (countryName  != "_Southern Asia_")
                && (countryName  != "_South-Eastern Asia_") && (countryName  != "_Western Asia_")
                && (countryName  != "_EUROPE_") && (countryName  != "_Eastern Europe_")
                && (countryName  != "_Northern Europe_") && (countryName  != "_Southern Europe_")
                && (countryName  != "_Western Europe_") && (countryName  != "_LATIN AMERICA AND THE CARIBBEAN_")
                && (countryName  != "_Caribbean_") && (countryName  != "_Central America_")
                && (countryName  != "_South America_") && (countryName  != "_NORTHERN AMERICA_")
                && (countryName  != "_OCEANIA_") && (countryName  != "_Australia/New Zealand_")
                    ) {
                if ((counter == 82) || (counter > 134 && counter < 179) || (counter > 221)) {
                    advancedArr[advanced_arr_size].countryName = countryName;
                    advancedArr[advanced_arr_size].lifeExpectancy = life/100.0;
                    advanced_arr_size++;
                }
            }


        }

    }


    countriesStruct arrTwo[arr_size];


    int countTwo = 0;

    for (int i = 0; i < arr_size; i++) {
        if (arr[i].lifeExpectancy > 0) {
            arrTwo[i].lifeExpectancy = arr[i].lifeExpectancy;
            arrTwo[i].countryName = arr[i].countryName;
            countTwo ++;
        }
    }

    countriesStruct arrThree[advanced_arr_size];

    int countThree = 0;

    for (int i = 0; i < arr_size; i++) {
        if (advancedArr[i].lifeExpectancy > 0) {
            arrThree[i].lifeExpectancy = advancedArr[i].lifeExpectancy;
            arrThree[i].countryName = advancedArr[i].countryName;
            countThree ++;
        }
    }


    // cout << countTwo << endl;

    sort(arrTwo, countTwo);

    cout << "---- ordered list highest to lowest-- " << endl;
    for (int i = 0; i < countTwo ; i++) {
        // cout << i << endl;
        cout << arrTwo[i].countryName << endl;
        cout << arrTwo[i].lifeExpectancy << endl;
        cout << "------------------------- " << endl;
    }

    cout << "--- United States rank -- " << endl;
    for (int i = 0; i < countTwo ; i++) {
        if (arrTwo[i].countryName  == "_United States of America_") {
            cout << i + 1 << endl;
        }
    }


    sort(arrThree, countThree);

    cout << "--- United States advance rank -- " << endl;
    for (int i = 0; i < countThree ; i++) {
        if (arrThree[i].countryName  == "_United States of America_") {
            cout << i + 1 << endl;
        }
    }

}



