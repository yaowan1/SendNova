
libev.sn: 
	g++ -g -o libev.sn libev.cpp -lev


.PHONY:clean
clean:
	-rm libev.sn
