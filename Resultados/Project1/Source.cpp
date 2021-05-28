#include <iostream>
#include <vector>  
#include <string>  
#include <stdio.h>  
#include <stdlib.h> 
#include <string>
#include <map>


#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>

using namespace std;
using namespace cgicc;
ifstream archivo;

void BusquedaOptimizada(string search) {

    vector<string> searches;
    string delim = " ";
    size_t prev = 0, pos = 0;

    do
    {
        pos = search.find(delim, prev);
        if (pos == string::npos) pos = search.length();
        string token = search.substr(prev, pos - prev);
        if (!token.empty()) searches.push_back(token);
        prev = pos + delim.length();
    } while (pos < search.length() && prev < search.length());

    string path_diccionario = "C:\\Users\\cesar\\OneDrive\\Documents\\Tareas Uni\\8vo Semestre\\Proyectos Ing Software\\Actividad 1\\Actividad 13\\Diccionario.txt";
    string path_posting = "C:\\Users\\cesar\\OneDrive\\Documents\\Tareas Uni\\8vo Semestre\\Proyectos Ing Software\\Actividad 1\\Actividad 13\\Posting.txt";
    string path_documentos = "C:\\Users\\cesar\\OneDrive\\Documents\\Tareas Uni\\8vo Semestre\\Proyectos Ing Software\\Actividad 1\\Actividad 12\\Documentos.txt";

    vector<string> diccionario;
    vector<string> posting;
    vector<string> documentos;

    archivo.open(path_posting);
    string line;

    //Agregamos la informacion del archivo posting
    while (getline(archivo, line)) {
        posting.push_back(line);
    }

    archivo.close();

    archivo.open(path_documentos);
    string line2;

    //Agregamos la informacion del archivo documentos
    while (getline(archivo, line2)) {
        documentos.push_back(line2);
    }

    archivo.close();

    std::map<string, double> files;

    int max = 10;

    cout << "<ul style='list-style:none;'>";

    for (const auto& s : searches) {

        if (max == 0) {
            break;
        }

        archivo.open(path_diccionario);
        string line3;

        //Agregamos la informacion del archivo diccionario
        while (getline(archivo, line3)) {

            int pos = line3.find(";");
            string palabra = line3.substr(0, pos);

            if (palabra == s) {
                size_t uno = line3.find(";");
                size_t dos = line3.find_last_of(";");

                int repeticiones = stoi(line3.substr(uno + 1, dos - uno - 1));
                int indicePost = stoi(line3.substr(line3.find_last_of(";") + 1));

                for (int i = 0; i < repeticiones; i++) {

                    if (max == 0) {
                        break;
                    }

                    string postingLine = posting.at(indicePost + i);
                    int po = postingLine.find(";");
                    string fileSource = postingLine.substr(0, po);

                    cout << "<li><a href='Files\\" << fileSource << "'>Files\\"<< fileSource << "</a></li>";

                    max--;

                }
            }

        }
        archivo.close();
    }
    cout << "</ul>";

    if (max == 10) {
        cout << "<h1>No hay resultados</h1>";
    }

}

int main() 
{
    Cgicc formData;

    cout << "Content-Type:text/html \n\n";

    cout << "<html>";
    cout << "  <head>";
    cout << "    <title>Resultados</title>";
    cout << "  </head>";
    cout << "  <body style='background:#a7cdec;'>";
    cout << "    <div>";
    cout << "       <div style=' margin-left:20%; margin-right:20%; background-color:EAABDA; height:100px; display:flex; justify-content:center; border-radius:90px; color: white;'>";
   
    form_iterator fi = formData.getElement("search");
    if (!fi->isEmpty() && fi != (*formData).end()) {
        cout << "        <h1>Results of: " << **fi << "</h1>";
        cout << "      </div>";
        cout << "      <br/>";
        cout << "      <div style='margin-left:20%; margin-right:20%; height:100px; display:flex; color: white; justify-content:center;'>";

        BusquedaOptimizada(**fi);

        cout << "      </div>";
        cout << "    </div>";
    }
    else {
        cout << "        <h1>No text entered</h1>";
        cout << "      </div>";
        cout << "      <br/>";
        cout << "      <div style='margin-left:20%; margin-right:20%; height:100px; display:flex; color: white; justify-content:center;'>";
        cout << "      </div>";
        cout << "    </div>";
    }

    cout << "    <br/>";
    cout << "    <div>";
    cout << "       <img style='max-width: 200px; max-height: 200px; display: block; margin: auto; position:relative; top:29em; 'src='https://xn--l8ja2b6546b.com/img/minatoaqua_angry.png'>";
    cout << "     </div>";
    cout << "     <footer>";
    cout << "       <div style=' background-color: #313873; position: absolute; bottom:0; width:99%; height:40px; color: white; align-items: center; '>";
    cout << "         <div style='text-align: center; list-style: none; justify-content: center;'>";
    cout << "           <li><b>Busqueda</b><br /></li>";
    cout << "         </div>";
    cout << "       </div>";
    cout << "     </footer>";
    cout << "   </body>";
    cout << " </html>";
}

