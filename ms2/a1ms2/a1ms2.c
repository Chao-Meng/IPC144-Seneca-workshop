// #############################################################################################
//  Assignment: 1 
//  Milestone : 2
// #############################################################################################
//  Student Name  : Chao Meng
//  Student ID    : 128438215
//  Student Email :cmeng14@myseneca.ca
//  Course Section: ZAA
// #############################################################################################

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "account.h"                                    // *** DO NOT MODIFY THIS LINE ***
#include "commonHelpers.h"                              // *** DO NOT MODIFY THIS LINE ***

// ------------------------------------------------------------------
// Function Prototypes:
// Confirm MS1 stuff still works and grades can be applied to MS1
void commonHelpersTest(void);                            // *** DO NOT MODIFY THIS LINE ***
// Display Account details                               // *** DO NOT MODIFY THIS PROTOTYPE ***
void displayAccount(const struct Account account, const struct UserLogin login, const struct Person person);
// ------------------------------------------------------------------
// Main entry point to application:

int main(void)
{
    struct Account account = { 0 };                      // *** DO NOT MODIFY THIS LINE ***
    struct Person person = { { 0 } };                    // *** DO NOT MODIFY THIS LINE ***
    struct UserLogin login = { { 0 } };                  // *** DO NOT MODIFY THIS LINE ***

    // Declare other variables you may need here:
    printf("Assignment 1 Milestone 2\n");                          // *** DO NOT MODIFY THIS LINE ***
    printf("=============================================\n\n");   // *** DO NOT MODIFY THIS LINE ***
    // ---------------------------------------------------------
    // Confirm MS1 deliverables; apply grade to MS1 accordingly
    // ---------------------------------------------------------
    commonHelpersTest();                                           // *** DO NOT MODIFY THIS LINE ***

    // ---------------------------------------------------------
    // Account Data: get user input
    // ---------------------------------------------------------
    printf("Account Data Input\n");                                // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n");          // *** DO NOT MODIFY THIS LINE ***
    // Add the necessary code to get user input for each Account member:
    // !!! <STUDENT CODE HERE> !!!
   
    printf("Enter the account number: ");
    account.accountNumber=getInteger();
    printf("Enter the account type (A=Agent | C=Customer): ");
    account.accountType = getCharOption("AC");
    printf("\n");
    // ---------------------------------------------------------
    // Person Data: get user input
    // ---------------------------------------------------------
   printf("Person Data Input\n");                        // *** DO NOT MODIFY THIS LINE ***
   printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***

    // Add the necessary code to get user input for each Person member:
    // NOTE: You will need to get the CURRENT YEAR to devise the appropriate range
    //       when prompting for the birth year data.  There is a function in the 
    //       commonHelpers library that gives you this!
    // !!! <STUDENT CODE HERE> !!!
   printf("Enter the person's full name (30 chars max): ");
   getCString(person.fullName, 0, 30);
   int curYear=currentYear();
   printf("Enter birth year (current age must be between 18 and 110): ");
   person.yearBorn= getIntFromRange(curYear-110, curYear-18);

   printf("Enter the household Income: $");
   person.familyIncome = getPositiveDouble();
 
   printf("Enter the country (30 chars max.): ");
   getCString(person.homeCountry, 0, 30);
   printf("\n");
    // ---------------------------------------------------------
    // UserLogin Data: get user input
    // ---------------------------------------------------------
    printf("User Login Data Input\n");                    // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***
    // Add the necessary code to get user input for each UserLogin member:
    // !!! <STUDENT CODE HERE> !!!
    printf("Enter user login (10 chars max): "); 
    getCString(login.userName, 0, 10);
  
    printf("Enter the password (must be 8 chars in length): ");
    getCString(login.password,8,8);
    // Display all the entered data
    // ---------------------------------------------------------

    // Call function to display the Account record:
    //________________(__________________________________________);
    printf("\n");
    displayAccount(account, login, person);
    printf("\n");
    printf("\nAssignment #1 Milestone #2 completed!\n");  // *** DO NOT MODIFY THIS LINE ***
    return 0; // *** DO NOT MODIFY THIS LINE ***
}

// ------------------------------------------------------------------
// Function definitions:

