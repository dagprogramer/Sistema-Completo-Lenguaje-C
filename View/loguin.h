//pantalla loguin
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "fondo.h"
#define ARRIBA 72
#define ABAJO 80
#define TECLAENTER 13


void obtenerPosicion(int,int);
int obtenerMenu(const char *,const char *[],int);

int menuLoguin(){
	int opcion;
	bool repite=true;
	const char *titulo="MENU LOGUIN";
	const char *opciones[]={"INGRESAR USUARIO Y CONTRASENIA","REGRESAR"};
	int elementos=2;
	opcion=obtenerMenu(titulo,opciones,elementos);
	return opcion;
}

int menuEntidades(){
	int opcion;
	const char *titulo="MENU ENTIDADES";
	const char *opciones[]={"CARRERA","ALUMNO","PROFESOR","MATERIA","CORRELATIVA","TIPO DE EXAMEN","NOTA","REGRESAR"};
	int elementos=8;
	opcion=obtenerMenu(titulo,opciones,elementos);
	return opcion;
}

int menuAccion(){
	int opcion;
	const char *titulo="MENU ACCION";
	const char *opciones[]={"AGREGAR","EDITAR","REGRESAR"};
	int elementos=3;
	opcion=obtenerMenu(titulo,opciones,elementos);
	return opcion;
}

int menuAccionUpdate(){
	int opcion;
	const char *titulo="MENU ACCION UPDATE";
	const char *opciones[]={"MODIFICAR ENTIDAD","REGRESAR"};
	int elementos=2;
	opcion=obtenerMenu(titulo,opciones,elementos);
	return opcion;
}

int obtenerMenu(const char *titulo,const char *opciones[],int elementos){
	int opcionSeleccionada=1;
	int tecla;
	bool repite=true;
	do{
		system("cls");
		obtenerPosicion(5,3+opcionSeleccionada);printf("==>");
		obtenerPosicion(15,2);printf("%s",titulo);
		for(int i=0;i<elementos;i++){
			obtenerPosicion(10,4+i);printf("%i-%s",i+1,opciones[i]);
		}
		
		do{
			tecla=getch();
		}while(tecla!=ARRIBA && tecla!=ABAJO && tecla!=TECLAENTER);
		
		switch(tecla){
			case ARRIBA:
				opcionSeleccionada--;
				if(opcionSeleccionada<1){
					opcionSeleccionada=elementos;
				}
				break;
				case ABAJO:
					opcionSeleccionada++;
					if(opcionSeleccionada>elementos){
						opcionSeleccionada=1;
					}
					break;
					case TECLAENTER:
						repite=false;
						break;
		}
	}while(repite);
	return opcionSeleccionada;
}

void obtenerPosicion(int x,int y){
	COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/*
void pantallaLoguin(int posiciones[]){
	Set_Mrc(posiciones[0],posiciones[1],posiciones[2],posiciones[3]);
	barraBienvenida(posiciones[0],posiciones[1],posiciones[2]);
	//barraFormularioLoguin(c1,r2);
}

void pantallaInicio(int posiciones[]){
	Set_Mrc(posiciones[0],posiciones[1],posiciones[2],posiciones[3]);
	barraNavegacion(posiciones[0],posiciones[1],posiciones[2]);
	//barraFormularioEntidadAccion(c1,r2);
}

void pantallaEntidad(int posiciones[],int opc,int accion){
	Set_Mrc(posiciones[0],posiciones[1],posiciones[2],posiciones[3]);
	barraNavegacionEntidad(posiciones[0],posiciones[1],posiciones[2],opc,accion);
}

int pantallaBienvenida(int posiciones[]){
	int opcion;
	Set_Mrc(posiciones[0],posiciones[1],posiciones[2],posiciones[3]);
	barraInicio(posiciones[0],posiciones[1],posiciones[2]);
	scanf("%i",&opcion);
	return opcion;
}

int menu(const char *titulo,const char *opciones[],int elementos){
	int opcion;
	printf("\t\t\t %s \n",titulo);
	for(int i=0;i<elementos;i++){
		printf("\t %i- %s \n",i,opciones[i]);
	}
	printf("\tINGRESE OPCION ");
	scanf("%i",&opcion);
	return opcion;
}

pantallaLoguin(){
	printf("PANTALLA LOGUIN \n");
}

void menuPrincipal(){
	bool repite=true;
	int opcion;
	const char *titulo="MENU PRINCIPAL";
	const char *opciones[]={"INGRESO AL SISTEMA","SALIR"};
	int elementos=2;
	opcion=menu(titulo,opciones,elementos);
	do{
		system("cls");
		switch(opcion){
			case 1:
				pantallaLoguin();
				break;
				case 2:
					repite=false;
					break;
		}
	}while(repite);
}
*/

