#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoUsuario{
	char archUsr[20];
    char usuario[20];
    char passwd[20];
    int edad;
	int numeroCompras;
	int discosComprados;
   struct nodoUsuario *sig;
} NodoUsuario;

typedef struct nodoDisco{
	char archDisk[40];
	char artista[40];
	char nombreDisco[40];
	double precio;
	int anioLanzamiento;
	int numeroCompras;
	struct nodoDisco *sig;
}NodoDisco;

NodoUsuario *users = NULL;
NodoDisco *discos=NULL;
int COMPRAS=0;
NodoUsuario* leer_lista_usuarios(NodoUsuario *inicio);
NodoUsuario* lista_ingresar_usuario(NodoUsuario *inicio, char archUsrTMP[20], char usr[20], char pwd[20], int edadTMP, int numeroComprasTMP, int discosCompradosTMP);
int logueo(NodoUsuario *users);
int guardar_usuarios(NodoUsuario *users);
NodoUsuario* nuevo_usuario(NodoUsuario *users);
NodoDisco* lista_ingresar_disco(NodoDisco *inicio,char archDiskTMP[40],char artistaTMP[40],char nombreDiscoTMP[40] ,double precioTMP,int anioLanzamientoTMP,int numeroComprasTMP);
NodoDisco* leer_lista_discos(NodoDisco *inicio);
int guardar_discos(NodoDisco *users);
NodoDisco* nuevo_disco(NodoDisco *inicio);
int admin(void);
void mostrarDiscos(void);
void editarDisco(void);
void realizar_busquedas(void);
int busqueda_artista(char art[40]);
int busqueda_nombreDisco(char ndd[40]);
int busqueda_anio(int anio);
int busqueda_compras(int comp);
void mostrarUsuarios(void);
void usuario(char usr[40]);
int guardar_usuarios(NodoUsuario *users);
int editarPerfil(char usr[40]);
void comprarDisco(char usr[40]);

int main(int argc, char const *argv[]){
	
	users=leer_lista_usuarios(users);
	discos=leer_lista_discos(discos);
	
	logueo(users);
	
	guardar_usuarios(users);
	guardar_discos(discos);
	
	return 0;
}

void comprarDisco(char usr[40]){
	NodoDisco *tmpDiscos=discos;
	NodoUsuario *tmpUsr=users;
	int i,opc;		
	mostrarDiscos();
	printf("\n\n\tElegir Disco:  ");
	scanf("%d",&opc);

	while(tmpUsr!=NULL){
		if(strcmp(tmpUsr->usuario,usr)==0)
			break;
		else
			tmpUsr=tmpUsr->sig;
	}
	for(i=1;i<opc;i++){
		if(tmpDiscos!=NULL){
			tmpDiscos=tmpDiscos->sig;
		}
	}

	printf("Compro el disco %s de %s\n",tmpDiscos->nombreDisco,tmpDiscos->artista);
	getchar();
	getchar();
	tmpDiscos->numeroCompras++;
	tmpUsr->discosComprados++;
	if(COMPRAS==0)
		tmpUsr->numeroCompras++;
}

int busqueda_nombreDisco(char ndd[40]){
	NodoDisco *dis = discos;
	int i=0;
	while(dis != NULL){
		if(strcmp(dis->nombreDisco,ndd)==0){
			printf("%d. %s %s %lf %d\n",++i,dis->nombreDisco,dis->artista,dis->precio,dis->anioLanzamiento);
		}
		dis = dis->sig;
	}
	if(i==0)
		return 1;
	else
		return 0;
}

int busqueda_artista(char art[40]){
	NodoDisco *dis = discos;
	int i=0;
	while(dis != NULL){
		if(strcmp(dis->artista,art)==0){
			printf("%d. %s %s %lf %d\n",++i,dis->nombreDisco,dis->artista,dis->precio,dis->anioLanzamiento);
		}
		dis = dis->sig;
	}
	if(i==0)
		return 1;
	else
		return 0;
}

