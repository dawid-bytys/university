program program_4

implicit none

real :: a, b
integer :: c

open(unit=66, file="data_in", status="old", action="read", position="rewind")
read(unit=66, fmt=*) a, b, c
write(unit=*, fmt="(a8, f6.3, t40, a5, es12.4, a6, i8)") &
"a = ", a, "b = ", b, "c = ", c

stop
end program program_4