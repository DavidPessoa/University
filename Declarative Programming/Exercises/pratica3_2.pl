dict([VAL=KEY|_]).

ins(K,V, Din, Dout):- append(Din,[K=V],Dout).


del(K,Din,Dout):-member(K=L,Din), delete(Din,K=L,Dout).

get(K,V,[K=V|_]).
get(K,V,[R=L|T]):- get(K,V,T). 

all1(K,[_|[]]).
all1(K,[K=_|T]):- all1(K,T). 

/*  [1=David, 2=Pedro, 3=Rute] */