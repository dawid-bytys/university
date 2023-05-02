program program_5

implicit none

integer :: i, k

do i = 1, 10
    do k = 1, 12, 5
        write(unit=*, fmt=*) i, k
    end do
end do

stop
end program program_5