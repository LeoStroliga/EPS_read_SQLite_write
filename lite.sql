--CREATE TABLE event (
--   id INTEGER PRIMARY KEY,
--   latitude REAL,
--   longitude REAL,
--  time TEXT
--);

--INSERT INTO event (latitude, longitude, time)
--VALUES(43.510852,16.473664, '17:50,3/6/2025');

--VALUES(43.510852,16.473664, '2006-01-02T15:04:05Z07:00');

--DELETE FROM event WHERE id=1;
INSERT INTO event (latitude, longitude, time)
VALUES(43.510852,16.473664, '2006-01-02T15:04:05Z07:00');

SELECT * FROM event;
