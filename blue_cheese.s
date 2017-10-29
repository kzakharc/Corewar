.name "blue waffle"
.comment "Don't google it!"

start:
	ld %0, r2
	live %666
	lfork %1000
	live %666
	lfork %2000
	live %666
	lfork %3000
	live %666
	lfork %500
	live %42
	lfork %:stis
	live %42
	lfork %:l1
	ld %0, r2
	zjmp %:start

stis:
	sti r1, %:l1, %1
	sti r1, %:l2, %1
	sti r1, %:l3, %1
	sti r1, %:l4, %1
	sti r1, %:l5, %1
	sti r1, %:l6, %1
	sti r1, %:l7, %1
	sti r1, %:l8, %1
	sti r1, %:l9, %1
	sti r1, %:l10, %1
	sti r1, %:l11, %1
	sti r1, %:l12, %1
	sti r1, %:l13, %1
	sti r1, %:l14, %1
	sti r1, %:l15, %1
	sti r1, %:l16, %1
	sti r1, %:l17, %1
	sti r1, %:l18, %1
	sti r1, %:l19, %1
	sti r1, %:l20, %1
	sti r1, %:l21, %1
	sti r1, %:l22, %1
	sti r1, %:l23, %1
	sti r1, %:l24, %1

l1:	 	live %42
l2:	 	live %42
l3:	 	live %42
l4:	 	live %42
l5:	 	live %42
l6:	 	live %42
l7:	 	live %42
l8:	 	live %42
l9:	 	live %42
l10: 	live %42
l11:	live %42
l12:	live %42
l13:	live %42
l14:	live %42
l15:	live %42
l16:	live %42
l17:	live %42
l18:	live %42
l19:	live %42
l20:	live %42
l21:	live %42
l22:	live %42
l23:	live %42
l24:	live %42

