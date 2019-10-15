#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

struct SalesRec {

    char     date[10];
    char     region[10];
    char     rep[10];
    char     item[10];
    int      units;
    float    unitCost;
    float    Total;
};


void order (SalesRec* numb1, SalesRec* numb2) {
    if (numb1->Total > numb2->Total) {
        SalesRec temp = *numb1;
        *numb1 = *numb2;
        *numb2 = temp;
    }
}

void bsort(SalesRec* ptr, int n) {
    int j, k;

    for (int j = 0; j<n-1; j++) {
        for (k = j+1; k<n; k++) {
            order(ptr+j, ptr+k);
        }
    }
}


int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    SalesRec salesArr[40];
    int   salesArrayCount;
    SalesRec* s;
    s = (SalesRec*)malloc(40*(16));

    infile.open ("/Users/tanmayarora/Documents/SalesDataP2.csv", ifstream::in);
    if (infile.is_open())
    {

        int   c=0;
        while (infile.good())
        {
            //cout << "running" << endl;

            infile.getline(salesArr[c].date, 256, ',');
            infile.getline(salesArr[c].region, 256, ',');
            infile.getline(salesArr[c].rep, 256, ',');
            infile.getline(salesArr[c].item, 256, ',');
            infile.getline(cNum, 256, ',');
            salesArr[c].units = atoi(cNum);
            //cout << salesArr[c].units << endl;
            infile.getline(cNum, 256, '\n');
            salesArr[c].unitCost = atof(cNum);

            i++ ;
            c++;

            //cout << c << endl;
        }
        salesArrayCount = c-1;
        infile.close();
    }
    else
    {
        cout << "Error opening file";
    }

    for (int i=0; i < salesArrayCount; i++){
        //cout << salesArr[i].region << endl;
        salesArr[i].Total = salesArr[i].unitCost * salesArr[i].units;
    }

    // Initialize the sort array pointers
    for (int i=0; i < salesArrayCount; i++) {
        s[i] = salesArr[i];
    }


    bsort(s, salesArrayCount);

    for (int i=30; i >0; i--) {
        cout << "Record: " << s[i].date << ", " << s[i].region << ", " << s[i].rep << ", " << s[i].item << ", "
             << s[i].units << ", " << s[i].unitCost << ", " << s[i].Total << endl;
    }


}












