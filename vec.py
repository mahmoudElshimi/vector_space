from __future__ import annotations
from typing import Any
from math import sqrt


# define a Vector
class Vec:
    def __init__(self: Vec, arr: list[float], name: str = "") -> None:
        self.arr: list[float] = arr
        self.dim: int = len(arr)
        self.norm: float = Vec.get_norm(arr)
        self.name: str = name

    @staticmethod
    def get_norm(arr: list[float]) -> float:
        return sqrt(sum(map(lambda x: x**2, arr)))

    @staticmethod
    def check_vec(other: Any) -> None:
        if not isinstance(other, Vec):
            raise TypeError("Both operands must be of Vec type")

    def __repr__(self: Vec) -> str:
        return f"Vector {self.name}(\nArray: {self.arr}\nDim: {self.dim}\nNorm:{self.norm}\n)"

    def __str__(self: Vec) -> str:
        return f"Vector {self.name}(\nArray: {self.arr}\nDim: {self.dim}\nNorm:{self.norm}\n)"

    def __add__(self: Vec, other: Vec) -> Vec:
        Vec.check_vec(other)
        return Vec([sum(i) for i in zip(self.arr, other.arr)])

    def __sub__(self: Vec, other: Vec) -> Vec:
        Vec.check_vec(other)
        return Vec([i - j for i, j in zip(self.arr, other.arr)])

    def __mul__(self: Vec, other: Vec) -> float:
        if isinstance(other, Vec):
            if self.dim != other.dim:
                raise TypeError(
                    "unsupported operand type(s) for *: unless both vectors have same dimension"
                )
            return sum([i * j for i, j in zip(self.arr, other.arr)])
        elif isinstance(other, int | float):
            return Vec.__rmul__(self, other)
        raise TypeError("Both operands must be of Vec type or scaler * Vec")

    def __rmul__(self: Vec, other: float) -> Vec:
        return Vec([other * i for i in self.arr])
        
    def cross(self: Vec, other: Vec) -> Vec:
        Vec.check_vec(other)
        if self.dim != 3 or other.dim != 3:
            raise ValueError("Cross product is only defined for 3-dimensional vectors")
        cross_product = [
            self.arr[1] * other.arr[2] - self.arr[2] * other.arr[1],
            self.arr[2] * other.arr[0] - self.arr[0] * other.arr[2],
            self.arr[0] * other.arr[1] - self.arr[1] * other.arr[0],
        ]
        return Vec(cross_product, f"{self.name}×{other.name}")    
        
    def isorthogonal(self: Vec, other: Vec) -> bool:
        return self * other == 0


def main() -> None:
    v = Vec([0, 1, 0], "V")
    w = Vec([1, 0, 0], "W")
    u: Vec = v + w
    u.name: str = "U"
    cross_vw = v.cross(w)
    print(v)
    print(w)
    print(u)
    print("Dot product of V.U: ", v * u)
    print("Are V & W orthogonal? ", v.isorthogonal(w))
    print(cross_vw) 


if __name__ == "__main__":
    main()
