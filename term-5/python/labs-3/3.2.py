"""
Co jest złego w kodzie?
"""

# 1. Próba przypisania wartości do zmiennej, która jest typu None.
"""
L = [3, 5, 4] ; L = L.sort()
"""

# 2. Próba przypisania trzech wartości do dwóch zmiennych.
"""
x, y = 1, 2, 3
"""

# 3. Próba zmienienia wartości w krotce. Krotki są niemutowalne.
"""
X = 1, 2, 3 ; X[1] = 4
"""

# 4. Próba odwołania się do indeksu, który nie istnieje.
"""
X = [1, 2, 3] ; X[3] = 4
"""

# 5. Próba odwołania się do metody, która nie istnieje dla danego typu.
"""
X = "abc" ; X.append("d")
"""

# 6. Funkcja pow przyjmuje dwa argumenty.
"""
L = list(map(pow, range(8)))
"""
