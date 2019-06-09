
// archivo manejo del sistema
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "View/loguin.h"
#include "Model/lib_model.h"
#include "Controller/GenericController.h"

void iniciarPrograma();
struct estructuras estructuras;
struct estructuras accionLoguin();
void accionEntidad();
void accionesCarrera();
void accionesAlumno();
void accionesProfesor();
void accionesMateria();
void accionesCorrelativa();
void accionesTipoExamen();
void accionesNota();
struct ctrlError ctrlError;

int main(){
//funcion que manipula todo el programa
iniciarPrograma();

	system("pause>null");
	return 0;
}

//funcion inicio prgrama para logueo y manipulacion de entidades
void iniciarPrograma(){
	bool repite=true;
	int opcion;
	int opcionEntidad;
	const char *titulo="BIENVENIDOS A ITUOM 401";
	const char *opciones[]={"INGRESAR DATOS LOGUIN","SALIR"};
	int elementos=2;
	do{
		fflush(stdin);
		opcion=obtenerMenu(titulo,opciones,elementos);
		switch(opcion){
			case 1:
				system("cls");
				fflush(stdin);
                 estructuras.setFormularioLoguin();
                 if(strcmp(estructuras.getDatosLoguin().getUsuario(),"diego")==0){
                 	system("cls");
                 	fflush(stdin);
                 	accionEntidad();
				 }else{
				 	printf("USUARIO NO VALIDO \n");
				 	system("pause>null");
				 }
				break;
				case 2:
					system("cls");
					printf("GRACIAS POR SU VISITA");
					repite=false;
					break;
		}
	}while(repite);
	
}

//funcion que inserta y obtiene datos de loguin
struct estructuras accionLoguin(){
	bool repite=true;
	int opcion;
	do{
		opcion=menuLoguin();
		system("cls");
		switch(opcion){
			case 1:
				fflush(stdin);
				estructuras.setFormularioLoguin();
				break;
				case 2:
					repite=false;
					break;
		}
	}while(repite);
	return estructuras;
}

//funcion que manipula las acciones de todas las entidades
void accionEntidad(){
	bool repite=true;
	int opcion;
	do{
		opcion=menuEntidades();
		system("cls");
		switch(opcion){
			case 1:
				accionesCarrera();//entidad pura-funcionando(con manejo de error)
				break;
				case 2:
					accionesAlumno();//entidad pura-funcionando(con manejo de error)
					break;
					case 3:
						accionesProfesor();//entidad-pura funcionando(con manejo de error)
						break;
						case 4:
							accionesMateria();//entidad no pura-funcionando(con manejo de error)
							break;
							case 5:
								accionesCorrelativa();//entidad no pura-funcionando(con manejo de error)
								break;
								case 6:
									accionesTipoExamen();// entidad pura-funcionando(con manejo de error)
									break;
									case 7:
										accionesNota();//entidad no pura-produccion(con manejo de error)
										break;
										case 8:
											repite=false;
											break;
		}
	}while(repite);
}

//funcion para acciones de Entidad Carrera(funcionando)
void accionesCarrera(){
	struct ctrlCarrera ctrlCarrera;
	struct carrera carrera;
	bool repite=true;
	bool repiteAccion=true;
	bool repiteAtributo=true;
	bool existe;
	int opcion;
	int opcionAccion;
	int idCarrera;
	int numeroCampo;
	do{
		opcion=menuAccion();
		system("cls");
		switch(opcion){
			case 1:
				fflush(stdin);
				estructuras.setFormularioCarrera();
				printf("\n");
				estructuras.getDatosCarrera().imprimirDatosCarrera();
				ctrlCarrera.insertCarrera(estructuras.getDatosCarrera());
				system("pause>null");
				break;
				case 2:
					ctrlCarrera.getAllCarrera();
					system("pause>null");
					do{
						opcionAccion=menuAccionUpdate();
						switch(opcionAccion){
							case 1:
								system("cls");
								printf("INGRESE EL ID DE CARRERA A MODIFICAR  ");
								fflush(stdin);
								scanf("%i",&idCarrera);
								printf("\n");
								carrera=ctrlCarrera.getCarreraById(idCarrera);
								existe=ctrlCarrera.existeCarrera(carrera,idCarrera);
								if(existe==false){
									ctrlError.imprimirErrorCarrera();
									repiteAccion=false;
								}else{
									carrera.imprimirDatosCarrera();
								system("pause>null");
								printf("\n");
								do{
	                                const char *titulo="MENU MODIFICAR CAMPOS CARRERA";
	                                const char *opciones[]={"ID_CARRERA","NOMBRE_CARRERA","DURACION","DESACTIVAR ENTIDAD","REGRESAR"};
	                                int elementos=5;
	                                numeroCampo=obtenerMenu(titulo,opciones,elementos);
	                                system("cls");
	                                switch(numeroCampo){
	                                	case 1:
	                                		carrera.setId();
	                                		break;
	                                		case 2:
	                                			carrera.setNombre();
	                                			break;
	                                			case 3:
	                                				carrera.setDuracion();
	                                				break;
	                                				case 4:
	                                					system("cls");
									                    printf("SE HA DESACTIVADO LA CARRERA EN LA BASE DE DATOS \n");
									                    system("pause>null");
	                                					carrera.setDesactivo(2);
	                                					break;
	                                					case 5:
	                                						repiteAtributo=false;
	                                						break;
									}
								}while(repiteAtributo);
								}
								break;
								case 2:
									system("cls");
									printf("SE HAN MODIFICADO TODOS LOS DATOS EN LA BASE DE DATOS \n");
									system("pause>null");
									repiteAccion=false;
									break;
						}
					}while(repiteAccion);
					ctrlCarrera.updateCarrera(carrera);
					break;
					case 3:
						repite=false;
						break;
		}
	}while(repite);
}

