#include <iostream>

#include <conio.h>

#include <windows.h>

#include <vector>

#include <fstream>

#include <ctime>

using namespace std;

	char choice;
	
	int points;
	
	int error;
	
	long words; // for a complete string
	
	long letters; // for individual characters
	
	double accuracy;
	
	double elapsed_time;
	
	string name;

class Value {
	protected:
		
// if the user wants to practice on more than one lesson at a time, errors points and accuracy needs to be restored
		
		void initialize_toZero() {
		
		error = 0;
		accuracy = 0;
		points = 0;
		
	}
};	

class tutor : public Value {
	
	public:

		//for changing font colour
		
	void colour(int x) {
	
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
  
}

		void lessons(){
			
			char ch;

			
			system( "cls" );
			
			colour(12);
			
			cout << "\n\n\t\t\t____________________";
			cout << "\n\n\t\t\tSELECT THE FOLLOWING";
			cout << "\n\n\t\t\t____________________";
			colour(9);
			cout << "\n\n\n\t\t->PRESS 1: a-z keys: ";
			cout << "\n\n\n\t\t->PRESS 2: a-z, 0-9, A-Z keys: ";	
			
			choice = getch();
			
			
	switch (choice)
	{
		case '1':{
			
		Value :: initialize_toZero();
		int count = 0;
		cout << "\n\n\t\t\tYou have selected a-z keys for the practice!";
		Sleep(500);
		cout << "\n\n\n\t\tINSTRUCTIONS: \n";
		cout << "\n\n\t\t->In this lesson, random characters from \"a\" to \"z\" will be generated.";
		cout << "\n\n\t\t->You would have to type the character that is being dislayed on the run time.";
		cout << "\n\n\t\t->You will get 1 point for typing each character accurately.";
		cout << "\n\n\t\t->A beep sound would be generated incase you missed any letter and will be counted in error.";
		cout << "\n\n\n\t\t\tPress any key to continue: ";	
		choice = getch();
		
		
	
	char small_char[] = { "abcdefghijklmnopqrstuvwxyz" };	
    	
		do
		{	

		int max_index = sizeof (small_char) / sizeof (small_char[0]);
	
	//generating random characters at run time			
	
		int random = rand() % max_index;
				
	 	system("cls");
	 	
	    colour(2);
	    
	    cout << "\n\n\t\t\tMAXIMUM MISTYPED CHARACTERS -> 3";
	    cout << "\n\n\t\t\tMistyped: " << error;
	    
	    colour(12);
	    
		cout << "\n\n\t\t\tPress enter if you wanna exit: \n";
	 	
	 	colour(14);
		
		cout << "\n\n\t\t\tPress: " << small_char[random]<<" ";
    
		ch = getch();
		
		letters++;
		count++;
					
		if( ch == small_char[random] ) {
					
		// if the input is equal to what our program displayed
		points++;
						
		}
		
		else {
			
		cout << "\a";
		error++;
					}
				}
				
	while(ch != '\r' && error <= 3); // loop continues until user presses enter
	
    
	letters -= 1; 
	error -= 1; //as pressing enter was also counted in character
	
	accuracy = (double) (points * 100) / (count);
	
	colour(1);
	
	cout << "\n\t\t\t\t\t*******RESULT*******\n";
	
	colour(2);
	
	cout << "Correct: " << points << endl;
	
	colour(4);
	
	cout << "Wrong: " << error << endl;
	
	colour(14);
    
	cout << "Total characters practiced: " << letters << endl;
    
	colour(8);
	
	cout << "\n\n\t\t->Your points: " << accuracy << "/100";
			
			colour(2);	
			
		if ( accuracy >= 90 && accuracy <= 100) {
		cout<<"\n\n\n\t\t\tWEll DONE!";
			}
			
		else if ( accuracy >= 70 && accuracy <= 89) {
		cout<<"\n\n\n\t\t\tNice try! ";
				}
				
		else if ( accuracy >= 50 && accuracy < 70) {
		cout<<"\n\n\n\t\t\tAverage score! ";
				}
		else {
		cout<<"\n\n\n\t\t\tPoor score! More practice needed.";
				}
				break;
				
			}	
			
	case '2': {
			
//initializing values for errors, points and accuracy to zero so that previous values aren't counted
				
				Value :: initialize_toZero();
				int count = 0;
				
		cout << "\n\n\t\t\tYou have selected a-z, A-Z, 0-9 keys for the practice!";
		Sleep(500);
		cout << "\n\n\n\t\tINSTRUCTIONS: \n";
		cout << "\n\n\t\t->In this lesson, random characters of upper and lower case and numbers from 0 to 9 will be generated.";
		cout << "\n\n\t\t->You would have to type the character that is being dislayed on the run time.";
		cout << "\n\n\t\t->You will get 1 point for typing each character accurately.";
		cout << "\n\n\t\t->A beep sound would be generated incase you missed any letter and will be counted in error.";
		cout << "\n\n\n\t\t\tPress any key to continue: ";
			
		choice = getch();
		
		do
		{	

		char combine[] = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" };
		
		int max_index = sizeof (combine) / sizeof (combine[0]);
		int random = rand() % max_index;				
		
		system("cls");
		
		
	    colour(2);
	    
	    cout << "\n\n\t\t\tMAXIMUM MISTYPED CHARACTERS -> 3";
	    cout << "\n\n\t\t\tMistyped: " << error;
	    
		colour(12);
		cout << "\n\n\t\t\tPress enter if you wanna exit: \n";
		colour(14); 	
		cout << "\n\n\t\t\tPress: " << combine[random]<<" ";		
		ch = getch();
		letters++;
		count++;
					
		if( ch == combine[random] ) {
					
		points++;
										
		}
		
		else {
			
		cout<<"\a";
		error++;
					}
				}
				while( ch != '\r' && error <= 3);
   letters -= 1; 
	error -= 1; //as pressing enter was also counted in character
	
	accuracy = (double)(points*100) / (count);
	
	colour(1);
	
	cout << "\n\t\t\t\t\t*******RESULT*******\n";
	
	colour(2);
	
	cout << "Correct: " << points<< endl;
	colour(4);
	
	cout << "Wrong: " << error <<endl;
	colour(14);
    cout << "Total characters practiced: " << letters << endl;
    colour(8);
	cout << "\n\n\t\t->Your points: " << accuracy << "/100";
			
			colour(2);	
		if( accuracy >= 90 && accuracy <= 100 ) {
		cout<<"\n\n\n\t\t\tWEll DONE!";
			}
			
		else if ( accuracy >= 70 && accuracy <= 89 ) {
		cout<<"\n\n\n\t\t\tNice try! ";
				}
				
		else if ( accuracy >= 50 && accuracy < 70 ){
		cout<<"\n\n\n\t\t\tAverage score! ";
				}
				
		else {
		cout<<"\n\n\n\t\t\tPoor score! More practice needed.";
				}
				
				break;
				
			}
			
		default: 
			cout << "\a";
			cout << "\n\n\t\t\tSELECTION NOT FOUND!";
			lessons();
		} //end of switch
			
		   cout << "\n\n\t\tPress any key to go back to main menu: ";
			choice = getch();
			system("cls");
			menu(letters);
			
		} // end of lessons
		
