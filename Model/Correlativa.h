#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

struct correlativa{
	private:
	int id_correlativa;
	int id_materiaMatriz;
	int id_materiaCorrelativa;
	int activo;
	
	public:
		
		void ConstructorCorrelativa(int miId_correlativa,int miId_materiaMatriz,int miId_materiaCorrelativa,int miActivo){
			this->id_correlativa=miId_correlativa;
			this->id_materiaMatriz=miId_materiaMatriz;
			this->id_materiaCorrelativa=miId_materiaCorrelativa;
			this->activo=miActivo;
		}
		
		void Correlativa(){
			printf("INGRESE ID ");
			scanf("%i",&id_correlativa);
			printf("INGRESE ID_MATERIA_MATRIZ ");
			scanf("%i",&id_materiaMatriz);
			printf("INGRESE ID_MATERIA_CORRELATIVA ");
			scanf("%i",&id_materiaCorrelativa);
			printf("INGRESE ACTIVO(1-ACTIVO,2-DESACTIVO) ");
			scanf("%i",&activo);
		}
		
		void setId(){
			printf("INGRESE ID ");
			scanf("%i",&id_correlativa);
		}
		
		int getId(){
			return id_correlativa;
		}
		
		void setIdMateriaMatriz(){
			printf("INGRESE ID_MATERIA_MATRIZ ");
			scanf("%i",&id_materiaMatriz);
		}
		
		int getIdMateriaMatriz(){
			return id_materiaMatriz;
		}
		
		void setIdMateriaCorrelativa(){
			printf("INGRESE ID_MATERIA_CORRELATIVA ");
			scanf("%i",&id_materiaCorrelativa);
		}
		
		int getIdMateriaCorrelativa(){
			return id_materiaCorrelativa;
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
		
		void imprimirDatosCorrelativa(){
			printf("ID_CORRELATIVA: %i \n",id_correlativa);
			printf("ID_MATERIA_MATRIZ: %i \n",id_materiaMatriz);
			printf("ID_MATERIA_CORRELATIVA: %i \n",id_materiaCorrelativa);
			printf("ACTIVO: %i \n",activo);
		}
		
		void imprimirDatosCorrelativaReducido(){
			printf("ID: %i ID_MA:%i ID_CO:%i \n",id_correlativa,id_materiaMatriz,id_materiaCorrelativa);
		}
};
