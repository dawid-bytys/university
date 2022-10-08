import numpy as np

matrix_A_1 = np.array(
    [
        [2.34332898, -0.11253278, -0.01485349, 0.33316649, 0.71319625],
        [-0.11253278, 1.67773628, -0.32678856, -0.31118836, -0.43342631],
        [-0.01485349, -0.32678856, 2.66011353, 0.85462464, 0.16698798],
        [0.33316649, -0.31118836, 0.85462464, 1.54788582, 0.32269197],
        [0.71319625, -0.43342631, 0.16698798, 0.32269197, 3.27093538],
    ]
)

matrix_A_2 = np.array(
    [
        [2.34065520, -0.05353743, 0.00237792, 0.32944082, 0.72776588],
        [-0.05353743, 0.37604149, -0.70698859, -0.22898376, -0.75489595],
        [0.00237792, -0.70698859, 2.54906441, 0.87863502, 0.07309288],
        [0.32944082, -0.22898376, 0.87863502, 1.54269444, 0.34299341],
        [0.72776588, -0.75489595, 0.07309288, 0.34299341, 3.19154447],
    ]
)

vector_b = np.array(
    [
        3.55652063354463,
        -1.86337418741501,
        5.84125684808554,
        -1.74587299057388,
        0.84299677124244,
    ]
).transpose()

vector_b_prim = np.add(vector_b, np.array([1e-5, 0, 0, 0, 0]).transpose())

y_1 = np.linalg.solve(matrix_A_1, vector_b)
y_2 = np.linalg.solve(matrix_A_2, vector_b)

y_1_prim = np.linalg.solve(matrix_A_1, vector_b_prim)
y_2_prim = np.linalg.solve(matrix_A_2, vector_b_prim)

norm_1 = np.linalg.norm(y_1 - y_1_prim)
norm_2 = np.linalg.norm(y_2 - y_2_prim)

cond_A_1 = np.linalg.cond(matrix_A_1)
cond_A_2 = np.linalg.cond(matrix_A_2)

if __name__ == "__main__":
    print("Norm 1: ", norm_1)
    print("Norm 2: ", norm_2)
    print("Condition number of A_1: ", cond_A_1)
    print("Condition number of A_2: ", cond_A_2)