//funcion para acciones de Entidad Alumno(funcionando)
void accionesAlumno(){
	struct ctrlAlumno ctrlAlumno;
	struct alumno alumno;
	bool repite=true;
	bool repiteAccion=true;
	bool repiteAtributo=true;
	bool existe;
	int opcion;
	int opcionAccion;
	int legajo;
	int numeroCampo;
	do{
		opcion=menuAccion();
		system("cls");
		switch(opcion){
			case 1:
				fflush(stdin);
				estructuras.setFormularioAlumno();
				printf("\n");
				estructuras.getDatosAlumno().imprimirDatosAlumno();
				ctrlAlumno.insertAlumno(estructuras.getDatosAlumno());
				system("pause>null");
				break;
				case 2:
					ctrlAlumno.getAllAlumno();
					system("pause>null");
					do{
						opcionAccion=menuAccionUpdate();
						switch(opcionAccion){
							case 1:
								system("cls");
								printf("INGRESE LEGAJO ALUMNO A MODIFICAR  ");
								fflush(stdin);
								scanf("%i",&legajo);
								printf("\n");
								alumno=ctrlAlumno.getAlumnoById(legajo);
								existe=ctrlAlumno.existeAlumno(alumno,legajo);
								if(existe==false){
									ctrlError.imprimirErrorAlumno();
									repiteAccion=false;
								}else{
								   alumno.imprimirDatosAlumno();
								system("pause>null");
								printf("\n");
								do{
									const char *titulo="MENU MODIFICAR CAMPOS ALUMNO";
	                                const char *opciones[]={"LEGAJO","NOMBRE","APELLIDO","DOCUMENTO","FECHA_INSCRIPCION","FECHA_NACIMIENTO","TELEFONO","EMAIL","DESACTIVAR ENTIDAD","REGRESAR"};
	                                int elementos=10;
	                                numeroCampo=obtenerMenu(titulo,opciones,elementos);
	                                system("cls");
	                                switch(numeroCampo){
	                                	case 1:
	                                		alumno.setLegajo();
	                                		break;
	                                		case 2:
	                                			alumno.setNombre();
	                                			break;
	                                			case 3:
	                                				alumno.setApellido();
	                                				break;
	                                				case 4:
	                                					alumno.setDocumento();
	                                					break;
	                                					case 5:
	                                						alumno.setFechaInscripcion();
	                                						break;
	                                						case 6:
	                                							alumno.setFechaNacimiento();
	                                							break;
	                                							case 7:
	                                								alumno.setTelefono();
	                                								break;
	                                								 case 8:
	                                								 	alumno.setEmail();
																	   break;
																	    case 9:
																	    	alumno.setDesactivo(2);
																	    	system("cls");
									                                        printf("SE HA DESACTIVADO LA CARRERA EN LA BASE DE DATOS \n");
									                                        system("pause>null");
																	     break;
																		 case 10:
																		 	repiteAtributo=false;
																		 break;  
									}
								}while(repiteAtributo);	
								}
								break;
								case 2:
									system("cls");
									printf("SE HAN MODIFICADO TODOS LOS DATOS EN LA BASE DE DATOS \n");
									system("pause>null");
									repiteAccion=false;
									break;
						}
					}while(repiteAccion);
					ctrlAlumno.updateAlumno(alumno);
					break;
					case 3:
						repite=false;
						break;
		}
	}while(repite);
}

