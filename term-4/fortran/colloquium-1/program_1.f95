module read_utils
   implicit none
contains
   function read_integer(unit) result(num)
      integer, intent(in) :: unit
      integer :: num
      read(unit, *) num
   end function read_integer
end module read_utils

module sum_utils
   implicit none
contains
   function is_even(num) result(even)
      integer, intent(in) :: num
      logical :: even
      even = mod(num, 2) == 0
   end function is_even
end module sum_utils

program sum_even_odd
   use read_utils
   use sum_utils
   implicit none

   integer, dimension(15) :: numbers
   integer :: i, sum_even, sum_odd

   open(10, file = 'numbers.txt', status = 'old', action = 'read')

   sum_even = 0
   sum_odd = 0

   do i = 1, 15
      numbers(i) = read_integer(10)
      if (is_even(numbers(i))) then
         sum_even = sum_even + numbers(i)
      else
         sum_odd = sum_odd + numbers(i)
      end if
   end do

   close(10)

   print *, "Suma liczb parzystych: ", sum_even
   print *, "Suma liczb nieparzystych: ", sum_odd

end program sum_even_odd
