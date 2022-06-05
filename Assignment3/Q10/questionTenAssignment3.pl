every-other([],[]).
every-other([X],[X]).
every-other([X, _ | A], [X | B]):-
every-other(A,B).
