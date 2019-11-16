
objects		:= ./src/findway.o ./src/procinfo.o main.o

ps : $(objects) 
	g++	-o ps $(objects)

./src/findway.o : ./src/procnode.h
./src/procinfo.o : ./src/findway.h ./src/procnode.h
main.o : ./src/procnode.h

clean :
	-rm $(objects)