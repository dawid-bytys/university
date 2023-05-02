program program_13
    implicit none

    integer, parameter :: st = 8
    integer :: r, s
    logical, dimension(10, 10):: k1, k2
    logical, dimension(11:20, 11:20) :: m
    complex, dimension(1:10, 2 + st) :: z, c
    character(len = 10), dimension(1:3) :: napisy

    do r = 1, 10
        do s = 1, 10
            if (r == s) then
                k1(r, s) = .true.
            else
                k1(r, s) = .false.
            end if
        end do
    end do

    k2 = k1
    m = k2
    
    print *, m
    print *
    do s = 11, 20
        print *, (m(s, r), r = 11, 20, 1)
    end do

stop
end program program_13