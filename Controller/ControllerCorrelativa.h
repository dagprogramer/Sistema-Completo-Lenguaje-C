#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

struct ctrlCorrelativa{
	
	void insertCorrelativa(struct correlativa correlativa){
		FILE *f;
		f=fopen("Archivos/correlativa.txt","a");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		fprintf(f,"%i %i %i %i \n",correlativa.getId(),correlativa.getIdMateriaMatriz(),
		correlativa.getIdMateriaCorrelativa(),correlativa.getActivo());
		rewind(f);
		fclose(f);
	}
	
	void updateCorrelativa(struct correlativa miCorrelativa){
		struct correlativa correlativa;
		struct correlativa auxiliar;
		bool encontrado=false;
		FILE *f1;
		f1=fopen("Archivos/correlativa.txt","r");
		
		FILE *f2;
		f2=fopen("Archivos/auxiliar.txt","w");
		if((f1==NULL) && (f2==NULL)){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		int id_correlativa;
	    int id_materiaMatriz;
	    int id_materiaCorrelativa;
	    int activo;
	    while(!feof(f1)){
	    	fscanf(f1,"%i%i%i%i\n",&id_correlativa,&id_materiaMatriz,&id_materiaCorrelativa,&activo);
	    	correlativa.ConstructorCorrelativa(id_correlativa,id_materiaMatriz,id_materiaCorrelativa,activo);
	    	if(correlativa.getId()==miCorrelativa.getId()){
	    		auxiliar=miCorrelativa;
	    		correlativa=auxiliar;
	    		encontrado=true;
			}
			fprintf(f2,"%i %i %i %i \n",correlativa.getId(),correlativa.getIdMateriaMatriz(),
		    correlativa.getIdMateriaCorrelativa(),correlativa.getActivo());
		}
		rewind(f1);
		rewind(f2);
		fclose(f1); 
		fclose(f2);
		remove("Archivos/correlativa.txt");
		rename("Archivos/auxiliar.txt","Archivos/correlativa.txt");
	}
	
	struct correlativa getCorrelativaById(int miId){
		struct correlativa correlativa;
		struct correlativa miCorrelativa;
		FILE *f;
		f=fopen("Archivos/correlativa.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_correlativa;
	    int id_materiaMatriz;
	    int id_materiaCorrelativa;
	    int activo;
	    while(!feof(f)){
	    	fscanf(f,"%i%i%i%i\n",&id_correlativa,&id_materiaMatriz,&id_materiaCorrelativa,&activo);
	    	correlativa.ConstructorCorrelativa(id_correlativa,id_materiaMatriz,id_materiaCorrelativa,activo);
	    	if(correlativa.getId()==miId){
	    		miCorrelativa=correlativa;
			}
		}
		rewind(f);
	    fclose(f);
	    return miCorrelativa;
	}
	
	bool existeCorrelativa(struct correlativa correlativa,int idSeleccionado){
		bool existe=false;
		if(correlativa.getId()==idSeleccionado){
			existe=true;
		}
		return existe;
	}
	
	void getAllCorrelativa(){
		struct correlativa correlativa;
		FILE *f;
		f=fopen("Archivos/correlativa.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_correlativa;
	    int id_materiaMatriz;
	    int id_materiaCorrelativa;
	    int activo;
	    while(!feof(f)){
	    	fscanf(f,"%i%i%i%i\n",&id_correlativa,&id_materiaMatriz,&id_materiaCorrelativa,&activo);
	    	correlativa.ConstructorCorrelativa(id_correlativa,id_materiaMatriz,id_materiaCorrelativa,activo);
	    	correlativa.imprimirDatosCorrelativa();
	    	printf("\n");
		}
		rewind(f);
	    fclose(f);
	}
};
