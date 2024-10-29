Here are some basics related to bitwise operators and their relation.
<details>
    <summary><b>AND(&) Operator</b></summary>  
    Bitwise AND is a binary operator that operates on two equal-length bit patterns. If both bits in the compared position of the bit patterns are 1, the bit in the resulting bit pattern is 1, otherwise 0.</br>
    The table for bitwise operator &(AND):</br>
    <b>0 & 0 = 0</br>
    0 & 1 = 0</br>
    1 & 0 = 0</br>
    1 & 1 = 1</b></br>
    <b>Example:</b></br>
    A   =   5   =   (101)<sub>2</sub></br>
    B   =   3   =   (011)<sub>2</sub></br>
    A & B = (101)<sub>2</sub> & (011)<sub>2</sub>= (001)<sub>2</sub> = 1</br>
    <b>or</b></br>
    101 ⇒ 5</br>
    011 ⇒ 3</br>
    ----- &</br>
    001 ⇒ 1
    Each bit-column is AND-ed using the AND table above.

</details>  
<details>
    <summary><b>OR(|) Operator</b></summary>  
    Bitwise OR is also a binary operator that operates on two equal-length bit patterns, similar to bitwise AND. If both bits in the compared position of the bit patterns are 0, the bit in the resulting bit pattern is 0, otherwise 1.</br>
    The table for bitwise operator |(OR):</br>
    <b>0 | 0 = 0</br>
    0 | 1 = 1</br>
    1 | 0 = 1</br>
    1 | 1 = 1</br>
    </b></br>
    <b>Example:</b></br>
    A   =   5   =   (101)<sub>2</sub></br>
    B   =   3   =   (011)<sub>2</sub></br>
    A | B = (101)<sub>2</sub> | (011)<sub>2</sub>= (111)<sub>2</sub> = 7</br>
    <b>or</b></br>
    101 ⇒ 5</br>
    011 ⇒ 3</br>
    ----- |</br>
    111 ⇒ 7
    Each bit-column is OR-ed using the OR table above.

</details>
<details>
    <summary><b>XOR(^) Operator</b></summary>  
    Bitwise XOR also takes two equal-length bit patterns. If both bits in the compared position of the bit patterns are 0 or 1, the bit in the resulting bit pattern is 0, otherwise 1.</br></br>
    The table for bitwise operator ^(XOR):</br>
    <b>0 ^ 0 = 0</br>
    0 ^ 1 = 1</br>
    1 ^ 0 = 1</br>
    1 ^ 1 = 0</br>
    </b></br>
    <b>Example:</b></br>
    A   =   5   =   (101)<sub>2</sub></br>
    B   =   3   =   (011)<sub>2</sub></br>
    A ^ B = (101)<sub>2</sub> ^ (011)<sub>2</sub>= (110)<sub>2</sub> = 6</br>
    <b>or</b></br>
    101 ⇒ 5</br>
    011 ⇒ 3</br>
    ----- ^</br>
    110 ⇒ 6

</details>
<details>
    <summary><b>NOT(~) Operator</b></summary>  
    Bitwise NOT is an unary operator that flips the bits of the number i.e., if the ith bit is 0, it will change it to 1 and vice versa. Bitwise NOT is nothing but simply the one’s complement of a number.</br>
    <b>Example:</b></br>
    Let int a = 10;</br>
    then ~a = -11;</br>
    Let's take a look how the value is changing:</br>
    0000000000001010 ⇒ a(16 bits)</br>
    ---------------- ~</br>
    1111111111110101 ⇒ -11 (signed)</br>
    For <b>unsigned int</b>, a = 10;</br>
    0000000000001010 ⇒ a(16 bits)</br>
    ---------------- ~</br>
    1111111111110101 ⇒ 4294967285 (unsigned)

