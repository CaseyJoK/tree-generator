#include <iostream>
#include <ctime> 
#include <iomanip> 
#include <Windows.h>

using namespace std;

//const char BLANK = ' ', LEAF = '#', WOOD = '|'; these comments show the variables that were originally global and then I changed to be local and use paremeter passing
//const double MINSIZE = 4, MAXSIZE = 20;
//int treeHeight;

bool validHeight = false; //This sets the bool validHeight as false for all the functions, I left this as a global variable as I was struggling to make it local and pass it down through all the different functions (as I hadn't pracited passing a bool before)

int main()
{
	void getValidHeight();
	void drawAXmasTree();

	SetConsoleTitle("Christmas Tree - Casey-Jo Kenny - Group 2"); //This sets the console title to my name and group 
	PlaySound(TEXT("E:\Work\Fundamentals of Programming\Task 1a\Homework 3\sound.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); //This plays the christmas jingle and makes sure that it loops 
	cout << "Casey-Jo Kenny - Group 2 - Due on the 11th Decemeber 2018 \n \n"; //Outputs my name and the date the assignment is due

	struct tm dateTime;
	time_t now = time(0); //These 2 lines find the date and time at the time of running the program
	localtime_s(&dateTime, &now); //This attaches the date and time values to dateTime

	cout << dateTime.tm_mday << " ";

	switch (1 + dateTime.tm_mon) //This outputs the correct month in terms of the "mon" provided above 
	{
	case 1:
		cout << "January";
	case 2:
		cout << "Febuary";
	case 3:
		cout << "March";
	case 4:
		cout << "April";
	case 5:
		cout << "May";
	case 6:
		cout << "June";
	case 7:
		cout << "July";
	case 8:
		cout << "August";
	case 9:
		cout << "September";
	case 10:
		cout << "October";
	case 11:
		cout << "November";
	case 12:
		cout << "December";
	}
	cout << " " << 1900 + dateTime.tm_year << ", " << setfill('0') << setw(2) << dateTime.tm_hour << ":" << setfill('0') << setw(2) << 1 + dateTime.tm_min << ":" << setfill('0') << setw(2) << 1 + dateTime.tm_sec << "\n"; //outputs the whole date and time for the user to read and formats it so that theres leading 0's etc.


	drawAXmasTree(); //calls drawAXmasTree function
}

int getValidHeight() //This function checks if the size entered by the user is valid 
{
	const double MINSIZE = 4, MAXSIZE = 20; //Sets the min and max size that the tree can be 
	int treeHeight; //creates the variable for the treeHeight

	cout << "Enter the size of the tree (4-20):"; //asks for the input from user of their desired tree height
	cin >> treeHeight; //sets their input as a variable to be used later
	cout << endl; //starts a new line
	while (validHeight == false) //Because the global is set to false this while loop will automatically start when the user has entered a height
	{

		if (treeHeight >= MINSIZE && treeHeight <= MAXSIZE) //This checks to see if the treeHeight entered by the user is within the min and max size
		{
			validHeight = true; //If it is within the min and max size then it sets the validHeight to true and leaves the while loop
		}
		else //if it is without of the min and max size then it will move onto the else
		{
			validHeight = false; //which will set the validHeight to false 
			cout << "ERROR: Invalid height! Enter the size of the tree (4-20): "; //It will then produce this error message which will ask the user for a new size
			cin >> treeHeight; // and set the variable again which will then start the loop all over again to check if it is valid.
		}
	}

	return treeHeight; //This returns the treeHeight value 
}



void drawAXmasTree()
{
	const char BLANK = ' ', LEAF = '#', WOOD = '|'; //This sets the characters for the variables needed to draw the tree
	bool agreeToContinue(); //This sets agreeToContinue as bool so it can be true or false

	do // a do while means that it will do the entire function below while agree to continue is true
	{
		validHeight = false; //Sets the validHeight to false again to reset it
		int getValidHeight(); //Calls the getValidHeight Function above to ask for the height and check it
		void drawFoliage(char, char, int); //Calls the drawFoliage function
		void drawTrunk(char, char, int);//Calls the drawTrunk function

		int treeHeight = getValidHeight(); //This sets the variable treeHeight as the variable that the getValidHeight has returned. 

		HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //This is needed in order for the colours to work
		SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);  //This sets the colour for the foreground (border) to red and the background colour to white by mixing blue, green and red

		int border = 1; //This is a counter so that the while loop knows how many times to run depending on how big the border neeeds to be
		while (border <= (treeHeight * 2) - 1) //this says that while the "border" is less than the (treeHeight * 2) - 1 do the following, this is so we know what postion the border is in so we can use the the specific types of border and then we know that the border stays just bigger than the tree
		{
			//I used border symbols from Code Page 437
			//This while statement does the top portion of the border

			if (border == 1) { //if the border ==1 that means it is the top left corner
				cout << '\xC9'; //this means that we use the code for the symbol which represents the top left corner
				border++; //this then adds one to the border counter (border = border +1;) 
			}
			else if (border == (treeHeight * 2) - 1) //If the correct isnt true then we check if the position is the right hand corner
			{
				cout << '\xBB'; //If this is true we use the symbol of a border top right hand corner
				border++;//this then adds one to the border counter (border = border +1;) 
			}
			else { //If neither of these are true then we are in the middle of the top border 
				cout << '\xCD'; //this means that we use the symbol of the middle of the bored
				border++; //this then adds one to the border counter (border = border +1;) 
			}
		}
		cout << endl;
		SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //This sets the colour foreground (the tree) to green and sets the background to white by mixing blue, green and red.
		drawFoliage(BLANK, LEAF, treeHeight); //This calls the function drawFoliage which is set to the colours above because you set it before you call the function


		drawTrunk(BLANK, WOOD, treeHeight);//This calls the function drawTrunk which is set to the colours above because you set it before you call the function

		SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //This sets the colour foreground (the tree) to green and sets the background to white by mixing blue, green and red.

		border = 1; //The border will be set to red because I selected the colours before I created it

					//This while is doing things very similar to the above however this is for the bottom portion of the border
		while (border <= (treeHeight * 2) - 1)
		{
			if (border == 1) //if the border ==1 that means it is the bottom left corner
			{
				cout << '\xC8'; //This is the symbol code for the bottom left corner border
				border++; //this then adds one to the border counter (border = border +1;) 
			}
			else if (border == (treeHeight * 2) - 1) //If the correct isnt true then we check if the position is the right hand corner
			{
				cout << '\xBC'; //If this is true we use the symbol of a border bottom right hand corner
				border++; //this then adds one to the border counter (border = border +1;) 
			}
			else //If neither of these are true then we are in the middle of the bottom border 
			{
				cout << '\xCD'; //this means that we use the symbol of the middle of the bored
				border++; //this then adds one to the border counter (border = border +1;) 
			}
		}
		SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //This sets the text colour back to normal so that it isnt the same as above
		cout << endl; //This ends the line
	} while (agreeToContinue()); //This asks the user if they want another tree by going to the agreeToContinue function and will continue while it is true
}

bool agreeToContinue() { //This creates the bool function of agreeToContinue to ask the user if they want to continue
	char answer; //creates the char for the answer
	cout << "\nWould you like another tree? (Y/N): "; // This asks the user if they would want another tree and asks them to input Y or N
	cin >> answer; //Sets their answer as the answer variable
	if (tolower(answer) == 'y') //asks if their answer (and does (tolower(answer) so that it works if the user uses a lower case it will allow that to, equals to "y" which means yes
	{
		return true; // if this is true then return agreeToContinue as true
	}
	else {
		return false; //if this is false return agreeToContinue as false which will stop the program 
	}
}

void drawFoliage(char empty, char leaf, int treeHeight) //this is the function to draw the foliage and has the variables that it needs passed down
{

	int branchLine = 1; //this sets the branchLine as 1 which is used as a counter

	while (branchLine <= (treeHeight - 2)) //this says that while branchLine is less than or equal to treeHeight - 2 (because of the trunk) so that the program knows when to stop making the tree
	{
		void drawALineOfFoliage(char, char, int, int); //draw a line of foliage is what physically draws the leaves on each branch 
		drawALineOfFoliage(empty, leaf, treeHeight, branchLine); //does the above
		branchLine = branchLine + 1; //adds one to branch line so we know how many lines we have done (same as branchLine++)
	}//This will keep going until the branchLine is the same as (treeHeight - 2)

}

void drawTrunk(char empty, char trunk, int treeHeight) //This is very similar to the above but instead of drawing foliage it draws the trunk and has all the variables it needs passed to it
{
	double spaces; //creates the local variables that are needed
	double trunkLine = 1; //sets the trunkLine to 1 which acts as a counter (as explained above)
	while (trunkLine <= 2) // says that while trunkLine is more than or equal to 2 then do the following
	{
		HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //This sets the border colour because I had to do the side border with the trunk seperately
		cout << '\xBA'; //This sets the border as the side border symbol so that it is on either side of the trunk
		SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //sets the colour to brown for the trunk by mixing red and gro
		spaces = 1; //sets spaces to 1 to act as the counter for the trunk
		while (spaces <= (treeHeight - 2)) //This while says that while spaces is less than or equal to (treeHeight - 2)
		{
			cout << empty; //print an empty space so that the tree trunk is in the middle of the tree 
			spaces = spaces + 1; //add 1 to the space counter
		}

		cout << trunk; //print the trunk variable which is the same as WOOD
		spaces = 1; //spaces is 1 (resets the counter) this is because we need to print the border on the other side of the trunk and to do this we have to replicate the spaces on the other side of the trunk
		while (spaces <= (treeHeight - 2)) //does the same as above but after the wood
		{
			cout << empty; //adds empty spots after the wood
			spaces = spaces + 1; //adds 1 to the spaces counter
		}
		SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //This sets the colour back for the border as we need to do the right side of the trunk border
		cout << '\xBA'; //adds the symbol for the vertical border 
		cout << endl; //ends the line
		trunkLine = trunkLine + 1; //adds one the the counter so we know how many borders we need and when to stop
	}

}

void drawALineOfFoliage(char empty, char leaf, int treeHeight, int branchLine) //This is what prints each line of actual leaves in the tree and has all the variables it needs passed to it
{
	char randomDecoration(); //calls the function for a random decoration on the top of tree

	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //sets the border colour to red again for when we add the left side of the border (before the leaves)
	cout << '\xBA'; //outputs the symbol for the border (as mentioned above)
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //sets the colour to green for the leaves and the background to white by mixing blue, green and red
	for (int i = 0; i < treeHeight - branchLine - 1; i++) //i is the counter in this for loop and I am setting it as 0 and if i is less than treeHeight-branchLine -1; and then adding 1 to i at the end.
	{
		cout << empty; //output "BLANK" for the spaces on the left side of the tree (so it makes a tree shape)
	}
	for (int i = 0; i < (branchLine * 2) - 1; i++) //this is setting i again and then saying that if (branchLine * 2) - 1 and at the end add 1 to i
	{
		if (i == 0 && branchLine == 1) //if i == 0 it means that it is the top of three 
		{
			cout << randomDecoration(); //we then what to call the randomDecoration to select a decoration for the top of the tree
		}

		else { // if it isnt the top of the tree then do the following
			cout << leaf; //print the character LEAF which has been passed from a different function
		}
	}
	for (int i = 0; i < treeHeight - branchLine - 1; i++) //this is doing the same as above but for the otherside of the tree so we can add the border
	{
		cout << empty; //output a BLANK character that has been passed from above
	}
	SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //set the colour back to the red for the border
	cout << '\xBA'; //print the border symbol for the vertical 
	cout << endl; //end line
}

char randomDecoration() //function for the random decoration as a char
{
	switch (rand() % 4) //swtich to say that at random choose one of the below (out of 4 because theres 4 options)
	{
	case 0:
		return '*'; //display a *
	case 1:
		return '&'; //display a &
	case 2:
		return '@'; //display a @
	case 3:
		return '0'; //display a 0
	}
}

