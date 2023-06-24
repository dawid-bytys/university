module utils
   implicit none
contains
   subroutine read_matrix(filename, a, n)
      character(len=*), intent(in) :: filename
      integer, intent(out) :: n
      real, allocatable, intent(out) :: a(:,:)
      integer :: i

      open(unit=10, file=filename, status="old")
      read(10,*) n
      allocate(a(n, n))
      do i = 1, n
         read(10,*) a(i, :)
      end do
      close(10)
   end subroutine read_matrix

   subroutine print_matrix(a, n)
      integer, intent(in) :: n
      real, intent(in) :: a(n, n)
      integer :: i

      do i = 1, n
         print *, a(i, :)
      end do
   end subroutine print_matrix

   subroutine normalize_vector(x)
      real, intent(inout) :: x(:)
      real :: norm

      norm = sqrt(sum(x**2))
      x = x / norm
   end subroutine normalize_vector

   function is_square_matrix(a, n) result(is_square)
      real, intent(in) :: a(:,:)
      integer, intent(in) :: n
      logical :: is_square

      is_square = (size(a,1) == n .and. size(a,2) == n)
   end function is_square_matrix

   function vector_norm(x) result(norm)
      real, intent(in) :: x(:)
      real :: norm

      norm = sqrt(sum(x**2))
   end function vector_norm

   subroutine write_eigen_to_file(filename, eigenvalue, eigenvector)
      character(len=*), intent(in) :: filename
      real, intent(in) :: eigenvalue
      real, intent(in) :: eigenvector(:)

      open(unit=20, file=filename, status="unknown")
      write(20,*) "Eigenvalue: ", eigenvalue
      write(20,*) "Eigenvector: ", eigenvector
      close(20)
   end subroutine write_eigen_to_file
end module utils

program eigenvalue_calculator
   use utils
   implicit none
   real, allocatable :: a(:,:), x(:), y(:)
   integer :: n
   real :: eigenvalue, tol
   character(len=100) :: input_file, output_file

   ! ask user for filename
   write(*,*) "Enter the input filename (e.g., matrix.txt): "
   read(*,*) input_file

   ! read matrix from file
   call read_matrix(input_file, a, n)

   ! check if matrix is square
   if (.not. is_square_matrix(a, n)) then
      write(*,*) "Error: Matrix is not square."
      stop
   end if

   ! initialize x vector
   allocate(x(n))
   x = 1.0

   ! ask user for tolerance
   write(*,*) "Enter the tolerance for convergence (e.g., 1.0E-6): "
   read(*,*) tol

   ! power iteration method
   do
      y = matmul(a, x)
      eigenvalue = dot_product(y, x)
      call normalize_vector(y)
      if (vector_norm(y - x) < tol) exit
      x = y
   end do

   ! ask user for output filename
   write(*,*) "Enter the output filename to save eigenvalue and eigenvector (e.g., output.txt): "
   read(*,*) output_file

   ! write the eigenvalue and eigenvector to file
   call write_eigen_to_file(output_file, eigenvalue, x)

   ! print the eigenvalue and eigenvector
   write(*,*) "Eigenvalue: ", eigenvalue
   write(*,*) "Eigenvector: ", x
end program eigenvalue_calculator
