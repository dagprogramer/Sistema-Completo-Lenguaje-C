/*
  Utiliza color, ubicación de texto y marco.
*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <string.h>

void ir_cr(int x, int y)//Emulador de ir_cr
{
    /*
       funcion: crea función para ubicar printf en columna y renglón especifico
    por lo esta funcion emula ir_cr para posicionar texto en coordenadas especificas
    se tiene que declarar <windows.h>
    */
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Set_Mrc(int c1,int r1,int c2,int r2) // construye marco
{
    /*   
    funcion: crea marco con codigo ascii
    c1-----------c2
    r1            |
    |             |
    |             |
    -------------r2
    */
   int i;
   ir_cr(c1,r1); printf("%c",201);      // esquinas
   ir_cr(c1,r2); printf("%c",200);
   ir_cr(c2,r1); printf("%c",187);
   ir_cr(c2,r2); printf("%c",188);
   for(i=c1+1;i<c2;i++)                 // controla columna
   {
         ir_cr(i,r1);printf("%c",205);  // LINEA ARRIBA HORIZONTAL
         ir_cr(i,r2);printf("%c",205);  // LINEA ABAJO HORIZONTAL
   }
   for(i=r1+1;i<r2;i++)                 // controla renglon
   {
         ir_cr(c1,i);printf("%c",186);  // LINEA IZQUIERDA VERTICAL
         ir_cr(c2,i);printf("%c",186);  // LINEA DERECHA VERTICAL
   }   
}

void barraBienvenida(int c1,int r1,int c2){
	int col1=c1+1;
	int fil1=r1+1;
	int col2=c2-1;
	int fil2=r1+4;
    Set_Mrc(col1,fil1,col2,fil2);   
   ir_cr(col1+1,fil1+1);printf("BIENVENIDOS A ITUOM 401 CASEROS");
}

void barraInicio(int c1,int r1,int c2){
	int col1=c1+1;
	int fil1=r1+1;
	int col2=c2-1;
	int fil2=r1+4;
    Set_Mrc(col1,fil1,col2,fil2);   
    ir_cr(col1+1,fil1+1);printf("INICIO DEL SISTEMA");
    ir_cr(col1+1,fil1+4);printf("1-PANTALLA LOGUIN");
    ir_cr(col1+1,fil1+5);printf("2-SALIR");
    ir_cr(col1+1,fil1+6);printf("INGRESE LA OPCION ");
}

void barraNavegacion(int c1,int r1,int c2){
	int col1=c1+1;
	int fil1=r1+1;
	int col2=c2-1;
	int fil2=r1+4;
	int dim=7;
	int dim_length=fil1;
	char entidades[dim][30]={{"Carrera"},{"Alumno"},{"Profesores"},{"Materias"},{"Correlativas"},{"TipoExamen"},{"Nota"}};
    Set_Mrc(col1,fil1,col2,fil2);
    for(int i=0;i<dim;i++){
    	ir_cr(dim_length+1,col1+1);printf("%i%s",i+1,entidades[i]);
    	dim_length+=(strlen(entidades[i])+1);
	}
}

void barraNavegacionEntidad(int c1,int r1,int c2,int opc_entidad,int opc_accion){
	int col1=c1+1;
	int fil1=r1+1;
	int col2=c2-1;
	int fil2=r1+4;
	int dim=7;
	int dim_length=fil1;
	char entidades[dim][30]={{"Carrera"},{"Alumno"},{"Profesores"},{"Materias"},{"Correlativas"},{"TipoExamen"},{"Nota"}};
	char acciones[3][30]={{"1-AGREGAR"},{"2-EDITAR"},{"2-ELIMINAR"}};
    Set_Mrc(col1,fil1,col2,fil2);
    ir_cr(dim_length+1,col1+1);printf("%i%s %s",opc_entidad+1,entidades[opc_entidad],acciones[opc_accion]);
}


