void CCfgCamGeneral::initDefault()
{
    //Clase de cifrado
    crypto = new SimpleCrypt(Q_UINT64_C(0x0c2ad4a4acb9f023));

    STRCPY(m_szDescription, "");
    m_szDescription[49] = '\0';
    m_eConfigConnectionMode = CONFIG_CAM_CMODE_NONE;
    STRCPY (m_szConnectionChain, "");
    m_szConnectionChain[CONFIG_MAX_PATH] = '\0';
    STRCPY (m_szSerialNumber, "");
    m_szSerialNumber[CONFIG_MAX_PATH] = '\0';
    STRCPY (m_szLicense, "");
    m_szLicense[CONFIG_MAX_PATH] = '\0';
    m_iFps = 25;
    m_iTimeSendFps = 5;
    m_iFpsShow = 20;
    m_iMatWidth = 640;
    m_iMatHeight = 480;
    m_iMatType = 3;
    m_iBuffMaxLengh = 30;
    m_iLeftCutout = 0;
    m_iRightCutout = 0;
    m_iTopCutout = 0;
    m_iBottomCutout = 0;
    m_iFocalLength = 35;
    m_iPixelPitch = 17;
    m_dIFOV = 0.4857;
    m_dOffsetIfov_x = 0.06;
    m_dOffsetIfov_y = 0.001;

    m_bCCTVAccessControl = false;
    STRCPY (m_szCCTVUsername, "");
    STRCPY (m_szCCTVPassword, "");

    m_eConfigCameraType = CONFIG_CAM_TYPE_NONE;
    m_eConfigSensorType = CONFIG_SENSOR_NONE;
    m_iMatMetaDataLeft = 0;
    m_iMatMetaDataRight = 0;
    STRCPY(m_szCameraModelName, "");
    m_szCameraModelName[19] = '\0';
    m_baPartNumber = QByteArray::fromHex("");

    m_ucDataBits = 0;
    m_ucModeConvert2_8To16 = 3;
    m_usDivConvert2_8To16 = 1;
    m_usAndConvert2_8To16 = 0;
    m_iInvertValues = 16384;

    m_bAutomaticGain = false;
    m_iMaxPixSaturated = 10;
    m_iAutoGainInterval = 60;
    m_iGain = 0;
    m_iDiodeBias = 2;
    m_iIntegrationTime = 13000;

    /*Pico & ATTO parameters*/
    m_iParamGFID = -1;
    m_iParamGSK = -1;
    m_iParamVSK = -1;
    m_iParamVBUS = -1;
    m_iParamGain = -1;
    m_iParamTInt = -1;

    m_iLaserCOM = 0;
    m_eConfigLaserType = CONFIG_LASER_NONE;
    m_iPortThirdPartyOnvif = 0;
    m_iPortThirdPartyHttp = 0;
    m_iPortThirdPartyRtsp = 0;
    m_iFramesSecondRtsp = 5;
    m_bRTSPAccessControl = false;
    STRCPY(m_szRTSPUsername, "");
    STRCPY(m_szRTSPPassword, "");
    m_bPaletteRtsp = false;
    m_bValuesRtsp = false;

    m_bWeightingFactors = false;
    m_bVerticalFlip = false;
    m_bHorizontalFlip = false;
    m_bImageRotate = false;
    m_bPaletteBar = true;
    m_bStretching = true;
    m_bAutoStretching = true;
    m_bStretchingRegion = false;
    m_iRegionSize = 50;
    m_bCameraRepeatedFrames = false;
    m_bShowROI = true;
    m_bShowNOROI = false;
    m_bShowCurrentFrame = true;
    m_bShowSimulateName = false;
    m_bEnableAll = true;
    m_dCamEmissivity = 1.0;
    m_bShowDigitalLevels = false;
    m_bShowSaturatedPixels = true;
    m_bAutomaticRaw = false;
    m_bAutomaticMP4 = true;
    m_dCamGain = 1;
    m_dCamOffset = 0;
    m_bShowWindowTest = false;
    m_iSkip = 0;
    m_iMean = 0;

    m_bEmailAlert = false;

    m_iReconnectionWait = 3000;
    m_iReconnectionAttemps = 10;

    STRCPY (m_szConnectionPhidget, "");
    m_szConnectionPhidget[CONFIG_MAX_IP -1] = '\0';
    m_iRelayPort = 2;
    m_iStepperPort = 0;
    m_iSensorPort = 3;
    m_iShutterMaxPos = -4000;
    m_iShutterMinPos = 0;

    m_bHasShutter = false;
    m_iNucSecondsBetweenAutomatic = 3600;
    m_iSecondsDelayClosedshutterImgnuc = 2;
    m_bPanAndTilt = false;
    m_iPanAndTiltCom = 0;
    m_bPanAndTiltPelcoD = true;
    m_iPanAndTiltID = 1;
    m_iPanAndTiltSpeed = 32;
    m_bPanInverted = false;
    m_bTiltInverted = false;
    STRCPY (m_szTourActiveAutomatic, "");
    STRCPY (m_szPresetActiveAutomatic, "");
    m_szTourActiveAutomatic[CFG_MAX_SMALL_ID] = '\0';
    m_szPresetActiveAutomatic[CFG_MAX_SMALL_ID] = '\0';
    m_bHasSensorLens = false;
    m_bHasPleoraExpansor = false;
    m_bHasMemorySPI = false;
    m_bHasCompass = false;

    m_bAdamRelay = false;
    STRCPY (m_szAdamRelayIP, "");
    m_szAdamRelayIP[CONFIG_MAX_PATH] = '\0';
    m_iAdamRelayPort = 0;
    m_iMaxOperationTemperature = 80;

    m_bSwitchPOE = false;
    STRCPY (m_szSwitchIP, "");
    m_szSwitchIP[CONFIG_MAX_PATH] = '\0';
    m_iSwitchInterface = 0;

    /* Variables para el reset automático de cámaras */
    m_bAutoResetEnabled = false;
    m_bResetPeriodicEnabled = false;
    m_bResetPunctualEnabled = false;
    STRCPY(m_szResetUnits, "");
    m_szResetUnits[9] = '\0';
    m_iResetUnitsValue = -1;
    STRCPY(m_szResetDateTime, "");
    m_szResetDateTime[49] = '\0';
    STRCPY(m_szResetPeriodicDateTime, "");
    m_szResetPeriodicDateTime[49] = '\0';

    m_bCloseShutter = false;
    m_bFPSWarnings = false;
    m_bSensiaNUC = true;

    m_iCurrentPreset = -1;
    m_iCurrentTour = -1;
    vGlobalTemp.clear();
    m_dMediaTemp = 0;

    m_bMaintenanceMode = false;

    STRCPY(m_sGeolocation, "");

    /* Smart camera periodic cleaner */
    m_iPeriodicUnitsValue = 0;
    STRCPY(m_szPeriodicUnits, "");
    m_szPeriodicUnits[49] = '\0';
    m_bPeriodicPunctual = true;
    m_bPeriodicRepeat = false;
    m_bPeriodicDeleteAt = false;
    m_bPeriodicDeleteAtActive = false;
    STRCPY(m_szNextCheckTime, "");
    m_szNextCheckTime[49] = '\0';
    STRCPY(m_szPeriodicDeleteAtTime, "00:00:00");
    m_szPeriodicDeleteAtTime[49] = '\0';

    m_iPTLimitTiltTop = -1;
    m_iPTLimitTiltBottom = -1;
    m_iPTLimitPanLeft = -1;
    m_iPTLimitPanRight = -1;
}