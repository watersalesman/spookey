PACKAGE = spookey
CPP = g++
CPPFLAGS = -g -O3
LIBS = -lpthread

spookey: spookey.cc spookey.hh
	$(CPP) $(CPPFLAGS) -o $(PACKAGE) $(LIBS) $(PACKAGE).cc

clean:
	rm -f *.log $(PACKAGE)
