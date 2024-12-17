#include "Queue.h"
#include "Cipher.h"

int main()
{
	cout << "This program is running..." << endl;

	string key = "Aumpkin";

	char * ptr =  &key[0];

	Cipher testing(8, ptr);

	string input = "acbie";
	cout << testing.decodeMessage(input) << endl;

}
