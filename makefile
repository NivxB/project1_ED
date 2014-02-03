tda:	main.o integer.o linkedlist.o object.o tdalist.o dllnode.o varraylist.o farraylist.o dlcursorlist.o SLLNode.o slinkedlist.o
	g++ main.o integer.o dllnode.o linkedlist.o object.o tdalist.o varraylist.o farraylist.o dlcursorlist.o SLLNode.o slinkedlist.o -o tda
main.o:	main.cpp tdalist.h linkedlist.h integer.h
	g++ -c main.cpp
integer.o:	integer.cpp integer.h object.h
	g++ -c integer.cpp
dllnode.o:	dllnode.cpp dllnode.h
	g++ -c dllnode.cpp
SLLNode.o: SLLNode.cpp SLLNode.h
	g++ -c SLLNode.cpp
tdalist.o:	tdalist.h tdalist.cpp
	g++ -c tdalist.cpp
linkedlist.o:	linkedlist.cpp linkedlist.h tdalist.h object.h
	g++ -c linkedlist.cpp
object.o:	object.h object.cpp
	g++ -c object.cpp
varraylist.o: varraylist.h varraylist.cpp tdalist.h object.h
	g++ -c varraylist.cpp
farraylist.o: farraylist.h farraylist.cpp tdalist.h object.h
	g++ -c farraylist.cpp
dlcursorlist.o: dlcursorlist.h dlcursorlist.cpp tdalist.h object.h
	g++ -c dlcursorlist.cpp
slinkedlist.o: slinkedlist.h slinkedlist.cpp tdalist.h object.h
	g++ -c slinkedlist.cpp
clean:
	rm *.o tda
