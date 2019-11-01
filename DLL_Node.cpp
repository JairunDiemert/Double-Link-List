//File: DLL_Node.cpp
//Author: Jairuhigh Diemert
//Class: COP3530
//Project: Class work
//Description: This is the member function file for DLL_Node.

#include <iostream>
#include <cstdlib>
using namespace std;

#include "DLL_Node.h"

void DLL_Node::create()
{
    int n;
    currNodePtr=new DLL_Node;
    std::cout<<"\n\n Okay! Creating the list for you...." << std::endl;
    std::cout<<" Enter the integer data for the first node: ";
    char ch='y';
    std::cin>>currNodePtr->data;
    head=currNodePtr;
		tail=currNodePtr;//jairun
		currNodePtr->previous = NULL;//jairun
    currNodePtr->next=NULL;
    std::cout<<"\n\n First Node successfully added.";
    std::cout<<"\n\n Do you wish to add another node? (y/n): ";
    std::cin>>ch;

    while( ch=='y')
    {
	 newNodePtr=new DLL_Node;
	 std::cout<<"\n\n Enter the integer data for the Node: ";
	 std::cin>>newNodePtr->data;
	 currNodePtr->next=newNodePtr;
	 newNodePtr->next=NULL;  //nullptr for C++11
	 newNodePtr->previous = currNodePtr;//jairun
	 tail=newNodePtr; //jairun
	 currNodePtr=newNodePtr;
         std::cout << "\n Node successfully inserted!" << std::endl;
	 std::cout<<"\n\n Do you wish to add another node? (y/n): ";
	 std::cin>>ch;
    } //end while
} //end create()



void DLL_Node::insert()
  {
    int  ch;

    newNodePtr=new DLL_Node;

    std::cout<<"\n Insert at the beginning of the list - 1 \n Insert at the end of the list       - 2 \n Insert somewhere in the middle      - 3";
    std::cout<<"\n\n\t Please enter your choice (1/2/3): ";
    std::cin>>ch;

    std::cout<<"\n Please enter the data for this node: ";
    std::cin>>newNodePtr->data;
    currNodePtr=head;

    if(head==NULL)
    {
	head=newNodePtr;
	tail=newNodePtr;
	newNodePtr->next=NULL;
	newNodePtr->previous = NULL;//jairun
    }
    else
    switch(ch)
    {

      case 1:   newNodePtr->next=currNodePtr;
		head=newNodePtr;
		newNodePtr->previous = NULL; //Jairun
                std::cout << "\n Node successfully inserted!" << std::endl;
		break;
      case 2:
		while(currNodePtr->next!=NULL)
		   currNodePtr=currNodePtr->next;

		newNodePtr->next=NULL;
		newNodePtr->previous = currNodePtr;//Jairun
		currNodePtr->next=newNodePtr;
		tail=newNodePtr;//jairun
                std::cout << "\n Node successfully inserted!" << std::endl;
		break;

      case 3 :  std::cout<<"\n Enter after which Node (Please specify the Data of that Node)?: ";
	        int item;
	        std::cin>>item;
	        while(currNodePtr->next!=NULL  && currNodePtr->data!=item)
		    currNodePtr=currNodePtr->next;

                if(currNodePtr->data==item)
	         {
		    newNodePtr->next=currNodePtr->next;
		    currNodePtr->next=newNodePtr;
				newNodePtr->previous=currNodePtr;
                    std::cout << "\n Node successfully inserted!" << std::endl;
	         }
	        else
		    std::cout<<"\n No such Node exists!!";
	        break;

      default :  std::cout<<"\n\n No Node entered in the List yet. Please reconsider your choice.\n ";
   } //end switch

 } //end insert


