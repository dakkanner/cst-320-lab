COPTS=-Wall -g -c  -O0 -std=c++0x -Wno-reorder
OBJS=main.o \
	 langlex.o \
	 cSymbolTable.o \
	 cSymbol.o \
	 langparse.o \
	 cBlockNode.o \
	 cPrintNode.o \
	 cDeclsNode.o \
	 cStmtsNode.o \
	 cIntExpr.o \
	 cFloatExpr.o \
	 cBinaryExpr.o \
	 cVarNode.o \
	 cArraySpec.o \
	 cVarRef.o \
	 cVarPart.o \
	 cArrayVal.o \
	 cScanNode.o \
	 cIfNode.o \
	 cReturnNode.o \
	 cWhileNode.o \
	 cAssignmentNode.o \
	 cStructDecl.o \
	 cParamNode.o \
	 cParamSpec.o \
	 cParamsNode.o \
	 cParamsSpec.o \
	 cFuncPrefix.o \
	 cFuncHeader.o \
	 cFuncDecl.o \
	 cFuncCall.o

all: lang

clean:
	rm -f $(OBJS)
	rm -f langlex.c
	rm -f langparse.c
	rm -f langparse.h
	rm -f lang
	rm -f out

.cpp.o:
	g++ $(COPTS) $? -o $@

.c.o:
	g++ $(COPTS) $? -o $@

main.o: main.cpp langparse.c langlex.c 
	g++ $(COPTS) main.cpp -o $@

langlex.c: lang.l langparse.c
	flex -o langlex.c lang.l

langlex.o: langlex.c langparse.c
	g++ $(COPTS) -Wno-sign-compare langlex.c -o $@
	
langparse.c: lang.y
	bison --defines=langparse.h lang.y -o langparse.c

lang: $(OBJS)
	g++ $(OBJS) -o lang

