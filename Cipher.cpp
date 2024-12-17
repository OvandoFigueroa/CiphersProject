#include "Cipher.h"
#include "Queue.h"

// This default constructor will set "cpsc" as the key
Cipher::Cipher(){

	cipherQueue.enqueue('c');
	cipherQueue.enqueue('p');
	cipherQueue.enqueue('s');
	cipherQueue.enqueue('c');
	arraySize = 4;

	key = new char[arraySize];
	key[0] = 'c';
	key[1] = 'p';
	key[2] = 's';
	key[3] = 'c';
}

// This overloaded constructor will take the word its given along side
// the int size to populate the queue
Cipher::Cipher(int size, char* ptr){

	int counter = 0;
	arraySize = size;
	key = new char[size];
	while ( counter < size ){
		cipherQueue.enqueue(*ptr);
		key[counter] = *ptr;
		counter++;
		ptr++;
	}
}

// This setCipher will take the word its given along side
// the int size to populate the queue
void Cipher::setCipher(int size, char* ptr){

	int counter = 0;
	arraySize = size;
	key = new char[size];
	while ( counter < size ) {
		cipherQueue.enqueue(*ptr);
		key[counter] = *ptr;
		counter++;
		ptr++;
	}

}

// This function returns the original cipher key
char* Cipher::getCipher(){
	return key;
}

/*
 * This function takes the size of the word it's given
 * to encode and uses that size to loop through every index of
 * the word and moves it forward according to the key
*/
string Cipher::encodeMessage(string in){
	int stringLength = in.size();
	char keyPortion;
	for ( int i = 0 ; i < stringLength ; i++ )
	{
		cipherQueue.dequeue(keyPortion); // Dequeues the key
		in[i] = letterShift( in[i], keyPortion, false );
		cipherQueue.enqueue(keyPortion); // Queues the key
		// The reason for this queue loop is incase the key is shorter
		// than the word its supposed to encode
	}
	return in;


}

/*
 * This function takes the size of the encoded word it's given
 * and uses that size to loop through every index
 * and moves it backward according to the key
*/
string Cipher::decodeMessage(string in){
	int stringLength = in.size();
        char keyPortion;
        for ( int i = 0 ; i < stringLength ; i++ )
        {
                cipherQueue.dequeue(keyPortion);
                in[i] = letterShift( in[i], keyPortion, true );
                cipherQueue.enqueue(keyPortion);
        }
        return in;
}

// This takes the character needed to shift, sends it into another
// function called toNumbers.
// This also takes the key which determines how much its supposed
// to shift and sends that as well into toNumbers.
char Cipher::letterShift(char input, char shift, bool reverse){

	int letterToShift = toNumbers(input);
	int shiftAmount = toNumbers(shift);

	if ( reverse == false ){
		letterToShift += shiftAmount;
		// For example, if you have z(26) and want to 
		// shift it forward by b(2), you'll over shoot.
		// You will have 28, so subtract 26 and you are
		// back to b(2)
		if ( letterToShift > 26 )
			letterToShift -= 26;
		return toLetters(letterToShift);

	} else {
		letterToShift -= shiftAmount;
		// For example, if you have a(1) and want to
                // shift it forward by a(1), you'll over shoot.
                // You will have 0, so add 26  and you are
                // back to z(26)
		if ( letterToShift <= 0 )
			letterToShift += 26;
		return toLetters(letterToShift);
	}
}

// This function converts letters into its respective number
// in the alphabet
int Cipher::toNumbers(char input){

	switch (input){
		case 'A':
			return 1;
			break;
		case 'B':
			return 2;
			break;
		case 'C':
			return 3;
			break;
		case 'D':
			return 4;
			break;
		case 'E':
                        return 5;
			break;
                case 'F':
                        return 6;
			break;
                case 'G':
                        return 7;
			break;
                case 'H':
                        return 8;
			break;
	       	case 'I':
                        return 9;
			break;
                case 'J':
                        return 10;
			break;
                case 'K':
                        return 11;
			break;
                case 'L':
                        return 12;
			break;
                case 'M':
                        return 13;
			break;
                case 'N':
                        return 14;
			break;
                case 'O':
                        return 15;
			break;
                case 'P':
                        return 16;
			break;
                case 'Q':
                        return 17;
			break;
                case 'R':
                        return 18;
			break;
                case 'S':
                        return 19;
			break;
                case 'T':
                        return 20;
			break;
                case 'U':
                        return 21;
			break;
		case 'V':
			return 22;
			break;
		case 'W':
			return 23;
			break;
		case 'X':
			return 24;
			break;
		case 'Y':
			return 25;
			break;
		case 'Z':
			return 26;
			break;
                case 'a':
                        return 1;
			break;
                case 'b':
                        return 2;
			break;
                case 'c':
                        return 3;
			break;
                case 'd':
                        return 4;
			break;
                case 'e':
                        return 5;
			break;
                case 'f':
                        return 6;
			break;
                case 'g':
                        return 7;
			break;
                case 'h':
                        return 8;
			break;
                case 'i':
                        return 9;
			break;
                case 'j':
                        return 10;
			break;
                case 'k':
                        return 11;
			break;
                case 'l':
                        return 12;
			break;
                case 'm':
                        return 13;
			break;
                case 'n':
                        return 14;
			break;
                case 'o':
                        return 15;
			break;
                case 'p':
                        return 16;
			break;
                case 'q':
                        return 17;
			break;
                case 'r':
                        return 18;
			break;
                case 's':
                        return 19;
			break;
                case 't':
                        return 20;
			break;
                case 'u':
                        return 21;
			break;
                case 'v':
                        return 22;
			break;
                case 'w':
                        return 23;
			break;
                case 'x':
                        return 24;
			break;
                case 'y':
                        return 25;
			break;
                case 'z':
                        return 26;
			break;
		default:
			return 1;
			break;
	}
}

// This function is used after the arithmetic above is done to return its
// respective character
char Cipher::toLetters(int input){

	switch (input){
		case 1:
			return 'a';
			break;
		case 2:
			return 'b';
			break;
                case 3:
                        return 'c';
			break;
                case 4:
                        return 'd';
			break;
                case 5:
                        return 'e';
			break;
                case 6:
                        return 'f';
			break;
                case 7:
                        return 'g';
			break;
                case 8:
                        return 'h';
			break;
                case 9:
                        return 'i';
			break;
                case 10:
                        return 'j';
			break;
                case 11:
                        return 'k';
			break;
                case 12:
                        return 'l';
			break;
                case 13:
                        return 'm';
			break;
                case 14:
                        return 'n';
			break;
                case 15:
                        return 'o';
			break;
                case 16:
                        return 'p';
			break;
                case 17:
                        return 'q';
			break;
                case 18:
                        return 'r';
			break;
                case 19:
                        return 's';
			break;
		case 20:
                        return 't';
			break;
                case 21:
                        return 'u';
			break;
                case 22:
                        return 'v';
			break;
                case 23:
                        return 'w';
			break;
                case 24:
                        return 'x';
			break;
		case 25:
			return 'y';
			break;
		case 26:
			return 'z';
			break;
		default:
			return '?';
			break;
	}

}
