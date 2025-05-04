Vector Space:  An implementation of Vector Space written in both C and Python.
==============================================================================
- Why C? God created universe in C.
- Why Python? You know.
- Python code was statically typed and checked using mypy.

Definition and basic properties
-------------------------------
- A vector is any object that respects these [axioms](https://en.wikipedia.org/wiki/Vector_space#Definition_and_basic_properties). 
   In this implementation we assume that they are $\in \mathbb{C}^{n}$
  
- [Dot product](https://en.wikipedia.org/wiki/Dot_product#Definition) is defined as:
  
  For \(\mathbb{R}^n\):
  $$\vec{u} \cdot \vec{w} = \sum_{i}{u_{i}w_{i}} \textit{, where } \vec{u}, \vec{w} \in \mathbb{R}^{n} \text{. In general } V \times V \to F$$
  
  For \(\mathbb{C}^n\):
  $$\vec{u} \cdot \vec{w} = \sum_{i}{u_{i}\overline{w_{i}}} \textit{, where } \vec{u}, \vec{w} \in \mathbb{C}^{n} \text{ and } \overline{w_{i}} \text{ is the complex conjugate of } w_{i}.$$
  
- [Norm](https://en.wikipedia.org/wiki/Norm_(mathematics)) is defined as:

 $$\|\|\vec{u}\|\| = \sqrt{\sum_{i}{\|u_{i}\|}} = \sqrt{\sum_{i}{u_{i}^{2}}}$$

- [Cross product](https://en.wikipedia.org/wiki/Cross_product) is defined only in 3D as:
  
 $$\vec{u} \times \vec{w} = 
  \left(
  \begin{array}{c}
  u_2 w_3 - u_3 w_2 \\
  u_3 w_1 - u_1 w_3 \\
  u_1 w_2 - u_2 w_1
  \end{array}
  \right)
  \textit{, where } \vec{u}, \vec{w} \in \mathbb{R}^{3}$$
  
  
  
To Do
-----
- Implement a Cross product. #Done as per: #3bc7daa, #22a5520.
- Support Vectors  $\in \mathbb{C}^{n}$ . #Done as per: #4be75a6
- Adding Rust implementation, whay? cuz i love Rust.  

Requirements
------------
- Python >= 3.11.6
- CC --std=c99 -lm (Clang or GCC).

Running
-------
```
$ git clone https://github.com/mahmoudElshimi/vector_space
$ cd vector_space
$ python -i vec.py
$ cc --std=c99 -lm -Wall -o vec vec.c && ./vec
```

