#include <iostream>
#include <string>
using namespace std;

int accounts[100][3]; // 2D array to store account_number, pin_number, and balance
int num_accounts = 0;
int manager_pin_number = 1234;
bool is_open = false;

int main()
{

    cout << "1. To open the bank enter capital 'S'. " << endl;
    cout << "2. To open back account enter capital 'O'. " << endl;
    cout << "3. To see balance enter capital 'B'. " << endl;
    cout << "4. For deposit enter capital 'D'. " << endl;
    cout << "5. For withdrawl enter capital 'W'." << endl;
    cout << "6. To close an opened account enter capital 'C'." << endl;
    cout << "7. To add interest rate enter capital 'I'." << endl;
    cout << "8. To see an opened back accounts enter capital 'P'." << endl;
    cout << "9. To close the bank enter capital 'E'." << endl;
    cout << "\nRemark - In order to access these services you first need to Open the bank";
    cout << endl;
    while (true)
    {
        string transaction_type;
        cout << "Transaction type: ";
        cin >> transaction_type;

        if (transaction_type == "S")
        {
            int manager_pin;
            cout << "Manager pin: ";
            cin >> manager_pin;
            if (manager_pin == manager_pin_number)
            {
                is_open = true;
                cout << "Bank is now open." << endl;
            }
            else
            {
                cout << "Incorrect manager pin." << endl;
            }
        }
        else if (transaction_type == "O")
        {
            if (is_open && num_accounts < 100)
            {
                double initial_deposit;
                int pin_number;
                cout << "Initial deposit: ";
                cin >> initial_deposit;
                cout << "Pin number: ";
                cin >> pin_number;
                if (initial_deposit >= 25)
                {
                    accounts[num_accounts][0] = num_accounts + 1001; // account_number
                    accounts[num_accounts][1] = pin_number;          // pin_number
                    accounts[num_accounts][2] = initial_deposit;     // balance

                    num_accounts++;
                    cout << "Account opened with account number " << num_accounts + 1000 << "." << endl;
                }
                else
                {
                    cout << "Please enter initial deposit greater than 25." << endl;
                }
            }
            else if (!is_open)
            {
                cout << "Bank is not open." << endl;
            }
            else
            {
                cout << "Maximum number of accounts reached." << endl;
            }
        }

        else if (transaction_type == "B")
        {
            if (is_open)
            {
                int account_number, pin_number;
                cout << "Account number: ";
                cin >> account_number;
                cout << "Pin number: ";
                cin >> pin_number;

                bool found = false;
                for (int i = 0; i < num_accounts; i++)
                {
                    if (accounts[i][0] == account_number && accounts[i][1] == pin_number)
                    {
                        cout << "Account number: " << accounts[i][0] << ", Balance: " << accounts[i][2] << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Invalid account number or pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        else if (transaction_type == "D")
        {
            if (is_open)
            {
                int account_number, pin_number;
                double amount;
                cout << "Account number: ";
                cin >> account_number;
                cout << "Amount: ";
                cin >> amount;
                cout << "Pin number: ";
                cin >> pin_number;

                bool found = false;
                for (int i = 0; i < num_accounts; i++)
                {
                    if (accounts[i][0] == account_number && accounts[i][1] == pin_number)
                    {
                        accounts[i][2] += amount;
                        cout << "Deposit successful. New balance: " << accounts[i][2] << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Invalid account number or pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        else if (transaction_type == "W")
        {
            if (is_open)
            {
                int account_number, pin_number;
                double amount;
                cout << "Account number: ";
                cin >> account_number;
                cout << "Pin number: ";
                cin >> pin_number;
                cout << "Enter amount:";
                cin >> amount;
                bool found = false;
                for (int i = 0; i < num_accounts; i++)
                {
                    if (accounts[i][0] == account_number && accounts[i][1] == pin_number && is_open && accounts[i][2] >= amount)
                    {
                        accounts[i][2] -= amount;
                        cout << "Withdrawl of " << amount << " succesful. New balance is: " << accounts[i][2] << "." << endl;
                        found = true;
                        break;
                    }
                    else if (accounts[i][0] == account_number && accounts[i][1] == pin_number && is_open)
                    {
                        cout << "Insufficient funds." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Invalid account number or pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        else if (transaction_type == "C")
        {
            if (is_open)
            {
                int account_number, pin_number;
                cout << "Account number: ";
                cin >> account_number;
                cout << "Pin number: ";
                cin >> pin_number;

                bool found = false;
                for (int i = 0; i < num_accounts; i++)
                {
                    if (accounts[i][0] == account_number && accounts[i][1] == pin_number && is_open)
                    {
                        is_open = false;
                        cout << "Account closed." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Invalid account number or pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        else if (transaction_type == "I")
        {
            if (is_open)
            {
                double interest_rate;
                int manager_pin;
                cout << "Interest rate: ";
                cin >> interest_rate;
                cout << "Manager pin: ";
                cin >> manager_pin;
                if (manager_pin == manager_pin_number)
                {
                    for (int i = 0; i < num_accounts; i++)
                    {
                        if (is_open)
                        {
                            double interest = accounts[i][2] * interest_rate / 100;
                            accounts[i][2] += interest;
                        }
                    }
                }
                else
                {
                    cout << "Incorrect manager pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        else if (transaction_type == "P")
        {
            if (is_open)
            {
                char print_type;
                int manager_pin;
                cout << "Enter manager pin number: ";
                cin >> manager_pin;
                if (manager_pin == manager_pin_number)
                {
                    cout << "Enter 'A' to print all accounts and their balances or 'T' to print a specific account and its transactions: ";
                    cin >> print_type;
                    if (print_type == 'A')
                    {
                        for (int i = 0; i < num_accounts; i++)
                        {
                            cout << "Account number: " << accounts[i][0] << ", Balance: " << accounts[i][2] << endl;
                        }
                    }
                    else if (print_type == 'T')
                    {
                        int account_number;
                        cout << "Enter the account number: ";
                        cin >> account_number;
                        bool found = false;
                        for (int i = 0; i < num_accounts; i++)
                        {
                            if (accounts[i][0] == account_number)
                            {
                                found = true;
                                cout << "Account number: " << accounts[i][0] << endl;
                                for (int j = 3; j <= accounts[i][2] + 2; j++)
                                {
                                    cout << "Transaction " << j - 2 << ": " << accounts[i][j] << endl;
                                }
                                break;
                            }
                        }
                        if (!found)
                        {
                            cout << "Invalid account number." << endl;
                        }
                    }
                    else
                    {
                        cout << "Invalid print type." << endl;
                    }
                }
                else
                {
                    cout << "Incorrect pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        else if (transaction_type == "E")
        {
            if (is_open)
            {
                int manager_pin;
                cout << "Enter manager pin number: ";
                cin >> manager_pin;
                if (manager_pin == manager_pin_number && is_open)
                {
                    is_open = false;
                    cout << "All accounts have been closed. Exiting program..." << endl;
                    exit(0);
                }
                else
                {
                    cout << "Invalid manager pin number." << endl;
                }
            }
            else
            {
                cout << "Bank is not open." << endl;
            }
        }
        
	if(transaction_type != "E" && transaction_type != "B" && transaction_type != "C" && transaction_type != "D" && transaction_type != "I" && transaction_type != "P" && transaction_type != "O" && transaction_type != "W" ){
        	cout <<"Invalid transaction."<<endl;
		}	 
    }
    
		}
   