//funcion para acciones de Entidad Profesor(funcionando)
void accionesProfesor(){
	struct ctrlProfesor ctrlProfesor;
	struct profesor profesor;
	bool repite=true;
	bool repiteAccion=true;
	bool repiteAtributo=true;
	bool existe;
	int opcion;
	int opcionAccion;
	int idProfesor;
	int numeroCampo;
	do{
		opcion=menuAccion();
		system("cls");
		switch(opcion){
			case 1:
				fflush(stdin);
				estructuras.setFormularioProfesor();
				printf("\n");
				estructuras.getDatosProfesor().imprimirDatosProfesor();
				ctrlProfesor.insertProfesor(estructuras.getDatosProfesor());
				system("pause>null");
				break;
				case 2:
					ctrlProfesor.getAllProfesor();
					system("pause>null");
					do{
						opcionAccion=menuAccionUpdate();
						switch(opcionAccion){
							case 1:
								system("cls");
								printf("INGRESE EL ID DE PROFESOR A MODIFICAR  ");
								fflush(stdin);
								scanf("%i",&idProfesor);
								printf("\n");
								profesor=ctrlProfesor.getProfesorById(idProfesor);
								existe=ctrlProfesor.existeProfesor(profesor,idProfesor);
								if(existe==false){
									ctrlError.imprimirErrorProfesor();
									repiteAccion=false;
								}else{
								   profesor.imprimirDatosProfesor();
								system("pause>null");
								printf("\n");
								do{
									const char *titulo="MENU MODIFICAR CAMPOS PROFESOR";
	                                const char *opciones[]={"ID_PROFESOR","APELLIDO","NOMBRE","TELEFONO","EMAIL","DESACTIVAR ENTIDAD","REGRESAR"};
	                                int elementos=7;
	                                numeroCampo=obtenerMenu(titulo,opciones,elementos);
	                                system("cls");
	                                switch(numeroCampo){
	                                	case 1:
	                                		profesor.setId();
	                                		break;
	                                		case 2:
	                                			profesor.setApellido();
	                                			break;
	                                			case 3:
	                                				profesor.setNombre();
	                                				break;
	                                				case 4:
	                                					profesor.setTelefono();
	                                					break;
	                                					case 5:
	                                						profesor.setEmail();
	                                						break;
	                                						case 6:
	                                							profesor.setDesactivo(2);
	                                							system("cls");
									                            printf("SE HA DESACTIVADO LA CARRERA EN LA BASE DE DATOS \n");
									                            system("pause>null");
	                                							break;
	                                							case 7:
	                                								repiteAtributo=false;
	                                								break;
									}
								}while(repiteAtributo);	
								}
								break;
								case 2:
									system("cls");
									printf("SE HAN MODIFICADO TODOS LOS DATOS EN LA BASE DE DATOS \n");
									system("pause>null");
									repiteAccion=false;
									break;
						}
					}while(repiteAccion);
					ctrlProfesor.updateProfesor(profesor);
					break;
					case 3:
						repite=false;
						break;
		}
	}while(repite);
}

