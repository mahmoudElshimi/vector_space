Vector Space:  An implementation of Vector Space written in both C and Python.
==============================================================================
- Why C? God created universe in C.
- Why Python? You know.
- Python code was checked using mypy.

Definition and basic properties
-------------------------------
- A vector is any object that respect these [axioms](https://en.wikipedia.org/wiki/Vector_space#Definition_and_basic_properties), In this implementation we assume that they are $\in \mathbb{R}^{n}$
- [Dot prouduct](https://en.wikipedia.org/wiki/Dot_product#Definition) is define as: $$\vec{u} \cdot \vec{w} = \sum_{i}{u_{i}w_{i}} \textit{, where } \vec{u}, \vec{w} \in \mathbb{R}^{n}\text{. In general } V\times V\to F$$
- [Norm](https://en.wikipedia.org/wiki/Norm_(mathematics)) is define as: $$\|\|\vec{u}\|\| = \sqrt{\sum_{i}{\|u_{i}\|}} = \sqrt{\sum_{i}{u_{i}^{2}}}$$

To Do
-----
- Implement a Cross product.
- Support Vectors  $\in \mathbb{C}$
- Adding Rust implementation, whay? cuz i love rust.  

Requirements
------------
- Python >= 3.11.6
- CC --std=c99 -lm (Clang or GCC).

Running
-------
```
$ git clone https://github.com/mahmoudElshimi/vector_space
$ cd vector_space
$ python vec.py
$ cc --std=c99 -lm -Wall -o vec vec.c && ./vec
```

