#include <iostream>
#include <vector>
#include <string> 
using namespace std;

void cypher(vector<int> encmsg)
{
// code for cypher goes here.



}


int main()
{
	vector<int> intmsg;
	vector<int> encmsg({ 'V','F','X','B','L','I','T','Z','J','R','P','H','D','K','N','O','W','S','G','U','Y','Q','M','A','C','E' });
		
	std::cout << "Input text to cypher: ";
	std::getline (std::cin, intmsg);
	if (65 <= int(intmsg[0]) && int(intmsg[0]) <= 90) {
			cout << "uppercase" << endl;
		}
		else {
			cout << "lowercase" << endl;
		}

		return 0;
	}
	


// PSUEDO CODE FOR REFERENCE
	// IF char IS BETWEEN 65 AND 90 //is a capital letter
	// RETURN THE CHAR AT SLOT char - 65 IN CODE TABLE
	// ELSE IF char IS BETWEEN 97 AND 122 // is lower case letter
	// SET upperCaseLetter TO char - 32 // converts the number to upper case number
	// SET upperCaseCode TO CHAR AT SLOT upperCaseCode - 65 IN CODE TABLE // get upper case code
	// RETURN upperCaseCode + 32 // convert code back to lower case
	// ELSE // is not letter
	// RETURN char