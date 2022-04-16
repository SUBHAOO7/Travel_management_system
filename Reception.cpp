#include<iostream>
#include<fstream> // to handle our files
#include<iomanip> // to show floating point values used to manipulate the output
#include<windows.h>

using namespace std;

void menu();

class ManageMenu
{
	protected:
	    string userName; //hide admin name
	public :
		ManageMenu() //constructor
		{
			system("color 0A"); //change terminal color
	        cout << "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
	        cin >> userName;
	        system("CLS");
	        menu(); //call to main function to load after executing the constructr
        }

    ~ManageMenu(){} //de
		  	
}; 

class Customers //create class
{
	public:
		string name,gender,address; //atributes
		long long int age,mobile_no,menuBack;
		static int cus_ID;
		char all[999]; // create this array for getline() function
		
		//create method to get details from user
		void getDetails()
		{
			//save the details is old-customers.txt file
			ofstream out("old-customers.txt", ios:: app); //append mode
			{
				cout<<"Enter customer ID: ";
				cin>>cus_ID;
				cout<<"Enter customer name: ";
				cin>>name;
				cout<<"Enter customer gender: ";
				cin>>gender;
				cout<<"Enter customer age: ";
				cin>>age;
				cout<<"Enter customer mobile_no: ";
				cin>>mobile_no;
				cout<<"Enter customer address: ";
				cin>>address;				
			}
			out<<"\nCustomer ID: "<<cus_ID<<"\nName: "<<name<<"\nGender: "<<gender<<"\nAge: "<<age<<"\nMobile no: "<<mobile_no<<"\nAddress: "<<address<<endl;
			out.close();
			cout<<"\nSAVED \nNOTE: We save your details record for future purpose\n"<<endl;
		}
		
		//show the details
		void showDetails()
		{
			ifstream inf("old-customers.txt");
			{
				if (!inf)
				{
					cout<<"File Error!"<<endl;
				}
				while (!(inf.eof())) // .eof comes from fstream header file
				{
					inf.getline(all,999); // to get all lines 
					cout<<all<<endl;
				}
			}
			inf.close(); //close this open file 
		}
};

int Customers::cus_ID;

class Cabs
{
	public:
		int cabChoice,Km;
		float cabCost;
		static float lastcabCost;
		
		void cabDetails()
		{
			cout<<"We collaborated with fastest, safest, and smartest cab service"<<endl;
			cout<<"---------- SUBHA Cabs ----------\n"<<endl;
			cout<<"1. Rent a Standard Cab - Rs. 20 for 1 Km"<<endl;
			cout<<"2. Rent a Luxury Cab - Rs. 30 for 1 Km"<<endl;
			
			cout<<"\nTo Calculate the cost for your Journey: "<<endl;
			cout<<"Enter which kind of Cab you need:";
			cin>>cabChoice;
			cout<<"Enter Kilometers you have to travel:";
			cin>>Km;
			
			int hireCab;
			if (cabChoice==1)
			{
				cabCost=Km*20;
				cout<<"\n Your tour cost "<<cabCost<<" rupees for a Standard Cab"<<endl;
				cout<<"Press 1 to hire this cab: or";
				cout<<"Press 2 to select another cab: ";
				cin>>hireCab;
				
				system ("CLS"); // to clear the console
				
				if (hireCab==1)
				{
					lastcabCost= cabCost;
					cout<<"\nYou have successfully hired a Standard Cab"<<endl;	
					cout<<"Goto Menu and take the receipt"<<endl;
				}
				else if (hireCab==2)
				{
					cabDetails();
				}
				else
				{
					cout<<"invalid Input! Redirecting to previous menu \nplease wait!"<<endl;
					Sleep(999);
					system ("CLS"); // to clear the console
					cabDetails();
				}	
		    }
		    else if (cabChoice==2)
		    {
		    	cabCost=Km*30;
				cout<<"\n Your tour cost "<<cabCost<<" rupees for a Luxury Cab"<<endl;
				cout<<"Press 1 to hire this cab: or";
				cout<<"Press 2 to select another cab: ";
				cin>>hireCab;
				
				system ("CLS"); // to clear the console
				
				if (hireCab==1)
				{
					lastcabCost= cabCost;
					cout<<"\nYou successfully hired a Luxury Cab"<<endl;	
					cout<<"Goto Menu and take the receipt"<<endl;
				}
				else if (hireCab==2)
				{
					cabDetails();
				}
				else
				{
					cout<<"invalid Input! Redirecting to previous menu \nplease wait!"<<endl;
					Sleep(1100);
					system ("CLS"); // to clear the console
					cabDetails();
				}	
			}
			else
			{
				cout<<"invalid Input! Redirecting to Main menu \nplease wait!"<<endl;
				Sleep(1100);
				system ("CLS"); // to clear the console
				cabDetails();
				menu();
			}
			
			cout<<"\nPress 1 to Redirect Main Menu: "; // if anything above does not heppen this will print
			cin>>hireCab;
			system("CLS");
			if (hireCab==1)
			{
				menu();
			}
			else
			{
				menu();
			}
			
		}
};

