#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int Bus_counter = 0;
int c = 0;
int ticket_counter = 0;
int sml = 1;
char ch = sml;
int mx_buses = 0;
int mx_persons = 0;
int mx_users = 0;
int mx_tickets = 0;
int Mx_Tickets = 0;

string destinations[] = { "From:Cairo..to:SharmelSheikh", "From:Cairo..to:Hurghada", "From:Cairo..to:Alexandria", "From:Cairo..to:MarsaMatrouh", "From:Cairo..to:North_Coast", "From:Cairo..to:Dahab", "From:Cairo..to:Fayoum" };
struct buses
{
	int BusNumber;
	int No_Of_Seats;
	//int Available_No_Of_Seats;
	int No_Of_Trips;
	string destinations;
	//string TripsTime1[3];


}temp[35];

struct Tripstime
{
	string time1;
	string time2;
	string time3;

	int available_number_of_seats[3];
}triptime[50];

struct persons
{
	string name;
	string PhoneNumber;
	string Email;
	int No_Of_Buses_They_Booked;
	int No_Of_Seats_They_Chose;

}Users[50];


struct Tickets
{
	int ID;
	string Bus_Take_Of_Time;
	string Date_Of_Travelling;
	int BusNumber;
	char BusClass;
	string destination;
	string Price;
}ticket[50];

struct drivers
{
	int ID;
	double rate;

}driver[10];


void file_in();
void file_out();
void menu();
void login();
void admin();
void DISPLAYtickets();
void DISPLAYusers();
void adduser();
void AddTicket();
void addnewbus();
void open();
void display();
void Show_Available_buses();
void Bus_Schedule();
void ShowPrices();
void PaymentMethods();
void BookTickets();
void ShowTicketsInfo();
void Bus_Classes();
void driver_info();
void UsersInformation();
void CancelReservatin();



int main()
{
	file_in();
	open();
	file_out();
}
void menu()
{
	system("cls");

	int c;

	cout << "\t\t-----------------------------------------------------\n\n\n";
	cout << "\t\t                Welcome to the home page            \n\n\n";
	cout << "\t\t------------   Bus Reservation System   -------------\n\n\n";
	cout << "                                                               \n\n";
	cout << "| Press 1 to login as * ADMIN *                  |" << endl << endl;
	cout << "| Press 2 to login as * USER *                   |" << endl << endl;
	cout << "| Press 0 to * EXIT *                            |" << endl;
	cout << "\n\n\n\t\t  Enter Your Choice : ";
	cin >> c;
	cout << endl;

	switch (c)
	{
	case 1:
		system("cls");
		login();
		break;
	case 2:
		open();
		break;
	case 0:
		cout << "\t\t\t Thank you! \n\n";
		break;

	default:
		system("cls");
		cout << "\t\t\t INVALID SELECTION! PLEASE TRY AGAIN \n\n";
	}
}
void login()
{


	string username;
	string password;
	bool flag = false;

	cout << "\t\t-----------------------------------------------------\n\n\n";
	cout << "\t\t                                                      \n\n\n";
	cout << "\t\t--------------------   Login Page   -----------------\n\n\n";
	cout << "                                                               \n\n";
	cout << " Please enter username ----> "; cin >> username;
	cout << "\n Please enter Password ----> "; cin >> password;
	cout << " Press 0 to exit                            " << endl;



	if ((username == "admin") && (password == "1234"))
	{

		flag = true;

	}



	switch (flag)
	{
	case true:
		system("cls");
		admin();
		break;
	case false:
		system("cls");
		cout << "INVALID USERNAME OR PASSWORD " << endl;
		login();
		break;
	}


}
void admin()
{
	system("cls");
	cout << "\t\t-----------------------------------------------------\n\n\n";
	cout << "\t\t               Welcome to the ADMIN page            \n\n\n";
	cout << "\t\t-----------------------   MENU   --------------------\n\n\n";
	cout << "                                                               \n\n";
	cout << "\t| 1)                    Add Bus                       |" << endl;
	cout << "\t| 2)                    Add User                      |" << endl;
	cout << "\t| 3)                    Add ticket                    |" << endl;
	cout << "\t| 4)                    Show tickets                  |" << endl;
	cout << "\t| 5)                    Show Users                    |" << endl;
	cout << "\t| 0)                    Exit                          |" << endl;

	cout << "\n\t\t\t Please Enter Your Choice : ";
	cin >> c;
	cout << endl;


	switch (c)
	{
	case 1:
		addnewbus();
		break;
	case 2:
		adduser();
		break;
	case 3:
		AddTicket();
		break;
	case 4:
		DISPLAYtickets();
		break;
	case 5:
		DISPLAYusers();
		break;
	case 0:
		cout << "\t\t\t Thank you! \n\n";
		break;

	default:
		system("cls");
		cout << "\t\t\t INVALID SELECTION! PLEASE TRY AGAIN \n\n";
		admin();
	}



	

	
}
void DISPLAYtickets()
{
	system("cls");
	for (int i = 0; i < ticket_counter; i++)
	{
		cout << "  ticket ID : " << ticket[i].ID<<"\t\t";
		cout << ", ticket take of time : " << ticket[i].Bus_Take_Of_Time<<"\n";
		cout << ", ticket date : " << ticket[i].Date_Of_Travelling<<"\t\t";
		cout << ", ticket bus num : " << ticket[i].BusNumber << "\n";
		cout << ", ticket class : " << ticket[i].BusClass << "\t\t";
		cout << ", ticket destination : " << ticket[i].destination << "\n";
		cout << ", ticket price : " << ticket[i].Price <<"\n\n";
		cout << "\n----------------------------------------------------------------\n\n";
	}
}


