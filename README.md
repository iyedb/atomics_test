# atomics_test
The Make file have the following target:

show-mor: launches tkdiff with main.s and main-mor.s to show the difference in the assembler generated by load/store memory_order_seq_cst
and load/store memory_order_relaxed.

show-relacq: launches tkdiff with main.s and main-relacq.s to show the difference in the assembler generated by load/store memory_order_seq_cst
and load/store memory_order_relesae/acquire.

show-relacq-mor: launches tkdiff with main-mor.s and main-relacq.s to show the difference in the assembler generated by load/store memory_order_relaxed
and load/store memory_order_relesae/acquire.


