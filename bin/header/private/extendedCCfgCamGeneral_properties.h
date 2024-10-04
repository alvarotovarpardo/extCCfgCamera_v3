	SimpleCrypt *crypto;
	EnumConfigConnectionMode m_eConfigConnectionMode;
	char m_szConnectionChain[CONFIG_MAX_PATH + 1];
	char m_szDescription[50];
	char m_szSerialNumber[CONFIG_MAX_PATH + 1];
	char m_szLicense[CONFIG_MAX_PATH + 1];
	int m_iFps;
	int m_iFpsShow;
	int m_iMatWidth;
	int m_iMatHeight;
	int m_iMatType;
	int m_iBuffMaxLengh;
	int m_iTimeSendFps;
	int m_iLeftCutout;
	int m_iRightCutout;
	int m_iTopCutout;
	int m_iBottomCutout;
	EnumConfigCameraType m_eConfigCameraType;
	EnumConfigSensorType m_eConfigSensorType;
	bool m_bShowCurrentFrame;
	bool m_bShowSimulateName;
	bool m_bEnableAll;
	int m_iMatMetaDataLeft;
	int m_iMatMetaDataRight;
	char m_szCameraModelName[20];
	char m_szCameraHierarchy[20];
	QByteArray m_baPartNumber;
	double m_dMediaTemp;
	double m_dIFOV;
	double m_dOffsetIfov_x;
	double m_dOffsetIfov_y;
	double m_dFocalLength;
	double m_dPixelPitch;
	double m_dDistParameterK1;
	double m_dDistParameterK2;
	double m_dDistParameterK3;
	std::vector<double> vGlobalTemp;
	bool m_bCCTVAccessControl;
	char m_szCCTVUsername[50];
	char m_szCCTVPassword[50];
	char m_sGeolocation[100];
	
	unsigned char m_ucDataBits;
	unsigned char m_ucModeConvert2_8To16;
	unsigned short m_usDivConvert2_8To16;
	unsigned short m_usAndConvert2_8To16;
	int m_iInvertValues;
	
	/*Mileva parameters*/
	bool m_bAutomaticGain;
	int m_iMaxPixSaturated;
	int m_iAutoGainInterval;
	int m_iGain;
	int m_iDiodeBias;
	int m_iIntegrationTime;
	int m_iIntegrationData;
	
	/*Pico & ATTO parameters*/
	int m_iParamGFID;
	int m_iParamGSK;
	int m_iParamVSK;
	int m_iParamVBUS;
	int m_iParamGain;
	int m_iParamTInt;
	
	bool m_bHasLaser;
	int m_iLaserCOM;
	EnumConfigLaserType m_eConfigLaserType;
	int m_iPortThirdPartyOnvif;
	int m_iPortThirdPartyHttp;
	int m_iPortThirdPartyRtsp;
	int m_iFramesSecondRtsp;
	bool m_bRTSPAccessControl;
	char m_szRTSPUsername[50];
	char m_szRTSPPassword[50];
	bool m_bPaletteRtsp;
	bool m_bValuesRtsp;
	
	bool m_bVerticalFlip;
	bool m_bHorizontalFlip;
	bool m_bImageRotate;
	bool m_bPaletteBar;
	bool m_bStretching;
	bool m_bAutoStretching;
	bool m_bShowROI;
	bool m_bShowNOROI;
	bool m_bShowDigitalLevels;
	bool m_bShowSaturatedPixels;
	double m_dCamEmissivity;
	double m_dCamGain;
	double m_dCamOffset;
	bool m_bEmailAlert;
	bool m_bShowWindowTest;
	bool m_bWeightingFactors;
	bool m_bCameraRepeatedFrames;
	
	int m_iReconnectionWait;
	int m_iReconnectionAttemps;
	int m_iSkip;
	int m_iMean;
	
	char m_szConnectionPhidget[CONFIG_MAX_IP + 1];
	int m_iRelayPort;
	int m_iStepperPort;
	int m_iSensorPort;
	int m_iShutterMaxPos;
	int m_iShutterMinPos;
	
	bool m_bHasShutter;
	int m_iNucSecondsBetweenAutomatic;
	int m_iSecondsDelayClosedshutterImgnuc;
	bool m_bPanAndTilt;
	int m_iPanAndTiltCom;
	int m_iPanAndTiltID;
	int m_iPanAndTiltSpeed;
	bool m_bPanAndTiltPelcoD;
	bool m_bPanInverted;
	bool m_bTiltInverted;
	char m_szTourActiveAutomatic[CFG_MAX_SMALL_ID + 1];
	char m_szPresetActiveAutomatic[CFG_MAX_SMALL_ID + 1];
	bool m_bAutomaticRaw;
	bool m_bAutomaticRLK;
	bool m_bAutomaticMP4;
	bool m_bHasSensorLens;
	bool m_bHasPleoraExpansor;
	bool m_bHasMemorySPI;
	bool m_bHasCompass;
	
	bool m_bAdamRelay;
	bool m_bPulseRelay;
	char m_szAdamRelayIP[CONFIG_MAX_PATH + 1];
	int m_iAdamRelayPort m_iMaxOperationTemperature;
	int m_iAdamRelayPort m_iPulseRelaySeconds;
	
	bool m_bSwitchPOE;
	char m_szSwitchIP[CONFIG_MAX_PATH + 1];
	int m_iSwitchInterface;
	
	/* Variables para el reset automático de cámaras */
	bool m_bAutoResetEnabled;
	bool m_bResetPeriodicEnabled;
	bool m_bResetPunctualEnabled;
	char m_szResetUnits[20];
	int m_iResetUnitsValue;
	char m_szResetDateTime[50];
	char m_szResetPeriodicDateTime[50];
	
	bool m_bCloseShutter;
	bool m_bFPSWarnings;
	bool m_bSensiaNUC;
	
	int m_iCurrentPreset;
	int m_iCurrentTour;
	
	bool m_bMaintenanceMode;
	char m_szCameraBand[CONFIG_MAX_PATH + 1];
	
	/* Smart camera periodic cleaner */
	int m_iPeriodicUnitsValue;
	char m_szPeriodicUnits[50];
	char m_szPeriodicDeleteAtTime[50];
	char m_szNextCheckTime[50];
	bool m_bPeriodicPunctual;
	bool m_bPeriodicRepeat;
	bool m_bPeriodicDeleteAt;
	bool m_bPeriodicDeleteAtActive;
	
	bool m_bIsDummy;

	/*##################################################
	  ################## Distributed ###################
	  ##################################################*/

	int m_iFocalLength;
	int m_iPixelPitch;
	bool m_bStretchingRegion;
	int m_iRegionSize;
	/* Preset limits */
	int m_iPTLimitTiltTop;
	int m_iPTLimitTiltBottom;
	int m_iPTLimitPanLeft;
	int m_iPTLimitPanRight;

	/*##################################################
	  ################## Analytics ###################
	  ##################################################*/

	EnumConfigCameraMode m_eConfigCameraMode;
	char m_sFuel[20];
	bool m_bElectronicOld;
	char m_szPlaybackSpeed[20];
	bool m_bEmailSendAll;
	char m_szEmail[50];
	char m_szEmailCC[640];
	bool m_bHasSensorTemperature;
	char m_szResetUnits[10];
	/* Variables de RIO */
	double m_dThresholdCO;
	double m_dThresholdNOx;
	double m_dThresholdHC;
	double m_dThresholdOpacity;
	bool m_bDumpCO2;
	bool m_bDumpCO;
	bool m_bDumpNOx;
	bool m_bDumpHC;
	bool m_bDumpOpacity;
	double m_dTHLocalMinCO2;
	double m_dTHLocalMinCO;
	double m_dTHLocalMinHC;
	double m_dTHLocalMinNOx;
	double m_dTHLocalMinOpacity;
	double m_dWaitTime;
	double m_dAbsorbanceCO2;
	double m_dAbsorbanceCO;
	double m_dAbsorbanceHC;
	double m_dAbsorbanceNOx;
	double m_dAbsorbanceOpacity;
	int m_iVariationThreshold;
	int m_iKernelCO2;
	int m_iKernelCO;
	int m_iKernelHC;
	int m_iKernelNOx;
	int m_iKernelOpacity;
	int m_iOffset;
	int m_iOCRPort;
	bool m_bOCR;
	/* Variables para GreenCPorts */
	char m_szUnits[50];
	char m_szTarjetGas[50];
	double m_dCorrectionFactor;
	char m_szOpticalSize[50];
	char m_szSensitivity[50];
	double m_dLambda1;
	double m_dLambda2;
	bool m_bGasAbsorption;
	bool m_bGasEmission;
	bool m_bEdgeRemove;

	/*##################################################
	  ###################### Lite ######################
	  ##################################################*/

	int m_iTamVectorData;
	int m_iSizeClaheSkip;
	int m_iSizeClaheEnhanced;
	int m_iSizeClahe;
	int m_iWindowSize;
	double m_dClipClaheSkip;
	double m_dClipClaheEnhanced;
	double m_dClipClahe;
	double m_dMinFlowRateLimit;
	double m_dMaxFlowRateLimit;
	float m_fFactorMeanPond;
	int m_iTFrame;
	char m_sDeviceSerialNumber [50];
	double m_iLeakDistance;
	double m_dAmbientTemperature;
	int m_iHR;
	double m_dGasTemperature;
	double m_dGasDensity;
	char m_szDistanceUnits[50];
	char m_szDensityUnits[50];
	char m_szTemperatureUnits[50];
