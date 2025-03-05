DROP DATABASE IF EXISTS carrera_caballos;
CREATE DATABASE carrera_caballos;
USE carrera_caballos;
CREATE TABLE partidas (
    id_partida INT AUTO_INCREMENT PRIMARY KEY,
    fecha DATE NOT NULL,
    limite_edad INT NOT NULL
);
CREATE TABLE jugadores (
    id_jugador INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL,
    edad INT NOT NULL,
    id_partida INT,
    FOREIGN KEY (id_partida) REFERENCES partidas(id_partida)
);
INSERT INTO partidas (fecha, limite_edad) VALUES
('2025-03-02', 18),
('2025-03-10', 21);

INSERT INTO jugadores (nombre, edad, id_partida) VALUES
('Juan', 20, 1),
('Pedro', 17, 1),
('Maria', 22, 2);

