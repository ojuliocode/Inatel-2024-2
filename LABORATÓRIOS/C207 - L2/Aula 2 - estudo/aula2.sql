drop database if exists empresa;
create database empresa;
use empresa;
set sql_safe_updates = 0;

create table if not exists pessoa(
	id int not null auto_increment primary key,
    nome varchar(45),
    endereco varchar(45),
    cargo varchar(45),
    salario int
);

insert into pessoa () values (default, 'julio', 'rua mariquinha', 'engenheiro', 20000);
insert into pessoa () values (default, 'ana', 'rua mariquinha', 'professora', 1200);
insert into pessoa () values (default, 'titia', 'rua mariquinha', 'professora', 1250);
insert into pessoa (nome) values ('ana castela');
insert into pessoa (nome, endereco) values ('Brian', 'LA');
insert into pessoa () values (default, 'toreto', 'LA', 'dirigidor', 250000);
update pessoa set endereco = 'nao eh mais mariquinha' where id = '1';

select max(salario) from pessoa;

select distinct endereco from pessoa;
# delete from pessoa where id = '2';

