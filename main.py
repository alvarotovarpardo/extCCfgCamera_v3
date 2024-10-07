import os
import sys
import importlib
sys.path.append(os.path.join(os.getcwd(),'Code'))
import create_configBase
import create_extCCfgFiles
import create_main

importlib.reload(create_extCCfgFiles)
importlib.reload(create_configBase)
importlib.reload(create_main)

from create_extCCfgFiles import create_extCCfgCamGeneral_Header, create_extCCfgCamGeneral_Cpp
from create_configBase import createConfigBaseHeader, createConfigBaseCpp
from create_main import createMainCpp
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


headerConfigBase = r"C:\Users\Projects\sw_redlook_Fix\gui\util\config_base.h" # Nos basta con el del Fix.



# Leemos las clases .h y creamos una unificada
create_extCCfgCamGeneral_Header(CCfgHeaderFiles)

# Leemos los .cpp y creamos el initDefault() unificado
create_extCCfgCamGeneral_Cpp(CCfgCppFiles)

# Leemos config_base.h y lo guardamos 
createConfigBaseHeader(headerConfigBase)

# Creamos el constructor y destructor de CCfgClass
createConfigBaseCpp()

# Creamos el main
createMainCpp()