//funcion para acciones de Entidad Materia(funcionando)
void accionesMateria(){
	struct ctrlMateria ctrlMateria;
	struct ctrlProfesor ctrlProfesor;
	struct ctrlCarrera ctrlCarrera;
	struct materia materia;
	struct materia miMateria;
	struct carrera carrera;
	struct profesor profesor;
	bool repite=true;
	bool repiteAccion=true;
	bool repiteAtributo=true;
	bool existeCarrera;
	bool existeProfesor;
	bool existeMateria;
	int opcion;
	int opcionAccion;
	int idMateria;
	int numeroCampo;
	do{
		opcion=menuAccion();
		system("cls");
		switch(opcion){
			case 1:
				fflush(stdin);
				materia.setIdMateria();
				materia.setNombre();
				printf("\nOPCIONES CARRERA: \n");
				ctrlCarrera.getAllCarreraReducido();
				materia.setIdCarrera();
				carrera=ctrlCarrera.getCarreraById(materia.getIdCarrera());
				existeCarrera=ctrlCarrera.existeCarrera(carrera,materia.getIdCarrera());
				if(existeCarrera==false){
					ctrlError.imprimirErrorCarrera();
					repite=false;
				}else{
				   printf("\nOPCIONES PROFESOR: \n");	
				   ctrlProfesor.getAllProfesorReducido();
				   materia.setIdProfesor();
				   profesor=ctrlProfesor.getProfesorById(materia.getIdProfesor());
				   existeProfesor=ctrlProfesor.existeProfesor(profesor,materia.getIdProfesor());
				   if(existeProfesor==false){
				   	  ctrlError.imprimirErrorProfesor();
				   	  repite=false;
				   }else{
				   	  materia.setAnioCursada();
				      materia.setPromocion();
				      materia.setActivo();
				      estructuras.setMateria(materia);
				      printf("\n");
				      estructuras.getDatosMateria().imprimirDatosMateria();
				      ctrlMateria.insertMateria(estructuras.getDatosMateria());
				   }	
				}
				system("pause>null");
				break;
				case 2:
					ctrlMateria.getAllMateria();
					system("pause>null");
					do{
						opcionAccion=menuAccionUpdate();
						switch(opcionAccion){
							case 1:
								system("cls");
								printf("INGRESE EL ID DE MATERIA A MODIFICAR  ");
								scanf("%i",&idMateria);
								printf("\n");
								miMateria=ctrlMateria.getMateriaById(idMateria);
								existeMateria=ctrlMateria.existeMateria(miMateria,idMateria);
								if(existeMateria==false){
									ctrlError.imprimirErrorMateria();
									repiteAccion=false;
								}else{
									miMateria.imprimirDatosMateria();
								   system("pause>null");
								printf("\n");
								do{
									const char *titulo="MENU MODIFICAR CAMPOS MATERIA";
	                                const char *opciones[]={"ID_MATERIA","NOMBRE_MATERIA","NOMBRE_TECNICATURA","ID_PROFESOR","ANIO_CURSADA","NOTA_PROMOCION","DESACTIVAR ENTIDAD","REGRESAR"};
	                                int elementos=8;
	                                numeroCampo=obtenerMenu(titulo,opciones,elementos);
	                                system("cls");
	                                switch(numeroCampo){
	                                	case 1:
	                                		miMateria.setIdMateria();
	                                		break;
	                                		case 2:
	                                			miMateria.setNombre();
	                                			break;
	                                			case 3:
	                                				miMateria.setIdCarrera();
	                                				break;
	                                				case 4:
	                                					miMateria.setIdProfesor();
	                                					break;
	                                					case 5:
	                                						miMateria.setAnioCursada();
	                                						break;
	                                						case 6:
	                                							miMateria.setPromocion();
	                                							break;
	                                							case 7:
	                                								miMateria.setDesactivo(2);
	                                								system("cls");
									                                printf("SE HA DESACTIVADO LA CARRERA EN LA BASE DE DATOS \n");
									                                system("pause>null");
	                                								break;
	                                								case 8:
	                                									repiteAtributo=false;
	                                									break;
									}
								}while(repiteAtributo);	
								}
								break;
								case 2: 
								system("cls");
								printf("SE HAN MODIFICADO TODOS LOS DATOS EN LA BASE DE DATOS \n");
								system("pause>null");
								repiteAccion=false;
								   break;
						}
					}while(repiteAccion);
					ctrlMateria.updateMateria(miMateria);
					break;
					case 3:
						repite=false;
						break;
		}
	}while(repite);
}

