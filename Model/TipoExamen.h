#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct tipoExamen{
	private:
	int id_tipoExamen;
	char descripcion[50];
	int activo;
	
	public:
		
		void ConstructorTipoExamen(int miId_tipoExamen,const char miDescripcion[50],int miActivo){
			this->id_tipoExamen=miId_tipoExamen;
			strcpy(descripcion,miDescripcion);
			this->activo=miActivo;
		}
		
		void TipoExamen(){
			printf("INGRESE ID ");
			scanf("%i",&id_tipoExamen);
			printf("INGRESE DESCRIPCION ");
			scanf("%s",&descripcion);
			printf("INGRESE ACTIVO(1-ACTIVO,2-DESACTIVO) ");
			scanf("%i",&activo);
		}
		
		void setId(){
			printf("INGRESE ID ");
			scanf("%i",&id_tipoExamen);
		}
		
		int getId(){
			return id_tipoExamen;
		}
		
		void setDescripcion(){
			printf("INGRESE DESCRIPCION ");
			scanf("%s",&descripcion);
		}
		
		char* getDescripcion(){
			return descripcion;
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
		
		void imprimirDatosTipoExamen(){
			printf("ID_TIPO_EXAMEN: %i \n",id_tipoExamen);
			printf("DESCRIPCION_EXAMEN: %s \n",descripcion);
			printf("ACTIVO: %i \n",activo);
		}
		
		void imprimirDatosTipoExamenReducido(){
			printf("ID_EXAMEN: %i  DESCRIPCION: %s\n",id_tipoExamen,descripcion);
		}
};
