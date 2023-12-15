	.include "MPlayDef.s"

	.equ	song58_grp, voicegroup030
	.equ	song58_pri, 10
	.equ	song58_rev, 128
	.equ	song58_mvl, 127
	.equ	song58_key, 0
	.equ	song58_tbs, 1
	.equ	song58_exg, 0
	.equ	song58_cmp, 1

	.section .rodata
	.global	song58
	.align	2


@**************** Track 1 (Midi-Chn.0) ****************@

song58_001:
@  #01 @000   ----------------------------------------
 .byte   KEYSH , song58_key+0
 .byte   TEMPO , 150*song58_tbs/2
 .byte   VOICE , 1
 .byte   VOL , 53*song58_mvl/mxv
 .byte   PAN , c_v-8
 .byte   VOL , 120*song58_mvl/mxv
 .byte   PAN , c_v-7
 .byte   BEND , c_v+0
 .byte   TIE ,Ds3 ,v048
 .byte   TIE ,As3
 .byte   W01
 .byte   PAN , c_v-6
 .byte   W01
 .byte   PAN , c_v-4
 .byte   W01
 .byte   PAN , c_v-3
 .byte   W01
 .byte   PAN , c_v-2
 .byte   W01
 .byte   PAN , c_v-1
 .byte   W01
 .byte   PAN , c_v+1
 .byte   W01
 .byte   PAN , c_v+2
 .byte   W01
 .byte   PAN , c_v+3
 .byte   W01
 .byte   PAN , c_v+4
 .byte   W01
 .byte   PAN , c_v+6
 .byte   W01
 .byte   PAN , c_v+7
 .byte   W01
 .byte   PAN , c_v+8
 .byte   W01
 .byte   PAN , c_v+9
 .byte   W01
 .byte   PAN , c_v+11
 .byte   W01
 .byte   PAN , c_v+12
 .byte   W01
 .byte   PAN , c_v+13
 .byte   W01
 .byte   PAN , c_v+14
 .byte   W01
 .byte   PAN , c_v+16
 .byte   W01
 .byte   PAN , c_v+17
 .byte   W01
 .byte   PAN , c_v+18
 .byte   W01
 .byte   PAN , c_v+19
 .byte   W01
 .byte   PAN , c_v+21
 .byte   W01
 .byte   PAN , c_v+22
 .byte   W01
 .byte   PAN , c_v+23
 .byte   W01
 .byte   PAN , c_v+24
 .byte   W01
 .byte   PAN , c_v+26
 .byte   W01
 .byte   PAN , c_v+27
 .byte   W01
 .byte   PAN , c_v+28
 .byte   W01
 .byte   PAN , c_v+29
 .byte   W01
 .byte   PAN , c_v+31
 .byte   W01
 .byte   PAN , c_v+32
 .byte   W01
 .byte   PAN , c_v+33
 .byte   W01
 .byte   PAN , c_v+34
 .byte   W01
 .byte   PAN , c_v+36
 .byte   W01
 .byte   PAN , c_v+37
 .byte   W01
 .byte   PAN , c_v+38
 .byte   W01
 .byte   PAN , c_v+39
 .byte   W01
 .byte   PAN , c_v+41
 .byte   W01
 .byte   PAN , c_v+42
 .byte   W01
 .byte   PAN , c_v+43
 .byte   W01
 .byte   PAN , c_v+44
 .byte   W01
 .byte   PAN , c_v+46
 .byte   W01
 .byte   PAN , c_v+47
 .byte   W01
 .byte   PAN , c_v+48
 .byte   W01
 .byte   PAN , c_v+49
 .byte   W01
 .byte   VOL , 120*song58_mvl/mxv
 .byte   PAN , c_v+50
 .byte   VOL , 105*song58_mvl/mxv
 .byte   PAN , c_v+51
 .byte   BEND , c_v+0
 .byte   W01
 .byte   VOL , 91*song58_mvl/mxv
 .byte   PAN , c_v+52
 .byte   VOL , 84*song58_mvl/mxv
 .byte   BEND , c_v-64
 .byte   W01
 .byte   VOL , 77*song58_mvl/mxv
 .byte   PAN , c_v+53
 .byte   VOL , 69*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 58*song58_mvl/mxv
 .byte   PAN , c_v+54
 .byte   VOL , 66*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+55
 .byte   VOL , 74*song58_mvl/mxv
 .byte   PAN , c_v+56
 .byte   W01
 .byte   VOL , 83*song58_mvl/mxv
 .byte   PAN , c_v+57
 .byte   VOL , 86*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 90*song58_mvl/mxv
 .byte   PAN , c_v+58
 .byte   VOL , 99*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+59
 .byte   VOL , 107*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+60
 .byte   VOL , 120*song58_mvl/mxv
 .byte   PAN , c_v+59
 .byte   W01
 .byte   PAN , c_v+58
 .byte   W01
 .byte   PAN , c_v+57
 .byte   W01
 .byte   PAN , c_v+56
 .byte   W01
 .byte   PAN , c_v+54
 .byte   W01
 .byte   PAN , c_v+53
 .byte   W01
 .byte   PAN , c_v+52
 .byte   W01
 .byte   PAN , c_v+51
 .byte   W01
 .byte   PAN , c_v+49
 .byte   W01
 .byte   PAN , c_v+48
 .byte   W01
 .byte   PAN , c_v+47
 .byte   W01
 .byte   PAN , c_v+46
 .byte   W01
 .byte   PAN , c_v+44
 .byte   W01
 .byte   PAN , c_v+43
 .byte   W01
 .byte   PAN , c_v+42
 .byte   W01
 .byte   PAN , c_v+41
 .byte   W01
 .byte   PAN , c_v+39
 .byte   W01
 .byte   PAN , c_v+38
 .byte   W01
 .byte   PAN , c_v+37
 .byte   W01
 .byte   PAN , c_v+36
 .byte   W01
 .byte   PAN , c_v+34
 .byte   W01
 .byte   PAN , c_v+33
 .byte   W01
 .byte   PAN , c_v+32
 .byte   W01
 .byte   PAN , c_v+31
 .byte   W01
 .byte   PAN , c_v+29
 .byte   W01
 .byte   PAN , c_v+28
 .byte   W01
 .byte   PAN , c_v+27
 .byte   W01
 .byte   PAN , c_v+26
 .byte   W01
 .byte   PAN , c_v+24
 .byte   W01
 .byte   PAN , c_v+23
 .byte   W01
 .byte   PAN , c_v+22
 .byte   W01
 .byte   PAN , c_v+21
 .byte   W01
 .byte   PAN , c_v+19
 .byte   W01
 .byte   PAN , c_v+18
 .byte   W01
 .byte   PAN , c_v+17
 .byte   W01
 .byte   PAN , c_v+16
 .byte   W01
 .byte   PAN , c_v+14
 .byte   W01
 .byte   PAN , c_v+13
 .byte   W01
 .byte   PAN , c_v+12
 .byte   W01
 .byte   PAN , c_v+11
 .byte   W01
 .byte   PAN , c_v+9
 .byte   W01
 .byte   PAN , c_v+8
 .byte   W01
