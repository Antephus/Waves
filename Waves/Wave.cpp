/* Carrie Morris,  MSc Applied Computing
08000 5769
Handed in 28/10/2016
Version...3? 4?? */

#include <iostream>
#include <time.h>
using namespace std;


void print_wave(int wave_width);
void print_line(int line_width);
void print_consistent_waves();
void print_growing_waves();
void print_shrinking_waves();
void print_alternating_waves();

int main()
{
	int choice;

	cout << "Welcome! This program will display a series of waves made from * symbols." << endl << endl;

	// Display a small menu of options as a loop until the user is finished using the program
	do
	{
		cout << "------------------------------- MAIN MENU -------------------------------" << endl;
		cout << "What kind of waves would you like to see ?" << endl;
		cout << "1. Same sized waves" << endl;
		cout << "2. Waves that keep getting bigger" << endl;
		cout << "3. Waves that keep getting smaller" << endl;
		cout << "4. Waves that alternate in size between full and half sized waves" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "Please enter the number of your choice (1-4 or 0 to exit):" << endl;
		cin >> choice;

		// Get a new choice if the input was invalid
		while (!(choice >= 0) && !(choice < 5))
		{
			cout << "That's not a valid choice, please enter 1-4, or 0 to exit: " << endl;
			cin >> choice;
		}

		cout << endl << endl;


		switch (choice)
		{
		case 1:
			// Display waves of consistent size
			print_consistent_waves();
			break;

		case 2:
			// Display waves that keep getting bigger
			print_growing_waves();
			break;

		case 3:
			// Display waves that keep getting smaller
			print_shrinking_waves();
			break;

		case 4:
			// Display waves that alternate in size between half and full sized
			print_alternating_waves();
			break;

		case 0: 
			// If the user just wants to exit, don't print default error message and just break
			break;

		default:
			// If not an expected entry, get a new choice number
			cout << "That's not a valid choice, please enter 1-4, or 0 to exit: " << endl;
			cin >> choice;
			break;
		}

	//end of main menu
	} while (choice != 0);

	cout << "Thank you, good bye :)" << endl;

	return 0;
}



// Print a line of starsas wide as specified by the passed parameter
void print_line(int line_width)
{
	const int MILLISECONDS = 100;

	for (int count = 0; count < line_width; count++)
		cout << "*";

	// To slow things down
	clock_t goal = MILLISECONDS + clock();
	while (goal > clock());
}



// Print one wave/triangle of stars of a given width
void print_wave(int wave_width)
{
	int line_width;

	cout << endl;

	// Print lines of stars of increasing width till the specified overall width is reached
	for (line_width = 1; line_width < wave_width; line_width++)
	{
		print_line(line_width);
		cout << endl;
	}
	// Print lines of stars in decreasing width, forming one wave altogether with the previous lines
	for (line_width = wave_width; line_width > 0; line_width--)
	{
		print_line(line_width);
		cout << endl;
	}
}



void print_consistent_waves()
{
	int num_of_waves, wave_width;
	
	// Get the width of the waves and ensure it is at least large enough to see a wave shape
	cout << "How many stars wide would you like the widest point of the waves to be?" << endl;
	cout << "Please enter a whole number: " << endl;
	cin >> wave_width;

	while (wave_width < 2)
	{
		cout << "Sorry, you must enter a whole, positive number at least  2  or higher in order to see the wave shape, please try again: " << endl;
		cin >> wave_width;
	}


	// Get the number of waves they would like to see and ensure they enter at least two
	cout << endl << "And how many waves would you like to display?" << endl << "Please enter a whole number: " << endl;
	cin >> num_of_waves;

	while (num_of_waves < 2)
	{
		cout << "Sorry, you must enter a whole, positive number at least 2 or higher in order to see the waves' consistency of size: " << endl;
		cin >> num_of_waves;
	}

	// Print waves of consistent size
	for (int count = 0; count < num_of_waves; count++)
		print_wave(wave_width);
}



void print_growing_waves()
{
	int num_of_waves, wave_width;
	
	// Get the number of waves they would like to see and ensure they enter at least three
	cout << endl << "How many waves would you like to display?" << endl << "Please enter a whole number: " << endl;
	cin >> num_of_waves;

	while (num_of_waves < 3)
	{
		cout << "Sorry, you must enter a whole, positive number at least 3 or higher in order to see the difference in size between waves: " << endl;
		cin >> num_of_waves;
	}

	// Print waves of increasing size
	for (wave_width = 1; wave_width < num_of_waves; wave_width++)
		print_wave(wave_width);
}



void print_shrinking_waves()
{
	int num_of_waves, wave_width;

	// Get the number of waves they would like to see and ensure they enter at least two
	cout << endl << "How many waves would you like to display?" << endl << "Please enter a whole number: " << endl;
	cin >> num_of_waves;

	while (num_of_waves < 2)
	{
		cout << "Sorry, you must enter a whole, positive number at least 2 or higher in order to see the difference in size between waves: " << endl;
		cin >> num_of_waves;
	}

	// Print waves of decreasing size
	for (wave_width = num_of_waves; wave_width > 0; wave_width--)
		print_wave(wave_width);
}




void print_alternating_waves()
{
	int num_of_waves, wave_width;
	char last_wave_size = 'h'; // Set the last wave size variable to half-sized as first wave is always half sized

	// Get the width of the smaller waves and ensure it is at least large enough to see a wave shape
	cout << "How many stars wide would you like the widest point of the smaller (half sized) waves to be?" << endl;
	cout << "Please enter a whole number: " << endl;
	cin >> wave_width;

	while (wave_width < 2)
	{
		cout << "Sorry, you must enter a whole, positive number at least  2  or higher in order to see the wave shape, please try again: " << endl;
		cin >> wave_width;
	}
	
	// Get the number of waves they would like to see and ensure they enter at least three
	cout << endl << "How many waves would you like to display?" << endl << "Please enter a whole number: " << endl;
	cin >> num_of_waves;

	while (num_of_waves < 3)
	{
		cout << "Sorry, you must enter a whole, positive number at least 3 or higher in order to see the difference in size between waves: " << endl;
		cin >> num_of_waves;
	}

	// Print waves of alternating (half and full) sizes
	print_wave(wave_width);
	for (int count = 1; count < num_of_waves; count++)
	{
		if (last_wave_size == 'h')
		{
			print_wave((wave_width * 2));
			last_wave_size = 'f';
		}
		else
		{
			print_wave(wave_width);
			last_wave_size = 'h';
		}
	}
}