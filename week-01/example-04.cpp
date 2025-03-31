// Agrega texto a un archivo existente.

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ofstream file("cursos.txt", ios::app);

    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    file << "Curso: Investigación Operativa, "
         << "Ciclo: Ciclo V, "
         << "Escuela: FISI" << endl;

    file.close();

    return 0;
}