@  #01 @001   ----------------------------------------
 .byte   PAN , c_v+7
 .byte   W01
 .byte   PAN , c_v+6
 .byte   W01
 .byte   PAN , c_v+4
 .byte   W01
 .byte   PAN , c_v+3
 .byte   W01
 .byte   PAN , c_v+2
 .byte   W01
 .byte   PAN , c_v+1
 .byte   W01
 .byte   PAN , c_v-1
 .byte   W01
 .byte   PAN , c_v-2
 .byte   W01
 .byte   PAN , c_v-3
 .byte   W01
 .byte   PAN , c_v-4
 .byte   W01
 .byte   PAN , c_v-6
 .byte   W01
 .byte   PAN , c_v-7
 .byte   W01
 .byte   PAN , c_v-8
 .byte   W01
 .byte   PAN , c_v-9
 .byte   W01
 .byte   PAN , c_v-11
 .byte   W01
 .byte   PAN , c_v-12
 .byte   W01
 .byte   PAN , c_v-13
 .byte   W01
 .byte   PAN , c_v-14
 .byte   W01
 .byte   PAN , c_v-16
 .byte   W01
 .byte   PAN , c_v-17
 .byte   W01
 .byte   PAN , c_v-18
 .byte   W01
 .byte   PAN , c_v-19
 .byte   W01
 .byte   PAN , c_v-21
 .byte   W01
 .byte   PAN , c_v-22
 .byte   W01
 .byte   PAN , c_v-23
 .byte   W01
 .byte   PAN , c_v-24
 .byte   W01
 .byte   PAN , c_v-26
 .byte   W01
 .byte   PAN , c_v-27
 .byte   W01
 .byte   PAN , c_v-28
 .byte   W01
 .byte   PAN , c_v-29
 .byte   W01
 .byte   PAN , c_v-31
 .byte   W01
 .byte   PAN , c_v-32
 .byte   W01
 .byte   PAN , c_v-33
 .byte   W01
 .byte   PAN , c_v-34
 .byte   W01
 .byte   PAN , c_v-36
 .byte   W01
 .byte   PAN , c_v-37
 .byte   W01
 .byte   PAN , c_v-38
 .byte   W01
 .byte   PAN , c_v-39
 .byte   W01
 .byte   PAN , c_v-41
 .byte   W01
 .byte   PAN , c_v-42
 .byte   W01
 .byte   PAN , c_v-43
 .byte   W01
 .byte   PAN , c_v-44
 .byte   W01
 .byte   PAN , c_v-46
 .byte   W01
 .byte   PAN , c_v-47
 .byte   W01
 .byte   PAN , c_v-48
 .byte   W01
 .byte   PAN , c_v-49
 .byte   W01
 .byte   PAN , c_v-51
 .byte   W01
 .byte   PAN , c_v-52
 .byte   W01
 .byte   PAN , c_v-53
 .byte   W01
 .byte   PAN , c_v-54
 .byte   W01
 .byte   PAN , c_v-56
 .byte   W01
 .byte   PAN , c_v-57
 .byte   W01
 .byte   PAN , c_v-58
 .byte   W01
 .byte   PAN , c_v-59
 .byte   W01
 .byte   VOL , 120*song58_mvl/mxv
 .byte   PAN , c_v-60
 .byte   W01
 .byte   PAN , c_v-59
 .byte   VOL , 119*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-58
 .byte   VOL , 118*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-57
 .byte   VOL , 117*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-56
 .byte   VOL , 116*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-55
 .byte   VOL , 115*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-54
 .byte   VOL , 114*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-53
 .byte   VOL , 113*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-52
 .byte   VOL , 112*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-51
 .byte   VOL , 111*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-50
 .byte   VOL , 110*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-49
 .byte   VOL , 109*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-48
 .byte   VOL , 107*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-47
 .byte   VOL , 106*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-46
 .byte   VOL , 105*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-45
 .byte   VOL , 104*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-44
 .byte   VOL , 103*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-43
 .byte   VOL , 102*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-42
 .byte   VOL , 102*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-41
 .byte   VOL , 101*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-40
 .byte   VOL , 100*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-39
 .byte   VOL , 99*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-38
 .byte   VOL , 98*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-37
 .byte   VOL , 97*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-36
 .byte   VOL , 95*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-35
 .byte   VOL , 94*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-34
 .byte   VOL , 93*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-33
 .byte   VOL , 92*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-32
 .byte   VOL , 91*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-31
 .byte   VOL , 90*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-30
 .byte   VOL , 89*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-29
 .byte   VOL , 88*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-28
 .byte   VOL , 87*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-27
 .byte   VOL , 86*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-26
 .byte   VOL , 85*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-25
 .byte   VOL , 85*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-24
 .byte   VOL , 84*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 83*song58_mvl/mxv
 .byte   PAN , c_v-23
 .byte   VOL , 82*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-22
 .byte   VOL , 81*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-21
 .byte   VOL , 80*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-20
 .byte   VOL , 79*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-19
 .byte   VOL , 78*song58_mvl/mxv
 .byte   W01
