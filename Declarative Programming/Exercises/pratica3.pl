dict([]).
dict([VAL=KEY|L]-[L]).

ins(K,V,Din,Dout):- Dout is [K=V|Din]. 

get(K,V,[K=V|_]).
get(K,V,[H|T]):- get(K,V,T).

all(K,[]).
all(K,[K=_|T]):- all(K,T).




/*  [1=David, 2=Pedro, 3=Rute] */