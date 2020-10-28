/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 002            --
        -----------------------------------------------------------------
        |  Problem Statement :                                          |
        |---------------------------------------------------------------|
        | String Processing:                                            |
        | 1. Length                                                     |
        | 2. Substring                                                  |
        | 3. Indexing                                                   |
        | 4. Insert                                                     |
        | 5. Deleting                                                   |
        | 6. Replacing                                                  |
        -----------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

int LENGTH(char s[])
{
    return strlen(s);   // returning the length of the string
}

void INSERT(char s[], int indx, char t[])
{
    int len1 = strlen(s);       // storing the length of s
    int len2 = strlen(t);       // storing the length of t
    char temp[len1+len2+2];     // declaring a temporary string of necessary length
    int i;
    for(i = 0; i < indx; i++) { temp[i] = s[i]; }               // building temporary string
    for(int j = 0; j < len2; j++, i++) { temp[i] = t[j]; }      // building temporary string
    for(int j = indx; j < len1; i++, j++) { temp[i] = s[j]; }   // building temporary string
    temp[i]='\0';       // setting null character at the end of the temporary string
    strcpy(s, temp);    // copying temporary string to the given string pointer
}

void SUBSTRING(char s[], int initial, int length)
{
    char temp[length+1];        // declaring a temporary string of necessary length
    int s_len = LENGTH(s);      // storing the length of s
    int i;
    for(i = 0; i < length; i++) {
        if(i+initial < s_len) {
            temp[i] = s[initial + i];   // building temporary substring
        }
        else break;
    }
    temp[i]='\0';       // setting null character at the end of the temporary string
    strcpy(s, temp);    // copying temporary string to the given string pointer
}

int INDEX(char s[], char x[])
{
    int s_len = LENGTH(s);      // storing the length of s
    int x_len = LENGTH(x);      // storing the length of x
    int indx = -1;              // declaring and initializing the variable that 
                                // we have to return
    int i, j=0, bool = 0;       // declaring some other necessary variable
    
    for(i = 0; i <= s_len-x_len; i++) {         // finding the index algorithm
        if(s[i] == x[0]) {
            for(j = 0; j < x_len; j++) {
                if(s[i+j] != x[j]) {
                    j = 0;
                    break;
                }
            }
        }
        if(j == x_len) {
            bool = 1;
            break;
        }
    }
    if(bool) indx = i;
    return indx;        // returning the index
}

void REPLACE(char s[], char x[], char t[])
{
    int indx = INDEX(s, x);     // checking if the given pattern exists
    if(indx != -1) {
        int x_len = LENGTH(x);  // storing the length of x
        int s_len = LENGTH(s);  // storing the length of s
        int t_len = LENGTH(t);  // storing the length of t
        char temp[s_len - x_len + t_len +2];    // declaring a temporary string of necessary length
        int i;
                                            // replacing string algorithm
        for(i = 0; i < indx; i++) { temp[i] = s[i]; }
        for(int j = 0; j < t_len; j++, i++) { temp[i] = t[j]; }
        for(int j = indx + x_len; j < s_len; j++, i++) { temp[i] = s[j]; }
        temp[i] = '\0';
        
        strcpy(s, temp);        // copying temporary string to the given string pointer
    }
}

void DELETE(char s[], int p, int length)
{
    int s_len = LENGTH(s);          // storing the length of s
    char temp[s_len - length+2];    // declaring a temporary string of necessary length
    int i, j;
                                    // deleting string algorithm
    for(i = 0; i < p; i++) { temp[i] = s[i]; }
    j = p + length;
    for(; j < s_len; j++, i++) { temp[i] = s[j]; }
    temp[i] = '\0';
    
    strcpy(s, temp);        // copying temporary string to the given string pointer
}

void menu();

int main() 
{
    int n;
    menu();
    
    while(1) {
        scanf("%d", &n);
        if(n == 0) {
            printf("\nGood Bye!\n");
            break;
        }
        else if (n == 1) {
            char s[500];
            printf("Please Enter The String : ");
            getchar();
            gets(s);
            printf("Length of the string = %d\n\n", LENGTH(s));
        }
        else if (n == 2) {
            char s[500];
            int x, y;
            printf("String = ");
            getchar();
            gets(s);
            printf("Initial Position = ");
            scanf("%d", &x);
            printf("Length = ");
            scanf("%d", &y);
            SUBSTRING(s, x, y);
            
            printf("Your desired substring is : %s\n\n", s);
        }
        else if (n == 3) {
            char s[500];
            char t[500];
            getchar();
            printf("Text = ");
            gets(s);
            printf("Pattern = ");
            gets(t);
            int indx = INDEX(s, t);
            if(indx != -1) printf("Your desired index = %d\n\n", indx);
            else printf("No match!\n\n");
        }
        else if (n == 4) {
            char s[500];
            char t[500];
            int pos;
            getchar();
            printf("Text = ");
            gets(s);
            printf("Position = ");
            scanf("%d", &pos);
            printf("String = ");
            getchar();
            gets(t);
            
            INSERT(s, pos, t);
            printf("Your desired string = %s\n\n", s);
        }
        else if (n == 5) {
            char s[500];
            int x, y;
            printf("String = ");
            getchar();
            gets(s);
            printf("Initial Position = ");
            scanf("%d", &x);
            printf("Length = ");
            scanf("%d", &y);
            DELETE(s, x, y);
            
            printf("Your desired substring is : %s\n\n", s);
        }
        else if (n == 6) {
            char s[500];
            char x[500];
            char t[500];
            getchar();
            printf("text = ");
            gets(s);
            printf("pattern-1 = ");
            gets(x);
            printf("Pattern-02 = ");
            gets(t);
            REPLACE(s, x, t);
            
            printf("Your desired string = %s\n\n", s);
        }
        else {
            printf("Invalid Input.\n\n");
        }
        menu();
    }
    
    return 0;
}

void menu()         // creating a guiding menu
{
    printf("---  String Processing  ---\n");
    printf("0. Exit\n");
    printf("1. LENGTH(String)\n");
    printf("2. SUBSTRING(String, initial, length)\n");
    printf("3. INDEX(text, pattern)\n");
    printf("4. INSERT(text, position, string)\n");
    printf("5. DELETE(String, position, length)\n");
    printf("6. REPLACE(text, pattern1, pattern2)\n\n");
    printf("Enter your choice: ");
}