@  #01 @002   ----------------------------------------
 .byte   PAN , c_v-18
 .byte   VOL , 77*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-17
 .byte   VOL , 76*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-16
 .byte   W01
 .byte   PAN , c_v-15
 .byte   VOL , 75*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-14
 .byte   VOL , 74*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-13
 .byte   VOL , 73*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-12
 .byte   VOL , 72*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-11
 .byte   VOL , 70*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-10
 .byte   VOL , 69*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-9
 .byte   VOL , 68*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-8
 .byte   VOL , 68*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-7
 .byte   VOL , 67*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-6
 .byte   VOL , 66*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-5
 .byte   VOL , 65*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-4
 .byte   VOL , 64*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-3
 .byte   VOL , 63*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-2
 .byte   VOL , 62*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-1
 .byte   VOL , 61*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+0
 .byte   VOL , 60*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+1
 .byte   VOL , 58*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+2
 .byte   VOL , 57*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+3
 .byte   VOL , 56*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+4
 .byte   VOL , 55*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+5
 .byte   VOL , 54*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+6
 .byte   VOL , 53*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+7
 .byte   VOL , 52*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+8
 .byte   VOL , 51*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+9
 .byte   VOL , 51*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+10
 .byte   VOL , 50*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+11
 .byte   VOL , 49*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+12
 .byte   VOL , 48*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+13
 .byte   VOL , 47*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 46*song58_mvl/mxv
 .byte   PAN , c_v+14
 .byte   VOL , 45*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+15
 .byte   VOL , 44*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+16
 .byte   VOL , 43*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+17
 .byte   VOL , 42*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+18
 .byte   VOL , 41*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+19
 .byte   VOL , 40*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+20
 .byte   VOL , 39*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+21
 .byte   VOL , 38*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+22
 .byte   VOL , 37*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+23
 .byte   VOL , 36*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+24
 .byte   VOL , 35*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+25
 .byte   VOL , 34*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+26
 .byte   VOL , 33*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+27
 .byte   VOL , 32*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+28
 .byte   W01
 .byte   PAN , c_v+29
 .byte   VOL , 31*song58_mvl/mxv
 .byte   W01
 .byte   EOT
 .byte   Ds3 ,v070
 .byte   PAN , c_v+30
 .byte   VOL , 30*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+31
 .byte   VOL , 29*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+32
 .byte   VOL , 28*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+33
 .byte   VOL , 27*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+34
 .byte   VOL , 26*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+35
 .byte   VOL , 25*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+36
 .byte   VOL , 24*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+37
 .byte   VOL , 23*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+38
 .byte   VOL , 21*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+39
 .byte   VOL , 20*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+40
 .byte   VOL , 19*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+41
 .byte   VOL , 18*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+42
 .byte   VOL , 17*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+43
 .byte   VOL , 17*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+44
 .byte   VOL , 16*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+45
 .byte   VOL , 15*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+46
 .byte   VOL , 14*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+47
 .byte   VOL , 13*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+48
 .byte   VOL , 12*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+49
 .byte   VOL , 11*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+50
 .byte   VOL , 10*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 9*song58_mvl/mxv
 .byte   PAN , c_v+51
 .byte   VOL , 8*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+52
 .byte   VOL , 7*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+53
 .byte   VOL , 6*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+54
 .byte   VOL , 5*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+55
 .byte   VOL , 4*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+56
 .byte   VOL , 3*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+57
 .byte   VOL , 2*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+58
 .byte   VOL , 1*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+59
 .byte   VOL , 0*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 0*song58_mvl/mxv
 .byte   PAN , c_v+59
 .byte   W01
 .byte   PAN , c_v+58
 .byte   W01
 .byte   PAN , c_v+57
 .byte   W01
 .byte   PAN , c_v+56
 .byte   W01
 .byte   PAN , c_v+54
 .byte   W01
 .byte   PAN , c_v+53
 .byte   W01
 .byte   PAN , c_v+52
 .byte   W01
 .byte   PAN , c_v+51
 .byte   W01
 .byte   PAN , c_v+49
 .byte   W01
 .byte   PAN , c_v+48
 .byte   W01
 .byte   PAN , c_v+47
 .byte   W01
 .byte   PAN , c_v+46
 .byte   W01
 .byte   PAN , c_v+44
 .byte   W01
 .byte   PAN , c_v+43
 .byte   W01
 .byte   PAN , c_v+42
 .byte   W01
 .byte   PAN , c_v+41
 .byte   W01
 .byte   PAN , c_v+39
 .byte   W01
 .byte   PAN , c_v+38
 .byte   W01
