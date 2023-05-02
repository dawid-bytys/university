program program_22
    implicit none

    integer, dimension(5, 3) :: macierz
    integer, dimension(15) :: wektor
    integer, dimension(2) :: zakres
    integer :: kolumna, wiersz

    wektor = (/0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14/)
    macierz = reshape(wektor, (/5, 3/))

    print *, macierz
    zakres = (/5, 3/)
    macierz = reshape(wektor, zakres)

    print *
    print *, macierz(:4, :2)
    print *

    do wiersz = 1, 3
        print *, (macierz(kolumna, wiersz), kolumna = 1, 5, 1)
    end do

stop
end program program_22