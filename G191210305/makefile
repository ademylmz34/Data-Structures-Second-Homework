all: compile run

compile:
	g++ -I ./include/ -o ./lib/Queue.o -c ./src/Queue.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Reader.o -c ./src/Reader.cpp
	g++ -I ./include/ -o ./lib/Split.o -c ./src/Split.cpp
	g++ -I ./include/ -o ./lib/TreeNode.o -c ./src/TreeNode.cpp
	g++ -I ./include/ -o ./lib/AvlTree.o -c ./src/AvlTree.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Queue.o ./lib/Node.o ./lib/Reader.o ./lib/Split.o ./lib/TreeNode.o ./lib/AvlTree.o  ./src/Test.cpp
	
run:
	./bin/Test