int busqueda_anio(int anio){
	NodoDisco *dis = discos;
	int i=0;
	while(dis != NULL){
		if(dis->anioLanzamiento == anio){
			printf("%d. %s %s %lf %d\n",++i,dis->nombreDisco,dis->artista,dis->precio,dis->anioLanzamiento);
		}
		dis = dis->sig;
	}
	if(i==0)
		return 1;
	else
		return 0;
}

int busqueda_compras(int comp){
	NodoDisco *dis = discos;
	int i=0;
	while(dis != NULL){
		if(dis->numeroCompras == comp){
			printf("%d. %s %s %lf %d\n",++i,dis->nombreDisco,dis->artista,dis->precio,dis->anioLanzamiento);
		}
		dis = dis->sig;
	}
	if(i==0)
		return 1;
	else
		return 0;
}

void realizar_busquedas(void){
	int opc,param;
	char art[40];
	char ndd[40];
	int anio;
	int comp;
	do{
		system("clear");
		printf("\n\t\tRealizar Busquedas\n");
		printf("\n\t\t1. Artista\n\t\t2. Nombre del Disco\n\t\t3. Año de Lanzamiento\n\t\t4. Numero de Compras\n\t\t5. Salir\n");
		printf("Opcion: ");
		scanf("%d",&opc);

		switch(opc){
			case 1:
				printf("Ingrese el nombre del Artista:  ");
				scanf("%s",art);
				param = busqueda_artista(art);
				if(param==1)
					printf("\n\n\tNo se encontraron coinsidencias");
				getchar();
				getchar();
				break;
			case 2:
				printf("Ingrese el nombre del disco:  ");
				scanf("%s",ndd);
				param=busqueda_nombreDisco(ndd);
				if(param==1)
					printf("\n\n\tNo se encontraron coinsidencias");
				getchar();
				getchar();
				break;
			case 3:
				printf("Ingrese el nombre año:  ");
				scanf("%d",&anio);
				param=busqueda_anio(anio);
				if(param==1)
					printf("\n\n\tNo se encontraron coinsidencias");
				getchar();
				getchar();
				break;
			case 4:
				printf("Ingrese el numero de compras:  ");
				scanf("%d",&comp);
				param=busqueda_compras(comp);
				if(param==1)
					printf("\n\n\tNo se encontraron coinsidencias");
				getchar();
				getchar();
				break;
			case 5:
				break;
			default:
				printf("Opcion no valida\n");
				getchar();
				getchar();

		}
	}while(opc!=5);
}

int borrar_usuario(void){
	int indice;
	printf("Usuarios: \n");
	//mostrarDiscos();
	mostrarUsuarios();
	scanf("%d",&indice);
	
	NodoUsuario *nodoActual = users;
	if(users==NULL){
		return 0;
	}else if(indice == 0){
		nodoActual = users->sig;
		free(users);
		users=nodoActual;
	}
	else{
		NodoUsuario *anterior = users;
		int i = 0;
		while(i<indice && nodoActual->sig != NULL){
			anterior = nodoActual;
			nodoActual = nodoActual->sig;
			i++;
		}
		anterior->sig = nodoActual->sig;
		free(nodoActual);
		if(i==0){
			return 0;
		}
	}
	return 1;
}

int borrar_disco(void){
	int indice;

	printf("Discos: \n");
	
	NodoUsuario *tmp3 = users;
	int i=0;
	while(tmp3 != NULL){
		printf("%d. %s\n",++i,tmp3->usuario);
		tmp3= tmp3->sig;
	}
	scanf("%d",&indice);
	
	NodoUsuario *nodoActual = users;
	if(users==NULL){
		return 0;
	}else if(indice == 0){
		nodoActual = users->sig;
		free(users);
		users=nodoActual;
	}else{
		NodoUsuario *anterior = users;
		int j = 0;
		while(j<indice && nodoActual->sig != NULL){
			anterior = nodoActual;
			nodoActual = nodoActual->sig;
			j++;
		}
		anterior->sig = nodoActual->sig;
		free(nodoActual);
		if(j==0){
			return 0;
		}
	}
	return 1;
}

