// Lee un archivo de texto.

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream file("cursos.txt");

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