@  #01 @003   ----------------------------------------
 .byte   PAN , c_v+37
 .byte   W01
 .byte   PAN , c_v+36
 .byte   W01
 .byte   PAN , c_v+34
 .byte   W01
 .byte   PAN , c_v+33
 .byte   W01
 .byte   PAN , c_v+32
 .byte   W01
 .byte   PAN , c_v+31
 .byte   W01
 .byte   PAN , c_v+29
 .byte   W01
 .byte   PAN , c_v+28
 .byte   W01
 .byte   PAN , c_v+27
 .byte   W01
 .byte   PAN , c_v+26
 .byte   W01
 .byte   PAN , c_v+24
 .byte   W01
 .byte   PAN , c_v+23
 .byte   W01
 .byte   PAN , c_v+22
 .byte   W01
 .byte   PAN , c_v+21
 .byte   W01
 .byte   PAN , c_v+19
 .byte   W01
 .byte   PAN , c_v+18
 .byte   W01
 .byte   PAN , c_v+17
 .byte   W01
 .byte   PAN , c_v+16
 .byte   W01
 .byte   PAN , c_v+14
 .byte   W01
 .byte   PAN , c_v+13
 .byte   W01
 .byte   PAN , c_v+12
 .byte   W01
 .byte   PAN , c_v+11
 .byte   W01
 .byte   PAN , c_v+9
 .byte   W01
 .byte   PAN , c_v+8
 .byte   FINE

@**************** Track 2 (Midi-Chn.1) ****************@

