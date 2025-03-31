// Crea un registro para guardar nombre, dos apellidos y edad de una persona

#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    string surname1;
    string surname2;
    int age;
};

void request_data(Person &person)
{
    cout << "Enter name: ";
    getline(cin, person.name);
    cout << "Enter first surname: ";
    getline(cin, person.surname1);
    cout << "Enter second surname: ";
    getline(cin, person.surname2);
    cout << "Enter age: ";
    cin >> person.age;
};

void print_data(const Person &person)
{
    cout << "Name: " << person.name << endl;
    cout << "First surname: " << person.surname1 << endl;
    cout << "Second surname: " << person.surname2 << endl;
    cout << "Age: " << person.age << endl;
}

int main()
{
    Person person;
    request_data(person);
    print_data(person);

    return 0;
}
