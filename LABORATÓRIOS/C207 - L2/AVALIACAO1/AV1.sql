DROP DATABASE IF EXISTS AV1;
CREATE DATABASE AV1;
USE AV1;

#COMANDO PARA DESATIVAR O SAFE MODE
SET SQL_SAFE_UPDATES = 0;

CREATE TABLE IF NOT EXISTS Personagem (
    id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    nome VARCHAR(50) NOT NULL,
    linhagem VARCHAR(50) NOT NULL,
    classe VARCHAR(50) NOT NULL,
    arma VARCHAR(50) NOT NULL,
    proficiencia VARCHAR(50) NOT NULL,
    idade INT NOT NULL
);

# Responda aqui a letra A

insert into Personagem () values (default, 'Grog', 'golias', 'bárbaro', 'espada', 'atletismo', 40);
insert into Personagem () values (default, 'Keyleth', 'meio-elfo', 'druida', 'cajado', 'natureza', 23);
insert into Personagem () values (default, 'Pike', 'gnomo', 'clérigo', 'martelo', 'religião', 30);
insert into Personagem () values (default, 'Taryon', 'humano', 'artífice', 'pistola', 'tecnologia', 29);
insert into Personagem () values (default, 'Scanlan', 'gnomo', 'bardo', 'flauta', 'atuação', 66);
insert into Personagem () values (default, 'Tiberius', 'draconato', 'feiticeiro', 'cajado', 'arcanismo', 28);

# Responda aqui a letra B

update Personagem set idade = 24 where nome = 'Keyleth';

# Responda aqui a letra C

select * from Personagem where arma = 'cajado';

# Responda aqui a letra D

delete from Personagem where classe = 'artífice';

# Responda aqui a letra E

select * from Personagem where linhagem = 'gnomo';

# Responda aqui a letra F

select max(idade) from Personagem;

# Responda aqui a letra G

update Personagem set proficiencia = 'natação' where nome = 'Grog' or nome = 'Pike';

# Responda aqui a letra H
# Se considerar a busca como sendo com 6 letras, vamos ter Ti_ _ _ _ (Ti seguido de 4 espaços, pra somar 6 letras). Nesse caso ele não retorna nada pois o Tiberius tem 8 letras

select nome from Personagem where nome like'Ti____';

# Responda aqui a letra I

select count(*) from Personagem where idade >= 30;