song58_002:
@  #02 @000   ----------------------------------------
 .byte   KEYSH , song58_key+0
 .byte   VOICE , 1
 .byte   VOL , 120*song58_mvl/mxv
 .byte   PAN , c_v+7
 .byte   BEND , c_v+4
 .byte   TIE ,Ds3 ,v048
 .byte   TIE ,As3
 .byte   W01
 .byte   PAN , c_v+6
 .byte   W01
 .byte   PAN , c_v+4
 .byte   W01
 .byte   PAN , c_v+3
 .byte   W01
 .byte   PAN , c_v+2
 .byte   W01
 .byte   PAN , c_v+1
 .byte   W01
 .byte   PAN , c_v-1
 .byte   W01
 .byte   PAN , c_v-2
 .byte   W01
 .byte   PAN , c_v-3
 .byte   W01
 .byte   PAN , c_v-4
 .byte   W01
 .byte   PAN , c_v-6
 .byte   W01
 .byte   PAN , c_v-7
 .byte   W01
 .byte   PAN , c_v-8
 .byte   W01
 .byte   PAN , c_v-9
 .byte   W01
 .byte   PAN , c_v-11
 .byte   W01
 .byte   PAN , c_v-12
 .byte   W01
 .byte   PAN , c_v-13
 .byte   W01
 .byte   PAN , c_v-14
 .byte   W01
 .byte   PAN , c_v-16
 .byte   W01
 .byte   PAN , c_v-17
 .byte   W01
 .byte   PAN , c_v-18
 .byte   W01
 .byte   PAN , c_v-19
 .byte   W01
 .byte   PAN , c_v-21
 .byte   W01
 .byte   PAN , c_v-22
 .byte   W01
 .byte   PAN , c_v-23
 .byte   W01
 .byte   PAN , c_v-24
 .byte   W01
 .byte   PAN , c_v-26
 .byte   W01
 .byte   PAN , c_v-27
 .byte   W01
 .byte   PAN , c_v-28
 .byte   W01
 .byte   PAN , c_v-29
 .byte   W01
 .byte   PAN , c_v-31
 .byte   W01
 .byte   PAN , c_v-32
 .byte   W01
 .byte   PAN , c_v-33
 .byte   W01
 .byte   PAN , c_v-34
 .byte   W01
 .byte   PAN , c_v-36
 .byte   W01
 .byte   PAN , c_v-37
 .byte   W01
 .byte   PAN , c_v-38
 .byte   W01
 .byte   PAN , c_v-39
 .byte   W01
 .byte   PAN , c_v-41
 .byte   W01
 .byte   PAN , c_v-42
 .byte   W01
 .byte   PAN , c_v-43
 .byte   W01
 .byte   PAN , c_v-44
 .byte   W01
 .byte   PAN , c_v-46
 .byte   W01
 .byte   PAN , c_v-47
 .byte   W01
 .byte   VOL , 120*song58_mvl/mxv
 .byte   PAN , c_v-48
 .byte   VOL , 112*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 103*song58_mvl/mxv
 .byte   PAN , c_v-49
 .byte   VOL , 87*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-50
 .byte   VOL , 70*song58_mvl/mxv
 .byte   PAN , c_v-51
 .byte   BEND , c_v-64
 .byte   W01
 .byte   VOL , 50*song58_mvl/mxv
 .byte   PAN , c_v-52
 .byte   VOL , 53*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 58*song58_mvl/mxv
 .byte   PAN , c_v-53
 .byte   VOL , 63*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 68*song58_mvl/mxv
 .byte   PAN , c_v-54
 .byte   VOL , 77*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-55
 .byte   VOL , 86*song58_mvl/mxv
 .byte   PAN , c_v-56
 .byte   VOL , 91*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 96*song58_mvl/mxv
 .byte   PAN , c_v-57
 .byte   VOL , 101*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 105*song58_mvl/mxv
 .byte   PAN , c_v-58
 .byte   VOL , 115*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 120*song58_mvl/mxv
 .byte   PAN , c_v-59
 .byte   W01
 .byte   PAN , c_v-59
 .byte   W01
 .byte   PAN , c_v-58
 .byte   W01
 .byte   PAN , c_v-57
 .byte   W01
 .byte   PAN , c_v-56
 .byte   W01
 .byte   PAN , c_v-54
 .byte   W01
 .byte   PAN , c_v-53
 .byte   W01
 .byte   PAN , c_v-52
 .byte   W01
 .byte   PAN , c_v-51
 .byte   W01
 .byte   PAN , c_v-49
 .byte   W01
 .byte   PAN , c_v-48
 .byte   W01
 .byte   PAN , c_v-47
 .byte   W01
 .byte   PAN , c_v-46
 .byte   W01
 .byte   PAN , c_v-44
 .byte   W01
 .byte   PAN , c_v-43
 .byte   W01
 .byte   PAN , c_v-42
 .byte   W01
 .byte   PAN , c_v-41
 .byte   W01
 .byte   PAN , c_v-39
 .byte   W01
 .byte   PAN , c_v-38
 .byte   W01
 .byte   PAN , c_v-37
 .byte   W01
 .byte   PAN , c_v-36
 .byte   W01
 .byte   PAN , c_v-34
 .byte   W01
 .byte   PAN , c_v-33
 .byte   W01
 .byte   PAN , c_v-32
 .byte   W01
 .byte   PAN , c_v-31
 .byte   W01
 .byte   PAN , c_v-29
 .byte   W01
 .byte   PAN , c_v-28
 .byte   W01
 .byte   PAN , c_v-27
 .byte   W01
 .byte   PAN , c_v-26
 .byte   W01
 .byte   PAN , c_v-24
 .byte   W01
 .byte   PAN , c_v-23
 .byte   W01
 .byte   PAN , c_v-22
 .byte   W01
 .byte   PAN , c_v-21
 .byte   W01
 .byte   PAN , c_v-19
 .byte   W01
 .byte   PAN , c_v-18
 .byte   W01
 .byte   PAN , c_v-17
 .byte   W01
 .byte   PAN , c_v-16
 .byte   W01
 .byte   PAN , c_v-14
 .byte   W01
 .byte   PAN , c_v-13
 .byte   W01
 .byte   PAN , c_v-12
 .byte   W01
 .byte   PAN , c_v-11
 .byte   W01
 .byte   PAN , c_v-9
 .byte   W01
 .byte   PAN , c_v-8
 .byte   W01
