// Crea un archivo de texto llamado prueba.txt

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ofstream file("prueba.txt", ios::out);

    // Verificar si el archivo se abrió correctamente
    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    file << "Hello, World!" << endl;
    file.close();

    return 0;
}
