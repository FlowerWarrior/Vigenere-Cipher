#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
    cout << "VIGENERE CIPHER" << endl;
    cout << "--------------" << endl;

    // Get acceptable text
    string text;
    bool acceptable = false;
    while(!acceptable){
        cout << "Enter text: ";
        getline(cin, text);

        acceptable = true;
        for (int i = 0; i < text.length(); i++){
            if (tolower(text[i]) < 97 && text[i] != 32){
                acceptable = false;
            }
            if (tolower(text[i]) > 122 && text[i] != 32){
                acceptable = false;
            }
        }
        if (!acceptable){
            cout << "Wrong characters! Try again..." << endl;;
        }
    }

    // Get acceptable pass key
    string passKey;
    bool space = true;
    bool strangeChars = true;
    while(space || strangeChars){
        cout << "Enter key: ";
        getline(cin, passKey);

        space = false;
        strangeChars = false;
        for (int i = 0; i < passKey.length(); i++){
            if (tolower(passKey[i]) < 97 || tolower(passKey[i]) > 122){
                if (passKey[i] == 32){
                    space = true;
                }
                else{
                    strangeChars = true;
                }
            }

        }
        if (strangeChars){
            cout << "Wrong characters! ";
        }
        if (space){
            cout << "No spaces allowed! ";
        }
        if (strangeChars || space){
            cout << "Try again..." << endl;
        }
    }

    string encryptionKey;
    string encryptedText;
    int encryptionKeyLen = 0;
    for (int i = 0; i < text.length(); i++){

        text[i] = tolower(text[i]);
        passKey[i] = tolower(passKey[i]);

        if (text[i] == ' '){
            encryptedText += ' ';
            continue;
        }

        int x = encryptionKeyLen;
        if (x > passKey.length() - 1){
            x = x % passKey.length();
        }
        encryptionKey += passKey[x];

        char letter = 97 + (( (text[i] - 97) + (encryptionKey[encryptionKeyLen] - 97) ) % 26);
        encryptionKeyLen++;

        while (letter > 122){
            letter = 97 + letter % 122;
        }
        encryptedText += letter;
    }
    cout << endl << "Encrypted text: " << encryptedText << endl << endl;
    cout << "Press any key to continue..." << endl;
    getch();
    return 0;
}