</details>
<details>
    <summary><b>LEFT SHIFT(<<) operator</b></summary>  
    Left shift operator is a binary operator which shift the some number of bits, in the given bit pattern, to the left and append 0 at the end. Left shift is equivalent to multiplying the bit pattern with 2<sup>k</sup> ( if we are shifting k bits ).  This operator is mostly used if we want to multiply a number by 2, or, some powers of 2.   </br>
    1 << 1 = 2 = 2<sup>1</sup></br>  
    1 << 2 = 4 = 2<sup>2</sup></br> 
    1 << 3 = 8 = 2<sup>3</sup></br>
    1 << 4 = 16 = 2<sup>4</sup></br>
    …  </br>
    1 << n = 2<sup>n</sup></br>
    Another example:</br>
    4978 << 8 = 1274368 = 4978 * 2<sup>8</sup></br></br>
    <b>Note: </b> We need to be careful when using signed data type, as the left most bit is the sign bit. So, while left shifting, if you push a 1 at that position, the number will be negative.

</details>  
<details>
    <summary><b>Right Shift(>>) Operator</b></summary>  
    Right shift operator is a binary operator which shift the some number of bits, in the given bit pattern, to the right and append 0 at the left. Right shift is equivalent to dividing the bit pattern with 2<sup>k</sup> ( if we are shifting k bits ). This operator is mostly used if we want to divide a number by 2, or, some powers of 2.</br>
    4 >> 1 = 2 (i.e., 4/2<sup>1</sup>)</br>
    6 >> 1 = 3 (i.e., 6/2<sup>1</sup>)</br>
    5 >> 1 = 2 (i.e., 5/2<sup>1</sup>)</br>
    16 >> 4 = 1 (i,e., 16/2<sup>4</sup>)</br></br>
    <b>Non-portability of Right shift operator:</b>
    Filled by a 1 (RIGHT SHIFT ARITHMETIC)
    Filled by a 0 (RIGHT SHIFT LOGICAL)

</details>  
<details>
    <summary><b>Bitwise Operators Precedence</b></summary>  
    Order precedence of the basic operators is:

    NOT ( ~ ) highest
    AND ( & )
    XOR ( ^ )
    OR ( | ) lowest

</details>  
<details>
    <summary><b>Some Facts</b></summary>  
    Let X is a single bit, then we can write the following: 
    
    X & 1 =  X; X & 0 =  0
    X | 1 =  1; X | 0 =  X
    X ^ 1 = ~X; X ^ 0 =  X
</details> 

<details>
    <summary><b>Some equations</b></summary>

- a|b = a⊕b + a&b
- a⊕(a&b) = (a|b)⊕b
- b⊕(a&b) = (a|b)⊕a
- (a&b)⊕(a|b) = a⊕b
- a+b = a|b + a&b
- a+b = a⊕b + 2(a&b)
- a-b = (a⊕(a&b))-((a|b)⊕a)
- a-b = ((a|b)⊕b)-((a|b)⊕a)
- a-b = (a⊕(a&b))-(b⊕(a&b))
- a-b = ((a|b)⊕b)-(b⊕(a&b))
</details>

<details>
    <summary><b>More Facts</b></summary>

- <b>The left-shift and right-shift operators should not be used for negative numbers.</b>

  If the second operand(which decides the number of shifts) is a negative number, it results in undefined behavior in C. For example results of both 1 <<- 1 and 1 >> -1 is undefined. Also, if the number is shifted more than the size of the integer, the behavior is undefined. For example, 1 << 33 is undefined if integers are stored using 32 bits. Another thing is NO shift operation is performed if the additive expression (operand that decides no of shifts) is 0.

  Note: In C++, this behavior is well-defined.

- <b>The Bitwise operators should not be used in place of logical operators.</b>
  The result of logical operators (&&, || and !) is either 0 or 1, but bitwise operators return an integer value. Also, the logical operators consider any non-zero operand as 1.
- <b>The ~ operator should be used carefully.</b>  
  The result of ~ operator on a small number can be a big number if the result is stored in an unsigned variable. And the result may be a negative number if the result is stored in a signed variable (assuming that the negative numbers are stored in 2’s complement form where the leftmost bit is the sign bit)

</details>
