#include <iostream>
using namespace std;

int main()
{
    cout << "Content-Type:text/html \n\n";
    cout << "<html>";
    cout << "<head>";
    cout << "<title>Buscador</title>";
    cout << "</head>";
    cout << "<div style='background: #a7cdec; '>";
    cout << "<body style='background: #a7cdec; '>";
    cout << "<div style=' margin-left:20%; margin-right:20%; background-color:EAABDA; height:100px; display:flex; justify-content:center; border-radius:70px; '>";
    cout << "<div style='color:white; font-family:'Trebuchet MS', 'Lucida Sans Unicode', 'Lucida Grande', 'Lucida Sans', Arial, sans-serif;'>";
    cout << "<h1>Search Engine</h1>";
    cout << "</div>";
    cout << "</div>";

    cout << "<br/>";

    cout << "<div style='margin-left:20%; margin-right:20%; display:flex; justify-content:center;'>";
    cout << "<form action='/Buscador/Resultados.cgi' method='post'>";
    cout << "<div style='display: flex; color:#313873; font-family: 'Trebuchet MS', 'Lucida Sans Unicode', 'Lucida Grande', 'Lucida Sans', Arial, sans-serif;'>";
    cout << "<label for='fname'>Enter your search:</label><br />";
    cout << "</div>";
    cout << "<input name='search' type='text' /><br />";
    cout << "<div>";
    cout << "<div style='justify-content:center; align-items:center;'>";
    cout << "<br><button>Search</button>";
    cout << "</div>";
    cout << "</div>";
    cout << "</form>";
    cout << "</div>";
    cout << "<br />";
    cout << "<div>";
    cout << "<img style='max-width: 200px; max-height: 200px; display: block; margin: auto; position:relative; top:29em; 'src='https://xn--l8ja2b6546b.com/img/minatoaqua_angry.png'>";
    cout << "</div>";

    cout << "<footer>";
    cout << "<div style=' background-color: #313873; position: absolute; bottom:0; width:99%; height:40px; color: white; align-items: center; '>";
    cout << "<div style='text-align: center;'>";
    cout << "<li>";
    cout << "<b>Equipo</b><br/>Miguel Ruvalcaba, Cesar Magana, Eli Barrios, Julio Zamora, Jorge Gomez, Cesar Lopez.";
    cout << "</li>";
    cout << "</div>";
    cout << "</div>";
    cout << "</footer>";
    cout << "</body>";
    cout << "</div>";
    cout << "</html>";

    cout << "</body></html>";

    return 0;
}