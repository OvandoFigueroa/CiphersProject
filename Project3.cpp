#include "Queue.h"
#include "Cipher.h"

int main()
{
	//cout << "This program is running..." << endl;

	string key;

	cout << "Type in the word to use as the key: ";

	cin >> key;

	char * ptr =  &key[0];

	Cipher testing(sizeof(key), ptr);

	string input;
	
	char option;

	cout << "[e] encode with that key" << endl;

	cout << "[d] decode with that key" << endl;

	cout << "[q] quit" << endl;

	cin >> option;

	if (option == 'e')
	{

		cout << "Enter what to encode: ";

		cin >> input;

		cout << testing.encodeMessage(input) << endl;

	}
	else if (option == 'd')
	{

		cout << "Enter what to decode: ";

		cin >> input;

		cout << testing.decodeMessage(input) << endl;

	}
	else
	{
		return 0;
	}




}
