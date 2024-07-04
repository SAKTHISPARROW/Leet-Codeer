#include <iostream>
#include <string>
using namespace std;
class atm
{
    long int accountno;
    string name;
    string ph;
    double balance;
    int pin;

public:
    void setdata(long int ac, string n, string phno, double bal, int p)
    {
        accountno = ac;
        name = n;
        ph = phno;
        balance = bal;
        pin = p;
    }
    long int getacc()
    {
        return accountno;
    }
    string getname()
    {
        return name;
    }
    string getph()
    {
        return ph;
    }
    double getbal()
    {
        return balance;
    }
    int getpin()
    {
        return pin;
    }
    void cashwd(int amt)
    {
        if (amt > 0 && amt < balance)
        {
            balance -= amt;
            cout << endl
                 << "Please Collect Your Cash";
            cout << endl
                 << "Available Balance :" << balance;
        }
    }
    void setph(string oldph, string newph)
    {
        if (oldph == ph)
        {
            ph = newph;
            cout << endl
                 << "Sucessfully Updated Mobile no.";
        }
        else
        {
            cout << endl
                 << "Incorrect !!! Old Mobile no";
        }
    }
};
int main()
{
    int pin, ch = 0;
    long int ac;
    atm a;
    a.setdata(1234567890, "sakthi", "9600812860", 50000.90, 1234);
    do
    {
        cout << endl
             << "****Welcome to ATM*****" << endl;
        cout << endl
             << "Enter Your Account No ";
        cin >> ac;

        cout << endl
             << "Enter PIN ";
        cin >> pin;
        cout << "pin" << a.getpin() << a.getacc();
        if ((ac == a.getacc()) && (pin == a.getpin()))
        {
            do
            {
                string oldph, newph;
                int amt = 0;
                cout << endl
                     << "**** Welcome to ATM *****" << endl;
                cout << endl
                     << "Select Options ";
                cout << endl
                     << "1. Check Balance";
                cout << endl
                     << "2. Cash withdraw";
                cout << endl
                     << "3. Show User Details";
                cout << endl
                     << "4. Update Mobile no.";
                cout << endl
                     << "5. Exit" << endl;
                cin >> ch;
                switch (ch)
                {
                case 1:
                    cout << endl
                         << "Your Bank balance is :" << a.getbal();
                    break;
                case 2:
                    cout << endl
                         << "Enter the amount :";
                    cin >> amt;
                    a.cashwd(amt);
                    break;
                case 3:
                    cout << endl
                         << "*** User Details are :- ";
                    cout << endl
                         << "-> Account no" << a.getacc();
                    cout << endl
                         << "-> Name      " << a.getname();
                    cout << endl
                         << "-> Balance   " << a.getbal();
                    cout << endl
                         << "-> Mobile No." << a.getph();
                    break;
                case 4:
                    cout << endl
                         << "Enter Old Mobile No. ";
                    cin >> oldph;
                    cout << endl
                         << "Enter NEw Mobile No. ";
                    cin >> newph;
                    a.setph(oldph, newph);
                    break;
                case 5:
                    exit(0);
                default:
                    cout << endl
                         << "Enter Valid Data !!!";
                }
            } while (1);
        }
        else
        {
            cout << endl
                 << "User Details are Invalid !!! ";
        }
    } while (1);
    return 0;
}