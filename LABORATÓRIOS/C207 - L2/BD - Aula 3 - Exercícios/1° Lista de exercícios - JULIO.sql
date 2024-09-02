drop database if exists aula3;
create database aula3;
use aula3;
set sql_safe_updates = 0;

create table if not exists pessoa(
	id int not null auto_increment primary key,
    nome varchar(45),
    endereco varchar(45),
    cargo varchar(45)
);

# Questao 1:
# a)

insert into pessoa () values (default, "Ron Weasley", "Rua dos Alfaneiros", "Bruxo");
insert into pessoa (nome, endereco) values ("Harry Potter", "Rua dos Alfaneiros");
insert into pessoa () values (default, "Hermione", "Rua 15", "Bruxo");

# b)

select nome from pessoa;

# c) 

update pessoa set endereco = "Rua 14" where id = '1';

# d)

delete from pessoa where id = '3';

# Questao 2:

create table if not exists empresa(
	matricula int not null auto_increment primary key,
    nome varchar(45),
    cpf varchar(45),
    cargo varchar(45),
    nProjetos int
);

# a)

insert into empresa () values (default, "Junior", "000.000.000-00", "GP", 2);
insert into empresa () values (default, "Maria", "111.111.111-11", "Desenvolvedor", 3);
insert into empresa () values (default, "Carlos", "222.222.222-22", "Tester", 4);
insert into empresa () values (default, "Julia", "333.333.333-33", "Desenvolvedor", 5);

# b) 

select count(*) from empresa where nProjetos >= 4;

# c)

select avg(nProjetos) from empresa where cargo != "GP";

# d)

select distinct cargo from empresa;

# e)

select nome, cpf, nProjetos from empresa where cargo = "Desenvolvedor";

 # Questão 3:
 
 create table if not exists aluno (
    nome varchar(45),
	matricula int,
    endereco varchar(45),
    ano_nasc int,
    curso varchar(45)
 );
 
 # a)
 # A matricula, pois esta provavelmente não irá se repetir (não existem dois alunos com a mesma matrícula)
 
 # b)
 insert into aluno () values ("Carlos" , '333', "Rua 0", "2003", "geb");
 insert into aluno (nome, matricula, endereco, ano_nasc, curso) values ("Xanaina", "123", "Rua 1", "1998", "geb");
 insert into aluno (nome, endereco, ano_nasc, curso) values ("Luca", "Rua 2", "2004", "ges");
 insert into aluno () values ("Paula", 333, "Rua 3", 2000, 'gec');
 select * from aluno;

# Questão 4:
# a) 

insert into aluno () values ('Pedro', 225, 'Rua 25', 1999, 'gea');
insert into aluno () values ('Jander', 109, 'Rua 10', 2000, 'ges');
insert into aluno () values ('Laura', 342, 'Rua 3', 2002, 'gec');

# b) 

select nome, matricula, curso from aluno where nome like'Jan____%';
 
 # c)
 
 select nome, curso from aluno where nome like'L%A';
 
 # d) 
 
select nome, ano_nasc, curso from aluno where ano_nasc <= 2000;
 
 # e)
 
 select * from aluno limit 4;
 
 # f) 
 
 update aluno set endereco = "republica" where curso = 'ges';
 select * from aluno;
 
 # g)
 
 delete from aluno where curso='ges';
 select * from aluno;
 
 















