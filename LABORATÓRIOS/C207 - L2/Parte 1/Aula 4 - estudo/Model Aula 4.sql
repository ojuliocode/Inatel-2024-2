-- MySQL Workbench Forward Engineering

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`Varinha`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Varinha` (
  `chave_primaria` INT NOT NULL,
  `nome` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`chave_primaria`));

-- -----------------------------------------------------
-- Table `mydb`.`Bruxo`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Bruxo` (
  `chave_primaria` INT NOT NULL,
  `nome` VARCHAR(45) NOT NULL,
  `Varinha_chave_primaria` INT NOT NULL,
  PRIMARY KEY (`chave_primaria`),
  UNIQUE INDEX `chave_primaria_UNIQUE` (`chave_primaria` ASC) VISIBLE,
  INDEX `fk_Bruxo_Varinha_idx` (`Varinha_chave_primaria` ASC) VISIBLE,
  CONSTRAINT `fk_Bruxo_Varinha`
    FOREIGN KEY (`Varinha_chave_primaria`)
    REFERENCES `mydb`.`Varinha` (`chave_primaria`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);
-- -----------------------------------------------------
-- Table `mydb`.`Matéria`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Matéria` (
  `chave_primaria` INT NOT NULL,
  `nome` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`chave_primaria`));
-- -----------------------------------------------------
-- Table `mydb`.`Bruxo_has_Matéria`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Bruxo_has_Matéria` (
  `Bruxo_chave_primaria` INT NOT NULL,
  `Matéria_chave_primaria` INT NOT NULL,
  PRIMARY KEY (`Bruxo_chave_primaria`, `Matéria_chave_primaria`),
  INDEX `fk_Bruxo_has_Matéria_Matéria1_idx` (`Matéria_chave_primaria` ASC) VISIBLE,
  INDEX `fk_Bruxo_has_Matéria_Bruxo1_idx` (`Bruxo_chave_primaria` ASC) VISIBLE,
  CONSTRAINT `fk_Bruxo_has_Matéria_Bruxo1`
    FOREIGN KEY (`Bruxo_chave_primaria`)
    REFERENCES `mydb`.`Bruxo` (`chave_primaria`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Bruxo_has_Matéria_Matéria1`
    FOREIGN KEY (`Matéria_chave_primaria`)
    REFERENCES `mydb`.`Matéria` (`chave_primaria`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);
