program quadratic_roots
   implicit none

   real :: a, b, c
   real :: root1, root2
   complex :: complex_root1, complex_root2

   print*, "Wprowadź współczynniki a, b, c po spacji równania kwadratowego ax^2 + bx + c = 0: "
   read(*,*) a, b, c

   if (a .eq. 0.0) then
      print*, "Error: współczynnik 'a' nie może być równy 0."
      stop
   else
      call calculate_roots(a, b, c, root1, root2, complex_root1, complex_root2)
   end if

contains
   subroutine calculate_roots(a, b, c, root1, root2, complex_root1, complex_root2)
      implicit none

      real, intent(in) :: a, b, c
      real, intent(out) :: root1, root2
      complex, intent(out) :: complex_root1, complex_root2
      real :: discriminant

      discriminant = b**2 - 4.0*a*c

      if (discriminant .ge. 0.0) then
         root1 = (-b + sqrt(discriminant)) / (2.0*a)
         root2 = (-b - sqrt(discriminant)) / (2.0*a)
         print*, "Rzeczywiste pierwiastki: ", root1, root2
      else
         complex_root1 = cmplx(-b, sqrt(-discriminant)) / (2.0*a)
         complex_root2 = cmplx(-b, -sqrt(-discriminant)) / (2.0*a)
         print*, "Zespolone pierwiastki (Re, Im): ", complex_root1, complex_root2
      end if
   end subroutine calculate_roots
end program quadratic_roots