float Cabs :: lastcabCost;

class Booking
{
	public:
		int choiceHotel;
		int packChoice;
		static float hotelCost; // i can use this variable out of this class using inheritence
		
		void hotels()
		{
			string hotelNo[]= {"Blueview", "Greenpark", "Elephantbay"};
			for (int a=0;a<3;a++)
			{
				cout<<(a+1)<<". Hotel "<<hotelNo[a]<<endl;
			}
			cout<<"\nCurrently we collaborated with above hotels!"<<endl;
			cout<<"Press any key to back or\nEnter number of hotel you want to book: ";
			cin>>choiceHotel;
			
			system("CLS");
			
			if (choiceHotel==1)
			{
				cout<<"------WELCOME TO HOTEL BLUEVIEW------\n"<<endl;
				cout<<"The Garden, food and beverage. Enjoy all you drink, stay cool and get chilled in the summer sun."<<endl;
				cout<<"Packages offered by Blueview:\n"<<endl;
				
				cout<<"1. Standard pack"<<endl;
				cout<<"\tAll basic facilities you need just for Rs. 5000.00"<<endl;
				
				cout<<"2. Premium pack"<<endl;
				cout<<"\tEnjoy premium: Rs. 10000.00"<<endl;
				
				cout<<"3. Luxury pack"<<endl;
				cout<<"\tLive a Luxury pack at Blueview: Rs. 15000.00"<<endl;
				
				cout<<"\nPress another key to back or\nEnter number you want to book: ";
				cin>>packChoice;
				
				if (packChoice==1)
				{
					hotelCost=5000.00;
					cout<<"\nYou have successfully book Standard pack at Blueview"<<endl;
					cout<<"Goto Menu and take the receipt"<<endl;
				}
				else if (packChoice==2)
				{
					hotelCost=10000.00;
					cout<<"\nYou have successfully book Premium pack at Blueview"<<endl;
					cout<<"Goto Menu and take the receipt"<<endl;
				}
				else if (packChoice==3)
				{
					hotelCost=15000.00;
					cout<<"\nYou have successfully book Luxury pack at Blueview"<<endl;
					cout<<"Goto Menu and take the receipt"<<endl;
				}
				else
				{
					cout<<"Invalid Input! Redirecting to Previous Menu \nPlease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					menu();
				}
				
				int gotomenu;
				cout<<"\nPress 1 to redirect main menu: ";
				cin>>gotomenu;
				if (gotomenu==1)
				{
					menu();
				}
				else
				{
					menu();
				}
			}
			else if (choiceHotel==2)
			{
				cout<<"------WELCOME TO HOTEL GREENPARK------\n"<<endl;
				cout<<"The Garden, food and beverage. Enjoy all you drink, stay cool and get chilled in the summer sun."<<endl;
				cout<<"Packages offered by Greenpark:\n"<<endl;
				
				cout<<"1. Standard pack"<<endl;
				cout<<"\tAll basic facilities you need just for Rs. 5500.00"<<endl;
				
				cout<<"2. Premium pack"<<endl;
				cout<<"\tEnjoy premium: Rs. 11000.00"<<endl;
				
				cout<<"3. Luxury pack"<<endl;
				cout<<"\tLive a Luxury pack at Blueview: Rs. 15500.00"<<endl;
				
				cout<<"\nPress another key to back or\nEnter number you want to book: ";
				cin>>packChoice;
				
				if (packChoice==1)
				{
					hotelCost=5500.00;
					cout<<"\nYou have successfully book Standard pack at Greenpark"<<endl;
					cout<<"Goto Menu and take the receipt"<<endl;
				}
				else if (packChoice==2)
				{
					hotelCost=11000.00;
					cout<<"\nYou have successfully book Premium pack at Greenpark"<<endl;
					cout<<"Goto Menu and take the receipt"<<endl;
				}
				else if (packChoice==3)
				{
					hotelCost=15500.00;
					cout<<"\nYou have successfully book Luxury pack at Greenpark"<<endl;
					cout<<"Goto Menu and take the receipt"<<endl;
				}
				else
				{
					cout<<"Invalid Input! Redirecting to Previous Menu \nPlease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					menu();
				}
				
				int gotomenu;
				cout<<"\nPress 1 to redirect main menu: ";
				cin>>gotomenu;
				if (gotomenu==1)
				{
					menu();
				}
				else
				{
					menu();
				}
			}
			else if (choiceHotel==3)
			{
				cout<<"------WELCOME TO HOTEL ELEPHANTBAY------\n"<<endl;
				cout<<"The Garden, food and beverage. Enjoy all you drink, stay cool and get chilled in the summer sun."<<endl;
				cout<<"Packages offered by Elephantbay:\n"<<endl;
				
				cout<<"1. Standard pack"<<endl;
				cout<<"\tAll basic facilities you need just for Rs. 6000.00"<<endl;
				
				cout<<"2. Premium pack"<<endl;
				cout<<"\tEnjoy premium: Rs. 12000.00"<<endl;
				
				cout<<"3. Luxury pack"<<endl;
				cout<<"\tLive a Luxury pack at Elephantbay: Rs. 16000.00"<<endl;
				
				cout<<"\nPress another key to back or\nEnter number you want to book: ";
				cin>>packChoice;
				
				if (packChoice==1)
				{
					hotelCost=6000.00;
					cout<<"\nYou have successfully book Standard pack at Elephantbay"<<endl;
					cout<<"Goto Menu and take the receipt"<<endl;
				}
				else if (packChoice==2)
				{
					hotelCost=12000.00;
					cout<<"\nYou have successfully book Premium pack at Elephantbay"<<endl;
					cout<<"Goto Menu and take the receipt"<<endl;
				}
				else if (packChoice==3)
				{
					hotelCost=16000.00;
					cout<<"\nYou have successfully book Luxury pack at Elephantbay"<<endl;
					cout<<"Goto Menu and take the receipt"<<endl;
				}
				else
				{
					cout<<"Invalid Input! Redirecting to Previous Menu \nPlease wait!"<<endl;
					Sleep(1100);
					system("CLS");
					menu();
				}
				
				int gotomenu;
				cout<<"\nPress 1 to redirect main menu: ";
				cin>>gotomenu;
				if (gotomenu==1)
				{
					menu();
				}
				else
				{
					menu();
				}
			}			 			
		}
};

