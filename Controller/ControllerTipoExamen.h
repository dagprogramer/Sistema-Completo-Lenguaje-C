#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

struct ctrlTipoExamen{
	
	void insertTipoExamen(struct tipoExamen tipoExamen){
		FILE *f;
		f=fopen("Archivos/tipoExamen.txt","a");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		fprintf(f,"%i %s %i \n",tipoExamen.getId(),tipoExamen.getDescripcion(),tipoExamen.getActivo());
		rewind(f);
		fclose(f);
	}
	
	void updateTipoExamen(struct tipoExamen miTipoExamen){
		struct tipoExamen tipoExamen;
		struct tipoExamen auxiliar;
		bool encontrado=false;
		FILE *f1;
		f1=fopen("Archivos/tipoExamen.txt","r");
		
		FILE *f2;
		f2=fopen("Archivos/auxiliar.txt","w");
		if((f1==NULL) && (f2==NULL)){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		int id_tipoExamen;
	    char descripcion[50];
	    int activo;
		while(!feof(f1)){
			fscanf(f1,"%i%s%i\n",&id_tipoExamen,&descripcion,&activo);
			tipoExamen.ConstructorTipoExamen(id_tipoExamen,descripcion,activo);
			if(tipoExamen.getId()==miTipoExamen.getId()){
				auxiliar=miTipoExamen;
				tipoExamen=auxiliar;
				encontrado=true;
			}
			fprintf(f2,"%i %s %i \n",tipoExamen.getId(),tipoExamen.getDescripcion(),tipoExamen.getActivo());
	    }
		rewind(f1);
		rewind(f2);
		fclose(f1); 
		fclose(f2);
		remove("Archivos/tipoExamen.txt");
		rename("Archivos/auxiliar.txt","Archivos/tipoExamen.txt");
	}
	
	struct tipoExamen getTipoExamenById(int miId){
		struct tipoExamen tipoExamen;
		struct tipoExamen miTipoExamen;
		FILE *f;
		f=fopen("Archivos/tipoExamen.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_tipoExamen;
	    char descripcion[50];
	    int activo;
		while(!feof(f)){
			fscanf(f,"%i%s%i\n",&id_tipoExamen,&descripcion,&activo);
			tipoExamen.ConstructorTipoExamen(id_tipoExamen,descripcion,activo);
			if(tipoExamen.getId()==miId){
				miTipoExamen=tipoExamen;
			}
		}
		rewind(f);
	    fclose(f);
	    return miTipoExamen;
	}
	
	bool existeTipoExamen(struct tipoExamen tipoExamen,int idSeleccionado){
		bool existe=false;
		if(tipoExamen.getId()==idSeleccionado){
			existe=true;
		}
		return existe;
	}
	
	void getAllTipoExamen(){
		struct tipoExamen tipoExamen;
		FILE *f;
		f=fopen("Archivos/tipoExamen.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_tipoExamen;
	    char descripcion[50];
	    int activo;
	    int cont=0;
		while(!feof(f)){
			fscanf(f,"%i%s%i\n",&id_tipoExamen,&descripcion,&activo);
			tipoExamen.ConstructorTipoExamen(id_tipoExamen,descripcion,activo);
			tipoExamen.imprimirDatosTipoExamen();
			printf("\n");
		}
		rewind(f);
	    fclose(f);
	}
	
	void getAllTipoExamenReducido(){
		struct tipoExamen tipoExamen;
		FILE *f;
		f=fopen("Archivos/tipoExamen.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		int id_tipoExamen;
	    char descripcion[50];
	    int activo;
	    int cont=0;
		while(!feof(f)){
			fscanf(f,"%i%s%i\n",&id_tipoExamen,&descripcion,&activo);
			tipoExamen.ConstructorTipoExamen(id_tipoExamen,descripcion,activo);
			tipoExamen.imprimirDatosTipoExamenReducido();
			printf("\n");
		}
		rewind(f);
	    fclose(f);
	}
};
