import numpy as np

def create_random_vector(size: int) -> np.ndarray:
    return np.random.randint(0, 10, size=size, dtype=np.int32)

