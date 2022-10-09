#include"allfileHeader.h"

void Menu()
{
	char choice1, choice2, choice3;
	Admin Ad;
	manager Mg;
	Accountant Ac;
	bool condi = false;
	while (true)
	{
		system("color a1");
		cout << "Press 'A' To Login As An Admin.\nPress 'M' To Login As A Manager.\nPress 'C' To Login As An Accountant.\nPress 'E' To Exit.\n==> ";
		cin >> choice1;
		system("cls");
		choice1 = toupper(choice1);
		switch (choice1)
		{
		case 'A':
		{
			system("color b5");
			condi = Ad.Login();
			if (condi == true)
			{
				system("cls");
				cout << "\n\t\tLOGGED IN AS AN ADMIN\n\n\n";
				while (true)
				{
					cout << "Press '1' To Review Stats.\nPress '2' To Change Passwords.\nPress '3' To Exit To Main Menu.\n==> ";
					cin >> choice3;
					if(choice3 == '1')
					{
						Ad.Review();
						cout << endl << endl;
						cout << "\t\tPress 'Q' If You Have Any Query In Above Details.Else Press Any Other Key To Exit To Main Menu.\n==> ";
						cin >> choice2;
						choice2 = toupper(choice2);
						if (choice2 == 'Q')
						{
							system("cls");
							Ad.Respond();
						}
					}
					else if (choice3 == '2')
					{
						Ad.ChangePAss();
					}
					else if (choice3 == '3')
					{
						break;
					}
					else
					{
						cout << "WRONG CHOICE." << endl;
					}
				}
			}
			else
			{
				endl(2); tab(7);
				cout << "INVALID ACCOUNT CREDENTIAL";
			}
			break;
		}
		case 'M':
		{
			system("color 20");
			condi = Mg.Login();
			if (condi == true)
			{
				system("cls");
				cout << "\n\t\tLOGGED IN AS AN MANAGER\n\n\n";
				while (true)
				{
					cout << "Press '1' To Add New Student.\nPress '2' To Display Students Enrolled Today.\nPress '3' To Display All Students Record.\nPress '4' To Delete Any Student Data.\nPress '5' To Exit To Main Menu.\n==> ";
					cin >> choice2;
					cout << endl << endl;
					system("pause");
					system("cls");
					if (choice2 == '1')
					{
						Mg.AddStudent();
					}
					else if (choice2 == '2')
					{
						Mg.DisplayCurrent();
					}
					else if (choice2 == '3')
					{
						Mg.DisplayAll();
					}
					else if (choice2 == '4')
					{
						Mg.DisplayAll();
						cout << "\n\nSELECT STUDENT FROM ABOVE LIST.\n\n";
						Mg.DeleteStudent();
					}
					else if (choice2 == '5')
					{
						break;
					}
					else
					{
						cout << "WRONG OPTION.";
					}
					cout << endl << endl;
					system("pause");
					system("cls");
				}
			}
			else
			{
				endl(2); tab(7);
				cout << "INVALID ACCOUNT CREDENTIAL";
			}
			break;
		}
		case 'C':
		{
			system("color 20");
			char choice;
			condi = Ac.Login();
			if (condi == true)
			{
				system("cls");
				cout << "\n\t\tLOGGED IN AS AN Accountant\n\n\n";
				while (true)
				{
					system("cls");
					cout << "Press '1' To See The List Of Students And Their Fee Status" << endl;
					cout << "Press '2' To Pay Fee of the student." << endl;
					cout << "Press '3' To exit To Main Menu.\n-->> ";
					cin >> choice;
					if (choice == '1')
					{
						Ac.FeeStudents();
					}
					else if (choice == '2')
					{
						Ac.PayFee();
					}
					else if (choice == '3')
					{
						break;
					}
					else
					{
						cout << "Wrong Choice Entered." << endl;
					}
					system("pause");
				}
			}
			else
			{
				endl(2); tab(7);
				cout << "INVALID ACCOUNT CREDENTIAL";
			}
			break;
		}
		case 'E':
		{
			system("cls");
			system("color a4");
			cout << "Thanks For Using The Program." << endl << endl;
			system("pause");
			exit(0);
		}
		default:
		{
			cout << "Wrong Choice.Try Again.";
		}
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	}
}


int main()
{
	Menu();
	_getch();
	return 0;
}