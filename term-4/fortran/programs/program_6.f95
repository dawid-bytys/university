program program_6

implicit none

character(len=10) :: date
character(len=2) :: month

write(unit=*, fmt=*) "Podaj datę w formacie YYYY-MM-DD: "
read(unit=*, fmt=*) date

month = date(6:7)

write(unit=*, fmt="(a10)") month

select case(month)
    case("03":"05")
        write(unit=*, fmt="(a12)") "jest wiosna"
    case("06", "07", "08")
        write(unit=*, fmt="(a12)") "jest lato"
    case default
        write(unit=*, fmt="(a25)") "jest albo jesień, albo zima"
end select

stop
end program program_6