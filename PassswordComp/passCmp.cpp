/***********************************************************
**User Story 6      Similar Password
**
**DESCRIPTION:      main CPP file
**Version:			1.0
**
**This program will check add a series of passwords and compare to see if they are the same(will add additional functionality later)
***********************************************************/

#include <iostream>
#include <string.h>
#include <iomanip>
#include <vector>
#include <ctype.h>

using namespace std;

bool checkSimilarity(string passwordsToAdd, string passwordList[], int numPasswords );
void warning();

int main() {


	
	//Member variables for the number of password, and the current password to be added onto list as well as the password.
	int numPasswords;
	int index;
	string passwordsToAdd;
	
	//Ask for user input
	cout << "How many passwords would you like to implement?" << endl;
	cin >> numPasswords;
	
	//Creates memory allocation for string array;
	string passwordList[numPasswords];

	
	// x is condition for loop to run until enough passwords are inputted
	int x = 0;
	index = 0;
	while (x == 0)
	{
		
		cout << "Enter Password " << index+1 << endl;
		cin >> passwordsToAdd;
		
		if (checkSimilarity(passwordsToAdd, passwordList,index) == false)
		{
			passwordList[index] = passwordsToAdd;
			index++;
			if (index == numPasswords) {
			x = 1;
			}
		}
		else 
		{
			warning();
		}
		

		
	}
	
	
   
}

bool checkSimilarity (string passwordsToAdd, string passwordList[], int index)
{
	//cout << "I was here " << endl;
	string p1;
	string p2 = passwordsToAdd;
	string p3,p4;
	int k,l,m;
	l = 3;
	m = 0;
	const char * c = p2.c_str();
	k = strlen(c);
	
	for (int i=0;i <= k; i++){
		if (m >= l)
		{
			break;
		}
		else if (isalpha(p2[i])){
			p3 += p2[i];
			m += 1;
		}
		
		
		
	}
	//cout << "checking abcs for " << l << " length "  << p3 <<endl;
	//cout << " m is " << m << endl;
	
	for (int i = 0; i <= index;i++)
	{
		p4 = "";
		m = 0; //set initial count to 0
		p1 = passwordList[i];
		c = p1.c_str();
		k = strlen(c);
		// need to find a certain length (k) of letters in password list
		for (int j = 0;j < k;j++){
			if (m >= l)
			{
				break;
			}
			else if (isalpha(p1[j])) {
				p4 += p1[j];
				m += 1;
				//cout << "stuff was done here" << endl;
			}
		}
		if (p3 == p4)
		{
			cout <<"similar pw" <<endl;
			return true;
		}
		//cout << "this is p4" << p4 << endl;
		if (p1 == p2)
		{
			cout <<"same pw" <<endl;
			return true;
		}
		else
		{
		}
			
		
	}
	
	for (int i = 0; i <= index;i++)
	{
		p1 = passwordList[i];
		if (p1 == p2)
		{
			cout <<"same pw" <<endl;
			return true;
		}
		else
		{
		}
			
		
	}
	

	return false;
}

void warning() {
	cout << "Warning, you are using the similar passwords, please switch to a different password" << endl;
}

