#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
class Jugador {
    private:
    string nombre;
    int monedas = 100;
    public:
int getMonedas() {
        return monedas;
    }
int apostar(int cantidad){
    if (cantidad > monedas) {
        cout << "No tienes suficientes monedas." << endl;
        return -1;
    }

    monedas -= cantidad;
    return cantidad;
}
void ganar(int cantidad) {
    monedas += cantidad;
}
void mostrarSaldo(){
    cout << "Saldo actual: " << monedas << " monedas." << endl;

}
};

int main(){
srand(time(0));
Jugador jugador1;
jugador1.mostrarSaldo();
char option;
while (jugador1.getMonedas() > 0) {
    jugador1.mostrarSaldo();
    cout << "Tirar s/n: "<< endl;
    cin >> option;
    if (option != 's' && option != 'n') {
            cout << "Opcion invalida" << endl;
            continue;
    }
    if (option == 'n') {
        break;
    }
     if (jugador1.getMonedas() < 10) {
            cout << "No tienes monedas suficientes para jugar." << endl;
            break;
        }
    jugador1.apostar(10);

char simbolos[4] = {'@', '#', '$', '%'};

char r1 = simbolos [ rand () % 4];
char r2 = simbolos [ rand () % 4];
char r3 = simbolos [ rand () % 4];
cout << "[ " << r1 << " ] [ " << r2 << " ] [ " << r3 << " ]" << endl ;
if (r1 == r2 && r2 == r3) {
    jugador1.ganar(50);
    cout << "3 iguales! Ganas 50 monedas" << endl;
}
else if (r1 == r2 || r1 == r3 || r2 == r3) {
    jugador1.ganar(20);
    cout << "2 iguales! Ganas 20 monedas" << endl;
}
else {
    cout << "No ganaste nada" << endl;
}
}

cout << "Juego terminado" << endl;
cout << "Monedas finales: " << jugador1.getMonedas() << endl;










    return 0;
}

