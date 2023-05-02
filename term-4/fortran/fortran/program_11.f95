program program_11
    implicit none

    real :: sum, a_j
    real, parameter :: eps=1.0e-40

    a_j = .99999
    sum = 0.0

    do
        a_j = a_j * a_j
        sum = sum + a_j
        print *, a_j
        if (a_j < eps) exit
    end do

    print *, "suma = ", sum

stop
end program program_11