// Este otro ejemplo también hace un trabajo similar al anterior, pero en este caso, el nombre del archivo y el contenido del archivo se lo ingresa por consola.

#include <fstream>
#include <iostream>

using namespace std;

void create_file(const string &filename, const string &content)
{
    ofstream file(filename);

    if (!file) {
        cerr << "Error opening file" << endl;
        return;
    }

    file << content << endl;
    file.close();
}

int main()
{
    string filename;
    string content;

    cout << "Enter the name of the file to create: ";
    getline(cin, filename);

    cout << "Enter the content of the file: ";
    getline(cin, content);

    create_file(filename, content);

    return 0;
}
