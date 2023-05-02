program program_35
   implicit none
   real :: a, b, c, d, e, f;

   interface
      subroutine root(rank, x, y)
         implicit none
         real, intent(in) :: rank, x
         real, intent(out) :: y
      end subroutine root
   end interface

   a = 27; call root(3., a, b); write(*, *) "cube root of ", a, " equals ", b
   c = 16, call root(4., c, d); write(*, *) "4-th root of ", c, " equals ", d
   e = 1024, call root(10., e, f); write(*, *) "10-th root of ", e, " equals ", f
   stop
end program program_35
