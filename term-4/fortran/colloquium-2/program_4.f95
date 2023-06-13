program root_finder
   implicit none
   real(8) :: x, step, f, prev_f, left_bound, right_bound, estimated_root

   left_bound = -3.0d0
   right_bound = 4.0d0
   step = 0.001d0

   prev_f = func(left_bound)

   x = left_bound
   do while (x < right_bound)
      f = func(x)

      if (prev_f * f < 0) then
         estimated_root = (x + x - step) / 2.0d0
         print *, "Estimated root: ", estimated_root
      end if

      prev_f = f
      x = x + step
   end do

contains
   function func(x) result(fx)
      real(8), intent(in) :: x
      real(8) :: fx

      fx = x**3 - 3.0d0 * x**2 - 4.0d0 * x + 12.0d0
   end function func
end program root_finder
