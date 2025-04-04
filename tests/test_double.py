import mycypackage as mcp
import numpy as np

def test_double():
    v = np.random.randint(0, 10, size=10, dtype=np.int32)
    
    v2 = mcp.double_vector_cpp(v)
    assert np.array_equal(v2, v * 2) # v is not changed
    print(v)

    mcp.double_vector_cpp_nocopy(v)
    assert np.array_equal(v2, v) # v is now changed
    print(v)

    mcp.double_span_cpp_nocopy(v)
    assert np.array_equal(v2 * 2, v) # v is again changed
    print(v)