start(a).

final(a).
final(e).
final(f).

transition(a,0,d).
transition(a,1,b).
transition(b,0,f).
transition(b,1,c).
transition(c,0,c).
transition(c,1,c).
transition(d,0,a).
transition(d,1,e).
transition(e,0,f).
transition(e,1,c).
transition(f,0,f).
transition(f,1,c).

%Check is Q is start and see if Q with Xs leads to a final
accept(Xs):- start(Q),path(Q,Xs).
path(Q,[X|Xs]):-transition(Q,X,Qi),path(Qi,Xs).
path(Q,[]):-final(Q).
