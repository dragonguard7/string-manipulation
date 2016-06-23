#include <stdlib.h>
#include <iostream>

using namespace std;

char* appendSentence(char *source, char* append);
int getLength(char *str);
void printSentence(char *str);

int main()
{
    char append[50], newString[50], *nextString = (char*)malloc(sizeof(char*)), *currentString = (char*)malloc(sizeof(char*));
    char value = 'n';

    currentString = "Hello";
    printSentence(currentString);

    while(value != 'q'){
        cout << "Please enter a command: " << endl <<
                "\tA-append word." << endl <<
                "\tN-create new sentence" << endl <<
                "\tP-print sentence" << endl;
        cin >> value;

        if(value > 'Z'){ value -= ' ';}
        switch(value){
        case 'A':
             cout << "Please enter an addition" << endl;
             cin.ignore(1);
             cin.getline(append, 50);
             nextString = appendSentence(currentString, append);
             currentString = nextString;
             printSentence(currentString);
             break;
        case 'N':
            cout << "Please enter a new sentence" << endl;
            cin.ignore(1);
            cin.getline(newString, 50);
            currentString = newString;
            printSentence(currentString);
            break;
        case 'P':
            printSentence(currentString);
            break;

        }
    }


    return 0;
}

char* appendSentence(char *source, char* append){
    int sourceLen = getLength(source);
    int appendLen = getLength(append);

    //+2: 1 for space, 1 for null terminator
    char *newString = (char*)malloc(sizeof(char*) * (sourceLen + appendLen +2));
    char *temp = newString;

    int i;
    for(i = 0; i < (sourceLen); i++){
        *temp = *source;
        temp++; source++;
    }
    *temp = *(" ");
    temp++;
    i++;
    for(; i < (sourceLen + appendLen +2); i++){
        *temp = *append;
        temp++; append++;
    }
    newString[sourceLen+appendLen+1] = '\0';
    return newString;

}


//***Helper function to avoid string library.

//Gets the length of a char pointer, must be null terminated.
int getLength(char *str){
    int count = 0;
    while(*str){
        str++;
        count++;
    }
    return count;
}

void printSentence(char *str){
    cout << "Current sentence: " << str << endl;
}
