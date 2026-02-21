/*
================================================================================
    WITHHOLDING TAX AUTOMATION SYSTEM
    Tax Year: 2024 (Pakistan)
    
    Description: A comprehensive console application for calculating various
                 withholding taxes as per FBR (Federal Board of Revenue) 
                 regulations in Pakistan.
    
    Author: [Your Name]
    Date: January 2026
    Version: 2.0 - Corrected & Enhanced
    
    Features:
    - Salary Tax Calculation (Section 149)
    - Dividend Tax Calculation (Section 150)
    - Cash Withdrawal Tax (Section 231AB)
    - Electricity Consumer Tax (Section 235)
    - Auction Tax Calculation (Section 236A)
    - Complete File Handling for all calculations
    - Professional output formatting
    - Input validation
================================================================================
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
#include <limits>
using namespace std;

// ==================== FUNCTION PROTOTYPES ====================
void showMenu();                    // Display main menu
void showHeader();                  // Display application header
void showFooter();                  // Display footer separator
void calculateSalaryTax();          // Calculate salary tax (Section 149)
void calculateDividendTax();        // Calculate dividend tax (Section 150)
void calculateCashWithdrawalTax();  // Calculate cash withdrawal tax (Section 231AB)
void electricityConsumerTax();      // Calculate electricity consumer tax (Section 235)
void AuctionTax();                  // Calculate auction tax (Section 236A)
double getInput(string prompt);     // Helper function for validated input
int getIntInput(string prompt);     // Helper function for integer input
void clearScreen();                 // Clear console screen
void pause();                       // Pause for user to read output
string getCurrentDateTime();        // Get current date and time

// ==================== MAIN FUNCTION ====================
/*
    Purpose: Entry point of the application
    Flow: Display menu ? Get user choice ? Execute corresponding function
*/
int main() {
    int choice;
    bool running = true;
    
    while(running) {
        clearScreen();
        showHeader();
        showMenu();
        showFooter();
        
        cout << "\n   Enter your choice (1-6): ";
        cin >> choice;

        clearScreen();
        showHeader();
        
        // Execute the selected function based on user choice
        switch (choice) {
            case 1: 
                calculateSalaryTax(); 
                break;
            case 2: 
                calculateDividendTax(); 
                break;
            case 3: 
                calculateCashWithdrawalTax(); 
                break;
            case 4: 
                electricityConsumerTax(); 
                break;
            case 5: 
                AuctionTax(); 
                break;
            case 6: 
                cout << "\n   +------------------------------------------------------------+\n";
                cout << "   |  Thank you for using Tax Automation System!               |\n";
                cout << "   |         Exiting system. Goodbye!                           |\n";
                cout << "   +------------------------------------------------------------+\n\n";
                running = false;
                break;
            default: 
                cout << "\n   +------------------------------------------------------------+\n";
                cout << "   |      ? ERROR: Invalid choice!                             |\n";
                cout << "   |      Please select a number between 1-6                    |\n";
                cout << "   +------------------------------------------------------------+\n\n";
                pause();
        }
    }
    
    return 0;
}

// ==================== UTILITY FUNCTIONS ====================

/*
    Function: showHeader
    Purpose: Display professional application header with branding
*/
void showHeader() {
    cout << "\n";
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |                                                            |\n";
    cout << "   |       ?? WITHHOLDING TAX AUTOMATION SYSTEM ??              |\n";
    cout << "   |              Tax Year 2024 - Pakistan                      |\n";
    cout << "   |         Federal Board of Revenue (FBR) Compliant           |\n";
    cout << "   |                                                            |\n";
    cout << "   +------------------------------------------------------------+\n\n";
}

/*
    Function: showMenu
    Purpose: Display main menu with all available tax calculation options
            Shows section numbers for legal reference
*/
void showMenu() {
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |                      MAIN MENU                             |\n";
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |                                                            |\n";
    cout << "   |   1. ?? Salary Tax (Section 149)                          |\n";
    cout << "   |      Calculate annual and monthly salary tax               |\n";
    cout << "   |                                                            |\n";
    cout << "   |   2. ?? Dividend Tax (Section 150)                        |\n";
    cout << "   |      Calculate tax on dividend income                      |\n";
    cout << "   |                                                            |\n";
    cout << "   |   3. ?? Cash Withdrawal Tax (Section 231AB)               |\n";
    cout << "   |      Calculate tax on bank withdrawals                     |\n";
    cout << "   |                                                            |\n";
    cout << "   |   4. ? Electricity Consumer Tax (Section 235)            |\n";
    cout << "   |      Calculate tax on electricity bills                    |\n";
    cout << "   |                                                            |\n";
    cout << "   |   5. ?? Auction Tax (Section 236A)                        |\n";
    cout << "   |      Calculate tax on auction purchases                    |\n";
    cout << "   |                                                            |\n";
    cout << "   |   6. ?? Exit                                               |\n";
    cout << "   |      Close the application                                 |\n";
    cout << "   |                                                            |\n";
    cout << "   +------------------------------------------------------------+\n";
}