@  #02 @001   ----------------------------------------
 .byte   PAN , c_v-7
 .byte   W01
 .byte   PAN , c_v-6
 .byte   W01
 .byte   PAN , c_v-4
 .byte   W01
 .byte   PAN , c_v-3
 .byte   W01
 .byte   PAN , c_v-2
 .byte   W01
 .byte   PAN , c_v-1
 .byte   W01
 .byte   PAN , c_v+1
 .byte   W01
 .byte   PAN , c_v+2
 .byte   W01
 .byte   PAN , c_v+3
 .byte   W01
 .byte   PAN , c_v+4
 .byte   W01
 .byte   PAN , c_v+6
 .byte   W01
 .byte   PAN , c_v+7
 .byte   W01
 .byte   PAN , c_v+8
 .byte   W01
 .byte   PAN , c_v+9
 .byte   W01
 .byte   PAN , c_v+11
 .byte   W01
 .byte   PAN , c_v+12
 .byte   W01
 .byte   PAN , c_v+13
 .byte   W01
 .byte   PAN , c_v+14
 .byte   W01
 .byte   PAN , c_v+16
 .byte   W01
 .byte   PAN , c_v+17
 .byte   W01
 .byte   PAN , c_v+18
 .byte   W01
 .byte   PAN , c_v+19
 .byte   W01
 .byte   PAN , c_v+21
 .byte   W01
 .byte   PAN , c_v+22
 .byte   W01
 .byte   PAN , c_v+23
 .byte   W01
 .byte   PAN , c_v+24
 .byte   W01
 .byte   PAN , c_v+26
 .byte   W01
 .byte   PAN , c_v+27
 .byte   W01
 .byte   PAN , c_v+28
 .byte   W01
 .byte   PAN , c_v+29
 .byte   W01
 .byte   PAN , c_v+31
 .byte   W01
 .byte   PAN , c_v+32
 .byte   W01
 .byte   PAN , c_v+33
 .byte   W01
 .byte   PAN , c_v+34
 .byte   W01
 .byte   PAN , c_v+36
 .byte   W01
 .byte   PAN , c_v+37
 .byte   W01
 .byte   PAN , c_v+38
 .byte   W01
 .byte   PAN , c_v+39
 .byte   W01
 .byte   PAN , c_v+41
 .byte   W01
 .byte   PAN , c_v+42
 .byte   W01
 .byte   PAN , c_v+43
 .byte   W01
 .byte   PAN , c_v+44
 .byte   W01
 .byte   PAN , c_v+46
 .byte   W01
 .byte   PAN , c_v+47
 .byte   W01
 .byte   PAN , c_v+48
 .byte   W01
 .byte   PAN , c_v+49
 .byte   W01
 .byte   PAN , c_v+51
 .byte   W01
 .byte   PAN , c_v+52
 .byte   W01
 .byte   PAN , c_v+53
 .byte   W01
 .byte   PAN , c_v+54
 .byte   W01
 .byte   PAN , c_v+56
 .byte   W01
 .byte   PAN , c_v+57
 .byte   W01
 .byte   PAN , c_v+58
 .byte   W01
 .byte   PAN , c_v+59
 .byte   W01
 .byte   VOL , 120*song58_mvl/mxv
 .byte   PAN , c_v+59
 .byte   W01
 .byte   PAN , c_v+58
 .byte   VOL , 119*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+57
 .byte   VOL , 118*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+56
 .byte   VOL , 117*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+55
 .byte   VOL , 116*song58_mvl/mxv
 .byte   PAN , c_v+54
 .byte   W01
 .byte   VOL , 115*song58_mvl/mxv
 .byte   PAN , c_v+53
 .byte   W01
 .byte   PAN , c_v+52
 .byte   VOL , 114*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+51
 .byte   VOL , 113*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+50
 .byte   VOL , 112*song58_mvl/mxv
 .byte   PAN , c_v+49
 .byte   W01
 .byte   VOL , 111*song58_mvl/mxv
 .byte   PAN , c_v+48
 .byte   W01
 .byte   VOL , 110*song58_mvl/mxv
 .byte   PAN , c_v+47
 .byte   W01
 .byte   VOL , 109*song58_mvl/mxv
 .byte   PAN , c_v+46
 .byte   W01
 .byte   PAN , c_v+45
 .byte   VOL , 108*song58_mvl/mxv
 .byte   PAN , c_v+44
 .byte   VOL , 107*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+43
 .byte   VOL , 106*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+42
 .byte   VOL , 105*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+41
 .byte   VOL , 104*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+40
 .byte   VOL , 103*song58_mvl/mxv
 .byte   PAN , c_v+39
 .byte   W01
 .byte   VOL , 102*song58_mvl/mxv
 .byte   PAN , c_v+38
 .byte   W01
 .byte   PAN , c_v+37
 .byte   VOL , 102*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+36
 .byte   VOL , 101*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+35
 .byte   VOL , 100*song58_mvl/mxv
 .byte   PAN , c_v+34
 .byte   W01
 .byte   VOL , 99*song58_mvl/mxv
 .byte   PAN , c_v+33
 .byte   W01
 .byte   VOL , 98*song58_mvl/mxv
 .byte   PAN , c_v+32
 .byte   W01
 .byte   VOL , 97*song58_mvl/mxv
 .byte   PAN , c_v+31
 .byte   W01
 .byte   PAN , c_v+30
 .byte   VOL , 96*song58_mvl/mxv
 .byte   PAN , c_v+29
 .byte   VOL , 95*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+28
 .byte   VOL , 94*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+27
 .byte   VOL , 93*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+26
 .byte   VOL , 92*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+25
 .byte   VOL , 91*song58_mvl/mxv
 .byte   PAN , c_v+24
 .byte   W01
 .byte   VOL , 90*song58_mvl/mxv
 .byte   PAN , c_v+23
 .byte   W01
 .byte   PAN , c_v+22
 .byte   VOL , 89*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+21
 .byte   VOL , 88*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+20
 .byte   VOL , 87*song58_mvl/mxv
 .byte   PAN , c_v+19
 .byte   W01
 .byte   VOL , 86*song58_mvl/mxv
 .byte   PAN , c_v+18
 .byte   W01
 .byte   VOL , 85*song58_mvl/mxv
 .byte   PAN , c_v+17
 .byte   W01
 .byte   VOL , 85*song58_mvl/mxv
 .byte   PAN , c_v+16
 .byte   W01
 .byte   PAN , c_v+15
 .byte   VOL , 84*song58_mvl/mxv
 .byte   PAN , c_v+14
 .byte   W01
 .byte   VOL , 83*song58_mvl/mxv
 .byte   PAN , c_v+13
 .byte   VOL , 82*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+12
 .byte   VOL , 81*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+11
 .byte   VOL , 80*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+10
 .byte   VOL , 79*song58_mvl/mxv
 .byte   PAN , c_v+9
 .byte   W01
 .byte   PAN , c_v+8
 .byte   VOL , 78*song58_mvl/mxv
 .byte   W01
