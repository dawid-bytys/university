program program_18
    implicit none

    integer :: a, b
    real :: c, d

    print *, 'type 123456789'
    read 101, a, b, c, d
    print 200, a, b, a + b, c, d, c - d
    101 format(t6, i4, tl6, i4, tl6, f4.1, tl6, f4.2)
    200 format(5x, i4, 'minus', i5, 'is ', i5, tr4, f6.2, &
        " minus", f6.2, "is ", f8.3)
end program program_18