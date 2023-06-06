program program_12
    implicit none

    integer, parameter :: range = selected_int_kind(15)
    integer(kind = range) :: sum, n
    print *, "range = ", range
    sum = 0_range
    n = 0_range

    do
        n = n + 1
        if (n > 1234567890) exit
        if (n == 55) cycle
        if (n.eq.122) cycle
        if (n >= 20.and.n.le.30) cycle
        if (n.ge.20.and.n <= 30) cycle
        sum = sum + n
    end do

    print *, "suma = ", sum

stop
end program program_12