void DISPLAYusers()
{
	system("cls");
	for (int i = 0; i < c; i++)
	{
		cout << "user's name: " << Users[i].name;
		cout << ", user's phone NO*: " << Users[i].PhoneNumber;
		cout << ", user's Email" << Users[i].Email;
		cout << ", user's No*of buss booked: " << Users[i].No_Of_Buses_They_Booked;
		cout << ", user's No*of seats: " << Users[i].No_Of_Seats_They_Chose << endl;
		cout << "—————————————————————————————————————————————————————" << endl;
	}
	system("pasue");
}
void adduser()
{
	system("cls");
	int users;
	cout << "Enter the number of users that you want to add\n\n";
	cin >> users;
	for (int i = 0; i < users; i++)
	{
		cout << "Enter name: ";
		cin >> Users[c].name; 
		cout << "Enter phone number: ";
		cin >> Users[c].PhoneNumber;
		cout << "Enter email: ";
		cin >> Users[c].Email; 
		cout << "Enter the number of buses he/she booked: ";
		cin >> Users[c].No_Of_Buses_They_Booked;
		cout << "Enter the number of tickets he/she choosed: ";
		cin >> Users[c].No_Of_Seats_They_Chose;

		c++;
	}
}
void AddTicket()
{
	system("cls");
	int tickets;
	cout << "Enter the number of tickets that you want to add\n\n";
	cin >> tickets;
	for (int i = 0; i < tickets; i++)
	{
		cout << "Enter ID : ";
		cin >> ticket[i].ID; cout << "\n";
		cout << "Enter Bus take of time : ";
		cin >> ticket[i].Bus_Take_Of_Time;
		cout << "Enter Date of travelling : ";
		cin >> ticket[i].Date_Of_Travelling;
		cout << "Enter Bus number : ";
		cin >> ticket[i].BusNumber;
		cout << "Enter destination : ";
		cin >> ticket[i].destination;
		cout << "Enter Price : ";
		cin >> ticket[i].Price;
		ticket_counter++;
	}
}
void addnewbus()
{
	char newbus='n';
	system("cls");
	do
	{
		cout << "\n Enter bus number : ";
		cin >> temp[Bus_counter].BusNumber;
		cout << " Enter number of seats : ";
		cin >> temp[Bus_counter].No_Of_Seats;
		cout << " Enter the number of trips : ";
		cin >> temp[Bus_counter].No_Of_Trips;
		cout << "Enter Destination : ";
		cin >> temp[Bus_counter].destinations;
		cout << " Enter trip time1 : ";
		cin >> triptime[Bus_counter].time1;
		cout << " Enter trip time2 : ";
		cin >> triptime[Bus_counter].time2;
		cout << " Enter trip time3 : ";
		cin >> triptime[Bus_counter].time3;

		Bus_counter++;
		cout << "do you want to add another bus ? (y\n)";
		cin >> newbus;
	} while (newbus == 'y' || newbus == 'Y');
}


