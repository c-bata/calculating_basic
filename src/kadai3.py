def phi(x):
    """u(x, 0) = x (0<=x<=1/2), 1-x (1/2 < x <= 1)
    """
    if 0 <= x <= 1/2:
        return x
    elif 1/2 < x <= 1:
        return 1-x
    else:
        return None

def initial_u_array(N, dx):
    u_array = []
    for j in range(N+1):
        u_array.append(phi(j*dx))
    return u_array

def calc_u_array(alpha, u, n, j):
    ans = alpha * u[n][j+1]
    ans += (1 - 2 * alpha) * u[n][j]
    ans += alpha * u[n][j-1]
    return ans

def main(dx, dt, N, M, T):
    alpha = dt/(dx*dx)

    u_array = []
    u_array.append(initial_u_array(N, dx))

    for n in range(M):
        u = [0] + [calc_u_array(alpha, u_array, n, j) for j in range(1, N)] +[0]
        u_array.append(u)

    return u_array

if __name__ == '__main__':
    loop_variables = (
        # dx, dt, N, M, T
        (1/6,  1/100, 6,  100, 1),
        (1/10, 1/100, 10, 100, 1),
        (1/10, 1/500, 10, 500, 1),
    )
    for dx, dt, n, m, t in loop_variables:
        print('start', dx, dt, n, m, t)
        u_array = main(dx, dt, n, m, t)
        for u in u_array:
            print(','.join(["{0:.5f}".format(x) for x in u]))

