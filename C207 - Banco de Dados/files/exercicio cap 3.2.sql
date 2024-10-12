drop database if exists banco;
create database banco;
use banco;

set sql_safe_updates = false;

create table if not exists correntista (
	codigo_cliente int not null primary key,
    nome varchar(45),
    telefone varchar(45)
);

create table if not exists conta_corrente (
	codigo int primary key,
    saldo float,
    codigo_cliente int,
    foreign key (codigo_cliente) references correntista(codigo_cliente)
);

