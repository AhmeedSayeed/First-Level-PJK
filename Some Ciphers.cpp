// FCAI – Structured Programming – 2024 - Assignment 2
// Program Name: CS112_A2_T2_S18_20230021_20230444_20230083.cpp
// Program Description: A program can cipher and decipher: Route Cipher, Baconian Cipher, Vignere Cipher
// Last Modification Date: 10/3/2024
// Author1 and ID and Group: Ahmed Sayed Ahmed 20230021 [S17,S18]
// Author2 and ID and Group: Noureldin Mohamed Amin 20230444 [S17,S18]
// Author3 and ID and Group: Ayman Mohamed Emam 20230083 [S17,S18]
// Teaching Assistant: Eng.Ahmed Lotfy
// Who did what ==>
// Route Cipher, Menu and all validation functions made by [Ahmed Sayed Ahmed 20230021]
// Vignere Cipher made by [Ayman Mohamed Emam 20230083]
// Baconian Cipher and its validation function made by [Noureldin Mohamed Amin 20230444]

#include <bits/stdc++.h>
using namespace std;

int validation(int n1 , int n2){
    // Enter the number
    cout << "Please choose a number from " << n1 << " to " << n2 << ": " <<endl;
    string s_number;
    int number;
    getline(cin,s_number);
    // Check if number is valid
    bool flag = 0;
    while(!flag) {
        flag = 1;
        for (int i = 0; i < s_number.size(); ++i) {
            if (s_number[i] < '0' || s_number[i] > '9') {
                flag = 0;
                break;
            }
        }
        if(!flag){
            cout << "This input is invalid. Please choose a number from " << n1 << " to " << n2 << ": " <<endl;
            getline(cin,s_number);
        }
    }
    number = stoi(s_number);

    // Check if number is true
    while(number > n2 || number < n1){
        cout << "This number is not in range. Please choose a number from " << n1 << " to " << n2 << ": " <<endl;
        getline(cin,s_number);
        flag = 0;
        while(!flag) {
            flag = 1;
            for (int i = 0; i < s_number.size(); ++i) {
                if (s_number[i] < '0' || s_number[i] > '9') {
                    flag = 0;
                    break;
                }
            }
            if(!flag){
                cout << "This input is invalid. Please choose a number from " << n1 << " to " << n2 << ": " <<endl;
                getline(cin,s_number);
            }
        }
        number = stoi(s_number);
    }
    return number;
}

bool validate_message(string message){
    // Check if the message has characters or not
    for (int i = 0; i < message.size(); ++i) {
        if(isalpha(message[i]))
            return 1;
    }
    return 0;
}

void route_cipher(string message , int scrt_key){
    string message1 = "";
    double nChar = message.size();
    // Delete the spaces and non characters and make all characters capital
    for(int i = 0; i < message.size(); ++i) {
        if(isspace(message[i])) {
            nChar--;
            continue;
        }
        else if(isalpha(message[i])){
            message1 += toupper(message[i]);
        }
        else
            nChar--;
    }

    // Declare some important variables
    int rows = ceil(nChar/scrt_key) , counter = 0;
    char matrix[rows][scrt_key];

    // Fill the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < scrt_key; ++j) {
            if(counter < nChar) {
                matrix[i][j] = message1[counter];
                counter++;
            }
            else
                matrix[i][j] = 'X';
        }
    }

    // Print the encrypted message
    int TOP = 0 ,BOTTOM = rows - 1 , RIGHT = scrt_key - 1 , LEFT = 0;
    while(true){

        if(TOP > BOTTOM)
            break;
        for (int i = TOP; i <= BOTTOM; ++i) {
//            if(matrix[i][RIGHT] == 'X')
//                continue;
            cout << matrix[i][RIGHT];
        }
        RIGHT--;

        if(LEFT > RIGHT)
            break;
        for (int i = RIGHT; i >= LEFT; --i) {
//            if(matrix[BOTTOM][i] == 'X')
//                continue;
            cout << matrix[BOTTOM][i];
        }
        BOTTOM--;

        if(TOP > BOTTOM)
            break;
        for (int i = BOTTOM; i >= TOP; --i) {
//            if(matrix[i][left] == 'X')
//                continue;
            cout << matrix[i][LEFT];
        }
        LEFT++;

        if(LEFT > RIGHT)
            break;
        for (int i = LEFT; i <= RIGHT; ++i) {
//            if(matrix[top][i] == 'X')
//                continue;
            cout << matrix[TOP][i];
        }
        TOP++;
    }
    cout <<endl;
}

