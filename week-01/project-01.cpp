/*
            MENU
    [1] Agregar cursos"
    [2] Leer archivo"
    [3] Agregar cursos electivos"
    [4] Registrar estudiantes"
    [5] Mostrar estudiantes registrados"
    [6] Salir del menú"
*/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Course {
    string name;
    string cycle;
    string school;
};

struct Student {
    string code;
    string first_name;
    string last_name;
    int age;
    string address;
    string school;
};

void show_menu()
{
    cout << "\n\t\t\t\tMenú" << endl;
    cout << "[1] Agregar cursos" << endl;
    cout << "[2] Leer archivo" << endl;
    cout << "[3] Agregar cursos electivos" << endl;
    cout << "[4] Registrar estudiantes" << endl;
    cout << "[5] Mostrar estudiantes registrados" << endl;
    cout << "[6] Salir del menú" << endl;
    cout << "\n-> Seleccione una opción: ";
}

void add_courses_to_file(const string &filename)
{
    ofstream file(filename, ios::out);
    if (!file) {
        cerr << "Error al abrir el archivo para escribir" << endl;
        return;
    }

    vector<Course> courses;
    char choice;

    do {
        Course course;

        cout << "\nIntroduce el nombre del curso: ";
        cin.ignore();
        getline(cin, course.name);

        cout << "Introduce el ciclo: ";
        getline(cin, course.cycle);

        cout << "Introduce la escuela: ";
        getline(cin, course.school);

        courses.push_back(course);

        cout << "\n¿Quieres añadir otro curso? (s/n): ";
        cin >> choice;

    } while (choice != 'n' && choice != 'N');

    for (const auto &course : courses) {
        file << "Curso: " << course.name << ", "
             << "Ciclo: " << course.cycle << ", "
             << "Escuela: " << course.school << endl;
    }

    file.close();
}

void read_file(const string &filename)
{
    ifstream file(filename, ios::in);
    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    string line;
    cout << "\n--- Contenido al abrir el archivo ---" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void add_elective_courses(const string &filename)
{
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error al abrir el archivo para escribir" << endl;
        return;
    }

    vector<Course> courses;
    char choice;

    do {
        Course course;

        cout << "\nIntroduce el nombre del curso electivo: ";
        cin.ignore();
        getline(cin, course.name);

        cout << "Introduce el ciclo: ";
        getline(cin, course.cycle);

        cout << "Introduce la escuela: ";
        getline(cin, course.school);

        courses.push_back(course);

        cout << "\n¿Quieres añadir otro curso? (s/n): ";
        cin >> choice;

    } while (choice != 'n' && choice != 'N');

    for (const auto &course : courses) {
        file << "Curso Electivo: " << course.name << ", "
             << "Ciclo: " << course.cycle << ", "
             << "Escuela: " << course.cycle << endl;
    }

    file.close();
}

void add_student(const string &filename)
{
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error al abrir el archivo para escribir" << endl;
        return;
    }

    Student student;

    cout << "\nIntroduce el código del alumno: ";
    cin.ignore();
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

    file << student.code << "," << student.first_name << ","
         << student.last_name << "," << student.age << ","
         << student.address << "," << student.school << endl;

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
    string filename;
    int option;

    do {
        system("cls");
        show_menu();
        cin >> option;

        switch (option) {
        case 1:
            // system("clear");
            cout << "Introduce el nombre del archivo: ";
            cin >> filename;
            add_courses_to_file(filename);
            // create_course_file();
            break;
        case 2:
            system("cls");
            cout << "Introduce el nombre del archivo: ";
            cin >> filename;
            read_file(filename);
            // display_courses();
            break;
        case 3:
            cout << "Introduce el nombre del archivo: ";
            cin >> filename;
            add_elective_courses(filename);
            break;
        case 4:
            add_student("estudiantes.txt");
            break;
        case 5:
            display_students("estudiantes.txt");
            break;
        case 6:
            cout << "\nSaliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Intena de nuevo." << endl;
            system("pause");
        }
    } while (option != 6);

    return 0;
}
