#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

//Task A:
// Write a program that consists of two .cpp files 
//plus any supporting files. One will be named main.cpp 
//and it will drive your program. It will contain the main 
//function. The other file should be named reservoir.cpp and 
//should contain a function with the prototype 
//double get_east_storage(std::string date).

double get_east_storage(std::string date)
{
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); 
    }
    std::string junk;
    std::getline(fin, junk); 
	std::string extracted_date;
    double eastSt;
	while (fin >> extracted_date >> eastSt) {
        if (date == extracted_date)
        {
            return eastSt;
        }
        fin.ignore(INT_MAX, '\n');
    }
	fin.close();
    return 0;
}

 //task B part 1: 
 //double get_min_east() - this function should 
 //return the minimum storage in the East basin in the 2018
double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    std::getline(fin, junk);
    std::string extracted_date;
    double eastSt = 0.0;
    double minstor = 100.0;

    while (fin >> extracted_date >> eastSt){
        if (eastSt < minstor){
            minstor = eastSt; 
        }
        fin.ignore(INT_MAX, '\n');
    }
    fin.close();
    return minstor;

//task b part 2:
//double get_max_east() - this function 
//should return the maximum storage in the 
//East basin in the 2018.
double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    std::getline(fin, junk);
    std::string extracted_date;
    double eastSt = 0.0;
    double maxstor= 0.0; 
    while (fin >> extracted_date >> eastSt){
        if (eastSt > maxstor){
            maxstor = eastSt;
        }
        fin.ignore(INT_MAX, '\n'); 
    }
    fin.close();
    return maxstor;
}
// Task C:
//Add a function std::string compare_basins(std::string date) 
//that will return East if the East basin was higher 
//on the specified date and West if the West was higher. 
//It should return Equal if the values were the same.

std::string compare_basins(std::string date){
   std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    std::getline(fin, junk);
    std::string extracted_date;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;
    while (fin >> extracted_date >> eastSt >> eastEl >> westSt >> westEl){
        if (date == extracted_date){
            if (eastEl > westEl){
                return "East";
            }
            else if (westEl > eastEl){
                return "West";
            }
            else{
                return "Equal";
            }
        }
        fin.ignore(INT_MAX, '\n');
    }
    fin.close();
    return 0;
}