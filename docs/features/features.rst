FewMath - Feature Documentation
===============================

This section provides detailed documentation for FewMath functions.

.. contents:: Table of Contents
   :local:

📌 GCD Function
---------------
**Description**: Computes the Greatest Common Divisor (GCD) of one or multiple numbers.

**Usage**
.. code-block:: cpp

    #include "fewmath.h"
    int result = algebra::gcd({12, 18, 24});
    std::cout << result; // Output: 6

.. code-block:: python

    import fewmath
    result = fewmath.algebra.gcd([12, 18, 24])
    print(result)  # Output: 6

---

📌 LCM Function
---------------
**Description**: Computes the Least Common Multiple (LCM) of one or multiple numbers.

**Usage**
.. code-block:: cpp

    #include "fewmath.h"
    int result = algebra::lcm({12, 18, 24});
    std::cout << result; // Output: 72

.. code-block:: python

    import fewmath
    result = fewmath.algebra.lcm([12, 18, 24])
    print(result)  # Output: 72

---

📌 Additional Features
----------------------
Future documentation will include:
- Advanced algebraic functions.
- Matrix operations.
- Number theory utilities.
