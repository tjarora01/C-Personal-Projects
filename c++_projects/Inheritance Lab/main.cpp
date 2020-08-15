#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

class SalesRep
{
    public:
    char rep[50]; // A character array for ‘rep’ last name.
    char region[50]; // A character array for the rep’s ‘region’
};

class ItemCatalog
{
public:
    char item[50]; // character array for ‘item’ name.
protected:
    float unitCost; // a real number for ‘unitCost’.

};

class SALESREC: public SalesRep, public ItemCatalog
{
public:
    char date[10];

    int units;

    void setUnitCost(float uCost)
    {
        unitCost = uCost;
    }
    float getUnitCost()
    {
        return unitCost;
    }
    float Total()
    {
        return units * getUnitCost();
    }

    void displayRec()
    {
        cout << "Record: " << date <<", " << region << ", " << rep << ", " << item << ", " << units << ", " << unitCost << ", " << Total() << endl;
    }
};

void simpleSortTotal(SALESREC* s[], int c);

int main() {
    ifstream infile;
    int array[20];
    char cNum[10];
    SALESREC *salesArr[40];
    int salesArrayCount;
    SALESREC *s[40];

    infile.open("/Users/tanmayarora/Downloads/SalesDataP3.csv");
    if (infile.is_open()) {
        int c = 0;
        float inputUnitCost;
        while (infile.good()) {
            salesArr[c] = new SALESREC();
            infile.getline(salesArr[c]->date, 256, ',');
            infile.getline(salesArr[c]->region, 256, ',');
            infile.getline(salesArr[c]->rep, 256, ',');
            infile.getline(salesArr[c]->item, 256, ',');
            infile.getline(cNum, 256, ',');
            salesArr[c]->units = atoi(cNum);
            infile.getline(cNum, 256, '\n');
            inputUnitCost = atof(cNum);
            salesArr[c]->setUnitCost(inputUnitCost);  //store in salesArr[c]
            c++;
        }
        salesArrayCount = c - 1;
        infile.close();
    } else {
        cout << "Error opening file";
    }

    for (int i = 0; i < salesArrayCount; i++)
        s[i] = salesArr[i];

    cout << " Unsorted Sales Record Array\n";
    for (int i = 0; i < salesArrayCount; i++)
        salesArr[i]->displayRec();

    simpleSortTotal(s, salesArrayCount);

    cout << " - - - - - - - - - - - -\n";
    cout << " Sorted Sales Record Array\n";

    for (int i = 0; i < salesArrayCount; i++)
        s[i]->displayRec();

    //clean up (remove from memory) allocated sales records
    for (int i=0; i < salesArrayCount; i++) {
        delete   salesArr[i];
    }

}

void simpleSortTotal( SALESREC* ptr[] , int c)
{
    SALESREC* temp;
    float key = 0;

    int i = 0;
    for (int j = 1; j < c; j++) {
        temp = ptr[j];
        key = ptr[j]->Total();
        i = j - 1;
        while ((i > -1) && (ptr[i]->Total() > key)) {
            ptr[i + 1] = ptr[i];
            i = i - 1;
        }

        ptr[i +1] = temp;
    }
}



