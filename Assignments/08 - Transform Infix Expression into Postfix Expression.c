/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 008            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Transform Infix Expression into Postfix Expression            |
        -----------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char StackChar[100000];
int TOPChar = -1;
int maxStkChar = 100000;

int pushChar( char item )
{
	if( TOPChar == maxStkChar - 1 ) {
		printf("Overflow\n");
		return 0;
	}
	TOPChar++;
	StackChar[TOPChar] = item;
	return 1;
}

int popChar()
{
	if( TOPChar == -1 ) {
		printf("Underflow\n");
		return 0;
	}
	TOPChar--;
	return 1;
}

void SUBSTRING(char s[], int initial, int length, char t[])
{
    char temp[length+1];
    int s_len = strlen(s);
    int i;
    for(i = 0; i < length; i++) {
        if(i+initial < s_len) {
            temp[i] = s[initial + i];
        }
        else break;
    }
    temp[i]='\0';
    strcpy(t, temp);
}

void convertInfixToPostfix( char** infix, char** postfix, int sz )
{
	// step - 01
	pushChar( '(' );
	strcpy(infix[sz], ")");
	sz++;
	int index = 0;

	// step - 02
	for( int i = 0; i < sz; i++ ) {
		// step - 06
		if( strcmp(infix[i], ")") == 0 ) {
			while( StackChar[TOPChar] != '(' ) {
				char tmp[2];
				tmp[0] = StackChar[TOPChar];
				tmp[1] = '\0';
				strcpy( postfix[index], tmp );
				index++;
				popChar();
			}
			popChar();
		}
		// step - 05
		else if( (strcmp(infix[i], "+") == 0) || (strcmp(infix[i], "-") == 0) || (strcmp(infix[i], "*") == 0) || (strcmp(infix[i], "/") == 0) || (strcmp(infix[i], "^") == 0) ) {
			if( (strcmp(infix[i], "+") == 0) || (strcmp(infix[i], "-") == 0) ) {
				while( StackChar[TOPChar] == '*' || StackChar[TOPChar] == '/' || StackChar[TOPChar] == '^' ) {
					char tmp[2];
					tmp[0] = StackChar[TOPChar];
					tmp[1] = '\0';
					popChar();
					strcpy( postfix[index], tmp );
					index++;
				}
				pushChar( infix[i][0] );
			}
			else if( infix[i][0] == '*' || infix[i][0] == '/' ) {
				while( StackChar[TOPChar] == '^' ) {
					char tmp[2];
					tmp[0] = StackChar[TOPChar];
					tmp[1] = '\0';
					strcpy( postfix[index], tmp );
					index++;
					popChar();
				}
				pushChar( infix[i][0] );
			}
			else {
				pushChar( '^' );
			}
		}
		// step - 04
		else if( strcmp(infix[i], "(") == 0 ) {
			pushChar( '(' );
		}
		// srep - 03
		else {
			strcpy( postfix[index], infix[i] );
			index++;
		}
	}
	strcpy( postfix[index], ")" );
}

int main()
{
	char input[1000000];
	gets(input);
	int sz = strlen(input);

	// declaring and initializing 2D string for storing the
	// postfix expression using pointer and malloc() function
	char** postfix;
	postfix = ( char ** ) malloc( sizeof( char * ) * 10000 );
	for( int i = 0; i < 10000; i++ ) {
		postfix[i] = ( char * ) malloc( sizeof( char ) * 20 );
	}

	// declaring and initializing 2D string for storing the
	// infix expression using pointer and malloc() function
	char** infix;
	infix = ( char ** ) malloc( sizeof( char * ) * 10000 );
	for( int i = 0; i < 10000; i++ ) {
		infix[i] = ( char * ) malloc( sizeof( char ) * 20 );
	}

	int index = 0;

	// analysing user input and storing necessary data
	for( int i = 0; i < sz; ) {
		if( input[i] == ' ' ) {
			i++;
			continue;
		}
		if( input[i] >= '0' && input[i] <= '9' ) {
			int j = i;
			while( input[j] >= '0' && input[j] <= '9' ) {
				j++;
			}
			int lengthOfNumber = j - i;
			char num[20];
			SUBSTRING( input, i, lengthOfNumber, num );
			strcpy( infix[index], num );
			index++;
			i = j;
			continue;
		}
		else {
			infix[index][0] = input[i];
			infix[index][1] = '\0';
			i++;
			index++;
		}
		i++;
	}
	// printing analysed user input
	printf("Input (The Infix Expression): \n");
	printf("----------------------------------\n");
	for( int i = 0; i < index; i++ ) {
		printf( "%s", infix[i] );
	}
	printf("\n\n\n");

	convertInfixToPostfix( infix, postfix, index );

	int i = 0;
	printf("Output (The Postfix Expression):\n");
	printf("----------------------------------\n");
	while( strcmp(postfix[i], ")") != 0 ) {
		printf("%s ", postfix[i] );
		i++;
	}

	return 0;
}

