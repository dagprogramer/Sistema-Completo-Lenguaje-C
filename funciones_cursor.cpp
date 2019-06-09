#include<stdio.h>
#include<conio.h>
#include<windows.h>

void posicionarCursor(int,int);
void crearMarco(int,int,int,int);
void posicionarCaracter(int,int);

int main(){
	
	//crearMarco(1,1,50,25);
	posicionarCaracter(1,2);
	system("pause");
	return 0;
}

void posicionarCursor(int ancho,int alto){
	COORD coord;
	coord.X=ancho;
	coord.Y=alto;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void crearMarco(int ancho1,int alto1,int ancho2,int alto2){
	//esquinas
	posicionarCursor(ancho1,alto1);printf("%c",201);//esquina
	posicionarCursor(ancho1,alto2);printf("%c",200);
	posicionarCursor(ancho2,alto1);printf("%c",187);
	posicionarCursor(ancho2,alto2);printf("%c \n",188);
	
	//controlar posiciones en x
	for(int i=ancho1+1;i<ancho2;i++){
		posicionarCursor(i,alto1);printf("%c",205);
		posicionarCursor(i,alto2);printf("%c",205);
	}
	
	//controlar posiciones en y
	for(int i=alto1+1;i<alto2;i++){
		posicionarCursor(ancho1,i);printf("%c",186);
		posicionarCursor(ancho2,i);printf("%c",186);
	}
}

void posicionarCaracter(int x,int y){
	int j=x+74;
	int k=y+24;
	posicionarCursor(x,y);printf("%c",201);
	posicionarCursor(x,k);printf("%c",200);
	posicionarCursor(j,y);printf("%c",187);
	posicionarCursor(j,k);printf("%c \n",188);
}
