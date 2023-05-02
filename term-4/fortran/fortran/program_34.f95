program program_34
   implicit none
   real :: a, b, c

   interface
      function mean(x, y)
         implicit none
         real, intent(in) :: x, y
         real :: mean
         mean = (x + y) / 2.0
         return
      end function mean
   end interface

   a = 30; b = 60; c = mean(a, b)
   write(*, *) "mean = ", c
   stop
end program program_34
