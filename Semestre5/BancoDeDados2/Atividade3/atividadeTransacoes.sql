--Igor Radtke
--Renan Carlos Loewenstein

--criar a tabela teste
CREATE TABLE teste (id integer primary key, value char(500));

--adicionar 10 linhas na tabela
INSERT INTO teste(id, value) values

    (0,'zero'),
    (1,'um'),
    (2,'dois'),
    (3,'tres'),
    (4,'quatro'),
    (5,'cinco'),
    (6,'seis'),
    (7,'sete'),
    (8,'oito'),
    (9,'nove');

--verificar o tamanho da tabela
SELECT pg_size_pretty( pg_total_relation_size('teste'));

--insira uma tupla com id = 10  em uma transação A (sem comitar)
--TRANSAÇÃO A (terminal A)
BEGIN;
    insert into teste values (10, 'dez');

--insira uma tupla com id = 10  em uma transação B (sem comitar)
--TRANSAÇÃO B (terminal B)
/*
BEGIN;
    insert into teste values (10, 'dez');
*/ 


--Explique o que aconteceu já que os dados são operados em cópias diferentes?

            /*Quando o comando INSERT for feito na TRANSAÇÃO A sem comitar
        ele não permite que a TRANSAÇÃO B seja feita até a TRANSAÇÃO A
        for efetuada. Somente depois de comitar a TRANSAÇÃO A que a 
        TRANSAÇÃO B será liberada para ser feita.

            Se o INSERT da TRANSAÇÃO A for feito, o insert da TRANSAÇÃO B
        não será feito, pois terão IDs iguais e são primary keys.