CXX=      g++
CXXLINK=  $(CXX)
CXXFLAGS= -g -Wall -std=c++11
OBJS=     ip.o port.o string.o main.o


firewall.exe: libfirewall.so libinput.so $(OBJS)
	$(CXXLINK) -g -Wall $(OBJS) -o firewall.exe -lfirewall -linput -L. 

main.o: main.cpp port.h generic-field.h string.h ip.h
	$(CXX) $(CXXFLAGS) -c -fpic main.cpp
	
libfirewall.so: ip.o port.o string.o
	$(CXXLINK) -shared ip.o port.o string.o -o libfirewall.so
	
port.o: port.cpp port.h generic-field.h string.h
	$(CXX) $(CXXFLAGS) -c -fpic port.cpp
	
ip.o: ip.cpp ip.h generic-field.h string.h
	$(CXX) $(CXXFLAGS) -c -fpic ip.cpp
	
string.o: string.cpp string.h
	$(CXX) $(CXXFLAGS) -c -fpic string.cpp	

clean:
	rm -f *.o *.exe libfirewall.so