void display()
{
	cout << "\t\t***************************************** \n \n";
	cout << "\t\t| Welcome  to Bus Reservation System     |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t-----------------------------------------\n\n\n";

	cout << "  1. Show Available buses \t  6. Show Tickets Info  \n\n ";
	cout << " 2. Bus Schedule           \t  7. Bus Classes \n\n ";
	cout << " 3. Show Prices           \t  8. User informaion   \n\n ";
	cout << " 4. Payment Options          \t  9. Cancel Reservation   \n\n ";
	cout << " 5. Book Tickets       \t 10. Admin options ( for admins only ) \n\n ";
	cout << "11. Exit \n\n";
}

void Show_Available_buses()
{
	system("cls");
	cout << "****************************************************************************** \n";
	cout << "Bus numbers | Number of seats | Number of trips | Destination \n------------------------------------------------------------------------------\n\n";
	for (int i = 0; i < Bus_counter; i++)
	{
		cout <<' '<< temp[i].BusNumber << "\t\t" << temp[i].No_Of_Seats << "\t\t" << temp[i].No_Of_Trips << "\t\t"<< temp[i].destinations<<"\n\n";
	}
	cout << "-------------------------------------------------------------------------------\n";
}
void Bus_Schedule()
{
	system("Cls");
	cout << "****************************************************************************** \n";
	cout << "Bus number\t | trip time1 \t\t | trip time2  \t | trip time3  \n------------------------------------------------------------------------------\n\n";

	for (int i = 0; i < Bus_counter; i++)
	{
		cout << temp[i].BusNumber << " --> "<<"\t" << triptime[i].time1 << "\t" << triptime[i].time2 << "\t" << triptime[i].time3 << "\n\n";
	}
	
}
void PaymentMethods()
{
	system("cls");
	int choice;
	cout << " \t\t\t\t\tPayment Methods " << endl;
	cout << "1. By Visa" << endl;
	cout << "2. Cash" << endl;
	cout << "3. Vodafone cash" << endl;
	cout << "4. Etisalat cash" << endl;
	cout << "5. Paypal" << endl << endl;
	cout << "6. Exit" << endl;


	bool done = false; //for ask user completing
	do {
		cout << "Enter your choice :  " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:

			break;
		case 2:

			break;

		case 3:

			break;

		case 4:

			break;
		case 5:
			break;
		case 6:
			open();
			break;


		default:
			cout << "invalid option :) please try again ....... \n";
			done = true;
			continue;

		}
	} while (done);



}


void open()
{
	int choice;
	char Continue;

	do {
		system("cls");
		display();

		bool boo;
		string c;
		do
		{
			boo = true;
			cout << "\n\nEnter your choice : ";
			cin >> c;

			for (int i = 0; i< c.length(); i++)
			{
				if (!isdigit(c[i]))
				{
					boo = false;
					cout << "Wrong input " << endl;
					break;
				}
			}
		} while (!boo);
		choice = stoi(c);




		if (choice >= 10 && choice < 1)
		{
			cout << "\t invalid option :) please try again ......." << endl;
			system("cls");
		}

		switch (choice)
		{
		case 1:
			Show_Available_buses();
			break;
		case 2:
			Bus_Schedule();
			break;
		case 3:
			ShowPrices();
			break;
		case 4:
			PaymentMethods();
			break;
		case 5:
			BookTickets();
			break;
		case 6:
			ShowTicketsInfo();
			break;
		case 7:
			Bus_Classes();
			break;
		case 8:
			UsersInformation();
			break;
		case 9:
			CancelReservatin();
			break;
		case 10:
			menu();
			break;
		case 11:
			break;

		default:
			cout << "\t invalid option " << ch << " please try again ......." << endl;
			Continue = 'y';

			continue;
		}
		cout << "   you want do another(n/y)?  :";

		cin >> Continue;

	} while (Continue == 'y');

}

