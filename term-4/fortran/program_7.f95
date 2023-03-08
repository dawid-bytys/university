program program_7

implicit none

character(len=16) :: a, b, c, d

a = "a kindly gigant"
b = "a small man"
c = b(:8)
d = "for a" // b(8:)
b = " " // d(:4) // b(9:11) // a(3:6)
a = a(:2) // a(10:15) // "leap"

print *, "Your first name: "
read *, a

print *, "Your second name: "
read *, b

print *, a, b, "student"
print *, trim(a), " ", trim(b), " student"

stop
end program program_7