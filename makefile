include .env

all: folder compile link

fresh: clean all

folder:
	echo $(SHELL)
ifeq ($(OS),Windows_NT)
	if not exist build ( mkdir "build" ) ;
	if not exist "build/Modele" mkdir "build/Modele" ;
	if not exist "build/Vue" mkdir "build/Vue" ;
	if not exist "build/Controlleur" mkdir "build/Controlleur" ;
	if not exist "build/Intelligence" mkdir "build/Intelligence" ;
else
	mkdir -p build
	mkdir -p build/Modele
	mkdir -p build/Vue
	mkdir -p build/Controlleur
	mkdir -p build/Intelligence
endif

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

compile_modele: $(patsubst %.cc,$(Build)/%.o,$(wildcard Modele/*/*.cc))
compile_vue: $(patsubst %.cc,$(Build)/%.o,$(wildcard Vue/*.cc))
compile_controlleur: $(patsubst %.cc,$(Build)/%.o,$(wildcard Controlleur/*.cc))
compile_intelligence: $(patsubst %.cc,$(Build)/%.o,$(wildcard Intelligence/*.cc))
compile_main: $(patsubst %.cpp,$(Build)/%.o,main.cpp)

link: $(Executable)

clean:
ifeq ($(OS),Windows_NT)
	if exist $(Executable).exe del /F /Q $(Executable).exe ;
	if exist $(Build) RD /S /Q $(Build) ;
else
	rm -f $(Executable)
	rm -fr $(Build)
endif

$(Build)/%.o:%.cpp
	g++ -c $(CompilerFlag) $< -o $@

$(Build)/Modele/%.o:Modele/%.cc
ifeq ($(OS),Windows_NT)
	if not exist "$(dir $@)" mkdir "$(dir $@)" ;
	g++ -c $(CompilerFlag) $< -o $@
else
	mkdir -p $(dir $@)
	g++ -c $(CompilerFlag) $< -o $@
endif

$(Build)/Controlleur/%.o:Controlleur/*.cc
	g++ -c $(CompilerFlag) $< -o $@
$(Build)/Vue/%.o:Vue/*.cc
	g++ -c $(CompilerFlag) $< -o $@
$(Build)/Intelligence/%.o:Intelligence/%.cc
	g++ -c $(CompilerFlag) $< -o $@

$(Executable):
	g++ $(LinkerFlag) \
		$(wildcard build/*.o) \
		$(wildcard build/*/*.o) \
		$(wildcard build/*/*/*.o) -o $(Executable)
