CREATE TABLE cars (
    Serial INT PRIMARY KEY,
    Brand VARCHAR(100),
    Model VARCHAR(100),
    Rent INT,
    Available BOOLEAN
);

INSERT INTO cars (Serial, Brand, Model, Rent, Available) VALUES (123, 'Honda', 'Civic', 60, true);
INSERT INTO cars (Serial, Brand, Model, Rent, Available) VALUES (223, 'Maruti', 'Swift', 50, true);
INSERT INTO cars (Serial, Brand, Model, Rent, Available) VALUES (323, 'Honda', 'Amaze', 80, true);
INSERT INTO cars (Serial, Brand, Model, Rent, Available) VALUES (423, 'Hyundai', 'I20', 60, true);
INSERT INTO cars (Serial, Brand, Model, Rent, Available) VALUES (523, 'Tata', 'Nexon', 60, true);
INSERT INTO cars (Serial, Brand, Model, Rent, Available) VALUES (623, 'Toyota', 'Yaris', 50, true);

SELECT Available FROM cars WHERE Serial = 123;

UPDATE cars SET Available = false WHERE Serial = 123;

SELECT * FROM cars;