// add your code as appropriate 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
#include "reverseorder.h"

int main(){
    // test trail for task a
    std::cout << "The East Basin storage on 03/03/2018 is: " << get_east_storage("03/03/2018") << " billion gallons" << std::endl;
    // test trial for min
    std::cout << "The East Basin's minimum storage is: " << get_min_east() << " billion gallons" << std::endl;
    //test trial for max
    std::cout << "The East Basin's maximum storage is: " << get_max_east() << " billion gallons" << std::endl;
    // test trial for task c
    std::cout << "On 03/03/2018 the " << compare_basins("03/03/2018") << " basin storage is greater."
	//test trial for task d
    std::cout << "The West Basin elevation data printed in reverse chronological order during 03/03/2018 to 03/06/2018: " << std::endl;
    reverse_order("03/03/2018", "03/06/2018");
  }