//Build a library for singly linked list.
// Replace the airport array in main with a Linked List.
// Sort the array.
//idk why it's kinda weird but just remember that the indexing of the linked list starts at 1

#include <iostream>
#include <fstream>
#include <cmath>
#include "slist.h"

using namespace std;


//CREATE LINKED LIST
node* n;
node* t; // temporary
node* h; // head
node* tp; //for traversing linked list


void simpleSortTotal(Airport* s[], int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main() {


    ifstream infile;
    int i=0;
    //char cNum[10] ;

    char testAirport[50];
    char airportType[50];

    string testAirportWorks;
    string airportTypeWorks;

    char personName[50];

    string personNameWorks;

    char longitude[50];
    char latitude[50];

    char elevation_ft[50];
    char continent[50];
    char iso_country[50];
    char iso_region[50];
    char municipality[50];
    char gps_code[50];
    char lata_code[50];
    char local_code[50];

    string elevation_ftWorks;
    string continentWorks;
    string iso_countryWorks;
    string iso_regionWorks;
    string municipalityWorks;
    string gps_codeWorks;
    string lata_codeWorks;
    string local_codeWorks;

    //Airport* airportArr[13500];			// Replace array with Linked List
    int airportCount;
    //Airport* a[13500];

    n = new node; // creates first node

    t = n; // assigns temporary node to first node
    h = n; // assigns head node to first node
    tp = n; // tp equals the head node of the linked list


    infile.open("/Users/tanmayarora/Documents/USAirportCodes_2.csv", ifstream::in);


    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {




            infile.getline(testAirport, 256, ',');
            infile.getline(airportType, 256, ',');


            infile.getline(personName, 256, ',');

            infile.getline(longitude, 256, ',');

            infile.getline(latitude, 256, ',');


            infile.getline(elevation_ft, 256, ',');
            infile.getline(continent, 256, ',');
            infile.getline(iso_country, 256, ',');
            infile.getline(iso_region, 256, ',');
            infile.getline(municipality, 256, ',');
            infile.getline(gps_code, 256, ',');
            infile.getline(lata_code, 256, ',');
            infile.getline(local_code, 256, ',');



            if (strcmp(airportType, "small_airport") == 0 || strcmp(airportType, "medium_airport") == 0 || strcmp(airportType, "large_airport") == 0) {


                testAirportWorks = testAirport;


                airportTypeWorks = airportType;
                //airportTypeWorks is a string
                //airportType is a char array

                //cout << testAirport << endl;

                for (int i = 0; i < 30; i++) {
                    n->airport[i] = testAirport[i];
                }



                personNameWorks = personName;

                n->longitude = atof(longitude);
                //cout << n->longitude << endl;
                n->latitude = atof(latitude);

                elevation_ftWorks = elevation_ft;
                n->elevation_ft = elevation_ftWorks;

                continentWorks = continent;
                n->continent = continentWorks;

                iso_countryWorks = iso_country;
                n->iso_country = iso_countryWorks;

                iso_regionWorks = iso_regionWorks;
                n->iso_region = iso_regionWorks;

                municipalityWorks = municipality;
                n->municipality = municipalityWorks;

                gps_codeWorks = gps_code;
                n->gps_code = gps_codeWorks;

                lata_codeWorks = lata_code;
                n->lata_code = lata_codeWorks;

                local_codeWorks = local_code;
                n->local_code = local_codeWorks;

                n->distance = distanceEarth(AUSLATITUDE, AUSLONGITUDE, n->latitude, n->longitude);

                t->next = n; // access the "next" of the first node and makes it point to this node
                t = t->next; // moves t to the new node

                if (i != 0) {

                    n = new node;
                }

            }


            i++;
            c++;
        }
        airportCount = c-1;
        infile.close();


    }
    else
    {
        cout << "Error opening file";
    }





    node* test;


    test = simpleSortTotal(tp);




    tp = h;



    int counter = 0;

    node* farthestAirport = assign(tp);
    while (test->next != nullptr) {


        if (test->distance < 100) {
            cout << test->airport << endl;
            cout << test->distance << endl;

        }

        if (test->distance > h->distance) {

        }

        counter++;
        test = test->next;
    }

    cout << "the farthest airport is " << farthestAirport->airport << endl;
    cout << "its distance is " << farthestAirport->distance << endl;



}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
    return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
    return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
    double lat1r, lon1r, lat2r, lon2r, u, v;
    lat1r = deg2rad(lat1d);
    lon1r = deg2rad(lon1d);
    lat2r = deg2rad(lat2d);
    lon2r = deg2rad(lon2d);
    u = sin((lat2r - lat1r)/2);
    v = sin((lon2r - lon1r)/2);
    return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

// simpleSortTotal method is written in slist.cpp file