		void test(){
			
			system("cls");
			
			string input;
			
			colour(12);
			cout << "\n\n\t\t\t____________________";
			cout << "\n\n\t\t\tSELECT THE FOLLOWING";
			cout << "\n\n\t\t\t____________________";
			colour(9);
			cout << "\n\n\n\t\t->PRESS 1: COUNTRIES: ";
			cout << "\n\n\n\t\t->PRESS 2: ANIMALS: ";
			choice = getch();
			
			
			switch(choice) {
				
				case '1':{
				
			Value :: initialize_toZero();
		
		cout << "\n\n\t\t\tYou have selected COUNTRIES option for the test!";
		Sleep(500);
		cout << "\n\n\n\t\tINSTRUCTIONS: \n";
		cout << "\n\n\t\t->In this typing test, random country's name would be generated.";
		cout << "\n\n\t\t->Time will also be displayed at the end for testing how fast your typing skills are.";
		cout << "\n\n\t\t->You would have to type the country's name that is being dislayed on the run time.";
		cout << "\n\n\t\t->You will get 1 point for typing each word accurately.";
		cout << "\n\n\t\t->A beep sound would be generated incase you missed any letter and will be counted in error.";
		cout << "\n\n\n\t\t\tPress any key to continue: ";
		choice = getch();
				
		
				ifstream name;
				//opening a file that has all country names
				name.open("D:\\C++ Course\\basic filing\\Name of countries");
				
				
				vector <string> countries;
				string line;		
				
				if( !name ) // if file is not opening
				
				cout << "Seems like an error occured :(";
				
				while (getline(name, line)) {
        		countries.push_back(line);
    	}
				
				name.close(); 
				
			int max_index = countries.size();
			time_t start_time;
	
		
		do
		{	
			
		
		system("cls");
		
   	
	    colour(2);
	    
	    
	    cout << "\n\n\t\t\tMAXIMUM MISTYPED WORDS -> 3";
	    cout << "\n\n\t\t\tMistyped: " << error;
	    
		colour(12);
		
		cout << "\n\n\t\t\tType \"quit\" to exit: \n"; 
		
		colour(14);
		
		time_t start_time = time(NULL); // Get the current time
			
		int random = rand() % max_index;
		cout << "\n\n\t\tType: " << countries[random] << endl <<"\n\n\t\t";
		getline(cin, input);
		words++;
		
		for(int i=0; i<=countries[random].length(); i++) {
			
		//number of characters being practiced to display on main menu
		letters++;
		
		}
		
					
		if ( input.compare(countries[random]) == 0) {
					
		points++;
										
		}
		
		else {
			
		cout << "\a";
		error++;
				}
				
		} //end of do
				
				while( input != "quit" && error <= 3);
		
		 time_t end_time = time(NULL); // Get the current time again
    
	int minutes = static_cast<int>(start_time / 60)-(end_time / 60); // converting elapsed time into minutes
	
     elapsed_time = difftime(end_time, start_time);// time in seconds	
    
				words -= 1;
				error -= 2; //becus of initial beep sound 
				letters -= 4; //quit contains 4 letters which are also counted for result
				
				
	colour(1);
	cout << "\n\t\t\t\t\t*******RESULT*******\n";
	
	colour(2);
	cout << "Correct: " << points << endl;
	colour(4);
	cout << "Wrong: " << error << endl;
	colour(14);
    cout << "Total words practiced: " << words <<endl;
    colour(6);
	cout<<"Time taken: "<<minutes<<" minutes, "<<elapsed_time<<" seconds";
    colour(8);
    accuracy = (double) (points *100 / words);
	cout << "\n\n\t\t->Your points: " << accuracy << "/100";
				
			colour(2);	
		if ( accuracy >= 90 && accuracy <= 100 ) {
		cout<<"\n\n\n\t\t\tWEll DONE!";
			}
			
		else if ( accuracy >= 70 && accuracy <= 89 ) {
		cout<<"\n\n\n\t\t\tNice try! ";
				}
				
		else if ( accuracy >= 50 && accuracy < 70 ) {
		cout<<"\n\n\n\t\t\tAverage score! ";
				}
				
		else {
		cout<<"\n\n\n\t\t\tPoor score! Need alot of practice.";
				}
					break;
		} //end of case 1
				
		
		case '2': {
			
					Value :: initialize_toZero();
		
		cout << "\n\n\t\t\tYou have selected ANIMALS option for the test!";
		Sleep(500);
		cout << "\n\n\n\t\tINSTRUCTIONS: \n";
		cout << "\n\n\t\t->In this typing test, random animal's name would be generated.";
		cout << "\n\n\t\t->Time will also be displayed at the end for testing how fast your typing skills are.";
		cout << "\n\n\t\t->You would have to type the animal's name that is being dislayed on the run time.";
		cout << "\n\n\t\t->You will get 1 point for typing each word accurately.";
		cout << "\n\n\t\t->A beep sound would be generated incase you missed any letter and will be counted in error.";
		cout << "\n\n\n\t\t\tPress any key to continue: ";
		choice = getch();
	
			vector <string> animals;
			
			ifstream names;
			names.open("D:\\C++ Course\\basic filing\\Name of animals");
			
			if( !names )
			cout<<"Error occured while opening the file :(";
			
			string line;
			
		while (getline(names, line)) {
        animals.push_back(line);
    }
			names.close();
			
		int max_index = animals.size();
		time_t start_time;
		
		do
		{	
			
		int random = rand() % max_index;
		
		system("cls");
		
		colour(2);
	    
	    cout << "\n\n\t\t\tMAXIMUM MISTYPED WORDS -> 3";
	    cout << "\n\n\t\t\tMistyped: " << error;
		colour(12);
		cout << "\n\n\t\t\tType \"quit\" to exit: \n"; 	
		
		colour(14);
		
		time_t start_time = time(NULL); // Get the current time
		
		cout << "\n\n\t\tType: " << animals[random] << endl << "\n\n\t\t";
		getline(cin, input);
		words++;
		
		for(int i=0; i<=animals[random].length(); i++){
			
		letters++;
		
		}
		
					
		if( input.compare(animals[random]) == 0) {
					
		points++;
										
		}
		
		else {
			
		cout<<"\a";
		error++;
					}
		} // end of do
				
				while( input != "quit" && error <= 3);
    		
				words -= 1;
				error -= 2; 
				letters -= 4; //quit contains of 4 characters
				
		time_t end_time = time(NULL); // Get the current time again
    
	int minutes = static_cast<int>(start_time / 60)-(end_time / 60); // converting elapsed time into minutes
	
     elapsed_time = difftime(end_time, start_time);// time in seconds
    				
				system("cls");
				colour(1);
				
	cout << "\n\t\t\t\t\t*******RESULT*******\n";
	
	colour(2);
	cout << "Correct: " << points << endl;
	colour(4);
	cout << "Wrong: " << error << endl;
	colour(14);
    cout << "Total words practiced: " << words << endl;
    colour(6);
	cout<<"Time taken: "<<minutes<<" minutes, "<<elapsed_time<<" seconds";
    colour(8);
    accuracy = (double) (points * 100 / words);
	cout << "\n\n\t\t->Your points: "<< accuracy << "/100";
			
			colour(2);	
		if ( accuracy >= 90 && accuracy <= 100 ) {
		cout << "\n\n\n\t\t\tWEll DONE!";
			}
			
		else if ( accuracy >= 70 && accuracy <= 89 ) {
		cout << "\n\n\n\t\t\tNice try! ";
				}
				
		else if ( accuracy >= 50 && accuracy < 70 ) {
		cout << "\n\n\n\t\t\tAverage score! ";
				}
				
		else {
		cout << "\n\n\n\t\t\tPoor score! Need alot of practice.";
				}
				
			break;
		}	
				
				default:
					cout << "\a"; 
					test();
					cout << "\n\n\t\t\tSELECTION NOT FOUND!";
			} // end of switch
					
			cout << "\n\n\t\tPress any key to go back to main menu: ";
			choice = getch();
			system("cls");
			menu(letters);
			
		}// end of test function
			

