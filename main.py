import os
import sys
sys.path.append(os.path.join(os.getcwd(),'Code'))

from create_extCCfgFiles import create_extCCfgCamGeneral_Header, create_extCCfgCamGeneral_Cpp
from modules import copyInitParams, classifyInitDefault
CCfgHeaderFiles = [
    r"C:\Users\Projects\sw_redlook_Fix\gui\util\config_camera.h",
    r"C:\Users\Projects\sw_redlook_distributed\gui\util\config_camera.h",
    r"C:\Users\Projects\sw_redlook_analytics\gui\util\config_camera.h",
    r"C:\Users\Projects\sw_redlook_Lite\gui\util\config_camera.h"
]


CCfgCppFiles = [
    r"C:\Users\Projects\sw_redlook_Fix\gui\util\config_camera.cpp",
    r"C:\Users\Projects\sw_redlook_distributed\gui\util\config_camera.cpp",
    r"C:\Users\Projects\sw_redlook_analytics\gui\util\config_camera.cpp",
    r"C:\Users\Projects\sw_redlook_Lite\gui\util\config_camera.cpp"
]


# Leemos las clases .h y creamos una unificada
create_extCCfgCamGeneral_Header(CCfgHeaderFiles)

# Leemos los .cpp y creamos el initDefault() unificado
create_extCCfgCamGeneral_Cpp(CCfgCppFiles)

#%%
copyInitParams(CCfgCppFiles)
classifyInitDefault()