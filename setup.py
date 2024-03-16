from setuptools import setup, Extension, find_packages
from Cython.Build import cythonize
import numpy


extensions = [
    Extension(
        "mycypackage._foo",
        sources=["mycypackage/_foo.pyx"],
        include_dirs=[numpy.get_include()],
        extra_compile_args=["-O3", "-std=c++17"],
        # extra_link_args=["-Wl,-flat_namespace,-undefined,suppress"],        
        language="c++",
        extra_link_args=["-std=c++17"]        
    )
]

setup(
    name="mycypackage",
    version="0.1.0",
    author="Changhyun Kwon",
    author_email="chkwon@gmail.com",
    package_dir={"": "."},
    packages=find_packages(),
    python_requires=">=3.8",
    ext_modules=cythonize(extensions, language_level = "3"),
    install_requires=["numpy", "Cython"],
)