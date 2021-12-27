from math import asin, pi, sin, cos, sqrt

earth_radius = 6378.1


def formula_distance(la_1, la_2, lo_1, lo_2):
    la_1 = to_radius(la_1)
    la_2 = to_radius(la_2)
    lo_1 = to_radius(lo_1)
    lo_2 = to_radius(lo_2)
    return (
        2
        * earth_radius
        * asin(
            sqrt(
                (sin(abs(lo_1 - lo_2) / 2)) ** 2
                + cos(lo_1) * cos(lo_2) * (sin(abs(la_1 - la_2) / 2)) ** 2
            )
        )
    )


def to_radius(x):
    return x / 180 * pi
