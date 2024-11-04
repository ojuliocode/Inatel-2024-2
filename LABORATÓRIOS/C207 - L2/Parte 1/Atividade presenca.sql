drop database if exists avengers;
create database avengers;
use avengers;

CREATE TABLE Heroi (
    idHeroi INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(45) NOT NULL,
    endereco VARCHAR(45),
    nascimento DATE,
    habilidade VARCHAR(45),
    sexo CHAR,
    email VARCHAR(45)
);

CREATE TABLE Vilao(
	idVilao INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(45) NOT NULL,
    num_crimes INT NOT NULL
);

CREATE TABLE Missao (
	idMissao INT AUTO_INCREMENT PRIMARY KEY,
    data DATE NOT NULL,
    nome VARCHAR(45) NOT NULL,
    local VARCHAR(45),
    duracao INT,
    idVilao INT,
    FOREIGN KEY (idVilao) REFERENCES Vilao(idVilao)
    
);

CREATE TABLE Heroi_has_Missao (
    idHeroi INT,
    idMissao INT,
    PRIMARY KEY (idHeroi, idMissao),
    FOREIGN KEY (idHeroi) REFERENCES Heroi(idHeroi),
    FOREIGN KEY (idMissao) REFERENCES Missao(idMissao)
);

INSERT INTO Heroi (nome, endereco, nascimento, habilidade, sexo, email) VALUES ('Iron Man', 'Stark Tower', '1970-05-29', 'Tecnologia', 'M', 'ironman@avengers.com');
INSERT INTO Heroi (nome, endereco, nascimento, habilidade, sexo, email) VALUES ('Captain America', 'Brooklyn', '1918-07-04', 'Força', 'M', 'cap@avengers.com');
INSERT INTO Heroi (nome, endereco, nascimento, habilidade, sexo, email) VALUES ('Black Widow', 'Moscou', '1984-11-22', 'Espionagem', 'F', 'widow@avengers.com');
INSERT INTO Heroi (nome, endereco, nascimento, habilidade, sexo, email) VALUES ('Thor', 'Asgard', '1000-01-01', 'Deus do Trovão', 'M', 'thor@avengers.com');
INSERT INTO Heroi (nome, endereco, nascimento, habilidade, sexo, email) VALUES ('Hulk', 'Desconhecido', '1969-12-18', 'Força', 'M', 'hulk@avengers.com');

INSERT INTO Vilao (nome, num_crimes) VALUES('Loki', 50);
INSERT INTO Vilao (nome, num_crimes) VALUES('Thanos', 100);
INSERT INTO Vilao (nome, num_crimes) VALUES('Ultron', 75);
INSERT INTO Vilao (nome, num_crimes) VALUES('Red Skull', 60);
INSERT INTO Vilao (nome, num_crimes) VALUES('Hela', 40);


INSERT INTO Missao (data, nome, local, duracao, idVilao) VALUES ('2023-01-01', 'Batalha de Nova York', 'Nova York', 5, 1);
 INSERT INTO Missao (data, nome, local, duracao, idVilao) VALUES ('2023-02-01', 'Guerra Infinita', 'Wakanda', 10, 2);
 INSERT INTO Missao (data, nome, local, duracao, idVilao) VALUES ('2023-03-01', 'Era de Ultron', 'Sokovia', 7, 3);
INSERT INTO Missao (data, nome, local, duracao, idVilao) VALUES('2023-04-01', 'Primeira Missão', 'Berlim', 3, 4);
INSERT INTO Missao (data, nome, local, duracao, idVilao) VALUES('2023-05-01', 'Ragnarok', 'Asgard', 8, 5);

INSERT INTO Heroi_has_Missao() VALUES(1,1);
INSERT INTO Heroi_has_Missao() VALUES(1,2);
INSERT INTO Heroi_has_Missao() VALUES(1,3);

INSERT INTO Heroi_has_Missao() VALUES(2,2);
INSERT INTO Heroi_has_Missao() VALUES(2,3);
INSERT INTO Heroi_has_Missao() VALUES(2,4);

INSERT INTO Heroi_has_Missao() VALUES(3,3);
INSERT INTO Heroi_has_Missao() VALUES(3,4);
INSERT INTO Heroi_has_Missao() VALUES(3,5);

INSERT INTO Heroi_has_Missao() VALUES(4,1);
INSERT INTO Heroi_has_Missao() VALUES(4,2);
INSERT INTO Heroi_has_Missao() VALUES(4,4);

INSERT INTO Heroi_has_Missao() VALUES(5,5);
INSERT INTO Heroi_has_Missao() VALUES(5,4);
INSERT INTO Heroi_has_Missao() VALUES(5,1);

SELECT h.nome AS Nome_Herói,
       m.nome AS Nome_Missão,
       v.nome AS Nome_Vilão
FROM Heroi h
JOIN Heroi_has_Missao hm ON h.idHeroi = hm.idHeroi
JOIN Missao m ON hm.idMissao = m.idMissao
JOIN Vilao v ON m.idVilao = v.idVilao
ORDER BY h.nome;

SELECT h.nome AS Nome_Herói,
       SUM(m.duracao) AS Duracao_Total,
       COUNT(*) AS Quantidade_Missoes
FROM Heroi h
JOIN Heroi_has_Missao hm ON h.idHeroi = hm.idHeroi
JOIN Missao m ON hm.idMissao = m.idMissao
GROUP BY h.nome
ORDER BY h.nome;

SELECT m.nome AS Nome_Missão,
       h.nome AS Nome_Herói,
       v.num_crimes AS Número_Crimes
FROM Missao m
JOIN Heroi_has_Missao hm ON m.idMissao = hm.idMissao
JOIN Heroi h ON hm.idHeroi = h.idHeroi
JOIN Vilao v ON m.idVilao = v.idVilao
ORDER BY m.nome;