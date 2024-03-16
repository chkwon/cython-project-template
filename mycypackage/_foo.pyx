import numpy as np 

# Import necessary Cython libraries
from libc.stdlib cimport malloc, free
from libcpp.vector cimport vector
from libcpp cimport bool

cdef extern from "../cpp_code/foo.cpp":
    pass

cdef extern from "../cpp_code/foo.hpp":
    void multiply_vector(vector[int] & v, int factor)
    
    void multiply_array(int * v, int len, int factor)


# Define a Cython wrapper function

def double_vector_cpp(arr: np.ndarray[np.int32_t]):
    
    # This function makes a copy of arr, so that the original array is not modified
    multiply_vector(arr, 2)

    # If you want to use vector<int> in your C++ code, then you should make a copy somewhere.
    # For example,
    cdef vector[int] v = arr.tolist() # This makes a copy of the array
    multiply_vector(v, 2)
    return np.array(v) # This makes a copy of the vector




def double_vector_cpp_nocopy(arr: np.ndarray[np.int32_t]):
    # First, we check if the array is contiguous. If not, we make it contiguous
    if not arr.flags['C_CONTIGUOUS']:
        arr = np.ascontiguousarray(arr, dtype=np.int32)

    # We create a view of the array, so that we can pass it to the C++ function
    cdef int[:] arr_view = arr

    # This function modifies the original array
    multiply_array(<int*> &arr_view[0], arr_view.shape[0], 2)