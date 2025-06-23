main: main.o historicList.o fileList.o aux_func_main.o commands.o
	gcc -o main main.o historicList.o aux_func_main.o commands.o



main.o: main.c historicList.h libmain.h firstlib.h fileList.h aux_func_main.h commands.h 
	gcc -c main.c



historicList.o: historicList.c historicList.h
	gcc -c historicList.c



fileList.o: fileList.c fileList.h
	gcc -c fileList.c


aux_func_main.o: aux_func_main.c aux_func_main.h
	gcc -c aux_func_main.c

commands.o: commands.c commands.h 
	gcc -c commands.c


clean:
	rm -f main.o historicList.o fileList.o aux_func_main.o commands.o main 