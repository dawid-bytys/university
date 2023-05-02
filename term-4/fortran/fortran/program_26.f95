program program_26
   implicit none
   real :: maximal, minimal, il_skal
   integer, dimension(2, 3) :: matrix_A
   logical, dimension(2, 3) :: mask
   integer, dimension(3, 2) :: matrix_B
   integer, dimension(2, 2) :: matrix_AB

   integer, dimension(3) :: vector_C
   integer, dimension(3) :: vector_D
   integer, dimension(6) :: vector_E

   integer, dimension(1:2) :: indeksy

   matrix_A(1, 1) = 1
   matrix_A(2, 1) = 4
   matrix_A(2, 2) = 5
   matrix_A(2, 3) = 6

   maximal = maxval(matrix_A)
   indeksy = maxloc(matrix_A)
   print *, "max matrix_A(", indeksy(1), ",", indeksy(2), ")", maximal

   minimal = minval(matrix_A)
   indeksy = minloc(matrix_A)
   print *, "min matrix_A(", indeksy(1), ",", indeksy(2), ")", minimal

   vector_E = pack(matrix_A, mask)
   vector_E = pack(matrix_A, .true.)
   print *
   print *, "vector_E", vector_E

   vector_C = pack(matrixc_A, matrix_A <= 3)
   vector_D = pack(matrix_A, matrix_A > 3)
   il_skal = dot_product(vector_C, vector_D)
   print *
   print *, "vector_C = ", vector_C
   print *, "vector_D = ", vector_D
   print *, "il_skal = ", il_skal
   stop
end program program_26
