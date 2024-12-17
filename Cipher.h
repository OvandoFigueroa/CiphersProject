#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include "Queue.h"
using namespace std;
#include <string>

class Cipher{

	private:
		int arraySize;
		Queue cipherQueue;
		char* key;
	public:
		Cipher();
		Cipher( int, char* );
		void setCipher( int, char* );
		char * getCipher();
		string encodeMessage( string in );
		string decodeMessage( string in );
		static char letterShift( char , char , bool reverse );
		static int toNumbers(char);
		static char toLetters(int);

};

#endif
