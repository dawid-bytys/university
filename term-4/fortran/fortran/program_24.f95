program program_24
   implicit none
   integer :: i, j
   real :: mala, duza, cala, mnoze1, mnoze2
   integer, parameter :: miesiac = 12, rok = 5
   integer, dimension(miesiac, rok) :: forsa
   do i = 1, miesiac
      do j = 1, rok
         forsa(i, j) = int(abs(sin(real(i)) * j) * (-1) ** i)
      end do
   end do
   print *, forsa
   where(forsa.le.0) forsa = -forsa
   where(forsa.eq.0) forsa = 1
   mala = sum(forsa, forsa < 3)
   duza = sum(forsa, forsa >= 3)
   cala = sum(forsa)
   print *, "mala = ", mala, " duza = ", duza, " cala = ", cala
   print *, forsa
   mnoze1 = product(forsa)
   mnoze2 = product(forsa, mask = forsa >= 3)
   print *, "mnoze1 = ", mnoze1, " mnoze2 = ", mnoze2
   stop
end program program_24

