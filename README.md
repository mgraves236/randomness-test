*University project for Quantum Cryptography class.*

# Background
Random number generators are defined by algorithms thus are actually *pseudo-random* number generators. That means that sequences generated by them might include patterns.

This behavior is undesirable in many of the applications of RNGs, including crucial ones as cryptography or communication protocols. 

## Random Number Generators
There are three types of RNGs: Pseudo-random number generators (PRNGs), True random number generators (TRNGs) and Quantum random number generators (QRNGs).

###### PRNGs
PRNGs are based on deterministic algorithms which usually must first be provided a random seed. It is important that the seed is generated by the *real* randomness since the same seed will generate the same sequence for every run. 

###### TRNGs
These random number generators relay on classical physical processes to create random numbers. The randomness is provided by the existence of many uncontrollable degrees of freedom or systems with chaotic behavior. However, it is hard to establish the quality of generated random numbers.

###### QRNGs
QRNGs are based on the quantum property of indeterminacy. It is impossible to predict random numbers produced by these generators.


## Randomness tests
Randomness tests are used to determine whether there is a recognizable pattern in a data set. It is crucial to assure the randomness of an algorithm before it will be used for purposes where security is concerned. These test should also confirm whether the generation process was a quantum one. 

Some standards are insufficient and one can find a PRNG that would pass the test, while some QRNGs would not.

# Project outline
 1. We implemented a brute force statistical test in C++ based on searching for patterns. To consider a randomly generated bits truly random the string should pass the following tests:
    - There should be as many 0s as there are 1s (tantamount to checking one-bit patterns).
    
    - Each sequence of bits should occur roughly with the same probability (we accept a 0.01% deviation from the expected value). 
    
    The program checks an input file for occurrences of bit sequences, e.g. the string should consist of 50% of 1s and 50% of 0s, then checks two-bit patterns: 01, 10, 11, 00 and each of them should appear with 25% probability, etc.
    We search for up to 28-bit patterns, however to save resources and time we limited the number of patterns to search within the file to 64, which means that we check 64 random permutations.
    


 2. Run the tests on provided binary files generated by QRNGs. Visualize obtained data.


 4. Run the tests on sequences generated by different PRNGs and TRNGs.


 5. Analyze influence of testing parameters (enhance the complexity of performed tests, search for more complex, long range patterns in provided data). E.g. find parameters that will detect determinism of a following sequence (one third of the sequence can be predicted based on two previous parts): 
```
s_1 = 100mb from QRNG
s_2 = 100mb from QRNG
s_3 = s_1 XOR s_2 

sequence = s_1.s_2.s_3
```
  6. Determine what pattern length is the most effective for testing a string of a given length, i.e. how long the pattern needs to be in relation to the one being tested for the test to disclose its pseudo-randomness.


  7. Show that waiting times are rising exponentially with the sequence length.

# Bibliography 
[Wikipedia, *Randomness test*](https://en.wikipedia.org/wiki/Randomness_test)

[Quantum Flagship, *Quantum Random Numbers Generator*](https://qt.eu/discover-quantum/underlying-principles/qrng/)

[Andrei Khrennikov, *Randomness: quantum versus classical*](https://arxiv.org/abs/1512.08852)

[Predictive hacks, *How to test for randomness*](https://predictivehacks.com/how-to-test-for-randomness/)

[Andrew Rukhin, *A Statistical Test Suite for Random and Pseudorandom Number Generators for Cryptographic Applications*](https://nvlpubs.nist.gov/nistpubs/legacy/sp/nistspecialpublication800-22r1a.pdf)

[Vipul Goyal, *Introduction to Cryptography. Lecture 7: Pseudo Random Generators*](https://www.cs.cmu.edu/~goyal/s18/15503/scribe_notes/lecture7.pdf)
