-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Looking for crime scene reports for that street in reported date
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';

-- Looking for clues in the interviews
SELECT name, transcript
FROM interviews
WHERE month = 7 AND day = 28;

-- Folowing ruth clue
SELECT activity, license_plate
FROM bakery_security_logs
WHERE month = 7 AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 25;

-- Following Eugene clue
SELECT account_number, amount
FROM atm_transactions
WHERE month = 7 AND day = 28 AND year = 2023
AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- Following Raymond clue
ALTER TABLE phone_calls
ADD caller_name text;

ALTER TABLE phone_calls
ADD receiver_name text;

UPDATE phone_calls
SET caller_name = people.name
FROM people
WHERE phone_calls.caller = people.phone_number;

UPDATE phone_calls
SET receiver_name = people.name
FROM people
WHERE phone_calls.receiver = people.phone_number;

SELECT caller, caller_name, receiver, receiver_name FROM phone_calls
WHERE year = 2023
AND month = 7
AND day = 28
AND duration <60;

SELECT id, hour, minute, origin_airport_id, destination_airport_id
FROM flights
WHERE year = 2023
AND month = 7
AND day = 29
ORDER BY hour ASC
LIMIT 1;

UPDATE flights
SET origin_airport_id = airports.city
FROM airports
WHERE flights.origin_airport_id = airports.id;

UPDATE flights
SET destination_airport_id = airports.city
FROM airports
WHERE flights.destination_airport_id = airports.id;

SELECT flights.destination_airport_id, name, phone_number, license_plate FROM people
JOIN flights ON flights.id = passengers.flight_id
WHERE flights.id = 36
ORDER BY flights.hour ASC;


