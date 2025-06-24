#include "commands.h"


#define MAX_LEN_DIRECTORY 512


void authors(char comando[], char *partes_comando[]){
	//partes_comando[0] es solo el comando
	const char * name = "david suarez";
	const char * email = "aux@gmail.com";

	const char * opt = partes_comando[1];
	if(!opt){
		fprintf(stdout, "%s\n%s\n", name, email);
	}else if(!strcmp(opt, "-n")){
		fprintf(stdout, "%s\n", name);
	}else if(!strcmp(opt, "-l")){
		fprintf(stdout, "%s\n", email);
		//en este caso opt es nulo y por ende imprimimos toda la informacion
		
	}else{
		fprintf(stderr, "An unknown option has been introduced in authors\n");
	}
}
void pid(){
	pid_t pid = getpid();
	fprintf(stdout, "pid:%d\n", (int) pid);
}

void ppid(){
	pid_t pid = getppid();
	fprintf(stdout, "ppid:%d\n", (int) pid);
}
void cd(char comando[], char *partes_comando[]){
	const char * dir = partes_comando[1];
	char buff[MAX_LEN_DIRECTORY];

	if(!dir){
		if(getcwd(buff, sizeof(buff))){
			printf("%s\n", buff);
		}else{
			fprintf(stderr, "An error has ocurred while printing current directory\n");
		}
	}else{
		if(chdir(dir)){
			fprintf(stderr, "An error has ocurred while changing working directory\n");
		}
	}
}
void date_aux(char comando[], char *partes_comando[]){
	const char * opt = partes_comando[1];
	time_t tiempo;

	struct tm *info_tiempo;

	time(&tiempo);
	info_tiempo = localtime(&tiempo);

	if(!opt){
		fprintf(stdout,
			"%02d:%02d:%02d\n%02d/%02d/%04d\n", 
			info_tiempo -> tm_hour,
			info_tiempo -> tm_min,
			info_tiempo -> tm_sec,
			info_tiempo -> tm_mday,
			info_tiempo -> tm_mon + 1,
			info_tiempo -> tm_year + 1900); 
	}else if(!strcmp(opt, "-t")){
		fprintf(stdout,
			"%02d:%02d:%02d\n", 
			info_tiempo -> tm_hour,
			info_tiempo -> tm_min,
			info_tiempo -> tm_sec);
	}else if(!strcmp(opt, "-d")){
		fprintf(stdout,
			"%02d/%02d/%04d\n", 
			info_tiempo -> tm_mday,
			info_tiempo -> tm_mon + 1,
			info_tiempo -> tm_year + 1900);

	}else{
		fprintf(stderr, "An unknown option has been introduced in date\n");
	}
}
void historic(char comando[], char *partes_comando[]){
	const char * opt = partes_comando[1];
	char *p;

	if(!opt){
		imprimirListaHistorico(-1);
	}else{ 
		p = strchr(opt, '-');
		if(!p){
		//no se encuentra -
		//repetimos el comando n-esimo
			posHistorico m = buscarN(atoi(opt));
			if(!m){
				//el elemento no existe
				fprintf(stderr, "No existe ningun comando en la posicion %d del historico\n", atoi(opt));
				return;
			}else{
				procesarEntrada(m -> data, m -> data_parts);
			}

		}else{
			int lim = atoi(++p);
			imprimirListaHistorico(lim);
	
		}
	}
}
/*
funciones de control de archivos
*/

void open_aux(char comando[], char *partes_comando[]);
void close_df(char comando[], char *partes_comando[]);
void dup_aux(char comando[], char *partes_comando[]);


void infosys(){

	struct utsname buffer;
	if(uname(&buffer) != 0){
		fprintf(stderr, "An error has ocurred while using uname\n");
		return;
	}
	printf("SO:%s\n", buffer.sysname);
    printf("Nodename:%s\n", buffer.nodename);
    printf("Release:%s\n", buffer.release);
    printf("Versión:%s\n", buffer.version);
    printf("Arch:%s\n", buffer.machine);

}

void help_cmd(char comando[], char *partes_comando[]){
	fprintf(stderr, "Not imlpemented yet.\n");
}

void quit(){
	exit(EXIT_SUCCESS);
}