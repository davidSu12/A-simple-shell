main: main.o historicList.o
	gcc -o main main.o historicList.o
main.o: main.c historicList.h libmain.h firstlib.h
	gcc -c main.c
historicList.o: historicList.c historicList.h
	gcc -c historicList.c

clean:
	rm -f main.o historicList.o main