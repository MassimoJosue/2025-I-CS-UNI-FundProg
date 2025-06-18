CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -pthread # Añadido -pthread
LDFLAGS = -pthread # Añadido -pthread

TARGET = main
SRCS = main.cpp arit.cpp demos.cpp array.cpp sorting.cpp \
       struct.cpp recursion.cpp mystring.cpp classes.cpp util.cpp \
	   compareFunc.cpp Pointers.cpp DemoComplex.cpp \
	   inheritance.cpp \
	   academico/person.cpp \
	   academico/professor.cpp \
	   academico/student.cpp \
	   academico/undergradstudent.cpp \
	   academico/graduatestudent.cpp \
	   academico/admin.cpp \
	   DemoTemplates.cpp \
	   DemoFiles.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean