program program_8

implicit none

type person
    character(len=12) :: first_name
    character(len=1) :: middle_initial
    character(len=12) :: last_name
    integer :: age
    character(len=1) :: sex
    character(len=11) :: social_security
end type person

type(person) :: jack, jill

jack = person("Jack", "R", "Hagen", 47, "M", "123-45-6789")
jill = person("Jill", "M", "Smith", 39, "F", "987-65-4321")

print *, jill % last_name
print *, jack % age

if (jack % sex == "F") print *, jack % first_name, " to kobieta"
if (jill % sex == "F") print *, jill % first_name, " to kobieta"

stop
end program program_8