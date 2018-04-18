# Deprecated #

This repository is no longer maintained and the metric MDS function is now included in the `mathtoolbox` library: https://github.com/yuki-koyama/mathtoolbox , so please use the new library.

---

# Overview #

This is a simple and minimum implementation of the classical multi-dimensional scaling (MDS) technique, which can be used as a header-only library. 

# Installation #

You can use it just by copying `mds.h` to your project.

# License #
MIT License.

# Dependency #
[Eigen](http://eigen.tuxfamily.org/)

# Test Run

This repository includes a simple test program, which can be run by
```
git clone https://github.com/yuki-koyama/multidimensional-scaling.git
cd multidimensional-scaling
mkdir build
cd build
cmake ../
make
make test
```

# Others #
[Blog about MDS](http://yuki-koyama.hatenablog.com/entry/2015/07/13/015736) (written in Japanese)
