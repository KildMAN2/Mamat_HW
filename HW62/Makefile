CXX = g++
CXXFLAGS = -g -Wall -std=c++11 -fPIC
LDFLAGS = -L.
LDLIBS = -lfirewall -linput

TARGET = firewall.exe
LIBRARY = libfirewall.so
# Exclude main.o for the LIB_OBJS used in the shared library
LIB_OBJS = ip.o port.o string.o string-array.o
OBJS = $(LIB_OBJS) main.o

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBRARY)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS) $(LDLIBS)

$(LIBRARY): $(LIB_OBJS)
	$(CXX) -shared -o $(LIBRARY) $(LIB_OBJS) -fPIC

main.o: main.cpp port.h generic-field.h string.h ip.h generic-string.h string-array.h
	$(CXX) $(CXXFLAGS) -c main.cpp

port.o: port.cpp port.h generic-field.h string.h generic-string.h string-array.h
	$(CXX) $(CXXFLAGS) -c port.cpp

ip.o: ip.cpp ip.h generic-field.h string.h generic-string.h string-array.h
	$(CXX) $(CXXFLAGS) -c ip.cpp

string.o: string.cpp string.h generic-string.h string-array.h
	$(CXX) $(CXXFLAGS) -c string.cpp

string-array.o: string-array.cpp string-array.h generic-string.h string.h
	$(CXX) $(CXXFLAGS) -c string-array.cpp


clean:
	rm -f *.o $(TARGET) $(LIBRARY)
