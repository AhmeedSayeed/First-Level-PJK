// Program: A board of 3 x 3 is displayed and player 1 takes odd numbers 1,
//3, 5, 7, 9 and player 2 takes even numbers 0, 2, 4, 6, 8. Players take turns to write their
//numbers. Odd numbers start. Use each number only once. The first person to complete a line
//that adds up to 15 is the winner. The line can have both odd and even numbers.
// Author: Ahmed Sayed Ahmed
// ID: 20230021
// Section: None (Registration did not open)
// Version: 1.0
// Date: 1 March 2024

#include <bits/stdc++.h>
using namespace std;

int player1_input_row(){
    // Enter the row
    cout << "Player 1, please choose a row from 1 to 3: " <<endl;
    string s_row;
    int row;
    getline(cin,s_row);
    // Check if row is valid
    bool flag = 0;
    while(!flag) {
        flag = 1;
        for (int i = 0; i < s_row.size(); ++i) {
            if (s_row[i] < '0' || s_row[i] > '9') {
                flag = 0;
                break;
            }
        }
        if(!flag){
            cout << "This input is invalid. Please choose a row from 1 to 3: " <<endl;
            getline(cin,s_row);
        }
    }
    row = stoi(s_row);

    // Check if row is true
    while(row > 3 || row < 1){
        cout << "This row is not in range. Please choose a row from 1 to 3: " <<endl;
        getline(cin,s_row);
        flag = 0;
        while(!flag) {
            flag = 1;
            for (int i = 0; i < s_row.size(); ++i) {
                if (s_row[i] < '0' || s_row[i] > '9') {
                    flag = 0;
                    break;
                }
            }
            if(!flag){
                cout << "This input is invalid. Please choose a row from 1 to 3: " <<endl;
                getline(cin,s_row);
            }
        }
        row = stoi(s_row);
    }
    return row;
}

int player1_input_column(){
    // Enter the column
    cout << "Player 1, please choose a column from 1 to 3: " <<endl;
    string s_column;
    int column;
    getline(cin,s_column);
    // Check if column is valid
    bool flag = 0;
    while(!flag) {
        flag = 1;
        for (int i = 0; i < s_column.size(); ++i) {
            if (s_column[i] < '0' || s_column[i] > '9') {
                flag = 0;
                break;
            }
        }
        if(!flag){
            cout << "This input is invalid. Please choose a column from 1 to 3: " <<endl;
            getline(cin,s_column);
        }
    }
    column = stoi(s_column);

    // Check if column is true
    while(column > 3 || column < 1){
        cout << "This column is not in range. Please choose a column from 1 to 3: " <<endl;
        getline(cin,s_column);
        flag = 0;
        while(!flag) {
            flag = 1;
            for (int i = 0; i < s_column.size(); ++i) {
                if (s_column[i] < '0' || s_column[i] > '9') {
                    flag = 0;
                    break;
                }
            }
            if(!flag){
                cout << "This input is invalid. Please choose a column from 1 to 3: " <<endl;
                getline(cin,s_column);
            }
        }
        column = stoi(s_column);
    }
    return column;
}

int player2_input_row(){
    // Enter the row
    cout << "Player 2, please choose a row from 1 to 3: " <<endl;
    string s_row;
    int row;
    getline(cin,s_row);
    // Check if row is valid
    bool flag = 0;
    while(!flag) {
        flag = 1;
        for (int i = 0; i < s_row.size(); ++i) {
            if (s_row[i] < '0' || s_row[i] > '9') {
                flag = 0;
                break;
            }
        }
        if(!flag){
            cout << "This input is invalid. Please choose a row from 1 to 3: " <<endl;
            getline(cin,s_row);
        }
    }
    row = stoi(s_row);

    // Check if row is true
    while(row > 3 || row < 1){
        cout << "This row is not in range. Please choose a row from 1 to 3: " <<endl;
        getline(cin,s_row);
        flag = 0;
        while(!flag) {
            flag = 1;
            for (int i = 0; i < s_row.size(); ++i) {
                if (s_row[i] < '0' || s_row[i] > '9') {
                    flag = 0;
                    break;
                }
            }
            if(!flag){
                cout << "This input is invalid. Please choose a row from 1 to 3: " <<endl;
                getline(cin,s_row);
            }
        }
        row = stoi(s_row);
    }
    return row;
}

