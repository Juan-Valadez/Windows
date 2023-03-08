#include <iostream>

using namespace std;

int main(){

cout<<endl;

    cout<<"    ###                                        ###       ##"<<endl;
    cout<<"   ####                                         ##"<<endl;
    cout<<"  ## ##             ####    #####               ##      ###     #####     ####     ####"<<endl;
    cout<<" ##  ##            ##  ##   ##  ##              ##       ##     ##  ##   ##  ##       ##"<<endl;
    cout<<" #######           ######   ##  ##              ##       ##     ##  ##   ######    #####"<<endl;
    cout<<"     ##            ##       ##  ##              ##       ##     ##  ##   ##       ##  ##"<<endl;
    cout<<"     ##             #####   ##  ##             ####     ####    ##  ##    #####    #####"<<endl<<endl;


cout << "\n \tCuatro en raya! El desafio de la estrategia y la concentracion!"<<endl<<endl;
cout << "\t Jugador 1: X"<<endl;
cout << "\t Jugador 2: O"<<endl<<endl;

//Quieres Jugar?
char s;
cout<<"         Quieres Jugar? s/n ";
cin >> s;
if(s == 'n'){
    return 0;
}
cout<<endl;

//---------------------------------Tablero---------------------------------

//t1 son las filas y t2 las columnas
int t1=8,t2=8;
char tablero[t1][t2];

for(int i=0;i<t1;i++){
    cout << "    " << i <<" ";
}
for(int i=0;i<t1;i++){cout<<endl;
    for(int a=0;a<t2;a++){
        tablero[i][a] = '-';
        cout <<"    "<<tablero[i][a]<<" ";
    }
}
cout<<endl<<endl;

//--------------------------------1 VS 1----------------------------------

int datos = 0;
int num=0;
int jugador = 2;
int lb=7;
datos = t1 * t2;

//---------- Inicio del juego---------------
for(int i=0;i<datos;i++){

//-----Jugador---------------
if(i % 2 == 0){
    jugador = 1;
}else{
    jugador = 2;
}

//-----Numero de columna------
cout << "Jugador "<<jugador <<" diga un numero del 0-7: ";cin>>num;cout<<endl;
while(num>7 || num<0){
    cout << "Este numero esta fuera del rango del tablero"<<endl;
    cout << "Intentelo de nuevo: ";cin>>num;cout<<endl;}



//--------------------------ESPACIOS LIBRES-----------------------

//-----Fichas encima de otras
lb = 7;
if(tablero[7][num] == 'X' || tablero[7][num] == 'O'){
lb = lb - 1;
}
if(tablero[6][num] == 'X' || tablero[6][num] == 'O'){
lb = lb - 1;
}
if(tablero[5][num] == 'X' || tablero[5][num] == 'O'){
lb = lb - 1;
}
if(tablero[4][num] == 'X' || tablero[4][num] == 'O'){
lb = lb - 1;
}
if(tablero[3][num] == 'X' || tablero[3][num] == 'O'){
lb = lb - 1;
}
if(tablero[2][num] == 'X' || tablero[2][num] == 'O'){
lb = lb - 1;
}
if(tablero[1][num] == 'X' || tablero[1][num] == 'O'){
lb = lb - 1;
}
if(tablero[0][num] == 'X' || tablero[0][num] == 'O'){
lb = lb - 1;
}else{}

//-------------Columna libre por columna
int espc=0;

for(int e=0;e<8;e++){
    if (tablero[e][num] == 'X' || tablero[e][num] == 'O'){
        espc = espc + 1;
    }
}

while(espc == 8){
    cout << "\n NO hay mas espacio en esta columna";
    cout << "\n Has perdido el turno. ";cin>>num;cout<<endl;
    i = i - 1;

for(int e=0;e<8;e++){
    if (tablero[e][num] != 'X' || tablero[e][num] != 'O'){
        espc = espc - 1;
    }
}
}

//------------------------  Salida por tablero tablero Jugador 1---------------------

if(jugador == 1){


//Numero de arriba del tablero
for(int n=0;n<t1;n++){
    cout << "    " << n <<" ";
}

//tablero
for(int b=0;b<t1;b++){
cout<<endl;
    for(int a=0;a<t2;a++){
        tablero[lb][num] = 'X';
        cout <<"    "<<tablero[b][a]<<" ";
    }
}
}
cout<<endl<<endl;

//------------------------  Salida por tablero tablero Jugador 2 -------------------
if(jugador == 2){

//Numero de arriba del tablero
for(int n=0;n<t1;n++){
    cout << "    " << n <<" ";
}

//tablero
for(int b=0;b<t1;b++){
cout<<endl;
    for(int a=0;a<t2;a++){
        tablero[lb][num] = 'O';
        cout <<"    "<<tablero[b][a]<<" ";
    }
}
}
cout<<endl<<endl;


//-----------------------------------GANADOR JUGADOR 1-------------------------------------------

//-------------- Horizontal
for(int g = 0; g < 8; g++) {
    for(int j = 0; j < 5; j++) {
        if(tablero[g][j] == 'X' && tablero[i][j+1] == 'X' && tablero[g][j+2] == 'X' && tablero[g][j+3] == 'X') {
            cout <<"\t - El jugador 1 ha ganado en horizontal -"<<endl<<endl;
            return 0;
        }
    }
}

//-------------- Verificar
for(int g = 0; g < 5; g++) {
    for(int j = 0; j < 8; j++) {
        if(tablero[g][j] == 'X' && tablero[g+1][j] == 'X' && tablero[g+2][j] == 'X' && tablero[g+3][j] == 'X') {
            cout <<"\t - El jugador 1 ha ganado en vertical -"<<endl<<endl;
            return 0;
        }
    }
}

// Diagonal (izquierda a derecha)
for(int g = 0; g < 5; g++) {
    for(int j = 0; j < 5; j++) {
        if(tablero[g][j] == 'X' && tablero[g+1][j+1] == 'X' && tablero[g+2][j+2] == 'X' && tablero[g+3][j+3] == 'X') {
            cout <<"\t - El jugador 1 ha ganado en diagonal (izquierda a derecha) -"<<endl<<endl;
            return 0;
        }
    }
}

// Diagonal (derecha a izquierda)
for(int g = 0; g < 5; g++) {
    for(int j = 3; j < 8; j++) {
        if(tablero[g][j] == 'X' && tablero[g+1][j-1] == 'X' && tablero[g+2][j-2] == 'X' && tablero[g+3][j-3] == 'X') {
            cout << "\t - El jugador 1 ha ganado en diagonal (derecha a izquierda) -"<<endl<<endl;
            return 0;
        }
    }
}

//-----------------------------------GANADOR JUGADOR 2-------------------------------------------

//-------------- Horizontal
for(int g = 0; g < 8; g++) {
    for(int j = 0; j < 5; j++) {
        if(tablero[g][j] == 'O' && tablero[i][j+1] == 'O' && tablero[g][j+2] == 'O' && tablero[g][j+3] == 'O') {
            cout <<"\t - El jugador 2 ha ganado en horizontal -"<<endl<<endl;
            return 0;
        }
    }
}

//-------------- Verificar
for(int g = 0; g < 5; g++) {
    for(int j = 0; j < 8; j++) {
        if(tablero[g][j] == 'O' && tablero[g+1][j] == 'O' && tablero[g+2][j] == 'O' && tablero[g+3][j] == 'O') {
            cout <<"\t El jugador 2 ha ganado en vertical "<<endl<<endl;
            return 0;
        }
    }
}

// Diagonal (izquierda a derecha)
for(int g = 0; g < 5; g++) {
    for(int j = 0; j < 5; j++) {
        if(tablero[g][j] == 'O' && tablero[g+1][j+1] == 'O' && tablero[g+2][j+2] == 'O' && tablero[g+3][j+3] == 'O') {
            cout <<"\t El jugador 2 ha ganado en diagonal (izquierda a derecha)"<<endl<<endl;
            return 0;
        }
    }
}

// Diagonal (derecha a izquierda)
for(int g = 0; g < 5; g++) {
    for(int j = 3; j < 8; j++) {
        if(tablero[g][j] == 'O' && tablero[g+1][j-1] == 'O' && tablero[g+2][j-2] == 'O' && tablero[g+3][j-3] == 'O') {
            cout << "\t El jugador 2 ha ganado en diagonal (derecha a izquierda)"<<endl<<endl;
            return 0;
        }
    }
}

//--------------------------------FIN 1 VS 1----------------------------------
}
cout << "No hay mas espacio en el tablero";

    return 0;
}