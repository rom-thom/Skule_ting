  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_lab2_P)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_P.Joystick_gain_x
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_P.Joystick_gain_y
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_lab2_P.elev_ref
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_P.HILWriteAnalog_channels
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 45;
      section.data(45)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_P.HILInitialize_OOTerminate
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_P.HILInitialize_OOExit
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_lab2_P.HILInitialize_OOStart
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_lab2_P.HILInitialize_OOEnter
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOFinal
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_lab2_P.HILInitialize_POFinal
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_lab2_P.HILInitialize_AIHigh
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_lab2_P.HILInitialize_AILow
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOHigh
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOLow
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOInitial
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOWatchdog
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_lab2_P.HILInitialize_POFrequency
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_lab2_P.HILInitialize_POLeading
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_lab2_P.HILInitialize_POTrailing
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_lab2_P.HILInitialize_POInitial
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_lab2_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_lab2_P.Constant4_Value
	  section.data(18).logicalSrcIdx = 21;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_lab2_P.Gain2_Gain
	  section.data(19).logicalSrcIdx = 22;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_lab2_P.ElevationCounttorad_Gain
	  section.data(20).logicalSrcIdx = 23;
	  section.data(20).dtTransOffset = 27;
	
	  ;% heli_q8_lab2_P.Gain1_Gain
	  section.data(21).logicalSrcIdx = 24;
	  section.data(21).dtTransOffset = 28;
	
	  ;% heli_q8_lab2_P.PitchCounttorad_Gain
	  section.data(22).logicalSrcIdx = 25;
	  section.data(22).dtTransOffset = 37;
	
	  ;% heli_q8_lab2_P.PitchTransferFcn_A
	  section.data(23).logicalSrcIdx = 26;
	  section.data(23).dtTransOffset = 38;
	
	  ;% heli_q8_lab2_P.PitchTransferFcn_C
	  section.data(24).logicalSrcIdx = 27;
	  section.data(24).dtTransOffset = 39;
	
	  ;% heli_q8_lab2_P.PitchTransferFcn_D
	  section.data(25).logicalSrcIdx = 28;
	  section.data(25).dtTransOffset = 40;
	
	  ;% heli_q8_lab2_P.TravelCounttorad_Gain
	  section.data(26).logicalSrcIdx = 29;
	  section.data(26).dtTransOffset = 41;
	
	  ;% heli_q8_lab2_P.TravelTransferFcn_A
	  section.data(27).logicalSrcIdx = 30;
	  section.data(27).dtTransOffset = 42;
	
	  ;% heli_q8_lab2_P.TravelTransferFcn_C
	  section.data(28).logicalSrcIdx = 31;
	  section.data(28).dtTransOffset = 43;
	
	  ;% heli_q8_lab2_P.TravelTransferFcn_D
	  section.data(29).logicalSrcIdx = 32;
	  section.data(29).dtTransOffset = 44;
	
	  ;% heli_q8_lab2_P.ElevationTransferFcn_A
	  section.data(30).logicalSrcIdx = 33;
	  section.data(30).dtTransOffset = 45;
	
	  ;% heli_q8_lab2_P.ElevationTransferFcn_C
	  section.data(31).logicalSrcIdx = 34;
	  section.data(31).dtTransOffset = 46;
	
	  ;% heli_q8_lab2_P.ElevationTransferFcn_D
	  section.data(32).logicalSrcIdx = 35;
	  section.data(32).dtTransOffset = 47;
	
	  ;% heli_q8_lab2_P.RateTransitiony_InitialConditio
	  section.data(33).logicalSrcIdx = 36;
	  section.data(33).dtTransOffset = 48;
	
	  ;% heli_q8_lab2_P.DeadZoney_Start
	  section.data(34).logicalSrcIdx = 37;
	  section.data(34).dtTransOffset = 49;
	
	  ;% heli_q8_lab2_P.DeadZoney_End
	  section.data(35).logicalSrcIdx = 38;
	  section.data(35).dtTransOffset = 50;
	
	  ;% heli_q8_lab2_P.Gainy_Gain
	  section.data(36).logicalSrcIdx = 39;
	  section.data(36).dtTransOffset = 51;
	
	  ;% heli_q8_lab2_P.Gain_Gain
	  section.data(37).logicalSrcIdx = 40;
	  section.data(37).dtTransOffset = 52;
	
	  ;% heli_q8_lab2_P.RateTransitionx_InitialConditio
	  section.data(38).logicalSrcIdx = 41;
	  section.data(38).dtTransOffset = 53;
	
	  ;% heli_q8_lab2_P.DeadZonex_Start
	  section.data(39).logicalSrcIdx = 42;
	  section.data(39).dtTransOffset = 54;
	
	  ;% heli_q8_lab2_P.DeadZonex_End
	  section.data(40).logicalSrcIdx = 43;
	  section.data(40).dtTransOffset = 55;
	
	  ;% heli_q8_lab2_P.Gainx_Gain
	  section.data(41).logicalSrcIdx = 44;
	  section.data(41).dtTransOffset = 56;
	
	  ;% heli_q8_lab2_P.FrontmotorSaturation_UpperSat
	  section.data(42).logicalSrcIdx = 45;
	  section.data(42).dtTransOffset = 57;
	
	  ;% heli_q8_lab2_P.FrontmotorSaturation_LowerSat
	  section.data(43).logicalSrcIdx = 46;
	  section.data(43).dtTransOffset = 58;
	
	  ;% heli_q8_lab2_P.BackmotorSaturation_UpperSat
	  section.data(44).logicalSrcIdx = 47;
	  section.data(44).dtTransOffset = 59;
	
	  ;% heli_q8_lab2_P.BackmotorSaturation_LowerSat
	  section.data(45).logicalSrcIdx = 48;
	  section.data(45).dtTransOffset = 60;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 50;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_lab2_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 51;
	  section.data(3).dtTransOffset = 4;
	
	  ;% heli_q8_lab2_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 52;
	  section.data(4).dtTransOffset = 5;
	
	  ;% heli_q8_lab2_P.HILInitialize_POConfiguration
	  section.data(5).logicalSrcIdx = 53;
	  section.data(5).dtTransOffset = 6;
	
	  ;% heli_q8_lab2_P.HILInitialize_POAlignment
	  section.data(6).logicalSrcIdx = 54;
	  section.data(6).dtTransOffset = 7;
	
	  ;% heli_q8_lab2_P.HILInitialize_POPolarity
	  section.data(7).logicalSrcIdx = 55;
	  section.data(7).dtTransOffset = 8;
	
	  ;% heli_q8_lab2_P.HILReadEncoderTimebase_Clock
	  section.data(8).logicalSrcIdx = 56;
	  section.data(8).dtTransOffset = 9;
	
	  ;% heli_q8_lab2_P.StreamCall2_SendBufferSize
	  section.data(9).logicalSrcIdx = 57;
	  section.data(9).dtTransOffset = 10;
	
	  ;% heli_q8_lab2_P.StreamCall2_ReceiveBufferSize
	  section.data(10).logicalSrcIdx = 58;
	  section.data(10).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_P.UnitDelay_InitialCondition
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_P.UnitDelay_InitialCondition_m
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_lab2_P.UnitDelay_InitialCondition_b
	  section.data(3).logicalSrcIdx = 61;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_lab2_P.UnitDelay_InitialCondition_h
	  section.data(4).logicalSrcIdx = 62;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_lab2_P.UnitDelay_InitialCondition_n
	  section.data(5).logicalSrcIdx = 63;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_lab2_P.UnitDelay_InitialCondition_b3
	  section.data(6).logicalSrcIdx = 64;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_P.StreamFormattedRead_MaxUnits
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_P.HILInitialize_AIChannels
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOChannels
	  section.data(3).logicalSrcIdx = 67;
	  section.data(3).dtTransOffset = 9;
	
	  ;% heli_q8_lab2_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 68;
	  section.data(4).dtTransOffset = 17;
	
	  ;% heli_q8_lab2_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 69;
	  section.data(5).dtTransOffset = 25;
	
	  ;% heli_q8_lab2_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 70;
	  section.data(6).dtTransOffset = 26;
	
	  ;% heli_q8_lab2_P.HILReadEncoderTimebase_Channels
	  section.data(7).logicalSrcIdx = 71;
	  section.data(7).dtTransOffset = 34;
	
	  ;% heli_q8_lab2_P.HILReadEncoderTimebase_SamplesI
	  section.data(8).logicalSrcIdx = 72;
	  section.data(8).dtTransOffset = 37;
	
	  ;% heli_q8_lab2_P.StreamFormattedRead1_MaxUnits
	  section.data(9).logicalSrcIdx = 73;
	  section.data(9).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 76;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 77;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_lab2_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 78;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_lab2_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 79;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_lab2_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 80;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_lab2_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 81;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_lab2_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 82;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_lab2_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 83;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_lab2_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 84;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_lab2_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 85;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_lab2_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 86;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_lab2_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 87;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 88;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 89;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 90;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 91;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_lab2_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 92;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_lab2_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 93;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_lab2_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 94;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_lab2_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 95;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_q8_lab2_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 96;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_q8_lab2_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 97;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_q8_lab2_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 98;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_q8_lab2_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 99;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_q8_lab2_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 100;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_q8_lab2_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 101;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_q8_lab2_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 102;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_q8_lab2_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 103;
	  section.data(29).dtTransOffset = 28;
	
	  ;% heli_q8_lab2_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 104;
	  section.data(30).dtTransOffset = 29;
	
	  ;% heli_q8_lab2_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 105;
	  section.data(31).dtTransOffset = 30;
	
	  ;% heli_q8_lab2_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 106;
	  section.data(32).dtTransOffset = 31;
	
	  ;% heli_q8_lab2_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 107;
	  section.data(33).dtTransOffset = 32;
	
	  ;% heli_q8_lab2_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 108;
	  section.data(34).dtTransOffset = 33;
	
	  ;% heli_q8_lab2_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 109;
	  section.data(35).dtTransOffset = 34;
	
	  ;% heli_q8_lab2_P.HILReadEncoderTimebase_Active
	  section.data(36).logicalSrcIdx = 110;
	  section.data(36).dtTransOffset = 35;
	
	  ;% heli_q8_lab2_P.StreamCall2_NonBlocking
	  section.data(37).logicalSrcIdx = 111;
	  section.data(37).dtTransOffset = 36;
	
	  ;% heli_q8_lab2_P.StreamCall2_Active
	  section.data(38).logicalSrcIdx = 112;
	  section.data(38).dtTransOffset = 37;
	
	  ;% heli_q8_lab2_P.HILWriteAnalog_Active
	  section.data(39).logicalSrcIdx = 113;
	  section.data(39).dtTransOffset = 38;
	
	  ;% heli_q8_lab2_P.GameController_AutoCenter
	  section.data(40).logicalSrcIdx = 114;
	  section.data(40).dtTransOffset = 39;
	
	  ;% heli_q8_lab2_P.GameController_Enabled
	  section.data(41).logicalSrcIdx = 115;
	  section.data(41).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_P.HILReadEncoderTimebase_Overflow
	  section.data(1).logicalSrcIdx = 116;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_P.StringConstant1_Value
	  section.data(2).logicalSrcIdx = 117;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_lab2_P.StreamCall2_URI
	  section.data(3).logicalSrcIdx = 118;
	  section.data(3).dtTransOffset = 256;
	
	  ;% heli_q8_lab2_P.StreamCall2_Endian
	  section.data(4).logicalSrcIdx = 119;
	  section.data(4).dtTransOffset = 257;
	
	  ;% heli_q8_lab2_P.GameController_ControllerNumber
	  section.data(5).logicalSrcIdx = 120;
	  section.data(5).dtTransOffset = 258;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_lab2_B)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_B.DataTypeConversion1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_B.Gain2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_lab2_B.ElevationCounttorad
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% heli_q8_lab2_B.Sum1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% heli_q8_lab2_B.DataTypeConversion2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% heli_q8_lab2_B.Gain1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 11;
	
	  ;% heli_q8_lab2_B.PitchCounttorad
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 14;
	
	  ;% heli_q8_lab2_B.PitchTransferFcn
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 15;
	
	  ;% heli_q8_lab2_B.TravelCounttorad
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 16;
	
	  ;% heli_q8_lab2_B.TravelTransferFcn
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 17;
	
	  ;% heli_q8_lab2_B.ElevationTransferFcn
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 18;
	
	  ;% heli_q8_lab2_B.RateTransitiony
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 19;
	
	  ;% heli_q8_lab2_B.Joystick_gain_y
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 20;
	
	  ;% heli_q8_lab2_B.Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 21;
	
	  ;% heli_q8_lab2_B.RateTransitionx
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 22;
	
	  ;% heli_q8_lab2_B.Joystick_gain_x
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 23;
	
	  ;% heli_q8_lab2_B.euler_rates
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_B.StreamFormattedRead1_o2
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_B.StreamFormattedRead1_o3
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_lab2_B.StreamFormattedRead1_o4
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_lab2_B.StreamFormattedRead1_o5
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_lab2_B.StreamFormattedRead1_o6
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_lab2_B.StreamFormattedRead1_o7
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_lab2_B.UnitDelay
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_lab2_B.UnitDelay_b
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_lab2_B.UnitDelay_e
	  section.data(9).logicalSrcIdx = 25;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_lab2_B.UnitDelay_m
	  section.data(10).logicalSrcIdx = 26;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_lab2_B.UnitDelay_n
	  section.data(11).logicalSrcIdx = 27;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_lab2_B.UnitDelay_i
	  section.data(12).logicalSrcIdx = 28;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_B.StreamCall2_o2
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_B.StreamFormattedRead1_o10
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_B.StreamFormattedRead1_o11
	  section.data(2).logicalSrcIdx = 31;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_lab2_B.RelationalOperator
	  section.data(3).logicalSrcIdx = 32;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_lab2_B.RelationalOperator_b
	  section.data(4).logicalSrcIdx = 33;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_lab2_B.RelationalOperator_i
	  section.data(5).logicalSrcIdx = 34;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_lab2_B.RelationalOperator_f
	  section.data(6).logicalSrcIdx = 35;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_lab2_B.RelationalOperator_j
	  section.data(7).logicalSrcIdx = 36;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_lab2_B.RelationalOperator_p
	  section.data(8).logicalSrcIdx = 37;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 12;
    sectIdxOffset = 4;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_lab2_DW)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_lab2_DW.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_lab2_DW.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% heli_q8_lab2_DW.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% heli_q8_lab2_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% heli_q8_lab2_DW.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% heli_q8_lab2_DW.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
	  ;% heli_q8_lab2_DW.RateTransitiony_Buffer0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
	  ;% heli_q8_lab2_DW.RateTransitionx_Buffer0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 65;
	
	  ;% heli_q8_lab2_DW.HILWriteAnalog_Buffer
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 66;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_DW.StreamCall2_Stream
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_DW.GameController_Controller
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 36;
      section.data(36)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_DW.Accelerometer_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_DW.Elevation_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_lab2_DW.P_dot_samm_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 4;
	
	  ;% heli_q8_lab2_DW.Pitch_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 5;
	
	  ;% heli_q8_lab2_DW.ToFile_PWORK.FilePtr
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 6;
	
	  ;% heli_q8_lab2_DW.e_dotrefrads_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 7;
	
	  ;% heli_q8_lab2_DW.e_dot_samm_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 8;
	
	  ;% heli_q8_lab2_DW.elevationrate_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 22;
	  section.data(8).dtTransOffset = 9;
	
	  ;% heli_q8_lab2_DW.gyroskop_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 23;
	  section.data(9).dtTransOffset = 10;
	
	  ;% heli_q8_lab2_DW.p_refrad_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 24;
	  section.data(10).dtTransOffset = 13;
	
	  ;% heli_q8_lab2_DW.pitchrate_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 25;
	  section.data(11).dtTransOffset = 14;
	
	  ;% heli_q8_lab2_DW.travelrate_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 26;
	  section.data(12).dtTransOffset = 15;
	
	  ;% heli_q8_lab2_DW.ElevationScoperads_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 27;
	  section.data(13).dtTransOffset = 16;
	
	  ;% heli_q8_lab2_DW.ElevationScoperad_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 28;
	  section.data(14).dtTransOffset = 17;
	
	  ;% heli_q8_lab2_DW.PitchScoperad_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 29;
	  section.data(15).dtTransOffset = 18;
	
	  ;% heli_q8_lab2_DW.PtichrateScoperads_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 30;
	  section.data(16).dtTransOffset = 19;
	
	  ;% heli_q8_lab2_DW.TravelrateScoperads_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 31;
	  section.data(17).dtTransOffset = 20;
	
	  ;% heli_q8_lab2_DW.TravelScoperad_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 32;
	  section.data(18).dtTransOffset = 21;
	
	  ;% heli_q8_lab2_DW.HILWriteAnalog_PWORK
	  section.data(19).logicalSrcIdx = 33;
	  section.data(19).dtTransOffset = 22;
	
	  ;% heli_q8_lab2_DW.Closed_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 34;
	  section.data(20).dtTransOffset = 23;
	
	  ;% heli_q8_lab2_DW.Connected2_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 35;
	  section.data(21).dtTransOffset = 24;
	
	  ;% heli_q8_lab2_DW.Scope_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 36;
	  section.data(22).dtTransOffset = 25;
	
	  ;% heli_q8_lab2_DW.ax_PWORK.LoggedData
	  section.data(23).logicalSrcIdx = 37;
	  section.data(23).dtTransOffset = 31;
	
	  ;% heli_q8_lab2_DW.ay_PWORK.LoggedData
	  section.data(24).logicalSrcIdx = 38;
	  section.data(24).dtTransOffset = 32;
	
	  ;% heli_q8_lab2_DW.az_PWORK.LoggedData
	  section.data(25).logicalSrcIdx = 39;
	  section.data(25).dtTransOffset = 33;
	
	  ;% heli_q8_lab2_DW.wx_PWORK.LoggedData
	  section.data(26).logicalSrcIdx = 40;
	  section.data(26).dtTransOffset = 34;
	
	  ;% heli_q8_lab2_DW.wy_PWORK.LoggedData
	  section.data(27).logicalSrcIdx = 41;
	  section.data(27).dtTransOffset = 35;
	
	  ;% heli_q8_lab2_DW.wz_PWORK.LoggedData
	  section.data(28).logicalSrcIdx = 42;
	  section.data(28).dtTransOffset = 36;
	
	  ;% heli_q8_lab2_DW.Scope_PWORK_i.LoggedData
	  section.data(29).logicalSrcIdx = 43;
	  section.data(29).dtTransOffset = 37;
	
	  ;% heli_q8_lab2_DW.Scope_PWORK_o.LoggedData
	  section.data(30).logicalSrcIdx = 44;
	  section.data(30).dtTransOffset = 39;
	
	  ;% heli_q8_lab2_DW.Scope_PWORK_e.LoggedData
	  section.data(31).logicalSrcIdx = 45;
	  section.data(31).dtTransOffset = 41;
	
	  ;% heli_q8_lab2_DW.Scope_PWORK_oq.LoggedData
	  section.data(32).logicalSrcIdx = 46;
	  section.data(32).dtTransOffset = 43;
	
	  ;% heli_q8_lab2_DW.Scope_PWORK_l.LoggedData
	  section.data(33).logicalSrcIdx = 47;
	  section.data(33).dtTransOffset = 45;
	
	  ;% heli_q8_lab2_DW.Scope_PWORK_f.LoggedData
	  section.data(34).logicalSrcIdx = 48;
	  section.data(34).dtTransOffset = 47;
	
	  ;% heli_q8_lab2_DW.XScope_PWORK.LoggedData
	  section.data(35).logicalSrcIdx = 49;
	  section.data(35).dtTransOffset = 49;
	
	  ;% heli_q8_lab2_DW.YScope_PWORK.LoggedData
	  section.data(36).logicalSrcIdx = 50;
	  section.data(36).dtTransOffset = 50;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_DW.UnitDelay_DSTATE_d
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_lab2_DW.UnitDelay_DSTATE_i
	  section.data(3).logicalSrcIdx = 53;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_lab2_DW.UnitDelay_DSTATE_g
	  section.data(4).logicalSrcIdx = 54;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_lab2_DW.UnitDelay_DSTATE_l
	  section.data(5).logicalSrcIdx = 55;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_lab2_DW.UnitDelay_DSTATE_ge
	  section.data(6).logicalSrcIdx = 56;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_lab2_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_lab2_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 59;
	  section.data(3).dtTransOffset = 11;
	
	  ;% heli_q8_lab2_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 60;
	  section.data(4).dtTransOffset = 19;
	
	  ;% heli_q8_lab2_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 61;
	  section.data(5).dtTransOffset = 27;
	
	  ;% heli_q8_lab2_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 62;
	  section.data(6).dtTransOffset = 35;
	
	  ;% heli_q8_lab2_DW.HILReadEncoderTimebase_Buffer
	  section.data(7).logicalSrcIdx = 63;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_DW.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_DW.Skiptonextline_SubsysRanBC
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_lab2_DW.StreamCall2_State
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2334391513;
  targMap.checksum1 = 2413185907;
  targMap.checksum2 = 2098024924;
  targMap.checksum3 = 580278344;

