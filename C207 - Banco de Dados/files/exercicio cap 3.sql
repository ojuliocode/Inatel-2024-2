drop database if exists locadora;
create database locadora;
use locadora;

set sql_safe_updates = false;

create table if not exists cliente (
	idCliente int auto_increment primary key not null,
    preNome varchar(15) not null,
    sobreNome varchar(25) not null
);


create table if not exists categoria (
	idCat int auto_increment primary key not null,
    nomeCat varchar(25) not null
);


create table if not exists filme (
	idFilme int auto_increment primary key not null,
    tiutlo varchar(45) not null,
    idCat int not null,
    foreign key (idCat) references categoria(idCat)
);

create table if not exists dvd (
	idDvd int auto_increment primary key not null,
    idCliente int,
    idFilme int not null,
    foreign key (idCliente) references cliente(idCliente),
    foreign key (idFilme) references filme(idFilme)
);

create table if not exists telefone (
	idTelefone int auto_increment primary key not null,
    numero varchar(11) not null,
    idCliente int,
    foreign key (idCliente) references cliente(idCliente)
);

create table if not exists ator (
	idAtor int auto_increment primary key not null,
    nomeAtor varchar(45) not null,
    dataNasc date not null
);

CREATE TABLE Ator_Estrela_Filme (
    idAtor INT,
    idFilme INT,
    PRIMARY KEY (idFilme, idAtor),
    FOREIGN KEY (idFilme) REFERENCES filme(idFilme),
    FOREIGN KEY (idAtor) REFERENCES ator(idAtor)
);