#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct SalesRec
{
    string date;
    string rep;
    string region;
    string item;
    double    units;
    double    unitCost;
    double    Total;
};

SalesRec list[30];




void bubbleSort(SalesRec arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n-1; i++)
    {
        swapped = false;
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j].Total > arr[j+1].Total)
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i].date << " " << arr[i].rep << " " << arr[i].region << " " << arr[i].item << " " << arr[i].units << ", " << arr[i].unitCost << ", " << arr[i].Total << endl;
    }
}


int main() {

    fstream inFile;
    inFile.open("/Users/tanmayarora/Documents/SalesData.txt");

    string word;

    int count = 0;
    int listCount = 0;

    while (inFile.good()) {
        inFile >> word;

        if (word.find(',') == 18446744073709551615) {

            string thing;
            inFile >> thing;
            word = word + " " + thing;
        }



        if (count == 7) {
            count = 0;
            listCount++;
        }

        if(count == 0) {
            list[listCount].date = word;
            //cout << list[listCount].date << "hey" << endl;
        }

        if(count == 1) {
            list[listCount].rep = word;
            //cout << list[listCount].rep << endl;
        }

        if(count == 2) {
            list[listCount].region = word;
            //cout << list[listCount].region << endl;
        }

        if(count == 3) {
            list[listCount].item = word;
            //cout << list[listCount].item << endl;
        }

        if(count == 4) {
            stringstream geek(word);
            geek >> list[listCount].units;
            //cout << list[listCount]->units << endl;
        }

        if(count == 5) {
            stringstream geek(word);
            geek >> list[listCount].unitCost;
            //cout << list[listCount]->unitCost << endl;
        }

        if(count == 6) {
            stringstream geek(word);
            geek >> list[listCount].Total;
            //cout << list[listCount]->Total << endl;
        }


        count++;


    }

    bubbleSort(list, 30);
    return 0;

}