//funcion para acciones de Entidad Correlativa(funcionando)
void accionesCorrelativa(){
	struct ctrlCorrelativa ctrlCorrelativa;
	struct ctrlMateria ctrlMateria;
	struct correlativa correlativa;
	struct correlativa miCorrelativa;
	struct materia materiaMatriz;
	struct materia materiaCorrelativa;
	bool repite=true;
	bool repiteAccion=true;
	bool repiteAtributo=true;
	bool existeMateriaMatriz;
	bool existeMateriaCorrelativa;
	bool existeCorrelativa;
	int opcion;
	int opcionAccion;
	int idCorrelativa;
	int numeroCampo;
	do{
		opcion=menuAccion();
		system("cls");
		switch(opcion){
			case 1:
				fflush(stdin);
				correlativa.setId();
				ctrlMateria.getAllMateriaReducido();
				fflush(stdin);
				correlativa.setIdMateriaMatriz();
				materiaMatriz=ctrlMateria.getMateriaById(correlativa.getIdMateriaMatriz());
				existeMateriaMatriz=ctrlMateria.existeMateria(materiaMatriz,correlativa.getIdMateriaMatriz());
				if(existeMateriaMatriz==false){
					ctrlError.imprimirErrorMateria();
					repite=false;
				}else{
					fflush(stdin);
				    correlativa.setIdMateriaCorrelativa();
				    materiaCorrelativa=ctrlMateria.getMateriaById(correlativa.getIdMateriaCorrelativa());
				    existeMateriaCorrelativa=ctrlMateria.existeMateria(materiaCorrelativa,correlativa.getIdMateriaCorrelativa());
				    if(existeMateriaCorrelativa==false){
				    	ctrlError.imprimirErrorMateria();
				    	repite=false;
					}else{
					   correlativa.setActivo();
				       estructuras.setCorrelativa(correlativa);
				       printf("\n");
				       estructuras.getDatosCorrelativa().imprimirDatosCorrelativa();
				       ctrlCorrelativa.insertCorrelativa(estructuras.getDatosCorrelativa());
				       system("pause>null");	
					}	
				}
				break;
				case 2:
					ctrlCorrelativa.getAllCorrelativa();
					system("pause>null");
					do{
						opcionAccion=menuAccionUpdate();
						switch(opcionAccion){
							case 1:
								 system("cls");
								 printf("INGRESE EL ID DE CORRELATIVA A MODIFICAR  ");
								 fflush(stdin);
								 scanf("%i",&idCorrelativa);
								printf("\n");
								miCorrelativa=ctrlCorrelativa.getCorrelativaById(idCorrelativa);
								existeCorrelativa=ctrlCorrelativa.existeCorrelativa(miCorrelativa,idCorrelativa);
								if(existeCorrelativa==false){
									ctrlError.imprimirErrorCorrelativa();
									repiteAccion=false;
								}else{
									correlativa.imprimirDatosCorrelativa();
								system("pause>null");
								printf("\n");
								do{
									const char *titulo="MENU MODIFICAR CAMPOS CORRELATIVA";
	                                const char *opciones[]={"ID_CORRELATIVA","ID_MATERIA_MATRIZ","ID_MATERIA_CORRELATIVA","DESACTIVAR ENTIDAD","REGRESAR"};
	                                int elementos=5;
	                                numeroCampo=obtenerMenu(titulo,opciones,elementos);
	                                system("cls");
	                                switch(numeroCampo){
	                                	case 1:
	                                		miCorrelativa.setId();
	                                		break;
	                                		case 2:
	                                			miCorrelativa.setIdMateriaMatriz();
	                                			break;
	                                			case 3:
	                                				miCorrelativa.setIdMateriaCorrelativa();
	                                				break;
	                                				case 4:
	                                					miCorrelativa.setDesactivo(2);
	                                					system("cls");
									                    printf("SE HA DESACTIVADO LA CARRERA EN LA BASE DE DATOS \n");
									                    system("pause>null");
	                                					break;
	                                					case 5:
														   repiteAtributo=false; 
														   break;
									}
								}while(repiteAtributo);
								}
								break;
								case 2:
								system("cls");
								printf("SE HAN MODIFICADO TODOS LOS DATOS EN LA BASE DE DATOS \n");
								system("pause>null");
								repiteAccion=false;
									break;
						}
					}while(repiteAccion);
					ctrlCorrelativa.updateCorrelativa(miCorrelativa);
					break;
					case 3:
						repite=false;
						break;
		}
	}while(repite);
}

//funcion para acciones de Entidad TipoExamen(funcionando)
void accionesTipoExamen(){
	struct ctrlTipoExamen ctrlTipoExamen;
	struct tipoExamen tipoExamen;
	bool repite=true;
	bool repiteAccion=true;
	bool repiteAtributo=true;
	bool existe;
	int opcion;
	int opcionAccion;
	int idTipoExamen;
	int numeroCampo;
	do{
		opcion=menuAccion();
		system("cls");
		switch(opcion){
			case 1:
				fflush(stdin);
				estructuras.setFormularioTipoExamen();
				printf("\n");
				estructuras.getDatosTipoExamen().imprimirDatosTipoExamen();
				ctrlTipoExamen.insertTipoExamen(estructuras.getDatosTipoExamen());
				system("pause>null");
				break;
				case 2:
					ctrlTipoExamen.getAllTipoExamen();
					system("pause>null");
					do{
						opcionAccion=menuAccionUpdate();
						switch(opcionAccion){
							case 1:
								system("cls");
								printf("INGRESE EL ID DE TIPO_EXAMEN A MODIFICAR  ");
								fflush(stdin);
								scanf("%i",&idTipoExamen);
								printf("\n");
								tipoExamen=ctrlTipoExamen.getTipoExamenById(idTipoExamen);
								existe=ctrlTipoExamen.existeTipoExamen(tipoExamen,idTipoExamen);
								if(existe==false){
									ctrlError.imprimirErrorTipoExamen();
									repiteAccion=false;
								}else{
									tipoExamen.imprimirDatosTipoExamen();
								system("pause>null");
								printf("\n");
								do{
								    const char *titulo="MENU MODIFICAR CAMPOS TIPO_EXAMEN";
	                                const char *opciones[]={"ID_TIPO_EXAMEN","DESCRIPCION_EXAMEN","DESACTIVAR ENTIDAD","REGRESAR"};
	                                int elementos=4;
	                                numeroCampo=obtenerMenu(titulo,opciones,elementos);
	                                system("cls");
								    switch(numeroCampo){
								    	case 1:
								    		tipoExamen.setId();
								    		break;
								    		case 2:
								    			tipoExamen.setDescripcion();
								    			break;
								    			case 3:
								    				tipoExamen.setDesactivo(2);
								    				system("cls");
									                printf("SE HA DESACTIVADO LA CARRERA EN LA BASE DE DATOS \n");
									                system("pause>null");
								    				break;
								    				case 4:
								    					repiteAtributo=false;
								    					break;
									}		
								}while(repiteAtributo);
								}
								break;
								case 2:
									system("cls");
									printf("SE HAN MODIFICADO TODOS LOS DATOS EN LA BASE DE DATOS \n");
									system("pause>null");
									repiteAccion=false;
									break;
						}
					}while(repiteAccion);
					ctrlTipoExamen.updateTipoExamen(tipoExamen);
					break;
					case 3:
						repite=false;
						break;
		}
	}while(repite);
}

