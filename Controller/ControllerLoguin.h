#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

struct ctrlLoguin{
	
	int cantidad;
	
	void insertLoguin(struct loguin loguin){
		FILE *f;
		f=fopen("Archivos/loguin.txt","a");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		fprintf(f,"%s %s \n",loguin.getUsuario(),loguin.getContrasenia());
		rewind(f);
		fclose(f);
	}
	
	void updateLoguin(struct loguin* misLoguin){
		FILE *f;
		f=fopen("Archivos/loguin.txt","w");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		for(int i=0;i<cantidad;i++){
			fprintf(f,"%s %s \n",misLoguin[i].getUsuario(),misLoguin[i].getContrasenia());
		}
		rewind(f);
		fclose(f);
	}
	
	struct loguin* getAllLoguin(){
		struct loguin loguin;
		static struct loguin misLoguin[100];
		FILE *f;
		f=fopen("Archivos/loguin.txt","r");
		if(f==NULL){
			printf("NO SE HA PODIDO ABRIR EL ARCHIVO \n");
			exit(1);
		}
		
		char usuario[50];
	    char contrasenia[50];
	    int cont=0;
	    while(!feof(f)){
	    	fscanf(f,"%s%s\n",&usuario,&contrasenia);
	    	loguin.ConstructorLoguin(usuario,contrasenia);
	    	misLoguin[cont]=loguin;
	    	cont++;
		}
	    rewind(f);
	    fclose(f);
	    cantidad=cont;
	    return misLoguin;
	}
	
	void imprimirLoguins(struct loguin* misLoguin){
		for(int i=0;i<cantidad;i++){
			printf("LOGUIN: %i\n",i+1);
			misLoguin[i].imprimirDatosLoguin();
			printf("\n");
		}
	}
};
