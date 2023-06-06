module vowel_counter
   implicit none
   private
   public :: count_vowels
contains
   integer function count_vowels(word)
      character(len=*), intent(in) :: word
      integer :: i

      count_vowels = 0

      do i=1, len(word)
         select case (word(i:i))
          case ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
            count_vowels = count_vowels + 1
          case default
            continue
         end select
      end do
   end function count_vowels
end module vowel_counter

program main
   use vowel_counter, only: count_vowels
   implicit none

   character(len=256) :: word
   integer :: num_vowels

   open(unit=10, file='input.txt', status='old', action='read')
   read(10, '(a)') word

   close(10)

   word = trim(adjustl(word))
   num_vowels = count_vowels(word)

   print*, "Słowo '", word, "' zawiera ", num_vowels, " samogłos(ek/ki)."
end program main
