-- Create the university database
CREATE DATABASE IF NOT EXISTS university;

-- Use the university database
USE university;

-- Create the "students" table
CREATE TABLE students (
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    birthdate DATE,
    enrollment_date DATE,
    group_id INT,
    FOREIGN KEY (group_id) REFERENCES groups(group_id)
);

-- Create the "employees" table
CREATE TABLE employees (
    employee_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    hire_date DATE,
    job_title VARCHAR(50)
);

-- Create the "faculties" table
CREATE TABLE faculties (
    faculty_id INT PRIMARY KEY AUTO_INCREMENT,
    faculty_name VARCHAR(100)
);

-- Create the "studies_fields" table
CREATE TABLE studies_fields (
    field_id INT PRIMARY KEY AUTO_INCREMENT,
    field_name VARCHAR(100),
    faculty_id INT,
    FOREIGN KEY (faculty_id) REFERENCES faculties(faculty_id)
);

-- Create the "groups" table
CREATE TABLE groups (
    group_id INT PRIMARY KEY AUTO_INCREMENT,
    group_name VARCHAR(50),
    field_id INT,
    FOREIGN KEY (field_id) REFERENCES studies_fields(field_id)
);

-- Create the "subjects" table
CREATE TABLE subjects (
    subject_id INT PRIMARY KEY AUTO_INCREMENT,
    subject_name VARCHAR(100)
);

-- Create a table to represent the relationship between employees, subjects, and groups
CREATE TABLE employee_subject_group (
    employee_id INT,
    subject_id INT,
    group_id INT,
    FOREIGN KEY (employee_id) REFERENCES employees(employee_id),
    FOREIGN KEY (subject_id) REFERENCES subjects(subject_id),
    FOREIGN KEY (group_id) REFERENCES groups(group_id)
);

-- Add data to the "faculties" table
INSERT INTO faculties (faculty_name) VALUES
    ('Faculty of Science'),
    ('Faculty of Arts'),
    ('Faculty of Engineering');

-- Add data to the "studies_fields" table
INSERT INTO studies_fields (field_name, faculty_id) VALUES
    ('Computer Science', 1),
    ('Biology', 1),
    ('History', 2),
    ('Civil Engineering', 3);

-- Add data to the "groups" table
INSERT INTO groups (group_name, field_id) VALUES
    ('CS101', 1),
    ('BIO201', 1),
    ('HIST101', 3),
    ('CE301', 4);

-- Add data to the "employees" table
INSERT INTO employees (first_name, last_name, hire_date, job_title) VALUES
    ('John', 'Doe', '2020-01-15', 'Professor'),
    ('Alice', 'Smith', '2018-05-20', 'Assistant Professor'),
    ('Michael', 'Johnson', '2019-09-10', 'Lecturer');

-- Add data to the "subjects" table
INSERT INTO subjects (subject_name) VALUES
    ('Introduction to Programming'),
    ('Cell Biology'),
    ('European History'),
    ('Structural Engineering');

-- Add data to the "students" table
INSERT INTO students (first_name, last_name, birthdate, enrollment_date, group_id) VALUES
    ('Emma', 'Johnson', '2000-05-10', '2021-09-01', 1),
    ('Oliver', 'Williams', '2001-03-15', '2021-09-01', 2),
    ('Sophia', 'Brown', '2002-08-20', '2021-09-01', 3);

-- Add data to the "employee_subject_group" table to establish relationships
INSERT INTO employee_subject_group (employee_id, subject_id, group_id) VALUES
    (1, 1, 1), -- John Doe teaches CS101
    (2, 2, 2), -- Alice Smith teaches BIO201
    (3, 3, 3), -- Michael Johnson teaches HIST101
    (3, 4, 4); -- Michael Johnson teaches CE301
