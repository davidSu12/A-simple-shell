#include "firstlib.h"
#include "libmain.h"
#include "fileList.h"
#include "historicList.h"
#include "aux_func_main.h"

void authors(char comando[], char *partes_comando[]);
void pid();
void ppid();
void cd(char comando[], char *partes_comando[]);
void date_aux(char comando[], char *partes_comando[]);
void historic(char comando[], char *partes_comando[]);
void open_aux(char comando[], char *partes_comando[]);
void close_df(char comando[], char *partes_comando[]);
void dup_aux(char comando[], char *partes_comando[]);
void infosys();
void help_cmd(char comando[], char *partes_comando[]);
void quit();
