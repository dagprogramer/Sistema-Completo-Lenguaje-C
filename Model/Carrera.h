#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct carrera{
	private:
	int id_carrera;
	char nombre[50];
	int duracion;
	int activo;
	
	public:
		
		void ConstructorCarrera(int miId_carrera,const char miNombre[50],int miDuracion,int miActivo){
			this->id_carrera=miId_carrera;
			strcpy(nombre,miNombre);
			this->duracion=miDuracion;
			this->activo=miActivo;
		}
		
		void Carrera(){
			printf("INGRESE ID ");
			scanf("%i",&id_carrera);
			printf("INGRESE NOMBRE CARRERA ");
			scanf("%s",&nombre);
			printf("INGRESE DURACION(ANIOS) ");
			scanf("%i",&duracion);
			printf("INGRESE ACTIVO(1-ACTIVO,2-DESACTIVO) ");
			scanf("%i",&activo);
		}
		
		void setId(){
			printf("INGRESE ID ");
			scanf("%i",&id_carrera);
		}
		
		int getId(){
			return id_carrera;
		}
		
		void setNombre(){
			printf("INGRESE NOMBRE CARRERA ");
			scanf("%s",&nombre);
		}
		
		char* getNombre(){
			return nombre;
		}
		
		void setDuracion(){
			printf("INGRESE DURACION(ANIOS) ");
			scanf("%i",&duracion);
		}
		
		int getDuracion(){
			return duracion;
		}
		
		void setActivo(){
			printf("INGRESE ACTIVO(1-ACTIVO,2-DESACTIVO) ");
			scanf("%i",&activo);
		}
		
		int getActivo(){
			return activo;
		}
		
		void setDesactivo(int desactivo){
			this->activo=desactivo;
		}
		
		void imprimirDatosCarrera(){
			printf("ID_CARRERA: %i \n",id_carrera);
			printf("NOMBRE_CARRERA: %s \n",nombre);
			printf("DURACION: %i \n",duracion);
			printf("ACTIVO: %i \n",activo);
		}
		
		void imprimirDatosCarreraReducido(){
			printf("ID_CARRERA: %i NOMBRE_CARRERA: %s",id_carrera,nombre);
		} 
};
