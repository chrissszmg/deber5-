# include <iostream> // cout , cin
# include <string> // string
# include <cstdlib> // rand () , srand ()
# include <ctime> // time ()
using namespace std ;
class Jugador {
    private:
    string nombre;
    char simbolo;
    public:
Jugador (string n, char s) {
        nombre = n;
        simbolo = s;
    }
string getNombre() {
        return nombre;
    }
char getSimbolo() {
        return simbolo;
    }

int pedirCasilla(){
    int casilla;
    cin >> casilla;
    return casilla;
}
};


void mostrarTablero(char t[]) {
    cout << " " << t[0] << " | " << t[1] << " | " << t[2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << t[3] << " | " << t[4] << " | " << t[5] << endl;
    cout << "---|---|---" << endl;
    cout << " " << t[6] << " | " << t[7] << " | " << t[8] << endl;
};

bool hayGanador(char t[]) {
    return (t[0]==t[1] && t[1]==t[2]) ||
           (t[3]==t[4] && t[4]==t[5]) ||
           (t[6]==t[7] && t[7]==t[8]) ||
           (t[0]==t[3] && t[3]==t[6]) ||
           (t[1]==t[4] && t[4]==t[7]) ||
           (t[2]==t[5] && t[5]==t[8]) ||
           (t[0]==t[4] && t[4]==t[8]) ||
           (t[2]==t[4] && t[4]==t[6]);
}

int main(){
Jugador jugador1("Jugador 1", 'X');
Jugador jugador2("Jugador 2", 'O');
char tablero[9] = {'1','2','3','4','5','6','7','8','9'};

int turno =0;
while (true) {
    cout << endl;
    mostrarTablero(tablero);
Jugador& jugadorActual = (turno % 2 == 0) ? jugador1 : jugador2;
cout << jugadorActual.getNombre() << " elige casilla: ";
int pos = jugadorActual.pedirCasilla();
pos--;



if (pos < 0 || pos > 8 || tablero[pos] == 'X' || tablero[pos] == 'O') {
    cout << "Movimiento invalido. Intenta de nuevo." << endl;
    continue;
}



tablero[pos] = jugadorActual.getSimbolo();



if (hayGanador(tablero)) {
    mostrarTablero(tablero);
    cout << jugadorActual.getNombre() << " ha ganado!" << endl;
    break;
}
if (turno == 8) {
    mostrarTablero(tablero);
    cout << "Empate!" << endl;
    break;
}
turno++;
}







    return 0;
}