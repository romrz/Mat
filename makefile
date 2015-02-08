
SRC = src/
BIN = bin/
TEST = tests/

default: lib

build: move-headers Fraction Real Matrix Expression Workspace

lib: build
	ar -rcs Mat/libmat.a $(BIN)workspace/*.o $(BIN)workspace/expression/*.o $(BIN)workspace/matrix/*.o $(BIN)workspace/number/*.o

Fraction: $(SRC)workspace/number/Fraction.cpp
	g++ -c -std=c++11 -I"Mat/" $(SRC)workspace/number/Fraction.cpp -o $(BIN)workspace/number/Fraction.o

Real: $(SRC)workspace/number/Real.cpp
	g++ -c -std=c++11 -I"Mat/" $(SRC)workspace/number/Real.cpp -o $(BIN)workspace/number/Real.o

Matrix: $(SRC)workspace/matrix/Matrix.cpp
	g++ -c -std=c++11 -I"Mat/" $(SRC)workspace/matrix/Matrix.cpp -o $(BIN)workspace/matrix/Matrix.o

Expression: $(SRC)workspace/expression/Expression.cpp
	g++ -c -std=c++11 -I"Mat/" $(SRC)workspace/expression/Expression.cpp -o $(BIN)workspace/expression/Expression.o

Workspace: $(SRC)workspace/Workspace.cpp
	g++ -c -std=c++11 -I"Mat/" $(SRC)workspace/Workspace.cpp -o $(BIN)workspace/Workspace.o

move-headers:
	cp $(SRC)workspace/*.h $(SRC)workspace/number/*.h $(SRC)workspace/matrix/*.h $(SRC)workspace/expression/*.h Mat/

clear:
	rm $(BIN)workspace/*.o $(BIN)workspace/expression/*.o $(BIN)workspace/matrix/*.o $(BIN)workspace/number/*.o $(TEST)*.out

build-tests:
	g++ $(TEST)FractionTest.cpp -o $(TEST)FractionTest.out -std=c++11 Mat/libmat.a
	g++ $(TEST)RealTest.cpp -o $(TEST)RealTest.out -std=c++11 Mat/libmat.a
	g++ $(TEST)ComplexTest.cpp -o $(TEST)ComplexTest.out -std=c++11 Mat/libmat.a
	g++ $(TEST)MatrixTest.cpp -o $(TEST)MatrixTest.out -std=c++11 Mat/libmat.a
	g++ $(TEST)WorkspaceTest.cpp -o $(TEST)WorkspaceTest.out -std=c++11 Mat/libmat.a
	g++ $(TEST)MatTest.cpp -o $(TEST)MatTest.out -std=c++11 Mat/libmat.a
