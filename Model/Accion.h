#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>


struct accion{
	private:
	int entidad;
	int accion;
	
	public:
		
		void ContructorAccion(int miEntidad,int miAccion){
			this->entidad=miEntidad;
			this->accion=miAccion;
		}
		
		void Accion(){
			printf("INGRESE ENTIDAD(1-Carrera,2-Alumno,3-Profesores,4-Materias,5-Correlativas,6-TipoExamen,7-Nota) ");
			scanf("%i",&entidad);
			printf("INGRESE ACCION(1-AGREGAR,2-EDITAR,3-ELIMINAR) ");
			scanf("%i",&accion);
		}
		
		void setEntidad(){
			printf("INGRESE ENTIDAD ");
			scanf("%i",&entidad);
		}
		
		int getEntidad(){
			return entidad;
		}
		
		void setAccion(){
			printf("INGRESE ACCION(1-AGREGAR,2-EDITAR,3-ELIMINAR) ");
			scanf("%i",&accion);
		}
		
		int getAccion(){
			return accion;
		}
		
		void imprimirAccion(){
			printf("ENTIDAD: %i ACCION: %i",entidad,accion);
		}
};