@  #02 @002   ----------------------------------------
 .byte   PAN , c_v+7
 .byte   VOL , 77*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+6
 .byte   VOL , 76*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v+4
 .byte   W01
 .byte   VOL , 75*song58_mvl/mxv
 .byte   PAN , c_v+3
 .byte   W01
 .byte   VOL , 74*song58_mvl/mxv
 .byte   PAN , c_v+2
 .byte   W01
 .byte   VOL , 73*song58_mvl/mxv
 .byte   PAN , c_v+1
 .byte   W01
 .byte   PAN , c_v+0
 .byte   VOL , 72*song58_mvl/mxv
 .byte   PAN , c_v-1
 .byte   W01
 .byte   VOL , 71*song58_mvl/mxv
 .byte   PAN , c_v-2
 .byte   VOL , 70*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-3
 .byte   VOL , 69*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-4
 .byte   VOL , 68*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-5
 .byte   VOL , 68*song58_mvl/mxv
 .byte   PAN , c_v-6
 .byte   W01
 .byte   PAN , c_v-7
 .byte   VOL , 67*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-8
 .byte   VOL , 66*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-9
 .byte   VOL , 65*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-10
 .byte   VOL , 64*song58_mvl/mxv
 .byte   PAN , c_v-11
 .byte   W01
 .byte   VOL , 63*song58_mvl/mxv
 .byte   PAN , c_v-12
 .byte   W01
 .byte   VOL , 62*song58_mvl/mxv
 .byte   PAN , c_v-13
 .byte   W01
 .byte   VOL , 61*song58_mvl/mxv
 .byte   PAN , c_v-14
 .byte   W01
 .byte   PAN , c_v-15
 .byte   VOL , 60*song58_mvl/mxv
 .byte   PAN , c_v-16
 .byte   W01
 .byte   VOL , 59*song58_mvl/mxv
 .byte   PAN , c_v-17
 .byte   VOL , 58*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-18
 .byte   VOL , 57*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-19
 .byte   VOL , 56*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-20
 .byte   VOL , 55*song58_mvl/mxv
 .byte   PAN , c_v-21
 .byte   W01
 .byte   PAN , c_v-22
 .byte   VOL , 54*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-23
 .byte   VOL , 53*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-24
 .byte   VOL , 52*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-25
 .byte   VOL , 51*song58_mvl/mxv
 .byte   PAN , c_v-26
 .byte   W01
 .byte   VOL , 51*song58_mvl/mxv
 .byte   PAN , c_v-27
 .byte   W01
 .byte   VOL , 50*song58_mvl/mxv
 .byte   PAN , c_v-28
 .byte   W01
 .byte   PAN , c_v-29
 .byte   VOL , 49*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-30
 .byte   VOL , 48*song58_mvl/mxv
 .byte   PAN , c_v-31
 .byte   W01
 .byte   VOL , 47*song58_mvl/mxv
 .byte   PAN , c_v-32
 .byte   W01
 .byte   VOL , 46*song58_mvl/mxv
 .byte   PAN , c_v-33
 .byte   VOL , 45*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-34
 .byte   VOL , 44*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-35
 .byte   VOL , 43*song58_mvl/mxv
 .byte   PAN , c_v-36
 .byte   W01
 .byte   PAN , c_v-37
 .byte   VOL , 42*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-38
 .byte   VOL , 41*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-39
 .byte   VOL , 40*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-40
 .byte   VOL , 39*song58_mvl/mxv
 .byte   PAN , c_v-41
 .byte   W01
 .byte   VOL , 38*song58_mvl/mxv
 .byte   PAN , c_v-42
 .byte   W01
 .byte   VOL , 37*song58_mvl/mxv
 .byte   PAN , c_v-43
 .byte   W01
 .byte   PAN , c_v-44
 .byte   VOL , 36*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-45
 .byte   VOL , 35*song58_mvl/mxv
 .byte   PAN , c_v-46
 .byte   W01
 .byte   VOL , 34*song58_mvl/mxv
 .byte   PAN , c_v-47
 .byte   W01
 .byte   VOL , 34*song58_mvl/mxv
 .byte   PAN , c_v-48
 .byte   VOL , 33*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-49
 .byte   VOL , 32*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-51
 .byte   W01
 .byte   PAN , c_v-52
 .byte   VOL , 31*song58_mvl/mxv
 .byte   W01
 .byte   EOT
 .byte   Ds3 ,v070
 .byte   PAN , c_v-53
 .byte   VOL , 30*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-54
 .byte   VOL , 29*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-55
 .byte   VOL , 28*song58_mvl/mxv
 .byte   PAN , c_v-56
 .byte   W01
 .byte   VOL , 27*song58_mvl/mxv
 .byte   PAN , c_v-57
 .byte   W01
 .byte   VOL , 26*song58_mvl/mxv
 .byte   PAN , c_v-58
 .byte   W01
 .byte   PAN , c_v-59
 .byte   VOL , 25*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-60
 .byte   VOL , 24*song58_mvl/mxv
 .byte   PAN , c_v-59
 .byte   W01
 .byte   VOL , 23*song58_mvl/mxv
 .byte   PAN , c_v-58
 .byte   W01
 .byte   VOL , 22*song58_mvl/mxv
 .byte   PAN , c_v-57
 .byte   VOL , 21*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-56
 .byte   VOL , 20*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-54
 .byte   VOL , 19*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-53
 .byte   VOL , 18*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-52
 .byte   VOL , 17*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-51
 .byte   VOL , 17*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-50
 .byte   VOL , 16*song58_mvl/mxv
 .byte   PAN , c_v-49
 .byte   W01
 .byte   VOL , 15*song58_mvl/mxv
 .byte   PAN , c_v-48
 .byte   W01
 .byte   VOL , 14*song58_mvl/mxv
 .byte   PAN , c_v-47
 .byte   W01
 .byte   PAN , c_v-46
 .byte   VOL , 13*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-45
 .byte   VOL , 12*song58_mvl/mxv
 .byte   PAN , c_v-44
 .byte   W01
 .byte   VOL , 11*song58_mvl/mxv
 .byte   PAN , c_v-43
 .byte   W01
 .byte   VOL , 10*song58_mvl/mxv
 .byte   PAN , c_v-42
 .byte   W01
 .byte   VOL , 9*song58_mvl/mxv
 .byte   PAN , c_v-41
 .byte   VOL , 8*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-39
 .byte   VOL , 7*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-38
 .byte   VOL , 6*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-37
 .byte   VOL , 5*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-36
 .byte   VOL , 4*song58_mvl/mxv
 .byte   W01
 .byte   PAN , c_v-35
 .byte   VOL , 3*song58_mvl/mxv
 .byte   PAN , c_v-34
 .byte   W01
 .byte   VOL , 2*song58_mvl/mxv
 .byte   PAN , c_v-33
 .byte   W01
 .byte   VOL , 1*song58_mvl/mxv
 .byte   PAN , c_v-32
 .byte   W01
 .byte   PAN , c_v-31
 .byte   VOL , 0*song58_mvl/mxv
 .byte   W01
 .byte   VOL , 0*song58_mvl/mxv
 .byte   PAN , c_v-29
 .byte   W01
 .byte   PAN , c_v-28
 .byte   W01
 .byte   PAN , c_v-27
 .byte   W01
 .byte   PAN , c_v-26
 .byte   W01
 .byte   PAN , c_v-24
 .byte   W01
 .byte   PAN , c_v-23
 .byte   W01
 .byte   PAN , c_v-22
 .byte   W01
 .byte   PAN , c_v-21
 .byte   W01
 .byte   PAN , c_v-19
 .byte   W01
 .byte   PAN , c_v-18
 .byte   W01
 .byte   PAN , c_v-17
 .byte   W01
 .byte   PAN , c_v-16
 .byte   W01
 .byte   PAN , c_v-14
 .byte   W01
 .byte   PAN , c_v-13
 .byte   W01
 .byte   PAN , c_v-12
 .byte   W01
 .byte   PAN , c_v-11
 .byte   W01
 .byte   PAN , c_v-9
 .byte   W01
 .byte   PAN , c_v-8
 .byte   W01
