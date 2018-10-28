t(1, isto(nao, e(um), termo(simples))).
t(2, pois(pois(pois,claro), que(nao), se, percebe(o(que), significa(isto)))).
t(3,aqui(simples)).


contem(T,X):-  functor(T,F,0), T = X.
contem(T,X):- (functor(T,F,A), A==1, arg(1,T,L),contem(L,X));	
			  (functor(T,F,A), A>1, lookup(T,X,A)). 
							


lookup(T,X,A):- (arg(A,T,L),A=A-1, A>0, lookup(L,X,A)). 
lookup(T,X,A):- (arg(A,T,L),contem(L,X)).  

queens(N,R):-
	length(R,N),  %serve para aloca o array R com o tamanho de N. 
	fd_domain(R,1,N),
	ok(R),
	fd_labeling(R).


ok([]).
ok([Ri|Rt]):-ok(Rt,Ri,1).

ok([],_,_).
ok([Rh|Rt],Ri,I) :- 
	L is I+1,
	ok(Rt,Ri,L),
	Rh #\= Ri, Ri #\= Rh+1, Ri #\= Rh-1,	
	fd_all_different(Rt).


mkq(N, Q) :-
 length(Q, N),
 q(Q, N).

q([], _).
q([Q|Qs], N) :-
 q1(1, N, Q),
 q(Qs, N).

q1(Q, N, Q) :- Q =< N.
q1(I, N, Q) :- I < N, I1 is I+1, q1(I1, N, Q).

rainhas(N,Q):-
	fd_domain(R,1,N),
	mkq(N,Q),
	fd_labeling(Q).

