CC = gcc -Wall 
YACC = bison -d -v
LEX = flex

ir : ir.tab.c lex.yy.c
	$(CC) $^ -g linkedlist.c tree.c tradutor.c -o $@ -lfl
	
ir.tab.c : ir.y
	$(YACC) $^

lex.yy.c : ir.lex
	$(LEX) $^

run : ir
	@./ir < test.txt

clean : 
	@$(RM) ir 
	@$(RM) linkedlist 	
	@$(RM) ir.tab.c ir.tab.h
	@$(RM) lex.yy.c
	@$(RM) ir.output
	