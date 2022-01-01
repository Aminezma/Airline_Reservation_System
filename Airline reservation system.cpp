/****************************************
* AirLine Ticket-Reservation System*
* Author: -Aminezma*
* IDE: Dev C++                          *
* Date: Nov 07,2017                     *
*                                       *         
*****************************************/
#include <iomanip>     //output manipulatons
#include <iostream> 
#include <string.h>    //string abstract datatype
#include <Windows.h>    //Sleep,gotoxy coordinate functions
#include<conio.h>       //getch function
using namespace std;
bool isdigits(const string &str); // test if a string  only contains numeric characters
void show_reserve_menu();
void flights_info();
bool check(string);
bool check_alphabet(string);
void flight_passenger();
struct passenger
{								//Structure of passenger is made to store passenger's attributes.	
	int ticketno;			
	string name;
	string passport;
	string cell;
	string flight;
	string address;
};
class queue                  // number of passengers in line class
{
	private:                      
		passenger arr[100];
		int front,rear,size,seat_count,ticket_number;
		int counter;
	public:
		queue() // first-in first-out passengers where passengers are inserted into one end of the line and extracted from the other.
		{
			front=rear=-1;
			size=100;
			seat_count=100;	
			ticket_number=12301;
			counter=0;
		}	
		bool isEmpty()
		{
			if(front==-1 && rear==-1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool isFull()
		{
			if(front==0 && rear==size-1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	void gotoxy(int x, int y)  	  //defining/initializing to predefined objects
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		 // X and Y coordinates
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}		
	void enqueue(string nm,string pp,string cl,string flt,string adrs)
		{
			if (isEmpty())
			{
				front++;
				rear++;
				arr[rear].ticketno=ticket_number;
				arr[rear].name=nm;
				arr[rear].passport=pp;
				arr[rear].cell=cl;
				arr[rear].flight=flt;
				arr[rear].address=adrs;
				ticket_number++;
				seat_count--;
			}
			else if(isFull())
			{
				cout<<"\nFAILED TO ENQUEUE BECAUSE QUEUE IS FULL..."<<endl;
	    	}
			else if(front!=0 && rear==size-1)
			{
				rear=0;
				arr[rear].ticketno=ticket_number;
				arr[rear].name=nm;
				arr[rear].passport=pp;
				arr[rear].cell=cl;
				arr[rear].flight=flt;
				arr[rear].address=adrs;
				ticket_number++;
				seat_count--;
			}
			else if(front!=0 && rear<=front-1)
			{
				rear++;
				arr[rear].ticketno=ticket_number;
				arr[rear].name=nm;
				arr[rear].passport=pp;
				arr[rear].cell=cl;
				arr[rear].flight=flt;
				arr[rear].address=adrs;
				ticket_number++;
				seat_count--;
			}
			else
			{
				rear++;
				arr[rear].ticketno=ticket_number;
				arr[rear].name=nm;
				arr[rear].passport=pp;
				arr[rear].cell=cl;
				arr[rear].flight=flt;
				arr[rear].address=adrs;
				ticket_number++;
				seat_count--;
			}
		}
		void dequeue()
		{
			if(isEmpty())
			{
				cout<<"\nCANNOT DEQUEUE ELEMENT BECAUSE QUEUE IS ALREADY EMPTY..."<<endl;
			}
			else if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else if(front==size-1)
			{
				front=0;
			}
			else
			{
				front=front+1;
			}
		}
		void display()
		{
				int x=4;
				int y=8;
				int s=2;
			if(front>rear)
			{
				for(int i=front;i<=size-1;i++)
				{
				gotoxy(s,y);
				Above_Horizontal();
				gotoxy(s,y+1);
				Line();
				gotoxy(s+75,y+1);
				Line();
				gotoxy(x,y+1);
				cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
				gotoxy(s,y+2);
				below_Horizontal();	
				y=y+3;
				}
				gotoxy(s,y+1);
				Above_Horizontal();
				gotoxy(s,y+2);
				Line();
				gotoxy(s+75,y+2);
				Line();
				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);
				below_Horizontal();	
				for(int i=0;i<=rear;i++)
				{
				gotoxy(s,y);
				Above_Horizontal();
				gotoxy(s,y+1);
				Line();
				gotoxy(s+75,y+1);
				Line();
				gotoxy(x,y+1);
				cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
				gotoxy(s,y+2);
				below_Horizontal();	
				y=y+3;
				}
				gotoxy(s,y+1);
				Above_Horizontal();
				gotoxy(s,y+2);
				Line();
				gotoxy(s+75,y+2);
				Line();
				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);
				below_Horizontal();
			}
			else if (front<rear)
			{
				for(int i=front;i<=rear;i++)
				{
				gotoxy(s,y);
				Above_Horizontal();
				gotoxy(s,y+1);
				Line();
				gotoxy(s+75,y+1);
				Line();
				gotoxy(x,y+1);
				cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
				gotoxy(s,y+2);
				below_Horizontal();	
				y=y+3;
				}
				gotoxy(s,y+1);
				Above_Horizontal();
				gotoxy(s,y+2);
				Line();
				gotoxy(s+75,y+2);
				Line();
				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);
				below_Horizontal();
			}
			else if(rear==front)
			{
				for(int i=front;i<=rear;i++)
				{
				gotoxy(s,y);
				Above_Horizontal();
				gotoxy(s,y+1);
				Line();
				gotoxy(s+75,y+1);
				Line();
				gotoxy(x,y+1);
				cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
				gotoxy(s,y+2);
				below_Horizontal();	
				y=y+3;
				}
				gotoxy(s,y+1);
				Above_Horizontal();
				gotoxy(s,y+2);
				Line();
				gotoxy(s+75,y+2);
				Line();
				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);
				below_Horizontal();
			}
		}
		void display_by_flight(string flt_no)
		{
			int x=4;
			int y=8;
			int s=2;
			//
			gotoxy(2,3);	
			Above_Horizontal();
			gotoxy(2,4);
			Line();	
			gotoxy(77,4);
			Line();	
			gotoxy(2,5);
			Line();	
			gotoxy(77,5);
			Line();
			gotoxy(2,6);
			Line();	
			gotoxy(77,6);
			Line();
			gotoxy(2,7);
			below_Horizontal();	
			gotoxy(31,4);
			cout<<"PASSENGER DETAILS";
			gotoxy(4,6);
			cout<<left<<setw(10)<<"Ticket#"<<setw(10)<<"Name"<<setw(15)<<"Passport No."<<setw(15)<<"Cell No."<<setw(13)<<"Flight No."<<"Address";		
			//
			if(front>rear)
			{
				for(int i=front;i<=size-1;i++)
				{
					if(flt_no==arr[i].flight)
					{
						gotoxy(s,y);
						Above_Horizontal();
						gotoxy(s,y+1);
						Line();
						gotoxy(s+75,y+1);
						Line();
						gotoxy(x,y+1);
						cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
						gotoxy(s,y+2);
						below_Horizontal();	
						y=y+3;
					}
				}
				gotoxy(s,y+1);
				Above_Horizontal();
				gotoxy(s,y+2);
				Line();
				gotoxy(s+75,y+2);
				Line();
				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);
				below_Horizontal();
				//
				for(int i=0;i<=rear;i++)
				{
					if(flt_no==arr[i].flight)
					{
						gotoxy(s,y);
						Above_Horizontal();
						gotoxy(s,y+1);
						Line();
						gotoxy(s+75,y+1);
						Line();
						gotoxy(x,y+1);
						cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
						gotoxy(s,y+2);
						below_Horizontal();	
						y=y+3;
					}
				}
				gotoxy(s,y+1);
				Above_Horizontal();
				gotoxy(s,y+2);
				Line();
				gotoxy(s+75,y+2);
				Line();
				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);
				below_Horizontal();
			}
			else if (front<rear)
			{
				for(int i=front;i<=rear;i++)
				{
					if(flt_no==arr[i].flight)
					{
						gotoxy(s,y);
						Above_Horizontal();
						gotoxy(s,y+1);
						Line();
						gotoxy(s+75,y+1);
						Line();
						gotoxy(x,y+1);
						cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
						gotoxy(s,y+2);
						below_Horizontal();	
						y=y+3;
					}
				}
				gotoxy(s,y+1);
				Above_Horizontal();
				gotoxy(s,y+2);
				Line();
				gotoxy(s+75,y+2);
				Line();
				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);
				below_Horizontal();
			}
			else if(rear==front)
			{
				for(int i=front; i<=rear;i++)
				{
					if(flt_no==arr[rear].flight)
					{
						gotoxy(s,y);
						Above_Horizontal();
						gotoxy(s,y+1);
						Line();
						gotoxy(s+75,y+1);
						Line();
						gotoxy(x,y+1);
						cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
						gotoxy(s,y+2);
						below_Horizontal();	
						y=y+3;
					}
				}
				gotoxy(s,y+1);
				Above_Horizontal();
				gotoxy(s,y+2);
				Line();
				gotoxy(s+75,y+2);
				Line();
				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);
				below_Horizontal();
			}
		}
	void Above()
	{
		char prev = ' ';
		prev = cout.fill((char)205);
		cout << (char)201 << setw(45) << "" << (char)187 << endl;
		cout.fill(prev);
	}
	void lines()
	{
		cout << (char)186<< endl;
	}
	void below()
	{
		char prev = ' ';
		prev = cout.fill((char)205);
		cout << (char)200 << setw(45) << "" << (char)188 << endl;
		cout.fill(prev);
	}
		void display_ticket(int ticket_no)
		{
			bool run=false;
			for(int i=0;i<=size-1;i++)
			{
				if(arr[i].ticketno==ticket_no)
				{
					gotoxy(19,6);
					cout<<"Ticket No:             "<<arr[i].ticketno;
					gotoxy(19,8);
					cout<<"Name:                  "<<arr[i].name;
					gotoxy(19,10);
					cout<<"Passport:              "<<arr[i].passport;
					gotoxy(19,12);
					cout<<"Cell No:               "<<arr[i].cell;
					gotoxy(19,14);
					cout<<"Flight No:             "<<arr[i].flight;
					gotoxy(19,16);
					cout<<"Address:               "<<arr[i].address;
				//
					gotoxy(17,5);
					Above();
					gotoxy(17,6);
					lines();
					gotoxy(63,6);
					lines();
					gotoxy(17,7);
					lines();
					gotoxy(63,7);
					lines();
					gotoxy(17,8);
					lines();
					gotoxy(63,8);
					lines();
					gotoxy(17,9);
					lines();
					gotoxy(63,9);
					lines();
					gotoxy(17,10);
					lines();
					gotoxy(63,10);
					lines();
					gotoxy(17,11);
					lines();
					gotoxy(63,11);
					lines();
					gotoxy(17,12);
					lines();
					gotoxy(63,12);
					lines();
					gotoxy(17,13);
					lines();
					gotoxy(63,13);
					lines();
					gotoxy(17,13);
					lines();
					gotoxy(63,13);
					lines();
					gotoxy(17,13);
					lines();
					gotoxy(63,13);
					lines();
					gotoxy(17,13);
					lines();
					gotoxy(63,13);
					lines();
					gotoxy(17,14);
					lines();
					gotoxy(63,14);
					lines();
					gotoxy(17,15);
					lines();
					gotoxy(63,15);
					lines();
					gotoxy(17,16);
					lines();
					gotoxy(63,16);
					lines();
					gotoxy(17,17);
					lines();
					gotoxy(63,17);
					lines();
					gotoxy(17,18);
					below();
					run=true;
				}
			}
			if(run==false)
			{
				system("CLS");
				cout<<"Ticket Number You Entered Is Not Valid..."<<endl<<endl;
			}
		}
	void flight_passenger()
	{
	int ch;
	gotoxy(2,19);
	cout<<"Enter Serial No. of Flight Whose Passengers You Want To Know: ";
	cin>>ch;
	switch (ch)
	{
		case 1:
			system("CLS");
			display_by_flight("NBIM-108");
			break;
		case 2:
			system("CLS");
			display_by_flight("MGAR-320");
			break;
		case 3:
			system("CLS");
			display_by_flight("KISM-170");
			break;
		case 4:
			system("CLS");
			display_by_flight("ELDON-102");
			break;
		case 5:
			system("CLS");
			display_by_flight("MOMN-101");
			break;
		default:
			system("CLS");	
			cout<<"Invalid Flight Number..."<<endl;
			break;
		}
	}	
	void input()
	{
		system("CLS");	
		gotoxy(2,2);	
		Above_Horizontal();
		gotoxy(2,3);
		Line();
		gotoxy(77,3);
		Line();
		gotoxy(2,4);
		below_Horizontal();
		//
		gotoxy(2,5);	
		Above_Horizontal();
		gotoxy(2,6);
		Line();
		gotoxy(77,6);
		Line();
		gotoxy(2,7);
		below_Horizontal();
		//
		gotoxy(2,8);	
		Above_Horizontal();
		gotoxy(2,9);
		Line();
		gotoxy(77,9);
		Line();	
		gotoxy(2,10);
		below_Horizontal();
		//
		gotoxy(2,11);	
		Above_Horizontal();
		gotoxy(2,12);
		Line();
		gotoxy(77,12);
		Line();
		gotoxy(2,13);
		below_Horizontal();
	}
	void show_reserve_menu()
	{
		int choice;
		char ch='y';
		string name,passport,cell,flight,address;
		system("CLS");
		while(ch=='y' || ch=='Y')
		{
			flights_info();
			gotoxy(2,19);
			cout<<"ENTER THE SERIAL NO. OF FLIGHT IN WHICH YOU WANT TO RESERVE SEAT:  ";
			cin>>choice;
			switch(choice)
			{
				case 1:
					system("CLS");
					input();
					gotoxy(23,3);
					cout<<"Enter Passenger Name: ";
					cin>>name;
					while(check(name)==false)
					{
						gotoxy(45,3);
						cout<<"                       "<<endl;
						gotoxy(45,3);
						cin>>name;
					}
					gotoxy(23,6);	
					cout<<"Enter Passport Number: ";
					cin>>passport;
					for(int i=0;i<=size-1;i++)
					{
						if(passport==arr[i].passport)
						{
							gotoxy(46,6);
							cout<<"                       "<<endl;
							gotoxy(46,6);
							cin>>passport;
						}
					}
					while(check_alphabet(passport)== false)
					{
						gotoxy(46,6);
						cout<<"                       "<<endl;
						gotoxy(46,6);
						cin>>passport;
					}
					gotoxy(23,9);	
					cout<<"Enter Cell Number: ";
					cin>>cell;
					for(int i=0;i<=size-1;i++)
					{
						if(cell==arr[i].cell)
						{
							gotoxy(42,9);
							cout<<"                       "<<endl;
							gotoxy(42,9);
							cin>>cell;
						}
					}
					while(check_alphabet(cell)==false)
					{
						gotoxy(42,9);
						cout<<"                   "<<endl;
						gotoxy(42,9);
						cin>>cell;
					}
					gotoxy(23,12);	
					cout<<"Enter Address: ";
					cin>>address;
					while(check(address)==false)
					{
						gotoxy(38,12);
						cout<<"                       ";
						gotoxy(38,12);
						cin>>address;
					}
					gotoxy(23,15);	
					flight="NBIM-108";
					enqueue(name,passport,cell,flight,address);
					cout<<"\nYOUR RECORD HAS BEEN SUCCESSFULLY ENTERED..."<<endl;
					break;
				case 2:
					system("CLS");
					input();
					gotoxy(23,3);
					cout<<"Enter Passenger Name: ";
					cin>>name;
					while(check(name)==false)
					{
						gotoxy(45,3);
						cout<<"                       "<<endl;
						gotoxy(45,3);
						cin>>name;
					}
					gotoxy(23,6);	
					cout<<"Enter Passport Number: ";
					cin>>passport;
					for(int i=0;i<=size-1;i++)
					{
						if(passport==arr[i].passport)
						{
							gotoxy(46,6);
							cout<<"                       "<<endl;
							gotoxy(46,6);
							cin>>passport;
						}
					}
					while(check_alphabet(passport)== false)
					{
						gotoxy(46,6);
						cout<<"                       "<<endl;
						gotoxy(46,6);
						cin>>passport;
					}
					gotoxy(23,9);	
					cout<<"Enter Cell Number: ";
					cin>>cell;
					for(int i=front;i<=rear;i++)
					{
						if(cell==arr[i].cell)
						{
							gotoxy(42,9);
							cout<<"                       "<<endl;
							gotoxy(42,9);
							cin>>cell;
						}
					}
					while(check_alphabet(cell)==false)
					{
						gotoxy(42,9);
						cout<<"                   "<<endl;
						gotoxy(42,9);
						cin>>cell;
					}
					gotoxy(23,12);	
					cout<<"Enter Address: ";
					cin>>address;
					while(check(address)==false)
					{
						gotoxy(38,12);
						cout<<"                       ";
						gotoxy(38,12);
						cin>>address;
					}
					gotoxy(23,15);	
					flight="MGAR-320";
					enqueue(name,passport,cell,flight,address);
					cout<<"\nYOUR RECORD HAS BEEN SUCCESSFULLY ENTERED..."<<endl;
					break;
				case 3:
					system("CLS");
					input();
					gotoxy(23,3);
					cout<<"Enter Passenger Name: ";
					cin>>name;
					while(check(name)==false)
					{
						gotoxy(45,3);
						cout<<"                       "<<endl;
						gotoxy(45,3);
						cin>>name;
					}
					gotoxy(23,6);	
					cout<<"Enter Passport Number: ";
					cin>>passport;
					for(int i=0;i<=size-1;i++)
					{
						if(passport==arr[i].passport)
						{
							gotoxy(46,6);
							cout<<"                       "<<endl;
							gotoxy(46,6);
							cin>>passport;
						}
					}
					while(check_alphabet(passport)== false)
					{
						gotoxy(46,6);
						cout<<"                       "<<endl;
						gotoxy(46,6);
						cin>>passport;
					}
					gotoxy(23,9);	
					cout<<"Enter Cell Number: ";
					cin>>cell;
					for(int i=0;i<=size-1;i++)
					{
						if(cell==arr[i].cell)
						{
							gotoxy(42,9);
							cout<<"                       "<<endl;
							gotoxy(42,9);
							cin>>cell;
						}
					}
					while(check_alphabet(cell)==false)
					{
						gotoxy(42,9);
						cout<<"                   "<<endl;
						gotoxy(42,9);
						cin>>cell;
					}
					gotoxy(23,12);	
					cout<<"Enter Address: ";
					cin>>address;
					while(check(address)==false)
					{
						gotoxy(38,12);
						cout<<"                       ";
						gotoxy(38,12);
						cin>>address;
					}
					gotoxy(23,15);	
					flight="KISM-170";
					enqueue(name,passport,cell,flight,address);
					cout<<"\nYOUR RECORD HAS BEEN SUCCESSFULLY ENTERED..."<<endl;
					break;
				case 4:
					system("CLS");
					input();
					gotoxy(23,3);
					cout<<"Enter Passenger Name: ";
					cin>>name;
					while(check(name)==false)
					{
						gotoxy(45,3);
						cout<<"                       "<<endl;
						gotoxy(45,3);
						cin>>name;
					}
					gotoxy(23,6);	
					cout<<"Enter Passport Number: ";
					cin>>passport;
					for(int i=0;i<=size-1;i++)
					{
						if(passport==arr[i].passport)
						{
							gotoxy(46,6);
							cout<<"                       "<<endl;
							gotoxy(46,6);
							cin>>passport;
						}
					}
					while(check_alphabet(passport)== false)
					{
						gotoxy(46,6);
						cout<<"                       "<<endl;
						gotoxy(46,6);
						cin>>passport;
					}
					gotoxy(23,9);	
					cout<<"Enter Cell Number: ";
					cin>>cell;
					for(int i=0;i<=size-1;i++)
					{
						if(cell==arr[i].cell)
						{
							gotoxy(42,9);
							cout<<"                       "<<endl;
							gotoxy(42,9);
							cin>>cell;
						}
					}
					while(check_alphabet(cell)==false)
					{
						gotoxy(42,9);
						cout<<"                   "<<endl;
						gotoxy(42,9);
						cin>>cell;
					}
					gotoxy(23,12);	
					cout<<"Enter Address: ";
					cin>>address;
					while(check(address)==false)
					{
						gotoxy(38,12);
						cout<<"                       ";
						gotoxy(38,12);
						cin>>address;
					}
					gotoxy(23,15);	
					flight="ELD0N-102";
					enqueue(name,passport,cell,flight,address);
					cout<<"\nYOUR RECORD HAS BEEN SUCCESSFULLY ENTERED..."<<endl;
					break;
				case 5:
					system("CLS");
					input();
					gotoxy(23,3);
					cout<<"Enter Passenger Name: ";
					cin>>name;
					while(check(name)==false)
					{
						gotoxy(45,3);
						cout<<"                       "<<endl;
						gotoxy(45,3);
						cin>>name;
					}
					gotoxy(23,6);	
					cout<<"Enter Passport Number: ";
					cin>>passport;
					for(int i=0;i<=size-1;i++)
					{
						if(passport==arr[i].passport)
						{
							gotoxy(46,6);
							cout<<"                       "<<endl;
							gotoxy(46,6);
							cin>>passport;
						}
					}
					while(check_alphabet(passport)== false)
					{
						gotoxy(46,6);
						cout<<"                       "<<endl;
						gotoxy(46,6);
						cin>>passport;
					}
					gotoxy(23,9);	
					cout<<"Enter Cell Number: ";
					cin>>cell;
					for(int i=0;i<=size-1;i++)
					{
						if(cell==arr[i].cell)
						{
							gotoxy(42,9);
							cout<<"                       "<<endl;
							gotoxy(42,9);
							cin>>cell;
						}
					}
					while(check_alphabet(cell)==false)
					{
						gotoxy(42,9);
						cout<<"                   "<<endl;
						gotoxy(42,9);
						cin>>cell;
					}
					gotoxy(23,12);	
					cout<<"Enter Address: ";
					cin>>address;
					while(check(address)==false)
					{
						gotoxy(38,12);
						cout<<"                       ";
						gotoxy(38,12);
						cin>>address;
					}
					gotoxy(23,15);	
					flight="MOMN-101";
					enqueue(name,passport,cell,flight,address);
					cout<<"\nYOUR RECORD HAS BEEN SUCCESSFULLY ENTERED..."<<endl;
					break;
				default:
					system("CLS");
					cout<<"Please Enter A Valid Serial Number....!! \n"<<endl;
					system("pause");
					break;	
			}
			system("CLS");
			cout<<"Do you want to enter again(Y/N):  ";
			cin>>ch;
			system("CLS");
		}
	}
	void Above_Horizontal()
	{
		char prev = ' ';
		prev = cout.fill((char)205);
		cout << (char)201 << setw(74) << "" << (char)187 << endl;
		cout.fill(prev);
	}
	void Line()
	{
	cout << (char)186<< endl;
	}
	void below_Horizontal()
	{
		char prev = ' ';
		prev = cout.fill((char)205);
		cout << (char)200 << setw(74) << "" << (char)188 << endl;
		cout.fill(prev);
	}
		void flight_info()
		{
			gotoxy(2,2);	
			Above_Horizontal();
			gotoxy(2,3);
			Line();	
			gotoxy(77,3);
			Line();
			gotoxy(2,4);
			Line();	
			gotoxy(77,4);
			Line();
			gotoxy(2,5);
			Line();	
			gotoxy(77,5);
			Line();
			gotoxy(2,6);
			Line();	
			gotoxy(77,6);
			Line();
			gotoxy(2,7);
			Line();	
			gotoxy(77,6);
			Line();
			gotoxy(2,7);
			Line();	
			gotoxy(77,7);
			Line();
			gotoxy(2,8);
			Line();	
			gotoxy(77,8);
			Line();
			gotoxy(2,9);
			Line();	
			gotoxy(77,9);
			Line();
			//
			gotoxy(2,10);
			Line();	
			gotoxy(77,10);
			Line();
			gotoxy(2,11);
			Line();	
			gotoxy(77,11);
			Line();
			gotoxy(2,12);
			Line();	
			gotoxy(77,12);
			Line();
			gotoxy(2,13);
			Line();	
			gotoxy(77,13);
			Line();
			gotoxy(2,14);
			Line();	
			gotoxy(77,14);
			Line();
			gotoxy(2,15);
			Line();	
			gotoxy(77,15);
			Line();
			gotoxy(2,16);
			Line();	
			gotoxy(77,16);
			Line();
			gotoxy(2,17);
			below_Horizontal();
		}
	void flights_info()
	{
		flight_info();
		gotoxy(31,1);
		cout<<"AVAILABLE FLIGHTS";
		gotoxy(4,4);
		cout<<left<<setw(6)<<"No."<<setw(15)<<"Flight. No"<<setw(14)<<"From"<<setw(17)<<"Destination"<<setw(14)<<"Time"<<"Fare";
		gotoxy(4,6);
		cout<<left<<setw(6)<<"1"<<setw(15)<<"NBIM-108"<<setw(14)<<"NAIROBI"<<setw(17)<<"MOMBASA"<<setw(14)<<"11:00 PM"<<"Ksh.10000";
		gotoxy(4,8);
		cout<<left<<setw(6)<<"2"<<setw(15)<<"MGAR-320"<<setw(14)<<"MOMBASA"<<setw(17)<<"GARISSA"<<setw(14)<<"12:00 PM"<<"Ksh.25000";
		gotoxy(4,10);
		cout<<left<<setw(6)<<"3"<<setw(15)<<"KISM-170"<<setw(14)<<"KISUMU"<<setw(17)<<"MOMBASA"<<setw(14)<<"03:00 PM"<<"Ksh.15000";
		gotoxy(4,12);
		cout<<left<<setw(6)<<"4"<<setw(15)<<"ELDN-102"<<setw(14)<<"ELDORET"<<setw(17)<<"NAKURU"<<setw(14)<<"02:00 AM"<<"Ksh.5000";
		gotoxy(4,14);
		cout<<left<<setw(6)<<"5"<<setw(15)<<"MOMN-101"<<setw(14)<<"MOMBASA"<<setw(17)<<"NAIROBI"<<setw(14)<<"09:00 AM"<<"Ksh.10000";	
	}
	void Menu()
	{
		gotoxy(2,2);	
		Above_Horizontal();
		gotoxy(2,3);
		Line();
		gotoxy(77,3);
		Line();
		gotoxy(2,4);
		Line();
		gotoxy(77,4);
		Line();
		gotoxy(2,5);
		Line();
		gotoxy(77,5);
		Line();
		gotoxy(2,6);
		Line();
		gotoxy(77,6);
		Line();
		gotoxy(2,7);
		Line();
		gotoxy(77,7);
		Line();
		gotoxy(2,8);
		Line();
		gotoxy(77,8);
		Line();
		gotoxy(2,9);
		Line();
		gotoxy(77,9);
		Line();
		gotoxy(2,10);
		Line();
		gotoxy(77,10);
		Line();
		gotoxy(2,11);
		Line();
		gotoxy(77,11);
		Line();
		gotoxy(2,12);
		Line();
		gotoxy(77,12);
		Line();
		gotoxy(2,13);
		Line();
		gotoxy(77,13);
		Line();
		gotoxy(2,14);
		Line();
		gotoxy(77,14);
		Line();
		gotoxy(2,15);
		Line();
		gotoxy(77,15);
		Line();
		gotoxy(2,16);
		below_Horizontal();
		//
		gotoxy(35,3);
		cout<<"MAIN MENU"<<endl;
		gotoxy(28,1);
		cout<<"What do you want to do?"<<endl;
		gotoxy(4,6);
		cout<<"1-Reserve Seat"<<endl;
		gotoxy(4,8);
		cout<<"2-My Ticket"<<endl;
		gotoxy(4,10);
		cout<<"3-Flights Schedule"<<endl;
		gotoxy(4,12);
		cout<<"4-Display Passengers"<<endl;
		gotoxy(4,14);
		cout<<"5-Quit Program"<<endl;
	}
};

