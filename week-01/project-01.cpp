/*
    MENU
    1. Crea archivo txt llamado cursos y permite registrar varios cursos
    2. Muestra el contenido del archivo cursos
    3. Salir
*/

#include <fstream>
#include <iostream>

using namespace std;

void show_menu()
{
    cout << "\n\t\t\t\tMenú" << endl;
    cout << "[1] Crear archivo .txt llamado cursos y permite registrar varios cursos" << endl;
    cout << "[2] Mostrar el contenido del archivo cursos" << endl;
    cout << "[3] Salir" << endl;
    cout << "\n\n-> Seleccione una opción: ";
}

void create_course_file()
{
    ofstream file("cursos.txt", ios::app);
    if (!file) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string course_name;
    char choice;

    do {
        system("cls");
        cout << "Introduce el nombre del curso: ";
        cin.ignore();
        getline(cin, course_name);

        file << course_name << endl;

        cout << "\n¿Deseas registrar otro curso? (s/n): ";
        cin >> choice;

    } while (choice != 'n' && choice != 'N');

    file.close();
}

void display_courses()
{
    ifstream file("cursos.txt");
    if (!file) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string line;
    cout << "Contenido del archivo cursos:" << endl;
    while (getline(file, line)) {
        cout << "- " << line << endl;
    }

    file.close();
    cout << "\nFin del contenido." << endl;

    system("pause");
}

int main()
{
    int option;

    do {
        system("cls");
        show_menu();
        cin >> option;

        switch (option) {
        case 1:
            system("cls");
            create_course_file();
            break;
        case 2:
            system("cls");
            display_courses();
            break;
        case 3:
            cout << "\nSaliendo del programa..." << endl;
            break;

        default:
            cout << "Opción no válida. Intena de nuevo." << endl;
        }
    } while (option != 3);

    return 0;
}
