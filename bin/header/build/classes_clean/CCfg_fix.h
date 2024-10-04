class CCfgCamGeneral : public CCfgClass
{
public:
    enum EnumConfigConnectionMode { CONFIG_CAM_CMODE_NONE, CONFIG_CAM_CMODE_OPENCV, CONFIG_CAM_CMODE_VIDEOINPUT, CONFIG_CAM_CMODE_PLEORA, CONFIG_CAM_CMODE_SIMULATE, CONFIG_CAM_CMODE_CCTV, CONFIG_CAM_CMODE_EYECGAS, CONFIG_CAM_CMODE_SIMULATE_EYECGAS, CONFIG_CAM_CMODE_FLIR_ATLAS, CONFIG_CAM_CMODE_FLIR_SPINNAKER, CONFIG_CAM_CMODE_SIMULATE_FLIR, CONFIG_CAM_CMODE_SMART, CONFIG_CAM_CMODE_ARAVIS, CONFIG_CAM_CMODE_PCO};
    enum EnumConfigCameraType { CONFIG_CAM_TYPE_NONE, CONFIG_CAM_TYPE_THERMAL, CONFIG_CAM_TYPE_VISIBLE };
    enum EnumConfigSensorType { CONFIG_SENSOR_VOXI, CONFIG_SENSOR_PELICAN, CONFIG_SENSOR_PICO640, CONFIG_SENSOR_FREJA, CONFIG_SENSOR_KINGLET, CONFIG_SENSOR_FASTPELICAN, CONFIG_SENSOR_PICO384, CONFIG_SENSOR_HOTPELICAN, CONFIG_SENSOR_ATTO640, CONFIG_SENSOR_PICO384V2, CONFIG_SENSOR_GUIDE, CONFIG_SENSOR_NONE };
    enum EnumConfigLaserType { CONFIG_LASER_NONE, CONFIG_LASER_A, CONFIG_LASER_B };
    enum EnumFocus { FOCUS_AUTO, FOCUS_INCREMENT, FOCUS_DECREMENT };

    CCfgCamGeneral();
    virtual ~CCfgCamGeneral();

    void initDefault();
    void display();
    void matchField(std::string &sAtributo, Jzon::Node &nodoValor);
    void serializeFields(Jzon::Node &node);

    char *getDescription() { return m_szDescription; }
    EnumConfigConnectionMode getConnectionMode() { return m_eConfigConnectionMode; }
    void setConnectionMode(EnumConfigConnectionMode eConfigConnectionMode) { m_eConfigConnectionMode = eConfigConnectionMode; }
    char *getConnectionChain() { return m_szConnectionChain; }
    void setConnectionChain(QString sConnectionChain) { strcpy_s(m_szConnectionChain,sConnectionChain.toLatin1().toStdString().c_str()); }
    char *getSerialNumber() { return m_szSerialNumber; }
    void setSerialNumber(QString sSerialNumber) { strcpy_s(m_szSerialNumber,sSerialNumber.toStdString().c_str()); }
    char *getLicense() { return m_szLicense; }
    void setLicense(QString sLicense) { strcpy_s(m_szLicense, sLicense.toStdString().c_str()); }
    int getFps() { return m_iFps; }
    int getTimeSendFps() { return m_iTimeSendFps; }
    int getFpsShow() { return m_iFpsShow; }
    int getMatWidth() { return m_iMatWidth; }
    int getMatHeight() { return m_iMatHeight; }
    int getMatType() { return m_iMatType; }
    int getBuffMaxLengh() { return m_iBuffMaxLengh; }
    int getLeftCutout() { return m_iLeftCutout; }
    int getRightCutout() { return m_iRightCutout; }
    int getTopCutout() { return m_iTopCutout; }
    int getBottomCutout() { return m_iBottomCutout; }
    double getFocalLength() { return m_dFocalLength; }
    double getPixelPitch() { return m_dPixelPitch; }
    double getIFOV() { return m_dIFOV; }
    double getOffsetIfov_x() { return m_dOffsetIfov_x; }
    double getOffsetIfov_y() { return m_dOffsetIfov_y; }
    double getDistParameterK1() { return m_dDistParameterK1; }
    double getDistParameterK2() { return m_dDistParameterK2; }
    double getDistParameterK3() { return m_dDistParameterK3; }

    void setDescription(char *szDescription) { strcpy_s(m_szDescription, szDescription); }
    void setFps(int iFps) { m_iFps = iFps; }
    void setTimeSendFps(int iTimeSendFps) { m_iTimeSendFps = iTimeSendFps; }
    void setFpsShow(int iFpsShow) { m_iFpsShow = iFpsShow; }
    void setMatWidth(int iMatWidth) { m_iMatWidth = iMatWidth; }
    void setMatHeight(int iMatHeight) { m_iMatHeight = iMatHeight; }
    void setMatType(int iMatType) { m_iMatType = iMatType; }
    void setBuffMaxLengh(int iBuffMaxLengh) { m_iBuffMaxLengh = iBuffMaxLengh; }
    void setLeftCutout(int iLeftCutout) { m_iLeftCutout = iLeftCutout; }
    void setRightCutout(int iRightCutout) { m_iRightCutout = iRightCutout; }
    void setTopCutout(int iTopCutout) { m_iTopCutout = iTopCutout; }
    void setBottomCutout(int iBottomCutout) { m_iBottomCutout = iBottomCutout; }
    void setFocalLength(double dFocalLength) { m_dFocalLength = dFocalLength; }
    void setPixelPitch(double dPixelPitch) { m_dPixelPitch = dPixelPitch; }
    void setIFOV(double dIFOV) {m_dIFOV = dIFOV; }
    void setOffsetIfov_x(double dOffsetIfov_x) {m_dOffsetIfov_x = dOffsetIfov_x; }
    void setOffsetIfov_y(double dOffsetIfov_y) {m_dOffsetIfov_y = dOffsetIfov_y; }
    void setDistParameterK1(double dDistParameterK1) {m_dDistParameterK1 = dDistParameterK1; }
    void setDistParameterK2(double dDistParameterK2) {m_dDistParameterK2 = dDistParameterK2; }
    void setDistParameterK3(double dDistParameterK3) {m_dDistParameterK3 = dDistParameterK3; }

    bool getCCTVAccessControl() { return m_bCCTVAccessControl; }
    void setCCTVAccesControl(bool bCCTVAccesControl) { m_bCCTVAccessControl = bCCTVAccesControl; }
    void setCCTVUsername(char *szCCTVUsername) { strcpy_s(m_szCCTVUsername, szCCTVUsername); }
    char *getCCTVUsername() { return m_szCCTVUsername; }
    void setCCTVPassword(char *szCCTVPassword) { strcpy_s(m_szCCTVPassword, szCCTVPassword); }
    char *getCCTVPassword() { return m_szCCTVPassword;}

    EnumConfigCameraType getConfigCameraType() { return m_eConfigCameraType; }
    void setConfigCameraType(EnumConfigCameraType eConfigCamera) { m_eConfigCameraType = eConfigCamera; }
    EnumConfigSensorType getConfigSensorType() { return m_eConfigSensorType; }
    void setConfigSensorType(EnumConfigSensorType eConfigSensor) { m_eConfigSensorType = eConfigSensor; }
    char *getCameraModelName() { return m_szCameraModelName; }
    void setCameraModelName(char *sCameraModelName) { strcpy_s(m_szCameraModelName,sCameraModelName); }
    char *getCameraHierarchy() { return m_szCameraHierarchy; }
    void setCameraHierarchy(char *sCameraHierarchy) { strcpy_s(m_szCameraHierarchy, sCameraHierarchy); }
    QByteArray getPartNumber() { return m_baPartNumber; }
    void setPartNumber(QByteArray baPartNumber) { m_baPartNumber = baPartNumber; }
    int getMatMetaDataLeft() { return m_iMatMetaDataLeft; }
    void setMatMetaDataLeft(int iMatMetaDataLeft) { m_iMatMetaDataLeft = iMatMetaDataLeft; }
    int getMatMetaDataRigh() { return m_iMatMetaDataRight; }
    void setMatMetaDataRigh(int iMatMetaDataRight) { m_iMatMetaDataRight = iMatMetaDataRight; }

    void setReconnectionWait(int iReconnectionWait) { m_iReconnectionWait = iReconnectionWait; }
    int getReconnectionWait() { return m_iReconnectionWait; }
    void setReconnectionAttemps(int iReconnectionAttemps) { m_iReconnectionAttemps = iReconnectionAttemps; }
    int getReconnectionAttemps() { return m_iReconnectionAttemps; }

    unsigned char getDataBits() { return m_ucDataBits; }
    void setDataBits(unsigned char ucDataBits) { m_ucDataBits = ucDataBits; }
    unsigned char getModeConvert2_8To16() { return m_ucModeConvert2_8To16; }
    void setModeConvert2_8To16(unsigned char ucModeConvert2_8To16) { m_ucModeConvert2_8To16 = ucModeConvert2_8To16; }
    // Con la division por cero salta una excepción así que si es cero devolvemos 1
    unsigned short getDivConvert2_8To16() { if (m_usDivConvert2_8To16 == 0) return 1; else return m_usDivConvert2_8To16; }
    void setDivConvert2_8To16(unsigned short usDivConvert2_8To16) { m_usDivConvert2_8To16 = usDivConvert2_8To16; }
    unsigned short getAndConvert2_8To16() { return m_usAndConvert2_8To16; }
    void setAndConvert2_8To16(unsigned short usAndConvert2_8To16) { m_usAndConvert2_8To16 = usAndConvert2_8To16; }
    int getInvertValues() { return m_iInvertValues; }
    void setInvertValues(int iInvertValues) { m_iInvertValues = iInvertValues; }

    //********************************* setters Mileva parameters ******************************
    void setAutomaticGain(bool bAutomaticGain) { m_bAutomaticGain = bAutomaticGain; }
    void setMaxPixSaturated(int iMaxPixSaturated) { m_iMaxPixSaturated = iMaxPixSaturated; }
    void setAutoGainInterval(int iAutoGainInterval) { m_iAutoGainInterval = iAutoGainInterval; }
    void setGain(int iGain) { m_iGain = iGain; }
    void setDiodeBias(int iDiodeBias) { m_iDiodeBias= iDiodeBias; }
    void setIntegrationTime(int iIntegrationTime) { m_iIntegrationTime = iIntegrationTime; }
    void setIntegrationData(int iIntegrationData) { m_iIntegrationData = iIntegrationData; }
    //******************************************************************************************

    //********************************* getters Mileva parameters ******************************
    bool getAutomaticGain() { return m_bAutomaticGain; }
    int getMaxPixSaturated() { return  m_iMaxPixSaturated; }
    int getAutoGainInterval() { return  m_iAutoGainInterval; }
    int getGain() { return m_iGain; }
    int getDiodeBias() { return m_iDiodeBias; }
    int getIntegrationTime() { return m_iIntegrationTime; }
    int getIntegrationData() { return m_iIntegrationData; }
    //******************************************************************************************

    //********************************* setters Pico & ATTO parameters *************************
    void setParamGFID(int iParamGFID) { m_iParamGFID = iParamGFID; }
    void setParamGSK(int iParamGSK) { m_iParamGSK = iParamGSK; }
    void setParamVSK(int iParamVSK) { m_iParamVSK = iParamVSK; }
    void setParamVBUS(int iParamVBUS) { m_iParamVBUS = iParamVBUS; }
    void setParamGain(int iParamGain) { m_iParamGain = iParamGain; }
    void setParamTInt(int iParamTInt) { m_iParamTInt = iParamTInt; }
    //******************************************************************************************

    //********************************* getters Pico & ATTO parameters *************************
    int getParamGFID() { return m_iParamGFID; }
    int getParamGSK() { return m_iParamGSK; }
    int getParamVSK() { return m_iParamVSK; }
    int getParamVBUS() { return m_iParamVBUS; }
    int getParamGain() { return m_iParamGain; }
    int getParamTInt() { return m_iParamTInt; }
    //******************************************************************************************

    bool getHasLaser() { return m_bHasLaser; }
    void setHasLaser(bool bHasLaser) { m_bHasLaser = bHasLaser; }
    int getLaserCOM() { return m_iLaserCOM; }
    void setLaserCOM(int iLaserCOM) { m_iLaserCOM = iLaserCOM; }
    EnumConfigLaserType getConfigLaserType() { return m_eConfigLaserType; }
    void setConfigLaserType(EnumConfigLaserType eConfigLaserType) { m_eConfigLaserType = eConfigLaserType; }
    int getPortThirdPartyOnvif() { return m_iPortThirdPartyOnvif; }
    void setPortThirdPartyOnvif(int iPortThirdPartyOnvif) { m_iPortThirdPartyOnvif = iPortThirdPartyOnvif; }
    int getPortThirdPartyHttp() { return m_iPortThirdPartyHttp; }
    void setPortThirdPartyHttp(int iPortThirdPartyHttp) { m_iPortThirdPartyHttp = iPortThirdPartyHttp; }
    int getPortThirdPartyRtsp() { return m_iPortThirdPartyRtsp; }
    void setPortThirdPartyRtsp(int iPortThirdPartyRtsp) { m_iPortThirdPartyRtsp = iPortThirdPartyRtsp; }

    int getFramesSecondRtsp() { return m_iFramesSecondRtsp; }
    void setFramesSecondRtsp(int iFramesSecondRtsp) { m_iFramesSecondRtsp = iFramesSecondRtsp; }
    bool getRTSPAccessControl() { return m_bRTSPAccessControl; }
    void setRTSPAccesControl(bool bRTSPAccesControl) { m_bRTSPAccessControl = bRTSPAccesControl; }
    void setRTSPUsername(char *szRTSPUsername) { strcpy_s(m_szRTSPUsername, szRTSPUsername); }
    char *getRTSPUsername() { return m_szRTSPUsername; }
    void setRTSPPassword(char *szRTSPPassword) { strcpy_s(m_szRTSPPassword, szRTSPPassword); }
    const char * getRTSPPassword() { return m_szRTSPPassword; }
    bool getPaletteRtsp() { return m_bPaletteRtsp; }
    void setPaletteRtsp(bool bPaletteRtsp) { m_bPaletteRtsp = bPaletteRtsp; }
    bool getValuesRtsp() { return m_bValuesRtsp; }
    void setValuesRtsp(bool bValuesRtsp) { m_bValuesRtsp = bValuesRtsp; }

    //********************************* setters options *********************************
    void setVerticalFlip(bool bVerticalFlip) { m_bVerticalFlip = bVerticalFlip; }
    void setHorizontalFlip(bool bHorizontalFlip) { m_bHorizontalFlip = bHorizontalFlip; }
    void setImageRotate(bool bImageRotate) { m_bImageRotate = bImageRotate; }
    void setPaletteBar(bool bPaletteBar) { mtxChangeHotConfig.lock(); m_bPaletteBar = bPaletteBar; mtxChangeHotConfig.unlock();}
    void setStretching(bool bStretching) { m_bStretching = bStretching; }
    void setAutoStretching(bool bAutoStretching) { m_bAutoStretching = bAutoStretching; }
    void setCameraRepeatedFrames(bool bCameraRepeatedFrames) { m_bCameraRepeatedFrames = bCameraRepeatedFrames; }
    void setShowROI(bool bShowROI) { m_bShowROI = bShowROI; }
    void setShowNOROI(bool bShowNOROI) { m_bShowNOROI = bShowNOROI; }
    void setCamEmissivity(double dCamEmissivity) { m_dCamEmissivity = dCamEmissivity; }
    void setEnableAll(bool bStatus) {m_bEnableAll = bStatus;}
    void setShowDigitalLevels(bool bShowDigitalLevels) { m_bShowDigitalLevels = bShowDigitalLevels;}
    void setShowSaturatedPixels(bool bShowSaturatedPixels){ m_bShowSaturatedPixels = bShowSaturatedPixels; }
    void setAutomaticRaw(bool bAutomaticRaw) { m_bAutomaticRaw = bAutomaticRaw; }
    void setAutomaticRLK(bool bAutomaticRLK) { m_bAutomaticRLK = bAutomaticRLK; }
    void setAutomaticMP4(bool bAutomaticMP4) { m_bAutomaticMP4 = bAutomaticMP4; }
    void setCamGain(double dCamGain) {m_dCamGain = dCamGain; }
    void setCamOffset(double dCamOffset) {m_dCamOffset = dCamOffset;}
    void setFPSWarnings(bool bState) { m_bFPSWarnings = bState; }
    void setSensiaNUC(bool bSensiaNUC) { m_bSensiaNUC = bSensiaNUC; }
    void setShowWindowTest(bool bShowWindowTest) { m_bShowWindowTest = bShowWindowTest; }
    void setSkip(int iSkip) { m_iSkip = iSkip; }
    void setMean(int iMean) { m_iMean = iMean; }
    void setWeightingFactors(bool bWeightingFactors){ m_bWeightingFactors = bWeightingFactors; }
    void setShowCurrentFrame(bool bShowCurrentFrame) { m_bShowCurrentFrame = bShowCurrentFrame; }
    void setShowSimulateName(bool bShowSimulateName) { m_bShowSimulateName = bShowSimulateName; }
    void setDummy(bool bDummy){ m_bIsDummy = bDummy;}
    //************************************************************************************

    //********************************* getters options *********************************
    bool getVerticalFlip() { return m_bVerticalFlip; }
    bool getHorizontalFlip() { return m_bHorizontalFlip; }
    bool getImageRotate() { return m_bImageRotate; }
    bool getPaletteBar() { return m_bPaletteBar; }
    bool getStretching() { return m_bStretching; }
    bool getAutoStretching() { return m_bAutoStretching; }
    bool getCameraRepeatedFrames() { return m_bCameraRepeatedFrames; }
    bool getShowROI() { return m_bShowROI; }
    bool getShowNOROI() { return m_bShowNOROI; }
    double getCamEmissivity() { return m_dCamEmissivity; }
    bool getEnableAll() {return m_bEnableAll;}
    bool getShowDititalLevels() {return m_bShowDigitalLevels;}
    bool getShowSaturatedPixels() { return m_bShowSaturatedPixels; }
    bool getAutomaticRaw() { return m_bAutomaticRaw; }
    bool getAutomaticRLK() { return m_bAutomaticRLK; }
    bool getAutomaticMP4() { return m_bAutomaticMP4; }
    double getCamGain() { return m_dCamGain; }
    double getCamOffset() { return m_dCamOffset; }
    bool getFPSWarnings() { return m_bFPSWarnings; }
    bool getSensiaNUC() { return m_bSensiaNUC; }
    bool getShowWindowTest() { return m_bShowWindowTest; }
    int getSkip() { return m_iSkip; }
    int getMean() {return m_iMean; }
    bool getWeightingFactors(){ return m_bWeightingFactors; }
    bool getShowCurrentFrame(){ return m_bShowCurrentFrame; }
    bool getShowSimulateName(){ return m_bShowSimulateName; }
    bool getDummy(){ return m_bIsDummy; }
    //************************************************************************************

    void setEmailAlert(bool bEmailAlert) { m_bEmailAlert = bEmailAlert; }
    bool getEmailAlert() { return m_bEmailAlert; }
    char *getConnectionPhidget() { return m_szConnectionPhidget; }
    void setConnectionPhidget(QString sConnectionPhidget) { strcpy_s(m_szConnectionPhidget,sConnectionPhidget.toStdString().c_str()); }
    int getRelayPort() { return m_iRelayPort; }
    void setRelayPort(int iRelayPort) { m_iRelayPort = iRelayPort; }
    int getStepperPort() { return m_iStepperPort; }
    void setStepperPort(int iStepperPort) { m_iStepperPort = iStepperPort; }
    int getSensorPort() { return m_iSensorPort; }
    void setSensorPort(int iSensorPort) { m_iSensorPort = iSensorPort; }
    int getShutterMaxPos() { return m_iShutterMaxPos; }
    void setShutterMaxPos(int iShutterMaxPos) { m_iShutterMaxPos = iShutterMaxPos; }
    int getShutterMinPos() { return m_iShutterMinPos; }
    void setShutterMinPos(int iShutterMinPos) { m_iShutterMinPos = iShutterMinPos; }

    bool getHasShutter() { return m_bHasShutter; }
    void setHasShutter(bool bHasShutter) { m_bHasShutter = bHasShutter; }
    int getNucSecondsBetweenAutomatic() { return m_iNucSecondsBetweenAutomatic; }
    void setNucSecondsBetweenAutomatic(int iNucSecondsBetweenAutomatic) { m_iNucSecondsBetweenAutomatic = iNucSecondsBetweenAutomatic; }
    int getSecondsDelayClosedshutterImgnuc() { return m_iSecondsDelayClosedshutterImgnuc; }
    void setSecondsDelayClosedshutterImgnuc(int iSecondsDelayClosedshutterImgnuc) { m_iSecondsDelayClosedshutterImgnuc = iSecondsDelayClosedshutterImgnuc; }
    bool getCloseShutter() { return m_bCloseShutter; }
    void setCloseShutter(bool bCloseShutter) { m_bCloseShutter = bCloseShutter; }
    bool getPanAndTilt() { return m_bPanAndTilt; }
    void setPanAndTilt(bool bPanAndTilt) { m_bPanAndTilt = bPanAndTilt; }
    int getPanAndTiltCom() { return m_iPanAndTiltCom; }
    void setPanAndTiltCom(int iPanAndTiltCom) { m_iPanAndTiltCom = iPanAndTiltCom; }
    bool getPanAndTiltPelcoD() { return m_bPanAndTiltPelcoD; }
    void setPanAndTiltPelcoD(bool bPanAndTiltPelcoD) { m_bPanAndTiltPelcoD = bPanAndTiltPelcoD; }
    int getPanAndTiltID() { return m_iPanAndTiltID; }
    void setPanAndTiltID(int iPanAndTiltID) { m_iPanAndTiltID = iPanAndTiltID; }
    int getPanAndTiltSpeed() { return m_iPanAndTiltSpeed; }
    void setPanAndTiltSpeed(int iPanAndTiltSpeed) { m_iPanAndTiltSpeed = iPanAndTiltSpeed; }
    bool getPanInverted() { return m_bPanInverted; }
    void setPanInverted(bool bPanInverted) { m_bPanInverted = bPanInverted; }
    bool getTiltInverted() { return m_bTiltInverted; }
    void setTiltInverted(bool bTiltInverted) { m_bTiltInverted = bTiltInverted; }
    char *getTourActiveAutomatic() { return m_szTourActiveAutomatic; }
    void setTourActiveAutomatic(char * szTour) { strncpy_s(m_szTourActiveAutomatic, szTour,  CFG_MAX_SMALL_ID); }
    char *getPresetActiveAutomatic() { return m_szPresetActiveAutomatic; }
    void setPresetActiveAutomatic(char * szPreset) { strncpy_s(m_szPresetActiveAutomatic, szPreset,  CFG_MAX_SMALL_ID); }
    bool getHasSensorLens() { return m_bHasSensorLens; }
    void setHasSensorLens(bool bHasSensorLens) { m_bHasSensorLens = bHasSensorLens; }
    bool getHasPleoraExpansor() { return m_bHasPleoraExpansor; }
    void setHasPleoraExpansor(bool bHasPleoraExpansor) { m_bHasPleoraExpansor = bHasPleoraExpansor; }
    bool getHasMemorySPI() { return m_bHasMemorySPI; }
    void setHasMemorySPI(bool bHasMemorySPI) { m_bHasMemorySPI = bHasMemorySPI; }
    bool getHasCompass() { return m_bHasCompass; }
    void setHasCompass(bool bHasCompass) { m_bHasCompass = bHasCompass; }

    bool getAdamRelay() { return m_bAdamRelay; }
    void setAdamRelay(bool bAdamRelay) { m_bAdamRelay = bAdamRelay; }
    char *getAdamRelayIP() { return m_szAdamRelayIP; }
    void setAdamRelayIP(QString sAdamRelayIP) { strcpy_s(m_szAdamRelayIP,sAdamRelayIP.toStdString().c_str()); }
    int getAdamRelayPort() { return m_iAdamRelayPort; }
    void setAdamRelayPort(int iAdamRelayPort) { m_iAdamRelayPort = iAdamRelayPort; }
    int getMaxOperationTemperature() { return m_iMaxOperationTemperature; }
    void setMaxOperationTemperature(int iMaxOperationTemperature) { m_iMaxOperationTemperature = iMaxOperationTemperature; }
    void setPulseRelay(bool bPulseRelay) { m_bPulseRelay = bPulseRelay; }
    bool getPulseRelay() { return m_bPulseRelay; }
    void setPulseRelaySeconds(int iPulseRelaySeconds) { m_iPulseRelaySeconds = iPulseRelaySeconds; }
    int getPulseRelaySeconds() { return m_iPulseRelaySeconds; }

    bool getSwitchPOE() { return m_bSwitchPOE; }
    void setSwitchPOE(bool bSwitchPOE) { m_bSwitchPOE = bSwitchPOE; }
    char *getSwitchIP() { return m_szSwitchIP; }
    void setSwitchIP(QString sSwitchIP) { strcpy_s(m_szSwitchIP,sSwitchIP.toStdString().c_str()); }
    int getSwitchInterface() { return m_iSwitchInterface; }
    void setSwitchInterface(int iSwitchInterface) { m_iSwitchInterface = iSwitchInterface; }

    void setMaintenanceMode(bool bMaintenanceMode) { m_bMaintenanceMode = bMaintenanceMode; }
    bool getMaintenanceMode() { return m_bMaintenanceMode; }

    //***************************** getters auto reset ***********************************
    bool getAutoResetEnabled() { return m_bAutoResetEnabled; }
    void setAutoResetEnabled(bool bStatus) { m_bAutoResetEnabled = bStatus; }
    bool getResetPeriodicEnabled() { return m_bResetPeriodicEnabled; }
    void setResetPeriodicEnabled(bool bStatus) { m_bResetPeriodicEnabled = bStatus; }
    bool getResetPunctualEnabled() { return m_bResetPunctualEnabled; }
    void setResetPunctualEnabled(bool bStatus) { m_bResetPunctualEnabled = bStatus; }
    char *getResetUnits() { return m_szResetUnits; }
    void setResetUnits(char *szResetUnits) { strcpy_s(m_szResetUnits, szResetUnits); }
    int getResetUnitsValue() { return m_iResetUnitsValue; }
    void setResetUnitsValue(int iResetUnitsValue) { m_iResetUnitsValue = iResetUnitsValue; }
    char *getResetDateTime() { return m_szResetDateTime; }
    void setResetDateTime(char *szResetDateTime) { strcpy_s(m_szResetDateTime, szResetDateTime); }
    char *getResetPeriodicDateTime() { return m_szResetPeriodicDateTime; }
    void setResetPeriodicDateTime(char *szResetPeriodicDateTime) { strcpy_s(m_szResetPeriodicDateTime, szResetPeriodicDateTime); }
    //************************************************************************************

    void setCurrentPreset(int iCurrentPreset) { m_iCurrentPreset = iCurrentPreset; }
    int getCurrentPreset() { return m_iCurrentPreset; }
    void setCurrentTour(int iCurrentTour) { m_iCurrentTour = iCurrentTour; }
    int getCurrentTour() { return m_iCurrentTour; }
    double getGlobalTemp() { return m_dMediaTemp; }
    void setGlobalTemp(double dTempFever, int numberSamples, int idRoi);

    void setGeolocation(char *sGeolocation) { strcpy_s(m_sGeolocation, sGeolocation); }
    char *getGeolocation() { return m_sGeolocation; }
    void setCameraBand(char *sCameraBand) { strcpy_s(m_szCameraBand, sCameraBand); }
    char *getCameraBand() { return m_szCameraBand; }

    /* Smart camera periodic cleaner */
    void setPeriodicUnitsValue(int iPeriodicUnitsValue) { m_iPeriodicUnitsValue = iPeriodicUnitsValue; }
    int getPeriodicUnitsValue() { return m_iPeriodicUnitsValue; }
    void setPeriodicUnits(char *sPeriodicUnits) { strcpy_s(m_szPeriodicUnits, sPeriodicUnits); }
    char *getPeriodicUnits() { return m_szPeriodicUnits; }
    void setPeriodicPunctual(bool bPeriodicPunctual) { m_bPeriodicPunctual = bPeriodicPunctual; }
    bool getPeriodicPunctual() { return m_bPeriodicPunctual; }
    void setPeriodicRepeat(bool bPeriodicRepeat) { m_bPeriodicRepeat = bPeriodicRepeat; }
    bool getPeriodicRepeat() { return m_bPeriodicRepeat; }
    void setPeriodicDeleteAt(bool bPeriodicDeleteAt) { m_bPeriodicDeleteAt = bPeriodicDeleteAt; }
    bool getPeriodicDeleteAt() { return m_bPeriodicDeleteAt; }
    void setPeriodicDeleteAtActive(bool bPeriodicDeleteAtActive) { m_bPeriodicDeleteAtActive = bPeriodicDeleteAtActive; }
    bool getPeriodicDeleteAtActive() { return m_bPeriodicDeleteAtActive; }
    void setPeriodicDeleteAtTime(char *sPeriodicDeleteAtTime) { strcpy_s(m_szPeriodicDeleteAtTime, sPeriodicDeleteAtTime); }
    char *getPeriodicDeleteAtTime() { return m_szPeriodicDeleteAtTime; }
    void setPeriodicNextCheckTime(char *sNextCheckTime) { strcpy_s(m_szNextCheckTime, sNextCheckTime); }
    char *getPeriodicNextCheckTime() { return m_szNextCheckTime; }

private:
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
    int m_iAdamRelayPort;
    int m_iMaxOperationTemperature;
    int m_iPulseRelaySeconds;
    
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
};
