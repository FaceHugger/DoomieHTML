CC= g++ 
CFLAGS= -ggdb -Wno-deprecated -Wall 
PRINCIPAL = testing.cpp
objetos=  DOM_Tree.h 
EXE= run

$(EXE): $(PRINCIPAL) $(objetos)
	$(CC)-o $@ $^
main: $(PRINCIPAL).cpp
	 $(CC) $(CFLAGS) -c -o $@ $^
DOM_Tree.o: DOM_Tree.h
	$(CC) -o $(CFLAGS)-c -o $@ $<

clean:
	rm -rf QT *.o
