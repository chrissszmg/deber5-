
# include < iostream > // cout , cin
# include < string > // string
# include < cstdlib > // rand () , srand ()
# include < ctime > // time ()
using namespace std ;

class Jugador {
private :
string nombre ; 
int puntos ; 
public :

Jugador ( string n , int p ) {
nombre = n ;
puntos = p ;
}
// Getter ( para acceder a private )
string getNombre () {
return nombre ;
}
int getPuntos () {
return puntos ;
}
int sumarPuntos ( int p ) {
    puntos = puntos + p ;
    return puntos ;
}
// Metodo que hace algo
void mostrar () {
cout << "Suma: " << puntos << endl;

}
};

int Generar ( int mazo [13] ) {
    int carta = mazo [ rand () % 13];
    cout << "Nueva carta: " << carta << endl;
    return carta;
}
int main(){
int mazo [13] = {2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 10 , 10 , 10 , 11};
srand ( time (0) ) ;

Jugador jugador1 ( "Jugador 1" , 0 );
int n = Generar ( mazo );
jugador1.sumarPuntos ( n );
jugador1.mostrar();
int n1 = Generar ( mazo );
jugador1.sumarPuntos ( n1 );
jugador1.mostrar();
cout << "Tus cartas: " << n << " , " << n1 << endl;
while (jugador1.getPuntos () < 21 ) {
   char option;
cout << "Pedir carta (p) o Plantarse (s)?" << endl;
cin >>option;
    //Validacion de inputs
    if (option != 'p' && option != 's') {
    cout << "Opcion invalida. Intenta de nuevo." << endl;
    continue;
}
if (option == 'p') {
    int carta = Generar ( mazo );
    jugador1.sumarPuntos ( carta );
    jugador1.mostrar ();

    if (jugador1.getPuntos () > 21 ) {
        cout << "Perdiste!" << endl;
        break;
    }
}
else if (option == 's') {
    cout << "Te plantaste con " << jugador1.getPuntos () << " puntos." << endl;
    break;
}


}


    return 0;

}
