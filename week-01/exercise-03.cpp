// Realice un programa que pida al usuario el nombre o ubicación de un fichero de texto (archivo del ejercicio 2) y, a continuación, añada texto en él (cursos electivos y el ciclo correspondiente; indicar que son cursos electivos) hasta el final de la carrera.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Course {
    string name;
    string cycle;
};

void saveCoursesToFile(const string &filename, const vector<Course> &courses)
{
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error al abrir el archivo para escribir" << endl;
        return;
    }

    for (const auto &course : courses) {
        file << "Curso Electivo: " << course.name << ", "
             << "Ciclo: " << course.cycle << endl;
    }

    file.close();
}

int main()
{
    string filename;
    cout << "Introduce el nombre del fichero: ";
    cin >> filename;

    vector<Course> courses;
    char choice;

    do {
        Course course;
        cout << "\nIntroduce el nombre del curso electivo: ";
        cin.ignore();
        getline(cin, course.name);

        cout << "Introduce el ciclo: ";
        getline(cin, course.cycle);

        courses.push_back(course);

        cout << "\n¿Quieres añadir otro curso? (s/n): ";
        cin >> choice;

    } while (choice != 'n' || choice != 'N');

    saveCoursesToFile(filename, courses);

    return 0;
}
