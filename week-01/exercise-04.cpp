// Crea una aplicación que haga uso de un registro donde se pueda almacenar los datos de alumnos universitarios. Estos deben incluir: código, nombres, apellidos, edad, dirección, escuela y posteriormente mostrarlos por pantalla.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string code;
    string first_name;
    string last_name;
    int age;
    string address;
    string school;
};

void add_student(const string &filename)
{
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error al abrir el archivo para escribir" << endl;
        return;
    }

    Student student;

    cout << "\nIntroduce el código del alumno: ";
    getline(cin, student.code);

    cout << "Introduce el nombre del alumno: ";
    getline(cin, student.first_name);

    cout << "Introduce el apellido del alumno: ";
    getline(cin, student.last_name);

    cout << "Introduce la edad del alumno: ";
    cin >> student.age;
    cin.ignore();

    cout << "Introduce la dirección del alumno: ";
    getline(cin, student.address);

    cout << "Introduce la escuela del alumno: ";
    getline(cin, student.school);

    file << student.code << ","
         << student.first_name << ","
         << student.last_name << ","
         << student.age << ","
         << student.address << ","
         << student.school << endl;

    file.close();
}

void display_students(const string &filename)
{
    ifstream file(filename, ios::in);
    if (!file) {
        cerr << "Error al abrir el archivo para leer" << endl;
        return;
    }

    string line;
    cout << "\nLista de alumnos registrados:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main()
{
    string filename = "estudiantes.txt";
    char choice;

    do {
        add_student(filename);

        cout << "\n¿Deseas registrar un nuevo alumno? (s/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice != 'n' && choice != 'N');

    display_students(filename);

    return 0;
}
