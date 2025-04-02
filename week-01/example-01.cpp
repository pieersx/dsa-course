// Crea un registro para guardar nombre, dos apellidos y edad de una persona. Crea dos subprocesos para introducir esos datos en el registro y para mostrarlos por pantalla.

#include <iostream>
#include <thread>

using namespace std;

struct Person {
    string first_name;
    string last_name1;
    string last_name2;
    int age;
};

void input_data(Person &person)
{
    cout << "Introduzca el nombre: ";
    getline(cin, person.first_name);

    cout << "Introduzca el primer apellido: ";
    getline(cin, person.last_name1);

    cout << "Introduzca el segundo apellido: ";
    getline(cin, person.last_name2);

    cout << "Introduzca la edad: ";
    cin >> person.age;

    cin.ignore();
}

void display_data(const Person &person)
{
    cout << "Nombre: " << person.first_name << endl;
    cout << "Primer apellido: " << person.last_name1 << endl;
    cout << "Segundo apellido: " << person.last_name2 << endl;
    cout << "Edad: " << person.age << endl;
}

int main()
{
    Person person;

    thread t1(input_data, ref(person));
    t1.join();

    thread t2(display_data, cref(person));
    t2.join();

    return 0;
}
