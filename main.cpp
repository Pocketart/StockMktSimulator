/*
 * 03/23/2017 6:32PM
 * Console Trader 1.0
 *
 * This program has been written as a submission for the APCSP 'Create' PT
 *
 * By: Shaun Hoseong Cheon
 * Contact: shauncheon@shauncheon.com
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;
int main(void)

{
    // Initialize Variables
    int Days; // Days counter: Market will update on a daily basis
    int DaysChange; // Days counter buffer variable
    int StartingCash; // Starting amount of cash, decided by difficulty factor
    int Level; // Stage level
    int Difficulty; // Difficulty factor as selected by user
    int Age; // User profile
    int Firms; // Number of firms offering shares (increases by 3 per increment in Level)
    int Target; // Target Balance to reach to advance to next level
    int LoanAge; // Days since last bank loan
    int DepositAge; // Age of bank deposit in days (resets when any value is withdrawn)
    int Input; // Stores user int input for interaction
    double DoubleIn; // Stores user double input for interaction
    string Name; // User profile
    double BankMax; // Max Amount of Money that can be borrowed at a given point in time
    double Balance; // User balance in cash
    double BankBalance; // User balance in bank
    double LoanLimit;
    double IntRate; // Bank deposit interest rate
    double LoanOutRate; // Loan out return rate
    double PortfolioValue; // The total value of all the user's market holdings
    double TransferRate; // Transfer Payment Rate for buying/selling shares
    double LevelDiffMult; // Variable by level, affects stock market dynamo

    // Create Random
    unsigned seed = time(0);
    srand(seed);

    // Welcome Screen & Game Setup
    cout << "Welcome to Console Trader 1.0 by Shaun 'Hoseong' Cheon!" << endl << endl;
    cout << "This is a simple stock market simulator game." << endl;
    cout << "Lets begin by setting up your profile:" << endl;
    cout << "What is your name?" << endl;
    getline(cin, Name);
    cout << "Well hello " << Name << ", what is your age?" << endl;
    cin >> Age;

    cout << "How difficult would you like the game to be? (select a number)" << endl;
    cout << "1 <----- Easy (Banks do not charge interest rates, relatively stable markets)" << endl;
    cout << "2 <----- Normal (Banks charge interest rates, relatively volatile markets)" << endl;
    cout << "3 <----- Hard (Banks charge high rates, volatile markets, high transaction price)" << endl;
    cout << "4 <----- Advanced (Hard difficulty + spontaneous government policies + inflation)" << endl;
    cin >> Difficulty;

    while (Difficulty < 1 || Difficulty > 4)
    {
        cout << "That is not a valid selection, please choose either one of the 4 given choices\n" << endl;
        cout << "1 <----- Easy (Banks do not charge interest rates, relatively stable markets)" << endl;
        cout << "2 <----- Normal (Banks charge interest rates, relatively volatile markets)" << endl;
        cout << "3 <----- Hard (Banks charge high rates, volatile markets, high transaction price)" << endl;
        cout << "4 <----- Advanced (Hard difficulty + spontaneous government policies + inflation)" << endl;
        cin >> Difficulty;
    }

    cout << "Ok " << Name << ", so you are a " << Age << " year old living on the Internet." << endl;
    cout << "You have just discovered the stock market, and you believe its a viable way" << endl;
    cout << "to earn big bucks. You will now be trading on the console trader with all" << endl;
    cout << "your money. But before you start trading, let me walk you through the tutorial." << endl;
    cout << "\nPress [ENTER] to continue" << endl;
    cin.get();
    cin.get();

    cout << "\nThis is what the menu looks like:\n" << endl;
    cout << "1 - Market" << endl;
    cout << "2 - Bank" << endl;
    cout << "3 - Stats" << endl;
    cout << "4 - Next Day" << endl;
    cout << "5 - Next Week" << endl;
    cout << "6 - Exit (end tutorial and start game)" << endl;
    cout << "Enter a valid menu number to learn how to use the underlying functions\n" << endl;
    cin >> Input;


    while (Input != 6)
    {
        while (Input < 1 || Input > 6)
        {
            cout << "\n\nHere are the menu selections:\n" << endl;
            cout << "1 - Market" << endl;
            cout << "2 - Bank" << endl;
            cout << "3 - Stats" << endl;
            cout << "4 - One Day Forward" << endl;
            cout << "5 - One Week Forward" << endl;
            cout << "6 - Exit (end tutorial and start game)" << endl;
            cin >> Input;
        }

        if (Input == 1)
        {
            cout << "Here you can view the market price of the available shares" << endl;
            cout << "After you select an option, you can choose to buy or sell\n" << endl;
            cout << "1 - Firm01 - $" << "10" << endl;
            cout << "2 - Firm02 - $" << "12" << endl;
            cout << "3 - Firm03 - $" << "5" << endl;
            cout << "4 - Firm04 - $" << "4" << endl;
            cout << "5 - Back" << endl;

            cin >> Input;

            while (Input < 1 || Input > 5)
            {
                cout << "Enter a valid menu selection" << endl;
                cout << "Try again: ";
                cin >> Input;
            }

            if (Input == 1)
            {
                cout << "Selected firm: Firm01" << endl;
                cout << "You own 7 shares" << endl;
                cout << "Press 1 to sell, Press 2 to buy, Press 3 to cancel" << endl;
                cin >> Input;
                while (Input < 1 || Input > 3)
                {
                    cout << "Enter a valid menu selection" << endl;
                    cout << "Try again: ";
                    cin >> Input;
                }

                if (Input == 1)
                {
                    cout << "How many shares would you like to sell?" << endl;
                    cin >> Input;
                    cout << "You sold " << Input << " shares for Price x Num" << endl;
                    Input = 0;
                }
                else if (Input == 2)
                {
                    cout << "How many shares would you like to buy?" << endl;
                    cin >> Input;
                    cout << "You bought " << Input << " shares for Price x Num" << endl;
                    Input = 0;
                }
                else if (Input == 3)
                {
                    cout << "Transaction successfully cancelled." << endl;
                    Input = 0;
                }
            }
            else if (Input == 2)
            {
                cout << "Selected firm: Firm02" << endl;
                cout << "You own 18 shares" << endl;
                cout << "Press 1 to sell, Press 2 to buy, Press 3 to cancel" << endl;
                cin >> Input;
                while (Input < 1 || Input > 3)
                {
                    cout << "Enter a valid menu selection" << endl;
                    cout << "Try again: ";
                    cin >> Input;
                }

                if (Input == 1)
                {
                    cout << "How many shares would you like to sell?" << endl;
                    cin >> Input;
                    cout << "You sold " << Input << " shares for Price x Num" << endl;
                    Input = 0;
                }
                else if (Input == 2)
                {
                    cout << "How many shares would you like to buy?" << endl;
                    cin >> Input;
                    cout << "You bought " << Input << " shares for Price x Num" << endl;
                    Input = 0;
                }
                else if (Input == 3)
                {
                    cout << "Transaction successfully cancelled." << endl;
                    Input = 0;
                }
            }
            else if (Input == 3)
            {
                cout << "Selected firm: Firm03" << endl;
                cout << "You own 0 shares" << endl;
                cout << "Press 1 to sell, Press 2 to buy, Press 3 to cancel" << endl;
                cin >> Input;
                while (Input < 1 || Input > 3)
                {
                    cout << "Enter a valid menu selection" << endl;
                    cout << "Try again: ";
                    cin >> Input;
                }

                if (Input == 1)
                {
                    cout << "How many shares would you like to sell?" << endl;
                    cin >> Input;
                    cout << "You sold " << Input << " shares for Price x Num" << endl;
                    Input = 0;
                }
                else if (Input == 2)
                {
                    cout << "How many shares would you like to buy?" << endl;
                    cin >> Input;
                    cout << "You bought " << Input << " shares for Price x Num" << endl;
                    Input = 0;
                }
                else if (Input == 3)
                {
                    cout << "Transaction successfully cancelled." << endl;
                    Input = 0;
                }
            }
            else if (Input == 4)
            {
                cout << "Selected firm: Firm04" << endl;
                cout << "You own 2 shares" << endl;
                cout << "Press 1 to sell, Press 2 to buy, Press 3 to cancel" << endl;
                cin >> Input;
                while (Input < 1 || Input > 3)
                {
                    cout << "Enter a valid menu selection" << endl;
                    cout << "Try again: ";
                    cin >> Input;
                }

                if (Input == 1)
                {
                    cout << "How many shares would you like to sell?" << endl;
                    cin >> Input;
                    cout << "You sold " << Input << " shares for Price x Num" << endl;
                    Input = 0;
                }
                else if (Input == 2)
                {
                    cout << "How many shares would you like to buy?" << endl;
                    cin >> Input;
                    cout << "You bought " << Input << " shares for Price x Num" << endl;
                    Input = 0;
                }
                else if (Input == 3)
                {
                    cout << "Transaction successfully cancelled." << endl;
                    Input = 0;
                }
            }
            else if (Input == 5)
            {

            }
            Input = 0;
        }
        else if (Input == 2)
        {
            cout << "You have $ X.YZ in the bank" << endl;
            cout << "Press 1 to deposit, Press 2 to withdraw, 3 to cancel" << endl;
            cin >> Input;
            while (Input < 1 || Input > 3)
            {
                cout << "Enter a valid input [1-3]" << endl;
                cin >> Input;
            }
            if (Input == 1)
            {
                cout << "\nHow much would you like to Deposit?" << endl;
                cin >> DoubleIn;
                cout << "Your balance is now: $ X.YZ + " << DoubleIn << endl;
                Input = 0;
            }
            else if (Input == 2)
            {
                cout << "\nHow much would you like to withdraw?" << endl;
                cin >> DoubleIn;
                cout << "Your balance is now: $ X.YZ - " << DoubleIn << endl;
                Input = 0;
            }
            else if (Input == 3)
            {
                cout << "Bank action successfully cancelled." << endl;
                Input = 0;
            }
        }
        else if (Input == 3)
        {
            cout << "\nHere are your stats:\n" << endl;
            cout << showpoint << setprecision(2) << setw(20) << left << "Portfolio" << setw(15) << left << "Value" << endl;
            cout << showpoint << setprecision(2) << setw(20) << left << "In Bank" << setw(15) << left << "Value" << endl;
            cout << showpoint << setprecision(2) << setw(20) << left << "In Cash" << setw(15) << left << "Value" << endl;
            Input = 0;
        }
        else if (Input == 4)
        {
            cout << "\nIt is now 'old day' + 1" << endl;
            cout << "Check your markets, the values have changed." << endl;
            Input = 0;
        }
        else if (Input == 5)
        {
            cout << "\nIt is now 'old day' + 7" << endl;
            cout << "Check your markets, the values have changed." << endl;
            Input = 0;
        }
    }
    cout << "Closing Tutorial . . ." << endl;

    /* * * * * * * * * * * * *
     * Begin the actual game *
     * * * * * * * * * * * * *
     */

    cout << "The game will now begin with your difficulty level set to " << Difficulty << endl;
    cout << "Before you begin, I would like to remind you that your progress will not be saved" << endl << endl;

    // Fill default values
    Level = 1;
    Target = 4000*(Difficulty/2);


    for (int Level = 1; Level <= 5; Level++)
    {
        StartingCash = 3000/(Difficulty+Level-1);
        Balance = StartingCash;
        PortfolioValue = 1000;
        BankBalance = 0;
        LoanLimit = 5000/Difficulty;
        Firms = (3 + (2*Level));
        double*Market = new double[Firms]; // runtime array [Share Prices]
        int*Shares = new int[Firms]; // runtime array [Share Count]
        double*MarketSharesValue = new double[Firms]; // runtime array [Value of share holdings]

        for (int mc = 1; mc <= Firms; mc++)
        {
            int mccalc = (1 + pow(6,mc));
            Market[mc] = double(1 + rand()%mccalc);
        }

        for (Days = 1; PortfolioValue > 0; Days++)
        {
            if (DaysChange == 0)
            {

            }
            else if (DaysChange > 0)
            {
                for (int mc = 1; mc <= Firms; mc++)
                {
                    int ranran = 1+rand()%202;
                    if (ranran <= 1 && ranran < 15)
                        Market[mc] = Market[mc]*1.3;
                    else if (ranran >= 15 && ranran < 45)
                        Market[mc] = Market[mc]*1.23;
                    else if (ranran >= 45 && ranran < 90)
                        Market[mc] = Market[mc]*1.05;
                    else if (ranran >= 90 && ranran < 100)
                        Market[mc] = Market[mc]*1.1;
                    else if (ranran >= 100 && ranran < 115)
                        Market[mc] = Market[mc]*0.80;
                    else if (ranran >= 115 && ranran < 145)
                        Market[mc] = Market[mc]*0.93;
                    else if (ranran >= 145 && ranran < 190)
                        Market[mc] = Market[mc]*0.95;
                    else if (ranran >= 190 && ranran <= 200)
                        Market[mc] = Market[mc]*0.87;
                    else if (ranran == 201)
                        Market[mc] = Market[mc]*3;
                    else if (ranran == 202)
                        Market[mc] = Market[mc]*0.32;
                }
            }

            DaysChange = 0;

            cout << "\n\nIt is now Day " << Days << endl;
            cout << "1 - Market" << endl;
            cout << "2 - Bank" << endl;
            cout << "3 - Stats" << endl;
            cout << "4 - One Day Forward" << endl;
            cout << "5 - One Week Forward" << endl;
            cout << "6 - Exit (quit game)" << endl;
            cin >> Input;

            while (Input < 1 || Input > 6)
            {
                cout << "Enter a valid menu selection" << endl;
                cout << "Try again: ";
                cin >> Input;
            }
            if (Input == 1)
            {
                cout << "Here are the available stocks:" << endl;
                for (int m = 1; m <= Firms; m++)
                {
                    cout << showpoint << m << " - Firm" << m << " - $" << setprecision(13) << Market[m] << endl;
                }
                cin >> Input;
                if (Input == 0)
                {
                    Days--;
                }
                else
                {
                    for (int ioc = 1; Input != ioc; ioc++)
                    {

                    }

                }
                Input = 0;
            }
            else if (Input == 2)
            {

            }
            else if (Input == 3)
            {
                cout << "Here are your stats:" << endl;
            }
            else if (Input == 4)
            {
                cout << "Moving 1 day forward in time . . ." << endl;
                DaysChange = 1;
            }
            else if (Input == 5)
            {
                cout << "Moving 7 days forward in time . . ." << endl;
                DaysChange = 7;
                Days = Days + 6;
            }
            else if (Input == 6)
            {
                cout << "Are you sure you want to quit the game?" << endl;
                cout << "Your progress will not be saved" << endl;
                cout << "Press 6 to quit, or enter 0 to cancel." << endl;
                cin >> Input;
                if (Input == 6)
                    return 0;
                Days--;
                DaysChange = 0;
            }
        }
    }

//    for (Level = 1; PortfolioValue > 0; Level++)
//    {
//
//    }

    for (Days = 1; PortfolioValue > 0; Days++)
    {
        cout << "Day " << Days << endl;
        cout << "1 - Market" << endl;
        cout << "2 - Bank" << endl;
        cout << "3 - Stats" << endl;
        cout << "4 - One Day Forward" << endl;
        cout << "5 - One Week Forward" << endl;
        cout << "6 - Exit Game (stop program)" << endl;
        cin >> Input;
    }

    return 0;
}