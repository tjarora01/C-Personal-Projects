//
// Created by Tanmay Arora on 10/17/18.
//

#ifndef SALESDATA_TWO_SALESREC_H
#define SALESDATA_TWO_SALESREC_H


class SalesRec {
public:
    char     date[10];
    char     region[10];
    char     rep[10];
    char     item[10];
    int      units;
    float    unitCost;
    float    Total;
};


#endif //SALESDATA_TWO_SALESREC_H
