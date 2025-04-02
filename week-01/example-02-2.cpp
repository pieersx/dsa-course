// Este otro ejemplo también hace un trabajo similar al anterior, pero en este caso, el nombre del archivo y el contenido del archivo se lo ingresa por consola.

#include <fstream>
#include <iostream>

using namespace std;

void create_file(const string &filename, const string &content)
{
    ofstream file(filename, ios::out);

    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    file << content << endl;
    file.close();
}

int main()
{
    string filename;
    string content;

    cout << "Introduzca el nombre del archivo a crear: ";
    getline(cin, filename);

    cout << "Introduzca el contenido del archivo: ";
    getline(cin, content);

    create_file(filename, content);

    return 0;
}