NodoDisco* nuevo_disco(NodoDisco *inicio){
	NodoDisco *nuevoNodo=NULL;
	NodoDisco *nodoActual=inicio;
	char art[40],nomDisc[40];
	double pres;
	int anio,num;

	printf("\n\n\t\t\tRegistro de un nuevo Disco\n\t\t\t(usar notacion CamelCase)");
	printf("\n\n\t\t\tArtista: ");
	scanf("%s", art);
	printf("\n\t\t\tNombre del Disco: ");
	scanf("%s", nomDisc);
	printf("\n\t\t\tPrecio: ");
	scanf("%lf",&pres);
	printf("\n\t\t\tAño de Lanzamient: ");
	scanf("%d",&anio);
	
	while(nodoActual->sig != NULL){
		if(strcmp(nodoActual->artista,art)==0){
			printf("Disco ya existente\n");
			return inicio;
		}else{
			nodoActual=nodoActual->sig;
		}
	}
	nuevoNodo = malloc(sizeof(NodoDisco));
	strcpy(nuevoNodo->archDisk,art);
	strcpy(nuevoNodo->artista,art);
	strcpy(nuevoNodo->nombreDisco,nomDisc);
	nuevoNodo->precio = pres;
	nuevoNodo->anioLanzamiento = anio;
	nuevoNodo->numeroCompras = 0;
	nuevoNodo->sig = NULL;
	nodoActual->sig=nuevoNodo;

	return inicio;
}

void mostrarUsuarios(void){
	NodoUsuario *tmp = users;
	int i=0;
	system("clear");
	printf("\n\n");
	while(tmp != NULL){
		printf("\t\t%d. %s\n",++i,tmp->usuario);
		tmp= tmp->sig;
	}
	getchar();
	getchar();
	system("clear");
}

void mostrarDiscos(void){
	NodoDisco *tmp = discos;
	int i=0;
	system("clear");
	printf("\n\n");
	while(tmp != NULL){
		printf("\t\t%d. %s %s\n",++i,tmp->nombreDisco,tmp->artista);
		tmp= tmp->sig;
	}
	getchar();
	getchar();
	//system("clear");
}

void editarDisco(void){
	int i,opc,opc2;
	NodoDisco *tmp=discos;
	system("clear");
	printf("Discos:  \n");
	mostrarDiscos();
	printf("\nSeleccione que disco desea modificar:\t");
	scanf("%d",&opc);
	for(i=0;i<opc;i++){
		tmp=tmp->sig;
	}
	system("clear");
	
	do{
		printf("\n\t\tSeleccione lo que se quiere modificar: \n");
		printf("\n\t\t1. Nombre de Disco\n\t\t2. Artista\n\t\t3. Precio\n\t\t4. Año\n\t\t5. Salir");
		scanf("%d",&opc2);

		switch(opc2){
			case 1:
				printf("Ingrese el nuevo nombre del disco: ");
				scanf("%s",tmp->nombreDisco);
				break;
			case 2:
				printf("Ingrese e nuevo artista del disco: ");
				scanf("%s",tmp->artista);
				break;
			case 3:
				printf("Ingrese el nuevo precio: ");
				scanf("%lf",&tmp->precio);
				break;
			case 4:
				printf("Ingrese el nuevo año del disco: ");
				scanf("%d",&tmp->anioLanzamiento);
			case 5:
				break;
			default:
				printf("Opcion no valida\n");
		}	
	}while(opc2 != 5);
}