void ShowPrices()
{
	system("cls");
	cout << "1.From Cairo to Sharm el_Sheikh\t Class A --> 400L.E    Class B --> 300L.E\n\n";
	cout << "2.From Cairo to Hurghada       \t Class A --> 350L.E    Class B --> 280L.E \n\n";
	cout << "3.From Cairo to Alexandria     \t Class A --> 200L.E    Class B --> 150L.E \n\n";
	cout << "4.From Cairo to Marsa Matrouh  \t Class A --> 300L.E    Class B --> 250L.E \n\n";
	cout << "5.From Cairo to North_Coast    \t Class A --> 450L.E    Class B --> 400L.E \n\n";
	cout << "6.From Cairo to Dahab          \t Class A --> 500L.E    Class B --> 400L.E \n\n";
	cout << "7.From Cairo to Fayoum         \t Class A --> 200L.E    Class B --> 180L.E \n\n";

}
void BookTickets()
{
	int Bus_Number, trriptime, Destination, No_Of_Tickets;
	char Class;
	string date;
	char again;

	do {
		cout << "choosing Bus: \n\n";
		Show_Available_buses();
		cout << "Enter bus number : ";
		cin >> Bus_Number;
		system("cls");
		Bus_Schedule();
		cout << "Enter number (from 1 to 3) to choose trip time : ";
		cin >> trriptime;
		cout << "Please enter the number of tickets you want to book: ";
		cin >> No_Of_Tickets;
		triptime[Bus_Number - 1].available_number_of_seats[trriptime - 1] -= No_Of_Tickets;
		cout << "Enter the data of travelling (d/m/y): ";
		cin >> date;
		ShowPrices();
		cout << "\n\n";
		cout << "Enter number to choose destination : ";
		cin >> Destination;
		cout << "Class A Or B ? ";
		cin >> Class;
		system("cls");
		cout << "\t\t ** User informtaion **** \n\n";
		cout << "Please Enter your name: ";
		cin >> Users[c].name;
		cout << "Enter phone number: ";
		cin >> Users[c].PhoneNumber;
		cout << "Enter your Email address: ";
		cin >> Users[c].Email;
		cout << "\n\n";
		Users[c].No_Of_Buses_They_Booked = 0;
		Users[c].No_Of_Seats_They_Chose = 0;
		Users[c].No_Of_Seats_They_Chose += No_Of_Tickets;
		Users[c].No_Of_Buses_They_Booked += 1;
		cout << "Booking succeded \n\n";
		cout << "\t\t***************************************** \n \n";
		cout << "\t\t| Thank you for choosing our services" << ch << "\t|\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t-----------------------------------------\n\n\n";

		if (No_Of_Tickets == 1)
			cout << "Your seat number is: \n\n";

		else if (No_Of_Tickets > 1)
			cout << "Your seats numbers are: \n\n";
		for (int T = 0; T < No_Of_Tickets; T++)
		{
			ticket[ticket_counter].ID = triptime[Bus_Number - 1].available_number_of_seats[trriptime-1] + T + 1;
			if (trriptime == 1)
			{
				ticket[ticket_counter].Bus_Take_Of_Time = triptime[Bus_Number - 1].time1;
			}
		else if (trriptime == 2)
			{
				ticket[ticket_counter].Bus_Take_Of_Time = triptime[Bus_Number - 1].time2;
			}
		else if (trriptime == 3)
		{
			ticket[ticket_counter].Bus_Take_Of_Time = triptime[Bus_Number - 1].time3;
		}
			ticket[ticket_counter].Date_Of_Travelling = date;
			ticket[ticket_counter].BusNumber = Bus_Number;
			ticket[ticket_counter].BusClass = Class;
			ticket[ticket_counter].destination = destinations[Destination - 1];
			if (Destination == 1 && Class == 'A')
				ticket[ticket_counter].Price = "400L.E";
			else if (Destination == 1 && Class == 'B')
				ticket[ticket_counter].Price = "300L.E";
			else if (Destination == 2 && Class == 'A')
				ticket[ticket_counter].Price = "350L.E";
			else if (Destination == 2 && Class == 'B')
				ticket[ticket_counter].Price = "200L.E";
			else if (Destination == 3 && Class == 'A')
				ticket[ticket_counter].Price = "200L.E";
			else if (Destination == 3 && Class == 'B')
				ticket[ticket_counter].Price = "150L.E";
			else if (Destination == 4 && Class == 'A')
				ticket[ticket_counter].Price = "300L.E";
			else if (Destination == 4 && Class == 'B')
				ticket[ticket_counter].Price = "250L.E";
			else if (Destination == 5 && Class == 'A')
				ticket[ticket_counter].Price = "450L.E";
			else if (Destination == 5 && Class == 'B')
				ticket[ticket_counter].Price = "400L.E";
			else if (Destination == 6 && Class == 'A')
				ticket[ticket_counter].Price = "500L.E";
			else if (Destination == 6 && Class == 'B')
				ticket[ticket_counter].Price = "400L.E";
			else if (Destination == 7 && Class == 'A')
				ticket[ticket_counter].Price = "200L.E";
			else if (Destination == 7 && Class == 'B')
				ticket[ticket_counter].Price = "180L.E";
			cout << ticket[ticket_counter].ID << "\n\n";

			ticket_counter++;
		}

		//mx_tickets = T;
		c++;
		cout << "Do you want to book again ? (y/n) ";
		cin >> again;
		cout << "\n";
	} while (again == 'y' || again == 'Y');

}
void ShowTicketsInfo()
{
	system("cls");
	bool foundd = false;
	int bussnumber;
	int seattnumber;
	do
	{
		cout << "\t\t*******************************************\n";
		cout << "\t\t|\tTicket infromations\t          |\n";
		cout << "\t\t|_________________________________________|\n\n";



		cout << "Enter bus number: ";
		cin >> bussnumber;
		cout << "Enter seat number: ";
		cin >> seattnumber;
		int i, founded_t;
		for (i = 0; i < Mx_Tickets; i++)
		{
			if (ticket[i].BusNumber == bussnumber && ticket[i].ID == seattnumber)
			{
				foundd = true;
				founded_t = i;
				break;
			}
		}
		if (foundd)
		{
			cout << "\n\n***********************************************\n\n";
			cout << "ID: " << ticket[founded_t].ID << "\t\t" << "Bus Take of time: " << ticket[founded_t].Bus_Take_Of_Time << "\n\n" << "Date of travelling: " << ticket[founded_t].Date_Of_Travelling << "\t\t" << "Bus number: " << ticket[founded_t].BusNumber << "\t\t" << "Bus class: " << ticket[founded_t].BusClass << "\n\n" << "Your destination: " << ticket[founded_t].destination << "\t\t" << "Price: " << ticket[founded_t].Price << "\n\n";
			cout << "\n\n***********************************************\n\n";
		}
		else
			cout << "Invalid date try again..........\n\n";

	} while (foundd == false);

}

