procNot: entryPoint.o ProcessReader.o ProcessAnalyzer.o ProcessState.o
	g++ entryPoint.o ProcessReader.o ProcessAnalyzer.o ProcessState.o -o procNot
	
entryPoint.o: entryPoint.cpp ProcessInfo.h ProcessState.h ProcessReader.h ProcessAnalyzer.h
	g++ -c entryPoint.cpp

ProcessReader.o:  ProcessReader.cpp ProcessReader.h ProcessInfo.h ProcessState.h
	g++ -c ProcessReader.cpp

ProcessAnalyzer.o: ProcessAnalyzer.cpp ProcessAnalyzer.h ProcessInfo.h ProcessState.h
	g++ -c ProcessAnalyzer.cpp

ProcessState.o: ProcessState.cpp ProcessState.h
	g++ -c ProcessState.cpp