program program_23
   implicit none
   integer, dimension(2:5, 7:12, -5:4, 7, 2) :: macierz
   integer :: rozmiar, rozmiar1, rozmiar3, dolna_g, gorna_g
   macierz = 7

   rozmiar = size(macierz)
   rozmiar1 = size(macierz, 1)
   rozmiar3 = size(macierz, 3)
   dolna_g = lbound(macierz, 2)
   gorna_g = ubound(macierz, 2)
   print *, "rozmiar = ", rozmiar, "rozmiar1 = ", rozmiar1, &
      "rozmiar3 = ", rozmiar3, "dolna_g = ", dolna_g, &
      "gorna_g = ", gorna_g
   stop
end program program_23
