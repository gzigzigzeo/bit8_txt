# BIT8

Tiny library to print texts to 8-bit software buffers.

# Motivation

Text height should be 8 bits.

# Example

C++ templates are used here to shorten definitions in target program. Templates might increase compiled code size due to method duplication. In the another hand, there are very limited number of projects which use lots of screens at once. Hence, the only one copy of the class will be defined. -Os compliler flag eliminates duplication anyway and target code size might even be lower than with normal ++ classes.

# Testing

# References