void Bus_Classes()
{
	system("cls");
	char ch, more, info_driver;
	cout << "We have 2 classes ( A , B ) \n";

	do {
		cout << " Please enter the class you want information about : ";
		cin >> ch;
		switch (ch)
		{
		case 'a':
		case 'A':
			cout << " A class : \n" << "1. air conditioner \n" << "2. one trip ( Less time to reach )\n" << "3. The latest vehicle releases\n"
				<< "4. super comfortable\n" << "5. High technology \n" << "6. best drivers --> ";
			cout << "do you want information about drivers ( y , n ) : ";
			cin >> info_driver;
			if (info_driver == 'y' || info_driver == 'Y')
			{
				driver_info();
			}
			break;
		case 'b':
		case 'B':
			cout << " B class : \n" << " 1. cheap \n" << " 2. many stations \n" << " 3. Equipped for long trips \n";
			break;
		}
		cout << " do you want another class \n (y , n ) ? : ";
		cin >> more;
	} while (more == 'y' || more == 'Y');

}

void driver_info()
{
	drivers driver[9];
	driver[0].ID = 202010;
	driver[1].ID = 202011;
	driver[2].ID = 202012;
	driver[3].ID = 202013;
	driver[4].ID = 202014;
	driver[5].ID = 202015;
	driver[6].ID = 202016;
	driver[7].ID = 202017;
	driver[8].ID = 202018;

	driver[0].rate = 5;
	driver[1].rate = 5;
	driver[2].rate = 4.9;
	driver[3].rate = 4.9;
	driver[4].rate = 4.9;
	driver[5].rate = 4.7;
	driver[6].rate = 4.6;
	driver[7].rate = 4.5;
	driver[8].rate = 4.5;

	for (int i = 0; i < 9; i++)
	{
		cout << "driver " << i + 1 << " ->  ID : " << driver[i].ID
			<< "  rate : " << driver[i].rate << endl;
	}
}





