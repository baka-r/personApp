#include <iostream>
#include <string>
#include "person.h"
using namespace std;

// our application will be able to store data of person within a defined range
#define MAX_PERSONS 10

// making a globle variable
int CURRENT_PERSON_ID = 0, temp_deleted = 0, age, option;
string name, gender;
bool is_program_runing = true;
Person arry_of_persons[MAX_PERSONS];

void mainMenu();
void repeatMenu();
void addPerson();
void searchPerson();
void updatePerson();
void deletedPerson();
void getAllPersons();

void mainMenu()
{
    // display menu options
    cout << "Add a person press 1 " << endl;
    cout << "Search a perosn by name press 2 " << endl;
    cout << "update a perosn by name press 3 " << endl;
    cout << "delete a perosn by name press 4 " << endl;
    cout << "List of all persons press 5 " << endl;
    cout << "Exist Program press 6 " << endl;

    cin >> option;

    switch (option)
    {
    case 1:
        addPerson();
        break;
    case 2:
        searchPerson();
        break;
    case 3:
        updatePerson();
        break;
    case 4:
        deletedPerson();
        break;
    case 5:
        getAllPersons();
        break;
    case 6:
        is_program_runing = false;
        break;
    default:
        cout << "Incorrect Option. Please try again. " << endl;
        break;
    }
}

void repeatMenu()
{
    cout << "Enter yes/no for main menu: " << endl;
    string yes_or_no;
    cin >> yes_or_no;
    if (yes_or_no == "yes" || yes_or_no == "YES")
    {
        mainMenu();
    }
    else
    {
        is_program_runing = false;
    }
}

void addPerson()
{
    // get the input from the user
    cout << "Enter Person Name :" << endl;
    cin >> name;

    if (name.length() < 3)
    {
        cout << "Name should contain atlest 3 letters: " << endl;
        addPerson();
    }
    else
    {
        // validate name
        bool name_matched;
        for (int i = 0; i <= CURRENT_PERSON_ID - 1; i++)
        {
            name_matched = arry_of_persons[i].matchName(name);
            if (name_matched)
            {
                break;
            }
        }
        if (name_matched)
        {
            cout << "Enter a new name as it already exists" << endl;
            addPerson();
        }
        else
        {
            cout << "Enter Person age :" << endl;
            cin >> age;
            cout << "Enter Person gender :" << endl;
            cin >> gender;
            // use the parameterized constructor
            arry_of_persons[CURRENT_PERSON_ID] = Person(CURRENT_PERSON_ID, name, age, gender);

            cout << "Person Added Successfully following are its stored info :" << endl;
            arry_of_persons[CURRENT_PERSON_ID].getPersonInfo();

            // this will increment the id for new person
            CURRENT_PERSON_ID++;
            repeatMenu();
        }
    }
}

void searchPerson()
{
    // get input from the use
    bool name_matched;
    int temp_id;
    cout << "Enter a name to be searched" << endl;
    cin >> name;

    if (CURRENT_PERSON_ID > 0)
    {
        for (int i = 0; i <= MAX_PERSONS; i++)
        {
            name_matched = arry_of_persons[i].matchName(name);
            if (name_matched)
            {
                temp_id = i;
                break;
            }
        }
        if (name_matched)
        {
            arry_of_persons[temp_id].getPersonInfo();
        }
        else
        {
            cout << "The Person you are tring to access is deleted or not exists. please contact support team. " << endl;
        }
    }
}
void getAllPersons()
{
    cout << "Following is the list of all persons: " << endl;
    if (CURRENT_PERSON_ID - temp_deleted > 0)
    {
        for (int i = 0; i <= CURRENT_PERSON_ID - 1; i++)
        {
            arry_of_persons[i].getPersonInfo();
        }
    }
    else
    {
        cout << "There are No Persons Added" << endl;
    }
}

void updatePerson()
{
    // get input from the use
    bool name_matched;
    int temp_id;
    cout << "Enter a name to be searched and updated: " << endl;
    cin >> name;

    for (int i = 0; i <= MAX_PERSONS; i++)
    {
        name_matched = arry_of_persons[i].matchName(name);
        if (name_matched)
        {
            temp_id = i;
            break;
        }
    }
    if (name_matched)
    {
        cout << "Enter Person age :" << endl;
        cin >> age;
        cout << "Enter Person gender :" << endl;
        cin >> gender;
        arry_of_persons[temp_id].updateInfo(age, gender);
    }
    else
    {
        cout << "The Person you are tring to access is deleted or not exists. please contact support team. " << endl;
    }
}
void deletedPerson()
{
    // get input from the use
    bool name_matched;
    int temp_id;
    cout << "Enter a name to be searched and Deleted: " << endl;
    cin >> name;

    for (int i = 0; i <= MAX_PERSONS; i++)
    {
        name_matched = arry_of_persons[i].matchName(name);
        if (name_matched)
        {
            temp_id = i;
            break;
        }
    }
    if (name_matched)
    {
        arry_of_persons[temp_id].setDeleted(true);
        temp_deleted++;
        cout << "The person is deleted" << endl;
    }
    else
    {
        cout << "The Person you are tring to access is deleted or not exists. please contact support team. " << endl;
    }
}