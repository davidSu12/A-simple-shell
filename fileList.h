#ifndef FILELIST_H
#define FILELIST_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "firstlib.h"

#define MAX_FILE_LEN 20

typedef int type_fd;
typedef unsigned int type_mode; 
typedef int FileListPosition;

struct entry{
	type_fd fd;
	type_mode mode;
};

typedef struct entry item;

typedef struct list{
	item data[MAX_FILE_LEN];
	unsigned int top;
} list;



void createEmptyListFile();
bool insertItemFileList(type_fd fd, type_mode mode);
void deleteItemFileList(type_fd fd);
void deleteListFileList();
bool isEmptyListFileList();
FileListPosition nextFileList(FileListPosition p);
FileListPosition previousFileList(FileListPosition p);
FileListPosition firstFileList();
FileListPosition lastFileList();
FileListPosition searchItem(type_fd fd);
item getItem(type_fd fd);





#endif //FILELIST_H