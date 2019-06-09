#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct materia{
	private:
	int id_materia;
	char nombre[50];
	int id_carrera;
	int id_profesor;
	int anio_cursada;
	int promocion;
	int activo;
	
	public:
		
		void ConstructorMateria(int miId_materia,const char miNombre[50],int miId_carrera,int miId_profesor,
		int miAnio_cursada,int miPromocion,int miActivo){
			this->id_materia=miId_materia;
			strcpy(nombre,miNombre);
			this->id_carrera=miId_carrera;
			this->id_profesor=miId_profesor;
			this->anio_cursada=miAnio_cursada;
			this->promocion=miPromocion;
			this->activo=miActivo;
		}
		
		void Materia(){
			printf("INGRESE ID ");
			scanf("%i",&id_materia);
			printf("INGRESE NOMBRE MATERIA ");
			scanf("%s",&nombre);
			printf("INGRESE ID_CARRERA ");
			scanf("%i",&id_carrera);
			printf("INGRESE ID_PROFESOR ");
			scanf("%i",&id_profesor);
			printf("INGRESE ANIO_CURSADA ");
			scanf("%i",&anio_cursada);
			printf("INGRESE NOTA PROMOCION ");
			scanf("%i",&promocion);
			printf("INGRESE ACTIVO(1-ACTIVO,2-DESACTIVO) ");
			scanf("%i",&activo);
		}
		
		void setIdMateria(){
			printf("INGRESE ID ");
			scanf("%i",&id_materia);
		}
		
		int getIdMateria(){
			return id_materia;
		}
		
		void setNombre(){
			printf("INGRESE NOMBRE ");
			scanf("%s",&nombre);
		}
		
		char* getNombre(){
			return nombre;
		}
		
		void setIdCarrera(){
			printf("INGRESE ID_CARRERA ");
			scanf("%i",&id_carrera);
		}
		
		int getIdCarrera(){
			return id_carrera;
		}
		
		void setIdProfesor(){
			printf("INGRESE ID_PROFESOR ");
			scanf("%i",&id_profesor);
		}
		
		int getIdProfesor(){
			return id_profesor;
		}
		
		void setAnioCursada(){
			printf("INGRESE ANIO_CURSADA ");
			scanf("%i",&anio_cursada);
		}
		
		int getAnioCursada(){
			return anio_cursada;
		}
		
		void setPromocion(){
			printf("INGRESE NOTA PROMOCION ");
			scanf("%i",&promocion);
		}
		
		int getPromocion(){
			return promocion;
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
		
		void imprimirDatosMateria(){
			printf("ID_MATERIA: %i \n",id_materia);
			printf("NOMBRE_MATERIA: %s \n",nombre);
			printf("ID_CARRERA: %i \n",id_carrera);
			printf("ID_PROFESOR: %i \n",id_profesor);
			printf("ANIO_CURSADA: %i \n",anio_cursada);
			printf("NOTA_PROMOCION: %i \n",promocion);
			printf("ACTIVO: %i \n",activo);
		}
		
		void imprimirDatosMateriaReducido(){
			printf("ID: %i NOMBRE: %s CARRERA: %i ANIO: %i \n",id_materia,nombre,id_carrera,anio_cursada);
		}
};