void route_decipher(string message , int scrt_key){
    double nChar = message.size();
    string message1 = "";
    // Clear the message
    for (int i = 0; i < message.size(); ++i) {
        if(isspace(message[i]) || !isalpha(message[i])) {
            nChar--;
        }
        else
            message1 += toupper(message[i]);
    }

    // Declare some important variables
    int rows = ceil(nChar/scrt_key) , counter = 0;
    char matrix[rows][scrt_key];

    // Fill the matrix
    int TOP = 0 ,BOTTOM = rows - 1 , RIGHT = scrt_key - 1 , LEFT = 0;
    while(true){

        if(TOP > BOTTOM)
            break;
        for (int i = TOP; i <= BOTTOM; ++i) {
            matrix[i][RIGHT] = message1[counter];
            counter++;
        }
        RIGHT--;

        if(LEFT > RIGHT)
            break;
        for (int i = RIGHT; i >= LEFT; --i) {
            matrix[BOTTOM][i] = message1[counter];
            counter++;
        }
        BOTTOM--;

        if(TOP > BOTTOM)
            break;
        for (int i = BOTTOM; i >= TOP; --i) {
            matrix[i][LEFT] = message1[counter];
            counter++;
        }
        LEFT++;

        if(LEFT > RIGHT)
            break;
        for (int i = LEFT; i <= RIGHT; ++i) {
            matrix[TOP][i] = message1[counter];
            counter++;
        }
        TOP++;
    }

    // Print the unencrypted message
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < scrt_key; ++j) {
//            if(matrix[i][j] == 'X')
//                continue;
            cout << matrix[i][j];
        }
    }
    cout <<endl;
}

void Vignere_cipher (string message)
{
    // Take the key from the user
    string key;
    cout << "PLease enter the key: " <<endl;
    getline(cin , key);
    string encrypted = "";
    string key2 = "";
    int counter = 0;
    // Make the length of the key equal to the length of the message
    for (int i = 0; i < message.size(); ++i) {
        if(counter == key.size())
            counter = 0;
        key2 += key[counter];
        counter++;
    }
    // Make all character capital in the message and in the key
    for (int i = 0; i < message.size(); ++i) {
        if (islower(message[i]))
            message[i] = toupper(message[i]);
        if (islower(key2[i]))
            key2[i] = toupper(key2[i]);
    }
    // Apply the cipher algorithm
    for (int i = 0; i < message.size(); ++i) {
        if (isalpha(message[i]))
        {
            encrypted += char(((int(message[i]) + int(key2[i])) % 26) + int('A'));
        }
        else
            encrypted += message[i];
    }
    cout << "Your decrypted message is:" <<endl;
    cout << encrypted <<endl;
}

void  Vignere_decipher(string message){

    // Make all character capital in the message
    for (int i = 0; i < message.size(); ++i) {
        if(isalpha(message[i]))
            message[i] = toupper(message[i]);
    }

    // Take the key from the user
    string key , key1 = "" , decrypted_message = "";
    cout << "Please, Enter the key: " <<endl;
    getline(cin,key);
    int count = 0;

    // Make the length of the key equal to the length of the message and convert its characters to capital
    for (int i = 0; i < message.size(); ++i) {
        if(count == key.size())
            count = 0;
        key1 += toupper(key[count]);
        count++;
    }

    // Apply the decipher algorithm
    int diff , plus;
    for (int i = 0; i < message.size(); ++i) {
        if(isalpha(message[i])) {
            diff = message[i] - 'A';
            for (int j = 0; j < 27; ++j) {
                if ((j + 65 + key1[i]) % 26 == diff)
                    plus = j;
            }
            decrypted_message += char(65 + plus);
        }else
            decrypted_message += message[i];
    }
    cout << decrypted_message <<endl;
}

// function to do baconian cipher
void baconian_cipher(string s)
{
    string cipher = "" , output = "";

    // convert all capital characters to small characters.
    for (int i = 0; i < s.size(); ++i) {
        if (isupper(s[i]))
            s[i] = tolower(s[i]);
    }

    // discard every non-alphabetic characters
    for (char i : s) {
        if (!isalpha(i))
            continue;

        // get the ascii for every character
        int bin = i - 'a';

        // convert the ascii to binary number
        while(bin > 0)
        {
            if (bin % 2 == 0)
            {
                cipher = '0' + cipher;
            }
            else
                cipher = '1' + cipher;
            bin /= 2;
        }
        while(cipher.size() < 5)
        {
            cipher = '0' + cipher;
        }

        // convert every 1 to b and every 0 to a
        for (int j = 0; j < cipher.size() ; ++j) {
            if (cipher[j] == '0')
                cipher[j] = 'a';
            else
                cipher[j] = 'b';
        }
        output += cipher + " ";
        cipher = "";
    }
    cout << "The message after ciphering is:" <<endl;
    cout << output <<endl;
}

