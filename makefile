include .env

all: folder compile link

fresh: clean all

folder:
	mkdir -p build
	mkdir -p build/Modele
	mkdir -p build/Vue
	mkdir -p build/Controlleur
	mkdir -p build/Intelligence

compile: \
	compile_modele \
	compile_vue \
	compile_controlleur \
	compile_intelligence \
	compile_main \

check:$(patsubst %.cpp,%.o,$(wildcard Test/*.cpp))

Test/%.o:Test/%.cpp
	g++ $(CompilerFlag) $< -o $@
	./$@
	rm -f $@

compile_modele: $(patsubst %.cc,$(Build)%.o,$(wildcard Modele/*/*.cc))
compile_vue: $(patsubst %.cc,$(Build)%.o,$(wildcard Vue/*.cc))
compile_controlleur: $(patsubst %.cc,$(Build)%.o,$(wildcard Controlleur/*.cc))
compile_intelligence: $(patsubst %.cc,$(Build)%.o,$(wildcard Intelligence/*.cc))
compile_main: $(patsubst %.cpp,$(Build)%.o,main.cpp)

link: $(Executable)

clean:
	rm -f $(Executable)
	rm -fr $(Build)

$(Build)%.o:%.cpp
	g++ -c $(CompilerFlag) $< -o $@

$(Build)Modele/%.o:Modele/%.cc
	mkdir -p $(dir $@)
	g++ -c $(CompilerFlag) $< -o $@

$(Build)Controlleur/%.o:$(wildcard Controlleur/*.cc)
	g++ -c $(CompilerFlag) $< -o $@
$(Build)Vue/%.o:$(wildcard Vue/*.cc)
	g++ -c $(CompilerFlag) $< -o $@
$(Build)Intelligence/%.o:$(wildcard Intelligence/*.cc)
	g++ -c $(CompilerFlag) $< -o $@

$(Executable):
	g++ $(LinkerFlag) \
		$(wildcard build/*.o) \
		$(wildcard build/*/*.o) \
		$(wildcard build/*/*/*.o) -o $(Executable)