float Booking :: hotelCost;


class Charges : public Booking, Cabs, Customers // we use multi-level inheritance
{
	public:
		void printBill()
		{
			ofstream outf("receipt.txt");
			{
			    outf << "--------SUBHA Travel Agency--------" << endl;
	            outf << "-------------Receipt-------------" << endl;
	            outf << "_________________________________" << endl;
	
	            outf << "Customer ID: " << Customers::cus_ID << endl << endl;
	            outf << "Description\t\t Total" << endl;
	            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
	            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastcabCost << endl;
	
	            outf << "_________________________________" << endl;
	            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost+Cabs::lastcabCost << endl;
	            outf << "_________________________________" << endl;
	            outf << "------------THANK YOU------------" << endl;
            }
            outf.close();//cout << "Your receipt printed, please get it from the file saved path:D" << endl;
       }
       
       void showbill()
       {
       	    ifstream inf("receipt.txt");
       	    {
       	    	if (!inf)
       	    	{
       	    		cout<<"File Opening error!"<<endl;
			    } 
			    while (!(inf.eof()))
			    {
			    	inf.getline(all, 999);
			    	cout<<all<<endl;			    	
				}
       		}
       		inf.close();       	   
	   }
	
};

void menu()
{
	int mainChoice;
	int inChoice;
	int gotoMenu;
	
    cout << "\t\t      * SUBHA Travels *\n" << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBookings Management -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;
    
    cout<<"\nEnter your choice: ";
    cin>>mainChoice;
    
    system("CLS");
    
    Customers a2; // creating objects
    Customers a8;
	Cabs a3;
    Booking a4;
    Charges a5;
    
    if(mainChoice == 1)
	{
        cout << "------Customers------\n" << endl;
        cout << "1. Enter New Customer"<< endl;
        cout << "2. See Old Customers"<< endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;
        
        if(inChoice == 1)
		{
            a2.getDetails();
        }
        else if(inChoice == 2)
		{
            a2.showDetails();
        }
        else
		{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1)
		{
            menu();
        }
        else
		{
            menu();
        }
    }
    else if(mainChoice == 2)
	{
        a3.cabDetails();
    }
    else if(mainChoice == 3)
	{
        cout << "--> Book a Luxury Hotel using the System <--\n" << endl;
        a4.hotels();
    }
    else if(mainChoice == 4)
	{
        cout << "-->Get your receipt<--\n" << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n" << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;
        if(gotoMenu == 1)
		{
            system("CLS");
            a5.showbill();
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
			{
                menu();
            }
            else
			{
                menu();
            }
        }
        else
		{
            system("CLS");
            menu();
        }
    }
    else if(mainChoice == 5)
	{
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else
	{
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }

    

}

int main()
{
	ManageMenu startObj;
	return 0;
}
