#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
//Task D:
// For this task, add new files, reverseorder.cpp 
//and reverseorder.h. You will have to modify the 
//Makefile appropriately.
//In these files create a function 
//void reverse_oreder(std::string date1, std::string date2). 
//This function should print out the West basin elevation 
//for all days in the interval in reverse chronological order.
const int MAX_DATA_POINTS = 365;

void reverse_order(std::string date1, std::string date2){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); 
    }
    std::string junk;
    std::getline(fin, junk);
    std::string date_array[MAX_DATA_POINTS];
    double westElArray[MAX_DATA_POINTS];
    int index = 0;
    bool startWrite = false;

    while (index < MAX_DATA_POINTS && fin >> date_array[index] >> junk >> junk >> junk >> westElArray[index])
    {
        if (date_array[index] == date1){
            startWrite = true;
        }
        if (startWrite){
			index++;
        }
		if (date_array[index-1] == date2){
            break;
        }
        std::getline(fin, junk);
    }
    fin.close();

    for (int i = index - 1; i >= 0; i--)
    {
        std::cout << date_array[i] << " " << westElArray[i] << std::endl;
    }
}