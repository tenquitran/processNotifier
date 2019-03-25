processNotifier: entryPoint.o ProcessReader.o ProcessAnalyzer.o
	g++ entryPoint.o ProcessReader.o ProcessAnalyzer.o -o processNotifier
	
entryPoint.o: entryPoint.cpp ProcessInfo.h ProcessReader.h ProcessAnalyzer.h
	g++ -c entryPoint.cpp

ProcessReader.o: ProcessReader.cpp ProcessReader.h ProcessInfo.h
	g++ -c ProcessReader.cpp

ProcessAnalyzer.o: ProcessAnalyzer.cpp ProcessAnalyzer.h ProcessInfo.h
	g++ -c ProcessAnalyzer.cpp