num(z).
num(s(X)):-num(X).

mais(z,s(z)).
mais(s(A),s(B)):-mais(A,B).


soma(z,B,B).
soma(s(A),B,s(C)):-soma(A,B,C).


sub(X,z,X).	
sub(s(A),s(B),C):- sub(A,B,C).


lt(z,s(X)).
lt(s(A),s(B)):-lt(A,B).

le(z,_).
le(s(A),s(B)):-le(A,B).


dobro(z,z).
dobro(s(X),s(s(Y))):-dobro(X,Y).


mult(s(z),Y,Y).
mult(s(X),Y,Z):- mult(X,Y,T), soma(Y,T,Z).
/*
div(X,z,z).
div(X,s(Y),T):-div(X,Y,T), sub(X,Y,T).  falta aqui qq coisa */

pot(X,s(z),X).
pot(X,s(Y),Z):-pot(X,Y,T), mult(X,T,Z).

	
quadrado(X,Y):-mult(X,X,Y).


lista([]).
lista([_|L]):-lista(L).

membro(X, [X|_]).
membro(X, [_|L]):-membro(X,L).

prefixo([],_).
prefixo([X|A],[X|B]):- prefixo(A,B).

sufixo(A,A).
sufixo(A, [_|B]):- sufixo(A,B).

sublista(S,L):- prefixo(P,L), sufixo(S,P).

catena([],L,L).
catena([X|Xs], L, [X|Y]):- catena(Xs, L, Y).

nrev([], []).
nrev([X|A], B):-
	nrev(A, AR),
	catena(AR, [X], B).


rev(L,R):- rev(L,[],R).
rev([],R,R).
rev([A|B], X, R):- rev(B, [A|X], R).


compr([], z).
compr([_|T], s(X)):- compr(T,X).

sel(E, [E|L], L).
sel(E, [X|L], [X|M]):- sel(E, L, M).


cortar([E|T],E,[],[E|T]).
cortar([H|T],E, [H|T1], L2):- cortar(T,E,T1,L2).

partir([],E,[],[]).
partir([H|T],E,[H|T1],L2):- partir(T,E,T1,L2), H < E.
partir([H|T],E,L1, [H|T2]):- partir(T,E,L1,T2), H >= E.


misturar([],Tr,Tr).
misturar(Tr,[],Tr).
misturar([H1|T1],[H2|T2],[H1,H2|T]):- misturar(T1,T2,T).