--
-- File generated with SQLiteStudio v3.1.0 on Mo. Nov. 28 17:18:55 2016
--
-- Text encoding used: UTF-8
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: Ware
DROP TABLE IF EXISTS Ware;

CREATE TABLE Ware (
    ID           INTEGER NOT NULL
                         PRIMARY KEY AUTOINCREMENT,
    Name         TEXT    NOT NULL,
    Preis_pro_kg DECIMAL,
    Preis_pro_St DECIMAL,
    Kommentar    TEXT,
    Warengruppe  TEXT    REFERENCES Warengruppe (Name) 
                         NOT NULL,
    Menge_in_kg  DECIMAL,
    Menge_in_St  DECIMAL
);


-- Table: Warengruppe
DROP TABLE IF EXISTS Warengruppe;

CREATE TABLE Warengruppe (
    Name      TEXT NOT NULL
                   PRIMARY KEY
                   UNIQUE,
    Kommentar TEXT
);

-- Table: Empfaenger
DROP TABLE IF EXISTS Empfaenger;

CREATE TABLE Empfaenger (
    Name         TEXT NOT NULL
                      PRIMARY KEY
                      UNIQUE,
    Adresse      TEXT,
    Emailadresse TEXT    NOT NULL
);


-- Table: Absender
DROP TABLE IF EXISTS Absender;

CREATE TABLE Absender (
    Name         TEXT NOT NULL
                      PRIMARY KEY
                      UNIQUE,
    Adresse      TEXT,
    Emailadresse TEXT    NOT NULL
);

-- Table: InfoBestellung
DROP TABLE IF EXISTS InfoBestellung;

CREATE TABLE InfoBestellung (
    ID        INTEGER PRIMARY KEY AUTOINCREMENT,
    Zieldatum STRING  NOT NULL,
    Zielzeit  STRING,
    Kommentar TEXT
);

INSERT INTO Empfaenger (Name, Emailadresse, Adresse) VALUES ("unbekannt", "unbekannt", "unbekannt");
INSERT INTO Absender (Name, Emailadresse, Adresse) VALUES ("unbekannt", "unbekannt", "unbekannt");
INSERT INTO InfoBestellung (Zieldatum, Zielzeit, Kommentar) VALUES ("jjjj.mm.dd", "", "");

COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
