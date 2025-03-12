#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isStrNum(string str)
{
    if(str.length() == 0)
        return false;

    bool result = true;

    for(char chr : str)
    {
        if((chr < '0' || chr > '9') && chr != '.')
        {
            result = false;
            break;
        }
    }

    return result;
}

int strToUInt(string str)
{
    if(isStrNum(str))
    {
        int result = 0;
        for(char chr : str)
        {
            if(chr == '.')
                break;
            
            result *= 10;
            result += chr - '0';
        }
        return result;
    }

    return 0;
}

float strToFloat(string str)
{
    if(isStrNum(str))
    {
        float mantissa = 0.0f;
        bool afterDecPoint = false;
        unsigned short decShift = 1;

        for(char chr : str)
        {
            if(chr == '.')
            {
                afterDecPoint = true;
                continue;
            }

            if(afterDecPoint)
                decShift *= 10;

            mantissa *= 10;
            mantissa += chr - '0';
        }

        mantissa /= decShift;

        return mantissa;
    }

    return 0.0f;
}

class Employee
{
private:
    string nameFirst, nameLast;
    float hRate;
public:
    Employee()
    {}
    Employee(const string &firstName, const string &lastName, const float hourlyRate): 
        nameFirst(firstName), 
        nameLast(lastName), 
        hRate(hourlyRate)
    {};

    string getFirstName() const
    {
        return nameFirst;
    }

    string getLastName() const
    {
        return nameLast;
    }

    float getHourlyRate() const
    {
        return hRate;
    }

    void setFirstName(const string& firstName)
    {
        nameFirst = firstName;
    }

    void setLastName(const string& lastName)
    {
        nameLast = lastName;
    }

    void setHourlyRate(float hourlyRate)
    {
        hRate = hourlyRate;
    }

    void show()
    {
        cout << "Imie: " << nameFirst << ", Nazwisko: " << nameLast << ", Stawka godzinna: " << hRate << '\n';
    }

    float calculate(unsigned short hours)
    {
        return hours * hRate;
    }
};

class Manager: public Employee
{
private:
    float bonus;
    unsigned short numOfSubordinates = 0;
public:
    Manager(){};
    Manager(const string &firstName, const string &lastName, const float hourlyRate, const float managerBonus, const unsigned short numOfEmployees): Employee(firstName, lastName, hourlyRate), bonus(managerBonus), numOfSubordinates(numOfEmployees){};

    float getBonus()
    {
        return bonus;
    }

    unsigned short getNumOfEmployees()
    {
        return numOfSubordinates;
    }

    void setBonus(const float managerBonus)
    {
        bonus = managerBonus;
    }

    void setNumOfEmployees(const unsigned short numOfEmployees)
    {
        numOfSubordinates = numOfEmployees;
    }

    void show()
    {
        Employee::show();
        cout << "Bonus: " << bonus << ", Liczba pracowników: " << numOfSubordinates << '\n';
    }

    float calculate(float salary)
    {
        return getHourlyRate() * salary + bonus;
    }
};

class Worker : public Employee
{
private:
    string dpt;
public:
    Worker(){};
    Worker(const string &firstName, const string &lastName, const unsigned short hourlyRate, const string &department): Employee(firstName, lastName, hourlyRate), dpt(department){};

    string getDepartment()
    {
        return dpt;
    }

    void setDepartment(const string &department)
    {
        dpt = department;
    }

    void show()
    {
        Employee::show();
        cout << "Dzial: " << dpt << '\n';
    }
};

int main()
{
    vector<Manager> managers;
    vector<Worker> workers;

    bool done = false;
    while(!done)
    {
        string input;
        while(!isStrNum(input))
        {
            cout << "Wybierz akcje:\n [1] Dodaj menedzera\n[2] Usun menedzera\n [3] Wyswietl wszystkich menedzerow\n[4+] Przejdz dalej\n";

            cin >> input;
        }

        switch(strToUInt(input))
        {
            case(1):
            {
                string nameFirst, nameLast, hRate, bonus, numOfSubordinates;

                cout << "Podaj imie: ";
                cin >> nameFirst;
                cout << "Podaj nazwisko: ";
                cin >> nameLast;
                while(!isStrNum(hRate))
                {
                    cout << "Podaj stawke godzinna: ";
                    cin >> hRate;
                }
                while(!isStrNum(bonus))
                {
                    cout << "Podaj bonus menedzera: ";
                    cin >> bonus;
                }
                while(!isStrNum(numOfSubordinates))
                {
                    cout << "Podaj ilosc podwladnych: ";
                    cin >> numOfSubordinates;
                }

                managers.push_back(Manager(nameFirst, nameLast, strToFloat(hRate), strToFloat(bonus), strToUInt(numOfSubordinates)));

                break;
            }
            case(2):
            {
                unsigned short index = 0;
                for(Manager mng : managers)
                {
                    cout << "[" << index << "] ";
                    mng.show();

                    index++;
                }
                cout << "Podaj indeks menedzera do usuniecia: ";
                string choice;
                cin >> choice;

                managers.erase(managers.begin() + strToUInt(choice));

                break;
            }
            case(3):
            {
                for(Manager mng : managers)
                {
                    mng.show();
                }
                break;
            }
            default:
            {
                done = true;
                break;
            }
        }
    }

    done = false;

    while(!done)
    {
        string input;
        while(!isStrNum(input))
        {
            cout << "Wybierz akcje:\n [1] Dodaj pracownika\n[2] Usun pracownika\n [3] Wyswietl wszystkich pracownikow\n[4+] Zakoncz\n";

            cin >> input;
        }

        switch(strToUInt(input))
        {
            case(1):
            {
                string nameFirst, nameLast, hRate, dpt;

                cout << "Podaj imie: ";
                cin >> nameFirst;
                cout << "Podaj nazwisko: ";
                cin >> nameLast;
                while(!isStrNum(hRate))
                {
                    cout << "Podaj stawke godzinna: ";
                    cin >> hRate;
                }
                cout << "Podaj dzial: ";
                cin >> dpt;

                workers.push_back(Worker(nameFirst, nameLast, strToFloat(hRate), dpt));

                break;
            }
            case(2):
            {
                unsigned short index = 0;
                for(Worker wrk : workers)
                {
                    cout << "[" << index << "] ";
                    wrk.show();

                    index++;
                }
                cout << "Podaj indeks pracownika do usuniecia: ";
                string choice;
                cin >> choice;

                workers.erase(workers.begin() + strToUInt(choice));

                break;
            }
            case(3):
            {
                for(Worker wrk : workers)
                {
                    wrk.show();
                }
                break;
            }
            default:
            {
                done = true;
                break;
            }
        }
    }

}
