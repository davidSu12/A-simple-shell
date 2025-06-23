#include "fileList.h" 


static FileList list;


#define ELEMENT_NOT_FOUND (NULLFILE)


//MAX_FILE_LEN

/*

*/

void deleteItemFileList(type_fd fd){
	FileListPosition pos = searchItemFileList(fd);
	if(pos != ELEMENT_NOT_FOUND){
		for(; pos < lastFileList(); pos ++){
			list.data[pos] = list.data[pos + 1];
		}
		list.top --;
	}

	fprintf(stderr, "There is not such descriptor on the file list\n");
}
void deleteListFileList(){
	free(list.data);
	list.top = NULLFILE;
}
void createEmptyListFile(){
	list.data = calloc(MAX_FILE_LEN, sizeof(struct entry));
	list.top = NULLFILE;
	if(list.data == NULL){
		fprintf(stderr, "An error has ocurred while creating fileList");
		exit(EXIT_FAILURE);
	}
}
bool isEmptyFileList(){
	return list.top == NULLFILE;
}
bool insertItemFileList(type_fd fd, type_mode mode){
	if(list.top == MAX_FILE_LEN){
		//añadimos diez elementos mas
		itemFile *ptr = (itemFile *) realloc(list.data, 
									sizeof(list.data) + sizeof(struct entry) * 10);

		if(ptr == NULL){
			//no queda mas memoria
			fprintf(stderr, "There is no more memory for fileList");
			return false;
		}else{
			return insertItemFileList(fd, mode);
		}
	}else{

		list.top++;
		list.data[list.top].fd = fd;
		list.data[list.top].mode = mode;
		return true;

	}
}
FileListPosition nextFileList(FileListPosition p){
	if(list.top == MAX_FILE_LEN){
		return NULLFILE;
	}
	return ++p;
}
FileListPosition previousFileList(FileListPosition p){
	if(p == 0){
		return NULLFILE;
	}
	return --p;
}

FileListPosition firstFileList(){
	if(!isEmptyFileList()){
		return 0;
	}
	return NULLFILE;
}
FileListPosition lastFileList(){
	if(!isEmptyFileList()){
		return list.top;
	}
	return NULLFILE;
}

itemFile getItemFileList(FileListPosition p){
	return list.data[p];
}
FileListPosition searchItemFileList(type_fd fd){
	FileListPosition p;

	if(isEmptyFileList()){
		return NULLFILE;
	}else{
		for(p = firstFileList(); p <= lastFileList(); p = nextFileList(p)){
			itemFile temp = getItemFileList(p);
			if(temp.fd == fd){
				return p;
			}

		}
	}

	return ELEMENT_NOT_FOUND;
}
