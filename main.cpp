#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    string nameFirst, nameLast;
    unsigned short hRate;
public:
    Employee()
    {}
    Employee(const string &firstName, const string &lastName, const unsigned short hourlyRate): 
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

    unsigned short getHourlyRate() const
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

    void setHourlyRate(unsigned short hourlyRate)
    {
        hRate = hourlyRate;
    }

    void show()
    {
        cout << "Imie: " << nameFirst << "Nazwisko: " << nameLast << "Godziny pracy: " << hRate << '\n';
    }

    float calculate(float salary)
    {
        return salary * hRate;
    }
};

class Manager: public Employee
{
private:
    float bonus;
    unsigned short numOfSubordinates = 0;
public:
    Manager(){};
    Manager(const string &firstName, const string &lastName, const unsigned short hourlyRate, const float managerBonus, const unsigned short numOfEmployees): Employee(firstName, lastName, hourlyRate), bonus(managerBonus), numOfSubordinates(numOfEmployees){};

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
        return 
    }
};

int main()
{

}
//aj aj aj upubliczniasz nie dokończony kod not Śigma 
