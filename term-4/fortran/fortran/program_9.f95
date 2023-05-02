program program_9

implicit none

interface
    real function cube_root(x)
        real :: x
    end function cube_root
end interface

real :: a, b
print *, "Type a number: "
read *, a

b = cube_root(a)
print *, "Cube root of ", a, " is ", b

stop
end program program_9

real function cube_root(x)
    implicit none
    real :: x, log_x
    log_x = log(x)
    cube_root = exp(log_x / 3.0)
end function cube_root