void UsersInformation()
{
	string name, phnenumber;
	bool right = false;
	do
	{

		cout << "\n\nEnter your name: ";
		cin >> name;
		cout << "Enter your phone number: ";
		cin >> phnenumber;
		cout << "\n\n";
		for (int i = 0; i < c; i++)
		{
			if (Users[i].name == name && Users[i].PhoneNumber == phnenumber)
			{
				cout << "Name : " << Users[i].name << "\t" << "Phone number : " << Users[i].PhoneNumber << "\t" << "Email address : " << Users[i].Email << "\n\n" << "No*Of Buses he/she booked: " << Users[i].No_Of_Buses_They_Booked << "\t" << "No*Of Seats he/she choose: " << Users[i].No_Of_Seats_They_Chose << "\n";
				right = true;
			}	
		}
		if (right == false)
			cout << "Invalid data try again......\n\n";
	}while(right == false);

}
void CancelReservatin()
{
	system("cls");
	int buSNumber, Seattnumber,trip_number;
	string namme, phonee;
	int i, j, m;

	bool found1 = false;
	bool found2 = false;
	bool found3 = false;

	Show_Available_buses();
	cout << "Enter bus number that you want to cancel it's reseravtion: ";
	cin >> buSNumber;
	cout << "trip 1 or 2 or 3 ? : ";
	cin >> trip_number;
	//cout << "Enter the number of tickets you want to cancel: ";
	//cin >> NoOfTickets;
	cout << "Enter seat number: ";
	cin >> Seattnumber;
	cout << "Enter your name: ";
	cin >> namme;
	cout << "Enter your phone number: ";
	cin >> phonee;

	do{
		for (i = 0; i < ticket_counter; i++)
		{
			if (buSNumber == ticket[i].BusNumber && ticket[i].ID == Seattnumber)
			{
				found1 = true;
				break;
			}
		}

		for (j = 0; j < c; j++)
		{

			if (namme == Users[j].name  && Users[j].PhoneNumber == phonee)
			{
				found2 = true;
				break;
			}
		}

		for (m = 0; m < mx_buses; m++)
		{
			if (temp[m].BusNumber == buSNumber)
			{
				found3 = true;
				break;
			}
		}
		if (found1 == true && found2 == true && found3 == true)
		{
			ticket[i].ID = 0;
			Users[j].No_Of_Seats_They_Chose -= 1;

			if (Users[j].No_Of_Seats_They_Chose == 0)
				Users[j].No_Of_Buses_They_Booked = 0;

		    triptime[m].available_number_of_seats[trip_number-1] += 1;
			ticket_counter -= 1;

			cout << "\n\t\tReservation has been canceled successfully.......... \n\n";
		}

		else
		{
			cout << "\n\n\t\tInvalid data please try again..........\n\n";
			bool found1 = false;
			bool found2 = false;
			bool found3 = false;

			Show_Available_buses();
			cout << "Enter bus number that you want to cancel it's reseravtion: ";
			cin >> buSNumber;
			//cout << "Enter the number of tickets you want to cancel: ";
			//cin >> NoOfTickets;
			cout << "Enter seat number: ";
			cin >> Seattnumber;
			cout << "Enter your name: ";
			cin >> namme;
			cout << "Enter your phone number: ";
			cin >> phonee;


		}


	} while (found1 == false && found2 == false && found3 == false);
}