	void menu(long letters) {

	colour(13);
	cout << "\n\n\t\t\t\t\t\t\tTotal characters practiced: " << letters;
	colour(12);
	cout << "\n\n\t\t\t\t____________________";
    cout << "\n\n\t\t\t\t     MAIN MENU";
    cout << "\n\n\t\t\t\t____________________";
	colour(9);
	cout << "\n\n\n\t\t\t->PRESS 1: LESSONS: ";
	cout << "\n\n\n\t\t\t->PRESS 2: TYPING TEST: ";
	cout << "\n\n\n\t\t\t->PRESS 3: EXIT: ";
	cout << "\n\t\t\t\t\t\t\t\tPlease enter your choice: ";
	choice = getch();
	
	switch(choice) {
	 
		case '1': {
			
			cout << "\a";
			system("cls");
			lessons();
			break; }
			
		case '2': {
			
			cout << "\a";
			system("cls");
			test();
			break; }

		case '3':{
			cout << "\a";
			colour(13);
			cout << "\n\n\t\t\t\t\tTHANK YOU FOR USING!"; 
			colour(12);
			cout << "\n\n\t\t\t\t\tDeveloped by: Sarwat Aijaz";
			break; }

			default:
				system("cls");
				cout << "\a";
				colour(12);
				cout << "\n\t\tInvalid key pressed!";
				menu(letters);				
				
	} //end of switch
  
  }// end of menu function

}; // end of class