int admin(void){
	int opc;
	do{
		system("clear");
		printf("\n\n\t\t--Bienvenido al modo administrador--");
		printf("\n\n\t\t1. Mostrar Discos\n\t\t2. Editar Información de los Discos\n\t\t3. Agregar Disco\n\t\t4. Borrar Disco\n\t\t5. Buscar\n\t\t6. Agregar usuario\n\t\t7. Borrar usuario\n\t\t8. Salir");
		printf("\n\n\t\tOpcion:   ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				system("clear");
				mostrarDiscos();
				break;
			case 2:
				system("clear");
				editarDisco();
				break;
			case 3:
				system("clear");
				nuevo_disco(discos);
				break;
			case 4:
				system("clear");
				borrar_disco();
				break;
			case 5:
				system("clear");
				realizar_busquedas();
				break;
			case 6:
				system("clear");
				nuevo_usuario(users);
				break;
			case 7:
				system("clear");
				borrar_usuario();
				break;
			case 8:
				system("clear");
				printf("\n\n\t\tGracias por usar esta aplicacion");
				getchar();
				getchar();
				system("clear");
				break;
			default:
				printf("Opcion no valida\n");
				getchar();
				getchar();
		}
	}while(opc != 8);
}

int guardar_discos(NodoDisco *discos){
	FILE *apu=fopen("discos","w+");
	FILE *apu2=NULL;
	NodoDisco *nodoActual=discos;
	NodoDisco *tmp = NULL;

	if(!apu){
		printf("Error al abrir el archivo: ");
		return 1;
	}

	if(nodoActual==NULL){
		printf("Esta nulo %s\n",nodoActual->archDisk);
	}

	while(nodoActual!=NULL){
		fprintf(apu, "%s\n",nodoActual->archDisk);
		//printf("Guardando:\t %s\n",nodoActual->archDisk);
		apu2=fopen(nodoActual->archDisk,"w");
		fprintf(apu2,"%s %s %lf %d %d\n",nodoActual->artista,nodoActual->nombreDisco,nodoActual->precio,nodoActual->anioLanzamiento,nodoActual->numeroCompras);
		tmp=nodoActual->sig;
		free(nodoActual);
		nodoActual=tmp;
	}
	return 0;
}

NodoDisco* leer_lista_discos(NodoDisco *inicio){
	FILE *apu = fopen("discos","r");
	FILE *apu2;
	char archDisk[40];
	char artista[40];
	char nombreDisco[40];
	double precio;
	int anioLanzamiento;
	int numeroCompras;
	
	if(!apu){
		printf("Error al abrir el archivo\n");
		return inicio;
	}
	do{

		fscanf(apu,"%s\n",archDisk);
		apu2=fopen(archDisk,"r");
		
		fscanf(apu2,"%s %s %lf %d %d\n",artista,nombreDisco,&precio,&anioLanzamiento,&numeroCompras);
		//printf("%s ",archUsr );
		//printf("%s %s %d %d %d\n",usuario,passwd,edad,numeroCompras,discosComprados);
		inicio=lista_ingresar_disco(inicio,archDisk,artista,nombreDisco,precio,anioLanzamiento,numeroCompras);
		
	}while(!feof(apu));

	return inicio;
}

NodoDisco* lista_ingresar_disco(NodoDisco *inicio,char archDiskTMP[40],char artistaTMP[40],char nombreDiscoTMP[40] ,double precioTMP,int anioLanzamientoTMP,int numeroComprasTMP){
	NodoDisco *nodoActual = inicio;
	if(inicio==NULL){
		nodoActual = malloc(sizeof(NodoDisco));
		strcpy(nodoActual->archDisk,archDiskTMP);
		strcpy(nodoActual->artista,artistaTMP);
		strcpy(nodoActual->nombreDisco,nombreDiscoTMP);
		nodoActual->precio = precioTMP;
		nodoActual->anioLanzamiento = anioLanzamientoTMP;
		nodoActual->numeroCompras = numeroComprasTMP;
		nodoActual->sig = NULL;

		inicio = nodoActual;

	}else{
		while(nodoActual->sig != NULL){
			nodoActual = nodoActual->sig;
		}
		NodoDisco *nuevoNodo = malloc(sizeof(NodoDisco));
		strcpy(nuevoNodo->archDisk,archDiskTMP);
		strcpy(nuevoNodo->artista,artistaTMP);
		strcpy(nuevoNodo->nombreDisco,nombreDiscoTMP);
		nuevoNodo->precio = precioTMP;
		nuevoNodo->anioLanzamiento = anioLanzamientoTMP;
		nuevoNodo->numeroCompras = numeroComprasTMP;
		nuevoNodo->sig = NULL;
		nodoActual->sig = nuevoNodo;
	}
	return inicio;
}