// function to do baconian decipher
void baconian_decipher(string s) {
    int count = 0;
    string ch = "";
    string decipher = "";

    // erase spaces from the message
    for(int i = 0; i < s.size() ; ++i)
    {
        if (isspace(s[i]))
        {
            s.erase(s.begin() + i);
            i--;
        }
    }
    int size = s.size();
    for (int i = 0; i < size/5; ++i) {

        // divide the message into parts of 5 characters
        for (int j = 0; j < 5; ++j) {
            decipher += s[0];
            s.erase(s.begin());
        }

        // convert every a to 0 and every b to 1
        for (int j = 0; j < 5; ++j) {
            if (decipher[j] == 'a')
                decipher[j] = '0';
            else
                decipher[j] = '1';
        }
        int num = 0;

        // check if the binary is in the range of the codes of the alphabetic characters
        int dec = stoll(decipher);
        if (dec < 0 || dec > 11001) {
            decipher = "";
            count++;
            continue;
        }
        int k = 0;

        // convert the binary number to decimal
        while (dec > 0) {
            num += pow(2, k) * (dec % 10);
            dec /= 10;
            k++;
        }

        // get the ascii character for every decimal number
        ch += toupper(char(num + 97));
        decipher = "";
        num = 0;
    }
    cout << "The message after deciphering is:" << endl;
    cout << ch << endl;
    if (count)
    {
        if (count > 1)
            cout << "There are " << count << " characters have been ignored." <<endl;
        else
            cout << "There is " << count << " character has been ignored." <<endl;

    }
}

// Function to check if the entered message is valid or not
int valid_decipher(string s)
{
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != 'a' && s[i] != 'b' && !isspace(s[i]))
        {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Ahlan ya user ya habibi.\n";
    while(true) {
        // Choose from the menu
        cout << "What do you like to do now?\n"
                "1- Cipher a message\n"
                "2- Decipher a message\n"
                "3- End\n";
        int number = validation(1, 3);

        if (number == 1) {
            // Input the message
            cout << "Please enter the message to cipher: " << endl;
            string message;
            bool flag = 0;
            while(!flag){
                getline(cin, message);
                flag = validate_message(message);
                if(!flag)
                    cout << "This inout is invalid. Please enter a message contain characters: \n";
            }

            // Number of char
            int nChar = 0;
            for (int i = 0; i < message.size(); ++i) {
                if(isalpha(message[i]))
                    nChar++;
            }

            // Choose cipher
            cout << "Which Cipher do you like to choose?\n"
                    "1- Route Cipher\n"
                    "2- Baconian Cipher\n"
                    "3- Vignere Cipher\n"
                    "4- Return\n";
            int cipher = validation(1, 4);

            if (cipher == 1) {
                cout << "Enter the secret key!" <<endl;
                int scrt_key = validation(2,nChar/2);
                route_cipher(message,scrt_key);
            } else if (cipher == 2) {
                baconian_cipher(message);
            } else if (cipher == 3) {
                Vignere_cipher(message);
            }else{
                continue;
            }
        } else if (number == 2) {
            // Input the message
            cout << "Please enter the message to decipher: " << endl;
            string message;
            bool flag = 0;
            while(!flag){
                getline(cin, message);
                flag = validate_message(message);
                if(!flag)
                    cout << "This inout is invalid. Please enter a message contain characters: \n";
            }

            // Number of char
            int nChar = 0;
            for (int i = 0; i < message.size(); ++i) {
                if(isalpha(message[i]))
                    nChar++;
            }

            // Choose decipher
            cout << "Which Decipher do you like to choose?\n"
                    "1- Route decipher\n"
                    "2- Baconian decipher\n"
                    "3- Vignere decipher\n"
                    "4- Return\n";
            int decipher = validation(1, 4);

            if (decipher == 1) {
                cout << "Enter the secret key!" <<endl;
                int scrt_key = validation(2,nChar/2);
                route_decipher(message,scrt_key);
            } else if (decipher == 2) {
                while (!valid_decipher(message))
                {
                    cout << "Your message must consist of 'a' or 'b' only in decryption of this cipher." <<endl;
                    cout << "Please enter the message to decipher: " << endl;
                    getline(cin , message);
                }
                baconian_decipher(message);
            } else if (decipher == 3) {
                Vignere_decipher(message);
            }else{
                continue;
            }
        } else {
            cout << "Thanks for using our program" << endl;
            break;
        }
    }

    return 0;
}