Chapter 3
=========

Note 1: On the usage of pointers or references in function arguments
--------------------------------------------------------------------

These are tips taken from section 3.3.1 about passing arguments as values to be
copied, pointers to those arguments, or references:

1. In those situations where a function does not alter its parameters of a
   *built-in* or *pointer type*, value parameters can be used:

   .. code-block:: cpp

      void some_func(int val)
      {
           std::cout << val << '\n';
      }

      int main()
      {
          int x;

          some_func(x);  // a copy is passed
      }

2. When a function explicitly must change the values of its arguments, a
   pointer parameter is preferred.  These pointers parameters should preferably
   be the function's initial parameters.  This is called *return by argument*.

   .. code-block:: cpp

      void by_pointer(int *valp)
      {
          *valp += 5;
      }

3. When a function doesn't change the value of its class- or struct-type
   arguments, or if the modification of the argument is a trivial side-effect
   (e.g., the argument is a stream) references can be used.  Const-references
   should be used if the function does not modify the argument:

   .. code-block:: cpp

      void by_reference(std::string const &str)
      {
          std::cout << str;        // no modification of str
      }

      int main()
      {
          int x = 7;
          by_pointer(&x);            // a pointer is passed
                                     // x might be changed

          std::string str("hello");
          by_reference(str);         // str is not altered
      }

Note 2: Avoiding the copy operation
-----------------------------------

References play an important role in cases where the argument is not changed by
the function but where it is undesirable to copy the argument to initialize the
parameter.  Such a situation occurs when a large object is passed as argument,
or is returned by the function.  In these cases the copying operation tends to
become a significant factor, as the entire object must be copied.  In these
cases references are preferred.

If the argument isn't modified by the function, or if the caller shouldn't
modify the returned information, the `const` keyword should be used.
