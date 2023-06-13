program sum_of_natural_numbers
   implicit none
   integer(kind=8), parameter :: n1 = 1, n2 = 10
   integer(kind=8) :: result

   result = sum_recursive(n1, n2)

   write(*, '(A, I0, A, I0, A, I0)') "The sum of natural numbers from ", n1, " to ", n2, " is ", result
contains
   recursive function sum_recursive(a, b) result(sum)
      integer(kind=8), intent(in) :: a, b
      integer(kind=8) :: sum

      if (a > b) then
         sum = 0
      else
         sum = a + sum_recursive(a+1, b)
      end if
   end function sum_recursive
end program sum_of_natural_numbers

