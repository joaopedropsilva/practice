male(albert).
male(bob).
female(alice).

dances(alice).

parent(albert, bob).
parent(alice, bob).
parent(bob, carl).
parent(bob, charlie).

get_parent(C, P) :-
    parent(P, C).

related(C) :-
    parent(P, C).

what_grade(G) :-
    Grade is G - 5,
    format('Grade is ~w', [Grade]).

