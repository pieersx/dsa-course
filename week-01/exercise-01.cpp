// Realice un programa que pida al usuario el nombre de un fichero de texto y, a continuación, permita almacenar al usuario una lista de todos los cursos que ha llevado hasta el presente ciclo, incluido el ciclo correspondiente y la escuela a la que pertenece.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Course {
    string name;
    string cycle;
    string school;
};

void add_courses_to_file(const string &filename, const vector<Course> &courses)
{
    ofstream file(filename, ios::out);
    if (!file) {
        cerr << "Error al abrir el archivo para escribir" << endl;
        return;
    }

    for (const auto &course : courses) {
        file << "Curso: " << course.name << ", "
             << "Ciclo: " << course.cycle << ", "
             << "Escuela: " << course.school << endl;
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

    } while (choice != 'n');

    add_courses_to_file(filename, courses);

    return 0;
}
