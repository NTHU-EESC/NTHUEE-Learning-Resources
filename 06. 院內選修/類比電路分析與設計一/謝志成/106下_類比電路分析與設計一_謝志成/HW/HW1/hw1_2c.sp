hw1_2c
.protect
.lib 'cic018.l' TT
.unprotect
.temp 25
.option post 
.param W=20u L=0.2u vd=1.8 vss=0 in=0.370

M3 Vout Vin vss vss N_18 W=20u L=0.2u m=20

Vdd vdd 0 vd
Vss vss 0 vss
Vin vin 0 in
Rd Vdd Vout 10K 

*.dc in 0 1.8 0.001
.tf v(vout) vin
.probe DC V("lx18(M1)")

.end

