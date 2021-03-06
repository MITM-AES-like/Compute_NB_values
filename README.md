# Finding Guess-and-Determine MITM procedures to compute initial values of neutral bytes

This repository provides source codes and results for finding procedures to compute the initial values 

* of forward neutral bytes (in Blue) for the preimage attack on 7-round Whirlpool in Fig. 3 [\[1\]](https://eprint.iacr.org/2021/575).

* of backward neutral bytes (in Red) for the preimage attack on 9-round AES-192 hashing in Fig. 18 [\[1\]](https://eprint.iacr.org/2021/575).

* of forward neutral bytes (in Blue) for the collision attack on 6-round Grøstl-256 OT in Fig. 20 [\[1\]](https://eprint.iacr.org/2021/575).

* of backward neutral bytes (in Red) for the collision attack on 7-round AES-128 hashing in Fig. 22 [\[1\]](https://eprint.iacr.org/2021/575).

(only for the neutral bytes on which complex constraints are imposed such that non-trivial procedures are required).

The procedures for some other attacks can be obtained similarly.

This is aided by the Automatic-tool offered by Bouillaguet et. al in [\[2\]](https://www-almasty.lip6.fr/~bouillaguet/static/attacks/AES-tool.tar.gz).


## Subdirectories

* `equations`: contains files of systems of equations corresponding to the relations and constraints on the neutal bytes.
* `runlogs`: contains run logs that shows the complexity and number of solutions of the generated raw procedures.
* `Programs`: contains the resulted concrete raw procedures.

## Remark

Note that the generating of initial values for neutral words can be done simultaneously for many values of Gray cells such that the amortized complexity can be small. Thus, in the system of equations for the some attacks (e.g., Figures 18, 20, 22), some Gray cells that should have been set as known variables are relaxed such that the initial values of neutral bytes under all possible values of these Gray cells can be generated altogether. In these cases, the raw results generated by the Automatic-tool should be further manually adjusted. Concretely, a table should be built to store the solutions with the value of the relaxed Gray cells as the index.

## References

[1] Zhenzhen Bao, Jian Guo, Danping Shi, and Yi Tu. Superposition Meet-in-the-Middle Attacks: Updates on Fundamental Security of AES-like Hashing. Cryptology ePrint Archive, Report 2021/575, 2021. https://eprint.iacr.org/2021/575

[2] Charles Bouillaguet, Patrick Derbez, Pierre-Alain Fouque.: Automatic Search of Attacks on Round-Reduced AES and Applications. In CRYPTO 2011. [Online Automatic-tool] https://www-almasty.lip6.fr/~bouillaguet/static/attacks/AES-tool.tar.gz


