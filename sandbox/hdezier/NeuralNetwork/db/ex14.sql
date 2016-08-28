BEGIN;

--Add a dead column to person that's like the one in pet.
ALTER TABLE person
ADD COLUMN dead INTEGER;
--Add a phone_number column to person.
ALTER TABLE person
ADD COLUMN phone_number VARCHAR(15);
--Add a salary column to person that is float.
ALTER TABLE person
ADD COLUMN salary FLOAT;
--Add a dob column to both person and pet that is a DATETIME.
ALTER TABLE person
ADD COLUMN dob DATETIME;
ALTER TABLE pet
ADD COLUMN dob DATETIME;
--Add a purchased_on column to person_pet of type DATETIME.
ALTER TABLE person_pet
ADD COLUMN purchased_on DATETIME;
--Add a parent to pet column that's an INTEGER and holds the id for this pet's parent.
ALTER TABLE pet
ADD COLUMN parent INTEGER;
-- Update the existing database records with the new column data using UPDATE statements. Don't forget about the purchased_on column in person_pet relation table to indicate when that person bought the pet.
--Add 4 more people and 5 more pets and assign their ownership and what pet's are parents. On this last part remember that you get the id of the parent, then set it in the parent column.
INSERT INTO person (id, first_name, last_name, age, dead, phone_number, dob)
	VALUES(0, 'aaa', 'bbb', 15, 0, '0630302937', '2012-06-18 10:34:09');
INSERT INTO person (id, first_name, last_name, age, dead, phone_number, dob)
	VALUES(1, 'aaa0', 'bbb', 15, 0, '0630302937', '1012-06-18 10:34:09');
INSERT INTO person (id, first_name, last_name, age, dead, phone_number, dob)
	VALUES(2, 'aaa5', 'bbb', 15, 0, '0630302937', '1995-06-18 10:34:09');
INSERT INTO person (id, first_name, last_name, age, dead, phone_number, dob)
	VALUES(3, 'aaa10', 'bbb', 15, 0, '0630302937', '2010-06-18 10:34:09');

INSERT INTO pet (id, name, breed, age, dead, parent)
	VALUES(0, 'doggystyle', 'curious', 63, 0, 1);
INSERT INTO pet (id, name, breed, age, dead, parent)
	VALUES(1, 'doggystyle0', 'curious', 63, 0, 2);
INSERT INTO pet (id, name, breed, age, dead, parent)
	VALUES(2, 'doggystyle5', 'curious', 63, 0, 3);
INSERT INTO pet (id, name, breed, age, dead, parent)
	VALUES(3, 'doggystyle10', 'curious', 63, 0, 1);

INSERT INTO person_pet(person_id, pet_id, purchased_on)
	VALUES(0, 0, '2012-06-18 10:34:09');
INSERT INTO person_pet(person_id, pet_id, purchased_on)
	VALUES(1, 1, '1012-06-18 10:34:09');
INSERT INTO person_pet(person_id, pet_id, purchased_on)
	VALUES(2, 2, '1885-06-18 10:34:09');
INSERT INTO person_pet(person_id, pet_id, purchased_on)
	VALUES(3, 3, '2010-06-18 10:34:09');

-- Write a query that can find all the names of pets and their owners bought after 2004. Key to this is to map the person_pet based on the purchased_on column to the pet and parent.
SELECT person.first_name, pet.name FROM person, pet, person_pet
WHERE	person_pet.person_id = person.id
AND		person_pet.pet_id = pet.id
AND		person_pet.purchased_on > '1994-01-01 00:00:00';
-- Write a query that can find the pets that are children of a given pet. Again look at the pet.parent to do this. It's actually easy so don't over think it.

COMMIT;
