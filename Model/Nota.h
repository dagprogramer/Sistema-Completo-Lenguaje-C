#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct nota{
	private:
	int id_nota;
	int legajo;
	int id_materia;
	int valor;
	char fecha[50];
	int tipo_exmanen;
	int activo;
	
	public:
		
		void ConstructorNota(int miId_nota,int miLegajo,int miId_materia,int miValor,const char miFecha[50],
		int miTipo_exmanen,int miActivo){
			this->id_nota=miId_nota;
			this->legajo=miLegajo;
			this->id_materia=miId_materia;
			this->valor=miValor;
			strcpy(fecha,miFecha);
			this->tipo_exmanen=miTipo_exmanen;
			this->activo=miActivo;
		}
		
		void Nota(){
			printf("INGRESE ID_NOTA ");
			scanf("%i",&id_nota);
			printf("INGRESE LEGAJO ");
			scanf("%i",&legajo);
			printf("INGRESE ID_MATERIA ");
			scanf("%i",&id_materia);
			printf("INGRESE VALOR ");
			scanf("%i",&valor);
			printf("INGRESE FECHA(dd/mm/yy) ");
			scanf("%s",&fecha);
			printf("INGRESE ID_TIPO_EXAMEN ");
			scanf("%i",&tipo_exmanen);
			printf("INGRESE ACTIVO(1-ACTIVO,2-DESACTIVO) ");
			scanf("%i",&activo);
		}
		
		void setId(){
			printf("INGRESE ID_NOTA ");
			scanf("%i",&id_nota);
		}
		
		int getId(){
			return id_nota;
		}
		
		void setLegajo(){
			printf("INGRESE LEGAJO ");
			scanf("%i",&legajo);
		}
		
		int getLegajo(){
			return legajo;
		}
		
		void setIdMateria(){
			printf("INGRESE ID_MATERIA ");
			scanf("%i",&id_materia);
		}
		
		int getIdMateria(){
			return id_materia;
		}
		
		void setValor(){
			printf("INGRESE VALOR ");
			scanf("%i",&valor);
		}
		
		int getValor(){
			return valor;
		}
		
		void setFecha(){
			printf("INGRESE FECHA(dd/mm/yy) ");
			scanf("%s",&fecha);
		}
		
		char* getFecha(){
			return fecha;
		}
		
		void setTipoExamen(){
			printf("INGRESE ID TIPO_EXAMEN ");
			scanf("%i",&tipo_exmanen);
		}
		
		int getTipoExamen(){
			return tipo_exmanen;
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
		
		void imprimirNota(){
			printf("ID_NOTA: %i \n",id_nota);
			printf("LEGAJO: %i \n",legajo);
			printf("ID_MATERIA: %i \n",id_materia);
			printf("VALOR_NOTA: %i \n",valor);
			printf("FECHA: %s \n",fecha);
			printf("TIPO_EXAMEN: %i \n",tipo_exmanen);
			printf("ACTIVO: %i \n",activo);
		}
};
