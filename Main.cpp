//Code for Double Linked List functions
//DLL_Node.cpp
//Jairun Diemert

#include <iostream>
#include<stdlib.h>
using namespace std;

#include "DLL_Node.h"

int main()
{
    std::cout << "\n========================================================================" << std::endl;
    std::cout << " Welcome to the world of Linked Lists! \n" << std::endl;
    std::cout << " This program creates a single linked list and allows operation on the list." << std::endl;
    std::cout << "\n The single linked list created will just have a single, integer type data in it." << std::endl;
    
    DLL_Node nodeBox;
    while(1)
    {
         std::cout<<"\n\n---------- Menu --------- \n";
         std::cout<<"\n Create List           - 1\n\n Insert Node           - 2\n\n Delete Node           - 3 \n\n Display List Forward  - 4\n\n List Size             - 5\n\n Display List Backward - 6\n\n Search List           - 7\n\n Replace Element       - 8\n\n Exit                  - 9";
         std::cout<<"\n------------------------- \n";
         int userChoice;
         std::cout<<"\n Please enter your choice (1-5): ";
         std::cin>>userChoice;
         switch(userChoice)
         {
           case 1: nodeBox.create();
		   break;
           case 2 :nodeBox.insert();
		   break;
           case 3: nodeBox.del();
		   break;
           case 4: nodeBox.display();
		   break;
			 		 case 5: nodeBox.size();
		   break;
			 		 case 6: nodeBox.displayBackward();
		   break;
			 		 case 7: nodeBox.searchList();
		   break;
			     case 8: nodeBox.replace();
		   break;
           case 9: std::cout << "\n\n\n ." << std::endl;
                   std::cout << " .." << std::endl;
                   std::cout << " ..." << std::endl;
                   std::cout << " Thanks for using this program. Now ending the program... \n\n" << std::endl;
                   exit(0);
        } //end switch
    } //end while
  
    return 0;
} //end main()
