module zawiera_finkcje_large
   implicit none
   public :: zawiera_finkcje_large
contains
   function large(list, k) result(large_r)
      integer, intent(in), dimension(:) :: list
      integer, intent(in) :: k
      integer :: large_r

      if (any(list <= k)) then
         large_r = maxval(list, mask=(list <= k))
      else
         large_r = k
      end if
      return
   end function large
end module zawiera_finkcje_large

program program_37
   use zawiera_finkcje_large
   implicit none

   integer :: n, k
   integer, allocatable, dimension(:) :: list

   do
      print *, "Podan rozmiar macierzy 'list' "
      read(unit = *, fmt = *) n
      if (n <= 0) then
         exit
      end if

      allocate(list(n))
      print *, "Podaj wartości n-elementowej macierzy oddzielając & "
      read(unit = *, fmt = *) list
      print *, "Podaj liczbę 'k' "
      read(unit = *, fmt = *) k
      print *, "Największy element macierzy 'list' spośród mniejszych od liczby 'k' "
      write(unit = *, fmt = *) large(list, k)
   end do
   stop
end program program_37