int main() {
	
	//welcome screen
	
	tutor type;
			 		
	cout << "\n\n\t\t\t\t\t";
	int temp = 1;
	
	for(int i=1; i<40; i++) {
		if( temp == 15)
			temp = 1;
		
		cout << "*";
		type.colour(temp);
		temp++;
	}
    
	type.colour(1);
	
	cout << "\n\n\t\t\t\t\t_______________________________________";
	cout << "\n\n\t\t\t\t\t\tWELCOME TO MY TYPING TUTOR";
	cout << "\n\n\t\t\t\t\t_______________________________________";
	
	cout << "\n\n\t\t\t\t\t";
	
for(int i=1; i<40; i++) {
		if( temp == 15)
			temp = 1;
		
		cout << "*";
		type.colour(temp);
		temp++;
	}
	
	Sleep(100);
	
	type.colour(10);
	
	cout << "\n\n\t\t\t";
	
	string message = "Enter your name: ";
    for (int i = 0; i < message.length(); i++) {
        cout << message[i];
        Sleep(100); // Pause for 100 milliseconds
    }
	
	cin >> name;
	
	type.colour(128);
	cout << "\n\n\n\n\n\t\t";
	string message_2 = "Loading...";
	
	for(int i = 0; i < message_2.length() ; i++)
	{
		cout << message_2[i];	
		Sleep(100);
	}
	
	cout<<"\a";
	
	type.colour(12);
	system("cls");
	Sleep(50);
	
	cout << "\n\n\t\t\t\t\t**************************";    
	cout << "\n\n\t\t\t\t\t       Welcome "<< name << "!";
	cout << "\n\n\t\t\t\t\t**************************";
	
	type.colour(3);
	cout << "\n\n\t\tPress any key to continue: ";
	
	char ch;
	if(ch = getch()){
		system("cls");
	}
	
	Sleep(10);
	 type.menu(letters);
    
	
	return 0;
}

