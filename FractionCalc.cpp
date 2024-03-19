// FCAI – Structured Programming – 2024 - Assignment 2
// Program Name: CS112_A2_T3_S18_20230021_20230444_20230083.cpp
// Program Description: Fraction Calculator (summation , subtraction , division and multiplication)
// Last Modification Date: 18/3/2024
// Author1 and ID and Group: Ahmed Sayed Ahmed 20230021 [S17,S18]
// Author2 and ID and Group: Noureldin Mohamed Amin 20230444 [S17,S18]
// Author3 and ID and Group: Ayman Mohamed Emam 20230083 [S17,S18]
// Teaching Assistant: Eng.Ahmed Lotfy
// Who did what ==>
// Menu , validation and summation function functions made by [Ahmed Sayed Ahmed 20230021]
// subtract function made by [Ayman Mohamed Emam 20230083]
// Menu , validation and (division , multiply functions) made by [Noureldin Mohamed Amin 20230444]

// PDF on drive: https://drive.google.com/file/d/1rOwBDXefXiNqGxdrEa7iwBas1Qyp1Im5/view?usp=drive_link

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Function to do multiplication
void multiply (ll num1 , ll den1 , ll num2 , ll den2)
{
    // Multiply the first numerator by the second numerator
    ll mnum = num1 * num2;

    // Multiply the first denominator by the second denominator
    ll mden = den1 * den2;

    // If both the numerator and denominator are negative make the result positive
    if(mnum < 0 && mden < 0){
        mnum = abs(mnum);
        mden = abs(mden);
    }

    // Simplify the result
    while (mnum % 2 == 0 && mden % 2 == 0)
    {
        mnum/=2;
        mden/=2;
    }
    while (mnum % 3 == 0 && mden % 3 == 0)
    {
        mnum/=3;
        mden/=3;
    }
    while (mnum % 5 == 0 && mden % 5 == 0)
    {
        mnum/=5;
        mden/=5;
    }

    // Make the negative sign in the numerator
    if (mden < 0 && mnum > 0)
    {
        mden*=-1;
        mnum*=-1;
    }

    // If the denominator is 1 print the numerator only
    if (mden == 1)
        cout << "The result = " << mnum <<endl;
    else
        cout << "The result = " << mnum << "/" << mden <<endl;
}

// Function to do division
void division(ll num1 , ll den1 , ll num2 , ll den2)
{
    // Multiply the first numerator by the second denominator
    ll mnum = num1 * den2;

    // Multiply the second numerator by the first denominator
    ll mden = den1 * num2;

    // If both the numerator and denominator are negative make the result positive
    if(mnum < 0 && mden < 0){
        mnum = abs(mnum);
        mden = abs(mden);
    }

    // Simplify the result
    while (mnum % 2 == 0 && mden % 2 == 0)
    {
        mnum/=2;
        mden/=2;
    }
    while (mnum % 3 == 0 && mden % 3 == 0)
    {
        mnum/=3;
        mden/=3;
    }
    while (mnum % 5 == 0 && mden % 5 == 0)
    {
        mnum/=5;
        mden/=5;
    }

    // Make the negative sign in the numerator
    if (mden < 0 && mnum > 0)
    {
        mden*=-1;
        mnum*=-1;
    }

    // If the denominator is 1 print the numerator only
    if (mden == 1)
        cout << "The result = " << mnum <<endl;
    else
        cout << "The result = " << mnum << "/" << mden <<endl;
}

// Function to do summation
void summation(ll num1 , ll den1 , ll num2 , ll den2)
{
    // Calculate the numerator of the summation
    ll num = (num1 * den2) + (num2 * den1);

    // Calculate the denominator of the summation
    ll den = den1 * den2;

    // Simplify the result
    while (num % 2 == 0 && den % 2 == 0)
    {
        num/=2;
        den/=2;
    }
    while (num % 3 == 0 && den % 3 == 0)
    {
        num/=3;
        den/=3;
    }
    while (num % 5 == 0 && den % 5 == 0)
    {
        num/=5;
        den/=5;
    }

    // Make the negative sign in the numerator
    if (den < 0 && num > 0)
    {
        den*=-1;
        num*=-1;
    }

    // If the denominator is 1 print the numerator only
    if (den == 1)
        cout << "The result = " << num <<endl;
    else
        cout << "The result = " << num << "/" << den <<endl;
}

