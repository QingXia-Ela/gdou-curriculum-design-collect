CREATE TABLE `web_course`.`user` (
  `UserId` varchar(36) UNIQUE NOT NULL,
  `name` varchar(45) UNIQUE NOT NULL,
  `password` varchar(45) NOT NULL,
  PRIMARY KEY (`UserId`)
) CHARSET=utf8;

CREATE TABLE `web_course`.`lastlogin` (
  `UserId` varchar(36) UNIQUE NOT NULL REFERENCES `web_course`.`user` (`UserId`),
  `lastLoginTime` datetime NOT NULL,
  PRIMARY KEY (`UserId`)
) CHARSET=utf8;

CREATE TABLE `web_course`.`captcha` (
  `idcaptcha` INT(11) UNIQUE NOT NULL AUTO_INCREMENT,
  `code` varchar(4) NOT NULL,
  `image` text NOT NULL,
  PRIMARY KEY (`idcaptcha`)
) CHARSET=utf8;