//Author: Khalid Barakzai
//April, 2022
//This Program will calculate the volume, sort and load (SL) Hours and AM Hours for each Center in Maple Grove, Minnesota.
//This Program is a tool for the FT Preload Supervisor Team.

//Compile and Run Program in Terminal:
//g++ Igate.cc -o Igate
//./Igate

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
using namespace std;

class Maple_Grove_Center 
{
    public:
        //Handling Instruction Count Number
        double DMS_Volume;

    private:
};

int main()
{
    //Given from Preload Summary Report in DMS. 
    Maple_Grove_Center Lake_Shore;
    Maple_Grove_Center Three_Rivers;
    printf("\n");
    printf("          END OF DAY REPORT          \n");
    printf("-------------------------------------\n");
    printf("\n");
    
    // current date and time on the current system
    time_t now = time(0);

    // convert now to string form
    char* date_time = ctime(&now);

    cout << date_time << endl;

    double SPA_Volume;
    cout << "SPA Volume: ";
    cin >> SPA_Volume;
    printf("\n");
    //printf("DMS -> PRELOAD SUMMARY REPORT:\n");
    //printf("-------------------------------------\n");
    cout << "Lake Shore DMS Volume: ";
    cin >> Lake_Shore.DMS_Volume;
    cout << "Three Rivers DMS Volume: ";
    cin >> Three_Rivers.DMS_Volume;
    //Given from PDOP
    printf("\n");
    //printf("-------------------------------------\n");
    double Sort_Hours;
    cout << "Sort Hours: ";
    cin >> Sort_Hours;
    double AM_Hours;
    cout << "AM Hours: ";
    cin >> AM_Hours;
    printf("\n");
    printf("--------------------------------------------------------------------------\n");
    
    //PPH
    double PPH = SPA_Volume/(Sort_Hours+AM_Hours);

    //DMS Volume added up for each Center
    double DMS_Total = Lake_Shore.DMS_Volume + Three_Rivers.DMS_Volume;

    //Difference between SPA Volume and DMS divded to add later. 
    double Difference_To_Add_To_DMS_Volume = (SPA_Volume - DMS_Total)/2.0;

    //Adding the difference of volume to each center volume.
    Lake_Shore.DMS_Volume = Lake_Shore.DMS_Volume + Difference_To_Add_To_DMS_Volume;
    Three_Rivers.DMS_Volume = Three_Rivers.DMS_Volume + Difference_To_Add_To_DMS_Volume;

    //Finding the ratio of each center's volume to match it with the SPA Volume.
    double Lake_Shore_SPA_Ratio = Lake_Shore.DMS_Volume/SPA_Volume;
    double Three_Rivers_SPA_Ratio = Three_Rivers.DMS_Volume/SPA_Volume;

    //AM hours per center 
    double Lake_Shore_AM_Hours = Lake_Shore_SPA_Ratio*AM_Hours;
    double Three_Rivers_AM_Hours = Three_Rivers_SPA_Ratio*AM_Hours;
    
    //Sort and load hours per center
    double Lake_Shore_Sort_Hours = Lake_Shore_SPA_Ratio*Sort_Hours;
    double Three_Rivers_Sort_Hours = Three_Rivers_SPA_Ratio*Sort_Hours;

    //RESULTS
    printf("\n");
    printf("\n");
    printf("              RESULTS               \n");
    printf("-------------------------------------\n");
    printf("\n");
    printf("PPH: %.2f\n", PPH);
    printf("\n");
    printf("-------------------------------------\n");
    printf("\n");
    printf("\n");

    //Lakeshore's Results for Volume, Sort and Load Hours and AM Hours.  
    printf("LAKESHORE\n");
    printf("-------------------------------------\n");
    printf("Volume: %.1f\n", Lake_Shore.DMS_Volume);
    printf("Sort & Load Hours: %.3f\n", Lake_Shore_Sort_Hours);
    printf("AM Hours: %.3f\n", Lake_Shore_AM_Hours);
    printf("\n");
    printf("\n");


    //Three River's Results for Volume, Sort and Load Hours and AM Hours.
    printf("THREE RIVERS\n");
    printf("-------------------------------------\n");
    printf("Volume: %.1f\n", Three_Rivers.DMS_Volume);
    printf("Sort & Load Hours: %.3f\n", Three_Rivers_Sort_Hours);
    printf("AM Hours: %.3f\n",Three_Rivers_AM_Hours);
    printf("\n");
}