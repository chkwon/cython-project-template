# cython-project-template

## Installation
From the root directory of this repo:
```
pip install .
```
which will install a package named `mycypackage` to your Python package directory.

The dependency information with other package information is located in `setup.py`.


## Example 
To test if `mycypackage` is installed correctly, run the following code *outside* this repo:
```python
import mycypackage as mcp
mcp.double_random_vector(3)
```

## Unit Test

```
pytest tests
```