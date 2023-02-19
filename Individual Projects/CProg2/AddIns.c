#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AddIns.h"

/**
* This method used to strip off any white space at the end of a given string.
The function should return the size of the resulting string
*
* method: RemoveEndingWhiteSpace
*
* return type: double
*
* parameters:
* InString [char] used for method
*
*
* @author Kirk McBrayer
* @since 3/31/22
*
*/   
int RemoveEndingWhiteSpace(char InString[]){
	while(isspace(InString[strlen(InString) - 1]))
		{
			InString[strlen(InString) - 1] = '\0';
		}
	return strlen(InString);
}

/**
* used in input integer data, the size used in your program,
from a given input file.
*
* method: InputInteger
*
* return type: double
*
* parameters:
* InFile [FILE] input the file
*
*
* @author Kirk McBrayer
* @since 3/31/22
*
*/   
int InputInteger(FILE* InFile){
	int value = 0;
	char InString[50];
	if(!InFile){
		printf("File did not open.");
	}
    else {
	    fgets(InString, 50, InFile);
			RemoveEndingWhiteSpace(InString);
			value = atoi(InString);
  }
	return value;
}

/**
* used in input floating data, the size used in your program,
from a given input file.
*
* method: InputInteger
*
* return type: double
*
* parameters:
* InFile [FILE] input the file
*
*
* @author Kirk McBrayer
* @since 3/31/22
*
*/
float InputFloat(FILE* InFile){
	
	float value = 0;
	char InString[50];
	if(!InFile){
		printf("File did not open.");
	}
    else {
	    fgets(InString, 50, InFile);
			RemoveEndingWhiteSpace(InString);
			value = atof(InString);
  }
	return value;
}
/**
* used to input string data from a given input file.
*
* method: RemoveEndingWhiteSpace
*
* return type: double
*
* parameters:
* InFile [FILE] input the file
* InString [char] used for method
*
*
* @author Kirk McBrayer
* @since 3/31/22
*
*/   
void InputString(FILE* InFile, char InString[]){
	
	if(!InFile){
		printf("File did not open.");
	}
	else{
		fgets(InString, 50, InFile);
				RemoveEndingWhiteSpace(InString);
	}
}