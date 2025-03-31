#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\nAmount deposited successfully!";
            cout << "\nNew Balance: " << balance << "\n";
        } else {
            cout << "\nInvalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\nWithdrawal successful!";
            cout << "\nRemaining Balance: " << balance << "\n";
        } else {
            cout << "\nInsufficient balance or invalid withdrawal amount!\n";
        }
    }

    void displayBalance() const {
        cout << "\nAccount Details:\n";
        cout << "Holder Name: " << accountHolder << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: " << balance << "\n";
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice;
    while (true) {
        cout << "\n===============================";
        cout << "\n   Simple Banking System";
        cout << "\n===============================";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Check Balance";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            string name;
            int accNum;
            cout << "\nEnter Account Holder Name: ";
            cin >> name;
            cout << "Enter Account Number: ";
            cin >> accNum;
            accounts.push_back(BankAccount(name, accNum, 0));
            cout << "\nAccount created successfully!\n";
        } else if (choice == 2) {
            int accNum;
            double amount;
            cout << "\nEnter Account Number: ";
            cin >> accNum;
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    acc.deposit(amount);
                    break;
                }
            }
        } else if (choice == 3) {
            int accNum;
            double amount;
            cout << "\nEnter Account Number: ";
            cin >> accNum;
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    acc.withdraw(amount);
                    break;
                }
            }
        } else if (choice == 4) {
            int accNum;
            cout << "\nEnter Account Number: ";
            cin >> accNum;
            for (const auto &acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    acc.displayBalance();
                    break;
                }
            }
        } else if (choice == 5) {
            cout << "\nThank you for using our banking system!\n";
            break;
        } else {
            cout << "\nInvalid choice! Please try again.\n";
        }
    }
    return 0;
}