void DLL_Node::del()
{
       currNodePtr=head;

       if(head==NULL)
       {
	   std::cout<<"\n No Node in the List!";
	   //getch();

	}

       else if(currNodePtr->next==NULL)
       {
	  std::cout<<"\n Deleted .... No more Nodes in the List!";
	  head=NULL;
		tail=NULL;
	  //getch();
       }

       else
       {
          std::cout<<"\n Delete the first Node          - 1\n Delete the last Node           - 2\n Delete somewhere in the middle - 3" <<std::endl;
          std::cout<<"\n\t Please enter your choice (1/2/3): ";

          int ch;
          std::cin>>ch;

          switch(ch)
          {

             case 1:   head=currNodePtr->next;
		       free(currNodePtr);
		       std::cout<<"\n Node Deleted.";
		       break;

             case 2:   while(currNodePtr->next!=NULL)
		       {
		          newNodePtr=currNodePtr;
		          currNodePtr=currNodePtr->next;
		       }
		       newNodePtr->next=NULL;
					 tail=newNodePtr;//jairun

		       std::cout<<"\n Node Deleted.";
		       free(currNodePtr);
		       break;

             case 3:   std::cout<<"\n Which Node do you wish to delete? Please specify its integer data: " ;
		       int item,i=0;
		       std::cin>>item;
		       currNodePtr=head;
		       newNodePtr=head;
		       head=newNodePtr;

		       while(currNodePtr->next!=NULL && currNodePtr->data !=item)
		       {
		          i++;
		          newNodePtr=currNodePtr;
		          currNodePtr=currNodePtr->next;
		       }

		       if(currNodePtr->data==item)
		       {
		         if (i==0)
		         {
		            std::cout<<"\n Node Deleted.";
		            head=currNodePtr->next;
		         }
		         else
		         {
		            std::cout<<"\n Node Deleted.";
		            newNodePtr->next=currNodePtr->next;
		            free(currNodePtr);
		         }
	          }

		       else
		         std::cout<<"\n No Node Deleted! " ;
		       break;

              //default : std::cout<<"\n\n Sorry!! That choice is invalid!!";
	    } //end switch
         } //end else
 } //end del()

void DLL_Node::searchList()
{
	currNodePtr=head;

       if(head==NULL)
       {
	        std::cout<<"\n No Node in the List!";
	     }

			 std::cout<<"\n Which Node do you wish to seach? Please specify its integer data: " ;
		       int item,i=1;
		       std::cin>>item;
		       currNodePtr=head;

		       while(currNodePtr->next!=NULL && currNodePtr->data !=item)
		       {
		          i++;
							currNodePtr=currNodePtr->next;
		       }

		       if(currNodePtr->data==item)
		       {
		         std::cout<<"\n Node Data : "<<currNodePtr->data << " \nLocate at index: " << i <<"\n";
					 }
		       else
		         std::cout<<"\n No Node Found! " ;
}

void DLL_Node::display()
{
   currNodePtr=head;

   if(head==NULL)
       std::cout<<"\n No Node yet!\n";
   else
   {
      while(currNodePtr->next!=NULL)
      {
	 std::cout<<"\n Node Data : "<<currNodePtr->data;
	 currNodePtr=currNodePtr->next;
      }
      std::cout<<"\n Node Data : "<<currNodePtr->data;
   } //end else
} //end display()

void DLL_Node::displayBackward()
{
	currNodePtr=head;

   if(head==NULL)
       std::cout<<"\n No Node yet!\n";

	else
	{
		currNodePtr=tail;
		while(currNodePtr->previous!=NULL)
		{
			std::cout<<"\n Node Data : "<<currNodePtr->data;
	    currNodePtr=currNodePtr->previous;
		}
		std::cout<<"\n Node Data : "<<currNodePtr->data;
	}
}


void DLL_Node::size()
{
	currNodePtr=head;
	int size = 1;

	if(head==NULL)
		std::cout << "\n No elements in list.\n";
	else
	{
		while(currNodePtr->next!=NULL)
		{
			++size;
			currNodePtr=currNodePtr->next;
		}
		std::cout << "\n There are " << size << " elements in the list.\n";
	}
	
}

void DLL_Node::replace()
{
	
	currNodePtr=head;
	newNodePtr=new DLL_Node;

	if(head==NULL)
  {
		std::cout<<"\n No Node in the List!";
	}
	else
	{
		std::cout<<"\n Enter which Node to replace(Please specify the Data of that Node)?: ";
	  int item;
	  std::cin>>item;

	  while(currNodePtr->next!=NULL  && currNodePtr->data!=item)
		{
		  currNodePtr=currNodePtr->next;
		}
    if(currNodePtr->data==item)
	  {
			std::cout<<"\n Please enter the data for this node: ";
    	std::cin>>newNodePtr->data;
			currNodePtr->data = newNodePtr->data;
		}
		else
			std::cout<<"\n No such Node exists!!";
	}
}