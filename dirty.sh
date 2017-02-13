#!/bin/bash 

R1=5
G1=13
B1=6
R2=12
G2=16
B2=23

OE=4
CLK=17
LAT=21

A=22
B=26
C=27
D=20

ALL="$R1 $G1 $B1 $R2 $G2 $B2 $OE $CLK $LAT $A $B $C $D"


function gwrite() {
	gpio -g write $1 $2
}


function set_modes() {
	for p in $ALL; do
		gpio -g mode $p OUT
	done
}

function grand_address() {
	gwrite $A $((1 - $(gpio -g read $A)))
	gwrite $B $((1 - $(gpio -g read $B)))
	gwrite $C 0
	gwrite $D 0
}

function grand_color() {
	gwrite $R1 $((RANDOM % 2))
	gwrite $G1 0
	gwrite $B1 $((RANDOM % 2))
}

function ginit() {
	set_modes
	gwrite $CLK 0
	gwrite $OE 0
	grand_address
}


ginit 

while true; do

	for i in {1..4}; do
		grand_color

		gwrite $CLK 1
		gwrite $CLK 0
	done

	gwrite $LAT 1
	gwrite $LAT 0
	grand_address
done

