module nasze_zmienne
   implicit none
   real :: rank, x, y
end module nasze_zmienne

program program_36
   use nasze_zmienne

   interface
      subroutine root()
         use nasze_zmienne
      end subroutine root
   end interface

   x = 1048576; rank = 20
   call root()
   write(*, *) "20-th root of ", x, " equals ", y
   stop
end program program_36
