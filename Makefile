CXX           = g++
CXXFLAGS      = -O2 -std=c++11 -stdlib=libc++
OBJGROUP      = main.o mds.o
SOURCES       = main.cpp mds.cpp
INCPATH       = -I.
TARGET        = mds

all: mds
mds:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)
clean:
	rm -f *.o $(TARGET)
