//============================================================================
// Name        : Project2.cpp
// Author      : Josh Boston
// Version     :
// Copyright   : Your copyright notice
// Description : Project 2
//============================================================================

#include <iostream>
#include <string>
#include <cctype> // for case conversion
#include <vector>
using namespace std;


struct Word
{
    string english;
    string piglatin;
};

//prototypes
Word* splitSentence(const string, int&);
void convertToPigLatin(Word [], int);
void formatString(int, const string&, string&);
bool doesStartWithVowel(string);
void displayPigLatin(const Word[], int);

int main()
{
    string userString, formattedUserString;
    Word * wordArray = nullptr;

    //size for the array
    int size = 0;

    cout << "Please enter a string to convert to PigLatin: " << endl;
    getline(cin, userString);





    //split string into words store in word array
    wordArray = splitSentence(userString, size);


    //convert english word into piglatin
    convertToPigLatin(wordArray, size);

    //display words in both english and piglatin
    displayPigLatin(wordArray,size);



    return 0;
}

//keeps only letters and spaces and changes letters to lowercase
void formatString(int size, const string &token, string &formattedToken) {


    for (int i = 0; i < size; i++) {


        if (isalpha(token[i]) || isspace(token[i])) {
            formattedToken += tolower(token[i]);
        }


    }

    //erase spaces from beggining of string
    int index = 0;
    while (formattedToken[index] == ' ')
    {
        formattedToken.erase(index);
        index++;
    }

    //erase spaces from back of string
    int backIndex = formattedToken.size() -1;
    while (formattedToken[backIndex] == ' ')
    {
        formattedToken.erase(backIndex);
        backIndex--;
    }

}

Word * splitSentence(const string words, int &size)
{
    int tokenStart = 0; //index of the word
    char delim = ' '; // the delimiter is a space
    string formattedToken, formattedWords;
    vector<string> wordVector; //stores all the words to copy to array

    int wordsSize = words.size();   //size of array


    formatString(wordsSize, words, formattedWords); //formats string so there are only lowercase letters



    int element = 0;



    //find first index with a space after the first wordVector store it in variable
    int delimPosition = formattedWords.find(delim, tokenStart);



    //if there is only one word add that word to the vector
    if(delimPosition == -1)
    {
        wordVector.push_back(formattedWords);
    }

    int iteration = 0;
    while(delimPosition != -1)
    {

        iteration++;
        //get the wordVector, store it in variable
        string token = formattedWords.substr(tokenStart, delimPosition - tokenStart);






        wordVector.push_back(token);
        delimPosition++;

        while(formattedWords[delimPosition] == ' ')
        {
            delimPosition++;
        }




        tokenStart = delimPosition;

        //find the next space
        delimPosition = formattedWords.find(delim, delimPosition);


        //get the last wordVector
        if(delimPosition == -1)
        {
            formattedToken = "";
            token = "";
            string token = formattedWords.substr(tokenStart, delimPosition - tokenStart);



            wordVector.push_back(token);
        }






    }

    size = wordVector.size();

    Word* wordsArray = new Word[wordVector.size()]; //array pointer of Word type to return

    //copy vector to Word variable then add it to dynamic array pointer
    for(int i = 0; i < wordVector.size(); i++)
    {

        Word word;
        word.english = wordVector.at(i);
        wordsArray[i] = word;
    }



    return wordsArray;
}

void convertToPigLatin(Word wordArr[], int size)
{

    string englishWord, piglatinWord;

    for (int i = 0; i < size; ++i) {
        englishWord = wordArr[i].english;


        //if it does not start with a vowel
       if(!doesStartWithVowel(englishWord))
       {
           char firstLetter = englishWord[0];
           englishWord.erase(0,1);

           englishWord.push_back(firstLetter);
           englishWord += "ay";

           wordArr[i].piglatin = englishWord;


       }
       else //it does start with a vowel
       {
            wordArr[i].piglatin = wordArr[i].english + "way";

       }


    }




}

//returns true if the string does start with a vowel
bool doesStartWithVowel(string str)
{
    if(tolower(str[0]) == 'a' || tolower(str[0]) == 'e' ||
       tolower(str[0]) == 'i' || tolower(str[0]) == 'o' ||
       tolower(str[0]) == 'u')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//takes an array pointer with its size and displays it to the screen
void displayPigLatin(const Word * wordArray, int size)
{
    //displays the english word
    for (int i = 0; i < size; ++i)
    {
        cout << wordArray[i].english << " ";
    }
    cout<<endl;

    cout << "Output: " << endl;

    //displays the piglatin version
    for (int i = 0; i < size; ++i)
    {
          cout << wordArray[i].piglatin << " ";
    }
    cout<< endl;
}



