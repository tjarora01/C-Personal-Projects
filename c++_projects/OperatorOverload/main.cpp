#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        std::string result;
        std::remove_copy(item.begin(), item.end(), std::back_inserter(result), '*');
        if (!result.empty()) {
            tokens.push_back(result);

        }
    }
    return tokens;
}

int size = 33;

class SalesRec {
public:
    string orderDate;
    string region;
    string rep;
    string item;
    int units;
    float unitCost;
    string flag;
    string flag2;
    int sum;

    SalesRec operator+(const SalesRec& b) {
        SalesRec d;
        d.orderDate = this->orderDate;
        d.region = this->region;
        d.item = this->item;
        d.units = this->units + b.units;
        return d;
    }
};





int main() {

    SalesRec arr[33]; // array of structs containing each row of the csv file
    int c = 0;
    int i = 0;


    ifstream myFile;
    myFile.open("/Users/tanmayarora/Documents/SalesDataP5.csv");

    string lineDummy;
    getline(myFile, lineDummy, '\n');

    while(myFile.good() && (c < 33) ) {
        if (myFile.is_open()) {
            string line;
            getline(myFile, line, '\n');
            vector<string> strVector = split(line,',');
            arr[c].orderDate = strVector[0];
            arr[c].region = strVector[1];
            arr[c].rep = strVector[2];
            arr[c].item = strVector[3];

            string cNum1 = strVector[4];
            int x;
            sscanf(cNum1.c_str(), "%d", &x);
            arr[c].units = x;

            string cNum2 = strVector[5];
            float y;
            sscanf(cNum2.c_str(), "%f", &y);
            arr[c].unitCost = y;
            arr[c].flag = "N";

            //cout << c << endl;

        } else {
            cout << "Error opening file";
            myFile.close();
        }

        c++;
    }


    for (int i=0; i < 33; i++){
        for (int k=i+1; k < 33; k++){
            if ((arr[i].orderDate == arr[k].orderDate) && (arr[i].rep == arr[k].rep) && (arr[i].item == arr[k].item) && (arr[k].flag != "Y")) {
                arr[k].flag = "Y";
                arr[i].flag2 = "Y";
                // arr[i] =  arr[i] + arr[k];
                arr[i].sum =  arr[i].units + arr[k].units;
            }
        }
    }

    for (int i=0; i < 33; i++){
        //cout << i << endl;
        // cout << arr[i].flag << endl;
        if (arr[i].flag2 == "Y") {
            cout << arr[i].orderDate << endl;
            cout << arr[i].rep << endl;
            cout << arr[i].item << endl;
            cout << arr[i].sum << endl;
            cout << "-----------------------" << endl;

        }
    }

    for (int i=0; i < 33; i++){
        //cout << i << endl;
        // cout << arr[i].flag << endl;
        if ((arr[i].flag2 != "Y") && (arr[i].flag != "Y")) {
            cout << arr[i].orderDate << endl;
            cout << arr[i].rep << endl;
            cout << arr[i].item << endl;
            cout << arr[i].units << endl;
//cout << arr[i].sum << endl;
            cout << "-----------------------" << endl;

        }
    }

    myFile.close();


    return 0;
}