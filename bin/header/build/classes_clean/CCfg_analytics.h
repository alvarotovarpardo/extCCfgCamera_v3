class CCfgCamGeneral : public CCfgClass
{
public:
    enum EnumConfigConnectionMode { CONFIG_CAM_CMODE_NONE, CONFIG_CAM_CMODE_OPENCV, CONFIG_CAM_CMODE_VIDEOINPUT, CONFIG_CAM_CMODE_PLEORA, CONFIG_CAM_CMODE_SIMULATE, CONFIG_CAM_CMODE_CCTV, CONFIG_CAM_CMODE_DMK, CONFIG_CAM_CMODE_PCO };
    enum EnumConfigCameraType { CONFIG_CAM_TYPE_NONE, CONFIG_CAM_TYPE_THERMAL, CONFIG_CAM_TYPE_VISIBLE };
    enum EnumConfigSensorType { CONFIG_SENSOR_VOXI, CONFIG_SENSOR_PELICAN, CONFIG_SENSOR_PICO640, CONFIG_SENSOR_FREJA, CONFIG_SENSOR_KINGLET, CONFIG_SENSOR_FASTPELICAN, CONFIG_SENSOR_PICO384, CONFIG_SENSOR_HOTPELICAN, CONFIG_SENSOR_ATTO640, CONFIG_SENSOR_PICO384V2, CONFIG_SENSOR_GUIDE, CONFIG_SENSOR_NONE };
    enum EnumConfigCameraMode { CONFIG_MODE_ETHERNET, CONFIG_MODE_USB, CONFIG_MODE_OTHER };

    CCfgCamGeneral();
    virtual ~CCfgCamGeneral();

    void initDefault();
    void display();
    void matchField(std::string &sAtributo, Jzon::Node &nodoValor);
    void serializeFields(Jzon::Node &node);

    char *getDescription() { return m_szDescription; }
    EnumConfigConnectionMode getConnectionMode() { return m_eConfigConnectionMode; }
    void setConnectionMode(EnumConfigConnectionMode eConfigConnectionMode) { m_eConfigConnectionMode = eConfigConnectionMode; }
    EnumConfigCameraMode getConfigCameraMode() { return m_eConfigCameraMode; }
    void setConfigCameramode(EnumConfigCameraMode eConfigCameraMode) { m_eConfigCameraMode = eConfigCameraMode; }
    char *getConnectionChain() { return m_szConnectionChain; }
    void setConnectionChain(QString sConnectionChain) { strcpy_s(m_szConnectionChain,sConnectionChain.toStdString().c_str()); }
    bool getElectronicOld() { return m_bElectronicOld; }
    void setElectronicOld(bool bElectronicOld) { m_bElectronicOld=bElectronicOld; }
    int getFps() { return m_iFps; }
    char *getFuel() { return m_sFuel; }
    int getTimeSendFps() { return m_iTimeSendFps; }
    int getFpsShow() { return m_iFpsShow; }
    int getMatWidth() { return m_iMatWidth; }
    int getMatHeight() { return m_iMatHeight; }
    int getMatType() { return m_iMatType; }
    int getBuffMaxLengh() { return m_iBuffMaxLengh; }

    void setDescription(char *szDescription) { strcpy_s(m_szDescription, szDescription); }
    void setFps(int iFps) { m_iFps = iFps; }
    void setFuel(char *sFuel) { strcpy_s(m_sFuel, sFuel); }
    void setTimeSendFps(int iTimeSendFps) { m_iTimeSendFps = iTimeSendFps; }
    void setFpsShow(int iFpsShow) { m_iFpsShow = iFpsShow; }
    void setMatWidth(int iMatWidth) { m_iMatWidth = iMatWidth; }
    void setMatHeight(int iMatHeight) { m_iMatHeight = iMatHeight; }
    void setMatType(int iMatType) { m_iMatType = iMatType; }
    void setBuffMaxLengh(int iBuffMaxLengh) { m_iBuffMaxLengh = iBuffMaxLengh; }

    void setPlaybackSpeed(char *sPlaybackSpeed) { strcpy_s(m_szPlaybackSpeed, sPlaybackSpeed); }
    char *getPlaybackSpeed() { return m_szPlaybackSpeed; }

    EnumConfigCameraType getConfigCameraType() { return m_eConfigCameraType; }
    void setConfigCameraType(EnumConfigCameraType eConfigCamera) { m_eConfigCameraType = eConfigCamera; }
    EnumConfigSensorType getConfigSensorType() { return m_eConfigSensorType; }
    void setConfigSensorType(EnumConfigSensorType eConfigSensor) { m_eConfigSensorType = eConfigSensor; }
    char *getCameraModelName() { return m_szCameraModelName; }
    void setCameraModelName(char *sCameraModelName) { strcpy_s(m_szCameraModelName,sCameraModelName); }
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

    bool getCCTVAccessControl() { return m_bCCTVAccessControl; }
    void setCCTVAccessControl(bool bCCTVAccesControl) { m_bCCTVAccessControl = bCCTVAccesControl; }
    void setCCTVUsername(char *szCCTVUsername) { strcpy_s(m_szCCTVUsername, szCCTVUsername); }
    char *getCCTVUsername() { return m_szCCTVUsername; }
    void setCCTVPassword(char *szCCTVPassword) { strcpy_s(m_szCCTVPassword, szCCTVPassword); }
    char *getCCTVPassword() { return m_szCCTVPassword;}

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
    void setGain(int iGain) { m_iGain = iGain; }
    void setDiodeBias(int iDiodeBias) { m_iDiodeBias= iDiodeBias; }
    void setIntegrationTime(int iIntegrationTime) { m_iIntegrationTime = iIntegrationTime; }
    //******************************************************************************************

    //********************************* getters Mileva parameters ******************************
    int getGain() { return m_iGain; }
    int getDiodeBias() { return m_iDiodeBias; }
    int getIntegrationTime() { return m_iIntegrationTime; }
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

    int getPortThirdPartyOnvif() { return m_iPortThirdPartyOnvif; }
    void setPortThirdPartyOnvif(int iPortThirdPartyOnvif) { m_iPortThirdPartyOnvif = iPortThirdPartyOnvif; }
    int getPortThirdPartyHttp() { return m_iPortThirdPartyHttp; }
    void setPortThirdPartyHttp(int iPortThirdPartyHttp) { m_iPortThirdPartyHttp = iPortThirdPartyHttp; }
    int getPortThirdPartyRtsp() { return m_iPortThirdPartyRtsp; }
    void setPortThirdPartyRtsp(int iPortThirdPartyRtsp) { m_iPortThirdPartyRtsp = iPortThirdPartyRtsp; }

    int getFramesSecondRtsp() { return m_iFramesSecondRtsp; }
    void setFramesSecondRtsp(int iFramesSecondRtsp) { m_iFramesSecondRtsp = iFramesSecondRtsp; }
    bool getPaletteRtsp() { return m_bPaletteRtsp; }
    void setPaletteRtsp(bool bPaletteRtsp) { m_bPaletteRtsp = bPaletteRtsp; }
    bool getValuesRtsp() { return m_bValuesRtsp; }
    void setValuesRtsp(bool bValuesRtsp) { m_bValuesRtsp = bValuesRtsp; }

    //********************************* setters options *********************************
    void setVerticalFlip(bool bVerticalFlip) { m_bVerticalFlip = bVerticalFlip; }
    void setHorizontalFlip(bool bHorizontalFlip) { m_bHorizontalFlip = bHorizontalFlip; }
    void setImageRotate(bool bImageRotate) { m_bImageRotate = bImageRotate; }
    void setPaletteBar(bool bPaletteBar) { m_bPaletteBar = bPaletteBar; }
    void setStretching(bool bStretching) { m_bStretching = bStretching; }
    void setAutoStretching(bool bAutoStretching) { m_bAutoStretching = bAutoStretching; }
    void setShowROI(bool bShowROI) { m_bShowROI = bShowROI; }
    void setShowNOROI(bool bShowNOROI) { m_bShowNOROI = bShowNOROI; }
    void setCamEmissivity(double dCamEmissivity) { m_dCamEmissivity = dCamEmissivity; }
    void setShowDigitalLevels(bool bShowDigitalLevels) { m_bShowDigitalLevels = bShowDigitalLevels; }
    void setShowSaturatedPixels(bool bShowSaturatedPixels) { m_bShowSaturatedPixels = bShowSaturatedPixels; }
    //************************************************************************************

    //********************************* getters options *********************************
    bool getVerticalFlip() { return m_bVerticalFlip; }
    bool getHorizontalFlip() { return m_bHorizontalFlip; }
    bool getImageRotate() { return m_bImageRotate; }
    bool getPaletteBar() { return m_bPaletteBar; }
    bool getStretching() { return m_bStretching; }
    bool getAutoStretching() { return m_bAutoStretching; }
    bool getShowROI() { return m_bShowROI; }
    bool getShowNOROI() { return m_bShowNOROI; }
    double getCamEmissivity() { return m_dCamEmissivity; }
    bool getEnableAll() {return m_bEnableAll;}
    bool getShowDititalLevels() {return m_bShowDigitalLevels;}
    bool getShowSaturatedPixels() { return m_bShowSaturatedPixels; }
    //************************************************************************************

    //****************************** setters email alert *********************************
    void setEmailAlert(bool bEmailAlert) { m_bEmailAlert = bEmailAlert; }
    void setEmail(char *szEmail) { strcpy_s(m_szEmail, szEmail); }
    void setEmailCC(char *szEmailCC) { strcpy_s(m_szEmailCC, szEmailCC); }
    void setEmailSendAll(bool bEmailSendAll) { m_bEmailSendAll = bEmailSendAll; }
    //************************************************************************************

   //****************************** getters email alert **********************************
    bool getEmailAlert() { return m_bEmailAlert; }
    char *getEmail() { return m_szEmail; }
    char *getEmailCC() { return m_szEmailCC; }
    bool getEmailSendAll() { return m_bEmailSendAll; }
    //************************************************************************************

    bool getPanAndTilt() { return m_bPanAndTilt; }
    void setEnableAll(bool bStatus) {m_bEnableAll = bStatus;}
    void setPanAndTilt(bool bPanAndTilt) { m_bPanAndTilt = bPanAndTilt; }
    char *getTourActiveAutomatic() { return m_szTourActiveAutomatic; }
    void setTourActiveAutomatic(char * szTour) { strncpy_s(m_szTourActiveAutomatic, szTour,  CFG_MAX_SMALL_ID); }
    char *getPresetActiveAutomatic() { return m_szPresetActiveAutomatic; }
    void setPresetActiveAutomatic(char * szPreset) { strncpy_s(m_szPresetActiveAutomatic, szPreset,  CFG_MAX_SMALL_ID); }
    int getNucSecondsBetweenAutomatic() { return m_iNucSecondsBetweenAutomatic; }
    void setNucSecondsBetweenAutomatic(int iNucSecondsBetweenAutomatic) { m_iNucSecondsBetweenAutomatic = iNucSecondsBetweenAutomatic; }
    int getSecondsDelayClosedshutterImgnuc() { return m_iSecondsDelayClosedshutterImgnuc; }
    void setSecondsDelayClosedshutterImgnuc(int iSecondsDelayClosedshutterImgnuc) { m_iSecondsDelayClosedshutterImgnuc = iSecondsDelayClosedshutterImgnuc; }
    bool getCloseShutter() { return m_bCloseShutter; }
    void setCloseShutter(bool bCloseShutter) { m_bCloseShutter = bCloseShutter; }
    bool getAutomaticRaw() { return m_bAutomaticRaw; }
    void setAutomaticRaw(bool bAutomaticRaw) { m_bAutomaticRaw = bAutomaticRaw; }
    bool getHasShutter() { return m_bHasShutter; }
    void setHasShutter(bool bHasShutter) { m_bHasShutter = bHasShutter; }
    bool getHasSensorTemperature() { return m_bHasSensorTemperature; }
    void setHasSensorTemperature(bool bHasSensorTemperature) { m_bHasSensorTemperature = bHasSensorTemperature; }
    bool getHasPleoraExpansor() { return m_bHasPleoraExpansor; }
    void setHasPleoraExpansor(bool bHasPleoraExpansor) { m_bHasPleoraExpansor = bHasPleoraExpansor; }
    bool getHasMemorySPI() { return m_bHasMemorySPI; }
    void setHasMemorySPI(bool bHasMemorySPI) { m_bHasMemorySPI = bHasMemorySPI; }
    bool getHasCompass() { return m_bHasCompass; }
    void setHasCompass(bool bHasCompass) { m_bHasCompass = bHasCompass; }

    //***************************** getters auto reset ***********************************
    bool getAutoResetEnabled() { return m_bAutoResetEnabled; }
    void setAutoResetEnabled(bool bStatus) { m_bAutoResetEnabled = bStatus; }
    bool getResetPeriodicEnabled() { return m_bResetPeriodicEnabled; }
    void setResetPeriodicEnabled(bool bStatus) { m_bResetPeriodicEnabled = bStatus; }
    bool getResetPunctualEnabled() { return m_bResetPunctualEnabled; }
    void setResetPunctualEnabled(bool bStatus) { m_bResetPunctualEnabled = bStatus; }
    char *getResetUnits() { return m_szResetUnits; }
    void setResetUnits(char *szResetUnits) { STRCPY(m_szResetUnits, szResetUnits); }
    int getResetUnitsValue() { return m_iResetUnitsValue; }
    void setResetUnitsValue(int iResetUnitsValue) { m_iResetUnitsValue = iResetUnitsValue; }
    char *getResetDateTime() { return m_szResetDateTime; }
    void setResetDateTime(char *szResetDateTime) { STRCPY(m_szResetDateTime, szResetDateTime); }
    char *getResetPeriodicDateTime() { return m_szResetPeriodicDateTime; }
    void setResetPeriodicDateTime(char *szResetPeriodicDateTime) { STRCPY(m_szResetPeriodicDateTime, szResetPeriodicDateTime); }
    //************************************************************************************

    //****************************** Variables de configuración RIO **********************
    void setThresholdCO(double dThresholdCO) { m_dThresholdCO = dThresholdCO; }
    double getThresholdCO() { return m_dThresholdCO; }
    void setThresholdNOx(double dThresholdNOx) { m_dThresholdNOx = dThresholdNOx; }
    double getThresholdNOx() { return m_dThresholdNOx; }
    void setThresholdHC(double dThresholdHC) { m_dThresholdHC = dThresholdHC; }
    double getThresholdHC() { return m_dThresholdHC; }
    void setThresholdOpacity(double dThresholdOpacity) { m_dThresholdOpacity = dThresholdOpacity; }
    double getThresholdOpacity() { return m_dThresholdOpacity; }
    void setDumpCO2(bool bDumpCO2) { m_bDumpCO2 = bDumpCO2; }
    bool getDumpCO2() { return m_bDumpCO2; }
    void setDumpCO(bool bDumpCO) { m_bDumpCO = bDumpCO; }
    bool getDumpCO() { return m_bDumpCO; }
    void setDumpNOx(bool bDumpNOx) { m_bDumpNOx = bDumpNOx; }
    bool getDumpNOx() { return m_bDumpNOx; }
    void setDumpHC(bool bDumpHC) { m_bDumpHC = bDumpHC; }
    bool getDumpHC() { return m_bDumpHC; }
    void setDumpOpacity(bool bDumpOpacity) { m_bDumpOpacity = bDumpOpacity; }
    bool getDumpOpacity() { return m_bDumpOpacity; }
    double getTHLocalMinCO2() { return m_dTHLocalMinCO2; }
    double getTHLocalMinCO() { return m_dTHLocalMinCO; }
    double getTHLocalMinHC() { return m_dTHLocalMinHC; }
    double getTHLocalMinNOx() { return m_dTHLocalMinNOx; }
    double getTHLocalMinOpacity() { return m_dTHLocalMinOpacity; }
    void setTHLocalMinCO2(double dTHLocalMinCO2) { m_dTHLocalMinCO2 = dTHLocalMinCO2; }
    void setTHLocalMinCO(double dTHLocalMinCO) { m_dTHLocalMinCO = dTHLocalMinCO; }
    void setTHLocalMinHC(double dTHLocalMinHC) { m_dTHLocalMinHC = dTHLocalMinHC; }
    void setTHLocalMinNOx(double dTHLocalMinNOx) { m_dTHLocalMinNOx = dTHLocalMinNOx; }
    void setTHLocalMinOpacity(double dTHLocalMinOpacity) { m_dTHLocalMinOpacity = dTHLocalMinOpacity; }
    double getWaitTime() { return m_dWaitTime; }
    void setWaitTime(double dWaitTime) { m_dWaitTime = dWaitTime; }
    int getVariationThreshold() { return m_iVariationThreshold; }
    void setVariationThreshold(int iVariationThreshold) { m_iVariationThreshold = iVariationThreshold; }
    int getKernelCO2() { return m_iKernelCO2; }
    void setKernelCO2(int iKernelCO2) { m_iKernelCO2 = iKernelCO2; }
    int getKernelCO() { return m_iKernelCO; }
    void setKernelCO(int iKernelCO) { m_iKernelCO = iKernelCO; }
    int getKernelHC() { return m_iKernelHC; }
    void setKernelHC(int iKernelHC) { m_iKernelHC = iKernelHC; }
    int getKernelNOx() { return m_iKernelNOx; }
    void setKernelNOx(int iKernelNOx) { m_iKernelNOx = iKernelNOx; }
    int getKernelOpacity() { return m_iKernelOpacity; }
    void setKernelOpacity(int iKernelOpacity) { m_iKernelOpacity = iKernelOpacity; }
    double getAbsorbanceCO2() { return m_dAbsorbanceCO2; }
    void setAbsorbanceCO2(double dAbsorbanceCO2) { m_dAbsorbanceCO2 = dAbsorbanceCO2; }
    double getAbsorbanceCO() { return m_dAbsorbanceCO; }
    void setAbsorbanceCO(double dAbsorbanceCO) { m_dAbsorbanceCO = dAbsorbanceCO; }
    double getAbsorbanceHC() { return m_dAbsorbanceHC; }
    void setAbsorbanceHC(double dAbsorbanceHC) { m_dAbsorbanceHC = dAbsorbanceHC; }
    double getAbsorbanceNOx() { return m_dAbsorbanceNOx; }
    void setAbsorbanceNOx(double dAbsorbanceNOx) { m_dAbsorbanceNOx = dAbsorbanceNOx; }
    double getAbsorbanceOpacity() { return m_dAbsorbanceOpacity; }
    void setAbsorbanceOpacity(double dAbsorbanceOpacity) { m_dAbsorbanceOpacity = dAbsorbanceOpacity; }
    int getOffset() { return m_iOffset; }
    void setOffset(int iOffset) { m_iOffset = iOffset; }
    int getOCRPort() { return m_iOCRPort; }
    void setOCRPort(int iOCRPort) { m_iOCRPort = iOCRPort; }
    bool getOCR() { return m_bOCR; }
    void setOCR(bool bOCR) { m_bOCR = bOCR; }
    //************************************************************************************

    //********************************* VARIABLES DE GREENCPORTS *************************
    void setUnits(char *szUnits) { strcpy_s(m_szUnits, szUnits); }
    char *getUnits() { return m_szUnits; }

    void setTarjetGas(char *szTarjetGas) { strcpy_s(m_szTarjetGas, szTarjetGas); }
    char *getTarjetGas() { return m_szTarjetGas; }
    void setCorrectionFactor(double dCorrectionFactor) { m_dCorrectionFactor = dCorrectionFactor; }
    double getCorrectionFactor() { return m_dCorrectionFactor; }
    void setOpticalSize(char *szOpticalSize) { strcpy_s(m_szOpticalSize, szOpticalSize); }
    char *getOpticalSize() { return m_szOpticalSize; }
    void setSensitivity(char *szSensitivity) { strcpy_s(m_szSensitivity, szSensitivity); }
    char *getSensitivity() { return m_szSensitivity; }
    void setLambda1(double dLambda1) { m_dLambda1 = dLambda1; }
    double getLambda1() { return m_dLambda1; }
    void setLambda2(double dLambda2) { m_dLambda2 = dLambda2; }
    double getLambda2() { return m_dLambda2; }
    void setGasAbsorption(bool bGasAbsorption) { m_bGasAbsorption = bGasAbsorption; }
    bool getGasAbsorption() { return m_bGasAbsorption; }
    void setGasEmission(bool bGasEmission) { m_bGasEmission = bGasEmission; }
    bool getGasEmission() { return m_bGasEmission; }
    void setEdgeRemove(bool bEdgeRemove) { m_bEdgeRemove = bEdgeRemove; }
    bool getEdgeRemove() { return m_bEdgeRemove; }
    //************************************************************************************

private:
    SimpleCrypt *crypto;
    EnumConfigConnectionMode m_eConfigConnectionMode;
    EnumConfigCameraMode m_eConfigCameraMode;
    char m_szConnectionChain[CONFIG_MAX_PATH + 1];
    char m_szDescription[50];
    char m_sFuel[20];
    int m_iFps;
    int m_iFpsShow;
    int m_iMatWidth;
    int m_iMatHeight;
    int m_iMatType;
    int m_iBuffMaxLengh;
    int m_iTimeSendFps;
    EnumConfigCameraType m_eConfigCameraType;
    EnumConfigSensorType m_eConfigSensorType;
    bool m_bElectronicOld;
    bool m_bEnableAll;
    int m_iMatMetaDataLeft;
    int m_iMatMetaDataRight;
    char m_szCameraModelName[20];
    QByteArray m_baPartNumber;
    char m_szPlaybackSpeed[20];
    
    bool m_bCCTVAccessControl;
    char m_szCCTVUsername[50];
    char m_szCCTVPassword[50];
    
    unsigned char m_ucDataBits;
    unsigned char m_ucModeConvert2_8To16;
    unsigned short m_usDivConvert2_8To16;
    unsigned short m_usAndConvert2_8To16;
    int m_iInvertValues;
    
    /*Mileva parameters*/
    int m_iGain;
    int m_iDiodeBias;
    int m_iIntegrationTime;
    
    /*Pico & ATTO parameters*/
    int m_iParamGFID;
    int m_iParamGSK;
    int m_iParamVSK;
    int m_iParamVBUS;
    int m_iParamGain;
    int m_iParamTInt;
    
    int m_iPortThirdPartyOnvif;
    int m_iPortThirdPartyHttp;
    int m_iPortThirdPartyRtsp;
    int m_iFramesSecondRtsp;
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
    bool m_bEmailAlert;
    bool m_bEmailSendAll;
    char m_szEmail[50];
    char m_szEmailCC[640];
    int m_iReconnectionWait;
    int m_iReconnectionAttemps;
    
    bool m_bHasShutter;
    bool m_bCloseShutter;
    int m_iNucSecondsBetweenAutomatic;
    int m_iSecondsDelayClosedshutterImgnuc;
    bool m_bPanAndTilt;
    char m_szTourActiveAutomatic[CFG_MAX_SMALL_ID + 1];
    char m_szPresetActiveAutomatic[CFG_MAX_SMALL_ID + 1];
    bool m_bAutomaticRaw;
    bool m_bHasSensorTemperature;
    bool m_bHasPleoraExpansor;
    bool m_bHasMemorySPI;
    bool m_bHasCompass;
    
    /* Variables para el reset automático de cámaras */
    bool m_bAutoResetEnabled;
    bool m_bResetPeriodicEnabled;
    bool m_bResetPunctualEnabled;
    char m_szResetUnits[10];
    int m_iResetUnitsValue;
    char m_szResetDateTime[50];
    char m_szResetPeriodicDateTime[50];
    
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
    
};
