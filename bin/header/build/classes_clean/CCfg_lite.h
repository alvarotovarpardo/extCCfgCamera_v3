class CCfgCamGeneral : public CCfgClass
{
public:
    enum EnumConfigConnectionMode { CONFIG_CAM_CMODE_NONE, CONFIG_CAM_CMODE_OPENCV, CONFIG_CAM_CMODE_VIDEOINPUT, CONFIG_CAM_CMODE_PLEORA, CONFIG_CAM_CMODE_SIMULATE, CONFIG_CAM_CMODE_CCTV, CONFIG_CAM_CMODE_GST };
    enum EnumConfigCameraType { CONFIG_CAM_TYPE_NONE, CONFIG_CAM_TYPE_THERMAL, CONFIG_CAM_TYPE_VISIBLE };
    enum EnumConfigSensorType { CONFIG_SENSOR_NONE, CONFIG_SENSOR_PELICAN, CONFIG_SENSOR_FREJA, CONFIG_SENSOR_VOXI, CONFIG_SENSOR_PICO, CONFIG_SENSOR_GUIDE, CONFIG_SENSOR_KINGLET };

    CCfgCamGeneral();
    virtual ~CCfgCamGeneral();

    void initDefault();
    void display();
    void matchField(std::string &sAtributo, Jzon::Node &nodoValor);
    void serializeFields(Jzon::Node &node);

    char *getDescription() { return m_szDescription; }
    void setDescription(char *szDescription) { STRCPY(m_szDescription, szDescription); }
    EnumConfigConnectionMode getConnectionMode() { return m_eConfigConnectionMode; }
    void setConnectionMode(EnumConfigConnectionMode eConfigConnectionMode) { m_eConfigConnectionMode = eConfigConnectionMode; }
    char *getConnectionChain() { return m_szConnectionChain; }
    void setConnectionChain(QString sConnectionChain) { STRCPY(m_szConnectionChain,sConnectionChain.toStdString().c_str()); }
    char *getCameraModelName() { return m_szCameraModelName; }
    void setCameraModelName(char *sCameraModelName) { STRCPY(m_szCameraModelName,sCameraModelName); }
    EnumConfigCameraType getConfigCameraType() { return m_eConfigCameraType; }
    void setConfigCameraType(EnumConfigCameraType eConfigCamera) { m_eConfigCameraType = eConfigCamera; }
    EnumConfigSensorType getConfigSensorType() { return m_eConfigSensorType; }
    void setConfigSensorType(EnumConfigSensorType eConfigSensor) { m_eConfigSensorType = eConfigSensor; }
    int getFps() { return m_iFps; }
    void setFps(int iFps) { m_iFps = iFps; }
    int getTimeSendFps() { return m_iTimeSendFps; }
    void setTimeSendFps(int iTimeSendFps) { m_iTimeSendFps = iTimeSendFps; }
    int getMatWidth() { return m_iMatWidth; }
    void setMatWidth(int iMatWidth) { m_iMatWidth = iMatWidth; }
    int getMatHeight() { return m_iMatHeight; }
    void setMatHeight(int iMatHeight) { m_iMatHeight = iMatHeight; }
    int getMatType() { return m_iMatType; }
    void setMatType(int iMatType) { m_iMatType = iMatType; }
    int getBuffMaxLengh() { return m_iBuffMaxLengh; }
    void setBuffMaxLengh(int iBuffMaxLengh) { m_iBuffMaxLengh = iBuffMaxLengh; }
    int getMatMetaDataLeft() { return m_iMatMetaDataLeft; }
    void setMatMetaDataLeft(int iMatMetaDataLeft) { m_iMatMetaDataLeft = iMatMetaDataLeft; }
    int getMatMetaDataRigh() { return m_iMatMetaDataRight; }
    void setMatMetaDataRigh(int iMatMetaDataRight) { m_iMatMetaDataRight = iMatMetaDataRight; }
    unsigned char getDataBits() { return m_ucDataBits; }
    void setDataBits(unsigned char ucDataBits) { m_ucDataBits = ucDataBits; }
    unsigned char getModeConvert2_8To16() { return m_ucModeConvert2_8To16; }
    void setModeConvert2_8To16(unsigned char ucModeConvert2_8To16) { m_ucModeConvert2_8To16 = ucModeConvert2_8To16; }
    unsigned short getDivConvert2_8To16() { if (m_usDivConvert2_8To16 == 0) return 1; else return m_usDivConvert2_8To16; }
    void setDivConvert2_8To16(unsigned short usDivConvert2_8To16) { m_usDivConvert2_8To16 = usDivConvert2_8To16; }
    unsigned short getAndConvert2_8To16() { return m_usAndConvert2_8To16; }
    void setAndConvert2_8To16(unsigned short usAndConvert2_8To16) { m_usAndConvert2_8To16 = usAndConvert2_8To16; }
    int getInvertValues() { return m_iInvertValues; }
    void setInvertValues(int iInvertValues) { m_iInvertValues = iInvertValues; }
    int getTamVectorData() { return m_iTamVectorData; }
    void setTamVectorData(int iTamVectorData) { m_iTamVectorData = iTamVectorData; }
    //********************************* getters/setters mileva cam parameters *********************************
    int getGain() { return m_iGain; }
    void setGain(int iGain) { m_iGain = iGain; }
    int getDiodeBias() { return m_iDiodeBias; }
    void setDiodeBias(int iDiodeBias) { m_iDiodeBias= iDiodeBias; }
    int getTFrame() { return m_iTFrame; }
    void setTFrame(int iTFrame) { m_iTFrame = iTFrame; }
    int getIntegrationTime() { return m_iIntegrationTime; }
    void setIntegrationTime(int iIntegrationTime) { m_iIntegrationTime = iIntegrationTime; }
    //*********************************************************************************************************
    int getReconnectionWait() { return m_iReconnectionWait; }
    void setReconnectionWait(int iReconnectionWait) { m_iReconnectionWait = iReconnectionWait; }
    int getReconnectionAttemps() { return m_iReconnectionAttemps; }
    void setReconnectionAttemps(int iReconnectionAttemps) { m_iReconnectionAttemps = iReconnectionAttemps; }
    int getFpsShow() { return m_iFpsShow; }
    void setFpsShow(int iFpsShow) { m_iFpsShow = iFpsShow; }
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

    //********************************* getters/setters options *********************************
    bool getVerticalFlip() { return m_bVerticalFlip; }
    void setVerticalFlip(bool bVerticalFlip) { m_bVerticalFlip = bVerticalFlip; }
    bool getHorizontalFlip() { return m_bHorizontalFlip; }
    void setHorizontalFlip(bool bHorizontalFlip) { m_bHorizontalFlip = bHorizontalFlip; }
    bool getImageRotate(){ return m_bImageRotate;}
    void setImageRotate(bool bImageRotate) {m_bImageRotate = bImageRotate;}
    bool getPaletteBar() { return m_bPaletteBar; }
    void setPaletteBar(bool bPaletteBar) { m_bPaletteBar = bPaletteBar; }
    bool getStretching() { return m_bStretching; }
    void setStretching(bool bStretching) { m_bStretching = bStretching; }
    bool getAutoStretching() { return m_bAutoStretching; }
    void setAutoStretching(bool bAutoStretching) { m_bAutoStretching = bAutoStretching; }
    bool getStretchingRegion() { return m_bStretchingRegion; }
    void setStretchingRegion(bool bStretchingRegion) { m_bStretchingRegion = bStretchingRegion; }
    int getRegionSize() { return m_iRegionSize; }
    void setRegionSize(int iRegionSize) { m_iRegionSize = iRegionSize; }
    bool getShowROI() { return m_bShowROI; }
    void setShowROI(bool bShowROI) { m_bShowROI = bShowROI; }
    bool getShowNOROI() { return m_bShowNOROI; }
    void setShowNOROI(bool bShowNOROI) { m_bShowNOROI = bShowNOROI; }
    double getCamEmissivity() { return m_dCamEmissivity; }
    void setCamEmissivity(double dCamEmissivity) { m_dCamEmissivity = dCamEmissivity; }
    bool getShowDititalLevels() {return m_bShowDigitalLevels;}
    void setShowDigitalLevels(bool bShowDigitalLevels) { m_bShowDigitalLevels = bShowDigitalLevels;}
    bool getPanAndTilt() { return m_bPanAndTilt; }
    void setPanAndTilt(bool bPanAndTilt) { m_bPanAndTilt = bPanAndTilt; }
    char *getTourActiveAutomatic() { return m_szTourActiveAutomatic; }
    void setTourActiveAutomatic(char * szTour) { STRNCPY(m_szTourActiveAutomatic, szTour,  CFG_MAX_SMALL_ID); }
    char *getPresetActiveAutomatic() { return m_szPresetActiveAutomatic; }
    void setPresetActiveAutomatic(char * szPreset) { STRNCPY(m_szPresetActiveAutomatic, szPreset,  CFG_MAX_SMALL_ID); }
    bool getHasShutter() { return m_bHasShutter; }
    void setHasShutter(bool bHasShutter) { m_bHasShutter = bHasShutter; }
    int getNucSecondsBetweenAutomatic() { return m_iNucSecondsBetweenAutomatic; }
    void setNucSecondsBetweenAutomatic(int iNucSecondsBetweenAutomatic) { m_iNucSecondsBetweenAutomatic = iNucSecondsBetweenAutomatic; }
    int getSecondsDelayClosedshutterImgnuc() { return m_iSecondsDelayClosedshutterImgnuc; }
    void setSecondsDelayClosedshutterImgnuc(int iSecondsDelayClosedshutterImgnuc) { m_iSecondsDelayClosedshutterImgnuc = iSecondsDelayClosedshutterImgnuc; }
    bool getAutomaticRaw() { return m_bAutomaticRaw; }
    void setAutomaticRaw(bool bAutomaticRaw) { m_bAutomaticRaw = bAutomaticRaw; }
    int getSkip() { return m_iSkip; }
    void setSkip(int iSkip) { m_iSkip = iSkip; }
    int getMean() { return m_iMean; }
    void setMean(int iMean) { m_iMean = iMean; }
    int getWindowSize() { return m_iWindowSize; }
    void setWindowSize(int iWindowSize) { m_iWindowSize = iWindowSize; }
    int getSizeClaheSkip() { return m_iSizeClaheSkip; }
    void setSizeClaheSkip(int iSizeClaheSkip) { m_iSizeClaheSkip = iSizeClaheSkip; }
    int getSizeClaheEnhanced() { return m_iSizeClaheEnhanced; }
    void setSizeClaheEnhanced(int iSizeClaheEnhanced) { m_iSizeClaheEnhanced = iSizeClaheEnhanced; }
    int getSizeClahe() { return m_iSizeClahe; }
    void setSizeClahe(int iSizeClahe) { m_iSizeClahe = iSizeClahe; }
    double getClipClaheSkip() { return m_dClipClaheSkip; }
    void setClipClaheSkip(double dClipClaheSkip) { m_dClipClaheSkip = dClipClaheSkip; }
    double getClipClaheEnhanced() { return m_dClipClaheEnhanced; }
    void setClipClaheEnhanced(double dClipClaheEnhanced) { m_dClipClaheEnhanced = dClipClaheEnhanced; }
    double getClipClahe() { return m_dClipClahe; }
    void setClipClahe(double dClipClahe) { m_dClipClahe = dClipClahe; }
    char *getDeviceSerialNumber() {return m_sDeviceSerialNumber;}
    void setDeviceSerialNumber(char *sDeviceSerialNumber) {STRCPY(m_sDeviceSerialNumber, sDeviceSerialNumber);}
    float getFactorMeanPond() { return m_fFactorMeanPond; }
    void setFactorMeanPond(float fFactorMeanPond) { m_fFactorMeanPond = fFactorMeanPond; }
    //************************************************************************************

    //********************************* VARIABLES DE Quantification *************************
    void setUnits(char *szUnits) { STRCPY(m_szUnits, szUnits); }
    char *getUnits() { return m_szUnits; }
    void setDistanceUnits(char *szDistanceUnits) { STRCPY(m_szDistanceUnits, szDistanceUnits); }
    char *getDistanceUnits() { return m_szDistanceUnits; }
    void setLeakDistance(double iLeakDistance) { m_iLeakDistance = iLeakDistance; }
    double getLeakDistance() { return m_iLeakDistance; }
    void setMinFlowRate(double dMinFlowRate) { m_dMinFlowRateLimit = dMinFlowRate; }
    double getMinFlowRate() {return m_dMinFlowRateLimit; }
    void setMaxFlowRate(double dMaxFlowRate) { m_dMaxFlowRateLimit = dMaxFlowRate; }
    double getMaxFlowRate() {return m_dMaxFlowRateLimit; }
    void setTarjetGas(char *szTarjetGas) { STRCPY(m_szTarjetGas, szTarjetGas); }
    char *getTarjetGas() { return m_szTarjetGas; }
    void setCorrectionFactor(double dCorrectionFactor) { m_dCorrectionFactor = dCorrectionFactor; }
    double getCorrectionFactor() { return m_dCorrectionFactor; }
    void setTemperatureUnits(char *szTemperatureUnits) { STRCPY(m_szTemperatureUnits, szTemperatureUnits); }
    char *getTemperatureUnits() { return m_szTemperatureUnits; }
    void setAmbientTemperature(double dAmbientTemperature) { m_dAmbientTemperature = dAmbientTemperature; }
    double getAmbientTemperature() { return m_dAmbientTemperature; }
    void setHR(int iHR) { m_iHR = iHR; }
    int getHR() { return m_iHR; }
    void setGasTemperature(double dGasTemperature) { m_dGasTemperature = dGasTemperature; }
    double getGasTemperature() { return m_dGasTemperature; }
    void setOpticalSize(char *szOpticalSize) { STRCPY(m_szOpticalSize, szOpticalSize); }
    char *getOpticalSize() { return m_szOpticalSize; }
    void setSensitivity(char *szSensitivity) { STRCPY(m_szSensitivity, szSensitivity); }
    char *getSensitivity() { return m_szSensitivity; }
    void setDensityUnits(char *szDensityUnits) { STRCPY(m_szDensityUnits, szDensityUnits); }
    char *getDensityUnits() { return m_szDensityUnits; }
    void setGasDensity(double dGasDensity) { m_dGasDensity = dGasDensity; }
    double getGasDensity() { return m_dGasDensity; }
    void setQSensitivity(char *szSensitivity) { STRCPY(m_szSensitivity, szSensitivity); }
    char *getQSensitivity() { return m_szSensitivity; }
    //************************************************************************************

private:
    EnumConfigConnectionMode m_eConfigConnectionMode;
    char m_szConnectionChain[CONFIG_MAX_PATH + 1];
    char m_szDescription[50];
    int m_iFps;
    int m_iFpsShow;
    int m_iMatWidth;
    int m_iMatHeight;
    int m_iMatType;
    int m_iBuffMaxLengh;
    int m_iTimeSendFps;
    int m_iTamVectorData;
    EnumConfigCameraType m_eConfigCameraType;
    EnumConfigSensorType m_eConfigSensorType;
    int m_iMatMetaDataLeft;
    int m_iMatMetaDataRight;
    int m_iSkip;
    int m_iMean;
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
    char m_szCameraModelName[20];
    
    unsigned char m_ucDataBits;
    unsigned char m_ucModeConvert2_8To16;
    unsigned short m_usDivConvert2_8To16;
    unsigned short m_usAndConvert2_8To16;
    int m_iInvertValues;
    int m_iGain;
    int m_iDiodeBias;
    int m_iTFrame;
    int m_iIntegrationTime;
    
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
    bool m_bStretchingRegion;
    int m_iRegionSize;
    double m_dCamEmissivity;
    int m_iReconnectionWait;
    int m_iReconnectionAttemps;
    
    bool m_bPanAndTilt;
    char m_szTourActiveAutomatic[CFG_MAX_SMALL_ID + 1];
    char m_szPresetActiveAutomatic[CFG_MAX_SMALL_ID + 1];
    bool m_bHasShutter;
    int m_iNucSecondsBetweenAutomatic;
    int m_iSecondsDelayClosedshutterImgnuc;
    bool m_bAutomaticRaw;
    
    char m_sDeviceSerialNumber [50];
    
    /* Variables para GreenCPorts */
    char m_szUnits[50];
    double m_iLeakDistance;
    char m_szTarjetGas[50];
    double m_dCorrectionFactor;
    double m_dAmbientTemperature;
    int m_iHR;
    double m_dGasTemperature;
    double m_dGasDensity;
    char m_szOpticalSize[50];
    char m_szSensitivity[50];
    char m_szDistanceUnits[50];
    char m_szDensityUnits[50];
    char m_szTemperatureUnits[50];
};
