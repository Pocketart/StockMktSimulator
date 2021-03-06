/*
 * 04/20/2017 12:38AM
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
    int Difficulty; // Difficulty factor as selected by user
    int Age; // User profile
    int Firms; // Number of firms offering shares (increases by 3 per increment in Level)
    int Input; // Stores user int input for interaction
    double DoubleIn; // Stores user double input for interaction
    string Name; // User profile
    double Balance; // User balance in cash
    double BankBalance; // User balance in bank
    double PortfolioValue; // The total value of all the user's market holdings

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
    cout << "1 <----- Easy (Use this if you are new)" << endl;
    cout << "2 <----- Normal (Standard)" << endl;
    cout << "3 <----- Hard (Slightly Difficult)" << endl;
    cout << "4 <----- Advanced (Are you sure?)" << endl;
    cin >> Difficulty;

    while (Difficulty < 1 || Difficulty > 4)
    {
        cout << "That is not a valid selection, please choose either one of the 4 given choices\n" << endl;
        cout << "1 <----- Easy (Use this if you are new)" << endl;
        cout << "2 <----- Normal (Standard)" << endl;
        cout << "3 <----- Hard (Slightly Difficult)" << endl;
        cout << "4 <----- Advanced (Are you sure?)" << endl;
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
     * * * * * * * * * * * * */

    cout << "The game will now begin with your difficulty level set to " << Difficulty << endl;
    cout << "Before you begin, I would like to remind you that your progress will not be saved" << endl << endl;

    // Fill default values
    int Target = 4000*(Difficulty/2);


    for (int Level = 1; Level <= 5; Level++)
    {
        StartingCash = 3000/(Difficulty+Level-1);
        Balance = StartingCash;
        PortfolioValue = Balance;
        BankBalance = 0;
        Firms = (3 + (2*Level));
        double*Market = new double[Firms]; // runtime array [Share Prices]
        double*Shares = new double[Firms]; // runtime array [Share Count]
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
                PortfolioValue = 0;
                for (int calck = 1; calck <= Firms; calck++)
                {
                    MarketSharesValue[calck] = Market[calck] * Shares[calck];
                    PortfolioValue = PortfolioValue + MarketSharesValue[calck];
                }
                PortfolioValue = PortfolioValue + Balance + BankBalance;
                if (PortfolioValue < 0)
                {
                    cout << "You are broke." << endl;
                    cout << "Game Over!" << endl;
                    return 0;
                }
            }
            else if (DaysChange > 0)
            {
                for (int mc = 1; mc <= Firms; mc++) // difficulty and luck
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
                        Market[mc] = Market[mc]*(0.80/Difficulty);
                    else if (ranran >= 115 && ranran < 145)
                        Market[mc] = Market[mc]*(0.93/Difficulty);
                    else if (ranran >= 145 && ranran < 190)
                        Market[mc] = Market[mc]*(0.95/Difficulty);
                    else if (ranran >= 190 && ranran <= 200)
                        Market[mc] = Market[mc]*(0.87/Difficulty);
                    else if (ranran == 201)
                        Market[mc] = Market[mc]*3.3;
                    else if (ranran == 202)
                        Market[mc] = Market[mc]*0.32/Difficulty;
                }
                BankBalance = BankBalance * 1.0018;
                PortfolioValue = 0;
                for (int calck = 1; calck <= Firms; calck++)
                {
                    MarketSharesValue[calck] = Market[calck] * Shares[calck];
                    PortfolioValue = PortfolioValue + MarketSharesValue[calck];
                }
                PortfolioValue = PortfolioValue + Balance + BankBalance;
            }

            DaysChange = 0;
            //display menu
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
                cout << "Press 0 to cancel" << endl;
                cin >> Input;
                while (Input < 0 || Input > Firms)
                {
                    cout << "That is not a valid selection!" << endl;
                    cout << "Please enter an option on the menu: ";
                    cin >> Input;
                }

                if (Input == 0)
                {
                    cout << "Taking you back to the menu . . . . . ." << endl;
                }
                else
                {
                    int selec = Input;
                    cout << "\n\nYou have selected: Firm" << selec << endl;
                    cout << showpoint << "You have: $" << Balance << endl;
                    cout << showpoint << "Each share is worth $" << Market[selec] << endl;
                    cout << "You currently own " << Shares[selec] << " shares of this firm" << endl;
                    cout << "Press 1 to buy, Press 2 to sell, or press 3 to cancel.";
                    cin >> Input;

                    while (Input < 1 || Input > 3)
                    {
                        cout << "Invalid input!" << endl;
                        cout << "Please enter a valid selection on the menu: " << endl;
                        cin >> Input;
                    }

                    if (Input == 1)
                    {
                        cout << "How many shares would you like to buy?" << endl;
                        cin >> Input;
                        if ((Input*Market[selec])>(Balance-20))
                        {
                            cout << "You do not have enough money to buy the shares + pay the transaction fee!" << endl;
                            cout << "Come back later when you have more money!" << endl;
                            cout << "Perhaps check out the bank if you haven't yet" << endl;
                            Input = 0;
                            selec = 0;
                        }
                        else
                        {
                            Shares[selec] = (Shares[selec] + Input);
                            Balance = Balance - (Shares[selec]*Market[selec]);
                            Balance = (Balance - 20);
                            cout << "Successfully purchased shares!" << endl;
                            cout << "Your balance is now: $" << Balance << endl;
                        }
                    }
                    if (Input == 2)
                    {
                        cout << "How many shares would you like to sell?" << endl;
                        cin >> Input;
                        while (Input > Shares[selec])
                        {
                            cout << "The number of shares that you are trying to sell exceeds the number of shares" << endl;
                            cout << "you own.\n" << endl;
                            cout << "You have: " << Shares[selec] << " shares." << endl;
                            cout << "How many would you like to sell?:";
                            cin >> Input;
                        }
                        if ((Shares[selec]*Market[selec]) < (5*Difficulty))
                        {
                            cout << "The value of your sale is less than the" << endl;
                            cout << "transaction fee of: $" << (5*Difficulty) << endl;
                            cout << "Come back after you rethink your sale" << endl;
                        }
                        else
                        {
                            Shares[selec] = (Shares[selec] - Input);
                            Balance = Balance + (Input*Market[selec]);
                            Balance = (Balance - 5*Difficulty);
                            cout << "Successfully sold " << Input << " shares" << endl;
                            cout << "Your balance is now: $" << Balance << endl;
                        }
                    }
                }
                DaysChange = 0;
                Days--;
                Input = 0;
            }
            else if (Input == 2) // bank action
            {
                cout << "You have $" << BankBalance << " in your bank account" << endl;
                cout << "Press 1 to deposit, 2 to withdraw/borrow, and 0 to cancel bank action" << endl;
                cout << "Enter selection:";
                cin >> Input;
                while (Input < 0 || Input > 2) //verify selection
                {
                    cout << "Invalid Input! Please enter a valid menu selection (0,1,2)" << endl;
                    cin >> Input;
                }
                if (Input == 1) // deposit money
                {
                    cout << "You have $" << Balance << " as cash and $" << BankBalance << endl;
                    cout << "in your bank account" << endl;
                    cout << "How much money would you like to deposit?" << endl;
                    cin >> Input;
                    while (Input > Balance) // deposit verify
                    {
                        cout << "You can't deposit more than the amount of money you have!" << endl;
                        cout << "Enter a different value that fits in the range" << endl;
                        cin >> Input;
                    }
                    Balance = Balance - Input;
                    BankBalance = BankBalance + Input;
                    cout << "Deposit successful!" << endl;
                    Days--;
                }
                else if (Input == 2) // withdraw and or borrow
                {
                    if (BankBalance < -1500)
                    {
                        cout << "You can't withdraw money right now because you have a negative balance" << endl;
                        cout << "greater than $1500" << endl;
                    }
                    else
                    {
                        cout << "How much money would you like to withdraw?" << endl;
                        cout << "A withdrawal larger than the balance in the bank will be counted as a loan" << endl;
                        cin >> Input;
                        while ((BankBalance - Input) < (-1500))
                        {
                            cout << "You are trying to withdraw/borrow more than the borrowing limit of $1500" << endl;
                            cout << "Please enter a different value:" << endl;
                            cin >> Input;
                        }
                    }
                    BankBalance = BankBalance - Input;
                    Balance = Balance + Input;
                    cout << "You have successfully withdrawn $" << Input << endl;
                    cout << "You now have $" << BankBalance << " in your bank account" << endl;
                }
                else if (Input == 0) // cancel bank action
                {
                    cout << "Bank action successfully cancelled.";
                    Days--;
                }
            }
            else if (Input == 3) // view stats
            {
                cout << "Here are your stats:" << endl;
                cout << setprecision(5) << "It is day " << Days << ", and you have $" << Balance << " as cash" << endl;
                cout << setprecision(5) << "Your bank account balance is $" << BankBalance << endl;
                cout << setprecision(5) << "Your portfolio is worth $" << PortfolioValue << endl;
                Days--;
            }
            else if (Input == 4) // move 1 day forward
            {
                cout << "Moving 1 day forward in time . . ." << endl;
                DaysChange = 1;
            }
            else if (Input == 5) // move 7 days more forward
            {
                cout << "Moving 7 days forward in time . . ." << endl;
                DaysChange = 7;
                Days = Days + 6;
            }
            else if (Input == 6) // game exit prompt
            {
                cout << "Are you sure you want to exit the game?" << endl;
                cout << "Your progress will be lost forever" << endl;
                cout << "Press 6 to quit, or enter any other key to cancel." << endl;
                cin >> Input;
                if (Input == 6)
                {
                    cout << "Thank you for playing" << endl;
                    return 0;
                }
                Days--;
                DaysChange = 0;
                Input = 0;
            }
        }
        delete Market;
        delete MarketSharesValue;
        delete Shares;
    }
    return 0;
}