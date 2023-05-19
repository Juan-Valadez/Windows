/*Comando para escanear el disco y más*/

#include <iostream>
#include <cstdlib> //Para los casos
#include <conio.h> //Para seleccionar opcion
#include <cstdlib> /*Para la  funcion exit que me sirve para ponerle fin al programa*/

using namespace std;

/*--------------Funciones----------------*/

/*-------Funcion Si o No----*/
int funcionsino(){

/*Esta funcion va a comparar si el caracter introducido es s paso si no termina el programa*/
char s;
cout<<"\tQuieres continuar? s/n ";
cin >> s;
if(s == 'n'){
    system("cls");
    cout << "\nEspero haber sido de ayuda. Gracias por todo ;). ";
    system("pause");
    exit (0);
}
}
/*--END--Funcion Si o No----*/

/*----Funcion eres admin----*/
int funcionadmin(){
/*Al igual que la anterior esta tiene el mismo funcionamiento*/
char n;
cout<<"\tEres admin? s/n ";
cin >> n;
if(n == 'n'){
    system("cls");
    cout << "Deberas de ejecutar este programa como admin ;)\n";
    system("pause");
    exit (0);
}
}

/*------------FIN_Funciones--------------*/

/*--------------------------INICIO--------------------------*/
int main(){

int opcion = 0;
char tecla;
const int numOpciones = 5;
string opciones[numOpciones] = {"Archivos", "Window IMG","Disco","Hardware-Inf","Salir"};

/*Puntero --> Vamos a utilizarlo para almacenar el valore de opcion*/
int *punt = &opcion;
*punt = opcion;

    do {
        // Borrar la pantalla y mostrar la opción seleccionada
        system("cls");/*El sistem cls lo utilizamos para que no nos vuelva a imprimir el menu cada vez que nos movemos por la interfaz del menu*/
        cout << "Que accion quieres realizar?: \n\n";
        for (int i = 0; i < numOpciones; i++) { /*Este for lo utilizamos para saber que casilla esta seleccionada mediante caracteres*/
            if (i == opcion) {
                cout << "[#] " << opciones[i] << endl;
            } else {
                cout << "[ ] " << opciones[i] << endl;
            }
        }

        // Leer la tecla presionada por el usuario
        tecla = getch();

        // Actualizar la opción seleccionada según la tecla presionada. El nº 72 y 80 es el numero que representa esa tecla
        if (tecla == 72 && opcion > 0) { // Flecha hacia arriba restamas uno a opcion (Ej: De arriba abajo segun las opcioes: 1,2,3)
        opcion--;
        } else if (tecla == 80 && opcion < numOpciones - 1) { // Flecha hacia abajo | Tal y como hemos dicho antes pero al contrario
        opcion++;
        }

    } while(tecla != 13); // Continuar hasta que se presione Enter || El nº 13 representa la tecla Enter


/*---------------------CASO---------------------*/

switch(*punt){/*llamamos al puntero que tiene guardado el valor de opcion y segun el valor obtenido de la variable se le asignada un caso*/

/*El funcionamiento de cada caso es muy parejo llamamos a las funciones que creamos antes y ejecutamos un comando en la consola con la funcion system("comando");*/

/*---Caso Cero---*/
case 0:
cout << "\nHas elegido Archivos. Vamos a ejecutar el comando:\nSFC (System File Checker): Verifica y repara los archivos del sistema corruptos.\n\n";
funcionsino();
system("cls");
funcionadmin();
system ("sfc /scannow");
break;

/*---Primer Caso---*/
case 1:
cout << "\nHas elegido Window IMG. Vamos a ejecutar el comando:\nDISM (Deployment Image Servicing and Management): Escanea y repara la imagen de Windows y los componentes del sistema operativo.\n\n";
funcionsino();
system("cls");
funcionadmin();
system ("DISM /Online /Cleanup-Image /ScanHealth");
cout << "En el caso de a ver encontrado algun daño pulse (s) a continuacion.";
funcionsino();
break;

/*---Segundo Caso---*/
case 2:
cout << "\nHas elegido Disco. Vamos a ejecutar el comando:\nCHKDSK: Verifica y repara errores en el disco duro.\n\n";
funcionsino();
system("cls");
funcionadmin();
system ("chkdsk C: /f");
break;

/*---Tercer Caso---*/
case 3:
cout << "\nHas elegido Hardware. Vamos a ejecutar el comando:\nWMIC para sacar informacion del hardware de tu equipo,(en el siguiente orden): Procesador, Sistema Operativo, Modulos de Memoria y Clave del sistema operativo.\n\n";
funcionsino();
system("cls");
system ("wmic cpu get Name, NumberOfCores");
system ("wmic os get Caption, Version, OSArchitecture");
system ("wmic memorychip get Capacity, Speed");
system ("wmic path softwarelicensingservice get OA3xOriginalProductKey");
break;

/*---Cuarto Caso---*/
case 4:
return 0;
break;

}
/*---------------------Fin de casos---------------------*/

/*Vaciar memoria del puntero*/
delete [] punt;
punt = NULL;


return 0;

}