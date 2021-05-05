Executable=Agario3D
CompilerFlag=-std=c++17
LinkerFlag=-lGL -lGLU -lglut -lm
Source= $(wildcard *.cpp)
Object= $(patsubst %.cpp,%.o,$(Source))

all: $(Executable)

$(Executable): $(Object)
	g++ $(LinkerFlag) $(Object) -o $@ 

%.o:%.cpp
	g++ -c $(CompilerFlag) $< -o $@

clean:
	rm $(Executable) $(Object) -f