NodoUsuario* nuevo_usuario(NodoUsuario *users){
	NodoUsuario *nuevoNodo=users;
	NodoUsuario *nodoActual=users;
	char usr[20],pwd[20];
	int edad;

	printf("\n\n\t\t\tRegistro de usuarios");
	printf("\n\n\t\t\tUsuario: ");
	scanf("%s", usr);
	printf("\n\t\t\tContraseña: ");
	scanf("%s", pwd);
	printf("\n\t\t\tEdad: ");
	scanf("%d",&edad);

	while(nodoActual->sig != NULL){
		if(strcmp(nodoActual->usuario,usr)==0){
			printf("Usuario ya existente\n");
			return users;
		}else{
			nodoActual=nodoActual->sig;
		}
	}
	nuevoNodo = malloc(sizeof(NodoUsuario));
	strcpy(nuevoNodo->archUsr,usr);
	strcpy(nuevoNodo->usuario,usr);
	strcpy(nuevoNodo->passwd,pwd);
	nuevoNodo->edad = edad;
	nuevoNodo->numeroCompras = 0;
	nuevoNodo->discosComprados = 0;
	nuevoNodo->sig = NULL;
	nodoActual->sig=nuevoNodo;
	int i=0;

	return users;
}

int guardar_usuarios(NodoUsuario *users){
	FILE *apu=fopen("usuarios","w+");
	FILE *apu2=NULL;
	NodoUsuario *nodoActual=users;
	NodoUsuario *tmp = NULL;

	if(!apu){
		printf("Error al abrir el archivo: ");
		return 1;
	}

	if(nodoActual==NULL){
		printf("Esta nulo %s\n",nodoActual->archUsr);
	}

	while(nodoActual!=NULL){
		fprintf(apu, "%s\n",nodoActual->archUsr);
		apu2=fopen(nodoActual->archUsr,"w");
		fprintf(apu2,"%s %s %d %d %d\n",nodoActual->usuario,nodoActual->passwd,nodoActual->edad,nodoActual->numeroCompras,nodoActual->discosComprados);
		tmp=nodoActual->sig;
		free(nodoActual);
		nodoActual=tmp;
	}
	return 0;
}

int editarPerfil(char usr[40]){
	NodoUsuario *tmp = users;
	int opc;
	while(tmp!=NULL){
		tmp = tmp->sig;
		if(strcmp(tmp->usuario,usr)==0){
			break;
		}
	}
	system("clear");
	printf("\n\n\t\tEditando Perfil de %s\n", usr);
	do{
		printf("\n\n\t\t1. Cambiar Contraseña\n\t\t2. Cambiar edad\n\t\t3. Salir\n");
		printf("\n\t\tOpcion:  ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				system("clear");
				printf("\n\n\t\tIngrese Nueva Contraseña:  ");
				scanf("%s",tmp->passwd);
				break;
			case 2:
				system("clear");
				printf("\n\n\t\tIngrese su Edad:  ");
				scanf("%d",&tmp->edad);
				break;
			case 3:
				system("clear");
				break;
			default:
				printf("Opcion no valida\n");
				getchar();
				getchar();

		}
	}while(opc!=3);
}

void usuario(char usr[40]){
	int opc;
	do{
		system("clear");
		printf("\n\n\t\t--Bienvenido %s--",usr);
		printf("\n\n\t\t1. Mostrar Discos\n\t\t2. Buscar\n\t\t3. Comprar Discos\n\t\t4. Editar Perfil\n\t\t5. Salir");
		printf("\n\n\t\tOpcion:   ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				system("clear");
				mostrarDiscos();
				break;
			case 2:
				system("clear");
				realizar_busquedas();
				break;
			case 3:
				system("clear");
				comprarDisco(usr);
				break;
			case 4:
				system("clear");
				editarPerfil(usr);
				break;
			case 5:
				system("clear");
				printf("\n\n\t\tGracias por usar esta aplicacion");
				getchar();
				getchar();
				system("clear");
				break;
			default:
				printf("Opcion no valida\n");
				getchar();
				getchar();
		}
	}while(opc != 5);
}	

