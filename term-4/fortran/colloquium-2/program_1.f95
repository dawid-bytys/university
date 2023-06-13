program deposit_calculator
   implicit none

   type :: deposit_info
      real :: principal
      real :: annual_rate
      integer :: num_years
   end type deposit_info

   type(deposit_info) :: my_deposit
   real :: final_amount

   my_deposit%principal = 1000.0
   my_deposit%annual_rate = 0.02
   my_deposit%num_years = 30

   final_amount = calculate_final_amount(my_deposit)

   print *, "Initial amount: ", my_deposit%principal, "PLN"
   print *, "Annual interest rate: ", my_deposit%annual_rate * 100.0, "%"
   print *, "Number of years: ", my_deposit%num_years
   print *, "Final amount: ", final_amount, "PLN"

contains
   function calculate_final_amount(deposit) result(final_amount)
      type(deposit_info), intent(in) :: deposit
      real :: final_amount
      integer :: i

      final_amount = deposit%principal
      do i = 1, deposit%num_years
         final_amount = final_amount * (1 + deposit%annual_rate)
      end do
   end function calculate_final_amount
end program deposit_calculator