// Function to do subtraction
void subtract(ll num1 , ll den1 , ll num2 , ll den2)
{
    // Calculate the numerator of the summation
    ll num = (num1 * den2) - (num2 * den1);

    // Calculate the denominator of the summation
    ll den = den1 * den2;

    // Simplify the result
    while (num % 2 == 0 && den % 2 == 0)
    {
        num/=2;
        den/=2;
    }
    while (num % 3 == 0 && den % 3 == 0)
    {
        num/=3;
        den/=3;
    }
    while (num % 5 == 0 && den % 5 == 0)
    {
        num/=5;
        den/=5;
    }

    // Make the negative sign in the numerator
    if (den < 0 && num > 0)
    {
        den*=-1;
        num*=-1;
    }

    // If the denominator is 1 print the numerator only
    if (den == 1)
        cout << "The result = " << num <<endl;
    else
        cout << "The result = " << num << "/" << den <<endl;
}

int main()
{
    // Print a welcome message and the notes
    cout << "Welcome to fraction calculator app." <<endl;
    string opr;
    int den1 , den2 , num1 , num2;
    string dens1 = "" , dens2 = "" , nums1 = "" , nums2 = "";
    char operation;
    while (true) {
        cout << "Note 1: your operation must be written as one of these formats." <<endl;
        cout << "1) a/b \"Space\" (*-+/) \"Space\" c/d." <<endl;
        cout << "2) a \"Space\" (*-+/) \"Space\" c/d." <<endl;
        cout << "3) a/b \"Space\" (*-+/) \"Space\" c." <<endl;
        cout << "4) a \"Space\" (*-+/) \"Space\" c." <<endl;
        cout << "Note 2: b and d can not be 0." <<endl;
        cout << "Please enter a rational number operations in one of the previous formats (or exit):" << endl;
        getline(cin, opr);

        // if the input is "exit" in any case (upper characters or lower) end the program
        if (regex_match(opr, regex("exit", regex_constants::icase)))
        {
            cout << "Thank you for using our app." <<endl;
            return 0;
        }

        // Check if the matches with the notes or not, if matches continue and if not ask the user again
        else if (!regex_match(opr, regex("[-+]?[0-9]+(/[+-]?[0-9]+)?[ ][+-/*]?[ ][-+]?[0-9]+(/[+-]?[0-9]+)?")))
        {
            cout << "Please follow the notes." <<endl;
            continue;
        }

        bool notfrac = 0;
        // while character not equal '/' add it to the first numerator
        while (opr[0] != '/') {
            // If the character equal space that means that it is not a fraction
            if(opr[0] == ' ') {
                notfrac = 1;
                break;
            }
            nums1 += opr[0];
            opr.erase(opr.begin());
        }
        // convert the first numerator from string to long long
        num1 = stoll(nums1);
        nums1 = "";
        opr.erase(opr.begin());

        // If it not a fraction
        if(!notfrac) {
            // While it not a space add it to the first denominator
            while (!isspace(opr[0])) {
                dens1 += opr[0];
                opr.erase(opr.begin());
            }
            // convert the first denominator from string to long long
            den1 = stoll(dens1);
            // if the first denominator is 0, print an error message and ask user again
            if (den1 == 0) {
                cout << "The denominator can not equal 0." << endl;
                continue;
            }
            dens1 = "";
            opr.erase(opr.begin());
        // if it is a fraction make the first denominator equal 1
        }else
            den1 = 1;

        // Extract the operation from the equation
        operation = opr[0];
        opr.erase(opr.begin());
        opr.erase(opr.begin());
        notfrac = 0;

        // while character not equal '/' add it to the second numerator
        while (opr[0] != '/') {
            // if the size of the string equals 1 that means that it is not a fraction
            if(1 == opr.size()) {
                nums2 += opr[0];
                notfrac = 1;
                break;
            }
            nums2 += opr[0];
            opr.erase(opr.begin());
        }
        // convert the second numerator from string to long long
        num2 = stoll(nums2);
        // if the second numerator is 0 and the operation is division, print and error message and ask the user again
        if (num2 == 0 && operation == '/')
        {
            cout << "You can not divide by 0." <<endl;
            continue;
        }
        nums2 = "";
        opr.erase(opr.begin());

        // if it is a fraction
        if(!notfrac) {
            // While the size of the string greater than 0, add it to the second denominator
            while (opr.size() > 0) {
                dens2 += opr[0];
                opr.erase(opr.begin());
            }
            // convert the second denominator from string to long long
            den2 = stoll(dens2);
            // if the second denominator is 0 print an error message and ask user again
            if (den2 == 0) {
                cout << "The denominator can not equal 0." << endl;
                continue;
            }
            dens2 = "";
        // if it is a fraction, make the second denominator equal 1
        }else
            den2 = 1;

        // determine the operation and call its function
        if (operation == '*') {
            multiply(num1, den1, num2, den2);
        }
        else if (operation == '/')
        {
            division(num1, den1, num2, den2);
        }
        else if (operation == '+')
        {
            summation(num1, den1, num2, den2);
        }
        else if (operation == '-')
        {
            subtract(num1, den1, num2, den2);
        }
    }
}
