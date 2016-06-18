#include <iostream>
#include <istream>

using namespace std;

char* appendWord(char *source, char* append);
int getLength(char *str);
void printSentence(char *str);
void appendSentence(char *source);

int main()
{
    char str[50],*nextString = (char*)malloc(sizeof(char*)), *currentString = (char*)malloc(sizeof(char*));
    char value = 0;

    currentString = appendWord("Hello", str);
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
             cout << "Please enter a sentence" << endl;
             cin.ignore(1);
             cin.getline(nextString, 50);
             //cin >> str;
             nextString = appendWord(currentString, str);
             currentString = nextString;
             break;
        case 'N':
            cout << "Please enter a new sentence" << endl;
            cin.ignore(1);
            cin.getline(nextString, 50);
            cout << "new sentence: " << nextString<< endl;
            nextString = appendWord(currentString, nextString);

            break;
        case 'P':
            printSentence(currentString);
            break;

        }
    }


    return 0;
}

char* appendWord(char *source, char* append){
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

void appendSentence(char *source){

        char * newSentence = (char*)malloc(sizeof(char*));

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
