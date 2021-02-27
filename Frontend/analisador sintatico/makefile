a.out: parsetest.o tiger.tab.o lex.yy.o errormsg.o util.o absyn.o prabsyn.o parse.o symbol.o table.o
	cc -g parsetest.o tiger.tab.o lex.yy.o errormsg.o util.o absyn.o prabsyn.o parse.o symbol.o table.o

parsetest.o: parsetest.c parse.h prabsyn.h
	gcc -g -c parsetest.c

tiger.tab.o: tiger.tab.c
	gcc -g -c tiger.tab.c

tiger.tab.c: tiger.y
	bison -dv tiger.y 

errormsg.o: errormsg.c errormsg.h util.h
	gcc -g -c errormsg.c

lex.yy.o: lex.yy.c errormsg.h util.h symbol.h absyn.h 
	gcc -g -c lex.yy.c

lex.yy.c: tiger.lex
	flex tiger.lex

util.o: util.c util.h
	gcc -g -c util.c

parse.o: parse.c parse.h absyn.h errormsg.h util.h
	gcc -g -c parse.c

symbol.o: symbol.c symbol.h util.h table.h
	gcc -g -c symbol.c

table.o: table.c table.h util.h
	gcc -g -c table.c

absyn.o: absyn.c util.h symbol.h absyn.h
	gcc -g -c absyn.c

prabsyn.o: prabsyn.c prabsyn.h symbol.h util.h absyn.h
	gcc -g -c prabsyn.c

clean: 
	rm -f a.out parsetest.o tiger.tab.o lex.yy.o errormsg.o util.o parse.o symbol.o table.o absyn.o prabsyn.o env.o types.o semant.o analise_semantica.o codigo_intermediario.o tiger.output tiger.tab.c tiger.tab.h
