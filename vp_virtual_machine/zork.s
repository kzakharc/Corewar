.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:liv, %1
		and r1, %0, r1

liv:	live %1
		zjmp %:liv