/*
    Function: showFooter
    Purpose: Display decorative footer line
*/
void showFooter() {
    cout << "   ------------------------------------------------------------\n";
}

/*
    Function: clearScreen
    Purpose: Clear the console screen for better readability
*/
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear"); // Linux/Mac
    #endif
}

/*
    Function: pause
    Purpose: Pause execution and wait for user input
*/
void pause() {
    cout << "\n   Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

/*
    Function: getInput
    Purpose: Get numeric input from user with validation
    Parameters: 
        - prompt: Message to display to user
    Returns: Double value entered by user (non-negative)
*/
double getInput(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // remove extra input
            return value;
        } else {
            cout << "Invalid input! Enter a non-negative number.\n";
            cin.clear(); // clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        }
    }
}

/*
    Function: getIntInput
    Purpose: Get integer input from user with validation
    Parameters: 
        - prompt: Message to display to user
    Returns: Integer value entered by user
*/
int getIntInput(string prompt) {
    int value;
    while(true) {
        cout << "   " << prompt;
        cin >> value;
        
        if(cin.fail()) {
            cout << "   ? Invalid input! Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

/*
    Function: getCurrentDateTime
    Purpose: Get current date and time as a string
    Returns: String containing formatted date and time
*/
string getCurrentDateTime() {
    time_t now = time(0);
    char buffer[80];
    struct tm *timeinfo = localtime(&now);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    return string(buffer);
}

// ==================== TAX CALCULATION FUNCTIONS ====================

/*
    Function: calculateSalaryTax
    Purpose: Calculate income tax based on progressive tax slabs
    Section: 149 of Income Tax Ordinance, 2001
    
    Tax Slabs (TY 2024):
    - Up to 600,000: 0%
    - 600,001 to 1,200,000: 2.5%
    - 1,200,001 to 2,400,000: 12.5%
    - 2,400,001 to 3,600,000: 22.5%
    - Above 3,600,000: 27.5%
*/
void calculateSalaryTax() {
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |           SALARY TAX CALCULATOR (Section 149)              |\n";
    cout << "   +------------------------------------------------------------+\n\n";
    
    // Get annual income from user with validation
    double income = getInput("Enter Annual Income (PKR): ");
    
    double tax = 0;
    
    // Calculate tax based on progressive slabs
    if (income <= 600000) {
        tax = 0;  // Tax-free up to 600,000
    }
    else if (income <= 1200000) {
        tax = (income - 600000) * 0.025;  // 2.5% on amount above 600,000
    }
    else if (income <= 2400000) {
        tax = 15000 + (income - 1200000) * 0.125;  // Fixed 15k + 12.5%
    }
    else if (income <= 3600000) {
        tax = 165000 + (income - 2400000) * 0.225;  // Fixed 165k + 22.5%
    }
    else {
        tax = 435000 + (income - 3600000) * 0.275;  // Fixed 435k + 27.5%
    }
    
    // Display results with proper formatting
    cout << fixed << setprecision(2);
    cout << "\n   +------------------------------------------------------------+\n";
    cout << "   |                    CALCULATION RESULTS                     |\n";
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |  Annual Income:        PKR " << setw(15) << income << "                |\n";
    cout << "   |  Annual Tax:           PKR " << setw(15) << tax << "                |\n";
    cout << "   |  Monthly Tax:          PKR " << setw(15) << tax / 12 << "                |\n";
    cout << "   |  Net Annual Income:    PKR " << setw(15) << income - tax << "                |\n";
    cout << "   +------------------------------------------------------------+\n";
    
    // Save to file
    ofstream outfile("salaryTax.txt", ios::app);
    if(outfile.is_open()) {
        outfile << "\n========== SALARY TAX CALCULATION ==========\n";
        outfile << "Date & Time: " << getCurrentDateTime() << "\n";
        outfile << "Annual Income (PKR): " << fixed << setprecision(2) << income << "\n";
        outfile << "Annual Tax (PKR): " << tax << "\n";
        outfile << "Monthly Tax (PKR): " << tax / 12 << "\n";
        outfile << "Net Annual Income (PKR): " << income - tax << "\n";
        outfile << "============================================\n";
        outfile.close();
        cout << "\n   ? Results saved to salaryTax.txt\n";
    } else {
        cout << "\n   ? Warning: Unable to save results to file\n";
    }
    
    pause();
}

/*
    Function: calculateDividendTax
    Purpose: Calculate withholding tax on dividend income
    Section: 150 of Income Tax Ordinance, 2001
    
    Tax Rates:
    - Filers: 15%
    - Non-Filers: 30%
*/
void calculateDividendTax() {
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |          DIVIDEND TAX CALCULATOR (Section 150)             |\n";
    cout << "   +------------------------------------------------------------+\n\n";
    
    // Get dividend amount with validation
    double amount = getInput("Enter Dividend Amount (PKR): ");
    
    // Check filer status with validation
    int filer = getIntInput("Are you a Filer? (1=Yes, 0=No): ");
    while(filer != 0 && filer != 1) {
        cout << "   ? Invalid input! Please enter 0 or 1.\n";
        filer = getIntInput("Are you a Filer? (1=Yes, 0=No): ");
    }
    
    // Determine tax rate based on filer status
    double rate = filer ? 0.15 : 0.30;  // 15% for filers, 30% for non-filers
    double tax = amount * rate;
    
    // Display results
    cout << fixed << setprecision(2);
    cout << "\n   +------------------------------------------------------------+\n";
    cout << "   |                    CALCULATION RESULTS                     |\n";
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |  Status:               " << setw(30) << left << (filer ? "Filer (15%)" : "Non-Filer (30%)") << right << "     |\n";
    cout << "   |  Gross Dividend:       PKR " << setw(15) << amount << "                |\n";
    cout << "   |  Tax Deducted:         PKR " << setw(15) << tax << "                |\n";
    cout << "   |  Net Amount Received:  PKR " << setw(15) << amount - tax << "                |\n";
    cout << "   +------------------------------------------------------------+\n";
    
    // Save to file
    ofstream outfile("dividendTax.txt", ios::app);
    if(outfile.is_open()) {
        outfile << "\n========== DIVIDEND TAX CALCULATION ==========\n";
        outfile << "Date & Time: " << getCurrentDateTime() << "\n";
        outfile << "Filer Status: " << (filer ? "Filer" : "Non-Filer") << "\n";
        outfile << "Tax Rate: " << (rate * 100) << "%\n";
        outfile << "Gross Dividend (PKR): " << fixed << setprecision(2) << amount << "\n";
        outfile << "Tax Deducted (PKR): " << tax << "\n";
        outfile << "Net Amount Received (PKR): " << amount - tax << "\n";
        outfile << "==============================================\n";
        outfile.close();
        cout << "\n   ? Results saved to dividendTax.txt\n";
    } else {
        cout << "\n   ? Warning: Unable to save results to file\n";
    }
    
    pause();
}

/*
    Function: calculateCashWithdrawalTax
    Purpose: Calculate tax on cash withdrawals from bank
    Section: 231AB of Income Tax Ordinance, 2001
    
    Rules:
    - Non-Filers: 0.6% tax on withdrawals exceeding PKR 50,000
    - Filers: Exempt from this tax
*/
void calculateCashWithdrawalTax() {
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |      CASH WITHDRAWAL TAX CALCULATOR (Section 231AB)        |\n";
    cout << "   +------------------------------------------------------------+\n\n";
    
    // Get withdrawal amount with validation
    double amount = getInput("Enter Withdrawal Amount (PKR): ");
    
    // Check filer status with validation
    int filer = getIntInput("Are you a Filer? (1=Yes, 0=No): ");
    while(filer != 0 && filer != 1) {
        cout << "   ? Invalid input! Please enter 0 or 1.\n";
        filer = getIntInput("Are you a Filer? (1=Yes, 0=No): ");
    }
    
    double tax = 0;
    
    // Tax only applies to non-filers on amounts above 50,000
    if (!filer && amount > 50000) {
        tax = amount * 0.006;  // 0.6% tax rate
    }
    
    // Display results
    cout << fixed << setprecision(2);
    cout << "\n   +------------------------------------------------------------+\n";
    cout << "   |                    CALCULATION RESULTS                     |\n";
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |  Status:               " << setw(30) << left << (filer ? "Filer (Exempt)" : "Non-Filer (0.6%)") << right << "     |\n";
    cout << "   |  Withdrawal Amount:    PKR " << setw(15) << amount << "                |\n";
    cout << "   |  Tax Deduction:        PKR " << setw(15) << tax << "                |\n";
    cout << "   |  Net Amount:           PKR " << setw(15) << amount - tax << "                |\n";
    
    // Show additional information for non-filers
    if (!filer && amount <= 50000) {
        cout << "   |                                                            |\n";
        cout << "   |  ??  Note: No tax on withdrawals up to PKR 50,000         |\n";
    }
    
    cout << "   +------------------------------------------------------------+\n";
    
    // Save to file
    ofstream outfile("cashWithdrawalTax.txt", ios::app);
    if(outfile.is_open()) {
        outfile << "\n========== CASH WITHDRAWAL TAX CALCULATION ==========\n";
        outfile << "Date & Time: " << getCurrentDateTime() << "\n";
        outfile << "Filer Status: " << (filer ? "Filer" : "Non-Filer") << "\n";
        outfile << "Withdrawal Amount (PKR): " << fixed << setprecision(2) << amount << "\n";
        outfile << "Tax Deduction (PKR): " << tax << "\n";
        outfile << "Net Amount (PKR): " << amount - tax << "\n";
        if (!filer && amount <= 50000) {
            outfile << "Note: No tax on withdrawals up to PKR 50,000\n";
        }
        outfile << "=====================================================\n";
        outfile.close();
        cout << "\n   ? Results saved to cashWithdrawalTax.txt\n";
    } else {
        cout << "\n   ? Warning: Unable to save results to file\n";
    }
    
    pause();
}

/*
    Function: electricityConsumerTax
    Purpose: Calculate additional tax on high electricity consumption
    Section: 235 of Income Tax Ordinance, 2001
    
    Tax Rate:
    - 7.5% on monthly bills exceeding PKR 25,000
    - No tax on bills up to PKR 25,000
*/
void electricityConsumerTax() {
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |    ELECTRICITY CONSUMER TAX CALCULATOR (Section 235)       |\n";
    cout << "   +------------------------------------------------------------+\n\n";
    
    // Get monthly electricity bill amount with validation
    double bill = getInput("Enter Monthly Electricity Bill (PKR): ");
    
    // Calculate tax: 7.5% if bill exceeds 25,000, otherwise 0
    double tax = (bill > 25000) ? bill * 0.075 : 0;
    
    // Display results
    cout << fixed << setprecision(2);
    cout << "\n   +------------------------------------------------------------+\n";
    cout << "   |                    CALCULATION RESULTS                     |\n";
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |  Monthly Bill:         PKR " << setw(15) << bill << "                |\n";
    cout << "   |  Tax Rate:             " << setw(30) << left << (bill > 25000 ? "7.5%" : "0% (Below threshold)") << right << "     |\n";
    cout << "   |  Monthly Tax:          PKR " << setw(15) << tax << "                |\n";
    cout << "   |  Total Payable:        PKR " << setw(15) << bill + tax << "                |\n";
    
    // Show threshold information
    if (bill <= 25000) {
        cout << "   |                                                            |\n";
        cout << "   |  ??  Note: No tax on bills up to PKR 25,000               |\n";
    }
    
    cout << "   +------------------------------------------------------------+\n";
    
    // Save to file
    ofstream outfile("electricityConsumerTax.txt", ios::app);
    if(outfile.is_open()) {
        outfile << "\n========== ELECTRICITY CONSUMER TAX CALCULATION ==========\n";
        outfile << "Date & Time: " << getCurrentDateTime() << "\n";
        outfile << "Monthly Bill (PKR): " << fixed << setprecision(2) << bill << "\n";
        outfile << "Tax Rate: " << (bill > 25000 ? "7.5%" : "0% (Below threshold)") << "\n";
        outfile << "Monthly Tax (PKR): " << tax << "\n";
        outfile << "Total Payable (PKR): " << bill + tax << "\n";
        if (bill <= 25000) {
            outfile << "Note: No tax on bills up to PKR 25,000\n";
        }
        outfile << "==========================================================\n";
        outfile.close();
        cout << "\n   ? Results saved to electricityConsumerTax.txt\n";
    } else {
        cout << "\n   ? Warning: Unable to save results to file\n";
    }
    
    pause();
}

/*
    Function: AuctionTax
    Purpose: Calculate withholding tax on auction purchases
    Section: 236A of Income Tax Ordinance, 2001
    
    Tax Rates by Property Type:
    1. Moveable Property:
       - Filers: 10%
       - Non-Filers: 20%
    
    2. Immovable Property:
       - Filers: 5%
       - Non-Filers: 10%
    
    3. Lease/Toll Rights:
       - Filers: 10%
       - Non-Filers: 20%
*/
void AuctionTax() {
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |         AUCTION TAX CALCULATOR (Section 236A)              |\n";
    cout << "   +------------------------------------------------------------+\n\n";
    
    // Get auction amount with validation
    double amount = getInput("Enter Auction Amount (PKR): ");
    
    // Display property type menu
    cout << "\n   +------------------------------------------------------------+\n";
    cout << "   |              SELECT PROPERTY TYPE                          |\n";
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |  1. Moveable Property (Vehicles, Machinery, etc.)          |\n";
    cout << "   |  2. Immovable Property (Land, Buildings, etc.)             |\n";
    cout << "   |  3. Lease / Toll Rights                                    |\n";
    cout << "   +------------------------------------------------------------+\n";
    
    int choice = getIntInput("\n   Select Property Type (1-3): ");
    while(choice < 1 || choice > 3) {
        cout << "   ? Invalid choice! Please select 1, 2, or 3.\n";
        choice = getIntInput("   Select Property Type (1-3): ");
    }
    
    // Check filer status with validation
    int filer = getIntInput("   Are you a Filer? (1=Yes, 0=No): ");
    while(filer != 0 && filer != 1) {
        cout << "   ? Invalid input! Please enter 0 or 1.\n";
        filer = getIntInput("   Are you a Filer? (1=Yes, 0=No): ");
    }
    
    string propertyType;
    double rate = 0;
    
    // Determine tax rate based on property type and filer status
    if (choice == 1) {
        rate = filer ? 0.10 : 0.20;  // 10% for filers, 20% for non-filers
        propertyType = "Moveable Property";
    }
    else if (choice == 2) {
        rate = filer ? 0.05 : 0.10;  // 5% for filers, 10% for non-filers
        propertyType = "Immovable Property";
    }
    else if (choice == 3) {
        rate = filer ? 0.10 : 0.20;  // 10% for filers, 20% for non-filers
        propertyType = "Lease/Toll Rights";
    }
    
    // Calculate auction tax
    double tax = amount * rate;
    
    // Display results
    cout << fixed << setprecision(2);
    cout << "\n   +------------------------------------------------------------+\n";
    cout << "   |                    CALCULATION RESULTS                     |\n";
    cout << "   +------------------------------------------------------------+\n";
    cout << "   |  Property Type:        " << setw(30) << left << propertyType << right << "     |\n";
    cout << "   |  Filer Status:         " << setw(30) << left << (filer ? "Filer" : "Non-Filer") << right << "     |\n";
    cout << "   |  Tax Rate:             " << setw(30) << left << (rate * 100) << "%" << right << "     |\n";
    cout << "   |  Auction Amount:       PKR " << setw(15) << amount << "                |\n";
    cout << "   |  Auction Tax:          PKR " << setw(15) << tax << "                |\n";
    cout << "   |  Total Payment:        PKR " << setw(15) << amount + tax << "                |\n";
    cout << "   +------------------------------------------------------------+\n";
    
    // Save to file
    ofstream outfile("auctionTax.txt", ios::app);
    if(outfile.is_open()) {
        outfile << "\n========== AUCTION TAX CALCULATION ==========\n";
        outfile << "Date & Time: " << getCurrentDateTime() << "\n";
        outfile << "Property Type: " << propertyType << "\n";
        outfile << "Filer Status: " << (filer ? "Filer" : "Non-Filer") << "\n";
        outfile << "Tax Rate: " << (rate * 100) << "%\n";
        outfile << "Auction Amount (PKR): " << fixed << setprecision(2) << amount << "\n";
        outfile << "Auction Tax (PKR): " << tax << "\n";
        outfile << "Total Payment (PKR): " << amount + tax << "\n";
        outfile << "=============================================\n";
        outfile.close();
        cout << "\n   ? Results saved to auctionTax.txt\n";
    } else {
        cout << "\n   ? Warning: Unable to save results to file\n";
    }
    
    pause();
}

/*
================================================================================
    END OF WITHHOLDING TAX AUTOMATION SYSTEM
    
    Version 2.0 Improvements:
    - Complete file handling for all tax calculation functions
    - Proper input validation with error handling
    - Professional output formatting with consistent borders
    - Date/time stamps in all saved records
    - Append mode for file operations (preserves history)
    - Fixed logical errors in filer status validation
    - Fixed character encoding issues in output
    - Improved user experience with better error messages
    
    Notes:
    - All tax rates and slabs are as per FBR regulations for TY 2024
    - Filer status significantly impacts tax rates
    - Regular updates needed when FBR changes tax policies
    - All calculations are saved with timestamps for record-keeping
    
    Future Enhancements:
    - Generate tax reports in PDF format
    - Add multi-user support with login system
    - Include tax payment challan generation
    - Add yearly tax summary feature
    - Database integration for better data management
================================================================================
*/