int logueo(NodoUsuario *users){

	NodoUsuario *inicio = users;
	char usr[20];
	char pwd[20];
	int cont=0;
	
	system("clear");
	printf("\n\n\t\t--Bienvenido a la prebe-tienda de discos--");
	printf("\n\n\t\t  Creado por: Torres Caballero Bruno");
	getchar();
	
	do{
		system("clear");
		printf("\n\n\t\t\tInicio de sesión:");
		printf("\n\n\t\t\tUsuario: ");
		scanf("%s", usr);
		printf("\n\t\t\tContraseña: ");
		scanf("%s", pwd);

		if (strcmp(usr,"ADMIN")==0 && strcmp(pwd, "ADMIN") == 0){
			admin();
			return 1;
		}else {
			while(inicio != NULL){
				if(strcmp(usr,inicio->usuario)==0 && strcmp(pwd,inicio->passwd) == 0){
					usuario(inicio->usuario);
					return 1;
				}
				inicio=inicio->sig;
			}	
			
		}
		printf("\n\n\t\tAcceso denegado");
		getchar();
		getchar();
		cont++;
	}while(cont <4);
	return 0;
}

NodoUsuario* leer_lista_usuarios(NodoUsuario *inicio){
	FILE *apu = fopen("usuarios","r");
	FILE *apu2;
	char archUsr[20];
    char usuario[20];
    char passwd[20];
    int edad;
	int numeroCompras;
	int discosComprados;
	
	if(!apu){
		printf("Error al abrir el archivo\n");
		return inicio;
	}

	do{
		fscanf(apu,"%s\n",archUsr);
		apu2=fopen(archUsr,"r");
		if(!apu2){
			printf("Error al abrir el archivo\n");
			return inicio;
		}
		fscanf(apu2,"%s %s %d %d %d\n",usuario,passwd,&edad,&numeroCompras,&discosComprados);
		
		inicio=lista_ingresar_usuario(inicio,archUsr,usuario,passwd,edad,numeroCompras,discosComprados);
		
	}while(!feof(apu));

	fclose(apu);
	fclose(apu2);
	return inicio;
}

NodoUsuario* lista_ingresar_usuario(NodoUsuario *inicio,char archUsrTMP[20], char usr[20], char pwd[20], int edadTMP, int numeroComprasTMP, int discosCompradosTMP){
	NodoUsuario *nodoActual = inicio;
	if(inicio==NULL){
		nodoActual = malloc(sizeof(NodoUsuario));
		strcpy(nodoActual->archUsr,archUsrTMP);
		strcpy(nodoActual->usuario,usr);
		strcpy(nodoActual->passwd,pwd);
		nodoActual->edad = edadTMP;
		nodoActual->numeroCompras = numeroComprasTMP;
		nodoActual->discosComprados = discosCompradosTMP;
		nodoActual->sig = NULL;

		inicio = nodoActual;
	}
	else{
		while(nodoActual->sig != NULL){
			nodoActual = nodoActual->sig;
		}
		NodoUsuario *nuevoNodo = malloc(sizeof(NodoUsuario));
		strcpy(nuevoNodo->archUsr,archUsrTMP);
		strcpy(nuevoNodo->usuario,usr);
		strcpy(nuevoNodo->passwd,pwd);
		nuevoNodo->edad = edadTMP;
		nuevoNodo->numeroCompras = numeroComprasTMP;
		nuevoNodo->discosComprados = discosCompradosTMP;
		nuevoNodo->sig = NULL;
		nodoActual->sig = nuevoNodo;
	}
	return inicio;
}
