program program_21
    implicit none

    integer, dimension(5, 3) :: macierz
    integer, dimension(15) :: wektor

    wektor = (/0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14/)
    macierz = reshape(wektor, (/5, 3/))
    
    print *, macierz

stop
end program program_21