
libev.sn:libev.o sn.o 
	g++ -g -o libev.sn libev.o sn.o -lev 
libev.o:libev.cpp
	g++ -g -c libev.cpp -lev
sn.o:sn.cpp
	g++ -g -c sn.cpp

.PHONY:clean
clean:
	-rm ./*.o libev.sn