int player2_input_column(){
    // Enter the column
    cout << "Player 2, please choose a column from 1 to 3: " <<endl;
    string s_column;
    int column;
    getline(cin,s_column);
    // Check if column is valid
    bool flag = 0;
    while(!flag) {
        flag = 1;
        for (int i = 0; i < s_column.size(); ++i) {
            if (s_column[i] < '0' || s_column[i] > '9') {
                flag = 0;
                break;
            }
        }
        if(!flag){
            cout << "This input is invalid. Please choose a column from 1 to 3: " <<endl;
            getline(cin,s_column);
        }
    }
    column = stoi(s_column);

    // Check if column is true
    while(column > 3 || column < 1){
        cout << "This column is not in range. Please choose a column from 1 to 3: " <<endl;
        getline(cin,s_column);
        flag = 0;
        while(!flag) {
            flag = 1;
            for (int i = 0; i < s_column.size(); ++i) {
                if (s_column[i] < '0' || s_column[i] > '9') {
                    flag = 0;
                    break;
                }
            }
            if(!flag){
                cout << "This input is invalid. Please choose a column from 1 to 3: " <<endl;
                getline(cin,s_column);
            }
        }
        column = stoi(s_column);
    }
    return column;
}

int main(){
    // Welcome message
    cout << "Welcome to Tic-Tac-Toe with numbers Game." <<endl;

    // set the initial board
    char board[3][3];
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            board[row][col] = 'X';
        }
    }

    // Display the board
    cout << "Initial board: " <<endl;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cout << setw(5) << board[row][col] << setw(5);
        }
        cout << endl;
    }

    // Set available numbers for player 1
    vector <int> player1_available_numbers {1 , 3 , 5 , 7 , 9};
    // Set available numbers for player 2
    vector <int> player2_available_numbers {0 , 2 , 4 , 6 , 8};

    //Set the counter of plays
    int counter = 0;

    // Start program
    while(counter <= 9) {
        // Player 1 Turn

        // Display the board
        if(counter != 0) {
            cout << "Now, board became: " <<endl;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    cout << setw(5) << board[row][col] << setw(5);
                }
                cout << endl;
            }
        }

        // Display available number for player 1
        cout << "Available numbers for Player 1: \n";
        for (int i = 0; i < player1_available_numbers.size(); ++i) {
            cout << player1_available_numbers[i];
            if (i != player1_available_numbers.size() - 1) cout << ',';
        }
        cout << endl;

        // Display available number for player 2
        cout << "Available numbers for Player 2: \n";
        for (int i = 0; i < player2_available_numbers.size(); ++i) {
            cout << player2_available_numbers[i];
            if (i != player2_available_numbers.size() - 1) cout << ',';
        }
        cout << endl;

        // Player 1 enter his number
        cout << "Player 1, please enter a number from your available numbers: " <<endl;
        string s_number;
        int number;
        getline(cin,s_number);
        bool flag_s = 0;

        // Validate the number
        while(!flag_s) {
            flag_s = 1;
            for (int i = 0; i < s_number.size(); ++i) {
                if (s_number[i] < '0' || s_number[i] > '9') {
                    flag_s = 0;
                    break;
                }
            }
            if(!flag_s){
                cout << "This input is invalid. Please choose a number from your available numbers: " <<endl;
                getline(cin,s_number);
            }
        }
        number = stoi(s_number);

        // Check if the number is in player 1 available numbers
        bool flag = 0;
        while (!flag) {
            for (int i = 0; i < player1_available_numbers.size(); ++i) {
                if (number == player1_available_numbers[i]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                // Enter the number again and check if valid
                cout << "This number is not available, Please choose a number from your available numbers: " <<endl;
                getline(cin,s_number);
                flag_s = 0;
                while(!flag_s) {
                    flag_s = 1;
                    for (int i = 0; i < s_number.size(); ++i) {
                        if (s_number[i] < '0' || s_number[i] > '9') {
                            flag_s = 0;
                            break;
                        }
                    }
                    if(!flag_s){
                        cout << "This input is invalid. Please choose a number from your available numbers: " <<endl;
                        getline(cin,s_number);
                    }
                }
                number = stoi(s_number);
            }
        }

        // Remove the number from player 1 available numbers
        for (int i = 0; i < player1_available_numbers.size(); ++i) {
            if (number == player1_available_numbers[i]) {
                player1_available_numbers.erase(player1_available_numbers.begin() + i);
                break;
            }
        }

        // Enter the row
        int row;
        row = player1_input_row();

        // Enter the column
        int column;
        column = player1_input_column();

        // Check if the index is chosen
        while (board[row-1][column-1] != 'X') {
            cout << "This place is chosen before. You have to re enter the row and the column again." <<endl;
            row = player1_input_row();
            column = player1_input_column();
        }

        // Update the board
        board[row-1][column-1] = number + '0';

        // Update the counter
        counter++;

        // Check if player 1 won
        int row_sum1 = 0 , column_sum1 = 0 , diagonal_sum1 = 0 ,diagonal_sum2 = 0 ;
        bool flag_sum = 1;
        for(int i = 0; i < 3; ++i) {
            if(board[row-1][i] == 'X') {
                flag_sum = 0;
                continue;
            }
            row_sum1 += board[row-1][i] - '0';
        }
        if(row_sum1 == 15 && flag_sum) {
            // Display the board
            cout << "Now, board became: " << endl;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    cout << setw(5) << board[row][col] << setw(5);
                }
                cout << endl;
            }
            cout << "Player 1 is the winner" << endl;
            break;
        }
        flag_sum = 1;
        for(int i = 0; i < 3; ++i) {
            if(board[i][column-1] == 'X') {
                flag_sum = 0;
                continue;
            }
            column_sum1 += board[i][column-1] - '0';
        }
        if(column_sum1 == 15 && flag_sum){
            // Display the board
            cout << "Now, board became: " << endl;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    cout << setw(5) << board[row][col] << setw(5);
                }
                cout << endl;
            }
            cout << "Player 1 is the winner" <<endl;
            break;
        }
        flag_sum = 1;
        if(row + column == 2 || row + column == 4 || row + column == 6){
            for (int i = 0; i < 3; ++i) {
                if(board[i][i] == 'X') {
                    flag_sum = 0;
                    continue;
                }
                diagonal_sum1 += board[i][i] - '0';
            }
        }
        if(diagonal_sum1 == 15 && flag_sum){
            // Display the board
            cout << "Now, board became: " << endl;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    cout << setw(5) << board[row][col] << setw(5);
                }
                cout << endl;
            }
            cout << "Player 1 is the winner" <<endl;
            break;
        }
        flag_sum = 1;
        if(row + column == 4){
            int j = 2;
            for (int i = 0; i < 3; ++i) {
                if(board[i][j] == 'X') {
                    flag_sum = 0;
                    continue;
                }
                diagonal_sum2 += board[i][j] - '0';
                j--;
            }
        }
        if(diagonal_sum2 == 15 && flag_sum){
            // Display the board
            cout << "Now, board became: " << endl;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    cout << setw(5) << board[row][col] << setw(5);
                }
                cout << endl;
            }
            cout << "Player 1 is the winner" <<endl;
            break;
        }

        // Check if Draw
        if(counter == 9) {
            // Display the board
            cout << "Now, board became: " << endl;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    cout << setw(5) << board[row][col] << setw(5);
                }
                cout << endl;
            }
            cout << "This game is Draw" <<endl;
            break;
        }

        // Player 2 Turn

        // Display the board
        cout << "Now, board became: " <<endl;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                cout << setw(5) << board[row][col] << setw(5);
            }
            cout << endl;
        }

        // Display available number for player 1
        cout << "Available numbers for Player 1: \n";
        for (int i = 0; i < player1_available_numbers.size(); ++i) {
            cout << player1_available_numbers[i];
            if (i != player1_available_numbers.size() - 1) cout << ',';
        }
        cout << endl;

        // Display available number for player 2
        cout << "Available numbers for Player 2: \n";
        for (int i = 0; i < player2_available_numbers.size(); ++i) {
            cout << player2_available_numbers[i];
            if (i != player2_available_numbers.size() - 1) cout << ',';
        }
        cout << endl;

        // Player 2 enter his number
        cout << "Player 2, please enter a number from your available numbers: " <<endl;
        string s_number2;
        int number2;
        getline(cin,s_number2);
        bool flag_s2 = 0;

        // Validate the number
        while(!flag_s2) {
            flag_s2 = 1;
            for (int i = 0; i < s_number2.size(); ++i) {
                if (s_number2[i] < '0' || s_number2[i] > '9') {
                    flag_s2 = 0;
                    break;
                }
            }
            if(!flag_s2){
                cout << "This input is invalid. Please choose a number from your available numbers: " <<endl;
                getline(cin,s_number2);
            }
        }
        number2 = stoi(s_number2);

        // Check if the number is in player 2 available numbers
        bool flag2 = 0;
        while (!flag2) {
            for (int i = 0; i < player2_available_numbers.size(); ++i) {
                if (number2 == player2_available_numbers[i]) {
                    flag2 = 1;
                    break;
                }
            }
            if (!flag2) {
                // Enter the number again and check if valid
                cout << "This number is not available, Please choose a number from your available numbers: " <<endl;
                getline(cin,s_number2);
                flag_s2 = 0;
                while(!flag_s2) {
                    flag_s2 = 1;
                    for (int i = 0; i < s_number2.size(); ++i) {
                        if (s_number2[i] < '0' || s_number2[i] > '9') {
                            flag_s2 = 0;
                            break;
                        }
                    }
                    if(!flag_s){
                        cout << "This input is invalid. Please choose a number from your available numbers: " <<endl;
                        getline(cin,s_number2);
                    }
                }
                number2 = stoi(s_number2);
            }
        }

        // Remove the number from player 2 available numbers
        for (int i = 0; i < player2_available_numbers.size(); ++i) {
            if (number2 == player2_available_numbers[i]) {
                player2_available_numbers.erase(player2_available_numbers.begin() + i);
                break;
            }
        }

        // Enter the row
        int row2;
        row2 = player2_input_row();

        // Enter the column
        int column2;
        column2 = player2_input_column();

        // Check if the index is chosen
        while (board[row2-1][column2-1] != 'X') {
            cout << "This place is chosen before. You have to re enter the row and the column again." <<endl;
            row2 = player2_input_row();
            column2 = player2_input_column();
        }

        // Update the board
        board[row2-1][column2-1] = number2 + '0';

        // Update the counter
        counter++;

        // Check if player 2 won
        int row_sum2 = 0 , column_sum2 = 0 , diagonal_sum3 = 0 ,diagonal_sum4 = 0;
        flag_sum = 1;
        for(int i = 0; i < 3; ++i) {
            if(board[row2-1][i] == 'X') {
                flag_sum = 0;
                continue;
            }
            row_sum2 += board[row2-1][i] - '0';
        }
        if(row_sum2 == 15 && flag_sum){
            // Display the board
            cout << "Now, board became: " << endl;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    cout << setw(5) << board[row][col] << setw(5);
                }
                cout << endl;
            }
            cout << "Player 2 is the winner" <<endl;
            break;
        }
        flag_sum = 1;
        for(int i = 0; i < 3; ++i) {
            if(board[i][column2-1] == 'X') {
                flag_sum = 0;
                continue;
            }
            column_sum2 += board[i][column2-1] - '0';
        }
        if(column_sum2 == 15 && flag_sum){
            // Display the board
            cout << "Now, board became: " << endl;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    cout << setw(5) << board[row][col] << setw(5);
                }
                cout << endl;
            }
            cout << "Player 2 is the winner" <<endl;
            break;
        }
        flag_sum = 1;
        if(row2 + column2 == 2 || row2 + column2 == 4 || row2 + column2 == 6){
            for (int i = 0; i < 3; ++i) {
                if(board[i][i] == 'X') {
                    flag_sum = 0;
                    continue;
                }
                diagonal_sum3 += board[i][i] - '0';
            }
        }
        if(diagonal_sum3 == 15 && flag_sum){
            // Display the board
            cout << "Now, board became: " << endl;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    cout << setw(5) << board[row][col] << setw(5);
                }
                cout << endl;
            }
            cout << "Player 2 is the winner" <<endl;
            break;
        }
        flag_sum = 1;
        if(row2 + column2 == 4){
            int j = 2;
            for (int i = 0; i < 3; ++i) {
                if(board[i][j] == 'X') {
                    continue;
                    flag_sum = 0;
                }
                diagonal_sum4 += board[i][j] - '0';
                j--;
            }
        }
        if(diagonal_sum4 == 15 && flag_sum){
            // Display the board
            cout << "Now, board became: " << endl;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    cout << setw(5) << board[row][col] << setw(5);
                }
                cout << endl;
            }
            cout << "Player 2 is the winner" <<endl;
            break;
        }

        // Check if Draw
        if(counter == 9) {
            // Display the board
            cout << "Now, board became: " << endl;
            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    cout << setw(5) << board[row][col] << setw(5);
                }
                cout << endl;
            }
            cout << "This game is Draw" <<endl;
            break;
        }
    }
    cout << "Thanks for playing my game" <<endl;

    return 0;
}