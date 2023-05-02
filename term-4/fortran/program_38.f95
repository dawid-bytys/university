module zawiera_procedure_norm
   implicit none
   public :: zawiera_procedure_norm
contains
   subroutine norm(v, total, flag)
      real, dimension(:), intent(in) :: v
      real, intent(out):: total
      logical, intent(out):: flag

      total = sqrt(sum(v * v))
      flag = (total <= 1.0e5)
      return
   end subroutine norm
end module zawiera_procedure_norm

program program_38
   use zawiera_procedure_norm
   implicit none
   real, dimension(6), parameter :: &
      v = (/10.0, 200.0, 3000.0, 40000.0, 500000.0, 6000000.0/)
   real :: total; logical :: flag

   write(unit=*, fmt="('Wartości macierzy v: ', 6(e10.3, 5x))") v
   write(unit=*, fmt="('Wartości macierzy v: ', 6(e10.1, 5x))") v
   write(unit=*, fmt="('Wartości macierzy v: ', 6(es10.2, 5x))") v
   write(unit=*, fmt="('Wartości macierzy v: ', 6(en12.4, 5x))") v

   call norm(v, total, flag)
   write(unit=*, fmt=77) total, flag
77 format("total, flag=", en10.3, 2x, l3)
   goto 99999
   print *, "tego wydruku nie zobaczysz"
99999 continue

   if(flag .eqv. .true.) goto 99998
   print *, "tego wydruku nie zobaczysz"
99998 continue
   stop
end program program_38
