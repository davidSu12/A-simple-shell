main: main.o historicList.o fileList.o
	gcc -o main main.o historicList.o
main.o: main.c historicList.h libmain.h firstlib.h fileList.h
	gcc -c main.c
historicList.o: historicList.c historicList.h
	gcc -c historicList.c
fileList.o: fileList.c fileList.h
	gcc -c fileList.c
clean:
	rm -f main.o historicList.o fileList.o main 