@  #02 @003   ----------------------------------------
 .byte   PAN , c_v-7
 .byte   W01
 .byte   PAN , c_v-6
 .byte   W01
 .byte   PAN , c_v-4
 .byte   W01
 .byte   PAN , c_v-3
 .byte   W01
 .byte   PAN , c_v-2
 .byte   W01
 .byte   PAN , c_v-1
 .byte   W01
 .byte   PAN , c_v+1
 .byte   W01
 .byte   PAN , c_v+2
 .byte   W01
 .byte   PAN , c_v+3
 .byte   W01
 .byte   PAN , c_v+4
 .byte   W01
 .byte   PAN , c_v+6
 .byte   W01
 .byte   PAN , c_v+7
 .byte   W01
 .byte   PAN , c_v+8
 .byte   W01
 .byte   PAN , c_v+9
 .byte   W01
 .byte   PAN , c_v+11
 .byte   W01
 .byte   PAN , c_v+12
 .byte   W01
 .byte   PAN , c_v+13
 .byte   W01
 .byte   PAN , c_v+14
 .byte   W01
 .byte   PAN , c_v+16
 .byte   W01
 .byte   PAN , c_v+17
 .byte   W01
 .byte   PAN , c_v+18
 .byte   W01
 .byte   PAN , c_v+19
 .byte   W01
 .byte   PAN , c_v+21
 .byte   W01
 .byte   PAN , c_v+22
 .byte   FINE

@******************************************************@
	.align	2

song58:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song58_pri	@ Priority
	.byte	song58_rev	@ Reverb.
    
	.word	song58_grp
    
	.word	song58_001
	.word	song58_002

	.end