queue obj;

int main()
{
	int choice,tcno;
	system("CLS");
	system("color B1");
	obj.Menu();
	obj.gotoxy(4,18);
	cout<<"Enter Your Choice: ";
	l:
	char c=getch();
  		if(c>='1' && c<='8')
		{
		choice=c-48;
		cout<<c;
	  		goto l2;
		}
		else
		{
			choice=getch();
		}
  	goto l;
	l2:
  	Sleep(200);
  	system("CLS");
	switch(choice)
	{
		case 1:		
			system("CLS");							
			obj.show_reserve_menu();
			system("pause");
			system("CLS");
			main();
			break;
		case 2:			
			system("CLS");
			if(obj.isEmpty())
			{
				cout<<"Record Is Empty....! \n"<<endl;
			}
			else
			{
				cout<<"Enter Your Ticket Number: ";
				cin>>tcno;						
				obj.display_ticket(tcno);
			}
			system("pause");
			system("CLS");
			main();
			break;
		case 3:
			system("CLS");
			if(obj.isEmpty())
			{
				cout<<"Record Is Empty....! \n"<<endl;
			}
			else
			{
				obj.flights_info();
				obj.flight_passenger();
			}
			system("pause");
			system("CLS");
			main();
			break;
		case 4:
			system("CLS");
			if(obj.isEmpty())
			{
				cout<<"Record Is Empty....! \n"<<endl;
			}
			else
			{
			obj.gotoxy(2,3);	
			obj.Above_Horizontal();
			obj.gotoxy(2,4);
			obj.Line();	
			obj.gotoxy(77,4);
			obj.Line();	
			obj.gotoxy(2,5);
			obj.Line();	
			obj.gotoxy(77,5);
			obj.Line();
			obj.gotoxy(2,6);
			obj.Line();	
			obj.gotoxy(77,6);
			obj.Line();
			obj.gotoxy(2,7);
			obj.below_Horizontal();	
			obj.gotoxy(31,4);
			cout<<"PASSENGER DETAILS";
			obj.gotoxy(4,6);
			cout<<left<<setw(10)<<"Ticket#"<<setw(10)<<"Name"<<setw(15)<<"Passport No."<<setw(15)<<"Cell No."<<setw(13)<<"Flight No."<<"Address";
			obj.display();
			}
			system("pause");
			system("CLS");
			main();
			break;
		case 5:		
			return 0;
			break;
		default:					//Default value for invalid Input. 
			cout<<"Invalid Number..."<<endl;
			system("pause");
			system("CLS");
			main();
			}
	return 0;
}
bool check(string a)
{
	int i=0;
	while(a[i]!=0)
	{
		if(a[i]>=48 && a[i]<=57)
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}
bool check_alphabet(string a)
{
	int i=0;
	while(a[i]!=0)
	{
		if(a[i]>=65 && a[i]<=122)
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}
