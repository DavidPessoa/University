num(z).
num(s(X)) :- num(X).

mais1(s(z),z).
mais1(s(A),s(B)) :- mais1(A,B).

soma(z,z,z).
soma(X,z,X).
soma(X,s(Y),s(Z)):- soma(X,Y,Z).

sub(X,z,X).
sub(s(X),s(Y),Z):- sub(X,Y,Z).

le(z,_).
le(s(X),s(Y)):-le(X,Y).

lt(z,s(Y)).
lt(s(X),s(Y)):-lt(X,Y). 

dobro(z,z).
dobro(s(s(X)),s(Y)):- dobro(X,Y).

mult(_,z,z).
mult(X,s(Y),Z):-
	mult(X,Y,W), 
	soma(X,W,Z).

div_int(z,_,z).
div_int(X,Y,s(Z)) :-
	sub(X,Y,W),
	div_int(W,Y,Z).

pot(z,_,z).
pot(s(z),_,s(z)).
pot(X,s(z),X).
pot(X,s(Y),Z):-
	pot(X,Y,W),
	soma(X,W,Z).


quadrado(X,Y):- mult(X,X,Y).

lista([]).
lista([_|L]):- lista(L).

membro(X,[X|_]).
membro(X,[_|L]):-membro(X,L).

prefixo([],_).
prefixo([H1|T1],[H1|T2]):- prefixo(T1,T2). 


sufixo(L, [_|L]).
sufixo(L, [H|T]):- sufixo(L, T).


catena([],L2,L2).
catena([H1|T1], L2, [H1|Tr]):- catena(T1,L2,Tr).


nrev([],[]).
nrev([H1|T1],L2):- 
	nrev(T1,Lw),
	catena(Lw,[H1],L2).


cortar([E|T],E,[E],T).
cortar([H|T], E, L1, L2):-
	cortar(T,E,Lr,L2),
	catena([H],Lr,L1).



partir([],E,[],[]).
partir([H|T],E,L1,L2):-
	partir(T,E,Lr,Lt),
	((H<E,
	catena([H],Lr,L1));
	H>=E,
	catena([H],Lt,L2)).


fact(z,s(z)).
fact(s(X),Y):- 
	fact(X,Z),
	mult(s(X),Z,Y).


divisivel(Y,Y).

divisivel(X,Y):- sub(X,Y,Z), divisivel(Z,Y).

leArray([H|T],Pos1,Cauda):- 
	H = Pos1, 
	Cauda = T.



avalia(P,X,Y):- leArray(P,H1,T1), 
	leArray(T1,H2,T2), 
	leArray(T2,H3,_), 
	H is (H1+H2*X +H3*X*X),
	Y is H.


derivada(P1,P2):- polinomio(P1,0,P2).

polinomio([],X,[]).
polinomio([H|T],X,L2):-  
	R is X+1,
	polinomio(T,R,Lt),
	D is H*(R-1),
	catena([D],Lt,L2).


misturar([],[],[]).
misturar([H1|T1],[H2|T2],L):- 
	misturar(T1,T2,L1),
	catena([H1,H2],L1,L).
