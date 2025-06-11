    // Age Calculator

    #include <bits/stdc++.h>
    using namespace std;

    // check for leap year
    bool isLeapYear(int year)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            return true;
        }
        return false;
    }

    // Get no. of days in a month
    int MonthDays(int month, int year)
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            return 31;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            return 30;
        }
        else if (month == 2)
        {
            if (isLeapYear(year))
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
        else
        {
            return -1;
        }
    }

    // Validating date
    bool ValidDate(int d, int m, int y)
    {
        if (y <= 0 || m <= 0 || m > 12 || d <= 0)
        {
            return false;
        }

        int MD = MonthDays(m, y); // MD = Month Days.
        if (d < MD)
        {
            return true;
        }
        return false;
    }

    // Calculator
    void calculator(int CY, int CM, int CD, int BY, int BM, int BD)
    {
        if (!ValidDate(CD, CM, CY) || !ValidDate(BD, BM, BY))
        {
            cout << "Error! Invalid Date.\n";
            return;
        }

        if (CY < BY || (CY == BY && CM < BM) || (CY == BY && CM == BM && CD < BD))
        {
            cout << "Dude, you are not born yet!\n";
            return;
        }

        int TY = CY - BY;
        int TM = CM - BM;
        int TD = CD - BD;

        if (TD < 0)
        {
            CM--;
            int prevMonth;
            int prevYear;

            if (CM == 0)
            {
                prevMonth = 12;
                prevYear = CY - 1;
            }
            else
            {
                prevMonth = CM;
                prevYear = CY;
            }

            int MD = MonthDays(prevMonth, prevYear); // Month Days

            TD = CD + MD - BD;
            TM--;
        }

        if (TM < 0)
        {
            TM = TM + 12;
            TY = TY - 1;
        }

        cout << "You have lived: " << TY << " Years, " << TM << " Months, and " << TD << " Days.\n";
    }

    int main()
    {
        int CY, CM, CD, BY, BM, BD;
        cout << "\n*** Age Calculator ***\n"
            << endl;
        cout << "\nEnter Today's Date (DD MM YYYY): ";
        cin >> CD >> CM >> CY;
        cout << "Enter Your Birth Date (DD MM YYYY): ";
        cin >> BD >> BM >> BY;
        cout << endl;

        calculator(CY, CM, CD, BY, BM, BD);

        return 0;
    }
