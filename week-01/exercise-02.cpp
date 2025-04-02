// Realice un programa que pida al usuario el nombre o ubicación de un fichero de texto (archivo del ejercicio 1) y, a continuación, dé lectura a todo el fichero y muestre en pantalla su contenido.

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    string filename;
    cout << "Introduce el nombre del fichero: ";
    cin >> filename;

    ifstream file(filename, ios::in);
    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();

    return 0;
}
