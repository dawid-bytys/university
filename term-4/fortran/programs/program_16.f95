program program_16
    integer, parameter :: st = 8
    integer :: wiersz, kolumna, r
    real, dimension(2:10, -30:30, 0:10) :: t, y, trazyy
    complex, dimension(1:10, 2 + st) :: z, c

    t = 2.0
    y = 3.0

    trazyy = t * y

    print *, trazyy

    z = (1.0, 1.0)
    do r = 1, 10
        z(1, r) = (0.0, 9.0)
    end do

    c = (2.0, 0.0) * z + (1.0, 0.0)

    print *, c(1:3, 8:10)
    print *

    do wiersz = 1, 3
        print *, (c(wiersz, kolumna), kolumna = 8, 10)
    end do
stop
end program program_16