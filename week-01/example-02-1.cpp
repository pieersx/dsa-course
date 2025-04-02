// Este ejemplo hace un trabajo similar al anterior, la diferencia esta en que el nombre del archivo se lo ingresa por consola.

#include <fstream>
#include <iostream>

using namespace std;

void create_file(const string &filename)
{
    ofstream file(filename, ios::out);

    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    file << "Hello, World!" << endl;
    file.close();
}

int main()
{
    string filename;
    cout << "Introduzca el nombre del archivo a crear: ";
    getline(cin, filename);

    create_file(filename);

    return 0;
}