//funcion para acciones de Entidad Nota
void accionesNota(){
	struct ctrlNota ctrlNota;
	struct ctrlAlumno ctrlAlumno;
	struct ctrlMateria ctrlMateria;
	struct ctrlTipoExamen ctrlTipoExamen;
	struct nota nota;
	struct nota miNota;
	struct alumno alumno;
	struct alumno miAlumno;
	struct alumno otroAlumno;
	struct materia miMateria;
	struct materia otraMateria;
	struct tipoExamen tipoExamen;
	struct tipoExamen otroTipoExamen;
	bool repite=true;
	bool repiteAccion=true;
	bool repiteAtributo=true;
	bool existeAlumno;
	bool existeAlumno2;
	bool existeMateria;
	bool existeTipoExamen;
	bool existeNota;
	bool existeOtroAlumno;
	bool existeOtraMateria;
	bool existeOtroTipoExamen;
	int opcion;
	int opcionAccion;
	int idNota;
	int legajo;
	int numeroCampo;
	int cantidadNota;
	
	do{
		opcion=menuAccion();
		system("cls");
		switch(opcion){
			case 1:
				fflush(stdin);
				nota.setId();
				printf("\nOPCIONES ALUMNO:\n");
				ctrlAlumno.getAllAlumnoReducido();
				nota.setLegajo();
				miAlumno=ctrlAlumno.getAlumnoById(nota.getLegajo());
				existeAlumno=ctrlAlumno.existeAlumno(miAlumno,nota.getLegajo());
				if(existeAlumno==false){
					ctrlError.imprimirErrorAlumno();
					repite=false;
				}else{
					printf("\nOPCIONES MATERIA:\n");
					ctrlMateria.getAllMateriaReducido();
					nota.setIdMateria();
					miMateria=ctrlMateria.getMateriaById(nota.getIdMateria());
					existeMateria=ctrlMateria.existeMateria(miMateria,nota.getIdMateria());
					if(existeMateria==false){
						ctrlError.imprimirErrorMateria();
						repite=false;
					}else{
						nota.setValor();
						nota.setFecha();
						printf("\nOPCIONES TIPO EXAMEN:\n");
						ctrlTipoExamen.getAllTipoExamenReducido();
						nota.setTipoExamen();
						tipoExamen=ctrlTipoExamen.getTipoExamenById(nota.getTipoExamen());
						existeTipoExamen=ctrlTipoExamen.existeTipoExamen(tipoExamen,nota.getTipoExamen());
						if(existeTipoExamen==false){
							ctrlError.imprimirErrorTipoExamen();
							repite=false;
						}else{
							nota.setActivo();
							estructuras.setNota(nota);
				            printf("\n");
				            estructuras.getDatosNotas().imprimirNota();
				            ctrlNota.insertNota(estructuras.getDatosNotas());
				            system("cls");
				            printf("SE HAN INGRESADO LOS DATOS EN LA BASE DE DATOS \n");
				            system("pause>null");
						}
					}
				}
				//fin opcion agregar
				break;
				case 2:
					printf("OPCIONES DE ALUMNOS \n");
					ctrlAlumno.getAllLegajo();
					printf("INGRESE EL LEGAJO DE ALUMNO  ");
					scanf("%i",&legajo);
					printf("\n");
					alumno=ctrlAlumno.getAlumnoById(legajo);
					existeAlumno2=ctrlAlumno.existeAlumno(alumno,legajo);
					if(existeAlumno2==false){
						ctrlError.imprimirErrorAlumno();
						repiteAccion=false;
					}else{
						cantidadNota=ctrlNota.getAllNotaByLegajo(alumno);
						if(cantidadNota==0){
							system("cls");
							printf("EL ALUMNO DE LEGAJO: %i POSEE: %i NOTAS",alumno.getLegajo(),cantidadNota);
							system("pause>null");
							repiteAccion=false;
						}else{
							system("pause>null");
						do{
							opcionAccion=menuAccionUpdate();
							system("cls");
							switch(opcionAccion){
								case 1:
								    printf("INGRESE EL ID DE NOTA A MODIFICAR  ");
								    scanf("%i",&idNota);
								    printf("\n");
								    miNota=ctrlNota.getNotaById(alumno,idNota);
								    existeNota=ctrlNota.existeNota(miNota,idNota);
								    if(existeNota==false){
								    	ctrlError.imprimirErrorNota();
								    	repiteAccion=false;
									}else{
										miNota.imprimirNota();
								        system("pause>null");
								        printf("\n");
								        do{
								        	const char *titulo="MENU MODIFICAR CAMPOS NOTA";
	                                        const char *opciones[]={"ID_NOTA","LEGAJO","ID_MATERIA","VALOR_NOTA","FECHA","TIPO_EXAMEN","DESACTIVAR ENTIDAD","REGRESAR"};
	                                        int elementos=8;
								        	numeroCampo=obtenerMenu(titulo,opciones,elementos);
								        	system("cls");
								        	switch(numeroCampo){
	                                	case 1:
	                                		miNota.setId();
	                                		break;
	                                		case 2:
	                                			ctrlAlumno.getAllLegajo();
	                                			miNota.setLegajo();
	                                			otroAlumno=ctrlAlumno.getAlumnoById(miNota.getLegajo());
	                                			existeOtroAlumno=ctrlAlumno.existeAlumno(otroAlumno,miNota.getLegajo());
	                                			if(existeOtroAlumno==false){
	                                				repiteAtributo=false;
	                                				ctrlError.imprimirErrorAlumno();
												}
	                                			break;
	                                			case 3:
	                                				ctrlMateria.getAllMateriaReducido();
	                                				miNota.setIdMateria();
	                                				otraMateria=ctrlMateria.getMateriaById(miNota.getIdMateria());
	                                				existeOtraMateria=ctrlMateria.existeMateria(otraMateria,miNota.getIdMateria());
	                                				if(existeOtraMateria==false){
	                                					repiteAtributo=false;
	                                					ctrlError.imprimirErrorMateria();
													}
	                                				break;
	                                				case 4:
	                                					miNota.setValor();
	                                					break;
	                                					case 5:
	                                						miNota.setFecha();
	                                						break;
	                                						case 6:
	                                							ctrlTipoExamen.getAllTipoExamen();
	                                							miNota.setTipoExamen();
	                                							otroTipoExamen=ctrlTipoExamen.getTipoExamenById(miNota.getTipoExamen());
	                                							existeOtroTipoExamen=ctrlTipoExamen.existeTipoExamen(otroTipoExamen,miNota.getTipoExamen());
	                                							if(existeOtroTipoExamen==false){
	                                								repiteAtributo=false;
	                                								ctrlError.imprimirErrorTipoExamen();
																}
	                                							break;
	                                							case 7:
	                                								miNota.setDesactivo(2);
	                                								system("cls");
									                                printf("SE HA DESACTIVADO LA CARRERA EN LA BASE DE DATOS \n");
									                                system("pause>null");
	                                								break;
	                                								case 8:
	                                									system("cls");
									                                    printf("SE HAN MODIFICADO TODOS LOS DATOS EN LA BASE DE DATOS \n");
									                                    system("pause>null");
	                                									repiteAtributo=false;
	                                									break;
									}
										}while(repiteAtributo);
										ctrlNota.updateNota(miNota);
									}
									break;
									case 2:
										repiteAccion=false;
										break;
							}
						}while(repiteAccion);
						}
						//hasta aca
					}
					//fin opcion editar
					break;
					case 3:
						//fin opcion regresar
						repite=false;
						break;
		}
	}while(repite);
	
	/*
	do{
		opcion=menuAccion();
		system("cls");
		switch(opcion){
			case 1:
				fflush(stdin);
				nota.setId();	
				printf("\n");
				ctrlAlumno.getAllAlumnoReducido();
				fflush(stdin);
				nota.setLegajo();
				printf("\n");
				miAlumno=ctrlAlumno.getAlumnoById(nota.getLegajo());
				existeAlumno=ctrlAlumno.existeAlumno(miAlumno,nota.getLegajo());
				if(existeAlumno==false){
					ctrlError.imprimirErrorAlumno();
					repite=false;
				}else{
					ctrlMateria.getAllMateriaReducido();
				    nota.setIdMateria();
				    miMateria=ctrlMateria.getMateriaById(nota.getIdMateria());
				    existeMateria=ctrlMateria.existeMateria(miMateria,nota.getIdMateria());
				    if(existeMateria==false){
				    	ctrlError.imprimirErrorMateria();
						repite=false;
					}else{
						nota.setValor();
				        nota.setFecha();
				        ctrlTipoExamen.getAllTipoExamenReducido();
				        nota.setTipoExamen();
				        tipoExamen=ctrlTipoExamen.getTipoExamenById(nota.getTipoExamen());
				        existeTipoExamen=ctrlTipoExamen.existeTipoExamen(tipoExamen,nota.getTipoExamen());
				        if(existeTipoExamen==false){
				        	ctrlError.imprimirErrorTipoExamen();
				        	repite=false;
						}else{
						   nota.setActivo();
				           estructuras.setNota(nota);
				           printf("\n");
				           estructuras.getDatosNotas().imprimirNota();
				           ctrlNota.insertNota(estructuras.getDatosNotas());
				           system("pause>null");	
						}
					}
				}
				break;
				
				case 2:
					ctrlAlumno.getAllLegajo();
					printf("INGRESE EL LEGAJO DE ALUMNO  ");
					scanf("%i",&legajo);
					printf("\n");
					alumno=ctrlAlumno.getAlumnoById(legajo);
					existeAlumno2=ctrlAlumno.existeAlumno(alumno,legajo);
					if(existeAlumno2==false){
						ctrlError.imprimirErrorAlumno();
						repiteAccion=false;
					}else{
						ctrlNota.getAllNotaByLegajo(alumno);
					system("pause>null");
					do{
						opcionAccion=menuAccionUpdate();
						switch(opcionAccion){
							case 1:
								system("cls");
								printf("INGRESE EL ID DE NOTA A MODIFICAR  ");
								scanf("%i",&idNota);
								printf("\n");
								miNota=ctrlNota.getNotaById(alumno,idNota);
								existeNota=ctrlNota.existeNota(miNota,idNota);
								if(existeNota==false){
									ctrlError.imprimirErrorNota();
									repiteAccion=false;
								}else{
									miNota.imprimirNota();
								system("pause>null");
								printf("\n");
								do{
									const char *titulo="MENU MODIFICAR CAMPOS NOTA";
	                                const char *opciones[]={"ID_NOTA","LEGAJO","ID_MATERIA","VALOR_NOTA","FECHA","TIPO_EXAMEN","DESACTIVAR ENTIDAD","REGRESAR"};
	                                int elementos=8;
	                                numeroCampo=obtenerMenu(titulo,opciones,elementos);
	                                system("cls");
	                                switch(numeroCampo){
	                                	case 1:
	                                		miNota.setId();
	                                		break;
	                                		case 2:
	                                			ctrlAlumno.getAllLegajo();
	                                			miNota.setLegajo();
	                                			break;
	                                			case 3:
	                                				ctrlMateria.getAllMateriaReducido();
	                                				miNota.setIdMateria();
	                                				break;
	                                				case 4:
	                                					miNota.setValor();
	                                					break;
	                                					case 5:
	                                						miNota.setFecha();
	                                						break;
	                                						case 6:
	                                							ctrlTipoExamen.getAllTipoExamen();
	                                							miNota.setTipoExamen();
	                                							break;
	                                							case 7:
	                                								miNota.setDesactivo(2);
	                                								system("cls");
									                                printf("SE HA DESACTIVADO LA CARRERA EN LA BASE DE DATOS \n");
									                                system("pause>null");
	                                								break;
	                                								case 8:
	                                									system("cls");
									                                    printf("SE HAN MODIFICADO TODOS LOS DATOS EN LA BASE DE DATOS \n");
									                                    system("pause>null");
	                                									repiteAtributo=false;
	                                									break;
									}
								}while(repiteAtributo);
								ctrlNota.updateNota(miNota);
								}
					}
								break;
								case 2:
									//system("cls");
									//printf("SE HAN MODIFICADO TODOS LOS DATOS EN LA BASE DE DATOS \n");
									//system("pause>null");
									repiteAccion=false;
									break;
					}while(repiteAccion);
					//ctrlNota.updateNota(miNota);
					break;
					case 3:
						repite=false;
						break;
		}
	}while(repite);
	*/
}
