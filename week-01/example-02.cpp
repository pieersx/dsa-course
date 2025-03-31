// Crea un archivo de texto llamado prueba.txt

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ofstream file("prueba.txt");

    // Verificar si el archivo se abrió correctamente
    if (!file) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    file << "Hello, World!" << endl;
    file.close();
}
