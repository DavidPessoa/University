CC = gcc -Wall 
YACC = bison -d -v
LEX = flex

tacl : tacl.tab.c lex.yy.c
	$(CC) $^ -g tree.c compiler.c -o $@ -lfl
	
tacl.tab.c : tacl.y
	$(YACC) $^

lex.yy.c : tacl.lex
	$(LEX) $^

run : tacl
	@./tacl < test.txt

clean : 
	@$(RM) tacl 
	@$(RM) tacl.tab.c tacl.tab.h
	@$(RM) lex.yy.c
	@$(RM) tacl.output
	