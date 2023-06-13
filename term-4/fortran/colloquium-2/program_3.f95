program monte_carlo_integral
   implicit none
   integer, parameter :: rdp = selected_real_kind(15)
   integer, parameter :: idp = selected_int_kind(15)
   real(kind = rdp) :: x, y, integral_estimate
   real(kind = rdp) :: pi_val = 3.14159265358979323846264338327950288_rdp
   integer(kind = idp) :: i, under_curve
   integer, parameter :: max_iterations = 1000000_idp

   call init_random_seed()
   under_curve = 0

   do i = 1, max_iterations
      call random_number(x)
      call random_number(y)

      x = x * pi_val
      y = y * 1.0_rdp

      if (y <= sin(x)) then
         under_curve = under_curve + 1
      end if
   end do

   integral_estimate = real(under_curve) / real(max_iterations) * pi_val
   print *, "Integral estimate = ", integral_estimate
   stop

contains
   subroutine init_random_seed()
      integer :: i, n, clock
      integer, dimension(:), allocatable :: seed

      call random_seed(size = n)
      allocate(seed(n))

      call system_clock(count = clock)
      seed = clock + 37 * (/ (i - 1, i = 1, n) /)
      call random_seed(put = seed)
      deallocate(seed)
   end subroutine
end program monte_carlo_integral
