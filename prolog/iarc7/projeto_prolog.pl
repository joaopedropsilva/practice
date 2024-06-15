aluno(joao, calculo).
aluno(maria, calculo).
aluno(joel, programacao).
aluno(joel, estrutura).
frequenta(joao, puc).
frequenta(maria, puc).
frequenta(joel, ufscar).
professor(carlos, calculo).
professor(ana_paula, estrutura).
professor(pedro, programacao).
funcionario(pedro, ufscar).
funcionario(ana_paula, puc).
funcionario(carlos, puc).

alunos_do_prof(X, A) :-
    professor(X, Materia),
    aluno(A, Materia).

associados_a_universidade(U, P) :-
    frequenta(P, U); funcionario(P, U).