void file_in()
{
	
	ifstream B_C("Buses_Counter.txt");
	B_C >> Bus_counter;
	B_C.close();
	
	ifstream u("Users_Counter.txt");
	u >> c;
	u.close();

	ifstream ticket_c("Ticket_Counter.txt");
	ticket_c >> ticket_counter;
	ticket_c.close();

	ifstream another_file("Buses.txt");
	int i = 0;
	while (another_file.good())
	{
		another_file >> temp[i].BusNumber >> temp[i].No_Of_Seats >> temp[i].No_Of_Trips >> temp[i].destinations;
		i++;
	}
	mx_buses = i;
	another_file.close();

	ifstream trips_time("Trips Time.txt");
	int s = 0;
	while (trips_time.good())
	{
		trips_time >> triptime[s].time1 >> triptime[s].time2 >> triptime[s].time3;
		for (int t = 0; t < 3; t++)
		{
			trips_time >> triptime[s].available_number_of_seats[t];
		}
		s++;
	}
	trips_time.close();
	ifstream persons_file("Persons.txt");
	int j = 0;
	while (persons_file.good())
	{
		persons_file >> Users[j].name >> Users[j].PhoneNumber >> Users[j].Email >> Users[j].No_Of_Buses_They_Booked >> Users[j].No_Of_Seats_They_Chose;
		j++;
	}
	mx_persons = j;
	persons_file.close();

	ifstream Tickets_file("Tickets.txt");
	int h = 0;
	while (Tickets_file.good())
	{
		Tickets_file >> ticket[h].ID >> ticket[h].Bus_Take_Of_Time >> ticket[h].Date_Of_Travelling >> ticket[h].BusNumber >> ticket[h].BusClass >> ticket[h].destination >> ticket[h].Price;
		h++;
	}
	Mx_Tickets = h;
	Tickets_file.close();
}

void file_out()
{

	ofstream B_C("Buses_Counter.txt");
	B_C << Bus_counter;
	B_C.close();

	ofstream  u("Users_Counter.txt");
	u << c;
	u.close();

	ofstream ticket_c("Ticket_Counter.txt");
	ticket_c << ticket_counter;
	ticket_c.close();


	ofstream another_file("Buses.txt");
	if (another_file.is_open())
	{
		for (int i = 0; i < mx_buses; i++)
		{
			another_file << temp[i].BusNumber << ' ' << temp[i].No_Of_Seats << ' ' << temp[i].No_Of_Trips << ' ' << temp[i].destinations << "\n";
		}
	}
	another_file.close();

	ofstream trips_time("Trips Time.txt");
	if (trips_time.is_open())
	{
		for (int s = 0; s < Bus_counter; s++)
		{
			trips_time << triptime[s].time1 << ' ' << triptime[s].time2 << ' ' << triptime[s].time3 << ' ';
			for (int t = 0; t < 3; t++)
				trips_time << triptime[s].available_number_of_seats[t] << ' ';

			trips_time << "\n";

		}
	}
	trips_time.close();
	ofstream Persons_file("Persons.txt");

	{
		for (int j = 0; j < c; j++)
		{
			Persons_file << Users[j].name << ' ' << Users[j].PhoneNumber << ' ' << Users[j].Email << ' ' << Users[j].No_Of_Buses_They_Booked << ' ' << Users[j].No_Of_Seats_They_Chose << "\n";
		}
	}
	Persons_file.close();


	ofstream Tickets_file("Tickets.txt");
	{
		for (int h = 0; h < ticket_counter + 1 ; h++)
		{
			if (ticket[h].ID == 0)
				continue;

			Tickets_file << ticket[h].ID << ' ' << ticket[h].Bus_Take_Of_Time << ' ' << ticket[h].Date_Of_Travelling << ' ' << ticket[h].BusNumber << ' ' << ticket[h].BusClass << ' ' << ticket[h].destination << ' ' << ticket[h].Price << "\n";
		}
	}

	Tickets_file.close();


}


