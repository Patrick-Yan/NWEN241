
dbTable: dbTable.o
	g++ -o  dbTable dbTable.o



dbTable.o: dbTable.cc dbTable.hh
	g++ -c dbTable.cc


server: server.o
	g++ -o server server.o



server.o: server.c dbTable.hh
	g++ -c server.cc


clean:
	rm -rf *.o dbTable server
