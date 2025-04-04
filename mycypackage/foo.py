import numpy as np 
from .utils import create_random_vector
from ._foo import double_vector_cpp, double_vector_cpp_nocopy, double_span_cpp_nocopy


def double_random_vector(size: int) -> np.ndarray:
    v = create_random_vector(size)
    print("v = ", v)
    v2 = double_vector_cpp(v)
    print("v2 = ", v2)
    
    double_vector_cpp_nocopy(v)
    print("v = ", v)
    
    double_span_cpp_nocopy(v)
    print("v = ", v)
    
    return v



