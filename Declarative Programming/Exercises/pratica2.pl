isort(L1,Item):- isort(L1,Item,L).

isort([],I,L).  
isort([X|Xs],I,[X|T]):- I>X, isort(Xs,I,T).
isort([X|Xs],I,[I,X|Xs]):- I=<X. 

randomizer(0,K,[]).
randomizer(N,K, [H|T]):- R is N-1, random(0,K,H), randomizer(R,K,T).