// Display Account details: Add the missing code!
void displayAccount(const struct Account account, const struct UserLogin login, const struct Person person)
{
    printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
    printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");

    // Display the respective data to align to the table header above:
    // !!! <STUDENT CODE HERE> !!!
    char strA[20] = { 'A','G','E','N','T','\0' };
    char strC[20] = { 'C','U','S','T','O','M','E','R', '\0' };
    char Type[20] = {0};
    
    if (account.accountType == 'A') {
        strcpy(Type, strA);
    }
    if (account.accountType == 'C') {
        strcpy(Type, strC);
    }

    printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s %8s", account.accountNumber,Type,
        person.fullName, person.yearBorn,person.familyIncome, person.homeCountry, login.userName, login.password);
}

// Confirm MS1 stuff still works and grades can be applied to MS1
// *** DO NOT MODIFY THIS FUNCTION DEFINITION ***
void commonHelpersTest(void)
{
    int intValue;
    double dblValue;
    char charValue, cstringValue[7];

    // ---------------------------------------------------------------------
    // TEST #1
    printf("TEST #1 - Instructions:\n"
        "1) Enter the word 'error'  [ENTER]\n"
        "2) Enter the number '-100' [ENTER]\n"
        ":>");
    intValue = getInteger();

    printf("////////////////////////////////////////\n");
    printf("TEST #1 RESULT: ");
    if (intValue == -100)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #2
    printf("TEST #2 - Instructions:\n"
        "1) Enter the number '-100' [ENTER]\n"
        "2) Enter the number '200'  [ENTER]\n"
        ":>");
    intValue = getPositiveInteger();

    printf("////////////////////////////////////////\n");
    printf("TEST #2 RESULT: ");
    if (intValue == 200)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #3
    printf("TEST #3 - Instructions:\n"
        "1) Enter the word 'error' [ENTER]\n"
        "2) Enter the number '-4'  [ENTER]\n"
        "3) Enter the number '12'  [ENTER]\n"
        "4) Enter the number '-3'  [ENTER]\n"
        ":>");
    intValue = getIntFromRange(-3, 11);

    printf("////////////////////////////////////////\n");
    printf("TEST #3 RESULT: ");
    if (intValue == -3)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #4
    printf("TEST #4 - Instructions:\n"
        "1) Enter the number '14' [ENTER]\n"
        ":>");
    intValue = getIntFromRange(-40, 14);

    printf("////////////////////////////////////////\n");
    printf("TEST #4 RESULT: ");
    if (intValue == 14)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #5
    printf("TEST #5 - Instructions:\n"
        "1) Enter the word 'error'     [ENTER]\n"
        "2) Enter the number '-150.75' [ENTER]\n"
        ":>");
    dblValue = getDouble();

    printf("////////////////////////////////////////\n");
    printf("TEST #5 RESULT: ");
    if (dblValue == -150.75)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #6
    printf("TEST #6 - Instructions:\n"
        "1) Enter the number '-22.11' [ENTER]\n"
        "2) Enter the number '225.55' [ENTER]\n"
        ":>");
    dblValue = getPositiveDouble();

    printf("////////////////////////////////////////\n");
    printf("TEST #6 RESULT: ");
    if (dblValue == 225.55)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #7
    printf("TEST #7 - Instructions:\n"
        "1) Enter the character 'R' [ENTER]\n"
        "2) Enter the character 'p' [ENTER]\n"
        "3) Enter the character 'r' [ENTER]\n"
        ":>");
    charValue = getCharOption("qwerty");

    printf("////////////////////////////////////////\n");
    printf("TEST #7 RESULT: ");
    if (charValue == 'r')
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #8
    printf("TEST #8: - Instructions:\n"
        "1) Enter the word 'horse'  [ENTER]\n"
        "2) Enter the word 'SENECA' [ENTER]\n"
        ":>");
    getCString(cstringValue, 6, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #8 RESULT: ");
    printf("%s (Answer: SENECA)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #9
    printf("TEST #9: - Instructions:\n"
        "1) Enter the words 'Seneca College' [ENTER]\n"
        "2) Enter the word 'IPC'             [ENTER]\n"
        ":>");
    getCString(cstringValue, 3, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #9 RESULT: ");
    printf("%s (Answer: IPC)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #10
    printf("TEST #10: - Instructions:\n"
        "1) Enter the word 'ipc'    [ENTER]\n"
        "2) Enter the word 'SCHOOL' [ENTER]\n"
        ":>");
    getCString(cstringValue, 4, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #10 RESULT: ");
    printf("%s (Answer: SCHOOL)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");

}
