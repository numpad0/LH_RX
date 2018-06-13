// SteamVR 1.0 tracking code written using https://github.com/ashtuchkin/vive-diy-position-sensor
// + observations

// Author: @numpad0 2018

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  // wait for 1500us continuous low

  // enter SYNC_WAIT

  // ///////// LH RX SLOT 1                                       -    0 -  400us window
  // trigger on rise edge - LH_1    -    0us mark
  // set LH_1_RISE

  // trigger on fall edge - LH_1             mark + 65-135us
  // calculate and set LH_1_OOTX[skip, data, axis]

  // ///////// LH RX SLOT 2                                       -  400 -  800us window
  // trigger on rise edge - LH_2    -  400us mark
  // set LH_2_RISE

  // trigger on fall edge - LH_2             mark + 65-135us
  // calculate and set LH_2_OOTX[skip, data, axis]

  // ///////// LH RX SLOT 3                                       -  800 - 1200us window
  // trigger on rise edge - LH_3  -  800us mark
  // set LH_3_RISE

  // trigger on fall edge - LH_3           mark + 65-135us  
  // calculate and set LH_3_OOTX[skip, data, axis]

  // Following may occur:
  //     LH 1 LH 2 LH 3
  // A|   0    0    0
  // B|   0    0    1
  // C|   0    1    1 
  // D|   0    1    0
  // E|   1    1    0
  // F|   1    1    1
  // G|   1    0    1
  // H|   1    0    0

  // Following is valid: E, H
  // E: 
  //   Assume LH 1 = LH_B
  //   Assume LH 2 = LH_C
  //   System should enter LASER SWEEP at T+1222us
  //   set BIH_EXT = true(norm)

  // H: 
  //   Assume LH 1 = LH_C
  //   Assume LH 2 = LH_NONE
  //   System should enter LASER SWEEP at T+ 822us
  //   set BIH_EXT = false(recovery)

  // Following is invalid: A, B, C, D, F, G
  // System should return to WATCH state

  // wait for BUILT IN HOLD EXPIRE  -  822us mark
  // if BIH_LEN = false:                     mark +   0us
  // if BIH_LEN = true :                     mark + 400us

  // start of LASER SWEEP           - 1222us mark

  // wait for rise edge   - LASER

  // end of LASER SWEEP             - 6777us mark

  // pose calculation
  // data transmission

  // end of LOOP                    - 8333us mark
  //                                         mark - 400us = 7933us
  
}

int ootx(int ootx_length){
  //      skip   data   axis   time     delta
  // j0    0      0      0      62.5     ---
  // k0    0      0      1      72.9    +10.4
  // j1    0      1      0      83.3    +10.4
  // k1    0      1      1      93.8    +10.5
  // j2    1      0      0     104      +10.2
  // k2    1      0      1     115      +11
  // j3    1      1      0     125      +10
  // k3    1      1      1     135      +10

}

void pose_calculation(void){
  // collect:
  //   for sensor in sensors:
  //     sensor(LH_B_H)
  //     sensor(LH_B_V)
  //     sensor(LH_C_H)
  //     sensor(LH_C_V)
  // collect:
  //   imu_pose();  
}

void data_transmission(void){
  
}

