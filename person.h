
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    // data members
    int person_id;
    string person_name;
    int person_age;
    string person_gender;
    bool is_deleted;

public:
    // setters
    // we will use person_id as an unique identifier each person will have a different id
    // so we want make a setter to set id it will be set by default
    void setName(string name)
    {
        person_name = name;
    }
    void setAge(int age)
    {
        person_age = age;
    }
    void setId(string gender)
    {
        person_gender = gender;
    }
    void setDeleted(bool deleted)
    {
        is_deleted = deleted;
    }

    // getters
    int getId(int id)
    {
        return person_id;
    }
    string getName()
    {
        return person_name;
    }
    int getAge(int age)
    {
        return person_age;
    }
    string getgender(string gender)
    {
        return person_gender;
    }
    bool getDelted()
    {
        return is_deleted;
    }

    // access all info
    void getPersonInfo()
    {
        if (!is_deleted)
        {
            cout << "ID: " << person_id << endl;
            cout << "Name: " << person_name << endl;
            cout << "Age :" << person_age << endl;
            cout << "Gender: " << person_gender << endl;
            cout << "IS Deleted: " << is_deleted << endl;
        }
        else
        {
            cout << "The Person you are tring to access is deleted. please contact support team. " << endl;
        }
    }

    // seach by name
    void searchByName(string name)
    {
        if (!is_deleted)
        {
            cout << "ID: " << person_id << endl;
            cout << "Name: " << person_name << endl;
            cout << "Age :" << person_age << endl;
            cout << "Gender: " << person_gender << endl;
            cout << "IS Deleted: " << is_deleted << endl;
        }
        else
        {
            cout << "The Person you are tring to access is deleted. please contact support team. " << endl;
        }
    }

    bool matchName(string name)
    {
        if (name == person_name && !is_deleted)
            return true;
        else
            return false;
    }

    // update Info

    void updateInfo(int age, string gender)
    {
        // updating just age and gender as id, name ,is_deleted is not allowed to be updated without support team
        person_age = age;
        person_gender = gender;
    }

    // default
    Person()
    {
        person_id = 0;
        person_name = "";
        person_age = 0;
        person_gender = "";
        is_deleted = false;
    }

    // parametrized
    Person(int id, string name, int age, string gender)
    {
        person_id = id;
        person_name = name;
        person_age = age;
        person_gender = gender;
        is_deleted = false;
    }
};
